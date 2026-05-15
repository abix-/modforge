// Address: 0x1402c721c
// Ghidra name: FUN_1402c721c
// ============ 0x1402c721c FUN_1402c721c (size=58) ============


undefined1 FUN_1402c721c(int param_1)



{

  char cVar1;

  

  if (param_1 == 0) {

    DAT_1403fe638 = 1;

  }

  FUN_1402c7480();

  cVar1 = __vcrt_initialize();

  if (cVar1 != '\0') {

    cVar1 = FUN_1402e7ce8();

    if (cVar1 != '\0') {

      return 1;

    }

    __vcrt_uninitialize(0);

  }

  return 0;

}




