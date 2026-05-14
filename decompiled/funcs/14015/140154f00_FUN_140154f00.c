// Address: 0x140154f00
// Ghidra name: FUN_140154f00
// ============ 0x140154f00 FUN_140154f00 (size=113) ============


ulonglong FUN_140154f00(longlong param_1,undefined4 param_2)



{

  longlong *plVar1;

  char cVar2;

  ulonglong uVar3;

  

  while (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,3);

      if (cVar2 == '\0') break;

    }

    plVar1 = (longlong *)(param_1 + 0xf8);

    *(undefined4 *)(param_1 + 0x3c) = param_2;

    param_1 = *plVar1;

    if (*plVar1 == 0) {

      return 1;

    }

  }

  uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","texture");

  return uVar3 & 0xffffffffffffff00;

}




