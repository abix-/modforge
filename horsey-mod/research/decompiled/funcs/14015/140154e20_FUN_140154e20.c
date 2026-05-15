// Address: 0x140154e20
// Ghidra name: FUN_140154e20
// ============ 0x140154e20 FUN_140154e20 (size=213) ============


ulonglong FUN_140154e20(longlong param_1,undefined4 *param_2)



{

  longlong lVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  char cVar5;

  ulonglong uVar6;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar5 = FUN_1401aa7c0(param_1,2);

      if (cVar5 == '\0') goto LAB_140154ed5;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      uVar6 = FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return uVar6 & 0xffffffffffffff00;

    }

    lVar1 = *(longlong *)(param_1 + 0x138);

    if (param_2 == (undefined4 *)0x0) {

      *(undefined8 *)(lVar1 + 0x10) = 0xffffffffffffffff;

      *(undefined8 *)(lVar1 + 8) = 0;

    }

    else {

      if (((int)param_2[2] < 0) || ((int)param_2[3] < 0)) {

        uVar6 = FUN_14012e850("rect has a negative size");

        return uVar6;

      }

      uVar2 = param_2[1];

      uVar3 = param_2[2];

      uVar4 = param_2[3];

      *(undefined4 *)(lVar1 + 8) = *param_2;

      *(undefined4 *)(lVar1 + 0xc) = uVar2;

      *(undefined4 *)(lVar1 + 0x10) = uVar3;

      *(undefined4 *)(lVar1 + 0x14) = uVar4;

    }

    FUN_140156e80(param_1);

    uVar6 = FUN_14014af50(param_1);

    return uVar6;

  }

LAB_140154ed5:

  uVar6 = FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return uVar6 & 0xffffffffffffff00;

}




