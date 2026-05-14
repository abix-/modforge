// Address: 0x14014e730
// Ghidra name: FUN_14014e730
// ============ 0x14014e730 FUN_14014e730 (size=129) ============


undefined8 FUN_14014e730(longlong param_1)



{

  char cVar1;

  undefined8 uVar2;

  

  if (param_1 == 0) {

LAB_14014e796:

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_14014e796;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    if (*(longlong *)(param_1 + 0xf0) != 0) {

      FUN_140149cf0(param_1);

                    /* WARNING: Could not recover jumptable at 0x00014014e793. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar2 = (**(code **)(param_1 + 0xf0))(param_1);

      return uVar2;

    }

  }

  return 0;

}




