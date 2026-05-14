// Address: 0x14015c2e0
// Ghidra name: FUN_14015c2e0
// ============ 0x14015c2e0 FUN_14015c2e0 (size=251) ============


void FUN_14015c2e0(undefined8 *param_1)



{

  undefined4 uVar1;

  

  FUN_14015fda0();

  FUN_140139010((longlong)param_1 + 0x8c,1);

  FUN_140179b60(*param_1);

  if (param_1[0x17] != 0) {

    FUN_140163d80(param_1[0x17],0);

    param_1[0x17] = 0;

  }

  if (*(char *)(param_1 + 0x18) != '\0') {

    (*DAT_1403fc100)(param_1);

    *(undefined1 *)(param_1 + 0x18) = 0;

    param_1[0x19] = 0;

  }

  FUN_140179b40(*param_1);

  FUN_140139010((longlong)param_1 + 0x8c,0);

  FUN_140160220(param_1[1]);

  FUN_140190140(param_1[0x13]);

  param_1[0x13] = 0;

  FUN_140190140(param_1[0x14]);

  param_1[0x14] = 0;

  FUN_140190140(param_1[0x15]);

  param_1[0xc] = param_1[0xf];

  *(undefined4 *)(param_1 + 0xd) = *(undefined4 *)(param_1 + 0x10);

  param_1[0x15] = 0;

  *(undefined4 *)((longlong)param_1 + 0x84) = 0;

  uVar1 = FUN_14015e760(*(undefined4 *)(param_1 + 0xc));

  *(undefined4 *)(param_1 + 0x11) = uVar1;

  return;

}




