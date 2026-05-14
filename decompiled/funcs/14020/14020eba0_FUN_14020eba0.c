// Address: 0x14020eba0
// Ghidra name: FUN_14020eba0
// ============ 0x14020eba0 FUN_14020eba0 (size=94) ============


void FUN_14020eba0(void)



{

  undefined8 uVar1;

  int iVar2;

  undefined8 local_res8 [4];

  undefined1 local_28 [40];

  

  uVar1 = FUN_14012fd40(L"Windows.Gaming.Input.RawGameController");

  iVar2 = (*DAT_1403fd288)(L"Windows.Gaming.Input.RawGameController",uVar1,local_28,local_res8);

  if (-1 < iVar2) {

    iVar2 = (*DAT_1403fd280)(local_res8[0],&DAT_140350618,&DAT_1403fd2a0);

    if (iVar2 < 0) {

      FUN_1401a9ef0("Couldn\'t find Windows.Gaming.Input.IRawGameControllerStatics",iVar2);

    }

  }

  return;

}




