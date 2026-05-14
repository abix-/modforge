// Address: 0x14012c690
// Ghidra name: FUN_14012c690
// ============ 0x14012c690 FUN_14012c690 (size=150) ============


undefined8 * FUN_14012c690(uint *param_1,undefined8 param_2)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  

  if (param_1 == (uint *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","iface");

    return (undefined8 *)0x0;

  }

  if (*param_1 < 0x38) {

    FUN_14012e850("Invalid interface, should be initialized with SDL_INIT_INTERFACE()");

    return (undefined8 *)0x0;

  }

  puVar2 = (undefined8 *)FUN_1401841a0(1,0x48);

  if (puVar2 != (undefined8 *)0x0) {

    uVar1 = *(undefined8 *)(param_1 + 2);

    *puVar2 = *(undefined8 *)param_1;

    puVar2[1] = uVar1;

    uVar1 = *(undefined8 *)(param_1 + 6);

    puVar2[2] = *(undefined8 *)(param_1 + 4);

    puVar2[3] = uVar1;

    uVar1 = *(undefined8 *)(param_1 + 10);

    puVar2[4] = *(undefined8 *)(param_1 + 8);

    puVar2[5] = uVar1;

    puVar2[6] = *(undefined8 *)(param_1 + 0xc);

    puVar2[7] = param_2;

  }

  return puVar2;

}




