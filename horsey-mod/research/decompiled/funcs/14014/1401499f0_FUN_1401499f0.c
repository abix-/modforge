// Address: 0x1401499f0
// Ghidra name: FUN_1401499f0
// ============ 0x1401499f0 FUN_1401499f0 (size=124) ============


longlong FUN_1401499f0(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x250);

  if (lVar1 == 0) {

    lVar1 = FUN_1401841a0(1,0x58);

    if (lVar1 == 0) {

      return 0;

    }

  }

  else {

    *(undefined8 *)(param_1 + 0x250) = *(undefined8 *)(lVar1 + 0x50);

    *(undefined8 *)(lVar1 + 0x50) = 0;

  }

  if (*(longlong *)(param_1 + 0x248) != 0) {

    *(longlong *)(*(longlong *)(param_1 + 0x248) + 0x50) = lVar1;

    *(longlong *)(param_1 + 0x248) = lVar1;

    return lVar1;

  }

  *(longlong *)(param_1 + 0x240) = lVar1;

  *(longlong *)(param_1 + 0x248) = lVar1;

  return lVar1;

}




