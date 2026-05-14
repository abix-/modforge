// Address: 0x1400c8d90
// Ghidra name: FUN_1400c8d90
// ============ 0x1400c8d90 FUN_1400c8d90 (size=40) ============


void FUN_1400c8d90(longlong param_1)



{

  undefined4 *puVar1;

  longlong lVar2;

  

  puVar1 = (undefined4 *)(param_1 + 0x14);

  lVar2 = 200;

  do {

    *puVar1 = 0;

    puVar1 = puVar1 + 10;

    lVar2 = lVar2 + -1;

  } while (lVar2 != 0);

  *(undefined4 *)(param_1 + 8000) = 199;

  return;

}




