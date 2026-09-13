# Abiotic Factor mod performance

[Research index](abiotic-factor.md) | [Todo](todo.md)

The mod runs inside the host's game process. Every op that touches game
objects runs on the game thread while the frame waits, so the cost of an op
is frame time the player loses. The rules below are the same ones
misery-mod/docs/performance.md arrived at; this file records how they apply
here and what was measured.

## Rules

1. **Find an object once, then keep the pointer.** A full object list walk
   (walk_class_chain, find_objects_by_chain) costs a visible hitch. It is
   allowed once per object, never per tick, never per lookup. Re-scan only
   when the cached pointer is unreadable or no longer names what it did.
2. **Repeating work runs off the game thread and only enqueues small jobs.**
   The follow loop and the UDP client are their own threads. What they hand
   to the game thread is pointer reads and one path query.
3. **The path query is the only per-leg engine call.** Navigation asks the
   engine's A* once at the start of a leg and again only on re-plan. It never
   runs per tick.
4. **Research ops may scan; gameplay ops may not.** `players` and the
   discovery ops walk the object list by design. Tests that poll them do so
   every ten seconds at most, not every two.

## What follows the rules today

| Path | Game-thread work per cycle | Object scans |
|---|---|---|
| ai_player.follow, every 2 s | one job: both positions from cached controllers, then the path query only when farther than the follow distance | none after the first lookup of each player |
| ai_player.travel | one job: start position and the path query | none after first lookup |
| nav.find_path | one path query; navigation system cached | none after first |
| UDP walk (client) | none; ServerMove packets at 30 Hz go over the socket | none |
| players op | full controller scan | one per call, research and tests only |

## What was measured

2026-09-12: the first follow loop looked up both players by a full object
scan every two seconds, and the follow test scanned a third time for its gap
readout. The user reported the frame rate collapsing while Sophia followed.
Controllers are now cached by name; the test reads the gap every ten seconds.
That still stuttered every two seconds: the path query resolved its world
context object by class on every call, a fourth full scan per cycle. The
context is now cached like the navigation system. Frame time before and
after is not measured yet; the user's report is the only evidence.

## Open

- Measure the game thread cost of one path query on this map, so follow's
  re-plan period is chosen from a number rather than a guess.
- The UDP client sends a move every 33 ms and receives a correction for each
  while Sophia is on a stale reported position. Cost on the host is not
  measured.
