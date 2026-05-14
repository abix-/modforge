// Address: 0x140284bc0
// Ghidra name: FUN_140284bc0
// ============ 0x140284bc0 FUN_140284bc0 (size=118) ============


uint FUN_140284bc0(longlong param_1,undefined8 param_2)



{

  longlong lVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  longlong lVar5;

  

  uVar3 = 0;

  iVar4 = 0;

  if (0 < *(int *)(param_1 + 0xa8)) {

    lVar5 = 0;

    do {

      lVar1 = *(longlong *)(lVar5 + *(longlong *)(param_1 + 0xb0));

      uVar2 = (**(code **)(*(longlong *)(lVar1 + 0x68) + 0x68))(lVar1,param_2);

      uVar3 = uVar3 | uVar2;

      lVar5 = lVar5 + 8;

      iVar4 = iVar4 + 1;

    } while (iVar4 < *(int *)(param_1 + 0xa8));

  }

  return uVar3;

}




