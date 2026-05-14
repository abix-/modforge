// Address: 0x1401e82f0
// Ghidra name: FUN_1401e82f0
// ============ 0x1401e82f0 FUN_1401e82f0 (size=126) ============


int FUN_1401e82f0(longlong param_1)



{

  int iVar1;

  

  iVar1 = (**(code **)(**(longlong **)(param_1 + 0x48) + 0x48))();

  if (iVar1 < 0) {

    FUN_1401a9ef0("D3D12_IssueBatch",iVar1);

    return iVar1;

  }

  (**(code **)(**(longlong **)(param_1 + 0x40) + 0x50))

            (*(longlong **)(param_1 + 0x40),1,param_1 + 0x48);

  FUN_1401eb150(param_1);

  FUN_1401e8fd0(param_1);

  return iVar1;

}




