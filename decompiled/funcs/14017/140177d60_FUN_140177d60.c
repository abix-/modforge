// Address: 0x140177d60
// Ghidra name: FUN_140177d60
// ============ 0x140177d60 FUN_140177d60 (size=164) ============


undefined8 * FUN_140177d60(uint *param_1,undefined8 param_2)



{

  undefined8 uVar1;

  undefined8 uVar2;

  undefined8 *puVar3;

  

  if (param_1 == (uint *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","iface");

    return (undefined8 *)0x0;

  }

  if (*param_1 < 0x60) {

    FUN_14012e850("Invalid interface, should be initialized with SDL_INIT_INTERFACE()");

    return (undefined8 *)0x0;

  }

  puVar3 = (undefined8 *)FUN_1401841a0(1,0x68);

  if (puVar3 != (undefined8 *)0x0) {

    uVar1 = *(undefined8 *)(param_1 + 2);

    *puVar3 = *(undefined8 *)param_1;

    puVar3[1] = uVar1;

    uVar1 = *(undefined8 *)(param_1 + 6);

    puVar3[2] = *(undefined8 *)(param_1 + 4);

    puVar3[3] = uVar1;

    uVar1 = *(undefined8 *)(param_1 + 10);

    puVar3[4] = *(undefined8 *)(param_1 + 8);

    puVar3[5] = uVar1;

    uVar1 = *(undefined8 *)(param_1 + 0xe);

    puVar3[6] = *(undefined8 *)(param_1 + 0xc);

    puVar3[7] = uVar1;

    uVar1 = *(undefined8 *)(param_1 + 0x12);

    puVar3[8] = *(undefined8 *)(param_1 + 0x10);

    puVar3[9] = uVar1;

    uVar1 = *(undefined8 *)(param_1 + 0x14);

    uVar2 = *(undefined8 *)(param_1 + 0x16);

    puVar3[0xc] = param_2;

    puVar3[10] = uVar1;

    puVar3[0xb] = uVar2;

  }

  return puVar3;

}




