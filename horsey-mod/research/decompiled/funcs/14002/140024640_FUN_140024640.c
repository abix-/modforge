// Address: 0x140024640
// Ghidra name: FUN_140024640
// ============ 0x140024640 FUN_140024640 (size=178) ============


undefined8 * FUN_140024640(undefined8 param_1,undefined8 *param_2,int param_3)



{

  undefined8 uVar1;

  char *pcVar2;

  longlong lVar3;

  longlong lVar4;

  

  if (param_3 == 1) {

    *param_2 = 0;

    param_2[1] = 0;

    param_2[2] = 0;

    param_2[3] = 0;

    pcVar2 = (char *)FUN_1402c704c(0x20);

    *param_2 = pcVar2;

    param_2[2] = 0x15;

    param_2[3] = 0x1f;

    uVar1 = s_iostream_stream_error_14039c460._8_8_;

    *(undefined8 *)pcVar2 = s_iostream_stream_error_14039c460._0_8_;

    *(undefined8 *)(pcVar2 + 8) = uVar1;

    *(undefined4 *)(pcVar2 + 0x10) = s_iostream_stream_error_14039c460._16_4_;

    pcVar2[0x14] = s_iostream_stream_error_14039c460[0x14];

    pcVar2[0x15] = '\0';

    return param_2;

  }

  lVar3 = FUN_1402c6d34(param_3);

  lVar4 = -1;

  *param_2 = 0;

  param_2[1] = 0;

  param_2[2] = 0;

  param_2[3] = 0;

  do {

    lVar4 = lVar4 + 1;

  } while (*(char *)(lVar3 + lVar4) != '\0');

  FUN_140027e30(param_2,lVar3);

  return param_2;

}




