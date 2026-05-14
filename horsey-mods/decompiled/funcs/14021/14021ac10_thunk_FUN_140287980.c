// Address: 0x14021ac10
// Ghidra name: thunk_FUN_140287980
// ============ 0x14021ac10 thunk_FUN_140287980 (size=5) ============


ulonglong thunk_FUN_140287980(undefined8 param_1,longlong param_2)



{

  longlong *plVar1;

  int iVar2;

  int aiStackX_10 [6];

  

  plVar1 = *(longlong **)(*(longlong *)(param_2 + 0x48) + 0x50);

  iVar2 = (**(code **)(*plVar1 + 0x48))(plVar1,aiStackX_10);

  if (iVar2 < 0) {

    FUN_1402878d0("Getting effect status",iVar2);

    return 0xffffffff;

  }

  return (ulonglong)(aiStackX_10[0] != 0);

}




