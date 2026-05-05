// RPG / level-up subsystem.
//
// Spike A: kill detection. Hooks Maine.HealthComponent's ProcessEvent slot
// and logs every Kill call with the dying actor's class and the killer's
// controller (resolved from FDamageInfo.InstigatorController). Used to
// prove out the data we need before plumbing XP / levels / perks.
//
// Field offsets all from C:\tools\work\sdk\SDK:
//   UHealthComponent.LastDamageInfo:     0x03B0  (Maine_classes.hpp:42287)
//   FDamageInfo.InstigatorController:    0x0020  (Maine_structs.hpp:4815)
//   FDamageInfo.Target:                  0x0030
//
// HealthComponent is `final`, so its vtable is unique -- one hook covers
// every instance in the world.

pub mod kill_hook;
