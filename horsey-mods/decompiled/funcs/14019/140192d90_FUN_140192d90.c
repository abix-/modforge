// Address: 0x140192d90
// Ghidra name: FUN_140192d90
// ============ 0x140192d90 FUN_140192d90 (size=46) ============


ulonglong FUN_140192d90(short param_1,short param_2)



{

  short *psVar1;

  uint uVar2;

  

  uVar2 = 0;

  psVar1 = &DAT_14033a2b2;

  while ((param_1 != psVar1[-1] || (param_2 != *psVar1))) {

    uVar2 = uVar2 + 1;

    psVar1 = psVar1 + 2;

    if (4 < uVar2) {

      return (ulonglong)psVar1 & 0xffffffffffffff00;

    }

  }

  return CONCAT71((int7)((ulonglong)psVar1 >> 8),1);

}




