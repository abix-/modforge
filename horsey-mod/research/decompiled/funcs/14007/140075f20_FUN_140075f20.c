// Address: 0x140075f20
// Ghidra name: FUN_140075f20
// ============ 0x140075f20 FUN_140075f20 (size=158) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 * FUN_140075f20(undefined8 *param_1,undefined8 *param_2)



{

  undefined8 uVar1;

  

  uVar1 = DAT_1403ffbe8;

  if ((ulonglong)(DAT_1403ead30 - DAT_1403ead28) <

      (ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18)) {

    *param_2 = DAT_1403ffbe8;

    *param_1 = uVar1;

    return param_1;

  }

  *(undefined4 *)param_2 = *DAT_1403ead20;

  DAT_1403ead20 = DAT_1403ead20 + 1;

  if ((ulonglong)(DAT_1403ead30 - DAT_1403ead28) <

      (ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18)) {

    *(undefined4 *)((longlong)param_2 + 4) = 0;

    *param_1 = *param_2;

    return param_1;

  }

  *(undefined4 *)((longlong)param_2 + 4) = *DAT_1403ead20;

  DAT_1403ead20 = DAT_1403ead20 + 1;

  *param_1 = *param_2;

  return param_1;

}




