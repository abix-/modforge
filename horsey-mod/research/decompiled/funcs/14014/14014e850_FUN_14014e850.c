// Address: 0x14014e850
// Ghidra name: FUN_14014e850
// ============ 0x14014e850 FUN_14014e850 (size=244) ============


ulonglong FUN_14014e850(longlong param_1,undefined4 *param_2,undefined4 *param_3)



{

  char cVar1;

  ulonglong uVar2;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0;

  }

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_14014e91f;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      uVar2 = FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return uVar2 & 0xffffffffffffff00;

    }

    if (*(code **)(param_1 + 8) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00014014e8e4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar2 = (**(code **)(param_1 + 8))(param_1,param_2,param_3);

      return uVar2;

    }

    if (*(longlong *)(param_1 + 0x118) != 0) {

      uVar2 = FUN_14016ebe0(*(longlong *)(param_1 + 0x118),param_2,param_3);

      return uVar2;

    }

    return 1;

  }

LAB_14014e91f:

  uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return uVar2 & 0xffffffffffffff00;

}




