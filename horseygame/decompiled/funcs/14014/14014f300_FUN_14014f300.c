// Address: 0x14014f300
// Ghidra name: FUN_14014f300
// ============ 0x14014f300 FUN_14014f300 (size=183) ============


undefined1

FUN_14014f300(longlong param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)



{

  undefined4 uVar1;

  undefined4 uVar2;

  char cVar3;

  undefined1 uVar4;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0x3f800000;

  }

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = 0x3f800000;

  }

  if (param_4 != (undefined4 *)0x0) {

    *param_4 = 0x3f800000;

  }

  if (param_1 == 0) {

LAB_14014f38d:

    FUN_14012e850("Parameter \'%s\' is invalid","texture");

    uVar4 = 0;

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar3 = FUN_1401aa7c0(param_1,3);

      if (cVar3 == '\0') goto LAB_14014f38d;

    }

    uVar1 = *(undefined4 *)(param_1 + 0x34);

    uVar2 = *(undefined4 *)(param_1 + 0x38);

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = *(undefined4 *)(param_1 + 0x30);

    }

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = uVar1;

    }

    if (param_4 != (undefined4 *)0x0) {

      *param_4 = uVar2;

    }

    uVar4 = 1;

  }

  return uVar4;

}




