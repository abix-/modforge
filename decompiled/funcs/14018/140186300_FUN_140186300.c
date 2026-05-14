// Address: 0x140186300
// Ghidra name: FUN_140186300
// ============ 0x140186300 FUN_140186300 (size=57) ============


undefined4 FUN_140186300(undefined8 param_1)



{

  longlong lVar1;

  undefined4 uVar2;

  

  uVar2 = 0xffffffff;

  FUN_140186540();

  lVar1 = FUN_140186240(param_1);

  if (lVar1 != 0) {

    uVar2 = *(undefined4 *)(lVar1 + 8);

  }

  FUN_140186c50();

  return uVar2;

}




