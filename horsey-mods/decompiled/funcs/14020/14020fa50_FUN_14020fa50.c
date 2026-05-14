// Address: 0x14020fa50
// Ghidra name: FUN_14020fa50
// ============ 0x14020fa50 FUN_14020fa50 (size=219) ============


undefined8 FUN_14020fa50(longlong param_1,undefined4 param_2)



{

  longlong lVar1;

  char cVar2;

  undefined4 uVar3;

  longlong lVar4;

  longlong *plVar5;

  

  lVar4 = FUN_140210760(param_2);

  uVar3 = 1;

  lVar1 = *(longlong *)(lVar4 + 0x70);

  plVar5 = (longlong *)FUN_1401841a0(1,0x28);

  if (plVar5 != (longlong *)0x0) {

    *plVar5 = lVar4;

    *(longlong **)(param_1 + 0x148) = plVar5;

    cVar2 = FUN_140210780(lVar1);

    if ((cVar2 == '\0') && (cVar2 = FUN_14000c9a0(), cVar2 == '\0')) {

      *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(lVar1 + 0x7c);

      *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(lVar1 + 0x80);

      uVar3 = *(undefined4 *)(lVar1 + 0x84);

    }

    else {

      *(undefined4 *)(param_1 + 0x44) = 6;

      *(undefined4 *)(param_1 + 0x70) = 0xb;

    }

    *(undefined4 *)(param_1 + 0x60) = uVar3;

    if ((*(byte *)(lVar1 + 0x6c) & 3) != 0) {

      uVar3 = FUN_140158c10(param_1);

      FUN_140175280(uVar3,"SDL.joystick.cap.rumble",1);

    }

    if ((*(byte *)(lVar1 + 0x6c) & 0xc) != 0) {

      uVar3 = FUN_140158c10(param_1);

      FUN_140175280(uVar3,"SDL.joystick.cap.trigger_rumble",1);

    }

    return 1;

  }

  return 0;

}




