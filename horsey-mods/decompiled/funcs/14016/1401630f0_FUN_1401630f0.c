// Address: 0x1401630f0
// Ghidra name: FUN_1401630f0
// ============ 0x1401630f0 FUN_1401630f0 (size=66) ============


undefined1 FUN_1401630f0(void)



{

  longlong lVar1;

  undefined1 uVar2;

  longlong lVar3;

  char cVar4;

  

  lVar1 = FUN_1401611a0();

  lVar3 = FUN_140183290();

  if (lVar3 != 0) {

    if ((*(uint *)(lVar3 + 0x48) >> 0xf & 1) != 0) {

      cVar4 = '\x01';

      goto LAB_140163118;

    }

  }

  cVar4 = '\0';

LAB_140163118:

  if (cVar4 == *(char *)(lVar1 + 0xc1)) {

    return 1;

  }

  uVar2 = FUN_140162d10();

  return uVar2;

}




