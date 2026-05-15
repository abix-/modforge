// Address: 0x140226d70
// Ghidra name: FUN_140226d70
// ============ 0x140226d70 FUN_140226d70 (size=51) ============


undefined8 FUN_140226d70(longlong param_1)



{

  undefined8 uVar1;

  int iVar2;

  int iVar3;

  

  if ((*(int *)(param_1 + 0x54) == 1) ||

     (iVar2 = *(int *)(param_1 + 0xac), iVar3 = *(int *)(param_1 + 0xb0),

     *(int *)(param_1 + 0x54) == 3)) {

    iVar2 = *(int *)(param_1 + 0xb0);

    iVar3 = *(int *)(param_1 + 0xac);

  }

  uVar1 = 3;

  if (iVar3 <= iVar2) {

    uVar1 = 1;

  }

  return uVar1;

}




