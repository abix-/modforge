// Address: 0x1402e77b0
// Ghidra name: thunk_FUN_1402e7568
// ============ 0x1402e77b0 thunk_FUN_1402e7568 (size=5) ============


undefined8 thunk_FUN_1402e7568(void)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  longlong lVar4;

  

  uVar3 = 0;

  if (DAT_1403ff0d8 == 0) {

    __acrt_initialize_multibyte();

    lVar2 = FUN_1402f47f4();

    if (lVar2 == 0) {

      FUN_1402e9a80(0);

      uVar3 = 0xffffffff;

    }

    else {

      lVar4 = FUN_1402e75dc(lVar2);

      lVar1 = lVar4;

      if (lVar4 == 0) {

        uVar3 = 0xffffffff;

        lVar4 = DAT_1403ff0d8;

        lVar1 = DAT_1403ff0f0;

      }

      DAT_1403ff0f0 = lVar1;

      DAT_1403ff0d8 = lVar4;

      FUN_1402e9a80(0);

      FUN_1402e9a80(lVar2);

    }

  }

  else {

    uVar3 = 0;

  }

  return uVar3;

}




