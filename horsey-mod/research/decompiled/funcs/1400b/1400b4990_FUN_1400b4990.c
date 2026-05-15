// Address: 0x1400b4990
// Ghidra name: FUN_1400b4990
// ============ 0x1400b4990 FUN_1400b4990 (size=23) ============


longlong FUN_1400b4990(longlong param_1)



{

  longlong lVar1;

  uint7 uVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x40);

  uVar2 = (uint7)((ulonglong)lVar1 >> 8);

  if ((lVar1 != *(longlong *)(param_1 + 0x48)) && (*(longlong *)(lVar1 + 0x30) != 0)) {

    return CONCAT71(uVar2,1);

  }

  return (ulonglong)uVar2 << 8;

}




