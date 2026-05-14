// Address: 0x140067a20
// Ghidra name: FUN_140067a20
// ============ 0x140067a20 FUN_140067a20 (size=172) ============


void FUN_140067a20(longlong param_1)



{

  uint uVar1;

  undefined4 uVar2;

  

  FUN_140070f90(DAT_1403d6480);

  uVar2 = DAT_1403d6494;

  FUN_140071000(0,0);

  uVar1 = *(uint *)(param_1 + 0x114);

  FUN_140072fe0(CONCAT44((float)(uVar1 ^ DAT_14039cac0) * *(float *)(param_1 + 0x110),

                         (float)(uVar1 ^ DAT_14039cac0) * *(float *)(param_1 + 0x10c)),0,

                CONCAT44(uVar1,uVar1),uVar1,uVar2);

  FUN_1400d5d90(param_1,1);

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  FUN_1400cacd0(param_1,1);

  return;

}




