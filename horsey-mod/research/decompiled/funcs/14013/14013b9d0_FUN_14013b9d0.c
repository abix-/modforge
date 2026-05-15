// Address: 0x14013b9d0
// Ghidra name: FUN_14013b9d0
// ============ 0x14013b9d0 FUN_14013b9d0 (size=78) ============


void FUN_14013b9d0(longlong param_1)



{

  undefined8 *puVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined8 uVar5;

  undefined8 *puVar6;

  

  puVar6 = (undefined8 *)FUN_1401391c0(0x28);

  if (puVar6 != (undefined8 *)0x0) {

    puVar1 = *(undefined8 **)(param_1 + 0x10);

    uVar5 = puVar1[1];

    *puVar6 = *puVar1;

    puVar6[1] = uVar5;

    uVar2 = *(undefined4 *)((longlong)puVar1 + 0x14);

    uVar3 = *(undefined4 *)(puVar1 + 3);

    uVar4 = *(undefined4 *)((longlong)puVar1 + 0x1c);

    *(undefined4 *)(puVar6 + 2) = *(undefined4 *)(puVar1 + 2);

    *(undefined4 *)((longlong)puVar6 + 0x14) = uVar2;

    *(undefined4 *)(puVar6 + 3) = uVar3;

    *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar4;

    puVar6[4] = puVar1[4];

    *(undefined8 **)(param_1 + 0x10) = puVar6;

    FUN_14013acf0(param_1,puVar6);

    return;

  }

  return;

}




