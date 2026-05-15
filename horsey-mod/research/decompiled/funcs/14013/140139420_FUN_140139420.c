// Address: 0x140139420
// Ghidra name: FUN_140139420
// ============ 0x140139420 FUN_140139420 (size=50) ============


ulonglong FUN_140139420(uint param_1)



{

  uint uVar1;

  

  if ((&DAT_1403fb6a0)[(byte)(param_1 >> 8)] != 0) {

    uVar1 = *(uint *)((&DAT_1403fb6a0)[(byte)(param_1 >> 8)] +

                     (ulonglong)((param_1 & 0xff) >> 5) * 4);

    return (ulonglong)CONCAT31((int3)(uVar1 >> 8),(uVar1 >> (param_1 & 0x1f) & 1) == 0);

  }

  return CONCAT71((uint7)(ushort)(param_1 >> 0x10),1);

}




