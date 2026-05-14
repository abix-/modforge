// Address: 0x14015c7c0
// Ghidra name: FUN_14015c7c0
// ============ 0x14015c7c0 FUN_14015c7c0 (size=233) ============


void FUN_14015c7c0(undefined4 *param_1)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  

  if (DAT_1403fc138 != 0) {

    FUN_14017cab0(DAT_1403fc128);

    FUN_1401ab340(DAT_1403fc138,*param_1);

    FUN_14017cae0(DAT_1403fc128);

  }

  if (*(longlong *)(param_1 + 0xe) != 0) {

    *(undefined8 *)(*(longlong *)(param_1 + 0xe) + 0x40) = *(undefined8 *)(param_1 + 0x10);

  }

  if (*(longlong *)(param_1 + 0x10) != 0) {

    *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x38) = *(undefined8 *)(param_1 + 0xe);

  }

  if (*(undefined4 **)(*(longlong *)(param_1 + 2) + 0xd0) == param_1) {

    *(undefined8 *)(*(longlong *)(param_1 + 2) + 0xd0) = *(undefined8 *)(param_1 + 0xe);

  }

  puVar2 = *(undefined8 **)(param_1 + 6);

  while (puVar2 != (undefined8 *)0x0) {

    FUN_140179b40(*puVar2);

    puVar1 = (undefined8 *)puVar2[0x19];

    puVar2[0x19] = 0;

    puVar2[0x1a] = 0;

    puVar2[0x18] = 0;

    FUN_140179b60(*puVar2);

    puVar2 = puVar1;

  }

  FUN_14015fec0(*(undefined8 *)(param_1 + 2));

  FUN_1401841e0(param_1);

  return;

}




