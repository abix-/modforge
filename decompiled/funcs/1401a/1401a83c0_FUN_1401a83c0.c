// Address: 0x1401a83c0
// Ghidra name: FUN_1401a83c0
// ============ 0x1401a83c0 FUN_1401a83c0 (size=187) ============


void FUN_1401a83c0(code *param_1,undefined8 param_2)



{

  longlong lVar1;

  int iVar2;

  

  FUN_14017cab0(DAT_1403fcd48);

  if ((0 < DAT_1403fcd44) && (iVar2 = 0, 0 < DAT_1403fcd44)) {

    lVar1 = 0;

    do {

      if (param_1 != (code *)0x0) {

        (*param_1)(*(undefined4 *)(lVar1 + DAT_1403fcd50),

                   *(undefined8 *)(lVar1 + 0x58 + DAT_1403fcd50),param_2);

      }

      FUN_1401841e0(*(undefined8 *)(lVar1 + 8 + DAT_1403fcd50));

      iVar2 = iVar2 + 1;

      lVar1 = lVar1 + 0x60;

    } while (iVar2 < DAT_1403fcd44);

  }

  FUN_1401841e0(DAT_1403fcd50);

  DAT_1403fcd50 = 0;

  DAT_1403fcd44 = 0;

  DAT_1403fcd40 = 0;

  FUN_14017cae0(DAT_1403fcd48);

  return;

}




