// Address: 0x14015ce70
// Ghidra name: FUN_14015ce70
// ============ 0x14015ce70 FUN_14015ce70 (size=124) ============


void FUN_14015ce70(longlong param_1)



{

  if (DAT_1403fc128 != 0) {

    FUN_14017cab0();

    if (*(longlong *)(param_1 + 0xd8) != 0) {

      *(undefined8 *)(*(longlong *)(param_1 + 0xd8) + 0xe0) = *(undefined8 *)(param_1 + 0xe0);

    }

    if (*(longlong *)(param_1 + 0xe0) != 0) {

      *(undefined8 *)(*(longlong *)(param_1 + 0xe0) + 0xd8) = *(undefined8 *)(param_1 + 0xd8);

    }

    if (param_1 == DAT_1403fc140) {

      DAT_1403fc140 = *(longlong *)(param_1 + 0xe0);

    }

    FUN_14017cae0(DAT_1403fc128);

    return;

  }

  return;

}




