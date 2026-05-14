// Address: 0x140264b60
// Ghidra name: FUN_140264b60
// ============ 0x140264b60 FUN_140264b60 (size=68) ============


uint FUN_140264b60(void)



{

  uint uVar1;

  longlong lVar2;

  uint uVar3;

  

  lVar2 = FUN_140268130();

  uVar3 = 0;

  if (lVar2 == 0) {

    return 0;

  }

  if (((*(uint *)(lVar2 + 0x14c) & 0x20) != 0) &&

     (uVar3 = 0x10, (*(byte *)(lVar2 + 0x150) & 4) == 0)) {

    uVar3 = 0x30;

  }

  uVar1 = uVar3 | 2;

  if ((*(uint *)(lVar2 + 0x14c) & 0x40) == 0) {

    uVar1 = uVar3;

  }

  return uVar1;

}




