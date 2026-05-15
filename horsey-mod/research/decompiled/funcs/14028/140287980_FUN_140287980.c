// Address: 0x140287980
// Ghidra name: FUN_140287980
// ============ 0x140287980 FUN_140287980 (size=69) ============


ulonglong FUN_140287980(undefined8 param_1,longlong param_2)



{

  longlong *plVar1;

  int iVar2;

  int local_res10 [6];

  

  plVar1 = *(longlong **)(*(longlong *)(param_2 + 0x48) + 0x50);

  iVar2 = (**(code **)(*plVar1 + 0x48))(plVar1,local_res10);

  if (iVar2 < 0) {

    FUN_1402878d0("Getting effect status",iVar2);

    return 0xffffffff;

  }

  return (ulonglong)(local_res10[0] != 0);

}




