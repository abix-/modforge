// Address: 0x1401619a0
// Ghidra name: FUN_1401619a0
// ============ 0x1401619a0 FUN_1401619a0 (size=121) ============


void FUN_1401619a0(void)



{

  longlong lVar1;

  undefined8 uVar2;

  

  lVar1 = FUN_1401611a0();

  if ((*(longlong *)(lVar1 + 0x118) == 0) && (lVar1 = FUN_140145e60(1,1,0x16362004), lVar1 != 0)) {

    FUN_1402f94c0(*(undefined8 *)(lVar1 + 0x18),0,

                  (longlong)*(int *)(lVar1 + 0x10) * (longlong)*(int *)(lVar1 + 0xc));

    uVar2 = FUN_140160aa0(lVar1,0,0);

    FUN_140162be0(uVar2);

    FUN_140146010(lVar1);

    return;

  }

  return;

}




