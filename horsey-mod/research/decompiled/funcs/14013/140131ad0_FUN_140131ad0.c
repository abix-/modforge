// Address: 0x140131ad0
// Ghidra name: FUN_140131ad0
// ============ 0x140131ad0 FUN_140131ad0 (size=47) ============


undefined4 FUN_140131ad0(void)



{

  undefined4 uVar1;

  longlong lVar2;

  

  lVar2 = FUN_140130ab0();

  if (lVar2 != 0) {

    uVar1 = *(undefined4 *)(lVar2 + 0x10);

    FUN_140130b70(lVar2);

    return uVar1;

  }

  return 0;

}




