// Address: 0x1402ce164
// Ghidra name: FUN_1402ce164
// ============ 0x1402ce164 FUN_1402ce164 (size=122) ============


undefined4 FUN_1402ce164(longlong param_1,longlong param_2)



{

  undefined4 uVar1;

  

  if (param_1 == 0) {

    *(undefined1 *)(param_2 + 0x30) = 1;

    *(undefined4 *)(param_2 + 0x2c) = 0x16;

    FUN_1402cd39c(0,0,0,0,0,param_2);

  }

  else {

    if ((*(uint *)(param_1 + 0x14) >> 0xc & 1) == 0) {

      FUN_1402e1710();

      uVar1 = FUN_1402ce1e0(param_1,param_2);

      FUN_1402e171c(param_1);

      return uVar1;

    }

    __acrt_stdio_free_stream();

  }

  return 0xffffffff;

}




