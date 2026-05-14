// Address: 0x14016f170
// Ghidra name: FUN_14016f170
// ============ 0x14016f170 FUN_14016f170 (size=28) ============


longlong FUN_14016f170(void)



{

  uint7 uVar1;

  

  uVar1 = (uint7)((ulonglong)DAT_1403fc410 >> 8);

  if ((DAT_1403fc410 != 0) && (*(longlong *)(DAT_1403fc410 + 0x348) != 0)) {

    return CONCAT71(uVar1,1);

  }

  return (ulonglong)uVar1 << 8;

}




