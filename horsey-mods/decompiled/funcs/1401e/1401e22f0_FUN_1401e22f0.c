// Address: 0x1401e22f0
// Ghidra name: FUN_1401e22f0
// ============ 0x1401e22f0 FUN_1401e22f0 (size=25) ============


longlong FUN_1401e22f0(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x2e0) + 0x50);

  if (lVar1 != 0) {

    return lVar1;

  }

  return *(longlong *)(*(longlong *)(param_1 + 0x2e0) + 0x48);

}




