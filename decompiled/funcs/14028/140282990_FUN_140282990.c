// Address: 0x140282990
// Ghidra name: FUN_140282990
// ============ 0x140282990 FUN_140282990 (size=515) ============


void FUN_140282990(longlong param_1)



{

  uint uVar1;

  byte bVar2;

  longlong lVar3;

  bool bVar4;

  byte bVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  byte bVar10;

  int iVar11;

  undefined1 uVar12;

  int iVar13;

  int iVar14;

  undefined1 uStackX_11;

  

  lVar3 = *(longlong *)(param_1 + 0x70);

  iVar11 = 0;

  bVar10 = 1;

  uStackX_11 = 0;

  iVar14 = 0;

  *(undefined1 *)(lVar3 + 0x17) = 1;

  bVar5 = *(byte *)(lVar3 + 0x6f);

  if ((bVar5 & 4) == 0) {

    if ((bVar5 & 8) != 0) {

      uStackX_11 = 8;

      goto LAB_1402829f1;

    }

  }

  else if ((bVar5 & 8) == 0) {

    uStackX_11 = 4;

LAB_1402829f1:

    iVar14 = 1;

  }

  else {

    iVar14 = 2;

    uStackX_11 = 0xc;

  }

  if ((*(char *)(lVar3 + 0x15) == '\0') && (*(char *)(lVar3 + 0x16) == '\0')) {

    bVar4 = false;

  }

  else {

    bVar4 = true;

  }

  bVar2 = *(byte *)(lVar3 + 0x70);

  iVar7 = 0;

  if (*(char *)(lVar3 + 0x13) == '\0') {

    if (*(char *)(lVar3 + 0x14) != '\0') {

      iVar7 = 2;

      goto LAB_140282a50;

    }

  }

  else {

    if (*(char *)(lVar3 + 0x14) == '\0') {

      iVar7 = 1;

    }

    else {

      iVar7 = 3;

    }

LAB_140282a50:

    uStackX_11 = uStackX_11 | (byte)iVar7;

  }

  iVar8 = 0;

  if (bVar4) {

    if ((bVar5 & 0x30) == 0) {

      iVar8 = 1;

      goto LAB_140282a7a;

    }

    iVar8 = 3;

  }

  else {

    if ((bVar5 & 0x30) == 0) goto LAB_140282a7a;

    iVar8 = 2;

  }

  uStackX_11 = uStackX_11 | 0x30;

LAB_140282a7a:

  iVar13 = 0;

  if ((bVar5 & 0xc0) != 0) {

    uStackX_11 = uStackX_11 | 0xc0;

    if ((bVar2 & 0x30) == 0) {

      iVar13 = 1;

    }

    else {

      iVar13 = 2;

      bVar10 = 0x31;

    }

  }

  iVar6 = 0;

  if ((bVar2 & 8) == 0) {

    if ((bVar2 & 4) == 0) {

      if ((bVar2 & 2) != 0) {

        iVar6 = 1;

        bVar10 = bVar10 | 2;

      }

    }

    else {

      iVar6 = 2;

      bVar10 = bVar10 | 6;

    }

  }

  else {

    iVar6 = 3;

    bVar10 = bVar10 | 0xe;

  }

  iVar9 = 0;

  if ((bVar2 & 0x40) != 0) {

    if ((bVar2 & 0x80) == 0) {

      iVar9 = 1;

      bVar10 = bVar10 | 0x40;

    }

    else {

      iVar9 = 2;

      bVar10 = bVar10 | 0xc0;

    }

  }

  bVar5 = *(byte *)(lVar3 + 0x71) & 0xf;

  if (bVar5 == 1) {

    iVar11 = 1;

    uVar12 = 1;

  }

  else if (bVar5 == 3) {

    iVar11 = 2;

    uVar12 = 3;

  }

  else if (bVar5 == 7) {

    iVar11 = 3;

    uVar12 = 7;

  }

  else if (bVar5 == 0xf) {

    iVar11 = 4;

    uVar12 = 0xf;

  }

  else {

    uVar12 = 0;

  }

  *(undefined1 *)(lVar3 + 0x6e) = 0xff;

  *(byte *)(lVar3 + 0x6f) = uStackX_11;

  *(byte *)(lVar3 + 0x70) = bVar10;

  *(undefined1 *)(lVar3 + 0x71) = uVar12;

  uVar1 = iVar11 + (iVar9 + (iVar6 + (iVar13 + (iVar8 + (iVar14 + iVar7 * 3) * 4) * 3) * 4) * 3) * 5

  ;

  if (0xffff < uVar1) {

    uVar1 = 0xffff;

  }

  *(char *)(param_1 + 0x3c) = (char)uVar1;

  *(char *)(param_1 + 0x3d) = (char)(uVar1 >> 8);

  return;

}




