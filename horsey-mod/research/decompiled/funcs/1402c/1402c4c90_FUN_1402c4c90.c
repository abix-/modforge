// Address: 0x1402c4c90
// Ghidra name: FUN_1402c4c90
// ============ 0x1402c4c90 FUN_1402c4c90 (size=91) ============


void FUN_1402c4c90(longlong param_1)



{

  undefined8 *puVar1;

  longlong lVar2;

  

  puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 0x10) + 0x30);

  FUN_140179b40(*puVar1);

  *(undefined8 **)(param_1 + 0x68) = puVar1 + 2;

  lVar2 = puVar1[0x10];

  *(longlong *)(param_1 + 0x70) = lVar2;

  if (lVar2 != 0) {

    *(longlong *)(lVar2 + 0x68) = param_1;

  }

  puVar1[0x10] = param_1;

  FUN_140160360(puVar1[1]);

  FUN_140179b60(*puVar1);

  return;

}




