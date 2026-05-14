// Address: 0x14021f7b0
// Ghidra name: FUN_14021f7b0
// ============ 0x14021f7b0 FUN_14021f7b0 (size=179) ============


undefined8 FUN_14021f7b0(longlong *param_1,ulonglong param_2)



{

  ulonglong uVar1;

  ulonglong uVar2;

  longlong lVar3;

  ulonglong uVar4;

  

  uVar1 = param_1[2];

  if (uVar1 == 0) {

    uVar4 = param_2;

    if ((0xfffffffffffeffff < param_2) || (uVar4 = 0x1000, param_2 < 0x1001)) goto LAB_14021f83a;

    uVar4 = param_2 + 0x10000 & 0xffffffffffff0000;

  }

  else {

    uVar2 = param_1[3];

    if (~uVar2 < param_2) {

      FUN_14012e770();

      return 0;

    }

    uVar4 = uVar2 + param_2;

    if (0xffff < ~param_2 - uVar2) {

      if (uVar4 <= uVar1) {

        return 1;

      }

      uVar4 = (uVar4 & 0xffffffffffff0000) + 0x10000;

    }

  }

  if (uVar4 <= uVar1) {

    return 1;

  }

LAB_14021f83a:

  lVar3 = FUN_140184230(param_1[1],uVar4);

  if (lVar3 != 0) {

    param_1[1] = lVar3;

    param_1[2] = uVar4;

    *param_1 = lVar3;

    return 1;

  }

  return 0;

}




