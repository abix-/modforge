// Address: 0x140252800
// Ghidra name: FUN_140252800
// ============ 0x140252800 FUN_140252800 (size=8112) ============


ulonglong FUN_140252800(longlong param_1,int param_2,int param_3,int param_4,uint param_5,

                       int param_6,byte param_7,byte param_8,byte param_9,byte param_10,

                       byte param_11)



{

  ushort *puVar1;

  bool bVar2;

  longlong lVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  uint uVar8;

  ulonglong uVar9;

  uint uVar10;

  ulonglong uVar11;

  longlong lVar12;

  ushort uVar13;

  ushort uVar14;

  uint uVar15;

  int iVar16;

  ulonglong uVar17;

  ushort uVar18;

  ushort *puVar19;

  uint uVar20;

  longlong lVar21;

  int iVar22;

  uint uVar23;

  uint uVar24;

  int local_res18;

  int local_58;

  ulonglong local_48;

  ulonglong local_40;

  ulonglong local_38;

  

  iVar7 = param_5;

  lVar21 = (longlong)param_2;

  if (param_6 - 1U < 2) {

    uVar20 = ((uint)param_7 * (uint)param_10) / 0xff;

    uVar6 = ((uint)param_8 * (uint)param_10) / 0xff;

    uVar23 = ((uint)param_9 * (uint)param_10) / 0xff;

  }

  else {

    uVar20 = (uint)param_7;

    uVar6 = (uint)param_8;

    uVar23 = (uint)param_9;

  }

  uVar24 = param_10 ^ 0xff;

  param_6 = param_6 + -1;

  uVar10 = 0xff;

  uVar18 = (ushort)uVar20;

  uVar13 = (ushort)uVar6;

  if (param_3 == param_5) {

    switch(param_6) {

    case 0:

      uVar6 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5)) *

              param_3;

      uVar9 = (ulonglong)uVar6;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar6) * 2);

        uVar9 = (ulonglong)param_11;

        puVar19 = puVar1 + 1;

        if (param_11 != 0) {

          puVar19 = puVar1;

        }

        iVar7 = param_2 - param_4;

        if (param_11 != 0) {

          iVar7 = iVar7 + 1;

        }

      }

      else {

        iVar7 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar7 = param_4 - param_2;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar6 + lVar21) * 2);

      }

      for (; iVar7 != 0; iVar7 = iVar7 + -1) {

        uVar14 = *puVar19;

        uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar14 & 0x1f] * uVar24) * 0x80808081 &

                0xffffffff;

        *puVar19 = ((short)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar14 >> 10 & 0x1f] * uVar24) /

                           0xff) + uVar18) * 0x80 & 0xfc1f |

                   ((short)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar14 >> 5 & 0x1f] * uVar24) / 0xff

                           ) + uVar13) * 4 & 0xffe0 |

                   (ushort)(((byte)PTR_DAT_1403e28c8[uVar14 & 0x1f] * uVar24) / 0xff + uVar23 >> 3);

        puVar19 = puVar19 + 1;

      }

      break;

    case 1:

    case 0x1f:

      uVar24 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar9 = (ulonglong)uVar24;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar24) * 2);

        uVar9 = (ulonglong)param_11;

        puVar19 = puVar1 + 1;

        if (param_11 != 0) {

          puVar19 = puVar1;

        }

        iVar7 = param_2 - param_4;

        if (param_11 != 0) {

          iVar7 = iVar7 + 1;

        }

      }

      else {

        iVar7 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar7 = param_4 - param_2;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar24 + lVar21) * 2);

      }

      for (; iVar7 != 0; iVar7 = iVar7 + -1) {

        uVar13 = *puVar19;

        uVar9 = (ulonglong)(uVar13 & 0x1f);

        uVar24 = (byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] + uVar20;

        if (0xff < (byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] + uVar20) {

          uVar24 = uVar10;

        }

        uVar15 = (byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] + uVar6;

        if (0xff < (byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] + uVar6) {

          uVar15 = uVar10;

        }

        uVar8 = (byte)PTR_DAT_1403e28c8[uVar9] + uVar23;

        if (0xff < (byte)PTR_DAT_1403e28c8[uVar9] + uVar23) {

          uVar8 = uVar10;

        }

        *puVar19 = (((ushort)uVar24 & 0xfff8) << 5 | (ushort)uVar15 & 0xfff8) << 2 |

                   (ushort)(uVar8 >> 3);

        puVar19 = puVar19 + 1;

      }

      break;

    default:

      uVar6 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5)) *

              param_3;

      uVar9 = (ulonglong)uVar6;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar6) * 2);

        uVar9 = (ulonglong)param_11;

        puVar19 = puVar1 + 1;

        if (param_11 != 0) {

          puVar19 = puVar1;

        }

        uVar20 = param_2 - param_4;

        if (param_11 != 0) {

          uVar20 = uVar20 + 1;

        }

      }

      else {

        uVar20 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          uVar20 = param_4 - param_2;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar6 + lVar21) * 2);

      }

      if (uVar20 != 0) {

        uVar13 = ((uVar18 & 0xfff8) << 5 | uVar13 & 0xfff8) << 2 | (ushort)(uVar23 >> 3);

        uVar9 = (ulonglong)uVar13;

        for (uVar11 = (ulonglong)uVar20; uVar11 != 0; uVar11 = uVar11 - 1) {

          *puVar19 = uVar13;

          puVar19 = puVar19 + 1;

        }

      }

      break;

    case 3:

      uVar10 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar9 = (ulonglong)uVar10;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar10) * 2);

        uVar9 = (ulonglong)param_11;

        puVar19 = puVar1 + 1;

        if (param_11 != 0) {

          puVar19 = puVar1;

        }

        iVar7 = param_2 - param_4;

        if (param_11 != 0) {

          iVar7 = iVar7 + 1;

        }

      }

      else {

        iVar7 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar7 = param_4 - param_2;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar10 + lVar21) * 2);

      }

      for (; iVar7 != 0; iVar7 = iVar7 + -1) {

        uVar13 = *puVar19;

        uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar23) * 0x80808081 &

                0xffffffff;

        *puVar19 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] * uVar20) / 0xff) &

                    0xfff8) << 5 |

                   (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] * uVar6) / 0xff)

                   & 0xfff8) << 2 |

                   (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar23) / 0xff >> 3

                           );

        puVar19 = puVar19 + 1;

      }

      break;

    case 7:

      uVar15 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar9 = (ulonglong)uVar15;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar15) * 2);

        uVar9 = (ulonglong)param_11;

        puVar19 = puVar1 + 1;

        if (param_11 != 0) {

          puVar19 = puVar1;

        }

        iVar7 = param_2 - param_4;

        if (param_11 != 0) {

          iVar7 = iVar7 + 1;

        }

      }

      else {

        iVar7 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar7 = param_4 - param_2;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar15 + lVar21) * 2);

      }

      for (; iVar7 != 0; iVar7 = iVar7 + -1) {

        uVar13 = *puVar19;

        uVar15 = ((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] * uVar24) / 0xff +

                 ((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] * uVar20) / 0xff;

        uVar18 = (ushort)uVar15;

        if (0xff < uVar15) {

          uVar18 = 0xff;

        }

        uVar15 = ((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] * uVar24) / 0xff +

                 ((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] * uVar6) / 0xff;

        uVar14 = (ushort)uVar15;

        if (0xff < uVar15) {

          uVar14 = 0xff;

        }

        uVar15 = ((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar24) / 0xff +

                 ((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar23) / 0xff;

        if (0xff < uVar15) {

          uVar15 = uVar10;

        }

        uVar9 = (ulonglong)(uVar15 >> 3);

        *puVar19 = ((uVar18 & 0xfff8) << 5 | uVar14 & 0xfff8) << 2 | (ushort)(uVar15 >> 3);

        puVar19 = puVar19 + 1;

      }

      break;

    case 0xf:

      uVar10 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar9 = (ulonglong)uVar10;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar10) * 2);

        uVar9 = (ulonglong)param_11;

        puVar19 = puVar1 + 1;

        if (param_11 != 0) {

          puVar19 = puVar1;

        }

        iVar7 = param_2 - param_4;

        if (param_11 != 0) {

          iVar7 = iVar7 + 1;

        }

      }

      else {

        iVar7 = (param_4 - param_2) + 1;

        if (param_11 == 0) {

          iVar7 = param_4 - param_2;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar10 + lVar21) * 2);

      }

      for (; iVar7 != 0; iVar7 = iVar7 + -1) {

        uVar18 = *puVar19;

        uVar10 = ((byte)PTR_DAT_1403e28c8[uVar18 >> 10 & 0x1f] * uVar24) / 0xff + uVar20;

        uVar13 = (ushort)uVar10;

        if (0xff < uVar10) {

          uVar13 = 0xff;

        }

        uVar10 = ((byte)PTR_DAT_1403e28c8[uVar18 >> 5 & 0x1f] * uVar24) / 0xff + uVar6;

        uVar14 = (ushort)uVar10;

        if (0xff < uVar10) {

          uVar14 = 0xff;

        }

        uVar10 = ((byte)PTR_DAT_1403e28c8[uVar18 & 0x1f] * uVar24) / 0xff + uVar23;

        if (0xff < uVar10) {

          uVar10 = 0xff;

        }

        uVar9 = (ulonglong)(uVar10 >> 3);

        *puVar19 = ((uVar13 & 0xfff8) << 5 | uVar14 & 0xfff8) << 2 | (ushort)(uVar10 >> 3);

        puVar19 = puVar19 + 1;

      }

    }

  }

  else if (param_2 == param_4) {

    switch(param_6) {

    case 0:

      iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar16 = param_3 - param_5;

        uVar9 = (int)(iVar7 * param_5) + lVar21;

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

        if (param_11 == 0) {

          puVar19 = puVar19 + iVar7;

        }

        else {

          iVar16 = iVar16 + 1;

        }

      }

      else {

        uVar9 = iVar7 * param_3 + lVar21;

        iVar16 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar16 = param_5 - param_3;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

      }

      for (; iVar16 != 0; iVar16 = iVar16 + -1) {

        uVar14 = *puVar19;

        uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar14 & 0x1f] * uVar24) * 0x80808081 &

                0xffffffff;

        *puVar19 = ((short)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar14 >> 10 & 0x1f] * uVar24) /

                           0xff) + uVar18) * 0x80 & 0xfc1f |

                   ((short)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar14 >> 5 & 0x1f] * uVar24) / 0xff

                           ) + uVar13) * 4 & 0xffe0 |

                   (ushort)(((byte)PTR_DAT_1403e28c8[uVar14 & 0x1f] * uVar24) / 0xff + uVar23 >> 3);

        puVar19 = puVar19 + iVar7;

      }

      break;

    case 1:

    case 0x1f:

      iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar16 = param_3 - param_5;

        uVar9 = (int)(iVar7 * param_5) + lVar21;

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

        if (param_11 == 0) {

          puVar19 = puVar19 + iVar7;

        }

        else {

          iVar16 = iVar16 + 1;

        }

      }

      else {

        uVar9 = iVar7 * param_3 + lVar21;

        iVar16 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar16 = param_5 - param_3;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

      }

      for (; iVar16 != 0; iVar16 = iVar16 + -1) {

        uVar13 = *puVar19;

        uVar9 = (ulonglong)(uVar13 & 0x1f);

        uVar18 = (ushort)((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] + uVar20);

        if (0xff < (byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] + uVar20) {

          uVar18 = 0xff;

        }

        uVar14 = (ushort)((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] + uVar6);

        if (0xff < (byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] + uVar6) {

          uVar14 = 0xff;

        }

        uVar10 = (byte)PTR_DAT_1403e28c8[uVar9] + uVar23;

        if (0xff < (byte)PTR_DAT_1403e28c8[uVar9] + uVar23) {

          uVar10 = 0xff;

        }

        *puVar19 = ((uVar18 & 0xfff8) << 5 | uVar14 & 0xfff8) << 2 | (ushort)(uVar10 >> 3);

        puVar19 = puVar19 + iVar7;

      }

      break;

    default:

      iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar16 = param_3 - param_5;

        uVar9 = (int)(iVar7 * param_5) + lVar21;

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

        if (param_11 == 0) {

          puVar19 = puVar19 + iVar7;

        }

        else {

          iVar16 = iVar16 + 1;

        }

      }

      else {

        uVar9 = iVar7 * param_3 + lVar21;

        iVar16 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar16 = param_5 - param_3;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

      }

      if (iVar16 != 0) {

        do {

          *puVar19 = ((uVar18 & 0xfff8) << 5 | uVar13 & 0xfff8) << 2 | (ushort)(uVar23 >> 3);

          puVar19 = puVar19 + iVar7;

          iVar16 = iVar16 + -1;

        } while (iVar16 != 0);

      }

      break;

    case 3:

      iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar16 = param_3 - param_5;

        uVar9 = (int)(iVar7 * param_5) + lVar21;

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

        if (param_11 == 0) {

          puVar19 = puVar19 + iVar7;

        }

        else {

          iVar16 = iVar16 + 1;

        }

      }

      else {

        uVar9 = iVar7 * param_3 + lVar21;

        iVar16 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar16 = param_5 - param_3;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

      }

      for (; iVar16 != 0; iVar16 = iVar16 + -1) {

        uVar13 = *puVar19;

        uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar23) * 0x80808081 &

                0xffffffff;

        *puVar19 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] * uVar20) / 0xff) &

                    0xfff8) << 5 |

                   (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] * uVar6) / 0xff)

                   & 0xfff8) << 2 |

                   (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar23) / 0xff >> 3

                           );

        puVar19 = puVar19 + iVar7;

      }

      break;

    case 7:

      iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar16 = param_3 - param_5;

        uVar9 = (int)(iVar7 * param_5) + lVar21;

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

        if (param_11 == 0) {

          puVar19 = puVar19 + iVar7;

        }

        else {

          iVar16 = iVar16 + 1;

        }

      }

      else {

        uVar9 = iVar7 * param_3 + lVar21;

        iVar16 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar16 = param_5 - param_3;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

      }

      for (; iVar16 != 0; iVar16 = iVar16 + -1) {

        uVar13 = *puVar19;

        uVar10 = ((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] * uVar24) / 0xff +

                 ((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] * uVar20) / 0xff;

        uVar18 = (ushort)uVar10;

        if (0xff < uVar10) {

          uVar18 = 0xff;

        }

        uVar10 = ((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] * uVar24) / 0xff +

                 ((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] * uVar6) / 0xff;

        uVar14 = (ushort)uVar10;

        if (0xff < uVar10) {

          uVar14 = 0xff;

        }

        uVar10 = ((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar24) / 0xff +

                 ((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar23) / 0xff;

        if (0xff < uVar10) {

          uVar10 = 0xff;

        }

        uVar9 = (ulonglong)(uVar10 >> 3);

        *puVar19 = ((uVar18 & 0xfff8) << 5 | uVar14 & 0xfff8) << 2 | (ushort)(uVar10 >> 3);

        puVar19 = puVar19 + iVar7;

      }

      break;

    case 0xf:

      iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if ((int)param_5 < param_3) {

        iVar16 = param_3 - param_5;

        uVar9 = (int)(iVar7 * param_5) + lVar21;

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

        if (param_11 == 0) {

          puVar19 = puVar19 + iVar7;

        }

        else {

          iVar16 = iVar16 + 1;

        }

      }

      else {

        uVar9 = iVar7 * param_3 + lVar21;

        iVar16 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar16 = param_5 - param_3;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

      }

      for (; iVar16 != 0; iVar16 = iVar16 + -1) {

        uVar18 = *puVar19;

        uVar10 = ((byte)PTR_DAT_1403e28c8[uVar18 >> 10 & 0x1f] * uVar24) / 0xff + uVar20;

        uVar13 = (ushort)uVar10;

        if (0xff < uVar10) {

          uVar13 = 0xff;

        }

        uVar10 = ((byte)PTR_DAT_1403e28c8[uVar18 >> 5 & 0x1f] * uVar24) / 0xff + uVar6;

        uVar14 = (ushort)uVar10;

        if (0xff < uVar10) {

          uVar14 = 0xff;

        }

        uVar10 = ((byte)PTR_DAT_1403e28c8[uVar18 & 0x1f] * uVar24) / 0xff + uVar23;

        if (0xff < uVar10) {

          uVar10 = 0xff;

        }

        uVar9 = (ulonglong)(uVar10 >> 3);

        *puVar19 = ((uVar13 & 0xfff8) << 5 | uVar14 & 0xfff8) << 2 | (ushort)(uVar10 >> 3);

        puVar19 = puVar19 + iVar7;

      }

    }

  }

  else {

    uVar15 = param_3 - param_5;

    uVar10 = -(param_2 - param_4);

    if ((int)uVar10 < 0) {

      uVar10 = param_2 - param_4;

    }

    uVar8 = -uVar15;

    if ((int)-uVar15 < 0) {

      uVar8 = uVar15;

    }

    if (uVar10 == uVar8) {

      switch(param_6) {

      case 0:

        uVar11 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar9 = uVar11 & 0xffffffff;

        iVar7 = (int)uVar11;

        if ((int)param_5 < param_3) {

          uVar9 = (ulonglong)param_4;

          puVar19 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) + ((longlong)(int)(iVar7 * param_5) + uVar9) * 2)

          ;

          iVar16 = 1;

          if (param_2 < param_4) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar7;

          if (param_11 == 0) {

            uVar9 = (ulonglong)iVar16;

            puVar19 = puVar19 + uVar9;

          }

        }

        else {

          uVar15 = param_5 - param_3;

          iVar16 = 1;

          if (param_4 < param_2) {

            iVar16 = -1;

          }

          puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar7 * param_3 + lVar21) * 2);

          iVar16 = iVar16 + iVar7;

        }

        uVar6 = uVar15 + 1;

        if (param_11 == 0) {

          uVar6 = uVar15;

        }

        if (uVar6 != 0) {

          do {

            uVar14 = *puVar19;

            uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar14 & 0x1f] * uVar24) * 0x80808081 &

                    0xffffffff;

            *puVar19 = ((short)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar14 >> 10 & 0x1f] * uVar24) /

                               0xff) + uVar18) * 0x80 & 0xfc1f |

                       ((short)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar14 >> 5 & 0x1f] * uVar24) /

                               0xff) + uVar13) * 4 & 0xffe0 |

                       (ushort)(((byte)PTR_DAT_1403e28c8[uVar14 & 0x1f] * uVar24) / 0xff + uVar23 >>

                               3);

            puVar19 = puVar19 + iVar16;

            uVar6 = uVar6 - 1;

          } while (uVar6 != 0);

        }

        break;

      case 1:

      case 0x1f:

        uVar11 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar9 = uVar11 & 0xffffffff;

        iVar7 = (int)uVar11;

        if ((int)param_5 < param_3) {

          uVar9 = (ulonglong)param_4;

          puVar19 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) + ((longlong)(int)(iVar7 * param_5) + uVar9) * 2)

          ;

          iVar16 = 1;

          if (param_2 < param_4) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar7;

          if (param_11 == 0) {

            uVar9 = (ulonglong)iVar16;

            puVar19 = puVar19 + uVar9;

          }

        }

        else {

          uVar15 = param_5 - param_3;

          iVar16 = 1;

          if (param_4 < param_2) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar7;

          puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar7 * param_3 + lVar21) * 2);

        }

        uVar10 = uVar15 + 1;

        if (param_11 == 0) {

          uVar10 = uVar15;

        }

        if (uVar10 != 0) {

          do {

            uVar13 = *puVar19;

            uVar9 = 0xff;

            uVar18 = (ushort)((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] + uVar20);

            if (0xff < (byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] + uVar20) {

              uVar18 = 0xff;

            }

            uVar24 = (byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] + uVar6;

            if (0xff < (byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] + uVar6) {

              uVar24 = 0xff;

            }

            uVar15 = (byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] + uVar23;

            if (0xff < (byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] + uVar23) {

              uVar15 = 0xff;

            }

            *puVar19 = ((uVar18 & 0xfff8) << 5 | (ushort)uVar24 & 0xfff8) << 2 |

                       (ushort)(uVar15 >> 3);

            puVar19 = puVar19 + iVar16;

            uVar10 = uVar10 - 1;

          } while (uVar10 != 0);

        }

        break;

      default:

        iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        if ((int)param_5 < param_3) {

          puVar19 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) +

                    ((longlong)(int)(iVar7 * param_5) + (longlong)param_4) * 2);

          iVar16 = 1;

          if (param_2 < param_4) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar7;

          if (param_11 == 0) {

            puVar19 = puVar19 + iVar16;

          }

        }

        else {

          uVar15 = param_5 - param_3;

          iVar16 = 1;

          if (param_4 < param_2) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar7;

          puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar7 * param_3 + lVar21) * 2);

        }

        uVar6 = uVar15 + 1;

        if (param_11 == 0) {

          uVar6 = uVar15;

        }

        uVar9 = (ulonglong)uVar6;

        if (uVar6 != 0) {

          do {

            *puVar19 = ((uVar18 & 0xfff8) << 5 | uVar13 & 0xfff8) << 2 | (ushort)(uVar23 >> 3);

            puVar19 = puVar19 + iVar16;

            uVar6 = (int)uVar9 - 1;

            uVar9 = (ulonglong)uVar6;

          } while (uVar6 != 0);

          uVar9 = 0;

        }

        break;

      case 3:

        uVar11 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar9 = uVar11 & 0xffffffff;

        iVar7 = (int)uVar11;

        if ((int)param_5 < param_3) {

          uVar9 = (ulonglong)param_4;

          puVar19 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) + ((longlong)(int)(iVar7 * param_5) + uVar9) * 2)

          ;

          iVar16 = 1;

          if (param_2 < param_4) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar7;

          if (param_11 == 0) {

            uVar9 = (ulonglong)iVar16;

            puVar19 = puVar19 + uVar9;

          }

        }

        else {

          uVar15 = param_5 - param_3;

          iVar16 = 1;

          if (param_4 < param_2) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar7;

          puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar7 * param_3 + lVar21) * 2);

        }

        uVar10 = uVar15 + 1;

        if (param_11 == 0) {

          uVar10 = uVar15;

        }

        if (uVar10 != 0) {

          do {

            uVar13 = *puVar19;

            uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar23) * 0x80808081 &

                    0xffffffff;

            *puVar19 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] * uVar20) / 0xff) &

                        0xfff8) << 5 |

                       (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] * uVar6) /

                               0xff) & 0xfff8) << 2 |

                       (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar23) / 0xff

                               >> 3);

            puVar19 = puVar19 + iVar16;

            uVar10 = uVar10 - 1;

          } while (uVar10 != 0);

        }

        break;

      case 7:

        uVar11 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar9 = uVar11 & 0xffffffff;

        iVar7 = (int)uVar11;

        if ((int)param_5 < param_3) {

          uVar9 = (ulonglong)param_4;

          puVar19 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) + ((longlong)(int)(iVar7 * param_5) + uVar9) * 2)

          ;

          iVar16 = 1;

          if (param_2 < param_4) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar7;

          if (param_11 == 0) {

            uVar9 = (ulonglong)iVar16;

            puVar19 = puVar19 + uVar9;

          }

        }

        else {

          uVar15 = param_5 - param_3;

          iVar16 = 1;

          if (param_4 < param_2) {

            iVar16 = -1;

          }

          puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar7 * param_3 + lVar21) * 2);

          iVar16 = iVar16 + iVar7;

        }

        uVar10 = uVar15 + 1;

        if (param_11 == 0) {

          uVar10 = uVar15;

        }

        if (uVar10 != 0) {

          do {

            uVar13 = *puVar19;

            uVar15 = ((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] * uVar24) / 0xff +

                     ((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] * uVar20) / 0xff;

            uVar18 = (ushort)uVar15;

            if (0xff < uVar15) {

              uVar18 = 0xff;

            }

            uVar15 = ((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] * uVar24) / 0xff +

                     ((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] * uVar6) / 0xff;

            uVar14 = (ushort)uVar15;

            if (0xff < uVar15) {

              uVar14 = 0xff;

            }

            uVar15 = ((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar24) / 0xff +

                     ((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar23) / 0xff;

            if (0xff < uVar15) {

              uVar15 = 0xff;

            }

            uVar9 = (ulonglong)(uVar15 >> 3);

            *puVar19 = ((uVar18 & 0xfff8) << 5 | uVar14 & 0xfff8) << 2 | (ushort)(uVar15 >> 3);

            puVar19 = puVar19 + iVar16;

            uVar10 = uVar10 - 1;

          } while (uVar10 != 0);

        }

        break;

      case 0xf:

        uVar11 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar9 = uVar11 & 0xffffffff;

        iVar7 = (int)uVar11;

        if ((int)param_5 < param_3) {

          uVar9 = (ulonglong)param_4;

          puVar19 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) + ((longlong)(int)(iVar7 * param_5) + uVar9) * 2)

          ;

          iVar16 = 1;

          if (param_2 < param_4) {

            iVar16 = -1;

          }

          iVar16 = iVar16 + iVar7;

          if (param_11 == 0) {

            uVar9 = (ulonglong)iVar16;

            puVar19 = puVar19 + uVar9;

          }

        }

        else {

          uVar15 = param_5 - param_3;

          iVar16 = 1;

          if (param_4 < param_2) {

            iVar16 = -1;

          }

          puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar7 * param_3 + lVar21) * 2);

          iVar16 = iVar16 + iVar7;

        }

        uVar10 = uVar15 + 1;

        if (param_11 == 0) {

          uVar10 = uVar15;

        }

        if (uVar10 != 0) {

          do {

            uVar18 = *puVar19;

            uVar15 = ((byte)PTR_DAT_1403e28c8[uVar18 >> 10 & 0x1f] * uVar24) / 0xff + uVar20;

            uVar13 = (ushort)uVar15;

            if (0xff < uVar15) {

              uVar13 = 0xff;

            }

            uVar15 = ((byte)PTR_DAT_1403e28c8[uVar18 >> 5 & 0x1f] * uVar24) / 0xff + uVar6;

            uVar14 = (ushort)uVar15;

            if (0xff < uVar15) {

              uVar14 = 0xff;

            }

            uVar15 = ((byte)PTR_DAT_1403e28c8[uVar18 & 0x1f] * uVar24) / 0xff + uVar23;

            if (0xff < uVar15) {

              uVar15 = 0xff;

            }

            uVar9 = (ulonglong)(uVar15 >> 3);

            *puVar19 = ((uVar13 & 0xfff8) << 5 | uVar14 & 0xfff8) << 2 | (ushort)(uVar15 >> 3);

            puVar19 = puVar19 + iVar16;

            uVar10 = uVar10 - 1;

          } while (uVar10 != 0);

        }

      }

    }

    else {

      switch(param_6) {

      case 0:

        uVar6 = -(param_4 - param_2);

        if ((int)uVar6 < 0) {

          uVar6 = param_4 - param_2;

        }

        uVar20 = -(param_5 - param_3);

        if ((int)uVar20 < 0) {

          uVar20 = param_5 - param_3;

        }

        bVar2 = (int)uVar6 < (int)uVar20;

        if (bVar2) {

          local_res18 = uVar6 * 2;

          param_5 = local_res18 - uVar20;

          iVar16 = uVar6 - uVar20;

        }

        else {

          local_res18 = uVar20 * 2;

          param_5 = local_res18 - uVar6;

          iVar16 = uVar20 - uVar6;

          uVar20 = uVar6;

        }

        uVar9 = (ulonglong)bVar2;

        uVar6 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar6 = (uint)!bVar2;

        }

        uVar11 = (ulonglong)-(uint)bVar2;

        if (param_3 <= iVar7) {

          uVar11 = uVar9;

        }

        iVar22 = -1;

        if (param_3 <= iVar7) {

          iVar22 = 1;

        }

        uVar10 = uVar20 + 1;

        if (param_11 == 0) {

          uVar10 = uVar20;

        }

        if (0 < (int)uVar10) {

          lVar21 = lVar21 * 2;

          lVar12 = -2;

          if (param_2 <= param_4) {

            lVar12 = 2;

          }

          local_40 = (ulonglong)uVar10;

          do {

            puVar19 = (ushort *)

                      (param_3 * *(int *)(param_1 + 0x10) + lVar21 + *(longlong *)(param_1 + 0x18));

            uVar14 = *puVar19;

            *puVar19 = ((short)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar14 >> 10 & 0x1f] * uVar24) /

                               0xff) + uVar18) * 0x80 & 0xfc1f |

                       ((short)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar14 >> 5 & 0x1f] * uVar24) /

                               0xff) + uVar13) * 4 & 0xffe0 |

                       (ushort)(((byte)PTR_DAT_1403e28c8[uVar14 & 0x1f] * uVar24) / 0xff + uVar23 >>

                               3);

            lVar3 = lVar12;

            iVar4 = iVar22;

            iVar7 = iVar16 * 2;

            if ((int)param_5 < 0) {

              lVar3 = (longlong)(int)uVar6 * 2;

              iVar4 = (int)uVar11;

              iVar7 = local_res18;

            }

            param_5 = param_5 + iVar7;

            param_3 = param_3 + iVar4;

            uVar9 = (ulonglong)param_5;

            lVar21 = lVar21 + lVar3;

            local_40 = local_40 - 1;

          } while (local_40 != 0);

        }

        break;

      case 1:

      case 0x1f:

        uVar10 = -(param_4 - param_2);

        if ((int)uVar10 < 0) {

          uVar10 = param_4 - param_2;

        }

        uVar24 = -(param_5 - param_3);

        if ((int)uVar24 < 0) {

          uVar24 = param_5 - param_3;

        }

        bVar2 = (int)uVar10 < (int)uVar24;

        if (bVar2) {

          local_res18 = uVar10 * 2;

          param_5 = local_res18 - uVar24;

          iVar16 = uVar10 - uVar24;

        }

        else {

          local_res18 = uVar24 * 2;

          param_5 = local_res18 - uVar10;

          iVar16 = uVar24 - uVar10;

          uVar24 = uVar10;

        }

        uVar9 = (ulonglong)bVar2;

        uVar10 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar10 = (uint)!bVar2;

        }

        uVar11 = (ulonglong)-(uint)bVar2;

        if (param_3 <= iVar7) {

          uVar11 = uVar9;

        }

        iVar22 = -1;

        if (param_3 <= iVar7) {

          iVar22 = 1;

        }

        uVar15 = uVar24 + 1;

        if (param_11 == 0) {

          uVar15 = uVar24;

        }

        if (0 < (int)uVar15) {

          lVar21 = lVar21 * 2;

          lVar12 = -2;

          if (param_2 <= param_4) {

            lVar12 = 2;

          }

          local_40 = (ulonglong)uVar15;

          do {

            puVar19 = (ushort *)

                      (param_3 * *(int *)(param_1 + 0x10) + lVar21 + *(longlong *)(param_1 + 0x18));

            uVar13 = *puVar19;

            uVar18 = (ushort)((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] + uVar20);

            if (0xff < (byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] + uVar20) {

              uVar18 = 0xff;

            }

            uVar24 = (byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] + uVar6;

            if (0xff < (byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] + uVar6) {

              uVar24 = 0xff;

            }

            uVar15 = (byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] + uVar23;

            if (0xff < (byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] + uVar23) {

              uVar15 = 0xff;

            }

            *puVar19 = ((uVar18 & 0xfff8) << 5 | (ushort)uVar24 & 0xfff8) << 2 |

                       (ushort)(uVar15 >> 3);

            lVar3 = lVar12;

            iVar4 = iVar22;

            iVar7 = iVar16 * 2;

            if ((int)param_5 < 0) {

              lVar3 = (longlong)(int)uVar10 * 2;

              iVar4 = (int)uVar11;

              iVar7 = local_res18;

            }

            param_5 = param_5 + iVar7;

            param_3 = param_3 + iVar4;

            uVar9 = (ulonglong)param_5;

            lVar21 = lVar21 + lVar3;

            local_40 = local_40 - 1;

          } while (local_40 != 0);

        }

        break;

      default:

        uVar6 = -(param_4 - param_2);

        if ((int)uVar6 < 0) {

          uVar6 = param_4 - param_2;

        }

        uVar20 = -(param_5 - param_3);

        if ((int)uVar20 < 0) {

          uVar20 = param_5 - param_3;

        }

        bVar2 = (int)uVar6 < (int)uVar20;

        if (bVar2) {

          param_6 = uVar6 * 2;

          iVar16 = param_6 - uVar20;

          iVar7 = uVar6 - uVar20;

        }

        else {

          param_6 = uVar20 * 2;

          iVar16 = param_6 - uVar6;

          iVar7 = uVar20 - uVar6;

          uVar20 = uVar6;

        }

        uVar9 = (ulonglong)bVar2;

        uVar6 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar6 = (uint)!bVar2;

        }

        uVar11 = (ulonglong)-(uint)bVar2;

        if (param_3 <= (int)param_5) {

          uVar11 = uVar9;

        }

        iVar22 = -1;

        if (param_3 <= (int)param_5) {

          iVar22 = 1;

        }

        uVar10 = uVar20 + 1;

        if (param_11 == 0) {

          uVar10 = uVar20;

        }

        if (0 < (int)uVar10) {

          lVar21 = lVar21 * 2;

          lVar12 = -2;

          uVar17 = (ulonglong)uVar10;

          if (param_2 <= param_4) {

            lVar12 = 2;

          }

          do {

            uVar9 = *(ulonglong *)(param_1 + 0x18);

            *(ushort *)(param_3 * *(int *)(param_1 + 0x10) + lVar21 + uVar9) =

                 ((uVar18 & 0xfff8) << 5 | uVar13 & 0xfff8) << 2 | (ushort)(uVar23 >> 3);

            lVar3 = lVar12;

            iVar5 = iVar22;

            iVar4 = iVar7 * 2;

            if (iVar16 < 0) {

              lVar3 = (longlong)(int)uVar6 * 2;

              iVar5 = (int)uVar11;

              iVar4 = param_6;

            }

            iVar16 = iVar16 + iVar4;

            param_3 = param_3 + iVar5;

            lVar21 = lVar21 + lVar3;

            uVar17 = uVar17 - 1;

          } while (uVar17 != 0);

        }

        break;

      case 3:

        uVar10 = -(param_4 - param_2);

        if ((int)uVar10 < 0) {

          uVar10 = param_4 - param_2;

        }

        uVar24 = -(param_5 - param_3);

        if ((int)uVar24 < 0) {

          uVar24 = param_5 - param_3;

        }

        bVar2 = (int)uVar10 < (int)uVar24;

        if (bVar2) {

          local_res18 = uVar10 * 2;

          param_5 = local_res18 - uVar24;

          iVar16 = uVar10 - uVar24;

        }

        else {

          local_res18 = uVar24 * 2;

          param_5 = local_res18 - uVar10;

          iVar16 = uVar24 - uVar10;

          uVar24 = uVar10;

        }

        uVar9 = (ulonglong)bVar2;

        uVar10 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar10 = (uint)!bVar2;

        }

        uVar11 = (ulonglong)-(uint)bVar2;

        if (param_3 <= iVar7) {

          uVar11 = uVar9;

        }

        iVar22 = -1;

        if (param_3 <= iVar7) {

          iVar22 = 1;

        }

        uVar15 = uVar24 + 1;

        if (param_11 == 0) {

          uVar15 = uVar24;

        }

        if (0 < (int)uVar15) {

          lVar21 = lVar21 * 2;

          lVar12 = -2;

          if (param_2 <= param_4) {

            lVar12 = 2;

          }

          local_40 = (ulonglong)uVar15;

          do {

            puVar19 = (ushort *)

                      (param_3 * *(int *)(param_1 + 0x10) + lVar21 + *(longlong *)(param_1 + 0x18));

            uVar13 = *puVar19;

            *puVar19 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] * uVar20) / 0xff) &

                        0xfff8) << 5 |

                       (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] * uVar6) /

                               0xff) & 0xfff8) << 2 |

                       (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar23) / 0xff

                               >> 3);

            lVar3 = lVar12;

            iVar4 = iVar22;

            iVar7 = iVar16 * 2;

            if ((int)param_5 < 0) {

              lVar3 = (longlong)(int)uVar10 * 2;

              iVar4 = (int)uVar11;

              iVar7 = local_res18;

            }

            param_5 = param_5 + iVar7;

            param_3 = param_3 + iVar4;

            uVar9 = (ulonglong)param_5;

            lVar21 = lVar21 + lVar3;

            local_40 = local_40 - 1;

          } while (local_40 != 0);

        }

        break;

      case 7:

        uVar10 = -(param_4 - param_2);

        if ((int)uVar10 < 0) {

          uVar10 = param_4 - param_2;

        }

        uVar15 = -(param_5 - param_3);

        if ((int)uVar15 < 0) {

          uVar15 = param_5 - param_3;

        }

        bVar2 = (int)uVar10 < (int)uVar15;

        if (bVar2) {

          local_58 = uVar10 * 2;

          param_5 = local_58 - uVar15;

          iVar16 = uVar10 - uVar15;

        }

        else {

          local_58 = uVar15 * 2;

          param_5 = local_58 - uVar10;

          iVar16 = uVar15 - uVar10;

          uVar15 = uVar10;

        }

        uVar9 = (ulonglong)bVar2;

        uVar10 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar10 = (uint)!bVar2;

        }

        uVar11 = (ulonglong)-(uint)bVar2;

        if (param_3 <= iVar7) {

          uVar11 = uVar9;

        }

        iVar22 = -1;

        if (param_3 <= iVar7) {

          iVar22 = 1;

        }

        uVar8 = uVar15 + 1;

        if (param_11 == 0) {

          uVar8 = uVar15;

        }

        if (0 < (int)uVar8) {

          lVar21 = lVar21 * 2;

          lVar12 = -2;

          if (param_2 <= param_4) {

            lVar12 = 2;

          }

          local_38 = (ulonglong)uVar8;

          do {

            puVar19 = (ushort *)

                      (param_3 * *(int *)(param_1 + 0x10) + lVar21 + *(longlong *)(param_1 + 0x18));

            uVar13 = *puVar19;

            uVar15 = ((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] * uVar24) / 0xff +

                     ((byte)PTR_DAT_1403e28c8[uVar13 >> 10 & 0x1f] * uVar20) / 0xff;

            uVar18 = (ushort)uVar15;

            if (0xff < uVar15) {

              uVar18 = 0xff;

            }

            uVar15 = ((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] * uVar24) / 0xff +

                     ((byte)PTR_DAT_1403e28c8[uVar13 >> 5 & 0x1f] * uVar6) / 0xff;

            uVar14 = (ushort)uVar15;

            if (0xff < uVar15) {

              uVar14 = 0xff;

            }

            uVar15 = ((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar24) / 0xff +

                     ((byte)PTR_DAT_1403e28c8[uVar13 & 0x1f] * uVar23) / 0xff;

            if (0xff < uVar15) {

              uVar15 = 0xff;

            }

            *puVar19 = ((uVar18 & 0xfff8) << 5 | uVar14 & 0xfff8) << 2 | (ushort)(uVar15 >> 3);

            lVar3 = lVar12;

            iVar4 = iVar22;

            iVar7 = iVar16 * 2;

            if ((int)param_5 < 0) {

              lVar3 = (longlong)(int)uVar10 * 2;

              iVar4 = (int)uVar11;

              iVar7 = local_58;

            }

            param_5 = param_5 + iVar7;

            param_3 = param_3 + iVar4;

            uVar9 = (ulonglong)param_5;

            lVar21 = lVar21 + lVar3;

            local_38 = local_38 - 1;

          } while (local_38 != 0);

        }

        break;

      case 0xf:

        uVar10 = -(param_4 - param_2);

        if ((int)uVar10 < 0) {

          uVar10 = param_4 - param_2;

        }

        uVar15 = -(param_5 - param_3);

        if ((int)uVar15 < 0) {

          uVar15 = param_5 - param_3;

        }

        bVar2 = (int)uVar10 < (int)uVar15;

        if (bVar2) {

          local_res18 = uVar10 * 2;

          param_5 = local_res18 - uVar15;

          iVar16 = uVar10 - uVar15;

        }

        else {

          local_res18 = uVar15 * 2;

          param_5 = local_res18 - uVar10;

          iVar16 = uVar15 - uVar10;

          uVar15 = uVar10;

        }

        uVar9 = (ulonglong)bVar2;

        uVar10 = -(uint)!bVar2;

        if (param_2 <= param_4) {

          uVar10 = (uint)!bVar2;

        }

        uVar11 = (ulonglong)-(uint)bVar2;

        if (param_3 <= iVar7) {

          uVar11 = uVar9;

        }

        iVar22 = -1;

        if (param_3 <= iVar7) {

          iVar22 = 1;

        }

        uVar8 = uVar15 + 1;

        if (param_11 == 0) {

          uVar8 = uVar15;

        }

        if (0 < (int)uVar8) {

          lVar21 = lVar21 * 2;

          lVar12 = -2;

          if (param_2 <= param_4) {

            lVar12 = 2;

          }

          local_48 = (ulonglong)uVar8;

          do {

            puVar19 = (ushort *)

                      (param_3 * *(int *)(param_1 + 0x10) + lVar21 + *(longlong *)(param_1 + 0x18));

            uVar18 = *puVar19;

            uVar15 = ((byte)PTR_DAT_1403e28c8[uVar18 >> 10 & 0x1f] * uVar24) / 0xff + uVar20;

            uVar13 = (ushort)uVar15;

            if (0xff < uVar15) {

              uVar13 = 0xff;

            }

            uVar15 = ((byte)PTR_DAT_1403e28c8[uVar18 >> 5 & 0x1f] * uVar24) / 0xff + uVar6;

            uVar14 = (ushort)uVar15;

            if (0xff < uVar15) {

              uVar14 = 0xff;

            }

            uVar15 = ((byte)PTR_DAT_1403e28c8[uVar18 & 0x1f] * uVar24) / 0xff + uVar23;

            if (0xff < uVar15) {

              uVar15 = 0xff;

            }

            *puVar19 = ((uVar13 & 0xfff8) << 5 | uVar14 & 0xfff8) << 2 | (ushort)(uVar15 >> 3);

            lVar3 = lVar12;

            iVar4 = iVar22;

            iVar7 = iVar16 * 2;

            if ((int)param_5 < 0) {

              lVar3 = (longlong)(int)uVar10 * 2;

              iVar4 = (int)uVar11;

              iVar7 = local_res18;

            }

            param_5 = param_5 + iVar7;

            param_3 = param_3 + iVar4;

            uVar9 = (ulonglong)param_5;

            lVar21 = lVar21 + lVar3;

            local_48 = local_48 - 1;

          } while (local_48 != 0);

        }

      }

    }

  }

  return uVar9;

}




