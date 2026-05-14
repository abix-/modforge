// Address: 0x14010de10
// Ghidra name: FUN_14010de10
// ============ 0x14010de10 FUN_14010de10 (size=34) ============


longlong FUN_14010de10(longlong param_1)



{

  longlong lVar1;

  uint7 uVar2;

  

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x438) + 0xf8);

  uVar2 = (uint7)((ulonglong)*(longlong *)(param_1 + 0x438) >> 8);

  if ((lVar1 != 0) && (0 < *(int *)(lVar1 + 0x6a0))) {

    return CONCAT71(uVar2,1);

  }

  return (ulonglong)uVar2 << 8;

}




