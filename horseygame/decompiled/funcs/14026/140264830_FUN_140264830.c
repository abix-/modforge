// Address: 0x140264830
// Ghidra name: FUN_140264830
// ============ 0x140264830 FUN_140264830 (size=160) ============


undefined8 FUN_140264830(longlong param_1)



{

  undefined1 uVar1;

  longlong *plVar2;

  longlong lVar3;

  

  plVar2 = (longlong *)FUN_1401841a0(1,0x58);

  if (plVar2 == (longlong *)0x0) {

    return 0;

  }

  *plVar2 = param_1;

  uVar1 = FUN_140142940("SDL_JOYSTICK_HIDAPI_GIP_RESET_FOR_METADATA",0);

  *(undefined1 *)((longlong)plVar2 + 0x11) = uVar1;

  lVar3 = FUN_1402652e0(plVar2,0);

  FUN_140266e50(lVar3);

  if ((*(byte *)(lVar3 + 0x150) & 1) == 0) {

    lVar3 = FUN_140149350();

    plVar2[1] = lVar3 + 2000;

  }

  else {

    *(undefined1 *)(plVar2 + 2) = 1;

    FUN_140265350(lVar3);

  }

  *(longlong **)(param_1 + 0x70) = plVar2;

  *(undefined4 *)(param_1 + 0x5c) = 3;

  return 1;

}




