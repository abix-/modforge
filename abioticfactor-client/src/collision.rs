//! Local collision geometry from the current-build Facility export.
//! This does not implement Unreal collision filtering or overlap-event lifetime.

use parry3d_f64::{
    math::{Pose, Rot3, Vector},
    query::{PointQuery, intersection_test},
    shape::{Ball, Capsule, ConvexPolyhedron, Shape},
};
use serde::{Deserialize, Serialize};
use serde_json::Value;
use std::{collections::BTreeMap, io};

fn invalid(message: impl Into<String>) -> io::Error {
    io::Error::new(io::ErrorKind::InvalidData, message.into())
}

#[derive(Clone, Debug, Deserialize, Serialize)]
pub struct Transform {
    pub rotation: [f64; 4],
    pub translation: [f64; 3],
    pub scale: [f64; 3],
}

impl Transform {
    pub fn validate(&self) -> io::Result<()> {
        if !self
            .rotation
            .iter()
            .chain(&self.translation)
            .chain(&self.scale)
            .all(|v| v.is_finite())
            || (Rot3::from_array(self.rotation).length_squared() - 1.0).abs() > 1.0e-5
            || self.scale.iter().any(|v| v.abs() < 1.0e-12)
        {
            return Err(invalid("invalid collision transform"));
        }
        Ok(())
    }

    pub fn pose(&self) -> Pose {
        Pose::from_parts(
            Vector::from_array(self.translation),
            Rot3::from_array(self.rotation),
        )
    }

    fn point(&self, point: Vector) -> Vector {
        Rot3::from_array(self.rotation) * (Vector::from_array(self.scale) * point)
            + Vector::from_array(self.translation)
    }

    pub fn from_scene_properties(properties: &Value) -> io::Result<Self> {
        // These SceneComponent defaults are checked against every captured
        // Facility brush transform by the integration test before use.
        let angles = vector(properties.get("RelativeRotation"), [0.0; 3])?;
        Self::from_relative(
            vector(properties.get("RelativeLocation"), [0.0; 3])?,
            angles,
            vector(properties.get("RelativeScale3D"), [1.0; 3])?,
        )
    }

    pub fn from_relative(
        location: [f64; 3],
        angles: [f64; 3],
        scale: [f64; 3],
    ) -> io::Result<Self> {
        let rotation = Rot3::from_rotation_z(angles[1].to_radians())
            * Rot3::from_rotation_y(-angles[0].to_radians())
            * Rot3::from_rotation_x(-angles[2].to_radians());
        let result = Self {
            rotation: rotation.to_array(),
            translation: location,
            scale,
        };
        result.validate()?;
        Ok(result)
    }

    /// Current character attachment path: no socket/absolute overrides and
    /// uniform positive parent scale. Other attachment modes need research.
    pub fn attached_to(&self, parent: &Self) -> io::Result<Self> {
        self.validate()?;
        parent.validate()?;
        if parent.scale[0] <= 0.0
            || parent
                .scale
                .iter()
                .any(|v| (*v - parent.scale[0]).abs() > 1.0e-9)
        {
            return Err(invalid("nonuniform attachment parent not established"));
        }
        Ok(Self {
            rotation: (Rot3::from_array(parent.rotation) * Rot3::from_array(self.rotation))
                .to_array(),
            translation: parent
                .point(Vector::from_array(self.translation))
                .to_array(),
            scale: (Vector::from_array(parent.scale) * Vector::from_array(self.scale)).to_array(),
        })
    }
}

fn vector(value: Option<&Value>, absent: [f64; 3]) -> io::Result<[f64; 3]> {
    match value {
        None => Ok(absent),
        Some(value) if value.get("serialized_zero") == Some(&Value::Bool(true)) => Ok([0.0; 3]),
        Some(value) => serde_json::from_value(value.clone()).map_err(Into::into),
    }
}

pub struct Volume {
    pub name: String,
    pub level: String,
    pub transform: Transform,
    convexes: Vec<ConvexPolyhedron>,
}

pub struct FacilityCollision {
    pub volumes: Vec<Volume>,
}

impl FacilityCollision {
    /// Coordinate containment, separate from actor overlap and selected HUD area.
    pub fn contains_position(&self, volume: &Volume, position: [f64; 3]) -> io::Result<bool> {
        if !position.iter().all(|v| v.is_finite()) {
            return Err(invalid("non-finite map position"));
        }
        let pose = Pose::from_translation(Vector::from_array(volume.transform.translation));
        Ok(volume
            .convexes
            .iter()
            .any(|hull| hull.contains_point(&pose, Vector::from_array(position))))
    }

    pub fn from_json(bytes: &[u8]) -> io::Result<Self> {
        let parsed: Value = serde_json::from_slice(bytes)?;
        let exports = parsed["exports"]
            .as_array()
            .ok_or_else(|| invalid("missing map exports"))?;
        let mut indexed = BTreeMap::new();
        for export in exports {
            let index = export["index"]
                .as_u64()
                .ok_or_else(|| invalid("export index"))?;
            if indexed.insert(index, export).is_some() {
                return Err(invalid("duplicate export index"));
            }
        }
        let resolve = |reference: &Value, class: &str| -> io::Result<&Value> {
            let index = reference
                .as_u64()
                .ok_or_else(|| invalid("export reference"))?;
            let export = indexed
                .get(&index)
                .ok_or_else(|| invalid("referenced export absent"))?;
            if export["class"] != class {
                return Err(invalid(format!("expected {class} export")));
            }
            Ok(export)
        };
        let mut volumes = Vec::new();
        for volume in exports
            .iter()
            .filter(|export| export["class"] == "AbioticLevelStreamingVolume")
        {
            let name = volume["name"]
                .as_str()
                .ok_or_else(|| invalid("volume name"))?
                .to_owned();
            let props = &volume["properties"];
            let level = props["LevelToLoad"]["asset"]
                .as_str()
                .ok_or_else(|| invalid("level asset"))?
                .to_owned();
            let brush = resolve(&props["BrushComponent"], "BrushComponent")?;
            if props["RootComponent"] != brush["index"]
                || brush["outer"] != volume["index"]
                || brush["properties"].get("AttachParent").is_some()
            {
                return Err(invalid(format!("unsupported brush attachment for {name}")));
            }
            let transform = Transform::from_scene_properties(&brush["properties"])?;
            let body = resolve(&brush["properties"]["BrushBodySetup"], "BodySetup")?;
            let elements = body["properties"]["AggGeom"]["ConvexElems"]
                .as_array()
                .ok_or_else(|| invalid("convex elements"))?;
            let mut convexes = Vec::new();
            for element in elements {
                let element_transform = Transform {
                    rotation: serde_json::from_value(element["Transform"]["Rotation"].clone())?,
                    translation: vector(element["Transform"].get("Translation"), [0.0; 3])?,
                    scale: serde_json::from_value(element["Transform"]["Scale3D"].clone())?,
                };
                element_transform.validate()?;
                let vertices: Vec<[f64; 3]> =
                    serde_json::from_value(element["VertexData"].clone())?;
                if vertices.len() < 4
                    || vertices.len() > 65536
                    || !vertices.iter().flatten().all(|v| v.is_finite())
                {
                    return Err(invalid(format!("invalid convex vertices in {name}")));
                }
                // Keep hull coordinates near the brush origin. Apply both scales
                // to the vertices; a rigid pose cannot represent nonuniform scale.
                let rotation = Rot3::from_array(transform.rotation);
                let scale = Vector::from_array(transform.scale);
                let points: Vec<_> = vertices
                    .into_iter()
                    .map(|v| rotation * (scale * element_transform.point(Vector::from_array(v))))
                    .collect();
                convexes.push(
                    ConvexPolyhedron::from_convex_hull(&points)
                        .ok_or_else(|| invalid(format!("invalid convex hull in {name}")))?,
                );
            }
            if convexes.is_empty() {
                return Err(invalid(format!("no collision hulls in {name}")));
            }
            volumes.push(Volume {
                name,
                level,
                transform,
                convexes,
            });
        }
        if volumes.is_empty() {
            return Err(invalid("no Facility volumes"));
        }
        Ok(Self { volumes })
    }

    pub fn overlaps(&self, volume: &Volume, shapes: &[CharacterShape]) -> io::Result<bool> {
        if shapes.is_empty() {
            return Err(invalid("character collision shapes unknown"));
        }
        let pose = Pose::from_translation(Vector::from_array(volume.transform.translation));
        for convex in &volume.convexes {
            for shape in shapes {
                if intersection_test(&pose, convex, &shape.pose, shape.shape.as_ref())
                    .map_err(|_| invalid("unsupported collision pair"))?
                {
                    return Ok(true);
                }
            }
        }
        Ok(false)
    }
}

pub struct CharacterShape {
    pose: Pose,
    shape: Box<dyn Shape>,
}

impl CharacterShape {
    pub fn from_observation(component: &Value) -> io::Result<Self> {
        let transform: Transform = serde_json::from_value(component["world_transform"].clone())?;
        transform.validate()?;
        let scale = transform.scale[0];
        if scale <= 0.0
            || transform
                .scale
                .iter()
                .any(|value| (*value - scale).abs() > 1.0e-9)
        {
            return Err(invalid(
                "nonuniform character shape scaling not established",
            ));
        }
        let radius = component["unscaled_radius"]
            .as_f64()
            .ok_or_else(|| invalid("shape radius"))?
            * scale;
        if !radius.is_finite() || radius <= 0.0 {
            return Err(invalid("invalid shape radius"));
        }
        let shape: Box<dyn Shape> = match component["class"].as_str() {
            Some("SphereComponent") => Box::new(Ball::new(radius)),
            Some("CapsuleComponent") => {
                let half_height = component["unscaled_half_height"]
                    .as_f64()
                    .ok_or_else(|| invalid("capsule half height"))?
                    * scale;
                if !half_height.is_finite() || half_height < radius {
                    return Err(invalid("invalid capsule half height"));
                }
                // Unreal half height includes the hemispheres; Parry's is the
                // central segment half length.
                Box::new(Capsule::new_z(half_height - radius, radius))
            }
            _ => return Err(invalid("unresearched character collision shape")),
        };
        Ok(Self {
            pose: transform.pose(),
            shape,
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use serde_json::json;

    fn cube(transform: Transform) -> FacilityCollision {
        let vertices: Vec<_> = [-1.0, 1.0]
            .into_iter()
            .flat_map(|x| {
                [-1.0, 1.0]
                    .into_iter()
                    .flat_map(move |y| [-1.0, 1.0].into_iter().map(move |z| Vector::new(x, y, z)))
            })
            .map(|point| transform.point(point) - Vector::from_array(transform.translation))
            .collect();
        FacilityCollision {
            volumes: vec![Volume {
                name: "box".into(),
                level: "level".into(),
                transform,
                convexes: vec![ConvexPolyhedron::from_convex_hull(&vertices).expect("box hull")],
            }],
        }
    }

    #[test]
    fn coordinate_containment_uses_rotated_hull_not_world_bounds() {
        let facility = cube(
            Transform::from_relative([0.0; 3], [0.0, 45.0, 0.0], [100.0, 10.0, 10.0]).unwrap(),
        );
        let volume = &facility.volumes[0];
        assert!(
            facility
                .contains_position(volume, [50.0, 50.0, 0.0])
                .unwrap()
        );
        assert!(
            !facility
                .contains_position(volume, [50.0, -50.0, 0.0])
                .unwrap()
        );
        assert!(
            !facility
                .contains_position(volume, [0.0, 0.0, 20.0])
                .unwrap()
        );
    }

    #[test]
    fn rotated_thin_volume_does_not_use_its_world_bounding_box() {
        let facility = cube(
            Transform::from_relative([0.0; 3], [0.0, 45.0, 0.0], [100.0, 10.0, 10.0])
                .expect("box transform"),
        );
        let ball = |at| {
            CharacterShape::from_observation(&json!({"class":"SphereComponent","unscaled_radius":1.0,
            "world_transform":{"rotation":[0.0,0.0,0.0,1.0],"translation":at,"scale":[1.0,1.0,1.0]}})).expect("ball")
        };
        assert!(
            !facility
                .overlaps(&facility.volumes[0], &[ball([75.0, -75.0, 0.0])])
                .expect("outside rotated box")
        );
        assert!(
            facility
                .overlaps(&facility.volumes[0], &[ball([60.0, 60.0, 0.0])])
                .expect("inside rotated box")
        );
    }

    #[test]
    fn capsule_half_height_includes_hemispheres() {
        let facility =
            cube(Transform::from_relative([0.0; 3], [0.0; 3], [1.0; 3]).expect("box transform"));
        let capsule = |z| {
            CharacterShape::from_observation(&json!({"class":"CapsuleComponent","unscaled_radius":1.0,"unscaled_half_height":3.0,
            "world_transform":{"rotation":[0.0,0.0,0.0,1.0],"translation":[0.0,0.0,z],"scale":[1.0,1.0,1.0]}})).expect("capsule")
        };
        assert!(
            !facility
                .overlaps(&facility.volumes[0], &[capsule(4.1)])
                .expect("capsule clears box")
        );
        assert!(
            facility
                .overlaps(&facility.volumes[0], &[capsule(3.9)])
                .expect("hemisphere overlaps box")
        );
    }
}
