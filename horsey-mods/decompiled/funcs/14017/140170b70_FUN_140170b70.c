// Address: 0x140170b70
// Ghidra name: FUN_140170b70
// ============ 0x140170b70 FUN_140170b70 (size=335) ============


undefined8 FUN_140170b70(longlong param_1,undefined8 *param_2)



{

  char cVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_140170ca6;

    }

    if ((*(uint *)(param_1 + 0x48) & 0xc0000) != 0) {

      FUN_14012e850("Operation invalid on popup windows");

      return 0;

    }

    if (param_2 == (undefined8 *)0x0) {

      *(undefined8 *)(param_1 + 0xa0) = 0;

      *(undefined8 *)(param_1 + 0xa8) = 0;

      *(undefined8 *)(param_1 + 0xb0) = 0;

      *(undefined8 *)(param_1 + 0xb8) = 0;

      *(undefined8 *)(param_1 + 0xc0) = 0;

    }

    else {

      lVar2 = FUN_14016d920(param_2);

      if (lVar2 == 0) {

        uVar3 = FUN_14012e850("Invalid fullscreen display mode");

        return uVar3;

      }

      uVar3 = param_2[1];

      *(undefined8 *)(param_1 + 0xa0) = *param_2;

      *(undefined8 *)(param_1 + 0xa8) = uVar3;

      uVar3 = param_2[3];

      *(undefined8 *)(param_1 + 0xb0) = param_2[2];

      *(undefined8 *)(param_1 + 0xb8) = uVar3;

      *(undefined8 *)(param_1 + 0xc0) = param_2[4];

    }

    *(undefined8 *)(param_1 + 200) = *(undefined8 *)(param_1 + 0xa0);

    *(undefined8 *)(param_1 + 0xd0) = *(undefined8 *)(param_1 + 0xa8);

    *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_1 + 0xb0);

    *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0xb4);

    *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xb8);

    *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xbc);

    *(undefined8 *)(param_1 + 0xe8) = *(undefined8 *)(param_1 + 0xc0);

    if ((*(byte *)(param_1 + 0x48) & 0x49) == 1) {

      FUN_140173190(param_1,2,1);

      FUN_140172f30(param_1);

    }

    return 1;

  }

LAB_140170ca6:

  FUN_14012e850("Invalid window");

  return 0;

}




