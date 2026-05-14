// Address: 0x1402ea704
// Ghidra name: FUN_1402ea704
// ============ 0x1402ea704 FUN_1402ea704 (size=286) ============


undefined4 FUN_1402ea704(uint param_1,undefined8 param_2,uint param_3)



{

  bool bVar1;

  undefined4 uVar2;

  undefined4 *puVar3;

  

  if (param_1 == 0xfffffffe) {

    puVar3 = (undefined4 *)FUN_1402e688c();

    *puVar3 = 0;

    puVar3 = (undefined4 *)FUN_1402e68b0();

    *puVar3 = 9;

    return 0xffffffff;

  }

  if (((int)param_1 < 0) || (DAT_1403ff560 <= param_1)) {

    bVar1 = false;

  }

  else {

    bVar1 = true;

  }

  if (bVar1) {

    if ((*(byte *)((&DAT_1403ff160)[(longlong)(int)param_1 >> 6] + 0x38 +

                  (ulonglong)(param_1 & 0x3f) * 0x48) & 1) != 0) {

      if (param_3 < 0x80000000) {

        __acrt_lowio_lock_fh(param_1);

        uVar2 = 0xffffffff;

        if ((*(byte *)((&DAT_1403ff160)[(longlong)(int)param_1 >> 6] + 0x38 +

                      (ulonglong)(param_1 & 0x3f) * 0x48) & 1) == 0) {

          puVar3 = (undefined4 *)FUN_1402e68b0();

          *puVar3 = 9;

          puVar3 = (undefined4 *)FUN_1402e688c();

          *puVar3 = 0;

        }

        else {

          uVar2 = FUN_1402ea824(param_1,param_2,param_3);

        }

        __acrt_lowio_unlock_fh(param_1);

        return uVar2;

      }

      puVar3 = (undefined4 *)FUN_1402e688c();

      *puVar3 = 0;

      puVar3 = (undefined4 *)FUN_1402e68b0();

      *puVar3 = 0x16;

      goto LAB_1402ea78a;

    }

  }

  puVar3 = (undefined4 *)FUN_1402e688c();

  *puVar3 = 0;

  puVar3 = (undefined4 *)FUN_1402e68b0();

  *puVar3 = 9;

LAB_1402ea78a:

  FUN_1402cd454();

  return 0xffffffff;

}




