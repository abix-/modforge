# Native ghost-generation trace

## Question

Which instruction in Dwarf Fortress 53.16 changes a dead fortress citizen into
an active ghost, and which function owns the eligibility decision immediately
before that write?

The answer must come from the live process. Post-creation Lua cleanup is not
the requested feature.

## Instrument

`dfhooks_modforge.dll` is a minimal native dfhooks library. DFHack's chainloader
loads it into the Dwarf Fortress process after DFHack and calls its lifecycle
exports. It exposes modforge's existing DR0 hardware watchpoint at:

```text
POST http://127.0.0.1:33078/op
```

The watchpoint is installed on all existing process threads except its own HTTP
worker. A matching write records:

- the OS thread ID;
- the instruction address after the write;
- module and RVA;
- `rcx`, `rdx`, `r8`, and `r9`;
- stack values that resolve into the main executable;
- the watched bytes immediately after the instruction.

The final item is important because `unit.flags3` has several unrelated flags.
In the 53.16 structure, `ghostly` is bit 12, mask `0x1000`.

## Build and load

Build:

```powershell
cargo build --release -p dwarf-fortress-mod
```

Copy `target/release/dfhooks_modforge.dll` into the directory containing
`Dwarf Fortress.exe`. This relies on DFHack's dfhooks chainloader naming
convention and can coexist with DFHack's own priority-100 library. This adapter
uses priority 50. The current chainloader initializes higher priorities first
and shuts down in reverse, so DFHack is available before the adapter starts
and remains available until after the adapter stops.

Install the `dfhack/` folder as a normal Dwarf Fortress mod, or copy
`modforge-ghost-target.lua` into `hack/scripts/`.

After starting the game, verify the in-process adapter:

```powershell
curl.exe -X POST http://127.0.0.1:33078/op `
  -H "Content-Type: application/json" `
  -d '{"op":"process.modules","args":{}}'
```

The response must name `Dwarf Fortress.exe`, DFHack, and
`dfhooks_modforge.dll`.

## Capture procedure

Use only a disposable research save.

1. Select a living fortress citizen and run:

   ```text
   modforge-ghost-target
   ```

   Record its unit ID. Kill that citizen through a controlled in-game event.
   Do not delete or transform the unit.

2. Run the command again by ID after death:

   ```text
   modforge-ghost-target UNIT_ID
   ```

   Confirm the address is unchanged, `killed=true`, `ghostly=false`, and
   `own_group=true`.

3. Arm a long write watch on the printed `flags3_address`:

   ```powershell
   curl.exe -X POST http://127.0.0.1:33078/op `
     -H "Content-Type: application/json" `
     -d '{"op":"watch_writes","args":{"addr":"0xADDRESS","len":4,"mode":"write","duration_ms":1800000}}'
   ```

4. Advance the disposable fortress until the citizen becomes a ghost. Do not
   use `modtools/create-unit`; that constructs a ghost through a different
   path and would answer the wrong question.

5. In the returned records, find the first `value_after_hex` where mask
   `0x1000` became set. Record its `rip_module`, `rip_rva`, thread ID,
   registers, and executable return-address chain.

6. Read bytes around that RVA and decompile the containing function. Then arm
   an execution watchpoint on the candidate function entry to capture its
   arguments on a second ghost transition.

7. Identify the branch that decides ghost eligibility. The production hook
   must bypass that branch before `ghostly`, `ghost_info`, or active-unit state
   is mutated, while preserving ordinary death history and corpses.

## Evidence required before the hook

- Two independent citizen deaths hit the same owning function.
- The writer runs on the simulation thread.
- The candidate branch distinguishes haunting from ordinary death processing.
- Bypassing it produces no ghost and leaves death/corpse/history state intact.
- Save/load twice after suppression produces no corruption or delayed ghost.
- A disabled setting restores vanilla behavior.

## Installed target

The local target is:

```text
C:\Games\Steam\steamapps\common\Dwarf Fortress
```

Steam's app manifest confirms this as the installed game directory. Binary
presence and the currently installed DFHack version still need verification
from the terminal. The remaining prerequisites are a matching DFHack
installation, a successful release build, and staging
`dfhooks_modforge.dll` beside the executable.
