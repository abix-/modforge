// Address: 0x1402161f0
// Ghidra name: FUN_1402161f0
// ============ 0x1402161f0 FUN_1402161f0 (size=71) ============


void FUN_1402161f0(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  int iVar3;

  uint local_res8 [2];

  undefined1 local_res10 [8];

  

  lVar1 = *(longlong *)(param_1 + 200);

  plVar2 = *(longlong **)(lVar1 + 0x18);

  iVar3 = (**(code **)(*plVar2 + 0x20))(plVar2,local_res10,local_res8);

  if (iVar3 == 0) {

    *(uint *)(lVar1 + 0x24) = local_res8[0] / *(uint *)(param_1 + 0x6c);

  }

  return;

}




