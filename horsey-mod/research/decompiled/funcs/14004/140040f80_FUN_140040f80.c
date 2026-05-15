// Address: 0x140040f80
// Ghidra name: FUN_140040f80
// ============ 0x140040f80 FUN_140040f80 (size=54) ============


void FUN_140040f80(int param_1,undefined4 param_2)



{

  longlong lVar1;

  

  if (((DAT_1403d9504 != 0) && (DAT_1403ea292 == '\0')) && (DAT_1403ea293 != '\0')) {

    lVar1 = FUN_14004f010((longlong)param_1);

    if (lVar1 != 0) {

      *(undefined4 *)(lVar1 + 0x18) = param_2;

    }

  }

  return;

}




