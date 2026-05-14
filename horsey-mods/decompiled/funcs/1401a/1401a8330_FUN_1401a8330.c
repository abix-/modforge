// Address: 0x1401a8330
// Ghidra name: FUN_1401a8330
// ============ 0x1401a8330 FUN_1401a8330 (size=62) ============


undefined4 FUN_1401a8330(undefined4 param_1)



{

  longlong lVar1;

  undefined4 uVar2;

  

  FUN_14017caa0(DAT_1403fcd48);

  lVar1 = FUN_1401a8110(param_1);

  if (lVar1 == 0) {

    uVar2 = 0xffffffff;

  }

  else {

    uVar2 = *(undefined4 *)(lVar1 + 0x24);

  }

  FUN_14017cae0(DAT_1403fcd48);

  return uVar2;

}




