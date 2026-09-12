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

use std::fs::File;
use std::path::Path;

use anyhow::{Context, Result, anyhow};
use pdb::{FallibleIterator, ItemFinder, PDB, SymbolData, TypeData, TypeIndex};

/// One public function symbol: its decorated name and image-relative address.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Symbol {
    pub decorated: String,
    pub rva: u32,
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
    let file = File::open(pdb_path).with_context(|| format!("open {}", pdb_path.display()))?;
    let mut pdb = PDB::open(file).context("parse pdb header")?;
    let symbol_table = pdb.global_symbols().context("read global symbols")?;
    let address_map = pdb.address_map().context("read address map")?;
    let needle = format!("?{method}@{class}@@");

    let mut found = Vec::new();
    let mut symbols = symbol_table.iter();
    while let Some(symbol) = symbols.next()? {
        let Ok(SymbolData::Public(data)) = symbol.parse() else {
            continue;
        };
        if !data.function {
            continue;
        }
        let decorated = data.name.to_string();
        if !decorated.contains(&needle) {
            continue;
        }
        let rva = data
            .offset
            .to_rva(&address_map)
            .ok_or_else(|| anyhow!("{decorated}: offset has no image-relative address"))?;
        found.push(Symbol {
            decorated: decorated.into_owned(),
            rva: rva.0,
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
