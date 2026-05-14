// Address: 0x1400c8d30
// Ghidra name: FUN_1400c8d30
// ============ 0x1400c8d30 FUN_1400c8d30 (size=59) ============


longlong FUN_1400c8d30(longlong param_1,float param_2)



{

  undefined4 *puVar1;

  longlong lVar2;

  

  puVar1 = (undefined4 *)(param_1 + 0x14);

  lVar2 = 200;

  *(float *)(param_1 + 0x1f44) = param_2 * DAT_1403053c8;

  do {

    *puVar1 = 0;

    puVar1 = puVar1 + 10;

    lVar2 = lVar2 + -1;

  } while (lVar2 != 0);

  *(undefined4 *)(param_1 + 8000) = 199;

  return param_1;

}




