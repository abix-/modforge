// Address: 0x1402175d0
// Ghidra name: FUN_1402175d0
// ============ 0x1402175d0 FUN_1402175d0 (size=64) ============


undefined4 FUN_1402175d0(LPVOID param_1)



{

  undefined4 uVar1;

  BOOL BVar2;

  

  if (DAT_1403fdb28 != '\0') {

    uVar1 = FUN_140163700();

    return uVar1;

  }

  BVar2 = TlsSetValue(DAT_1403e5308,param_1);

  if (BVar2 == 0) {

    uVar1 = FUN_1401a9ed0("TlsSetValue()");

    return uVar1;

  }

  return 1;

}




