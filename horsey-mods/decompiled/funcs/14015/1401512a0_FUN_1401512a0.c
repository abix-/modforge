// Address: 0x1401512a0
// Ghidra name: FUN_1401512a0
// ============ 0x1401512a0 FUN_1401512a0 (size=235) ============


undefined8 FUN_1401512a0(longlong param_1)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  

  if (param_1 == 0) {

LAB_140151370:

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    return 0;

  }

  if (DAT_1403e3d60 != '\0') {

    cVar1 = FUN_1401aa7c0(param_1,2);

    if (cVar1 == '\0') goto LAB_140151370;

  }

  if (*(char *)(param_1 + 0x2d8) != '\0') {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    return 0;

  }

  if (*(longlong *)(param_1 + 0x1f0) != 0) {

    if (*(longlong *)(param_1 + 0x118) == 0) {

      iVar2 = strcmp(*(char **)(param_1 + 0x100),"gpu");

      if (iVar2 == 0) goto LAB_140151326;

    }

    uVar3 = FUN_14012e850("You can\'t present on a render target");

    return uVar3;

  }

LAB_140151326:

  if (*(char *)(param_1 + 0x2b0) != '\0') {

    FUN_14014fa80(param_1);

  }

  FUN_140149cf0(param_1);

  cVar1 = (**(code **)(param_1 + 200))(param_1);

  if ((*(char *)(param_1 + 0x122) != '\0') ||

     ((cVar1 == '\0' && (*(char *)(param_1 + 0x121) != '\0')))) {

    FUN_140155480(param_1);

  }

  return 1;

}




