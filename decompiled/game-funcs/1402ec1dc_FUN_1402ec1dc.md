# `FUN_1402ec1dc` @ 0x1402ec1dc

**Size**: 92 bytes
**Role**: `plays_sound` - Triggers a named sound  _(evidence: sound='AppPolicyGetProcessTerminationMethod')_
**Pattern category**: `plays_sound`

**Strings referenced**:
- `'AppPolicyGetProcessTerminationMethod'`

**Game callers** (2): [`FUN_1402ec1dc`](1402ec1dc_FUN_1402ec1dc.md), [`FUN_1402ec97c`](1402ec97c_FUN_1402ec97c.md)

**Game callees** (2): [`FUN_1402ec028`](1402ec028_FUN_1402ec028.md), [`FUN_1402ec1dc`](1402ec1dc_FUN_1402ec1dc.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 FUN_1402ec1dc(undefined8 param_1)

{

  code *pcVar1;

  undefined8 uVar2;

  if (DAT_1404240d0 == (code *)0xffffffffffffffff) {

    return 0xc0000225;

  }

  pcVar1 = DAT_1404240d0;

  if ((DAT_1404240d0 == (code *)0x0) &&

     (pcVar1 = (code *)FUN_1402ec028(0x1a,"AppPolicyGetProcessTerminationMethod",&DAT_14038eb14,

                                     "AppPolicyGetProcessTerminationMethod"), pcVar1 == (code *)0x0)

     ) {

    return 0xc0000225;

  }

  uVar2 = (*pcVar1)(0xfffffffffffffffa,param_1);

  return uVar2;

}
```