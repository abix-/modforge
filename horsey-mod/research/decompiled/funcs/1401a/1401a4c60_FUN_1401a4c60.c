// Address: 0x1401a4c60
// Ghidra name: FUN_1401a4c60
// ============ 0x1401a4c60 FUN_1401a4c60 (size=97) ============


void FUN_1401a4c60(longlong param_1,undefined4 *param_2,undefined8 param_3)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  

  uVar1 = param_2[1];

  uVar2 = param_2[2];

  uVar3 = param_2[3];

  *(undefined4 *)(param_1 + 0x10) = *param_2;

  *(undefined4 *)(param_1 + 0x14) = uVar1;

  *(undefined4 *)(param_1 + 0x18) = uVar2;

  *(undefined4 *)(param_1 + 0x1c) = uVar3;

  *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(param_2 + 4);

  *(undefined8 *)(param_1 + 0x28) = param_3;

  *(undefined4 *)(param_1 + 0x34) = 0x80;

  *(undefined4 *)(param_1 + 0x30) = 1;

  *(undefined4 *)(param_1 + 0xb8) = 0;

  *(longlong *)(param_1 + 0xd0) = param_1 + 0x38;

  *(longlong *)(param_1 + 0xc0) = param_1 + 0x38;

  FUN_1401a4400();

  *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(param_1 + 200);

  return;

}




