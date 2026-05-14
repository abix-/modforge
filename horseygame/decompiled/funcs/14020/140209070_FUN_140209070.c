// Address: 0x140209070
// Ghidra name: FUN_140209070
// ============ 0x140209070 FUN_140209070 (size=112) ============


void FUN_140209070(void)



{

  int iVar1;

  

  if (DAT_1403fd1b0 == '\0') {

    return;

  }

  iVar1 = GetSystemMetrics(0x1000);

  if ((iVar1 != 0) != (bool)DAT_1403fd1b1) {

    DAT_1403fd1b1 = iVar1 != 0;

    thunk_FUN_14020f650();

    if (iVar1 != 0) {

      FUN_14020acc0();

      FUN_14020ec00();

      FUN_14020a950();

      return;

    }

    FUN_14020ec00();

    FUN_140209ec0();

  }

  FUN_14020a950();

  return;

}




