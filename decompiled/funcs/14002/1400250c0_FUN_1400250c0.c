// Address: 0x1400250c0
// Ghidra name: FUN_1400250c0
// ============ 0x1400250c0 FUN_1400250c0 (size=96) ============


void FUN_1400250c0(longlong param_1)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  

  puVar2 = *(undefined8 **)(param_1 + 0x28);

  if (puVar2 == (undefined8 *)0x0) {

    *(undefined8 *)(param_1 + 0x28) = 0;

    *(undefined8 *)(param_1 + 0x30) = 0;

    return;

  }

  do {

    puVar1 = (undefined8 *)puVar2[0xc];

    (**(code **)*puVar2)(puVar2,1);

    puVar2 = puVar1;

  } while (puVar1 != (undefined8 *)0x0);

  *(undefined8 *)(param_1 + 0x28) = 0;

  *(undefined8 *)(param_1 + 0x30) = 0;

  return;

}




