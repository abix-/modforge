// Address: 0x1400764d0
// Ghidra name: FUN_1400764d0
// ============ 0x1400764d0 FUN_1400764d0 (size=117) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400764d0(int param_1)



{

  ulonglong uVar1;

  undefined1 local_res8 [32];

  

  DAT_1403ead20 = DAT_1403ead20 + param_1;

  uVar1 = (ulonglong)((int)DAT_1403ead20 - _DAT_1403ead18);

  if ((DAT_1403ead30 - DAT_1403ead28) - 4U <= uVar1) {

    local_res8[0] = 0;

    FUN_140076910(&DAT_1403ead28,(DAT_1403ead30 - DAT_1403ead28) + 0x1000,local_res8);

    _DAT_1403ead18 = DAT_1403ead28;

    DAT_1403ead20 = DAT_1403ead28 + uVar1;

  }

  return;

}




