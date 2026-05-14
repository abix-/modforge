// Address: 0x14017d520
// Ghidra name: FUN_14017d520
// ============ 0x14017d520 FUN_14017d520 (size=158) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14017d520(void)



{

  int iVar1;

  longlong lVar2;

  char *in_R9;

  double dVar3;

  

  if ((in_R9 != (char *)0x0) && (iVar1 = strcmp(in_R9,"waitevent"), iVar1 == 0)) {

    DAT_1403fc618 = 0;

    DAT_1403fc620 = 1;

    return;

  }

  DAT_1403fc620 = 0;

  if ((in_R9 != (char *)0x0) && (dVar3 = (double)thunk_FUN_1402de5ec(), 0.0 < dVar3)) {

    lVar2 = 0;

    dVar3 = DAT_140337230 / dVar3;

    if ((_DAT_140337238 <= dVar3) && (dVar3 = dVar3 - _DAT_140337238, dVar3 < _DAT_140337238)) {

      lVar2 = -0x8000000000000000;

    }

    DAT_1403fc618 = (longlong)dVar3 + lVar2;

    return;

  }

  DAT_1403fc618 = 0;

  return;

}




