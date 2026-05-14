// Address: 0x140223e80
// Ghidra name: FUN_140223e80
// ============ 0x140223e80 FUN_140223e80 (size=121) ============


void FUN_140223e80(longlong param_1)



{

  undefined8 *puVar1;

  int iVar2;

  

  *(undefined1 *)(param_1 + 0x1a0) = 0;

  if (0 < *(int *)(param_1 + 0x1f8)) {

    puVar1 = (undefined8 *)(param_1 + 0x1a8);

    iVar2 = 0;

    do {

      FUN_1401841e0(*puVar1);

      *puVar1 = 0;

      puVar1 = puVar1 + 1;

      iVar2 = iVar2 + 1;

    } while (iVar2 < *(int *)(param_1 + 0x1f8));

    *(undefined4 *)(param_1 + 0x1f8) = 0;

    FUN_1401838c0(0,0,0xffffffff,0);

  }

  return;

}




