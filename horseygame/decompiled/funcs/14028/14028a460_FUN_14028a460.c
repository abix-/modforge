// Address: 0x14028a460
// Ghidra name: FUN_14028a460
// ============ 0x14028a460 FUN_14028a460 (size=222) ============


undefined8 FUN_14028a460(longlong param_1,longlong param_2)



{

  longlong *plVar1;

  undefined8 uVar2;

  longlong lVar3;

  

  plVar1 = (longlong *)FUN_1401841a0(1,0x10);

  if (plVar1 == (longlong *)0x0) {

    return 0;

  }

  *(longlong **)(param_2 + 0x188) = plVar1;

  if (*(int *)(param_2 + 0x18) == 0x1fff0000) {

    *(undefined4 *)(param_2 + 0x18) = 0;

  }

  if (*(int *)(param_2 + 0x1c) == 0x1fff0000) {

    *(undefined4 *)(param_2 + 0x1c) = 0;

  }

  *plVar1 = param_2;

  if ((*(byte *)(param_2 + 0x48) & 2) == 0) {

    plVar1[1] = 0;

  }

  else {

    if (*(longlong *)(param_1 + 0x690) == 0) {

      uVar2 = FUN_14012e850("Cannot create an OPENGL window invalid egl_data");

      return uVar2;

    }

    lVar3 = FUN_140218bd0(param_1,*(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x24));

    plVar1[1] = lVar3;

    if (lVar3 == 0) {

      uVar2 = FUN_14012e850("Failed to created an offscreen surface (EGL display: %p)",

                            *(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10));

      return uVar2;

    }

  }

  return 1;

}




