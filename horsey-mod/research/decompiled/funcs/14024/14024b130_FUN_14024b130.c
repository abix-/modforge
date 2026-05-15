// Address: 0x14024b130
// Ghidra name: FUN_14024b130
// ============ 0x14024b130 FUN_14024b130 (size=7535) ============


ulonglong FUN_14024b130(longlong param_1,int param_2,int param_3,int param_4,uint param_5,

                       uint param_6,byte param_7,byte param_8,byte param_9,byte param_10,

                       byte param_11)



{

  uint *puVar1;

  bool bVar2;

  longlong lVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  int iVar8;

  uint uVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  longlong lVar12;

  uint uVar13;

  longlong lVar14;

  uint uVar15;

  uint uVar16;

  int iVar17;

  uint uVar18;

  int iVar19;

  uint *puVar20;

  uint uVar21;

  uint uVar22;

  uint uVar23;

  int local_res18;

  int local_58;

  int local_50;

  ulonglong local_40;

  ulonglong local_38;

  

  iVar8 = param_5;

  uVar7 = (uint)param_10;

  lVar14 = (longlong)param_2;

  if (param_6 - 1 < 2) {

    uVar21 = ((uint)param_7 * (uint)param_10) / 0xff;

    uVar22 = ((uint)param_8 * (uint)param_10) / 0xff;

    uVar15 = (param_9 * uVar7) / 0xff;

  }

  else {

    uVar21 = (uint)param_7;

    uVar22 = (uint)param_8;

    uVar15 = (uint)param_9;

  }

  iVar19 = param_6 + -1;

  uVar23 = uVar7 ^ 0xff;

  uVar13 = 0xff;

  if (param_3 == param_5) {

    switch(iVar19) {

    case 0:

      uVar13 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar10 = (ulonglong)uVar13;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar13) * 4);

        uVar10 = (ulonglong)param_11;

        puVar20 = puVar1 + 1;

        if (param_11 != 0) {

          puVar20 = puVar1;

        }

        iVar8 = param_2 - param_4;

        if (param_11 != 0) {

          iVar8 = iVar8 + 1;

        }

      }

      else {

        iVar8 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar8 = param_4 - param_2;

        }

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar13 + lVar14) * 4);

      }

      for (; iVar8 != 0; iVar8 = iVar8 + -1) {

        uVar13 = *puVar20;

        uVar16 = (uVar13 & 0xff) * uVar23;

        uVar10 = (ulonglong)uVar16 * 0x80808081 & 0xffffffff;

        *puVar20 = (((uVar13 >> 8 & 0xff) * uVar23) / 0xff + uVar22) * 0x100 |

                   (((uVar13 >> 0x10 & 0xff) * uVar23) / 0xff + uVar21) * 0x10000 |

                   (((uVar13 >> 0x18) * uVar23) / 0xff + uVar7) * 0x1000000 | uVar16 / 0xff + uVar15

        ;

        puVar20 = puVar20 + 1;

      }

      break;

    case 1:

    case 0x1f:

      uVar7 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5)) *

              param_3;

      uVar10 = (ulonglong)uVar7;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar7) * 4);

        uVar10 = (ulonglong)param_11;

        puVar20 = puVar1 + 1;

        if (param_11 != 0) {

          puVar20 = puVar1;

        }

        iVar8 = param_2 - param_4;

        if (param_11 != 0) {

          iVar8 = iVar8 + 1;

        }

      }

      else {

        iVar8 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar8 = param_4 - param_2;

        }

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar7 + lVar14) * 4);

      }

      for (; iVar8 != 0; iVar8 = iVar8 + -1) {

        uVar7 = *puVar20;

        uVar10 = (ulonglong)(uVar7 >> 0x10);

        uVar23 = (uVar7 >> 0x10 & 0xff) + uVar21;

        if (0xff < uVar23) {

          uVar23 = 0xff;

        }

        uVar16 = *(byte *)((longlong)puVar20 + 1) + uVar22;

        if (0xff < uVar16) {

          uVar16 = 0xff;

        }

        uVar18 = (uVar7 & 0xff) + uVar15;

        if (0xff < uVar18) {

          uVar18 = uVar13;

        }

        *puVar20 = (((uVar7 >> 0x18) << 8 | uVar23) << 8 | uVar16) << 8 | uVar18;

        puVar20 = puVar20 + 1;

      }

      break;

    default:

      uVar23 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar10 = (ulonglong)uVar23;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar23) * 4);

        uVar10 = (ulonglong)param_11;

        puVar20 = puVar1 + 1;

        if (param_11 != 0) {

          puVar20 = puVar1;

        }

        uVar13 = param_2 - param_4;

        if (param_11 != 0) {

          uVar13 = uVar13 + 1;

        }

      }

      else {

        uVar13 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          uVar13 = param_4 - param_2;

        }

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar23 + lVar14) * 4);

      }

      if (uVar13 != 0) {

        uVar15 = ((uVar7 << 8 | uVar21) << 8 | uVar22) << 8 | uVar15;

        uVar10 = (ulonglong)uVar15;

        for (uVar11 = (ulonglong)uVar13; uVar11 != 0; uVar11 = uVar11 - 1) {

          *puVar20 = uVar15;

          puVar20 = puVar20 + 1;

        }

      }

      break;

    case 3:

      uVar7 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5)) *

              param_3;

      uVar10 = (ulonglong)uVar7;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar7) * 4);

        uVar10 = (ulonglong)param_11;

        puVar20 = puVar1 + 1;

        if (param_11 != 0) {

          puVar20 = puVar1;

        }

        iVar8 = param_2 - param_4;

        if (param_11 != 0) {

          iVar8 = iVar8 + 1;

        }

      }

      else {

        iVar8 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar8 = param_4 - param_2;

        }

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar7 + lVar14) * 4);

      }

      for (; iVar8 != 0; iVar8 = iVar8 + -1) {

        uVar7 = *puVar20;

        uVar23 = (uVar7 & 0xff) * uVar15;

        uVar10 = (ulonglong)uVar23 * 0x80808081 & 0xffffffff;

        *puVar20 = (((uVar7 >> 0x10 & 0xff) * uVar21) / 0xff << 8 |

                   ((uVar7 >> 8 & 0xff) * uVar22) / 0xff) << 8 | uVar23 / 0xff | uVar7 & 0xff000000;

        puVar20 = puVar20 + 1;

      }

      break;

    case 7:

      uVar7 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5)) *

              param_3;

      uVar10 = (ulonglong)uVar7;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar7) * 4);

        uVar10 = (ulonglong)param_11;

        puVar20 = puVar1 + 1;

        if (param_11 != 0) {

          puVar20 = puVar1;

        }

        iVar8 = param_2 - param_4;

        if (param_11 != 0) {

          iVar8 = iVar8 + 1;

        }

      }

      else {

        iVar8 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar8 = param_4 - param_2;

        }

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar7 + lVar14) * 4);

      }

      for (; iVar8 != 0; iVar8 = iVar8 + -1) {

        uVar16 = *puVar20 & 0xff;

        uVar7 = (*(byte *)((longlong)puVar20 + 2) * uVar23) / 0xff +

                (*(byte *)((longlong)puVar20 + 2) * uVar21) / 0xff;

        if (0xff < uVar7) {

          uVar7 = 0xff;

        }

        uVar18 = (*(byte *)((longlong)puVar20 + 1) * uVar23) / 0xff +

                 (*(byte *)((longlong)puVar20 + 1) * uVar22) / 0xff;

        if (0xff < uVar18) {

          uVar18 = 0xff;

        }

        uVar16 = (uVar16 * uVar23) / 0xff + (uVar16 * uVar15) / 0xff;

        if (0xff < uVar16) {

          uVar16 = uVar13;

        }

        uVar10 = (ulonglong)uVar16;

        *puVar20 = (((*puVar20 >> 0x18) << 8 | uVar7) << 8 | uVar18) << 8 | uVar16;

        puVar20 = puVar20 + 1;

      }

      break;

    case 0xf:

      uVar13 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar10 = (ulonglong)uVar13;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar13) * 4);

        uVar10 = (ulonglong)param_11;

        puVar20 = puVar1 + 1;

        if (param_11 != 0) {

          puVar20 = puVar1;

        }

        iVar8 = param_2 - param_4;

        if (param_11 != 0) {

          iVar8 = iVar8 + 1;

        }

      }

      else {

        iVar8 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar8 = param_4 - param_2;

        }

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar13 + lVar14) * 4);

      }

      for (; iVar8 != 0; iVar8 = iVar8 + -1) {

        uVar16 = *puVar20;

        uVar13 = ((uVar16 >> 0x10 & 0xff) * uVar23) / 0xff + uVar21;

        if (0xff < uVar13) {

          uVar13 = 0xff;

        }

        uVar18 = (*(byte *)((longlong)puVar20 + 1) * uVar23) / 0xff + uVar22;

        if (0xff < uVar18) {

          uVar18 = 0xff;

        }

        uVar6 = ((uVar16 & 0xff) * uVar23) / 0xff + uVar15;

        if (0xff < uVar6) {

          uVar6 = 0xff;

        }

        uVar16 = ((uVar16 >> 0x18) * uVar23) / 0xff + uVar7;

        if (0xff < uVar16) {

          uVar16 = 0xff;

        }

        uVar6 = ((uVar16 << 8 | uVar13) << 8 | uVar18) << 8 | uVar6;

        uVar10 = (ulonglong)uVar6;

        *puVar20 = uVar6;

        puVar20 = puVar20 + 1;

      }

    }

  }

  else if (param_2 == param_4) {

    switch(iVar19) {

    case 0:

      iVar8 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar19 = param_3 - param_5;

        uVar10 = (int)(iVar8 * param_5) + lVar14;

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar10 * 4);

        if (param_11 == 0) {

          puVar20 = puVar20 + iVar8;

        }

        else {

          iVar19 = iVar19 + 1;

        }

      }

      else {

        uVar10 = iVar8 * param_3 + lVar14;

        iVar19 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar19 = param_5 - param_3;

        }

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar10 * 4);

      }

      for (; iVar19 != 0; iVar19 = iVar19 + -1) {

        uVar13 = *puVar20;

        uVar16 = (uVar13 & 0xff) * uVar23;

        uVar10 = (ulonglong)uVar16 * 0x80808081 & 0xffffffff;

        *puVar20 = (((uVar13 >> 8 & 0xff) * uVar23) / 0xff + uVar22) * 0x100 |

                   (((uVar13 >> 0x10 & 0xff) * uVar23) / 0xff + uVar21) * 0x10000 |

                   (((uVar13 >> 0x18) * uVar23) / 0xff + uVar7) * 0x1000000 | uVar16 / 0xff + uVar15

        ;

        puVar20 = puVar20 + iVar8;

      }

      break;

    case 1:

    case 0x1f:

      iVar8 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar19 = param_3 - param_5;

        uVar10 = (int)(iVar8 * param_5) + lVar14;

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar10 * 4);

        if (param_11 == 0) {

          puVar20 = puVar20 + iVar8;

        }

        else {

          iVar19 = iVar19 + 1;

        }

      }

      else {

        uVar10 = iVar8 * param_3 + lVar14;

        iVar19 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar19 = param_5 - param_3;

        }

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar10 * 4);

      }

      for (; iVar19 != 0; iVar19 = iVar19 + -1) {

        uVar7 = *puVar20;

        uVar10 = (ulonglong)(uVar7 >> 0x10);

        uVar23 = (uVar7 >> 0x10 & 0xff) + uVar21;

        if (0xff < uVar23) {

          uVar23 = 0xff;

        }

        uVar16 = *(byte *)((longlong)puVar20 + 1) + uVar22;

        if (0xff < uVar16) {

          uVar16 = 0xff;

        }

        uVar18 = (uVar7 & 0xff) + uVar15;

        if (0xff < uVar18) {

          uVar18 = uVar13;

        }

        *puVar20 = (((uVar7 >> 0x18) << 8 | uVar23) << 8 | uVar16) << 8 | uVar18;

        puVar20 = puVar20 + iVar8;

      }

      break;

    default:

      iVar8 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar19 = param_3 - param_5;

        uVar10 = (int)(iVar8 * param_5) + lVar14;

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar10 * 4);

        if (param_11 == 0) {

          puVar20 = puVar20 + iVar8;

        }

        else {

          iVar19 = iVar19 + 1;

        }

      }

      else {

        uVar10 = iVar8 * param_3 + lVar14;

        iVar19 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar19 = param_5 - param_3;

        }

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar10 * 4);

      }

      if (iVar19 != 0) {

        do {

          *puVar20 = ((uVar7 << 8 | uVar21) << 8 | uVar22) << 8 | uVar15;

          puVar20 = puVar20 + iVar8;

          iVar19 = iVar19 + -1;

        } while (iVar19 != 0);

      }

      break;

    case 3:

      iVar8 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar19 = param_3 - param_5;

        uVar10 = (int)(iVar8 * param_5) + lVar14;

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar10 * 4);

        if (param_11 == 0) {

          puVar20 = puVar20 + iVar8;

        }

        else {

          iVar19 = iVar19 + 1;

        }

      }

      else {

        uVar10 = iVar8 * param_3 + lVar14;

        iVar19 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar19 = param_5 - param_3;

        }

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar10 * 4);

      }

      for (; iVar19 != 0; iVar19 = iVar19 + -1) {

        uVar7 = *puVar20;

        uVar23 = (uVar7 & 0xff) * uVar15;

        uVar10 = (ulonglong)uVar23 * 0x80808081 & 0xffffffff;

        *puVar20 = (((uVar7 >> 0x10 & 0xff) * uVar21) / 0xff << 8 |

                   ((uVar7 >> 8 & 0xff) * uVar22) / 0xff) << 8 | uVar23 / 0xff | uVar7 & 0xff000000;

        puVar20 = puVar20 + iVar8;

      }

      break;

    case 7:

      iVar8 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar19 = param_3 - param_5;

        uVar10 = (int)(iVar8 * param_5) + lVar14;

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar10 * 4);

        if (param_11 == 0) {

          puVar20 = puVar20 + iVar8;

        }

        else {

          iVar19 = iVar19 + 1;

        }

      }

      else {

        uVar10 = iVar8 * param_3 + lVar14;

        iVar19 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar19 = param_5 - param_3;

        }

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar10 * 4);

      }

      for (; iVar19 != 0; iVar19 = iVar19 + -1) {

        uVar13 = *puVar20 & 0xff;

        uVar7 = (*(byte *)((longlong)puVar20 + 2) * uVar23) / 0xff +

                (*(byte *)((longlong)puVar20 + 2) * uVar21) / 0xff;

        if (0xff < uVar7) {

          uVar7 = 0xff;

        }

        uVar16 = (*(byte *)((longlong)puVar20 + 1) * uVar23) / 0xff +

                 (*(byte *)((longlong)puVar20 + 1) * uVar22) / 0xff;

        if (0xff < uVar16) {

          uVar16 = 0xff;

        }

        uVar13 = (uVar13 * uVar23) / 0xff + (uVar13 * uVar15) / 0xff;

        if (0xff < uVar13) {

          uVar13 = 0xff;

        }

        uVar10 = (ulonglong)uVar13;

        *puVar20 = (((*puVar20 >> 0x18) << 8 | uVar7) << 8 | uVar16) << 8 | uVar13;

        puVar20 = puVar20 + iVar8;

      }

      break;

    case 0xf:

      iVar8 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar19 = param_3 - param_5;

        uVar10 = (int)(iVar8 * param_5) + lVar14;

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar10 * 4);

        if (param_11 == 0) {

          puVar20 = puVar20 + iVar8;

        }

        else {

          iVar19 = iVar19 + 1;

        }

      }

      else {

        uVar10 = iVar8 * param_3 + lVar14;

        iVar19 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar19 = param_5 - param_3;

        }

        puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar10 * 4);

      }

      for (; iVar19 != 0; iVar19 = iVar19 + -1) {

        uVar16 = *puVar20;

        uVar13 = ((uVar16 >> 0x10 & 0xff) * uVar23) / 0xff + uVar21;

        if (0xff < uVar13) {

          uVar13 = 0xff;

        }

        uVar18 = (*(byte *)((longlong)puVar20 + 1) * uVar23) / 0xff + uVar22;

        if (0xff < uVar18) {

          uVar18 = 0xff;

        }

        uVar6 = ((uVar16 & 0xff) * uVar23) / 0xff + uVar15;

        if (0xff < uVar6) {

          uVar6 = 0xff;

        }

        uVar16 = ((uVar16 >> 0x18) * uVar23) / 0xff + uVar7;

        if (0xff < uVar16) {

          uVar16 = 0xff;

        }

        uVar6 = ((uVar16 << 8 | uVar13) << 8 | uVar18) << 8 | uVar6;

        uVar10 = (ulonglong)uVar6;

        *puVar20 = uVar6;

        puVar20 = puVar20 + iVar8;

      }

    }

  }

  else {

    uVar16 = param_3 - param_5;

    uVar13 = -(param_2 - param_4);

    if ((int)uVar13 < 0) {

      uVar13 = param_2 - param_4;

    }

    uVar18 = -uVar16;

    if ((int)-uVar16 < 0) {

      uVar18 = uVar16;

    }

    if (uVar13 == uVar18) {

      switch(iVar19) {

      case 0:

        uVar11 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar10 = uVar11 & 0xffffffff;

        iVar8 = (int)uVar11;

        if ((int)param_5 < param_3) {

          uVar10 = (ulonglong)param_4;

          puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(int)(iVar8 * param_5) + uVar10) * 4);

          iVar19 = 1;

          if (param_2 < param_4) {

            iVar19 = -1;

          }

          iVar19 = iVar19 + iVar8;

          if (param_11 == 0) {

            uVar10 = (ulonglong)iVar19;

            puVar20 = puVar20 + uVar10;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar8 * param_3 + lVar14) * 4);

          iVar19 = 1;

          if (param_4 < param_2) {

            iVar19 = -1;

          }

          iVar19 = iVar19 + iVar8;

        }

        uVar13 = uVar16 + 1;

        if (param_11 == 0) {

          uVar13 = uVar16;

        }

        if (uVar13 != 0) {

          do {

            uVar16 = *puVar20;

            uVar18 = (uVar16 & 0xff) * uVar23;

            uVar10 = (ulonglong)uVar18 * 0x80808081 & 0xffffffff;

            *puVar20 = (((uVar16 >> 8 & 0xff) * uVar23) / 0xff + uVar22) * 0x100 |

                       (((uVar16 >> 0x10 & 0xff) * uVar23) / 0xff + uVar21) * 0x10000 |

                       (((uVar16 >> 0x18) * uVar23) / 0xff + uVar7) * 0x1000000 |

                       uVar18 / 0xff + uVar15;

            puVar20 = puVar20 + iVar19;

            uVar13 = uVar13 - 1;

          } while (uVar13 != 0);

        }

        break;

      case 1:

      case 0x1f:

        uVar11 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar10 = uVar11 & 0xffffffff;

        iVar8 = (int)uVar11;

        if ((int)param_5 < param_3) {

          uVar10 = (ulonglong)param_4;

          puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(int)(iVar8 * param_5) + uVar10) * 4);

          iVar19 = 1;

          if (param_2 < param_4) {

            iVar19 = -1;

          }

          iVar19 = iVar19 + iVar8;

          if (param_11 == 0) {

            uVar10 = (ulonglong)iVar19;

            puVar20 = puVar20 + uVar10;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          iVar19 = 1;

          if (param_4 < param_2) {

            iVar19 = -1;

          }

          iVar19 = iVar19 + iVar8;

          puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar8 * param_3 + lVar14) * 4);

        }

        uVar7 = uVar16 + 1;

        if (param_11 == 0) {

          uVar7 = uVar16;

        }

        if (uVar7 != 0) {

          do {

            uVar23 = *puVar20;

            uVar10 = 0xff;

            uVar13 = (uVar23 >> 0x10 & 0xff) + uVar21;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar16 = *(byte *)((longlong)puVar20 + 1) + uVar22;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar18 = (uVar23 & 0xff) + uVar15;

            if (0xff < uVar18) {

              uVar18 = 0xff;

            }

            *puVar20 = (((uVar23 >> 0x18) << 8 | uVar13) << 8 | uVar16) << 8 | uVar18;

            puVar20 = puVar20 + iVar19;

            uVar7 = uVar7 - 1;

          } while (uVar7 != 0);

        }

        break;

      default:

        iVar8 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        if ((int)param_5 < param_3) {

          puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(int)(iVar8 * param_5) + (longlong)param_4) * 4);

          iVar19 = 1;

          if (param_2 < param_4) {

            iVar19 = -1;

          }

          iVar19 = iVar19 + iVar8;

          if (param_11 == 0) {

            puVar20 = puVar20 + iVar19;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar8 * param_3 + lVar14) * 4);

          iVar19 = 1;

          if (param_4 < param_2) {

            iVar19 = -1;

          }

          iVar19 = iVar19 + iVar8;

        }

        uVar23 = uVar16 + 1;

        if (param_11 == 0) {

          uVar23 = uVar16;

        }

        uVar10 = (ulonglong)uVar23;

        if (uVar23 != 0) {

          do {

            *puVar20 = ((uVar7 << 8 | uVar21) << 8 | uVar22) << 8 | uVar15;

            puVar20 = puVar20 + iVar19;

            uVar23 = (int)uVar10 - 1;

            uVar10 = (ulonglong)uVar23;

          } while (uVar23 != 0);

          uVar10 = 0;

        }

        break;

      case 3:

        uVar11 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar10 = uVar11 & 0xffffffff;

        iVar8 = (int)uVar11;

        if ((int)param_5 < param_3) {

          uVar10 = (ulonglong)param_4;

          puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(int)(iVar8 * param_5) + uVar10) * 4);

          iVar19 = 1;

          if (param_2 < param_4) {

            iVar19 = -1;

          }

          iVar19 = iVar19 + iVar8;

          if (param_11 == 0) {

            uVar10 = (ulonglong)iVar19;

            puVar20 = puVar20 + uVar10;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          iVar19 = 1;

          if (param_4 < param_2) {

            iVar19 = -1;

          }

          iVar19 = iVar19 + iVar8;

          puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar8 * param_3 + lVar14) * 4);

        }

        uVar7 = uVar16 + 1;

        if (param_11 == 0) {

          uVar7 = uVar16;

        }

        if (uVar7 != 0) {

          do {

            uVar23 = *puVar20;

            uVar13 = (uVar23 & 0xff) * uVar15;

            uVar10 = (ulonglong)uVar13 * 0x80808081 & 0xffffffff;

            *puVar20 = (((uVar23 >> 0x10 & 0xff) * uVar21) / 0xff << 8 |

                       ((uVar23 >> 8 & 0xff) * uVar22) / 0xff) << 8 | uVar13 / 0xff |

                       uVar23 & 0xff000000;

            puVar20 = puVar20 + iVar19;

            uVar7 = uVar7 - 1;

          } while (uVar7 != 0);

        }

        break;

      case 7:

        uVar11 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar10 = uVar11 & 0xffffffff;

        iVar8 = (int)uVar11;

        if ((int)param_5 < param_3) {

          uVar10 = (ulonglong)param_4;

          puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(int)(iVar8 * param_5) + uVar10) * 4);

          iVar19 = 1;

          if (param_2 < param_4) {

            iVar19 = -1;

          }

          iVar19 = iVar19 + iVar8;

          if (param_11 == 0) {

            uVar10 = (ulonglong)iVar19;

            puVar20 = puVar20 + uVar10;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          iVar19 = 1;

          if (param_4 < param_2) {

            iVar19 = -1;

          }

          iVar19 = iVar19 + iVar8;

          puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar8 * param_3 + lVar14) * 4);

        }

        uVar7 = uVar16 + 1;

        if (param_11 == 0) {

          uVar7 = uVar16;

        }

        if (uVar7 != 0) {

          do {

            uVar16 = *puVar20 & 0xff;

            uVar13 = (*(byte *)((longlong)puVar20 + 2) * uVar23) / 0xff +

                     (*(byte *)((longlong)puVar20 + 2) * uVar21) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar18 = (*(byte *)((longlong)puVar20 + 1) * uVar23) / 0xff +

                     (*(byte *)((longlong)puVar20 + 1) * uVar22) / 0xff;

            if (0xff < uVar18) {

              uVar18 = 0xff;

            }

            uVar16 = (uVar16 * uVar23) / 0xff + (uVar16 * uVar15) / 0xff;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar10 = (ulonglong)uVar16;

            *puVar20 = (((*puVar20 >> 0x18) << 8 | uVar13) << 8 | uVar18) << 8 | uVar16;

            puVar20 = puVar20 + iVar19;

            uVar7 = uVar7 - 1;

          } while (uVar7 != 0);

        }

        break;

      case 0xf:

        uVar11 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar10 = uVar11 & 0xffffffff;

        iVar8 = (int)uVar11;

        if ((int)param_5 < param_3) {

          uVar10 = (ulonglong)param_4;

          puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(int)(iVar8 * param_5) + uVar10) * 4);

          iVar19 = 1;

          if (param_2 < param_4) {

            iVar19 = -1;

          }

          iVar19 = iVar19 + iVar8;

          if (param_11 == 0) {

            uVar10 = (ulonglong)iVar19;

            puVar20 = puVar20 + uVar10;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          puVar20 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar8 * param_3 + lVar14) * 4);

          iVar19 = 1;

          if (param_4 < param_2) {

            iVar19 = -1;

          }

          iVar19 = iVar19 + iVar8;

        }

        uVar13 = uVar16 + 1;

        if (param_11 == 0) {

          uVar13 = uVar16;

        }

        if (uVar13 != 0) {

          do {

            uVar18 = *puVar20;

            uVar16 = ((uVar18 >> 0x10 & 0xff) * uVar23) / 0xff + uVar21;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar6 = (*(byte *)((longlong)puVar20 + 1) * uVar23) / 0xff + uVar22;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar9 = ((uVar18 & 0xff) * uVar23) / 0xff + uVar15;

            if (0xff < uVar9) {

              uVar9 = 0xff;

            }

            uVar18 = ((uVar18 >> 0x18) * uVar23) / 0xff + uVar7;

            if (0xff < uVar18) {

              uVar18 = 0xff;

            }

            uVar9 = ((uVar18 << 8 | uVar16) << 8 | uVar6) << 8 | uVar9;

            uVar10 = (ulonglong)uVar9;

            *puVar20 = uVar9;

            puVar20 = puVar20 + iVar19;

            uVar13 = uVar13 - 1;

          } while (uVar13 != 0);

        }

      }

    }

    else {

      switch(iVar19) {

      case 0:

        uVar13 = -(param_4 - param_2);

        if ((int)uVar13 < 0) {

          uVar13 = param_4 - param_2;

        }

        param_6 = -(param_5 - param_3);

        if ((int)param_6 < 0) {

          param_6 = param_5 - param_3;

        }

        bVar2 = (int)uVar13 < (int)param_6;

        if (bVar2) {

          local_res18 = uVar13 * 2;

          param_5 = local_res18 - param_6;

          iVar19 = uVar13 - param_6;

        }

        else {

          local_res18 = param_6 * 2;

          param_5 = local_res18 - uVar13;

          iVar19 = param_6 - uVar13;

          param_6 = uVar13;

        }

        uVar13 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar13 = (uint)!bVar2;

        }

        uVar16 = -(uint)bVar2;

        if (param_3 <= iVar8) {

          uVar16 = (uint)bVar2;

        }

        uVar18 = 0xffffffff;

        if (param_3 <= iVar8) {

          uVar18 = 1;

        }

        uVar10 = (ulonglong)param_6;

        uVar6 = param_6 + 1;

        if (param_11 == 0) {

          uVar6 = param_6;

        }

        if (0 < (int)uVar6) {

          lVar14 = lVar14 * 4;

          lVar12 = -4;

          if (param_2 <= param_4) {

            lVar12 = 4;

          }

          local_40 = (ulonglong)uVar6;

          do {

            puVar20 = (uint *)(param_3 * *(int *)(param_1 + 0x10) + lVar14 +

                              *(longlong *)(param_1 + 0x18));

            uVar6 = *puVar20;

            *puVar20 = (((uVar6 >> 8 & 0xff) * uVar23) / 0xff + uVar22) * 0x100 |

                       (((uVar6 >> 0x10 & 0xff) * uVar23) / 0xff + uVar21) * 0x10000 |

                       (((uVar6 >> 0x18) * uVar23) / 0xff + uVar7) * 0x1000000 |

                       ((uVar6 & 0xff) * uVar23) / 0xff + uVar15;

            lVar3 = lVar12;

            uVar6 = uVar18;

            iVar8 = iVar19 * 2;

            if ((int)param_5 < 0) {

              lVar3 = (longlong)(int)uVar13 * 4;

              uVar6 = uVar16;

              iVar8 = local_res18;

            }

            param_5 = param_5 + iVar8;

            param_3 = param_3 + uVar6;

            uVar10 = (ulonglong)param_5;

            lVar14 = lVar14 + lVar3;

            local_40 = local_40 - 1;

          } while (local_40 != 0);

        }

        break;

      case 1:

      case 0x1f:

        uVar7 = -(param_4 - param_2);

        if ((int)uVar7 < 0) {

          uVar7 = param_4 - param_2;

        }

        uVar23 = -(param_5 - param_3);

        if ((int)uVar23 < 0) {

          uVar23 = param_5 - param_3;

        }

        bVar2 = (int)uVar7 < (int)uVar23;

        if (bVar2) {

          param_6 = uVar7 * 2;

          iVar19 = param_6 - uVar23;

          iVar8 = uVar7 - uVar23;

        }

        else {

          param_6 = uVar23 * 2;

          iVar19 = param_6 - uVar7;

          iVar8 = uVar23 - uVar7;

          uVar23 = uVar7;

        }

        uVar10 = (ulonglong)bVar2;

        uVar7 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar7 = (uint)!bVar2;

        }

        uVar11 = (ulonglong)-(uint)bVar2;

        if (param_3 <= (int)param_5) {

          uVar11 = uVar10;

        }

        iVar17 = -1;

        if (param_3 <= (int)param_5) {

          iVar17 = 1;

        }

        uVar13 = uVar23 + 1;

        if (param_11 == 0) {

          uVar13 = uVar23;

        }

        if (0 < (int)uVar13) {

          lVar14 = lVar14 * 4;

          lVar12 = -4;

          if (param_2 <= param_4) {

            lVar12 = 4;

          }

          local_38 = (ulonglong)uVar13;

          do {

            puVar20 = (uint *)(param_3 * *(int *)(param_1 + 0x10) + lVar14 +

                              *(longlong *)(param_1 + 0x18));

            uVar23 = *puVar20;

            uVar10 = 0xff;

            uVar13 = (uVar23 >> 0x10 & 0xff) + uVar21;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar16 = *(byte *)((longlong)puVar20 + 1) + uVar22;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar18 = (uVar23 & 0xff) + uVar15;

            if (0xff < uVar18) {

              uVar18 = 0xff;

            }

            *puVar20 = (((uVar23 >> 0x18) << 8 | uVar13) << 8 | uVar16) << 8 | uVar18;

            lVar3 = lVar12;

            iVar5 = iVar17;

            iVar4 = iVar8 * 2;

            if (iVar19 < 0) {

              lVar3 = (longlong)(int)uVar7 * 4;

              iVar5 = (int)uVar11;

              iVar4 = param_6;

            }

            iVar19 = iVar19 + iVar4;

            param_3 = param_3 + iVar5;

            lVar14 = lVar14 + lVar3;

            local_38 = local_38 - 1;

          } while (local_38 != 0);

        }

        break;

      default:

        uVar23 = -(param_4 - param_2);

        if ((int)uVar23 < 0) {

          uVar23 = param_4 - param_2;

        }

        uVar13 = param_5 - param_3;

        param_5 = -uVar13;

        if ((int)param_5 < 0) {

          param_5 = uVar13;

        }

        bVar2 = (int)uVar23 < (int)param_5;

        if (bVar2) {

          local_res18 = uVar23 * 2;

          iVar17 = local_res18 - param_5;

          iVar19 = uVar23 - param_5;

        }

        else {

          local_res18 = param_5 * 2;

          iVar17 = local_res18 - uVar23;

          iVar19 = param_5 - uVar23;

          param_5 = uVar23;

        }

        uVar23 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar23 = (uint)!bVar2;

        }

        uVar13 = -(uint)bVar2;

        if (param_3 <= iVar8) {

          uVar13 = (uint)bVar2;

        }

        uVar16 = 0xffffffff;

        if (param_3 <= iVar8) {

          uVar16 = 1;

        }

        uVar18 = param_5 + 1;

        if (param_11 == 0) {

          uVar18 = param_5;

        }

        uVar10 = (ulonglong)uVar18;

        if (0 < (int)uVar18) {

          lVar14 = lVar14 * 4;

          lVar12 = -4;

          uVar11 = (ulonglong)uVar18;

          if (param_2 <= param_4) {

            lVar12 = 4;

          }

          do {

            uVar10 = *(ulonglong *)(param_1 + 0x18);

            *(uint *)(param_3 * *(int *)(param_1 + 0x10) + lVar14 + uVar10) =

                 ((uVar7 << 8 | uVar21) << 8 | uVar22) << 8 | uVar15;

            lVar3 = lVar12;

            uVar18 = uVar16;

            iVar8 = iVar19 * 2;

            if (iVar17 < 0) {

              lVar3 = (longlong)(int)uVar23 * 4;

              uVar18 = uVar13;

              iVar8 = local_res18;

            }

            iVar17 = iVar17 + iVar8;

            param_3 = param_3 + uVar18;

            lVar14 = lVar14 + lVar3;

            uVar11 = uVar11 - 1;

          } while (uVar11 != 0);

        }

        break;

      case 3:

        uVar7 = -(param_4 - param_2);

        if ((int)uVar7 < 0) {

          uVar7 = param_4 - param_2;

        }

        uVar23 = -(param_5 - param_3);

        if ((int)uVar23 < 0) {

          uVar23 = param_5 - param_3;

        }

        bVar2 = (int)uVar7 < (int)uVar23;

        if (bVar2) {

          param_6 = uVar7 * 2;

          iVar19 = param_6 - uVar23;

          iVar8 = uVar7 - uVar23;

        }

        else {

          param_6 = uVar23 * 2;

          iVar19 = param_6 - uVar7;

          iVar8 = uVar23 - uVar7;

          uVar23 = uVar7;

        }

        uVar10 = (ulonglong)bVar2;

        uVar7 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar7 = (uint)!bVar2;

        }

        uVar11 = (ulonglong)-(uint)bVar2;

        if (param_3 <= (int)param_5) {

          uVar11 = uVar10;

        }

        iVar17 = -1;

        if (param_3 <= (int)param_5) {

          iVar17 = 1;

        }

        uVar13 = uVar23 + 1;

        if (param_11 == 0) {

          uVar13 = uVar23;

        }

        if (0 < (int)uVar13) {

          lVar14 = lVar14 * 4;

          lVar12 = -4;

          if (param_2 <= param_4) {

            lVar12 = 4;

          }

          local_38 = (ulonglong)uVar13;

          do {

            puVar20 = (uint *)(param_3 * *(int *)(param_1 + 0x10) + lVar14 +

                              *(longlong *)(param_1 + 0x18));

            uVar23 = *puVar20;

            uVar13 = (uVar23 & 0xff) * uVar15;

            uVar10 = (ulonglong)uVar13 * 0x80808081 & 0xffffffff;

            *puVar20 = (((uVar23 >> 0x10 & 0xff) * uVar21) / 0xff << 8 |

                       ((uVar23 >> 8 & 0xff) * uVar22) / 0xff) << 8 | uVar13 / 0xff |

                       uVar23 & 0xff000000;

            lVar3 = lVar12;

            iVar5 = iVar17;

            iVar4 = iVar8 * 2;

            if (iVar19 < 0) {

              lVar3 = (longlong)(int)uVar7 * 4;

              iVar5 = (int)uVar11;

              iVar4 = param_6;

            }

            iVar19 = iVar19 + iVar4;

            param_3 = param_3 + iVar5;

            lVar14 = lVar14 + lVar3;

            local_38 = local_38 - 1;

          } while (local_38 != 0);

        }

        break;

      case 7:

        uVar7 = -(param_4 - param_2);

        if ((int)uVar7 < 0) {

          uVar7 = param_4 - param_2;

        }

        uVar13 = -(param_5 - param_3);

        if ((int)uVar13 < 0) {

          uVar13 = param_5 - param_3;

        }

        bVar2 = (int)uVar7 < (int)uVar13;

        if (bVar2) {

          local_58 = uVar7 * 2;

          param_6 = local_58 - uVar13;

          iVar8 = uVar7 - uVar13;

        }

        else {

          local_58 = uVar13 * 2;

          param_6 = local_58 - uVar7;

          iVar8 = uVar13 - uVar7;

          uVar13 = uVar7;

        }

        uVar10 = (ulonglong)bVar2;

        uVar7 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar7 = (uint)!bVar2;

        }

        uVar11 = (ulonglong)-(uint)bVar2;

        if (param_3 <= (int)param_5) {

          uVar11 = uVar10;

        }

        iVar19 = -1;

        if (param_3 <= (int)param_5) {

          iVar19 = 1;

        }

        uVar16 = uVar13 + 1;

        if (param_11 == 0) {

          uVar16 = uVar13;

        }

        if (0 < (int)uVar16) {

          lVar14 = lVar14 * 4;

          lVar12 = -4;

          if (param_2 <= param_4) {

            lVar12 = 4;

          }

          local_38 = (ulonglong)uVar16;

          do {

            puVar20 = (uint *)(param_3 * *(int *)(param_1 + 0x10) + lVar14 +

                              *(longlong *)(param_1 + 0x18));

            uVar16 = *puVar20 & 0xff;

            uVar13 = (*(byte *)((longlong)puVar20 + 2) * uVar23) / 0xff +

                     (*(byte *)((longlong)puVar20 + 2) * uVar21) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar18 = (*(byte *)((longlong)puVar20 + 1) * uVar23) / 0xff +

                     (*(byte *)((longlong)puVar20 + 1) * uVar22) / 0xff;

            if (0xff < uVar18) {

              uVar18 = 0xff;

            }

            uVar16 = (uVar16 * uVar23) / 0xff + (uVar16 * uVar15) / 0xff;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            *puVar20 = (((*puVar20 >> 0x18) << 8 | uVar13) << 8 | uVar18) << 8 | uVar16;

            lVar3 = lVar12;

            local_50 = iVar19;

            iVar17 = iVar8 * 2;

            if ((int)param_6 < 0) {

              local_50 = (int)uVar11;

              lVar3 = (longlong)(int)uVar7 * 4;

              iVar17 = local_58;

            }

            param_6 = param_6 + iVar17;

            param_3 = param_3 + local_50;

            uVar10 = (ulonglong)param_6;

            lVar14 = lVar14 + lVar3;

            local_38 = local_38 - 1;

          } while (local_38 != 0);

        }

        break;

      case 0xf:

        uVar13 = -(param_4 - param_2);

        if ((int)uVar13 < 0) {

          uVar13 = param_4 - param_2;

        }

        uVar16 = -(param_5 - param_3);

        if ((int)uVar16 < 0) {

          uVar16 = param_5 - param_3;

        }

        bVar2 = (int)uVar13 < (int)uVar16;

        if (bVar2) {

          local_58 = uVar13 * 2;

          param_6 = local_58 - uVar16;

          iVar8 = uVar13 - uVar16;

        }

        else {

          local_58 = uVar16 * 2;

          param_6 = local_58 - uVar13;

          iVar8 = uVar16 - uVar13;

          uVar16 = uVar13;

        }

        uVar10 = (ulonglong)bVar2;

        uVar13 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar13 = (uint)!bVar2;

        }

        uVar11 = (ulonglong)-(uint)bVar2;

        if (param_3 <= (int)param_5) {

          uVar11 = uVar10;

        }

        iVar19 = -1;

        if (param_3 <= (int)param_5) {

          iVar19 = 1;

        }

        uVar18 = uVar16 + 1;

        if (param_11 == 0) {

          uVar18 = uVar16;

        }

        if (0 < (int)uVar18) {

          lVar14 = lVar14 * 4;

          lVar12 = -4;

          if (param_2 <= param_4) {

            lVar12 = 4;

          }

          local_38 = (ulonglong)uVar18;

          do {

            puVar20 = (uint *)(param_3 * *(int *)(param_1 + 0x10) + lVar14 +

                              *(longlong *)(param_1 + 0x18));

            uVar18 = *puVar20;

            uVar16 = ((uVar18 >> 0x10 & 0xff) * uVar23) / 0xff + uVar21;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar6 = (*(byte *)((longlong)puVar20 + 1) * uVar23) / 0xff + uVar22;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar9 = uVar15 + ((uVar18 & 0xff) * uVar23) / 0xff;

            if (0xff < uVar9) {

              uVar9 = 0xff;

            }

            uVar18 = ((uVar18 >> 0x18) * uVar23) / 0xff + uVar7;

            if (0xff < uVar18) {

              uVar18 = 0xff;

            }

            *puVar20 = ((uVar18 << 8 | uVar16) << 8 | uVar6) << 8 | uVar9;

            lVar3 = lVar12;

            iVar4 = iVar19;

            iVar17 = iVar8 * 2;

            if ((int)param_6 < 0) {

              lVar3 = (longlong)(int)uVar13 * 4;

              iVar4 = (int)uVar11;

              iVar17 = local_58;

            }

            param_6 = param_6 + iVar17;

            param_3 = param_3 + iVar4;

            uVar10 = (ulonglong)param_6;

            lVar14 = lVar14 + lVar3;

            local_38 = local_38 - 1;

          } while (local_38 != 0);

        }

      }

    }

  }

  return uVar10;

}




