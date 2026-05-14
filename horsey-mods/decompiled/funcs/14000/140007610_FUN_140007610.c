// Address: 0x140007610
// Ghidra name: FUN_140007610
// ============ 0x140007610 FUN_140007610 (size=381) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_140007610(longlong param_1,float param_2,undefined4 param_3,undefined4 param_4)



{

  longlong lVar1;

  uint uVar2;

  undefined1 auStack_88 [32];

  float local_68;

  float local_64;

  float local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined1 local_54;

  ulonglong local_50;

  

  local_50 = DAT_1403e8b00 ^ (ulonglong)auStack_88;

  uVar2 = *(uint *)(param_1 + 0x19298);

  if ((uVar2 & 1) != 0) {

    FUN_1400117d0(param_1 + 0x192a0,param_1 + 0x192a0);

    uVar2 = *(uint *)(param_1 + 0x19298) & 0xfffffffe;

  }

  *(uint *)(param_1 + 0x19298) = uVar2 | 2;

  if (param_2 <= 0.0) {

    local_64 = 0.0;

  }

  else {

    local_64 = DAT_14039ca44 / param_2;

  }

  local_60 = param_2 * *(float *)(param_1 + 0x19358);

  local_54 = *(undefined1 *)(param_1 + 0x1935c);

  local_68 = param_2;

  local_5c = param_3;

  local_58 = param_4;

  FUN_1400111f0(param_1 + 0x192a0);

  *(undefined4 *)(param_1 + 0x19364) = 0;

  if ((*(char *)(param_1 + 0x1935f) != '\0') && (0.0 < local_68)) {

    FUN_1400063f0(param_1,&local_68);

    *(undefined4 *)(param_1 + 0x19368) = 0;

  }

  if (*(char *)(param_1 + 0x1935d) != '\0') {

    if (local_68 <= 0.0) goto LAB_140007733;

    FUN_140006950(param_1,&local_68);

    *(undefined4 *)(param_1 + 0x1937c) = 0;

  }

  if (0.0 < local_68) {

    *(float *)(param_1 + 0x19358) = local_64;

  }

LAB_140007733:

  if ((*(byte *)(param_1 + 0x19298) & 4) != 0) {

    for (lVar1 = *(longlong *)(param_1 + 0x19320); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x68))

    {

      *(undefined8 *)(lVar1 + 0x4c) = 0;

      *(undefined4 *)(lVar1 + 0x54) = 0;

    }

  }

  *(uint *)(param_1 + 0x19298) = *(uint *)(param_1 + 0x19298) & 0xfffffffd;

  *(undefined4 *)(param_1 + 0x19360) = 0;

  return;

}




