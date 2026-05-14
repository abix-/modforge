# `FUN_1402ebdf0` @ 0x1402ebdf0

**Size**: 51 bytes
**Role**: small helper (purpose unclear without reading)

**Game callers** (3): `FUN_1402e8e00`, `FUN_1402e8f40`, `FUN_1402ebdf0`

**Game callees** (2): `FUN_1402e68b0`, `FUN_1402ebdf0`

**Vendor callees** (0) - SDL/CRT/etc.

## Decompiled

```c
void FUN_1402ebdf0(int param_1)

{

  undefined4 *puVar1;

  if (param_1 == 1) {

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 0x21;

  }

  else if ((param_1 == 2) || (param_1 == 3)) {

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 0x22;

    return;

  }

  return;

}
```