// Address: 0x14003ed70
// Ghidra name: FUN_14003ed70
// ============ 0x14003ed70 FUN_14003ed70 (size=132) ============


void FUN_14003ed70(longlong param_1)



{

  uint uVar1;

  

  FUN_140070f90(DAT_1403d4564);

  uVar1 = *(uint *)(param_1 + 0x114);

  FUN_140072fe0(CONCAT44((float)(uVar1 ^ DAT_14039cac0) * *(float *)(param_1 + 0x110),

                         (float)(uVar1 ^ DAT_14039cac0) * *(float *)(param_1 + 0x10c)),0,

                CONCAT44(uVar1,uVar1));

  FUN_1400d5d90(param_1,1);

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  FUN_1400cacd0(param_1,1);

  return;

}




