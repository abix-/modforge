// Address: 0x14016d540
// Ghidra name: FUN_14016d540
// ============ 0x14016d540 FUN_14016d540 (size=166) ============


ulonglong FUN_14016d540(longlong param_1)



{

  char cVar1;

  undefined4 uVar2;

  undefined4 *puVar3;

  ulonglong uVar4;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 == 0) {

LAB_14016d5d2:

    FUN_14012e850("Invalid window");

    uVar4 = 0;

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016d5d2;

    }

    uVar2 = FUN_14016ea50(param_1);

    puVar3 = (undefined4 *)FUN_14016dd30(param_1);

    if (puVar3 == (undefined4 *)0x0) {

      FUN_1401745e0(uVar2,"sdl2-compat.window.preferred_fullscreen_display");

    }

    else {

      FUN_140175360(uVar2,"sdl2-compat.window.preferred_fullscreen_display",*puVar3);

    }

    if (((*(byte *)(param_1 + 0x48) & 1) == 0) ||

       (uVar4 = (ulonglong)*(uint *)(param_1 + 200), *(uint *)(param_1 + 200) == 0)) {

      uVar4 = FUN_14016d450(param_1);

      return uVar4;

    }

  }

  return uVar4;

}




