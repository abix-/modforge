// Address: 0x1401e7ec0
// Ghidra name: FUN_1401e7ec0
// ============ 0x1401e7ec0 FUN_1401e7ec0 (size=84) ============


longlong FUN_1401e7ec0(longlong param_1)



{

  longlong lVar1;

  longlong local_res8 [4];

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (*(longlong *)(lVar1 + 0x422b0) != 0) {

    return *(longlong *)(*(longlong *)(lVar1 + 0x422b0) + 0x28);

  }

  local_res8[0] = 0;

  (**(code **)(**(longlong **)(lVar1 + 0x68) + 0x48))(*(longlong **)(lVar1 + 0x68),local_res8);

  return (ulonglong)(uint)(*(int *)(lVar1 + 200) * *(int *)(lVar1 + 0x70)) + local_res8[0];

}




