// Address: 0x14015c8d0
// Ghidra name: FUN_14015c8d0
// ============ 0x14015c8d0 FUN_14015c8d0 (size=143) ============


void FUN_14015c8d0(undefined8 *param_1)



{

  longlong lVar1;

  

  if (param_1 != (undefined8 *)0x0) {

    FUN_140179b40(*param_1);

    lVar1 = param_1[0x1a];

    while (lVar1 != 0) {

      FUN_14015c7c0(lVar1);

      lVar1 = param_1[0x1a];

    }

    FUN_14015c2e0(param_1);

    (*DAT_1403fc108)(param_1);

    FUN_140179b60(*param_1);

    FUN_140179b30(*param_1);

    FUN_140160350(param_1[1]);

    FUN_1401841e0(param_1[0x13]);

    FUN_1401841e0(param_1[0xe]);

    FUN_1401841e0(param_1[9]);

    FUN_1401841e0(param_1);

  }

  return;

}




