// Address: 0x14005be60
// Ghidra name: FUN_14005be60
// ============ 0x14005be60 FUN_14005be60 (size=107) ============


void FUN_14005be60(longlong param_1)



{

  uint uVar1;

  

  FUN_140070f90(DAT_1403d4c50);

  uVar1 = *(uint *)(param_1 + 0x114);

  FUN_140072fe0(CONCAT44((float)(uVar1 ^ DAT_14039cac0) * *(float *)(param_1 + 0x110),

                         (float)(uVar1 ^ DAT_14039cac0) * *(float *)(param_1 + 0x10c)),0,

                CONCAT44(uVar1,uVar1));

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  return;

}




