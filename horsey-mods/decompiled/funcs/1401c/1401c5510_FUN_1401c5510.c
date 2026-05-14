// Address: 0x1401c5510
// Ghidra name: FUN_1401c5510
// ============ 0x1401c5510 FUN_1401c5510 (size=66) ============


undefined8 FUN_1401c5510(longlong param_1)



{

  undefined8 uVar1;

  char cVar2;

  uint uVar3;

  

  if (*(int *)(param_1 + 0x118) == 0) {

    cVar2 = FUN_1401c5ac0();

    if (cVar2 == '\0') {

      return 0;

    }

  }

  uVar3 = *(int *)(param_1 + 0x118) - 1;

  uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x110) + (ulonglong)uVar3 * 8);

  *(uint *)(param_1 + 0x118) = uVar3;

  return uVar1;

}




