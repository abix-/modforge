# `FUN_1402ebab0` @ 0x1402ebab0

**Size**: 778 bytes
**Role**: unclassified game logic

**Game callers** (4): `FUN_1402eb470`, `FUN_1402eba80`, `FUN_1402ebab0`, `FUN_1402ebdc0`

**Game callees** (3): `FUN_1402e8c00`, `FUN_1402e8ce0`, `FUN_1402ebab0`

**Vendor callees** (0) - SDL/CRT/etc.

## Decompiled

```c
void FUN_1402ebab0(uint *param_1,ulonglong *param_2,ulonglong param_3,int param_4,uint *param_5,

                  uint *param_6,int param_7)

{

  uint uVar1;

  ulonglong uVar2;

  DWORD dwExceptionCode;

  uint *local_res8;

  dwExceptionCode = 0xc000000d;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  if ((param_3 & 0x10) != 0) {

    dwExceptionCode = 0xc000008f;

    param_1[1] = param_1[1] | 1;

  }

  if ((param_3 & 2) != 0) {

    dwExceptionCode = 0xc0000093;

    param_1[1] = param_1[1] | 2;

  }

  if ((param_3 & 1) != 0) {

    dwExceptionCode = 0xc0000091;

    param_1[1] = param_1[1] | 4;

  }

  if ((param_3 & 4) != 0) {

    dwExceptionCode = 0xc000008e;

    param_1[1] = param_1[1] | 8;

  }

  if ((param_3 & 8) != 0) {

    dwExceptionCode = 0xc0000090;

    param_1[1] = param_1[1] | 0x10;

  }

  param_1[2] = param_1[2] ^ (~((int)(*param_2 >> 7) << 4) ^ param_1[2]) & 0x10;

  param_1[2] = param_1[2] ^ (~((int)(*param_2 >> 9) << 3) ^ param_1[2]) & 8;

  param_1[2] = param_1[2] ^ (~((int)(*param_2 >> 10) << 2) ^ param_1[2]) & 4;

  param_1[2] = param_1[2] ^ (~((int)(*param_2 >> 0xb) * 2) ^ param_1[2]) & 2;

  param_1[2] = param_1[2] ^ (~((uint)*param_2 >> 0xc) ^ param_1[2]) & 1;

  local_res8 = param_1;

  uVar2 = FUN_1402e8ce0();

  if ((uVar2 & 1) != 0) {

    local_res8[3] = local_res8[3] | 0x10;

  }

  if ((uVar2 & 4) != 0) {

    local_res8[3] = local_res8[3] | 8;

  }

  if ((uVar2 & 8) != 0) {

    local_res8[3] = local_res8[3] | 4;

  }

  if ((uVar2 & 0x10) != 0) {

    local_res8[3] = local_res8[3] | 2;

  }

  if ((uVar2 & 0x20) != 0) {

    local_res8[3] = local_res8[3] | 1;

  }

  uVar1 = (uint)*param_2 & 0x6000;

  if (uVar1 == 0) {

    *local_res8 = *local_res8 & 0xfffffffc;

  }

  else if (uVar1 == 0x2000) {

    *local_res8 = *local_res8 & 0xfffffffd;

    *local_res8 = *local_res8 | 1;

  }

  else if (uVar1 == 0x4000) {

    *local_res8 = *local_res8 & 0xfffffffe;

    *local_res8 = *local_res8 | 2;

  }

  else if (uVar1 == 0x6000) {

    *local_res8 = *local_res8 | 3;

  }

  *local_res8 = *local_res8 ^ (param_4 << 5 ^ *local_res8) & 0x1ffe0;

  local_res8[8] = local_res8[8] | 1;

  if (param_7 == 0) {

    local_res8[8] = local_res8[8] & 0xffffffe3 | 2;

    *(undefined8 *)(local_res8 + 4) = *(undefined8 *)param_5;

    local_res8[0x18] = local_res8[0x18] | 1;

    local_res8[0x18] = local_res8[0x18] & 0xffffffe3 | 2;

    *(undefined8 *)(local_res8 + 0x14) = *(undefined8 *)param_6;

  }

  else {

    local_res8[8] = local_res8[8] & 0xffffffe1;

    local_res8[4] = *param_5;

    local_res8[0x18] = local_res8[0x18] | 1;

    local_res8[0x18] = local_res8[0x18] & 0xffffffe1;

    local_res8[0x14] = *param_6;

  }

  FUN_1402e8c00();

  RaiseException(dwExceptionCode,0,1,(ULONG_PTR *)&local_res8);

  if ((local_res8[2] & 0x10) != 0) {

    *param_2 = *param_2 & 0xffffffffffffff7f;

  }

  if ((local_res8[2] & 8) != 0) {

    *param_2 = *param_2 & 0xfffffffffffffdff;

  }

  if ((local_res8[2] & 4) != 0) {

    *param_2 = *param_2 & 0xfffffffffffffbff;

  }

  if ((local_res8[2] & 2) != 0) {

    *param_2 = *param_2 & 0xfffffffffffff7ff;

  }

  if ((local_res8[2] & 1) != 0) {

    *param_2 = *param_2 & 0xffffffffffffefff;

  }

  uVar1 = *local_res8 & 3;

  if (uVar1 == 0) {

    *param_2 = *param_2 & 0xffffffffffff9fff;

  }

  else if (uVar1 == 1) {

    *param_2 = *param_2 & 0xffffffffffffbfff;

    *param_2 = *param_2 | 0x2000;

  }

  else if (uVar1 == 2) {

    *param_2 = *param_2 & 0xffffffffffffdfff;

    *param_2 = *param_2 | 0x4000;

  }

  else if (uVar1 == 3) {

    *param_2 = *param_2 | 0x6000;

  }

  if (param_7 == 0) {

    *(undefined8 *)param_6 = *(undefined8 *)(local_res8 + 0x14);

  }

  else {

    *param_6 = local_res8[0x14];

  }

  return;

}
```