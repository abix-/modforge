# Relays

> **Authoritative on:** how relays (Relay) fire their outputs: at Start,
> with a delay, and on load. The other relay and trigger kinds (RelayAuto,
> TriggerMultiple, ...) are not researched yet (todo).
>
> Index of every game system's doc: [`research.md`](research.md).

## Relay (2026-10-03, from Relay.cs; per-area counts not measured yet)

A relay with `triggerAtStart` fires its outputs from Start, three
end-of-frames later (StartDelay, Relay.cs:83-97). `triggerOutputs` does
nothing when the relay's object is switched off, when it is
`fireOnceOnly` and already fired, or when its required task items,
objectives or dialogue variables are not met (106-117). An output with a
`delay` runs a coroutine that counts `delayLeft` down by `Time.deltaTime`
each frame, then fires (delayTrigger, 218-237). `delayLeft` and
`firedOnce` are saved (only `fsIgnore` fields are not, 9-54);
OnLoadingGame restarts the countdown for every output with `delayLeft`
left (65-81).

In the game, Start and OnLoadingGame run on every area load, so start
outputs fire on every visit and delayed outputs resume. In kept areas:
Start runs on the first visit only (Relay is not in START_AGAIN), and the
load phases run on the first visit only, so start outputs do not fire
again on later visits, and a countdown stopped when the area is switched
off (Unity stops a switched-off object's coroutines) is not restarted.

Timers that catch up in OnMapChanged: RelayTimer, RelayOnDayChange
([`time.md`](time.md)). RelayPlayerDistance fires its outputs on a new
day when the player is far (a clock listener, same doc).
