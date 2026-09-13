//! Native function addresses and struct layouts read from a game's
//! shipped PDB.
//!
//! A game that ships its program database (Abiotic Factor does) names
//! every native function and type. Reading them by name replaces the
//! signature hunt for functions that are not UFunctions, such as
//! `APlayerController::InputKey`, and gives struct layouts such as
//! `FInputKeyParams` without guessing. Public symbol names in a PDB
//! are MSVC-decorated (`?InputKey@APlayerController@@UEAA...`), so a
//! function lookup matches the decorated name on `?<method>@<class>@@`.
//!
//! Both readers open and walk the PDB on every call. That is seconds
//! on a gigabyte PDB and only ever runs on a cold path.

use std::collections::HashMap;
use std::fs::File;
use std::path::Path;

use anyhow::{Context, Result, anyhow};
use pdb::{FallibleIterator, ItemFinder, PDB, SymbolData, TypeData, TypeIndex, Variant};

/// One function or data symbol: its name (decorated for public symbols,
/// plain for module procedures), its image-relative address, and for
/// module procedures the parameter type names, which is how overloads
/// that share a plain name are told apart.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Symbol {
    pub decorated: String,
    pub rva: u32,
    pub parameters: Vec<String>,
}

/// One data member of a class or struct.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Field {
    pub name: String,
    pub offset: u64,
    pub type_name: String,
}

/// A class or struct: its size and members in declaration order.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Layout {
    pub name: String,
    pub size: u64,
    pub fields: Vec<Field>,
}

/// Every public function whose decorated name contains `?<method>@<class>@@`.
///
/// Several can match one name: overloads, and `const` and non-`const`
/// versions. The caller picks by the rest of the decoration.
pub fn functions(pdb_path: &Path, class: &str, method: &str) -> Result<Vec<Symbol>> {
    publics(pdb_path, &format!("?{method}@{class}@@"), true)
}

/// Every public data symbol (a global such as `GEngine`) whose decorated
/// name contains `?<name>@@`.
pub fn globals(pdb_path: &Path, name: &str) -> Result<Vec<Symbol>> {
    publics(pdb_path, &format!("?{name}@@"), false)
}

/// Every procedure in the per-module symbol streams whose undecorated
/// name contains `needle` (`FURL::FURL`, `StaticConstructObject_Internal`).
/// Functions the linker did not put in the public table (most
/// non-virtual engine functions in a monolithic build) live here.
/// Walks every module, so it is slower than the public lookup.
pub fn procedures(pdb_path: &Path, needle: &str) -> Result<Vec<Symbol>> {
    let file = File::open(pdb_path).with_context(|| format!("open {}", pdb_path.display()))?;
    let mut pdb = PDB::open(file).context("parse pdb header")?;
    let address_map = pdb.address_map().context("read address map")?;
    let debug_information = pdb.debug_information().context("read module list")?;

    let mut found = Vec::new();
    let mut modules = debug_information.modules()?;
    while let Some(module) = modules.next()? {
        let Some(info) = pdb.module_info(&module)? else {
            continue;
        };
        let mut symbols = info.symbols()?;
        while let Some(symbol) = symbols.next()? {
            let Ok(SymbolData::Procedure(procedure)) = symbol.parse() else {
                continue;
            };
            let name = procedure.name.to_string();
            if !name.contains(needle) {
                continue;
            }
            let Some(rva) = procedure.offset.to_rva(&address_map) else {
                continue;
            };
            let entry = Symbol {
                decorated: name.into_owned(),
                rva: rva.0,
                parameters: Vec::new(),
            };
            if !found.contains(&entry) {
                found.push(entry);
            }
        }
    }
    Ok(found)
}

/// The names at the given image-relative addresses, from the public
/// table first and the per-module procedure streams for the rest.
/// One walk of the PDB for every address asked, so a disassembly that
/// collected thirty call targets names them in one pass. Addresses
/// with no symbol are absent from the result.
pub fn names_at(pdb_path: &Path, rvas: &[u32]) -> Result<HashMap<u32, String>> {
    let file = File::open(pdb_path).with_context(|| format!("open {}", pdb_path.display()))?;
    let mut pdb = PDB::open(file).context("parse pdb header")?;
    let address_map = pdb.address_map().context("read address map")?;
    let wanted: std::collections::HashSet<u32> = rvas.iter().copied().collect();
    let mut names = HashMap::new();

    let symbol_table = pdb.global_symbols().context("read global symbols")?;
    let mut symbols = symbol_table.iter();
    while let Some(symbol) = symbols.next()? {
        let Ok(SymbolData::Public(data)) = symbol.parse() else {
            continue;
        };
        let Some(rva) = data.offset.to_rva(&address_map) else {
            continue;
        };
        if wanted.contains(&rva.0) {
            names.entry(rva.0).or_insert_with(|| data.name.to_string().into_owned());
        }
    }
    if names.len() == wanted.len() {
        return Ok(names);
    }

    let debug_information = pdb.debug_information().context("read module list")?;
    let mut modules = debug_information.modules()?;
    while let Some(module) = modules.next()? {
        let Some(info) = pdb.module_info(&module)? else {
            continue;
        };
        let mut symbols = info.symbols()?;
        while let Some(symbol) = symbols.next()? {
            let Ok(SymbolData::Procedure(procedure)) = symbol.parse() else {
                continue;
            };
            let Some(rva) = procedure.offset.to_rva(&address_map) else {
                continue;
            };
            if wanted.contains(&rva.0) {
                names.entry(rva.0).or_insert_with(|| procedure.name.to_string().into_owned());
            }
        }
    }
    Ok(names)
}

fn publics(pdb_path: &Path, needle: &str, function: bool) -> Result<Vec<Symbol>> {
    let file = File::open(pdb_path).with_context(|| format!("open {}", pdb_path.display()))?;
    let mut pdb = PDB::open(file).context("parse pdb header")?;
    let symbol_table = pdb.global_symbols().context("read global symbols")?;
    let address_map = pdb.address_map().context("read address map")?;

    let mut found = Vec::new();
    let mut symbols = symbol_table.iter();
    while let Some(symbol) = symbols.next()? {
        let Ok(SymbolData::Public(data)) = symbol.parse() else {
            continue;
        };
        if data.function != function {
            continue;
        }
        let decorated = data.name.to_string();
        if !decorated.contains(needle) {
            continue;
        }
        let rva = data
            .offset
            .to_rva(&address_map)
            .ok_or_else(|| anyhow!("{decorated}: offset has no image-relative address"))?;
        found.push(Symbol {
            decorated: decorated.into_owned(),
            rva: rva.0,
            parameters: Vec::new(),
        });
    }
    Ok(found)
}

/// Member layout of the class or struct named `type_name` (undecorated,
/// as in `FInputKeyParams`). The first full definition wins; forward
/// references are skipped.
pub fn layout(pdb_path: &Path, type_name: &str) -> Result<Layout> {
    let file = File::open(pdb_path).with_context(|| format!("open {}", pdb_path.display()))?;
    let mut pdb = PDB::open(file).context("parse pdb header")?;
    let types = pdb.type_information().context("read type information")?;
    let mut finder = types.finder();

    let mut iter = types.iter();
    while let Some(item) = iter.next()? {
        finder.update(&iter);
        let Ok(TypeData::Class(class)) = item.parse() else {
            continue;
        };
        if class.properties.forward_reference() || class.name.to_string() != type_name {
            continue;
        }
        let Some(field_list) = class.fields else {
            continue;
        };
        let mut fields = Vec::new();
        collect_members(&finder, field_list, &mut fields)?;
        return Ok(Layout {
            name: type_name.to_string(),
            size: class.size,
            fields,
        });
    }
    Err(anyhow!("type '{type_name}' has no full definition in {}", pdb_path.display()))
}

/// The named values of the enum called `enum_name` (undecorated, as in
/// `EInputEvent`), in declaration order.
pub fn enumeration(pdb_path: &Path, enum_name: &str) -> Result<Vec<(String, i64)>> {
    let file = File::open(pdb_path).with_context(|| format!("open {}", pdb_path.display()))?;
    let mut pdb = PDB::open(file).context("parse pdb header")?;
    let types = pdb.type_information().context("read type information")?;
    let mut finder = types.finder();

    let mut iter = types.iter();
    while let Some(item) = iter.next()? {
        finder.update(&iter);
        let Ok(TypeData::Enumeration(enumeration)) = item.parse() else {
            continue;
        };
        if enumeration.properties.forward_reference() || enumeration.name.to_string() != enum_name
        {
            continue;
        }
        let TypeData::FieldList(list) = finder.find(enumeration.fields)?.parse()? else {
            return Err(anyhow!("enum '{enum_name}' has no field list"));
        };
        let values = list
            .fields
            .into_iter()
            .filter_map(|field| match field {
                TypeData::Enumerate(value) => {
                    Some((value.name.to_string().into_owned(), variant_i64(value.value)))
                }
                _ => None,
            })
            .collect();
        return Ok(values);
    }
    Err(anyhow!("enum '{enum_name}' has no full definition in {}", pdb_path.display()))
}

fn variant_i64(value: Variant) -> i64 {
    match value {
        Variant::U8(v) => i64::from(v),
        Variant::U16(v) => i64::from(v),
        Variant::U32(v) => i64::from(v),
        Variant::U64(v) => v as i64,
        Variant::I8(v) => i64::from(v),
        Variant::I16(v) => i64::from(v),
        Variant::I32(v) => i64::from(v),
        Variant::I64(v) => v,
    }
}

/// Append the data members of one field list, following continuation
/// lists (the PDB splits long member lists into chained records).
fn collect_members(
    finder: &ItemFinder<'_, TypeIndex>,
    list_index: TypeIndex,
    out: &mut Vec<Field>,
) -> Result<()> {
    let TypeData::FieldList(list) = finder.find(list_index)?.parse()? else {
        return Err(anyhow!("type {list_index:?} is not a field list"));
    };
    for field in list.fields {
        if let TypeData::Member(member) = field {
            out.push(Field {
                name: member.name.to_string().into_owned(),
                offset: member.offset,
                type_name: type_name(finder, member.field_type),
            });
        }
    }
    if let Some(next) = list.continuation {
        collect_members(finder, next, out)?;
    }
    Ok(())
}

/// A readable name for a member's type. Best effort: a name the PDB
/// cannot resolve prints as its raw index rather than failing the walk.
fn type_name(finder: &ItemFinder<'_, TypeIndex>, index: TypeIndex) -> String {
    let Ok(item) = finder.find(index) else {
        return format!("{index:?}");
    };
    match item.parse() {
        Ok(TypeData::Primitive(primitive)) => format!("{:?}", primitive.kind),
        Ok(TypeData::Class(class)) => class.name.to_string().into_owned(),
        Ok(TypeData::Enumeration(enumeration)) => enumeration.name.to_string().into_owned(),
        Ok(TypeData::Pointer(pointer)) => {
            format!("*{}", type_name(finder, pointer.underlying_type))
        }
        Ok(TypeData::Array(array)) => format!("[{}]", type_name(finder, array.element_type)),
        Ok(TypeData::Modifier(modifier)) => type_name(finder, modifier.underlying_type),
        Ok(TypeData::Bitfield(bitfield)) => format!(
            "{}:{}@{}",
            type_name(finder, bitfield.underlying_type),
            bitfield.length,
            bitfield.position
        ),
        Ok(other) => format!("{other:?}"),
        Err(_) => format!("{index:?}"),
    }
}
