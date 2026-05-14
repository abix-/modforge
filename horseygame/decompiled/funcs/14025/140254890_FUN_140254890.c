// Address: 0x140254890
// Ghidra name: FUN_140254890
// ============ 0x140254890 FUN_140254890 (size=8446) ============


ulonglong FUN_140254890(longlong param_1,int param_2,int param_3,int param_4,int param_5,

                       uint param_6,byte param_7,byte param_8,byte param_9,byte param_10,

                       byte param_11)



{

  ushort *puVar1;

  int iVar2;

  bool bVar3;

  longlong lVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  uint uVar8;

  ulonglong uVar9;

  ushort uVar10;

  uint uVar11;

  ulonglong uVar12;

  longlong lVar13;

  uint uVar14;

  ushort uVar15;

  uint uVar16;

  int iVar17;

  ulonglong uVar18;

  ushort *puVar19;

  uint uVar20;

  longlong lVar21;

  ushort uVar22;

  int iVar23;

  uint uVar24;

  int local_res18;

  int local_58;

  int local_50;

  ulonglong local_40;

  ulonglong local_38;

  

  lVar21 = (longlong)param_2;

  if (param_6 - 1 < 2) {

    uVar6 = ((uint)param_7 * (uint)param_10) / 0xff;

    uVar20 = ((uint)param_8 * (uint)param_10) / 0xff;

    uVar14 = ((uint)param_9 * (uint)param_10) / 0xff;

  }

  else {

    uVar6 = (uint)param_7;

    uVar20 = (uint)param_8;

    uVar14 = (uint)param_9;

  }

  uVar24 = param_10 ^ 0xff;

  iVar7 = param_6 + -1;

  uVar22 = (ushort)uVar20;

  uVar15 = (ushort)uVar6;

  if (param_3 == param_5) {

    switch(iVar7) {

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

        uVar10 = *puVar19;

        uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar10 & 0x1f] * uVar24) * 0x80808081 &

                0xffffffff;

        *puVar19 = ((short)(((byte)PTR_DAT_1403e28d0[uVar10 >> 5 & 0x3f] * uVar24) / 0xff) + uVar22)

                   * 8 & 0xffe0 |

                   ((short)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar10 >> 0xb] * uVar24) / 0xff) +

                   uVar15) * 0x100 & 0xf81f |

                   (ushort)(((byte)PTR_DAT_1403e28c8[uVar10 & 0x1f] * uVar24) / 0xff + uVar14 >> 3);

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

        uVar15 = *puVar19;

        uVar9 = 0xff;

        uVar22 = (ushort)((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] + uVar6);

        if (0xff < (byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] + uVar6) {

          uVar22 = 0xff;

        }

        uVar24 = (byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] + uVar20;

        if (0xff < (byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] + uVar20) {

          uVar24 = 0xff;

        }

        uVar11 = (byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] + uVar14;

        if (0xff < (byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] + uVar14) {

          uVar11 = 0xff;

        }

        *puVar19 = ((uVar22 & 0xfff8) << 5 | (ushort)uVar24 & 0xfffc) << 3 | (ushort)(uVar11 >> 3);

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

        uVar15 = ((uVar15 & 0xfff8) << 5 | uVar22 & 0xfffc) << 3 | (ushort)(uVar14 >> 3);

        uVar9 = (ulonglong)uVar15;

        for (uVar12 = (ulonglong)uVar20; uVar12 != 0; uVar12 = uVar12 - 1) {

          *puVar19 = uVar15;

          puVar19 = puVar19 + 1;

        }

      }

      break;

    case 3:

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

        uVar15 = *puVar19;

        uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar14) * 0x80808081 &

                0xffffffff;

        *puVar19 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] * uVar6) / 0xff) & 0xfff8) <<

                    5 | (ushort)((ulonglong)((byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] * uVar20) /

                                0xff) & 0xfffc) << 3 |

                   (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar14) / 0xff >> 3

                           );

        puVar19 = puVar19 + 1;

      }

      break;

    case 7:

      uVar11 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar9 = (ulonglong)uVar11;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar11) * 2);

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

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar11 + lVar21) * 2);

      }

      for (; iVar7 != 0; iVar7 = iVar7 + -1) {

        uVar15 = *puVar19;

        uVar11 = ((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] * uVar24) / 0xff +

                 ((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] * uVar6) / 0xff;

        uVar22 = (ushort)uVar11;

        if (0xff < uVar11) {

          uVar22 = 0xff;

        }

        uVar11 = ((byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] * uVar24) / 0xff +

                 ((byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] * uVar20) / 0xff;

        uVar10 = (ushort)uVar11;

        if (0xff < uVar11) {

          uVar10 = 0xff;

        }

        uVar11 = ((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar24) / 0xff +

                 ((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar14) / 0xff;

        if (0xff < uVar11) {

          uVar11 = 0xff;

        }

        uVar9 = (ulonglong)(uVar11 >> 3);

        *puVar19 = ((uVar22 & 0xfff8) << 5 | uVar10 & 0xfffc) << 3 | (ushort)(uVar11 >> 3);

        puVar19 = puVar19 + 1;

      }

      break;

    case 0xf:

      uVar11 = (*(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5))

               * param_3;

      uVar9 = (ulonglong)uVar11;

      if (param_4 < param_2) {

        puVar1 = (ushort *)

                 (*(longlong *)(param_1 + 0x18) + ((longlong)param_4 + (longlong)(int)uVar11) * 2);

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

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + ((int)uVar11 + lVar21) * 2);

      }

      for (; iVar7 != 0; iVar7 = iVar7 + -1) {

        uVar22 = *puVar19;

        uVar11 = ((byte)PTR_DAT_1403e28c8[uVar22 >> 0xb] * uVar24) / 0xff + uVar6;

        uVar15 = (ushort)uVar11;

        if (0xff < uVar11) {

          uVar15 = 0xff;

        }

        uVar11 = ((byte)PTR_DAT_1403e28d0[uVar22 >> 5 & 0x3f] * uVar24) / 0xff + uVar20;

        uVar10 = (ushort)uVar11;

        if (0xff < uVar11) {

          uVar10 = 0xff;

        }

        uVar11 = ((byte)PTR_DAT_1403e28c8[uVar22 & 0x1f] * uVar24) / 0xff + uVar14;

        if (0xff < uVar11) {

          uVar11 = 0xff;

        }

        uVar9 = (ulonglong)(uVar11 >> 3);

        *puVar19 = ((uVar15 & 0xfff8) << 5 | uVar10 & 0xfffc) << 3 | (ushort)(uVar11 >> 3);

        puVar19 = puVar19 + 1;

      }

    }

  }

  else if (param_2 == param_4) {

    switch(iVar7) {

    case 0:

      iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if (param_5 < param_3) {

        iVar17 = param_3 - param_5;

        uVar9 = iVar7 * param_5 + lVar21;

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

        if (param_11 == 0) {

          puVar19 = puVar19 + iVar7;

        }

        else {

          iVar17 = iVar17 + 1;

        }

      }

      else {

        uVar9 = iVar7 * param_3 + lVar21;

        iVar17 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar17 = param_5 - param_3;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

      }

      for (; iVar17 != 0; iVar17 = iVar17 + -1) {

        uVar10 = *puVar19;

        uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar10 & 0x1f] * uVar24) * 0x80808081 &

                0xffffffff;

        *puVar19 = ((short)(((byte)PTR_DAT_1403e28d0[uVar10 >> 5 & 0x3f] * uVar24) / 0xff) + uVar22)

                   * 8 & 0xffe0 |

                   ((short)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar10 >> 0xb] * uVar24) / 0xff) +

                   uVar15) * 0x100 & 0xf81f |

                   (ushort)(((byte)PTR_DAT_1403e28c8[uVar10 & 0x1f] * uVar24) / 0xff + uVar14 >> 3);

        puVar19 = puVar19 + iVar7;

      }

      break;

    case 1:

    case 0x1f:

      iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if (param_5 < param_3) {

        iVar17 = param_3 - param_5;

        uVar9 = iVar7 * param_5 + lVar21;

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

        if (param_11 == 0) {

          puVar19 = puVar19 + iVar7;

        }

        else {

          iVar17 = iVar17 + 1;

        }

      }

      else {

        uVar9 = iVar7 * param_3 + lVar21;

        iVar17 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar17 = param_5 - param_3;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

      }

      for (; iVar17 != 0; iVar17 = iVar17 + -1) {

        uVar15 = *puVar19;

        uVar9 = 0xff;

        uVar22 = (ushort)((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] + uVar6);

        if (0xff < (byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] + uVar6) {

          uVar22 = 0xff;

        }

        uVar24 = (byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] + uVar20;

        if (0xff < (byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] + uVar20) {

          uVar24 = 0xff;

        }

        uVar11 = (byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] + uVar14;

        if (0xff < (byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] + uVar14) {

          uVar11 = 0xff;

        }

        *puVar19 = ((uVar22 & 0xfff8) << 5 | (ushort)uVar24 & 0xfffc) << 3 | (ushort)(uVar11 >> 3);

        puVar19 = puVar19 + iVar7;

      }

      break;

    default:

      iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if (param_5 < param_3) {

        iVar17 = param_3 - param_5;

        uVar9 = iVar7 * param_5 + lVar21;

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

        if (param_11 == 0) {

          puVar19 = puVar19 + iVar7;

        }

        else {

          iVar17 = iVar17 + 1;

        }

      }

      else {

        uVar9 = iVar7 * param_3 + lVar21;

        iVar17 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar17 = param_5 - param_3;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

      }

      if (iVar17 != 0) {

        do {

          *puVar19 = ((uVar15 & 0xfff8) << 5 | uVar22 & 0xfffc) << 3 | (ushort)(uVar14 >> 3);

          puVar19 = puVar19 + iVar7;

          iVar17 = iVar17 + -1;

        } while (iVar17 != 0);

      }

      break;

    case 3:

      iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if (param_5 < param_3) {

        iVar17 = param_3 - param_5;

        uVar9 = iVar7 * param_5 + lVar21;

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

        if (param_11 == 0) {

          puVar19 = puVar19 + iVar7;

        }

        else {

          iVar17 = iVar17 + 1;

        }

      }

      else {

        uVar9 = iVar7 * param_3 + lVar21;

        iVar17 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar17 = param_5 - param_3;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

      }

      for (; iVar17 != 0; iVar17 = iVar17 + -1) {

        uVar15 = *puVar19;

        uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar14) * 0x80808081 &

                0xffffffff;

        *puVar19 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] * uVar6) / 0xff) & 0xfff8) <<

                    5 | (ushort)((ulonglong)((byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] * uVar20) /

                                0xff) & 0xfffc) << 3 |

                   (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar14) / 0xff >> 3

                           );

        puVar19 = puVar19 + iVar7;

      }

      break;

    case 7:

      iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if (param_5 < param_3) {

        iVar17 = param_3 - param_5;

        uVar9 = iVar7 * param_5 + lVar21;

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

        if (param_11 == 0) {

          puVar19 = puVar19 + iVar7;

        }

        else {

          iVar17 = iVar17 + 1;

        }

      }

      else {

        uVar9 = iVar7 * param_3 + lVar21;

        iVar17 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar17 = param_5 - param_3;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

      }

      for (; iVar17 != 0; iVar17 = iVar17 + -1) {

        uVar15 = *puVar19;

        uVar11 = ((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] * uVar24) / 0xff +

                 ((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] * uVar6) / 0xff;

        uVar22 = (ushort)uVar11;

        if (0xff < uVar11) {

          uVar22 = 0xff;

        }

        uVar11 = ((byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] * uVar24) / 0xff +

                 ((byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] * uVar20) / 0xff;

        uVar10 = (ushort)uVar11;

        if (0xff < uVar11) {

          uVar10 = 0xff;

        }

        uVar11 = ((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar24) / 0xff +

                 ((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar14) / 0xff;

        if (0xff < uVar11) {

          uVar11 = 0xff;

        }

        uVar9 = (ulonglong)(uVar11 >> 3);

        *puVar19 = ((uVar22 & 0xfff8) << 5 | uVar10 & 0xfffc) << 3 | (ushort)(uVar11 >> 3);

        puVar19 = puVar19 + iVar7;

      }

      break;

    case 0xf:

      iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

      if (param_5 < param_3) {

        iVar17 = param_3 - param_5;

        uVar9 = iVar7 * param_5 + lVar21;

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

        if (param_11 == 0) {

          puVar19 = puVar19 + iVar7;

        }

        else {

          iVar17 = iVar17 + 1;

        }

      }

      else {

        uVar9 = iVar7 * param_3 + lVar21;

        iVar17 = (param_5 - param_3) + 1;

        if (param_11 == 0) {

          iVar17 = param_5 - param_3;

        }

        puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + uVar9 * 2);

      }

      for (; iVar17 != 0; iVar17 = iVar17 + -1) {

        uVar22 = *puVar19;

        uVar11 = ((byte)PTR_DAT_1403e28c8[uVar22 >> 0xb] * uVar24) / 0xff + uVar6;

        uVar15 = (ushort)uVar11;

        if (0xff < uVar11) {

          uVar15 = 0xff;

        }

        uVar11 = ((byte)PTR_DAT_1403e28d0[uVar22 >> 5 & 0x3f] * uVar24) / 0xff + uVar20;

        uVar10 = (ushort)uVar11;

        if (0xff < uVar11) {

          uVar10 = 0xff;

        }

        uVar11 = ((byte)PTR_DAT_1403e28c8[uVar22 & 0x1f] * uVar24) / 0xff + uVar14;

        if (0xff < uVar11) {

          uVar11 = 0xff;

        }

        uVar9 = (ulonglong)(uVar11 >> 3);

        *puVar19 = ((uVar15 & 0xfff8) << 5 | uVar10 & 0xfffc) << 3 | (ushort)(uVar11 >> 3);

        puVar19 = puVar19 + iVar7;

      }

    }

  }

  else {

    uVar16 = param_3 - param_5;

    uVar11 = -(param_2 - param_4);

    if ((int)uVar11 < 0) {

      uVar11 = param_2 - param_4;

    }

    uVar8 = -uVar16;

    if ((int)-uVar16 < 0) {

      uVar8 = uVar16;

    }

    if (uVar11 == uVar8) {

      switch(iVar7) {

      case 0:

        uVar12 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar9 = uVar12 & 0xffffffff;

        iVar7 = (int)uVar12;

        if (param_5 < param_3) {

          uVar9 = (ulonglong)param_4;

          puVar19 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) + ((longlong)(iVar7 * param_5) + uVar9) * 2);

          iVar17 = 1;

          if (param_2 < param_4) {

            iVar17 = -1;

          }

          iVar17 = iVar17 + iVar7;

          if (param_11 == 0) {

            uVar9 = (ulonglong)iVar17;

            puVar19 = puVar19 + uVar9;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          iVar17 = 1;

          if (param_4 < param_2) {

            iVar17 = -1;

          }

          iVar17 = iVar17 + iVar7;

          puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar7 * param_3 + lVar21) * 2);

        }

        uVar6 = uVar16 + 1;

        if (param_11 == 0) {

          uVar6 = uVar16;

        }

        if (uVar6 != 0) {

          do {

            uVar10 = *puVar19;

            uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar10 & 0x1f] * uVar24) * 0x80808081 &

                    0xffffffff;

            *puVar19 = ((short)(((byte)PTR_DAT_1403e28d0[uVar10 >> 5 & 0x3f] * uVar24) / 0xff) +

                       uVar22) * 8 & 0xffe0 |

                       ((short)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar10 >> 0xb] * uVar24) / 0xff)

                       + uVar15) * 0x100 & 0xf81f |

                       (ushort)(((byte)PTR_DAT_1403e28c8[uVar10 & 0x1f] * uVar24) / 0xff + uVar14 >>

                               3);

            puVar19 = puVar19 + iVar17;

            uVar6 = uVar6 - 1;

          } while (uVar6 != 0);

        }

        break;

      case 1:

      case 0x1f:

        uVar12 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar9 = uVar12 & 0xffffffff;

        iVar7 = (int)uVar12;

        if (param_5 < param_3) {

          uVar9 = (ulonglong)param_4;

          puVar19 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) + ((longlong)(iVar7 * param_5) + uVar9) * 2);

          iVar17 = 1;

          if (param_2 < param_4) {

            iVar17 = -1;

          }

          iVar17 = iVar17 + iVar7;

          if (param_11 == 0) {

            uVar9 = (ulonglong)iVar17;

            puVar19 = puVar19 + uVar9;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          iVar17 = 1;

          if (param_4 < param_2) {

            iVar17 = -1;

          }

          iVar17 = iVar17 + iVar7;

          puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar7 * param_3 + lVar21) * 2);

        }

        uVar24 = uVar16 + 1;

        if (param_11 == 0) {

          uVar24 = uVar16;

        }

        if (uVar24 != 0) {

          do {

            uVar15 = *puVar19;

            uVar9 = 0xff;

            uVar22 = (ushort)((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] + uVar6);

            if (0xff < (byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] + uVar6) {

              uVar22 = 0xff;

            }

            uVar11 = (byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] + uVar20;

            if (0xff < (byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] + uVar20) {

              uVar11 = 0xff;

            }

            uVar16 = (byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] + uVar14;

            if (0xff < (byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] + uVar14) {

              uVar16 = 0xff;

            }

            *puVar19 = ((uVar22 & 0xfff8) << 5 | (ushort)uVar11 & 0xfffc) << 3 |

                       (ushort)(uVar16 >> 3);

            puVar19 = puVar19 + iVar17;

            uVar24 = uVar24 - 1;

          } while (uVar24 != 0);

        }

        break;

      default:

        iVar7 = *(int *)(param_1 + 0x10) / (int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        if (param_5 < param_3) {

          puVar19 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) +

                    ((longlong)(iVar7 * param_5) + (longlong)param_4) * 2);

          iVar17 = 1;

          if (param_2 < param_4) {

            iVar17 = -1;

          }

          iVar17 = iVar17 + iVar7;

          if (param_11 == 0) {

            puVar19 = puVar19 + iVar17;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          iVar17 = 1;

          if (param_4 < param_2) {

            iVar17 = -1;

          }

          iVar17 = iVar17 + iVar7;

          puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar7 * param_3 + lVar21) * 2);

        }

        uVar6 = uVar16 + 1;

        if (param_11 == 0) {

          uVar6 = uVar16;

        }

        uVar9 = (ulonglong)uVar6;

        if (uVar6 != 0) {

          do {

            *puVar19 = ((uVar15 & 0xfff8) << 5 | uVar22 & 0xfffc) << 3 | (ushort)(uVar14 >> 3);

            puVar19 = puVar19 + iVar17;

            uVar6 = (int)uVar9 - 1;

            uVar9 = (ulonglong)uVar6;

          } while (uVar6 != 0);

          uVar9 = 0;

        }

        break;

      case 3:

        uVar12 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar9 = uVar12 & 0xffffffff;

        iVar7 = (int)uVar12;

        if (param_5 < param_3) {

          uVar9 = (ulonglong)param_4;

          puVar19 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) + ((longlong)(iVar7 * param_5) + uVar9) * 2);

          iVar17 = 1;

          if (param_2 < param_4) {

            iVar17 = -1;

          }

          iVar17 = iVar17 + iVar7;

          if (param_11 == 0) {

            uVar9 = (ulonglong)iVar17;

            puVar19 = puVar19 + uVar9;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          iVar17 = 1;

          if (param_4 < param_2) {

            iVar17 = -1;

          }

          iVar17 = iVar17 + iVar7;

          puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar7 * param_3 + lVar21) * 2);

        }

        uVar24 = uVar16 + 1;

        if (param_11 == 0) {

          uVar24 = uVar16;

        }

        if (uVar24 != 0) {

          do {

            uVar15 = *puVar19;

            uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar14) * 0x80808081 &

                    0xffffffff;

            *puVar19 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] * uVar6) / 0xff) & 0xfff8)

                        << 5 | (ushort)((ulonglong)

                                        ((byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] * uVar20) /

                                       0xff) & 0xfffc) << 3 |

                       (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar14) / 0xff

                               >> 3);

            puVar19 = puVar19 + iVar17;

            uVar24 = uVar24 - 1;

          } while (uVar24 != 0);

        }

        break;

      case 7:

        uVar12 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar9 = uVar12 & 0xffffffff;

        iVar7 = (int)uVar12;

        if (param_5 < param_3) {

          uVar9 = (ulonglong)param_4;

          puVar19 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) + ((longlong)(iVar7 * param_5) + uVar9) * 2);

          iVar17 = 1;

          if (param_2 < param_4) {

            iVar17 = -1;

          }

          iVar17 = iVar17 + iVar7;

          if (param_11 == 0) {

            uVar9 = (ulonglong)iVar17;

            puVar19 = puVar19 + uVar9;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          iVar17 = 1;

          if (param_4 < param_2) {

            iVar17 = -1;

          }

          iVar17 = iVar17 + iVar7;

          puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar7 * param_3 + lVar21) * 2);

        }

        uVar11 = uVar16 + 1;

        if (param_11 == 0) {

          uVar11 = uVar16;

        }

        if (uVar11 != 0) {

          do {

            uVar15 = *puVar19;

            uVar16 = ((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] * uVar24) / 0xff +

                     ((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] * uVar6) / 0xff;

            uVar22 = (ushort)uVar16;

            if (0xff < uVar16) {

              uVar22 = 0xff;

            }

            uVar16 = ((byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] * uVar24) / 0xff +

                     ((byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] * uVar20) / 0xff;

            uVar10 = (ushort)uVar16;

            if (0xff < uVar16) {

              uVar10 = 0xff;

            }

            uVar16 = ((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar24) / 0xff +

                     ((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar14) / 0xff;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar9 = (ulonglong)(uVar16 >> 3);

            *puVar19 = ((uVar22 & 0xfff8) << 5 | uVar10 & 0xfffc) << 3 | (ushort)(uVar16 >> 3);

            puVar19 = puVar19 + iVar17;

            uVar11 = uVar11 - 1;

          } while (uVar11 != 0);

        }

        break;

      case 0xf:

        uVar12 = (longlong)*(int *)(param_1 + 0x10) /

                 (longlong)(int)(uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

        uVar9 = uVar12 & 0xffffffff;

        iVar7 = (int)uVar12;

        if (param_5 < param_3) {

          uVar9 = (ulonglong)param_4;

          puVar19 = (ushort *)

                    (*(longlong *)(param_1 + 0x18) + ((longlong)(iVar7 * param_5) + uVar9) * 2);

          iVar17 = 1;

          if (param_2 < param_4) {

            iVar17 = -1;

          }

          iVar17 = iVar17 + iVar7;

          if (param_11 == 0) {

            uVar9 = (ulonglong)iVar17;

            puVar19 = puVar19 + uVar9;

          }

        }

        else {

          uVar16 = param_5 - param_3;

          iVar17 = 1;

          if (param_4 < param_2) {

            iVar17 = -1;

          }

          iVar17 = iVar17 + iVar7;

          puVar19 = (ushort *)(*(longlong *)(param_1 + 0x18) + (iVar7 * param_3 + lVar21) * 2);

        }

        uVar11 = uVar16 + 1;

        if (param_11 == 0) {

          uVar11 = uVar16;

        }

        if (uVar11 != 0) {

          do {

            uVar22 = *puVar19;

            uVar16 = ((byte)PTR_DAT_1403e28c8[uVar22 >> 0xb] * uVar24) / 0xff + uVar6;

            uVar15 = (ushort)uVar16;

            if (0xff < uVar16) {

              uVar15 = 0xff;

            }

            uVar16 = ((byte)PTR_DAT_1403e28d0[uVar22 >> 5 & 0x3f] * uVar24) / 0xff + uVar20;

            uVar10 = (ushort)uVar16;

            if (0xff < uVar16) {

              uVar10 = 0xff;

            }

            uVar16 = ((byte)PTR_DAT_1403e28c8[uVar22 & 0x1f] * uVar24) / 0xff + uVar14;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            uVar9 = (ulonglong)(uVar16 >> 3);

            *puVar19 = ((uVar15 & 0xfff8) << 5 | uVar10 & 0xfffc) << 3 | (ushort)(uVar16 >> 3);

            puVar19 = puVar19 + iVar17;

            uVar11 = uVar11 - 1;

          } while (uVar11 != 0);

        }

      }

    }

    else {

      switch(iVar7) {

      case 0:

        uVar6 = -(param_4 - param_2);

        if ((int)uVar6 < 0) {

          uVar6 = param_4 - param_2;

        }

        uVar20 = -(param_5 - param_3);

        if ((int)uVar20 < 0) {

          uVar20 = param_5 - param_3;

        }

        bVar3 = (int)uVar6 < (int)uVar20;

        if (bVar3) {

          local_res18 = uVar6 * 2;

          iVar17 = local_res18 - uVar20;

          iVar7 = uVar6 - uVar20;

        }

        else {

          local_res18 = uVar20 * 2;

          iVar17 = local_res18 - uVar6;

          iVar7 = uVar20 - uVar6;

          uVar20 = uVar6;

        }

        uVar9 = (ulonglong)bVar3;

        uVar6 = -(uint)!bVar3;

        if (param_2 <= param_4) {

          uVar6 = (uint)!bVar3;

        }

        uVar12 = (ulonglong)-(uint)bVar3;

        if (param_3 <= param_5) {

          uVar12 = uVar9;

        }

        iVar23 = -1;

        if (param_3 <= param_5) {

          iVar23 = 1;

        }

        uVar11 = uVar20 + 1;

        if (param_11 == 0) {

          uVar11 = uVar20;

        }

        if (0 < (int)uVar11) {

          lVar21 = lVar21 * 2;

          lVar13 = -2;

          if (param_2 <= param_4) {

            lVar13 = 2;

          }

          local_40 = (ulonglong)uVar11;

          do {

            puVar19 = (ushort *)

                      (param_3 * *(int *)(param_1 + 0x10) + lVar21 + *(longlong *)(param_1 + 0x18));

            uVar10 = *puVar19;

            uVar9 = (ulonglong)((byte)PTR_DAT_1403e28c8[uVar10 & 0x1f] * uVar24) * 0x80808081 &

                    0xffffffff;

            *puVar19 = ((short)(((byte)PTR_DAT_1403e28d0[uVar10 >> 5 & 0x3f] * uVar24) / 0xff) +

                       uVar22) * 8 & 0xffe0 |

                       ((short)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar10 >> 0xb] * uVar24) / 0xff)

                       + uVar15) * 0x100 & 0xf81f |

                       (ushort)(((byte)PTR_DAT_1403e28c8[uVar10 & 0x1f] * uVar24) / 0xff + uVar14 >>

                               3);

            lVar4 = lVar13;

            iVar5 = iVar23;

            iVar2 = iVar7 * 2;

            if (iVar17 < 0) {

              lVar4 = (longlong)(int)uVar6 * 2;

              iVar5 = (int)uVar12;

              iVar2 = local_res18;

            }

            iVar17 = iVar17 + iVar2;

            param_3 = param_3 + iVar5;

            lVar21 = lVar21 + lVar4;

            local_40 = local_40 - 1;

          } while (local_40 != 0);

        }

        break;

      case 1:

      case 0x1f:

        uVar24 = -(param_4 - param_2);

        if ((int)uVar24 < 0) {

          uVar24 = param_4 - param_2;

        }

        uVar11 = -(param_5 - param_3);

        if ((int)uVar11 < 0) {

          uVar11 = param_5 - param_3;

        }

        bVar3 = (int)uVar24 < (int)uVar11;

        if (bVar3) {

          local_res18 = uVar24 * 2;

          param_6 = local_res18 - uVar11;

          iVar7 = uVar24 - uVar11;

        }

        else {

          local_res18 = uVar11 * 2;

          param_6 = local_res18 - uVar24;

          iVar7 = uVar11 - uVar24;

          uVar11 = uVar24;

        }

        uVar9 = (ulonglong)bVar3;

        uVar24 = -(uint)!bVar3;

        if (param_2 <= param_4) {

          uVar24 = (uint)!bVar3;

        }

        uVar12 = (ulonglong)-(uint)bVar3;

        if (param_3 <= param_5) {

          uVar12 = uVar9;

        }

        iVar17 = -1;

        if (param_3 <= param_5) {

          iVar17 = 1;

        }

        uVar16 = uVar11 + 1;

        if (param_11 == 0) {

          uVar16 = uVar11;

        }

        if (0 < (int)uVar16) {

          lVar21 = lVar21 * 2;

          lVar13 = -2;

          if (param_2 <= param_4) {

            lVar13 = 2;

          }

          local_38 = (ulonglong)uVar16;

          do {

            puVar19 = (ushort *)

                      (param_3 * *(int *)(param_1 + 0x10) + lVar21 + *(longlong *)(param_1 + 0x18));

            uVar15 = *puVar19;

            uVar22 = (ushort)((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] + uVar6);

            if (0xff < (byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] + uVar6) {

              uVar22 = 0xff;

            }

            uVar11 = (byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] + uVar20;

            if (0xff < (byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] + uVar20) {

              uVar11 = 0xff;

            }

            uVar16 = (byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] + uVar14;

            if (0xff < (byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] + uVar14) {

              uVar16 = 0xff;

            }

            *puVar19 = ((uVar22 & 0xfff8) << 5 | (ushort)uVar11 & 0xfffc) << 3 |

                       (ushort)(uVar16 >> 3);

            lVar4 = lVar13;

            local_50 = iVar17;

            iVar23 = iVar7 * 2;

            if ((int)param_6 < 0) {

              local_50 = (int)uVar12;

              lVar4 = (longlong)(int)uVar24 * 2;

              iVar23 = local_res18;

            }

            param_6 = param_6 + iVar23;

            param_3 = param_3 + local_50;

            uVar9 = (ulonglong)param_6;

            lVar21 = lVar21 + lVar4;

            local_38 = local_38 - 1;

          } while (local_38 != 0);

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

        bVar3 = (int)uVar6 < (int)uVar20;

        if (bVar3) {

          local_res18 = uVar6 * 2;

          iVar17 = local_res18 - uVar20;

          iVar7 = uVar6 - uVar20;

        }

        else {

          local_res18 = uVar20 * 2;

          iVar17 = local_res18 - uVar6;

          iVar7 = uVar20 - uVar6;

          uVar20 = uVar6;

        }

        uVar9 = (ulonglong)bVar3;

        uVar6 = -(uint)!bVar3;

        if (param_2 <= param_4) {

          uVar6 = (uint)!bVar3;

        }

        uVar12 = (ulonglong)-(uint)bVar3;

        if (param_3 <= param_5) {

          uVar12 = uVar9;

        }

        iVar23 = -1;

        if (param_3 <= param_5) {

          iVar23 = 1;

        }

        uVar24 = uVar20 + 1;

        if (param_11 == 0) {

          uVar24 = uVar20;

        }

        if (0 < (int)uVar24) {

          lVar21 = lVar21 * 2;

          lVar13 = -2;

          uVar18 = (ulonglong)uVar24;

          if (param_2 <= param_4) {

            lVar13 = 2;

          }

          do {

            uVar9 = *(ulonglong *)(param_1 + 0x18);

            *(ushort *)(param_3 * *(int *)(param_1 + 0x10) + lVar21 + uVar9) =

                 ((uVar15 & 0xfff8) << 5 | uVar22 & 0xfffc) << 3 | (ushort)(uVar14 >> 3);

            lVar4 = lVar13;

            iVar5 = iVar23;

            iVar2 = iVar7 * 2;

            if (iVar17 < 0) {

              lVar4 = (longlong)(int)uVar6 * 2;

              iVar5 = (int)uVar12;

              iVar2 = local_res18;

            }

            iVar17 = iVar17 + iVar2;

            param_3 = param_3 + iVar5;

            lVar21 = lVar21 + lVar4;

            uVar18 = uVar18 - 1;

          } while (uVar18 != 0);

        }

        break;

      case 3:

        uVar24 = -(param_4 - param_2);

        if ((int)uVar24 < 0) {

          uVar24 = param_4 - param_2;

        }

        uVar11 = -(param_5 - param_3);

        if ((int)uVar11 < 0) {

          uVar11 = param_5 - param_3;

        }

        bVar3 = (int)uVar24 < (int)uVar11;

        if (bVar3) {

          local_res18 = uVar24 * 2;

          param_6 = local_res18 - uVar11;

          iVar7 = uVar24 - uVar11;

        }

        else {

          local_res18 = uVar11 * 2;

          param_6 = local_res18 - uVar24;

          iVar7 = uVar11 - uVar24;

          uVar11 = uVar24;

        }

        uVar9 = (ulonglong)bVar3;

        uVar24 = -(uint)!bVar3;

        if (param_2 <= param_4) {

          uVar24 = (uint)!bVar3;

        }

        uVar12 = (ulonglong)-(uint)bVar3;

        if (param_3 <= param_5) {

          uVar12 = uVar9;

        }

        iVar17 = -1;

        if (param_3 <= param_5) {

          iVar17 = 1;

        }

        uVar16 = uVar11 + 1;

        if (param_11 == 0) {

          uVar16 = uVar11;

        }

        if (0 < (int)uVar16) {

          lVar21 = lVar21 * 2;

          lVar13 = -2;

          if (param_2 <= param_4) {

            lVar13 = 2;

          }

          local_38 = (ulonglong)uVar16;

          do {

            puVar19 = (ushort *)

                      (param_3 * *(int *)(param_1 + 0x10) + lVar21 + *(longlong *)(param_1 + 0x18));

            uVar15 = *puVar19;

            *puVar19 = (((ushort)(((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] * uVar6) / 0xff) & 0xfff8)

                        << 5 | (ushort)((ulonglong)

                                        ((byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] * uVar20) /

                                       0xff) & 0xfffc) << 3 |

                       (ushort)((ulonglong)((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar14) / 0xff

                               >> 3);

            lVar4 = lVar13;

            local_50 = iVar17;

            iVar23 = iVar7 * 2;

            if ((int)param_6 < 0) {

              local_50 = (int)uVar12;

              lVar4 = (longlong)(int)uVar24 * 2;

              iVar23 = local_res18;

            }

            param_6 = param_6 + iVar23;

            param_3 = param_3 + local_50;

            uVar9 = (ulonglong)param_6;

            lVar21 = lVar21 + lVar4;

            local_38 = local_38 - 1;

          } while (local_38 != 0);

        }

        break;

      case 7:

        uVar11 = -(param_4 - param_2);

        if ((int)uVar11 < 0) {

          uVar11 = param_4 - param_2;

        }

        uVar16 = -(param_5 - param_3);

        if ((int)uVar16 < 0) {

          uVar16 = param_5 - param_3;

        }

        bVar3 = (int)uVar11 < (int)uVar16;

        if (bVar3) {

          local_58 = uVar11 * 2;

          param_6 = local_58 - uVar16;

          iVar7 = uVar11 - uVar16;

        }

        else {

          local_58 = uVar16 * 2;

          param_6 = local_58 - uVar11;

          iVar7 = uVar16 - uVar11;

          uVar16 = uVar11;

        }

        uVar9 = (ulonglong)bVar3;

        uVar11 = -(uint)!bVar3;

        if (param_2 <= param_4) {

          uVar11 = (uint)!bVar3;

        }

        uVar12 = (ulonglong)-(uint)bVar3;

        if (param_3 <= param_5) {

          uVar12 = uVar9;

        }

        iVar17 = -1;

        if (param_3 <= param_5) {

          iVar17 = 1;

        }

        uVar8 = uVar16 + 1;

        if (param_11 == 0) {

          uVar8 = uVar16;

        }

        if (0 < (int)uVar8) {

          lVar21 = lVar21 * 2;

          lVar13 = -2;

          if (param_2 <= param_4) {

            lVar13 = 2;

          }

          local_38 = (ulonglong)uVar8;

          do {

            puVar19 = (ushort *)

                      (param_3 * *(int *)(param_1 + 0x10) + lVar21 + *(longlong *)(param_1 + 0x18));

            uVar15 = *puVar19;

            uVar16 = ((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] * uVar24) / 0xff +

                     ((byte)PTR_DAT_1403e28c8[uVar15 >> 0xb] * uVar6) / 0xff;

            uVar22 = (ushort)uVar16;

            if (0xff < uVar16) {

              uVar22 = 0xff;

            }

            uVar16 = ((byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] * uVar24) / 0xff +

                     ((byte)PTR_DAT_1403e28d0[uVar15 >> 5 & 0x3f] * uVar20) / 0xff;

            uVar10 = (ushort)uVar16;

            if (0xff < uVar16) {

              uVar10 = 0xff;

            }

            uVar16 = ((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar24) / 0xff +

                     ((byte)PTR_DAT_1403e28c8[uVar15 & 0x1f] * uVar14) / 0xff;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            *puVar19 = ((uVar22 & 0xfff8) << 5 | uVar10 & 0xfffc) << 3 | (ushort)(uVar16 >> 3);

            lVar4 = lVar13;

            local_50 = iVar17;

            iVar23 = iVar7 * 2;

            if ((int)param_6 < 0) {

              local_50 = (int)uVar12;

              lVar4 = (longlong)(int)uVar11 * 2;

              iVar23 = local_58;

            }

            param_6 = param_6 + iVar23;

            param_3 = param_3 + local_50;

            uVar9 = (ulonglong)param_6;

            lVar21 = lVar21 + lVar4;

            local_38 = local_38 - 1;

          } while (local_38 != 0);

        }

        break;

      case 0xf:

        uVar11 = -(param_4 - param_2);

        if ((int)uVar11 < 0) {

          uVar11 = param_4 - param_2;

        }

        uVar16 = -(param_5 - param_3);

        if ((int)uVar16 < 0) {

          uVar16 = param_5 - param_3;

        }

        bVar3 = (int)uVar11 < (int)uVar16;

        if (bVar3) {

          local_58 = uVar11 * 2;

          param_6 = local_58 - uVar16;

          iVar7 = uVar11 - uVar16;

        }

        else {

          local_58 = uVar16 * 2;

          param_6 = local_58 - uVar11;

          iVar7 = uVar16 - uVar11;

          uVar16 = uVar11;

        }

        uVar9 = (ulonglong)bVar3;

        uVar11 = -(uint)!bVar3;

        if (param_2 <= param_4) {

          uVar11 = (uint)!bVar3;

        }

        uVar12 = (ulonglong)-(uint)bVar3;

        if (param_3 <= param_5) {

          uVar12 = uVar9;

        }

        iVar17 = -1;

        if (param_3 <= param_5) {

          iVar17 = 1;

        }

        uVar8 = uVar16 + 1;

        if (param_11 == 0) {

          uVar8 = uVar16;

        }

        if (0 < (int)uVar8) {

          lVar21 = lVar21 * 2;

          lVar13 = -2;

          if (param_2 <= param_4) {

            lVar13 = 2;

          }

          local_38 = (ulonglong)uVar8;

          do {

            puVar19 = (ushort *)

                      (param_3 * *(int *)(param_1 + 0x10) + lVar21 + *(longlong *)(param_1 + 0x18));

            uVar22 = *puVar19;

            uVar16 = ((byte)PTR_DAT_1403e28c8[uVar22 >> 0xb] * uVar24) / 0xff + uVar6;

            uVar15 = (ushort)uVar16;

            if (0xff < uVar16) {

              uVar15 = 0xff;

            }

            uVar16 = uVar20 + ((byte)PTR_DAT_1403e28d0[uVar22 >> 5 & 0x3f] * uVar24) / 0xff;

            uVar10 = (ushort)uVar16;

            if (0xff < uVar16) {

              uVar10 = 0xff;

            }

            uVar16 = ((byte)PTR_DAT_1403e28c8[uVar22 & 0x1f] * uVar24) / 0xff + uVar14;

            if (0xff < uVar16) {

              uVar16 = 0xff;

            }

            *puVar19 = ((uVar15 & 0xfff8) << 5 | uVar10 & 0xfffc) << 3 | (ushort)(uVar16 >> 3);

            lVar4 = lVar13;

            iVar2 = iVar17;

            iVar23 = iVar7 * 2;

            if ((int)param_6 < 0) {

              lVar4 = (longlong)(int)uVar11 * 2;

              iVar2 = (int)uVar12;

              iVar23 = local_58;

            }

            param_6 = param_6 + iVar23;

            param_3 = param_3 + iVar2;

            uVar9 = (ulonglong)param_6;

            lVar21 = lVar21 + lVar4;

            local_38 = local_38 - 1;

          } while (local_38 != 0);

        }

      }

    }

  }

  return uVar9;

}




