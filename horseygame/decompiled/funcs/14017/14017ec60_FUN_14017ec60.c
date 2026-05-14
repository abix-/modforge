// Address: 0x14017ec60
// Ghidra name: FUN_14017ec60
// ============ 0x14017ec60 FUN_14017ec60 (size=145) ============


ulonglong FUN_14017ec60(uint param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  

  uVar4 = 0;

  iVar3 = 0x20;

  if ((param_1 != 0) && ((param_1 & param_1 - 1) == 0)) {

    iVar3 = 0x1f;

    if (param_1 != 0) {

      for (; param_1 >> iVar3 == 0; iVar3 = iVar3 + -1) {

      }

    }

    iVar2 = -1;

    if (param_1 != 0) {

      iVar2 = iVar3;

    }

    if ((&DAT_1403fc648)[iVar2] != '\0') {

      uVar4 = (ulonglong)param_1;

    }

    return uVar4;

  }

  uVar5 = 0xffffffff;

  if (param_1 != 0) {

    uVar5 = (ulonglong)param_1;

  }

  iVar2 = 0x1f;

  uVar1 = (uint)uVar5;

  if (uVar1 != 0) {

    for (; uVar1 >> iVar2 == 0; iVar2 = iVar2 + -1) {

    }

  }

  if ((uVar1 == 0) || (iVar2 + 1 < 0x21)) {

    iVar2 = 0x1f;

    if (uVar1 != 0) {

      for (; uVar1 >> iVar2 == 0; iVar2 = iVar2 + -1) {

      }

    }

    iVar3 = -1;

    if (uVar1 != 0) {

      iVar3 = iVar2;

    }

    iVar3 = iVar3 + 1;

  }

  uVar6 = uVar4;

  if (0 < iVar3) {

    uVar1 = 1;

    do {

      if (((uVar5 & 1) != 0) && ((&DAT_1403fc648)[uVar4] != '\0')) {

        uVar6 = (ulonglong)((uint)uVar6 | uVar1);

      }

      uVar5 = uVar5 >> 1;

      uVar4 = uVar4 + 1;

      uVar1 = uVar1 << 1 | (uint)((int)uVar1 < 0);

    } while ((longlong)uVar4 < (longlong)iVar3);

  }

  return uVar6;

}




