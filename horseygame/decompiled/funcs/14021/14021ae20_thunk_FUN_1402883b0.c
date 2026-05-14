// Address: 0x14021ae20
// Ghidra name: thunk_FUN_1402883b0
// ============ 0x14021ae20 thunk_FUN_1402883b0 (size=5) ============


undefined8 thunk_FUN_1402883b0(undefined8 param_1,longlong param_2,int param_3)



{

  longlong *plVar1;

  int iVar2;

  undefined8 uVar3;

  

  iVar2 = -1;

  if (param_3 != -1) {

    iVar2 = param_3;

  }

  plVar1 = *(longlong **)(*(longlong *)(param_2 + 0x48) + 0x50);

  iVar2 = (**(code **)(*plVar1 + 0x38))(plVar1,iVar2,0);

  if (iVar2 < 0) {

    uVar3 = FUN_1402878d0("Running the effect",iVar2);

    return uVar3;

  }

  return 1;

}




