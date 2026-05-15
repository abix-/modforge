// Address: 0x14017b8d0
// Ghidra name: FUN_14017b8d0
// ============ 0x14017b8d0 FUN_14017b8d0 (size=75) ============


undefined8 FUN_14017b8d0(uint param_1,undefined8 param_2,int param_3,int param_4)



{

  undefined8 uVar1;

  

  param_1 = param_1 & 0x1f;

  if (param_1 == 1) {

LAB_14017b916:

    uVar1 = FUN_14017a3d0();

    return uVar1;

  }

  if (param_1 == 2) {

    if (param_4 != 8) {

      if ((param_4 != 10) && (param_4 != 0x10)) {

        return 0;

      }

      goto LAB_14017b8ee;

    }

    if (0x240 < param_3) goto LAB_14017b916;

  }

  else if ((param_1 != 5) && (param_1 != 6)) {

    if (param_1 != 9) {

      return 0;

    }

LAB_14017b8ee:

    uVar1 = FUN_14017a370();

    return uVar1;

  }

  uVar1 = FUN_14017a3a0();

  return uVar1;

}




