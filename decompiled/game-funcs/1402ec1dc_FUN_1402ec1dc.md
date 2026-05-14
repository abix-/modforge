# `FUN_1402ec1dc` @ 0x1402ec1dc

**Size**: 92 bytes
**Role**: small helper (purpose unclear without reading)

**Strings referenced**:
- `'AppPolicyGetProcessTerminationMethod'`

**Game callers** (2): `FUN_1402ec1dc`, `FUN_1402ec97c`

**Game callees** (2): `FUN_1402ec028`, `FUN_1402ec1dc`

**Vendor callees** (0) - SDL/CRT/etc.

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