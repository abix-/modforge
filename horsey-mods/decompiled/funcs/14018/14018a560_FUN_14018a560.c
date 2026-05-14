// Address: 0x14018a560
// Ghidra name: FUN_14018a560
// ============ 0x14018a560 FUN_14018a560 (size=134) ============


undefined2 FUN_14018a560(longlong param_1)



{

  int iVar1;

  ulonglong uVar2;

  undefined *_Buf2;

  ulonglong uVar3;

  

  uVar2 = 0;

  _Buf2 = &DAT_1403e39b2;

  uVar3 = uVar2;

  do {

    iVar1 = memcmp((void *)(param_1 + 0x20),_Buf2,0x10);

    if (iVar1 == 0) {

      return (&DAT_1403e39b0)[uVar3 * 9];

    }

    uVar3 = uVar3 + 1;

    uVar2 = uVar2 + 0x12;

    _Buf2 = _Buf2 + 0x12;

  } while (uVar2 < 0x6c);

  return 0;

}




