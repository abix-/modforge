// Address: 0x1401545c0
// Ghidra name: FUN_1401545c0
// ============ 0x1401545c0 FUN_1401545c0 (size=180) ============


undefined1 FUN_1401545c0(longlong param_1,undefined4 *param_2)



{

  longlong lVar1;

  char cVar2;

  undefined1 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,2);

      if (cVar2 == '\0') goto LAB_140154654;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    lVar1 = *(longlong *)(param_1 + 0x138);

    if (((param_2 == (undefined4 *)0x0) || ((int)param_2[2] < 0)) || ((int)param_2[3] < 0)) {

      *(undefined1 *)(lVar1 + 0x48) = 0;

      uVar4 = 0;

      uVar5 = 0;

      uVar6 = 0;

      uVar7 = 0;

    }

    else {

      *(undefined1 *)(lVar1 + 0x48) = 1;

      uVar4 = *param_2;

      uVar5 = param_2[1];

      uVar6 = param_2[2];

      uVar7 = param_2[3];

    }

    *(undefined4 *)(lVar1 + 0x28) = uVar4;

    *(undefined4 *)(lVar1 + 0x2c) = uVar5;

    *(undefined4 *)(lVar1 + 0x30) = uVar6;

    *(undefined4 *)(lVar1 + 0x34) = uVar7;

    FUN_140156de0(param_1);

    uVar3 = FUN_14014adb0(param_1);

    return uVar3;

  }

LAB_140154654:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




