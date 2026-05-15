// Address: 0x1402f0358
// Ghidra name: FUN_1402f0358
// ============ 0x1402f0358 FUN_1402f0358 (size=163) ============


undefined8 FUN_1402f0358(undefined8 param_1,uint param_2,int *param_3,undefined8 param_4)



{

  ushort uVar1;

  undefined8 uVar2;

  int *piVar3;

  undefined8 local_res18 [2];

  

  piVar3 = &DAT_1403ff658;

  if (param_3 != (int *)0x0) {

    piVar3 = param_3;

  }

  uVar1 = (short)param_2 + 0x2400;

  if (*piVar3 == 0) {

    if (0x3ff < uVar1) {

      if ((ushort)((short)param_2 + 0x2800U) < 0x400) {

        *piVar3 = (param_2 & 0x27ff) * 0x400 + 0x10000;

        return 0;

      }

      uVar2 = FUN_1402f7f1c(param_1,param_2 & 0xffff,piVar3);

      return uVar2;

    }

  }

  else if (uVar1 < 0x400) {

    local_res18[0] = 0;

    uVar2 = FUN_1402f7f1c(param_1,(param_2 & 0x23ff) + *piVar3,local_res18);

    uVar2 = FUN_1402f7fc0(uVar2,piVar3);

    return uVar2;

  }

  uVar2 = FUN_1402f7fc8(piVar3,param_4);

  return uVar2;

}




