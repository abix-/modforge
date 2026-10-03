# Dialogue

> **Authoritative on:** dialogue (PixelCrushers Dialogue System,
> DialogueController, DialogueVariable). How dialogue triggers start per
> load or Start is not researched yet (todo).
>
> Index of every game system's doc: [`research.md`](research.md).

## Dialogue System

Uses the third-party Dialogue System for Unity. DialogueController
manages active conversations. DialogueVariable stores persistent
state checked by NPC reactions and quest conditions. Its data is saved
in `Globals.dialogue` and applied at the end of a load
([`save.md`](save.md)).
