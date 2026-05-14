// Address: 0x14015ce00
// Ghidra name: FUN_14015ce00
// ============ 0x14015ce00 FUN_14015ce00 (size=100) ============


void FUN_14015ce00(longlong param_1)



{

  if (DAT_1403fc128 != 0) {

    FUN_14017cab0();

    if (DAT_1403fc140 != 0) {

      *(longlong *)(DAT_1403fc140 + 0xd8) = param_1;

    }

    *(undefined8 *)(param_1 + 0xd8) = 0;

    *(longlong *)(param_1 + 0xe0) = DAT_1403fc140;

    DAT_1403fc140 = param_1;

    FUN_14017cae0(DAT_1403fc128);

    return;

  }

  return;

}




