// Address: 0x1402f4f90
// Ghidra name: FUN_1402f4f90
// ============ 0x1402f4f90 FUN_1402f4f90 (size=117) ============


undefined8 FUN_1402f4f90(uint param_1)



{

  undefined4 *puVar1;

  

  if (param_1 == 0xfffffffe) {

    puVar1 = (undefined4 *)FUN_1402e688c();

    *puVar1 = 0;

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 9;

  }

  else {

    if ((-1 < (int)param_1) && (param_1 < DAT_1403ff560)) {

      if ((*(byte *)((&DAT_1403ff160)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x38 +

                    (ulonglong)(param_1 & 0x3f) * 0x48) & 1) != 0) {

        return *(undefined8 *)

                ((&DAT_1403ff160)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x28 +

                (ulonglong)(param_1 & 0x3f) * 0x48);

      }

    }

    puVar1 = (undefined4 *)FUN_1402e688c();

    *puVar1 = 0;

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 9;

    FUN_1402cd454();

  }

  return 0xffffffffffffffff;

}




