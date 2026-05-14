// Address: 0x140288500
// Ghidra name: FUN_140288500
// ============ 0x140288500 FUN_140288500 (size=50) ============


undefined8 FUN_140288500(undefined8 param_1,longlong param_2)



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




