// Address: 0x1401fecc0
// Ghidra name: FUN_1401fecc0
// ============ 0x1401fecc0 FUN_1401fecc0 (size=240) ============


undefined8 FUN_1401fecc0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  FUN_1401f9dc0(lVar1);

  if (param_2 == 0) {

    lVar2 = *(longlong *)(lVar1 + 0x28f8);

    if (lVar2 != 0) {

      FUN_1401fd560(lVar1,0x11a0,0x20,0x1480,0x80,5,*(undefined8 *)(lVar2 + 8),lVar2 + 0x20);

    }

    *(undefined8 *)(lVar1 + 0x28f8) = 0;

    return 1;

  }

  lVar2 = *(longlong *)(param_2 + 0x138);

  if (*(longlong *)(lVar2 + 0x10) == 0) {

    uVar3 = FUN_14012e850("specified texture is not a render target");

    return uVar3;

  }

  *(longlong *)(lVar1 + 0x28f8) = lVar2;

  FUN_1401fd560(lVar1,0x11a0,0x11a0,0x1480,0x1480,2,*(undefined8 *)(lVar2 + 8),lVar2 + 0x20);

  return 1;

}




