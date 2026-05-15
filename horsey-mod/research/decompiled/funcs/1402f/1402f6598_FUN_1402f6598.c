// Address: 0x1402f6598
// Ghidra name: FUN_1402f6598
// ============ 0x1402f6598 FUN_1402f6598 (size=95) ============


byte FUN_1402f6598(uint param_1)



{

  undefined4 *puVar1;

  

  if (param_1 == 0xfffffffe) {

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 9;

  }

  else {

    if ((-1 < (int)param_1) && (param_1 < DAT_1403ff560)) {

      return *(byte *)((&DAT_1403ff160)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x38 +

                      (ulonglong)(param_1 & 0x3f) * 0x48) & 0x40;

    }

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 9;

    FUN_1402cd454();

  }

  return 0;

}




