// Address: 0x1401737d0
// Ghidra name: FUN_1401737d0
// ============ 0x1401737d0 FUN_1401737d0 (size=197) ============


ulonglong FUN_1401737d0(longlong param_1,undefined8 param_2,undefined4 param_3)



{

  char cVar1;

  ulonglong uVar2;

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

    return uVar2 & 0xffffffffffffff00;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 != '\0')))) {

    if (*(char *)(param_1 + 0x108) != '\0') {

                    /* WARNING: Could not recover jumptable at 0x000140173874. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar2 = (**(code **)(DAT_1403fc410 + 0x150))(DAT_1403fc410,param_1,param_2,param_3);

      return uVar2;

    }

    uVar2 = FUN_14012e850(

                         "Window surface is invalid, please call SDL_GetWindowSurface() to get a new surface"

                         );

    return uVar2;

  }

  uVar2 = FUN_14012e850("Invalid window");

  return uVar2 & 0xffffffffffffff00;

}




