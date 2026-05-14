// Address: 0x140075fd0
// Ghidra name: FUN_140075fd0
// ============ 0x140075fd0 FUN_140075fd0 (size=271) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 * FUN_140075fd0(undefined4 *param_1,undefined4 *param_2)



{

  if ((ulonglong)(DAT_1403ead30 - DAT_1403ead28) <

      (ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18)) {

    *(undefined1 *)param_2 = 0;

  }

  else {

    *(undefined1 *)param_2 = *DAT_1403ead20;

    DAT_1403ead20 = DAT_1403ead20 + 1;

  }

  if ((ulonglong)(DAT_1403ead30 - DAT_1403ead28) <

      (ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18)) {

    *(undefined1 *)((longlong)param_2 + 1) = 0;

  }

  else {

    *(undefined1 *)((longlong)param_2 + 1) = *DAT_1403ead20;

    DAT_1403ead20 = DAT_1403ead20 + 1;

  }

  if ((ulonglong)(DAT_1403ead30 - DAT_1403ead28) <

      (ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18)) {

    *(undefined1 *)((longlong)param_2 + 2) = 0;

  }

  else {

    *(undefined1 *)((longlong)param_2 + 2) = *DAT_1403ead20;

    DAT_1403ead20 = DAT_1403ead20 + 1;

  }

  if ((ulonglong)(DAT_1403ead30 - DAT_1403ead28) <

      (ulonglong)((longlong)DAT_1403ead20 - _DAT_1403ead18)) {

    *(undefined1 *)((longlong)param_2 + 3) = 0;

    *param_1 = *param_2;

    return param_1;

  }

  *(undefined1 *)((longlong)param_2 + 3) = *DAT_1403ead20;

  DAT_1403ead20 = DAT_1403ead20 + 1;

  *param_1 = *param_2;

  return param_1;

}




