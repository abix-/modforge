// Address: 0x14020a370
// Ghidra name: FUN_14020a370
// ============ 0x14020a370 FUN_14020a370 (size=946) ============


void FUN_14020a370(longlong param_1,undefined8 param_2,undefined4 param_3)



{

  short sVar1;

  int iVar2;

  int iVar3;

  undefined8 uVar4;

  longlong lVar5;

  int iVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  char *pcVar11;

  ulonglong uVar12;

  uint uVar13;

  uint uVar14;

  ulonglong uVar15;

  char cVar16;

  undefined2 *puVar17;

  int iVar18;

  ulonglong uVar19;

  undefined4 local_res8 [2];

  char *local_50;

  undefined2 local_48;

  

  pcVar11 = *(char **)(param_1 + 0x148);

  uVar9 = 0;

  uVar12 = *(ulonglong *)(pcVar11 + 0x40);

  local_res8[0] = *(undefined4 *)(pcVar11 + 0x10);

  iVar18 = *(int *)(param_1 + 0x70) - (uint)(byte)pcVar11[0x38];

  iVar6 = *(int *)(param_1 + 0x44) + (uint)(byte)pcVar11[0x39] * -2;

  iVar2 = *(int *)(param_1 + 0x60);

  local_50 = pcVar11;

  uVar4 = FUN_140149300();

  uVar15 = *(ulonglong *)(pcVar11 + 8);

  iVar3 = (*DAT_1403ffc08)(0,*(undefined8 *)(pcVar11 + 0x18),local_res8,uVar15,param_2,param_3);

  if (iVar3 != 0x110000) {

    return;

  }

  if (0 < iVar18) {

    puVar17 = *(undefined2 **)(pcVar11 + 0x20);

    uVar10 = uVar9;

    uVar19 = uVar9;

    do {

      iVar3 = (int)uVar10;

      lVar5 = FUN_1402099c0(*puVar17);

      if ((lVar5 != 0) && (*(char *)(lVar5 + 4) != '\0')) {

        uVar19 = (ulonglong)((uint)uVar19 | 1 << ((byte)iVar3 & 0x1f));

      }

      uVar10 = (ulonglong)(iVar3 + 1U);

      puVar17 = puVar17 + 1;

      uVar8 = uVar9;

    } while ((int)(iVar3 + 1U) < iVar18);

    do {

      uVar13 = 1 << ((byte)uVar8 & 0x1f) & (uint)uVar19;

      if ((byte)uVar8 < 10) {

        uVar7 = 1L << ((byte)*(undefined4 *)(&DAT_14034ffd8 + (uVar8 & 0xff) * 4) & 0x3f);

        uVar10 = uVar9;

        if (uVar13 != 0) {

          uVar10 = uVar7;

        }

        uVar12 = uVar12 & ~uVar7 | uVar10;

      }

      uVar15 = CONCAT71((int7)(uVar15 >> 8),uVar13 != 0);

      FUN_14015ad00(uVar4,param_1,uVar8 & 0xff,uVar15);

      uVar13 = (int)uVar8 + 1;

      uVar8 = (ulonglong)uVar13;

      pcVar11 = local_50;

    } while ((int)uVar13 < iVar18);

  }

  uVar10 = uVar9;

  if (0 < iVar6) {

    do {

      lVar5 = FUN_1402099c0(*(undefined2 *)(uVar10 + *(longlong *)(pcVar11 + 0x28)),

                            *(undefined8 *)(pcVar11 + 0x18),local_res8[0]);

      if (lVar5 != 0) {

        uVar15 = CONCAT62(0xffff,*(short *)(lVar5 + 4) + -0x8000);

        if ((byte)uVar9 < 4) {

          cVar16 = (byte)uVar9 * '\x04';

          uVar12 = uVar12 & ~(0xfL << (cVar16 + 0x10U & 0x3f)) |

                   (ulonglong)((uint)uVar15 & 0xf000) << (cVar16 + 4U & 0x3f);

        }

        FUN_14015aab0(uVar4,param_1,uVar9 & 0xff);

      }

      uVar13 = (int)uVar9 + 1;

      uVar9 = (ulonglong)uVar13;

      uVar10 = uVar10 + 2;

    } while ((int)uVar13 < iVar6);

  }

  uVar10 = 0;

  uVar9 = uVar10;

  if (0 < iVar2) {

    do {

      lVar5 = FUN_1402099c0(*(undefined2 *)(uVar10 + *(longlong *)(pcVar11 + 0x30)),

                            *(undefined8 *)(pcVar11 + 0x18),local_res8[0]);

      if (lVar5 != 0) {

        uVar13 = *(uint *)(lVar5 + 4);

        uVar15 = uVar15 & 0xffffffffffffff00;

        local_50 = (char *)0x80c040602030100;

        local_48 = 9;

        if (uVar13 < 10) {

          uVar15 = (ulonglong)*(byte *)((longlong)&local_50 + (ulonglong)uVar13);

          uVar12 = uVar12 & 0xffffffffffff87ff |

                   (longlong)*(int *)(&DAT_140350000 + (ulonglong)uVar13 * 4);

        }

        FUN_14015ae90(uVar4,param_1,uVar9 & 0xff,uVar15);

      }

      uVar13 = (int)uVar9 + 1;

      uVar10 = uVar10 + 2;

      uVar9 = (ulonglong)uVar13;

    } while ((int)uVar13 < iVar2);

  }

  if (pcVar11[0x39] == '\0') goto LAB_14020a6da;

  iVar2 = *(int *)(param_1 + 0x44);

  if ((pcVar11[0x50] == '\0') || (pcVar11[0x51] == '\0')) {

    cVar16 = '\0';

    if (pcVar11[0x56] != '\0') {

      cVar16 = '\x01';

    }

  }

  else {

    cVar16 = '\x01';

  }

  lVar5 = FUN_1402099c0(*(undefined2 *)(pcVar11 + 0x3a),*(undefined8 *)(pcVar11 + 0x18),

                        local_res8[0]);

  if (lVar5 == 0) goto LAB_14020a6da;

  sVar1 = *(short *)(lVar5 + 4);

  if ((short)(sVar1 + -0x8000) < 1) {

    uVar14 = 0xffff8000;

    uVar13 = 0xffff8000;

    if (-1 < (short)(sVar1 + -0x8000)) goto LAB_14020a679;

    uVar13 = (uint)(ushort)(sVar1 * -2 + 0x7fff);

  }

  else {

    uVar13 = (uint)(ushort)(sVar1 * 2 + 0x8001);

LAB_14020a679:

    uVar14 = uVar13;

    uVar13 = 0x8000;

  }

  uVar12 = ((ulonglong)(uVar14 & 0xf000) << 0x14 | uVar12 & 0xffffff00ffffffff) ^

           (ulonglong)(uVar13 & 0xf000) << 0x18;

  if (cVar16 == '\0') {

    FUN_14015aab0(uVar4,param_1,iVar2 + -2);

    FUN_14015aab0(uVar4,param_1,iVar2 + -1,uVar13);

  }

LAB_14020a6da:

  if (*pcVar11 != '\0') {

    *(ulonglong *)(pcVar11 + 0x40) = uVar12;

    uVar4 = FUN_140149350();

    *(undefined8 *)(pcVar11 + 0x48) = uVar4;

  }

  return;

}




