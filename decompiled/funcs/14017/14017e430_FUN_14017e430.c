// Address: 0x14017e430
// Ghidra name: FUN_14017e430
// ============ 0x14017e430 FUN_14017e430 (size=43) ============


longlong FUN_14017e430(uint param_1)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  

  iVar2 = 0x1f;

  if (param_1 != 0) {

    for (; param_1 >> iVar2 == 0; iVar2 = iVar2 + -1) {

    }

  }

  if ((param_1 != 0) && (-1 < iVar2)) {

    cVar1 = (&DAT_1403fc648)[iVar2];

    if (cVar1 != '\0') {

      (&DAT_1403fc648)[iVar2] = cVar1 + '\x01';

      return 1;

    }

    lVar3 = FUN_14017e460();

    return lVar3;

  }

  return (ulonglong)(uint3)((uint)iVar2 >> 8) << 8;

}




