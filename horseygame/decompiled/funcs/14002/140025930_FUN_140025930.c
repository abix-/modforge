// Address: 0x140025930
// Ghidra name: FUN_140025930
// ============ 0x140025930 FUN_140025930 (size=65) ============


void FUN_140025930(longlong param_1,undefined8 param_2,longlong param_3)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = FUN_140027540(param_1 + 0x68);

  if (lVar1 != 0) {

    lVar2 = -1;

    do {

      lVar2 = lVar2 + 1;

    } while (*(char *)(param_3 + lVar2) != '\0');

    FUN_140027f50(lVar1 + 0x40,param_3);

    return;

  }

  return;

}




