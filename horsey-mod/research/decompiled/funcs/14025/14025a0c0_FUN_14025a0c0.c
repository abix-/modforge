// Address: 0x14025a0c0
// Ghidra name: FUN_14025a0c0
// ============ 0x14025a0c0 FUN_14025a0c0 (size=6975) ============


ulonglong FUN_14025a0c0(longlong param_1,int param_2,int param_3,int param_4,uint param_5,

                       int param_6,byte param_7,byte param_8,byte param_9,byte param_10,

                       byte param_11)



{

  uint *puVar1;

  bool bVar2;

  longlong lVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  int iVar9;

  longlong lVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  int iVar15;

  int iVar16;

  uint *puVar17;

  uint uVar18;

  longlong lVar19;

  ulonglong uVar20;

  uint uVar21;

  uint uVar22;

  int local_res18;

  ulonglong local_50;

  ulonglong local_48;

  

  iVar6 = param_5;

  lVar19 = (longlong)param_2;

  if (param_6 - 1U < 2) {

    uVar11 = ((uint)param_7 * (uint)param_10) / 0xff;

    uVar21 = ((uint)param_8 * (uint)param_10) / 0xff;

    uVar12 = ((uint)param_9 * (uint)param_10) / 0xff;

  }

  else {

    uVar11 = (uint)param_7;

    uVar21 = (uint)param_8;

    uVar12 = (uint)param_9;

  }

  uVar22 = param_10 ^ 0xff;

  param_6 = param_6 + -1;

  uVar18 = 0xff;

  if (param_3 == param_5) {

    switch(param_6) {

    case 0:

      uVar18 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar7 = (ulonglong)uVar18;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar18) * 4);

        uVar7 = (ulonglong)param_11;

        puVar17 = puVar1 + 1;

        if (param_11 != 0) {

          puVar17 = puVar1;

        }

        iVar6 = param_2 - param_4;

        if (param_11 != 0) {

          iVar6 = iVar6 + 1;

        }

      }

      else {

        iVar6 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar6 = param_4 - param_2;

        }

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar18 + lVar19) * 4);

      }

      for (; iVar6 != 0; iVar6 = iVar6 + -1) {

        uVar18 = *puVar17;

        uVar14 = (uVar18 & 0xff) * uVar22;

        uVar7 = (ulonglong)uVar14 * 0x80808081 & 0xffffffff;

        *puVar17 = (((uVar18 >> 8 & 0xff) * uVar22) / 0xff + uVar21) * 0x100 |

                   (((uVar18 >> 0x10 & 0xff) * uVar22) / 0xff + uVar11) * 0x10000 |

                   uVar14 / 0xff + uVar12;

        puVar17 = puVar17 + 1;

      }

      break;

    case 1:

    case 0x1f:

      uVar22 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar7 = (ulonglong)uVar22;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar22) * 4);

        uVar7 = (ulonglong)param_11;

        puVar17 = puVar1 + 1;

        if (param_11 != 0) {

          puVar17 = puVar1;

        }

        iVar6 = param_2 - param_4;

        if (param_11 != 0) {

          iVar6 = iVar6 + 1;

        }

      }

      else {

        iVar6 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar6 = param_4 - param_2;

        }

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar22 + lVar19) * 4);

      }

      for (; iVar6 != 0; iVar6 = iVar6 + -1) {

        uVar22 = *puVar17 >> 0x10;

        uVar7 = (ulonglong)uVar22;

        uVar22 = (uVar22 & 0xff) + uVar11;

        if (0xff < uVar22) {

          uVar22 = uVar18;

        }

        uVar14 = *(byte *)((longlong)puVar17 + 1) + uVar21;

        if (0xff < uVar14) {

          uVar14 = uVar18;

        }

        uVar13 = (*puVar17 & 0xff) + uVar12;

        if (0xff < uVar13) {

          uVar13 = 0xff;

        }

        *puVar17 = (uVar22 << 8 | uVar14) << 8 | uVar13;

        puVar17 = puVar17 + 1;

      }

      break;

    default:

      uVar22 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar7 = (ulonglong)uVar22;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar22) * 4);

        uVar7 = (ulonglong)param_11;

        puVar17 = puVar1 + 1;

        if (param_11 != 0) {

          puVar17 = puVar1;

        }

        uVar18 = param_2 - param_4;

        if (param_11 != 0) {

          uVar18 = uVar18 + 1;

        }

      }

      else {

        uVar18 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          uVar18 = param_4 - param_2;

        }

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar22 + lVar19) * 4);

      }

      if (uVar18 != 0) {

        uVar12 = (uVar11 << 8 | uVar21) << 8 | uVar12;

        uVar7 = (ulonglong)uVar12;

        for (uVar8 = (ulonglong)uVar18; uVar8 != 0; uVar8 = uVar8 - 1) {

          *puVar17 = uVar12;

          puVar17 = puVar17 + 1;

        }

      }

      break;

    case 3:

      uVar22 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar7 = (ulonglong)uVar22;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar22) * 4);

        uVar7 = (ulonglong)param_11;

        puVar17 = puVar1 + 1;

        if (param_11 != 0) {

          puVar17 = puVar1;

        }

        iVar6 = param_2 - param_4;

        if (param_11 != 0) {

          iVar6 = iVar6 + 1;

        }

      }

      else {

        iVar6 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar6 = param_4 - param_2;

        }

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar22 + lVar19) * 4);

      }

      for (; iVar6 != 0; iVar6 = iVar6 + -1) {

        uVar22 = *puVar17;

        uVar18 = (uVar22 & 0xff) * uVar12;

        uVar7 = (ulonglong)uVar18 * 0x80808081 & 0xffffffff;

        *puVar17 = (((uVar22 >> 0x10 & 0xff) * uVar11) / 0xff << 8 |

                   ((uVar22 >> 8 & 0xff) * uVar21) / 0xff) << 8 | uVar18 / 0xff;

        puVar17 = puVar17 + 1;

      }

      break;

    case 7:

      uVar14 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar7 = (ulonglong)uVar14;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar14) * 4);

        uVar7 = (ulonglong)param_11;

        puVar17 = puVar1 + 1;

        if (param_11 != 0) {

          puVar17 = puVar1;

        }

        iVar6 = param_2 - param_4;

        if (param_11 != 0) {

          iVar6 = iVar6 + 1;

        }

      }

      else {

        iVar6 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar6 = param_4 - param_2;

        }

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar14 + lVar19) * 4);

      }

      for (; iVar6 != 0; iVar6 = iVar6 + -1) {

        uVar14 = (*(byte *)((longlong)puVar17 + 2) * uVar22) / 0xff +

                 (*(byte *)((longlong)puVar17 + 2) * uVar11) / 0xff;

        if (0xff < uVar14) {

          uVar14 = uVar18;

        }

        uVar13 = (*(byte *)((longlong)puVar17 + 1) * uVar22) / 0xff +

                 (*(byte *)((longlong)puVar17 + 1) * uVar21) / 0xff;

        if (0xff < uVar13) {

          uVar13 = uVar18;

        }

        uVar5 = ((byte)*puVar17 * uVar22) / 0xff + ((byte)*puVar17 * uVar12) / 0xff;

        if (0xff < uVar5) {

          uVar5 = 0xff;

        }

        uVar7 = (ulonglong)uVar5;

        *puVar17 = (uVar14 << 8 | uVar13) << 8 | uVar5;

        puVar17 = puVar17 + 1;

      }

      break;

    case 0xf:

      uVar18 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar7 = (ulonglong)uVar18;

      if (param_4 < param_2) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x18) +

                         ((longlong)param_4 + (longlong)(int)uVar18) * 4);

        uVar7 = (ulonglong)param_11;

        puVar17 = puVar1 + 1;

        if (param_11 != 0) {

          puVar17 = puVar1;

        }

        iVar6 = param_2 - param_4;

        if (param_11 != 0) {

          iVar6 = iVar6 + 1;

        }

      }

      else {

        iVar6 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar6 = param_4 - param_2;

        }

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + ((int)uVar18 + lVar19) * 4);

      }

      for (; iVar6 != 0; iVar6 = iVar6 + -1) {

        uVar18 = ((*puVar17 >> 0x10 & 0xff) * uVar22) / 0xff + uVar11;

        if (0xff < uVar18) {

          uVar18 = 0xff;

        }

        uVar14 = (*(byte *)((longlong)puVar17 + 1) * uVar22) / 0xff + uVar21;

        if (0xff < uVar14) {

          uVar14 = 0xff;

        }

        uVar13 = ((*puVar17 & 0xff) * uVar22) / 0xff + uVar12;

        uVar7 = (ulonglong)uVar13;

        if (0xff < uVar13) {

          uVar7 = 0xff;

        }

        *puVar17 = (uVar18 << 8 | uVar14) << 8 | (uint)uVar7;

        puVar17 = puVar17 + 1;

      }

    }

  }

  else if (param_2 == param_4) {

    switch(param_6) {

    case 0:

      iVar6 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar16 = param_3 - param_5;

        uVar7 = (int)(iVar6 * param_5) + lVar19;

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar7 * 4);

        if (param_11 == 0) {

          puVar17 = puVar17 + iVar6;

        }

        else {

          iVar16 = iVar16 + 1;

        }

      }

      else {

        uVar7 = iVar6 * param_3 + lVar19;

        iVar16 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar16 = param_5 - param_3;

        }

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar7 * 4);

      }

      for (; iVar16 != 0; iVar16 = iVar16 + -1) {

        uVar18 = *puVar17;

        uVar14 = (uVar18 & 0xff) * uVar22;

        uVar7 = (ulonglong)uVar14 * 0x80808081 & 0xffffffff;

        *puVar17 = (((uVar18 >> 8 & 0xff) * uVar22) / 0xff + uVar21) * 0x100 |

                   (((uVar18 >> 0x10 & 0xff) * uVar22) / 0xff + uVar11) * 0x10000 |

                   uVar14 / 0xff + uVar12;

        puVar17 = puVar17 + iVar6;

      }

      break;

    case 1:

    case 0x1f:

      iVar6 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar16 = param_3 - param_5;

        uVar7 = (int)(iVar6 * param_5) + lVar19;

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar7 * 4);

        if (param_11 == 0) {

          puVar17 = puVar17 + iVar6;

        }

        else {

          iVar16 = iVar16 + 1;

        }

      }

      else {

        uVar7 = iVar6 * param_3 + lVar19;

        iVar16 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar16 = param_5 - param_3;

        }

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar7 * 4);

      }

      for (; iVar16 != 0; iVar16 = iVar16 + -1) {

        uVar22 = *puVar17 >> 0x10;

        uVar7 = (ulonglong)uVar22;

        uVar22 = (uVar22 & 0xff) + uVar11;

        if (0xff < uVar22) {

          uVar22 = uVar18;

        }

        uVar14 = *(byte *)((longlong)puVar17 + 1) + uVar21;

        if (0xff < uVar14) {

          uVar14 = uVar18;

        }

        uVar13 = (*puVar17 & 0xff) + uVar12;

        if (0xff < uVar13) {

          uVar13 = 0xff;

        }

        *puVar17 = (uVar22 << 8 | uVar14) << 8 | uVar13;

        puVar17 = puVar17 + iVar6;

      }

      break;

    default:

      iVar6 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar16 = param_3 - param_5;

        uVar7 = (int)(iVar6 * param_5) + lVar19;

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar7 * 4);

        if (param_11 == 0) {

          puVar17 = puVar17 + iVar6;

        }

        else {

          iVar16 = iVar16 + 1;

        }

      }

      else {

        uVar7 = iVar6 * param_3 + lVar19;

        iVar16 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar16 = param_5 - param_3;

        }

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar7 * 4);

      }

      if (iVar16 != 0) {

        do {

          *puVar17 = (uVar11 << 8 | uVar21) << 8 | uVar12;

          puVar17 = puVar17 + iVar6;

          iVar16 = iVar16 + -1;

        } while (iVar16 != 0);

      }

      break;

    case 3:

      iVar6 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar16 = param_3 - param_5;

        uVar7 = (int)(iVar6 * param_5) + lVar19;

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar7 * 4);

        if (param_11 == 0) {

          puVar17 = puVar17 + iVar6;

        }

        else {

          iVar16 = iVar16 + 1;

        }

      }

      else {

        uVar7 = iVar6 * param_3 + lVar19;

        iVar16 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar16 = param_5 - param_3;

        }

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar7 * 4);

      }

      for (; iVar16 != 0; iVar16 = iVar16 + -1) {

        uVar22 = *puVar17;

        uVar18 = (uVar22 & 0xff) * uVar12;

        uVar7 = (ulonglong)uVar18 * 0x80808081 & 0xffffffff;

        *puVar17 = (((uVar22 >> 0x10 & 0xff) * uVar11) / 0xff << 8 |

                   ((uVar22 >> 8 & 0xff) * uVar21) / 0xff) << 8 | uVar18 / 0xff;

        puVar17 = puVar17 + iVar6;

      }

      break;

    case 7:

      iVar6 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar16 = param_3 - param_5;

        uVar7 = (int)(iVar6 * param_5) + lVar19;

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar7 * 4);

        if (param_11 == 0) {

          puVar17 = puVar17 + iVar6;

        }

        else {

          iVar16 = iVar16 + 1;

        }

      }

      else {

        uVar7 = iVar6 * param_3 + lVar19;

        iVar16 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar16 = param_5 - param_3;

        }

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar7 * 4);

      }

      for (; iVar16 != 0; iVar16 = iVar16 + -1) {

        uVar14 = (*(byte *)((longlong)puVar17 + 2) * uVar22) / 0xff +

                 (*(byte *)((longlong)puVar17 + 2) * uVar11) / 0xff;

        if (0xff < uVar14) {

          uVar14 = uVar18;

        }

        uVar13 = (*(byte *)((longlong)puVar17 + 1) * uVar22) / 0xff +

                 (*(byte *)((longlong)puVar17 + 1) * uVar21) / 0xff;

        if (0xff < uVar13) {

          uVar13 = uVar18;

        }

        uVar5 = ((byte)*puVar17 * uVar22) / 0xff + ((byte)*puVar17 * uVar12) / 0xff;

        if (0xff < uVar5) {

          uVar5 = 0xff;

        }

        uVar7 = (ulonglong)uVar5;

        *puVar17 = (uVar14 << 8 | uVar13) << 8 | uVar5;

        puVar17 = puVar17 + iVar6;

      }

      break;

    case 0xf:

      iVar6 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar16 = param_3 - param_5;

        uVar7 = (int)(iVar6 * param_5) + lVar19;

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar7 * 4);

        if (param_11 == 0) {

          puVar17 = puVar17 + iVar6;

        }

        else {

          iVar16 = iVar16 + 1;

        }

      }

      else {

        uVar7 = iVar6 * param_3 + lVar19;

        iVar16 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar16 = param_5 - param_3;

        }

        puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + uVar7 * 4);

      }

      for (; iVar16 != 0; iVar16 = iVar16 + -1) {

        uVar18 = ((*puVar17 >> 0x10 & 0xff) * uVar22) / 0xff + uVar11;

        if (0xff < uVar18) {

          uVar18 = 0xff;

        }

        uVar14 = (*(byte *)((longlong)puVar17 + 1) * uVar22) / 0xff + uVar21;

        if (0xff < uVar14) {

          uVar14 = 0xff;

        }

        uVar13 = ((*puVar17 & 0xff) * uVar22) / 0xff + uVar12;

        uVar7 = (ulonglong)uVar13;

        if (0xff < uVar13) {

          uVar7 = 0xff;

        }

        *puVar17 = (uVar18 << 8 | uVar14) << 8 | (uint)uVar7;

        puVar17 = puVar17 + iVar6;

      }

    }

  }

  else {

    uVar14 = param_3 - param_5;

    uVar18 = -(param_2 - param_4);

    if ((int)uVar18 < 0) {

      uVar18 = param_2 - param_4;

    }

    uVar13 = -uVar14;

    if ((int)-uVar14 < 0) {

      uVar13 = uVar14;

    }

    if (uVar18 == uVar13) {

      switch(param_6) {

      case 0:

        uVar8 = (longlong)*(int *)(param_1 + 0x10) /

                (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar7 = uVar8 & 0xffffffff;

        iVar6 = (int)uVar8;

        if ((int)param_5 < param_3) {

          uVar7 = (ulonglong)param_4;

          puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(int)(iVar6 * param_5) + uVar7) * 4);

          iVar16 = 1;

          if (param_2 < param_4) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar6;

          if (param_11 == 0) {

            uVar7 = (ulonglong)iVar16;

            puVar17 = puVar17 + uVar7;

          }

        }

        else {

          uVar14 = param_5 - param_3;

          iVar16 = 1;

          if (param_4 < param_2) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar6;

          puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar6 * param_3 + lVar19) * 4);

        }

        uVar18 = uVar14 + 1;

        if (param_11 == 0) {

          uVar18 = uVar14;

        }

        if (uVar18 != 0) {

          do {

            uVar14 = *puVar17;

            uVar13 = (uVar14 & 0xff) * uVar22;

            uVar7 = (ulonglong)uVar13 * 0x80808081 & 0xffffffff;

            *puVar17 = (((uVar14 >> 8 & 0xff) * uVar22) / 0xff + uVar21) * 0x100 |

                       (((uVar14 >> 0x10 & 0xff) * uVar22) / 0xff + uVar11) * 0x10000 |

                       uVar13 / 0xff + uVar12;

            puVar17 = puVar17 + iVar16;

            uVar18 = uVar18 - 1;

          } while (uVar18 != 0);

        }

        break;

      case 1:

      case 0x1f:

        uVar8 = (longlong)*(int *)(param_1 + 0x10) /

                (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar7 = uVar8 & 0xffffffff;

        iVar6 = (int)uVar8;

        if ((int)param_5 < param_3) {

          uVar7 = (ulonglong)param_4;

          puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(int)(iVar6 * param_5) + uVar7) * 4);

          iVar16 = 1;

          if (param_2 < param_4) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar6;

          if (param_11 == 0) {

            uVar7 = (ulonglong)iVar16;

            puVar17 = puVar17 + uVar7;

          }

        }

        else {

          uVar14 = param_5 - param_3;

          iVar16 = 1;

          if (param_4 < param_2) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar6;

          puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar6 * param_3 + lVar19) * 4);

        }

        uVar22 = uVar14 + 1;

        if (param_11 == 0) {

          uVar22 = uVar14;

        }

        if (uVar22 != 0) {

          do {

            uVar7 = 0xff;

            uVar18 = (*puVar17 >> 0x10 & 0xff) + uVar11;

            if (0xff < uVar18) {

              uVar18 = 0xff;

            }

            uVar14 = *(byte *)((longlong)puVar17 + 1) + uVar21;

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

            uVar13 = (*puVar17 & 0xff) + uVar12;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            *puVar17 = (uVar18 << 8 | uVar14) << 8 | uVar13;

            puVar17 = puVar17 + iVar16;

            uVar22 = uVar22 - 1;

          } while (uVar22 != 0);

        }

        break;

      default:

        iVar6 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        if ((int)param_5 < param_3) {

          puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(int)(iVar6 * param_5) + (longlong)param_4) * 4);

          iVar16 = 1;

          if (param_2 < param_4) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar6;

          if (param_11 == 0) {

            puVar17 = puVar17 + iVar16;

          }

        }

        else {

          uVar14 = param_5 - param_3;

          iVar16 = 1;

          if (param_4 < param_2) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar6;

          puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar6 * param_3 + lVar19) * 4);

        }

        uVar22 = uVar14 + 1;

        if (param_11 == 0) {

          uVar22 = uVar14;

        }

        uVar7 = (ulonglong)uVar22;

        if (uVar22 != 0) {

          do {

            *puVar17 = (uVar11 << 8 | uVar21) << 8 | uVar12;

            puVar17 = puVar17 + iVar16;

            uVar22 = (int)uVar7 - 1;

            uVar7 = (ulonglong)uVar22;

          } while (uVar22 != 0);

          uVar7 = 0;

        }

        break;

      case 3:

        uVar8 = (longlong)*(int *)(param_1 + 0x10) /

                (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar7 = uVar8 & 0xffffffff;

        iVar6 = (int)uVar8;

        if ((int)param_5 < param_3) {

          uVar7 = (ulonglong)param_4;

          puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(int)(iVar6 * param_5) + uVar7) * 4);

          iVar16 = 1;

          if (param_2 < param_4) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar6;

          if (param_11 == 0) {

            uVar7 = (ulonglong)iVar16;

            puVar17 = puVar17 + uVar7;

          }

        }

        else {

          uVar14 = param_5 - param_3;

          iVar16 = 1;

          if (param_4 < param_2) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar6;

          puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar6 * param_3 + lVar19) * 4);

        }

        uVar22 = uVar14 + 1;

        if (param_11 == 0) {

          uVar22 = uVar14;

        }

        if (uVar22 != 0) {

          do {

            uVar18 = *puVar17;

            uVar14 = (uVar18 & 0xff) * uVar12;

            uVar7 = (ulonglong)uVar14 * 0x80808081 & 0xffffffff;

            *puVar17 = (((uVar18 >> 0x10 & 0xff) * uVar11) / 0xff << 8 |

                       ((uVar18 >> 8 & 0xff) * uVar21) / 0xff) << 8 | uVar14 / 0xff;

            puVar17 = puVar17 + iVar16;

            uVar22 = uVar22 - 1;

          } while (uVar22 != 0);

        }

        break;

      case 7:

        uVar8 = (longlong)*(int *)(param_1 + 0x10) /

                (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar7 = uVar8 & 0xffffffff;

        iVar6 = (int)uVar8;

        if ((int)param_5 < param_3) {

          uVar7 = (ulonglong)param_4;

          puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(int)(iVar6 * param_5) + uVar7) * 4);

          iVar16 = 1;

          if (param_2 < param_4) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar6;

          if (param_11 == 0) {

            uVar7 = (ulonglong)iVar16;

            puVar17 = puVar17 + uVar7;

          }

        }

        else {

          uVar14 = param_5 - param_3;

          iVar16 = 1;

          if (param_4 < param_2) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar6;

          puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar6 * param_3 + lVar19) * 4);

        }

        uVar18 = uVar14 + 1;

        if (param_11 == 0) {

          uVar18 = uVar14;

        }

        if (uVar18 != 0) {

          do {

            uVar14 = (*(byte *)((longlong)puVar17 + 2) * uVar22) / 0xff +

                     (*(byte *)((longlong)puVar17 + 2) * uVar11) / 0xff;

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

            uVar13 = (*(byte *)((longlong)puVar17 + 1) * uVar22) / 0xff +

                     (*(byte *)((longlong)puVar17 + 1) * uVar21) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar5 = ((byte)*puVar17 * uVar22) / 0xff + ((byte)*puVar17 * uVar12) / 0xff;

            if (0xff < uVar5) {

              uVar5 = 0xff;

            }

            uVar7 = (ulonglong)uVar5;

            *puVar17 = (uVar14 << 8 | uVar13) << 8 | uVar5;

            puVar17 = puVar17 + iVar16;

            uVar18 = uVar18 - 1;

          } while (uVar18 != 0);

        }

        break;

      case 0xf:

        uVar8 = (longlong)*(int *)(param_1 + 0x10) /

                (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar7 = uVar8 & 0xffffffff;

        iVar6 = (int)uVar8;

        if ((int)param_5 < param_3) {

          uVar7 = (ulonglong)param_4;

          puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) +

                            ((longlong)(int)(iVar6 * param_5) + uVar7) * 4);

          iVar16 = 1;

          if (param_2 < param_4) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar6;

          if (param_11 == 0) {

            uVar7 = (ulonglong)iVar16;

            puVar17 = puVar17 + uVar7;

          }

        }

        else {

          uVar14 = param_5 - param_3;

          iVar16 = 1;

          if (param_4 < param_2) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar6;

          puVar17 = (uint *)(*(longlong *)(param_1 + 0x18) + (iVar6 * param_3 + lVar19) * 4);

        }

        uVar18 = uVar14 + 1;

        if (param_11 == 0) {

          uVar18 = uVar14;

        }

        if (uVar18 != 0) {

          do {

            uVar14 = ((*puVar17 >> 0x10 & 0xff) * uVar22) / 0xff + uVar11;

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

            uVar13 = (*(byte *)((longlong)puVar17 + 1) * uVar22) / 0xff + uVar21;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar5 = ((*puVar17 & 0xff) * uVar22) / 0xff + uVar12;

            uVar7 = (ulonglong)uVar5;

            if (0xff < uVar5) {

              uVar7 = 0xff;

            }

            *puVar17 = (uVar14 << 8 | uVar13) << 8 | (uint)uVar7;

            puVar17 = puVar17 + iVar16;

            uVar18 = uVar18 - 1;

          } while (uVar18 != 0);

        }

      }

    }

    else {

      switch(param_6) {

      case 0:

        uVar18 = -(param_4 - param_2);

        if ((int)uVar18 < 0) {

          uVar18 = param_4 - param_2;

        }

        uVar14 = -(param_5 - param_3);

        if ((int)uVar14 < 0) {

          uVar14 = param_5 - param_3;

        }

        bVar2 = (int)uVar18 < (int)uVar14;

        if (bVar2) {

          local_res18 = uVar18 * 2;

          param_5 = local_res18 - uVar14;

          iVar16 = uVar18 - uVar14;

        }

        else {

          local_res18 = uVar14 * 2;

          param_5 = local_res18 - uVar18;

          iVar16 = uVar14 - uVar18;

          uVar14 = uVar18;

        }

        uVar7 = (ulonglong)bVar2;

        uVar18 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar18 = (uint)!bVar2;

        }

        uVar8 = (ulonglong)-(uint)bVar2;

        if (param_3 <= iVar6) {

          uVar8 = uVar7;

        }

        iVar9 = -1;

        if (param_3 <= iVar6) {

          iVar9 = 1;

        }

        uVar13 = uVar14 + 1;

        if (param_11 == 0) {

          uVar13 = uVar14;

        }

        if (0 < (int)uVar13) {

          lVar19 = lVar19 * 4;

          lVar10 = -4;

          if (param_2 <= param_4) {

            lVar10 = 4;

          }

          local_50 = (ulonglong)uVar13;

          do {

            puVar17 = (uint *)(param_3 * *(int *)(param_1 + 0x10) + lVar19 +

                              *(longlong *)(param_1 + 0x18));

            uVar14 = *puVar17;

            *puVar17 = (((uVar14 >> 8 & 0xff) * uVar22) / 0xff + uVar21) * 0x100 |

                       (((uVar14 >> 0x10 & 0xff) * uVar22) / 0xff + uVar11) * 0x10000 |

                       ((uVar14 & 0xff) * uVar22) / 0xff + uVar12;

            lVar3 = lVar10;

            iVar15 = iVar9;

            iVar6 = iVar16 * 2;

            if ((int)param_5 < 0) {

              lVar3 = (longlong)(int)uVar18 * 4;

              iVar15 = (int)uVar8;

              iVar6 = local_res18;

            }

            param_5 = param_5 + iVar6;

            param_3 = param_3 + iVar15;

            uVar7 = (ulonglong)param_5;

            lVar19 = lVar19 + lVar3;

            local_50 = local_50 - 1;

          } while (local_50 != 0);

        }

        break;

      case 1:

      case 0x1f:

        uVar22 = -(param_4 - param_2);

        if ((int)uVar22 < 0) {

          uVar22 = param_4 - param_2;

        }

        uVar18 = -(param_5 - param_3);

        if ((int)uVar18 < 0) {

          uVar18 = param_5 - param_3;

        }

        bVar2 = (int)uVar22 < (int)uVar18;

        if (bVar2) {

          param_6 = uVar22 * 2;

          iVar16 = param_6 - uVar18;

          iVar6 = uVar22 - uVar18;

        }

        else {

          param_6 = uVar18 * 2;

          iVar16 = param_6 - uVar22;

          iVar6 = uVar18 - uVar22;

          uVar18 = uVar22;

        }

        uVar7 = (ulonglong)bVar2;

        uVar22 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar22 = (uint)!bVar2;

        }

        uVar8 = (ulonglong)-(uint)bVar2;

        if (param_3 <= (int)param_5) {

          uVar8 = uVar7;

        }

        iVar9 = -1;

        if (param_3 <= (int)param_5) {

          iVar9 = 1;

        }

        uVar14 = uVar18 + 1;

        if (param_11 == 0) {

          uVar14 = uVar18;

        }

        if (0 < (int)uVar14) {

          lVar19 = lVar19 * 4;

          uVar20 = (ulonglong)uVar14;

          lVar10 = -4;

          if (param_2 <= param_4) {

            lVar10 = 4;

          }

          do {

            puVar17 = (uint *)(param_3 * *(int *)(param_1 + 0x10) + lVar19 +

                              *(longlong *)(param_1 + 0x18));

            uVar7 = 0xff;

            uVar18 = (*puVar17 >> 0x10 & 0xff) + uVar11;

            if (0xff < uVar18) {

              uVar18 = 0xff;

            }

            uVar14 = *(byte *)((longlong)puVar17 + 1) + uVar21;

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

            uVar13 = (*puVar17 & 0xff) + uVar12;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            *puVar17 = (uVar18 << 8 | uVar14) << 8 | uVar13;

            lVar3 = lVar10;

            iVar4 = iVar9;

            iVar15 = iVar6 * 2;

            if (iVar16 < 0) {

              lVar3 = (longlong)(int)uVar22 * 4;

              iVar4 = (int)uVar8;

              iVar15 = param_6;

            }

            iVar16 = iVar16 + iVar15;

            param_3 = param_3 + iVar4;

            lVar19 = lVar19 + lVar3;

            uVar20 = uVar20 - 1;

          } while (uVar20 != 0);

        }

        break;

      default:

        uVar22 = -(param_4 - param_2);

        if ((int)uVar22 < 0) {

          uVar22 = param_4 - param_2;

        }

        uVar18 = param_5 - param_3;

        param_5 = -uVar18;

        if ((int)param_5 < 0) {

          param_5 = uVar18;

        }

        bVar2 = (int)uVar22 < (int)param_5;

        if (bVar2) {

          iVar16 = uVar22 * 2;

          iVar15 = iVar16 - param_5;

          iVar9 = uVar22 - param_5;

        }

        else {

          iVar16 = param_5 * 2;

          iVar15 = iVar16 - uVar22;

          iVar9 = param_5 - uVar22;

          param_5 = uVar22;

        }

        uVar22 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar22 = (uint)!bVar2;

        }

        uVar18 = -(uint)bVar2;

        if (param_3 <= iVar6) {

          uVar18 = (uint)bVar2;

        }

        uVar14 = 0xffffffff;

        if (param_3 <= iVar6) {

          uVar14 = 1;

        }

        uVar13 = param_5 + 1;

        if (param_11 == 0) {

          uVar13 = param_5;

        }

        uVar7 = (ulonglong)uVar13;

        if (0 < (int)uVar13) {

          lVar19 = lVar19 * 4;

          lVar10 = -4;

          uVar8 = (ulonglong)uVar13;

          if (param_2 <= param_4) {

            lVar10 = 4;

          }

          do {

            uVar7 = *(ulonglong *)(param_1 + 0x18);

            *(uint *)(param_3 * *(int *)(param_1 + 0x10) + lVar19 + uVar7) =

                 (uVar11 << 8 | uVar21) << 8 | uVar12;

            lVar3 = lVar10;

            uVar13 = uVar14;

            iVar6 = iVar9 * 2;

            if (iVar15 < 0) {

              lVar3 = (longlong)(int)uVar22 * 4;

              uVar13 = uVar18;

              iVar6 = iVar16;

            }

            iVar15 = iVar15 + iVar6;

            param_3 = param_3 + uVar13;

            lVar19 = lVar19 + lVar3;

            uVar8 = uVar8 - 1;

          } while (uVar8 != 0);

        }

        break;

      case 3:

        uVar22 = -(param_4 - param_2);

        if ((int)uVar22 < 0) {

          uVar22 = param_4 - param_2;

        }

        uVar18 = -(param_5 - param_3);

        if ((int)uVar18 < 0) {

          uVar18 = param_5 - param_3;

        }

        bVar2 = (int)uVar22 < (int)uVar18;

        if (bVar2) {

          param_6 = uVar22 * 2;

          iVar16 = param_6 - uVar18;

          iVar6 = uVar22 - uVar18;

        }

        else {

          param_6 = uVar18 * 2;

          iVar16 = param_6 - uVar22;

          iVar6 = uVar18 - uVar22;

          uVar18 = uVar22;

        }

        uVar7 = (ulonglong)bVar2;

        uVar22 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar22 = (uint)!bVar2;

        }

        uVar8 = (ulonglong)-(uint)bVar2;

        if (param_3 <= (int)param_5) {

          uVar8 = uVar7;

        }

        iVar9 = -1;

        if (param_3 <= (int)param_5) {

          iVar9 = 1;

        }

        uVar14 = uVar18 + 1;

        if (param_11 == 0) {

          uVar14 = uVar18;

        }

        if (0 < (int)uVar14) {

          lVar19 = lVar19 * 4;

          lVar10 = -4;

          if (param_2 <= param_4) {

            lVar10 = 4;

          }

          local_48 = (ulonglong)uVar14;

          do {

            puVar17 = (uint *)(param_3 * *(int *)(param_1 + 0x10) + lVar19 +

                              *(longlong *)(param_1 + 0x18));

            uVar18 = *puVar17;

            uVar14 = (uVar18 & 0xff) * uVar12;

            uVar7 = (ulonglong)uVar14 * 0x80808081 & 0xffffffff;

            *puVar17 = (((uVar18 >> 0x10 & 0xff) * uVar11) / 0xff << 8 |

                       ((uVar18 >> 8 & 0xff) * uVar21) / 0xff) << 8 | uVar14 / 0xff;

            lVar3 = lVar10;

            iVar4 = iVar9;

            iVar15 = iVar6 * 2;

            if (iVar16 < 0) {

              lVar3 = (longlong)(int)uVar22 * 4;

              iVar4 = (int)uVar8;

              iVar15 = param_6;

            }

            iVar16 = iVar16 + iVar15;

            param_3 = param_3 + iVar4;

            lVar19 = lVar19 + lVar3;

            local_48 = local_48 - 1;

          } while (local_48 != 0);

        }

        break;

      case 7:

        uVar18 = -(param_4 - param_2);

        if ((int)uVar18 < 0) {

          uVar18 = param_4 - param_2;

        }

        uVar14 = -(param_5 - param_3);

        if ((int)uVar14 < 0) {

          uVar14 = param_5 - param_3;

        }

        bVar2 = (int)uVar18 < (int)uVar14;

        if (bVar2) {

          local_res18 = uVar18 * 2;

          param_5 = local_res18 - uVar14;

          iVar16 = uVar18 - uVar14;

        }

        else {

          local_res18 = uVar14 * 2;

          param_5 = local_res18 - uVar18;

          iVar16 = uVar14 - uVar18;

          uVar14 = uVar18;

        }

        uVar7 = (ulonglong)bVar2;

        uVar18 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar18 = (uint)!bVar2;

        }

        uVar8 = (ulonglong)-(uint)bVar2;

        if (param_3 <= iVar6) {

          uVar8 = uVar7;

        }

        iVar9 = -1;

        if (param_3 <= iVar6) {

          iVar9 = 1;

        }

        uVar13 = uVar14 + 1;

        if (param_11 == 0) {

          uVar13 = uVar14;

        }

        if (0 < (int)uVar13) {

          lVar19 = lVar19 * 4;

          lVar10 = -4;

          if (param_2 <= param_4) {

            lVar10 = 4;

          }

          local_48 = (ulonglong)uVar13;

          do {

            puVar17 = (uint *)(param_3 * *(int *)(param_1 + 0x10) + lVar19 +

                              *(longlong *)(param_1 + 0x18));

            uVar14 = (*(byte *)((longlong)puVar17 + 2) * uVar22) / 0xff +

                     (*(byte *)((longlong)puVar17 + 2) * uVar11) / 0xff;

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

            uVar13 = (*(byte *)((longlong)puVar17 + 1) * uVar22) / 0xff +

                     (*(byte *)((longlong)puVar17 + 1) * uVar21) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar5 = ((byte)*puVar17 * uVar22) / 0xff + ((byte)*puVar17 * uVar12) / 0xff;

            if (0xff < uVar5) {

              uVar5 = 0xff;

            }

            *puVar17 = (uVar14 << 8 | uVar13) << 8 | uVar5;

            lVar3 = lVar10;

            iVar15 = iVar9;

            iVar6 = iVar16 * 2;

            if ((int)param_5 < 0) {

              lVar3 = (longlong)(int)uVar18 * 4;

              iVar15 = (int)uVar8;

              iVar6 = local_res18;

            }

            param_5 = param_5 + iVar6;

            param_3 = param_3 + iVar15;

            uVar7 = (ulonglong)param_5;

            lVar19 = lVar19 + lVar3;

            local_48 = local_48 - 1;

          } while (local_48 != 0);

        }

        break;

      case 0xf:

        uVar18 = -(param_4 - param_2);

        if ((int)uVar18 < 0) {

          uVar18 = param_4 - param_2;

        }

        uVar14 = -(param_5 - param_3);

        if ((int)uVar14 < 0) {

          uVar14 = param_5 - param_3;

        }

        bVar2 = (int)uVar18 < (int)uVar14;

        if (bVar2) {

          local_res18 = uVar18 * 2;

          param_5 = local_res18 - uVar14;

          iVar16 = uVar18 - uVar14;

        }

        else {

          local_res18 = uVar14 * 2;

          param_5 = local_res18 - uVar18;

          iVar16 = uVar14 - uVar18;

          uVar14 = uVar18;

        }

        uVar7 = (ulonglong)bVar2;

        uVar18 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar18 = (uint)!bVar2;

        }

        uVar8 = (ulonglong)-(uint)bVar2;

        if (param_3 <= iVar6) {

          uVar8 = uVar7;

        }

        iVar9 = -1;

        if (param_3 <= iVar6) {

          iVar9 = 1;

        }

        uVar13 = uVar14 + 1;

        if (param_11 == 0) {

          uVar13 = uVar14;

        }

        if (0 < (int)uVar13) {

          lVar19 = lVar19 * 4;

          lVar10 = -4;

          if (param_2 <= param_4) {

            lVar10 = 4;

          }

          local_48 = (ulonglong)uVar13;

          do {

            puVar17 = (uint *)(param_3 * *(int *)(param_1 + 0x10) + lVar19 +

                              *(longlong *)(param_1 + 0x18));

            uVar14 = ((*puVar17 >> 0x10 & 0xff) * uVar22) / 0xff + uVar11;

            if (0xff < uVar14) {

              uVar14 = 0xff;

            }

            uVar13 = (*(byte *)((longlong)puVar17 + 1) * uVar22) / 0xff + uVar21;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar5 = ((*puVar17 & 0xff) * uVar22) / 0xff + uVar12;

            if (0xff < uVar5) {

              uVar5 = 0xff;

            }

            *puVar17 = (uVar14 << 8 | uVar13) << 8 | uVar5;

            lVar3 = lVar10;

            iVar15 = iVar9;

            iVar6 = iVar16 * 2;

            if ((int)param_5 < 0) {

              lVar3 = (longlong)(int)uVar18 * 4;

              iVar15 = (int)uVar8;

              iVar6 = local_res18;

            }

            param_5 = param_5 + iVar6;

            param_3 = param_3 + iVar15;

            uVar7 = (ulonglong)param_5;

            lVar19 = lVar19 + lVar3;

            local_48 = local_48 - 1;

          } while (local_48 != 0);

        }

      }

    }

  }

  return uVar7;

}




