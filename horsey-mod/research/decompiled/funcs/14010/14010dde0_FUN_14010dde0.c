// Address: 0x14010dde0
// Ghidra name: FUN_14010dde0
// ============ 0x14010dde0 FUN_14010dde0 (size=34) ============


longlong FUN_14010dde0(longlong param_1)



{

  longlong lVar1;

  uint7 uVar2;

  

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x438) + 0xa8);

  uVar2 = (uint7)((ulonglong)*(longlong *)(param_1 + 0x438) >> 8);

  if ((lVar1 != 0) && (*(int *)(lVar1 + 0x2cc) != 1)) {

    return (ulonglong)uVar2 << 8;

  }

  return CONCAT71(uVar2,1);

}




