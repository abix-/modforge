// Address: 0x1402000e0
// Ghidra name: FUN_1402000e0
// ============ 0x1402000e0 FUN_1402000e0 (size=209) ============


undefined1 FUN_1402000e0(undefined8 param_1,undefined8 param_2,undefined4 param_3)



{

  char cVar1;

  char *pcVar2;

  undefined *puVar3;

  undefined8 uVar4;

  

  pcVar2 = (char *)FUN_140142960("SDL_RENDER_VSYNC");

  if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {

    cVar1 = FUN_1401749e0(param_3,"SDL.renderer.create.present_vsync",0);

    puVar3 = &DAT_140338120;

    if (cVar1 == '\0') {

      puVar3 = &DAT_14030df48;

    }

    FUN_140142e90("SDL_RENDER_VSYNC",puVar3);

    uVar4 = FUN_14016ee90(param_2);

    FUN_140142e90("SDL_RENDER_VSYNC",&DAT_14039bcb9);

  }

  else {

    uVar4 = FUN_14016ee90(param_2);

  }

  cVar1 = FUN_1401489c0(uVar4);

  if (cVar1 != '\0') {

    cVar1 = FUN_140200370(param_1,uVar4,param_3);

    if (cVar1 != '\0') {

      return 1;

    }

    FUN_14016b5e0(param_2);

  }

  return 0;

}




