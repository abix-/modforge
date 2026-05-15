// Address: 0x14014a540
// Ghidra name: FUN_14014a540
// ============ 0x14014a540 FUN_14014a540 (size=70) ============


undefined8 FUN_14014a540(longlong param_1)



{

  undefined4 uVar1;

  undefined8 uVar2;

  undefined4 *puVar3;

  

  puVar3 = (undefined4 *)FUN_1401499f0();

  if (puVar3 == (undefined4 *)0x0) {

    return 0;

  }

  *puVar3 = 4;

  *(undefined8 *)(puVar3 + 2) = 0;

  uVar1 = *(undefined4 *)(param_1 + 0x218);

  puVar3[4] = uVar1;

  uVar2 = *(undefined8 *)(param_1 + 0x224);

  *(undefined8 *)(puVar3 + 5) = *(undefined8 *)(param_1 + 0x21c);

  *(undefined8 *)(puVar3 + 7) = uVar2;

  return CONCAT71((uint7)(uint3)((uint)uVar1 >> 8),1);

}




