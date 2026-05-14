// Address: 0x1402e7f2c
// Ghidra name: FUN_1402e7f2c
// ============ 0x1402e7f2c FUN_1402e7f2c (size=228) ============


undefined8 FUN_1402e7f2c(uint param_1,int param_2)



{

  byte bVar1;

  char cVar2;

  longlong lVar3;

  ulonglong uVar4;

  undefined8 uVar5;

  longlong lVar6;

  

  lVar6 = (longlong)(int)param_1 >> 6;

  uVar4 = (ulonglong)(param_1 & 0x3f);

  lVar3 = (&DAT_1403ff160)[lVar6];

  bVar1 = *(byte *)(lVar3 + 0x38 + uVar4 * 0x48);

  cVar2 = *(char *)(lVar3 + 0x39 + uVar4 * 0x48);

  if (param_2 == 0x4000) {

    *(byte *)(lVar3 + 0x38 + uVar4 * 0x48) = bVar1 | 0x80;

    *(undefined1 *)((&DAT_1403ff160)[lVar6] + 0x39 + uVar4 * 0x48) = 0;

  }

  else if (param_2 == 0x8000) {

    *(byte *)(lVar3 + 0x38 + uVar4 * 0x48) = bVar1 & 0x7f;

  }

  else if ((param_2 - 0x10000U & 0xfffeffff) == 0) {

    *(byte *)(lVar3 + 0x38 + uVar4 * 0x48) = bVar1 | 0x80;

    *(undefined1 *)((&DAT_1403ff160)[lVar6] + 0x39 + uVar4 * 0x48) = 2;

  }

  else if (param_2 == 0x40000) {

    *(byte *)(lVar3 + 0x38 + uVar4 * 0x48) = bVar1 | 0x80;

    *(undefined1 *)((&DAT_1403ff160)[lVar6] + 0x39 + uVar4 * 0x48) = 1;

  }

  if ((bVar1 & 0x80) == 0) {

    uVar5 = 0x8000;

  }

  else if (cVar2 == '\0') {

    uVar5 = 0x4000;

  }

  else {

    uVar5 = 0x10000;

    if (cVar2 == '\x01') {

      uVar5 = 0x40000;

    }

  }

  return uVar5;

}




