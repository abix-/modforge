//! Unity-side selector resolvers. The selector grammar
//! (addr:0x..., class:Foo, ...) is engine-agnostic. Unity adds:
//!   - singleton:Foo -> Singleton<Foo>.Instance (game pattern)
//!   - static_instance:Foo -> StaticInstance<Foo>.Instance
//!   - class:Foo / first_class:Foo -> first live MonoObject of type
//!
//! Resolvers return an opaque handle string ("handle:<int>")
//! suitable for downstream `inspect_object` / `read_field` ops.

use parking_lot::Mutex;
use serde_json::{Value as Json, json};

use crate::mono::MonoType;

pub struct SelectorDef {
    pub prefix: &'static str,
    pub summary: &'static str,
    pub resolver: fn(&str) -> Option<Result<String, String>>,
}

pub struct SelectorRegistry {
    entries: Mutex<Vec<SelectorDef>>,
}

impl SelectorRegistry {
    pub const fn new() -> Self {
        Self {
            entries: Mutex::new(Vec::new()),
        }
    }

    pub fn register(&self, def: SelectorDef) {
        self.entries.lock().push(def);
    }

    pub fn register_many<I: IntoIterator<Item = SelectorDef>>(&self, defs: I) {
        let mut g = self.entries.lock();
        for d in defs {
            g.push(d);
        }
    }

    pub fn resolve(&self, selector: &str) -> Result<String, String> {
        let g = self.entries.lock();
        for def in g.iter() {
            if let Some(r) = (def.resolver)(selector) {
                return r;
            }
        }
        Err(format!(
            "unknown selector '{selector}'; try op:list_selectors"
        ))
    }

    pub fn list_json(&self) -> Json {
        let g = self.entries.lock();
        json!({
            "selectors": g.iter().map(|d| json!({
                "prefix": d.prefix,
                "summary": d.summary,
            })).collect::<Vec<_>>()
        })
    }
}

pub static SELECTOR_REGISTRY: SelectorRegistry = SelectorRegistry::new();

pub fn resolve(selector: &str) -> Result<String, String> {
    SELECTOR_REGISTRY.resolve(selector)
}

pub fn list_json() -> Json {
    SELECTOR_REGISTRY.list_json()
}

pub fn register_builtins() {
    SELECTOR_REGISTRY.register_many([
        SelectorDef {
            prefix: "handle:<int>",
            summary: "Existing Mono object handle",
            resolver: try_handle,
        },
        SelectorDef {
            prefix: "singleton:<Type>",
            summary: "Live Singleton<T>.Instance for the named type",
            resolver: try_singleton,
        },
        SelectorDef {
            prefix: "static_instance:<Type>",
            summary: "Live StaticInstance<T>.Instance for the named type",
            resolver: try_static_instance,
        },
        SelectorDef {
            prefix: "class:<Type>",
            summary: "First live instance of the named type (alias for first_class)",
            resolver: try_class,
        },
        SelectorDef {
            prefix: "first_class:<Type>",
            summary: "First live instance of the named type",
            resolver: try_first_class,
        },
    ]);
}

fn try_handle(s: &str) -> Option<Result<String, String>> {
    let rest = s.strip_prefix("handle:")?;
    Some(rest.parse::<i32>().map_or_else(
        |e| Err(format!("bad handle '{s}': {e}")),
        |_| Ok(s.to_string()),
    ))
}

fn try_singleton(s: &str) -> Option<Result<String, String>> {
    let name = s.strip_prefix("singleton:")?;
    Some(resolve_singleton(name))
}

fn try_static_instance(s: &str) -> Option<Result<String, String>> {
    let name = s.strip_prefix("static_instance:")?;
    Some(resolve_static_instance(name))
}

fn try_class(s: &str) -> Option<Result<String, String>> {
    let name = s.strip_prefix("class:")?;
    Some(resolve_first_class(name))
}

fn try_first_class(s: &str) -> Option<Result<String, String>> {
    let name = s.strip_prefix("first_class:")?;
    Some(resolve_first_class(name))
}

fn resolve_singleton(name: &str) -> Result<String, String> {
    let ty = MonoType::find(name).ok_or_else(|| format!("type '{name}' not found"))?;
    let inst = ty
        .singleton_instance()
        .ok_or_else(|| format!("Singleton<{name}>.Instance is null"))?;
    let h = inst.handle().0;
    std::mem::forget(inst);
    Ok(format!("handle:{h}"))
}

fn resolve_static_instance(name: &str) -> Result<String, String> {
    let ty = MonoType::find(name).ok_or_else(|| format!("type '{name}' not found"))?;
    let inst = ty
        .static_instance()
        .ok_or_else(|| format!("StaticInstance<{name}>.Instance is null"))?;
    let h = inst.handle().0;
    std::mem::forget(inst);
    Ok(format!("handle:{h}"))
}

fn resolve_first_class(name: &str) -> Result<String, String> {
    let ty = MonoType::find(name).ok_or_else(|| format!("type '{name}' not found"))?;
    let arr = ty.walk(false)?;
    let first = arr
        .get("instances")
        .and_then(Json::as_array)
        .and_then(|a| a.first())
        .ok_or_else(|| format!("no live instance of '{name}'"))?;
    let h = first
        .get("handle")
        .and_then(Json::as_i64)
        .ok_or("walk: missing 'handle' on instance entry")?;
    Ok(format!("handle:{h}"))
}
