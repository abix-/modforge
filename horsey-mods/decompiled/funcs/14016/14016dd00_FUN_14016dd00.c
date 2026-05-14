// Address: 0x14016dd00
// Ghidra name: FUN_14016dd00
// ============ 0x14016dd00 FUN_14016dd00 (size=46) ============


undefined8 FUN_14016dd00(void)



{

  int iVar1;

  

  iVar1 = FUN_14016d5f0();

  if (iVar1 < 0) {

    return 0;

  }

  return *(undefined8 *)(*(longlong *)(DAT_1403fc410 + 0x330) + (longlong)iVar1 * 8);

}




