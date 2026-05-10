//! `function_table!` decl-macro: declares a struct-of-`usize` table
//! of UFunction-pointer-identity slots, plus an `install(&UClass)`
//! constructor that resolves every slot in one pass.
//!
//! Replaces the hand-rolled "12 fields each calling `lookup(cls,
//! "ClassName", "FnName")?`" pattern that every UE4SS Rust mod ends
//! up with for hook-install code.
//!
//! ```ignore
//! ueforge::function_table! {
//!     pub struct InvIfaceFns for "WBP_InventoryInterface_C" {
//!         required populate_item_grid: "PopulateItemGrid",
//!         required construct: "Construct",
//!         optional refresh_ui: "RefreshUI",
//!     }
//! }
//!
//! // Resolve once at hook install:
//! let cls = INV_IFACE.get().ok_or("class not loaded")?;
//! let fns = InvIfaceFns::install(cls)?;
//!
//! // Identity-compare in the trampoline (zero allocations):
//! if function_ptr == fns.construct { ... }
//! ```
//!
//! Required fields error out the install path with a static-string
//! error naming the missing function. Optional fields land as `0` if
//! the function isn't present -- callers test with `if slot != 0`.
//!
//! Slots are `usize` rather than `*const UFunction` so the table is
//! `Send + Sync` without an `unsafe impl`. The pointer is to a
//! UFunction that lives forever in GObjects; cast back via
//! `slot as *const UFunction` when needed.

/// See module docs.
#[macro_export]
macro_rules! function_table {
    (
        $(#[$outer:meta])*
        $vis:vis struct $name:ident for $class:literal {
            $(
                $kind:ident $field:ident : $fn_name:literal
            ),* $(,)?
        }
    ) => {
        $(#[$outer])*
        $vis struct $name {
            $(
                pub $field: usize,
            )*
        }

        impl $name {
            /// Resolve every slot from `cls`. Required fields cause
            /// an `Err(<fn-name>)` if missing; optional fields land
            /// as `0`.
            pub fn install(
                cls: &$crate::ue::UClass,
            ) -> ::core::result::Result<Self, &'static str> {
                ::core::result::Result::Ok(Self {
                    $(
                        $field: $crate::function_table!(
                            @resolve $kind cls, $class, $fn_name
                        ),
                    )*
                })
            }

            /// Class name this table was declared for. Useful for
            /// diagnostics and for callers that want to keep one
            /// copy of the string.
            pub const CLASS_NAME: &'static str = $class;
        }
    };

    (@resolve required $cls:ident, $class:literal, $fn_name:literal) => {
        $cls
            .get_function($class, $fn_name)
            .map(|f| f as *const $crate::ue::UFunction as usize)
            .ok_or($fn_name)?
    };

    (@resolve optional $cls:ident, $class:literal, $fn_name:literal) => {
        $cls
            .get_function($class, $fn_name)
            .map(|f| f as *const $crate::ue::UFunction as usize)
            .unwrap_or(0)
    };
}

#[cfg(test)]
mod tests {
    // We can't actually invoke `install` without a real UClass, but
    // we can confirm the macro expansion compiles and the resulting
    // struct has the expected shape. CLASS_NAME is a const so we
    // exercise it from a const context.

    function_table! {
        pub struct ExampleFns for "ExampleClass" {
            required first: "First",
            required second: "Second",
            optional third: "Third",
        }
    }

    #[test]
    fn class_name_const() {
        const NAME: &str = ExampleFns::CLASS_NAME;
        assert_eq!(NAME, "ExampleClass");
    }

    #[test]
    fn fields_are_usize() {
        let table = ExampleFns {
            first: 0xDEAD,
            second: 0xBEEF,
            third: 0,
        };
        assert_eq!(table.first, 0xDEAD);
        assert_eq!(table.second, 0xBEEF);
        assert_eq!(table.third, 0);
    }
}
