// Address: 0x140150100
// Ghidra name: FUN_140150100
// ============ 0x140150100 FUN_140150100 (size=161) ============


undefined1 FUN_140150100(longlong param_1,undefined1 *param_2)



{

  char cVar1;

  undefined1 uVar2;

  undefined1 local_18 [16];

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_140150181;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    if (param_2 == (undefined1 *)0x0) {

      FUN_14014a2f0(param_1,local_18);

      param_2 = local_18;

    }

    uVar2 = FUN_1401501b0(param_1,param_2,1);

    return uVar2;

  }

LAB_140150181:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




