// Address: 0x14021ae60
// Ghidra name: thunk_FUN_140288500
// ============ 0x14021ae60 thunk_FUN_140288500 (size=5) ============


undefined8 thunk_FUN_140288500(undefined8 param_1,longlong param_2)



{

  int iVar1;

  undefined8 uVar2;

  

  iVar1 = (**(code **)(**(longlong **)(*(longlong *)(param_2 + 0x48) + 0x50) + 0x40))();

  if (iVar1 < 0) {

    uVar2 = FUN_1402878d0("Unable to stop effect",iVar1);

    return uVar2;

  }

  return 1;

}




