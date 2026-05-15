// Address: 0x140151170
// Ghidra name: FUN_140151170
// ============ 0x140151170 FUN_140151170 (size=301) ============


undefined8 FUN_140151170(longlong param_1,longlong param_2,int param_3)



{

  char cVar1;

  undefined8 uVar2;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,2), cVar1 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    return 0;

  }

  if (*(char *)(param_1 + 0x2d8) != '\0') {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    return 0;

  }

  if (param_2 != 0) {

    if (param_3 < 1) {

      return 1;

    }

    if ((*(float *)(*(longlong *)(param_1 + 0x138) + 0x90) == DAT_14039ca44) &&

       (*(float *)(*(longlong *)(param_1 + 0x138) + 0x94) == DAT_14039ca44)) {

      uVar2 = FUN_14014a740(param_1,param_2,param_3);

      return uVar2;

    }

    uVar2 = FUN_14014b600(param_1,param_2,param_3);

    return uVar2;

  }

  uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_RenderPoints(): points");

  return uVar2;

}




