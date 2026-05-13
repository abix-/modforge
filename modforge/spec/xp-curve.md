# XP curve

Pure math; no IO, no engine access. Implementation in
`modforge::rpg::xp` and consumed natively by both frameworks.

## Cumulative XP for a level

```
cumulative_xp_for_level(level) = round(base * level^exponent)
```

Capped at `max_level`. Defaults:

| Param | Default |
|---|---|
| `base` | 100 |
| `exponent` | 1.8 |
| `max_level` | 50 |

Level 1 -> 0 XP. Level 2 -> `round(100 * 2^1.8)` = 348. The
curve is generous early and flat at the end.

`max_level` MUST be `<= 1024`. `level_for_xp` is a linear scan
of `max_level` iterations and runs on every snapshot fetch.

## Inverse: level for a total XP

```
level_for_xp(xp) = max k such that cumulative_xp_for_level(k) <= xp
```

Implementation is a linear scan from 1 to `max_level`. Cost is
sub-microsecond at typical max_level.

## Tests

The pure math has unit tests in `modforge::rpg::xp::tests`:

- `cumulative_xp_for_level(1) == 0`
- `cumulative_xp_for_level(max_level) == round(base * max_level^exponent)`
- For all 1 <= L <= max_level:
  `level_for_xp(cumulative_xp_for_level(L)) == L`
- `level_for_xp(0) == 1`
- `level_for_xp(u64::MAX) == max_level`
