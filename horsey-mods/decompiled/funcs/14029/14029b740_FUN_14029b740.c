// Address: 0x14029b740
// Ghidra name: FUN_14029b740
// ============ 0x14029b740 FUN_14029b740 (size=2271) ============


void FUN_14029b740(longlong param_1)



{

  longlong lVar1;

  byte *pbVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  byte bVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  int iVar10;

  longlong lVar11;

  longlong lVar12;

  longlong lVar13;

  ushort uVar14;

  int iVar15;

  uint uVar16;

  ulonglong uVar17;

  uint *puVar18;

  uint uVar19;

  byte *pbVar20;

  ulonglong uVar21;

  ushort uVar22;

  uint uVar23;

  ushort uVar24;

  int iVar25;

  

  iVar7 = *(int *)(param_1 + 0x1c);

  lVar11 = *(longlong *)(param_1 + 0x48);

  uVar8 = *(uint *)(param_1 + 0x38);

  puVar18 = *(uint **)(param_1 + 8);

  pbVar20 = *(byte **)(param_1 + 0x30);

  lVar12 = *(longlong *)(param_1 + 0x68);

  bVar3 = *(byte *)(lVar11 + 5);

  uVar9 = *(uint *)(param_1 + 0x7c);

  iVar10 = *(int *)(param_1 + 0x44);

  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x60) + 8);

  bVar4 = *(byte *)(param_1 + 0x83);

  iVar15 = *(int *)(param_1 + 0x3c);

  while( true ) {

    if (iVar15 == 0) {

      return;

    }

    iVar25 = uVar8 + 3;

    iVar25 = (int)((iVar25 >> 0x1f & 3U) + iVar25) >> 2;

    uVar16 = uVar8 & 3;

    uVar19 = (uint)bVar3;

    if (uVar16 == 0) goto LAB_14029b7f7;

    if (uVar16 == 1) goto LAB_14029bde7;

    if (uVar16 == 2) goto LAB_14029bbee;

    if (uVar16 == 3) break;

LAB_14029bff6:

    puVar18 = (uint *)((longlong)puVar18 + (longlong)iVar7);

    pbVar20 = pbVar20 + iVar10;

    iVar15 = iVar15 + -1;

  }

  do {

    uVar16 = 0;

    if (bVar3 == 1) {

      uVar21 = (ulonglong)(byte)*puVar18;

LAB_14029ba9f:

      bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

              [(*(uint *)(lVar11 + 8) & uVar21) >> (*(byte *)(lVar11 + 0x1c) & 0x3f)];

      bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

              [(*(uint *)(lVar11 + 0xc) & uVar21) >> (*(byte *)(lVar11 + 0x1d) & 0x3f)];

      uVar17 = *(uint *)(lVar11 + 0x10) & uVar21;

LAB_14029bae2:

      uVar16 = (uint)bVar5;

      uVar24 = (ushort)bVar6;

      uVar23 = (uint)uVar21;

      uVar14 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1a)]

                             [uVar17 >> (*(byte *)(lVar11 + 0x1e) & 0x3f)];

    }

    else {

      if (bVar3 == 2) {

        uVar21 = (ulonglong)(ushort)*puVar18;

        goto LAB_14029ba9f;

      }

      if (bVar3 != 3) {

        if (bVar3 != 4) {

          uVar24 = 0;

          uVar14 = 0;

          uVar23 = uVar16;

          goto LAB_14029baf8;

        }

        uVar16 = *puVar18;

        uVar21 = (ulonglong)uVar16;

        bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

                [(*(uint *)(lVar11 + 8) & uVar16) >> (*(byte *)(lVar11 + 0x1c) & 0x3f)];

        bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

                [(*(uint *)(lVar11 + 0xc) & uVar16) >> (*(byte *)(lVar11 + 0x1d) & 0x3f)];

        uVar17 = (ulonglong)(*(uint *)(lVar11 + 0x10) & uVar16);

        goto LAB_14029bae2;

      }

      uVar23 = 0;

      uVar24 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) + (longlong)puVar18);

      uVar16 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) + (longlong)puVar18);

      uVar14 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) + (longlong)puVar18);

    }

LAB_14029baf8:

    if (uVar23 != uVar9) {

      pbVar2 = (byte *)(lVar13 + (ulonglong)*pbVar20 * 4);

      uVar24 = (uVar24 - *pbVar2) * (ushort)bVar4 + (ushort)*pbVar2 * 0xff + 1;

      uVar24 = (uVar24 >> 8) + uVar24;

      uVar22 = ((short)uVar16 - (ushort)pbVar2[1]) * (ushort)bVar4 + (ushort)pbVar2[1] * 0xff + 1;

      uVar22 = (uVar22 >> 8) + uVar22;

      uVar14 = (uVar14 - pbVar2[2]) * (ushort)bVar4 + (ushort)pbVar2[2] * 0xff + 1;

      uVar14 = (uVar14 >> 8) + uVar14;

      if (lVar12 == 0) {

        *pbVar20 = ((byte)(uVar22 >> 0xb) | (byte)(uVar24 >> 8) & 0xe3) & 0xfc |

                   (byte)(uVar14 >> 0xe);

      }

      else {

        *pbVar20 = *(byte *)((((ulonglong)(uVar22 >> 8) & 0xffffffe0 | (ulonglong)(uVar14 >> 0xb))

                              >> 3 | (ulonglong)(uVar24 >> 8) & 0xffffffe0) + lVar12);

      }

    }

    puVar18 = (uint *)((longlong)puVar18 + (longlong)(int)uVar19);

    pbVar20 = pbVar20 + 1;

LAB_14029bbee:

    uVar16 = 0;

    if (bVar3 == 1) {

      uVar21 = (ulonglong)(byte)*puVar18;

LAB_14029bc98:

      bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

              [(*(uint *)(lVar11 + 8) & uVar21) >> (*(byte *)(lVar11 + 0x1c) & 0x3f)];

      bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

              [(*(uint *)(lVar11 + 0xc) & uVar21) >> (*(byte *)(lVar11 + 0x1d) & 0x3f)];

      uVar17 = *(uint *)(lVar11 + 0x10) & uVar21;

LAB_14029bcdb:

      uVar16 = (uint)bVar5;

      uVar24 = (ushort)bVar6;

      uVar23 = (uint)uVar21;

      uVar14 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1a)]

                             [uVar17 >> (*(byte *)(lVar11 + 0x1e) & 0x3f)];

    }

    else {

      if (bVar3 == 2) {

        uVar21 = (ulonglong)(ushort)*puVar18;

        goto LAB_14029bc98;

      }

      if (bVar3 != 3) {

        if (bVar3 != 4) {

          uVar24 = 0;

          uVar14 = 0;

          uVar23 = uVar16;

          goto LAB_14029bcf1;

        }

        uVar16 = *puVar18;

        uVar21 = (ulonglong)uVar16;

        bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

                [(*(uint *)(lVar11 + 8) & uVar16) >> (*(byte *)(lVar11 + 0x1c) & 0x3f)];

        bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

                [(*(uint *)(lVar11 + 0xc) & uVar16) >> (*(byte *)(lVar11 + 0x1d) & 0x3f)];

        uVar17 = (ulonglong)(*(uint *)(lVar11 + 0x10) & uVar16);

        goto LAB_14029bcdb;

      }

      uVar23 = 0;

      uVar24 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) + (longlong)puVar18);

      uVar16 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) + (longlong)puVar18);

      uVar14 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) + (longlong)puVar18);

    }

LAB_14029bcf1:

    if (uVar23 != uVar9) {

      pbVar2 = (byte *)(lVar13 + (ulonglong)*pbVar20 * 4);

      uVar24 = (uVar24 - *pbVar2) * (ushort)bVar4 + (ushort)*pbVar2 * 0xff + 1;

      uVar24 = (uVar24 >> 8) + uVar24;

      uVar22 = ((short)uVar16 - (ushort)pbVar2[1]) * (ushort)bVar4 + (ushort)pbVar2[1] * 0xff + 1;

      uVar22 = (uVar22 >> 8) + uVar22;

      uVar14 = (uVar14 - pbVar2[2]) * (ushort)bVar4 + (ushort)pbVar2[2] * 0xff + 1;

      uVar14 = (uVar14 >> 8) + uVar14;

      if (lVar12 == 0) {

        *pbVar20 = ((byte)(uVar22 >> 0xb) | (byte)(uVar24 >> 8) & 0xe3) & 0xfc |

                   (byte)(uVar14 >> 0xe);

      }

      else {

        *pbVar20 = *(byte *)((((ulonglong)(uVar22 >> 8) & 0xffffffe0 | (ulonglong)(uVar14 >> 0xb))

                              >> 3 | (ulonglong)(uVar24 >> 8) & 0xffffffe0) + lVar12);

      }

    }

    puVar18 = (uint *)((longlong)puVar18 + (longlong)(int)uVar19);

    pbVar20 = pbVar20 + 1;

LAB_14029bde7:

    uVar16 = 0;

    if (bVar3 == 1) {

      uVar21 = (ulonglong)(byte)*puVar18;

LAB_14029be91:

      bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

              [(*(uint *)(lVar11 + 8) & uVar21) >> (*(byte *)(lVar11 + 0x1c) & 0x3f)];

      bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

              [(*(uint *)(lVar11 + 0xc) & uVar21) >> (*(byte *)(lVar11 + 0x1d) & 0x3f)];

      uVar17 = *(uint *)(lVar11 + 0x10) & uVar21;

LAB_14029bed4:

      uVar24 = (ushort)bVar6;

      uVar16 = (uint)bVar5;

      uVar23 = (uint)uVar21;

      uVar14 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1a)]

                             [uVar17 >> (*(byte *)(lVar11 + 0x1e) & 0x3f)];

    }

    else {

      if (bVar3 == 2) {

        uVar21 = (ulonglong)(ushort)*puVar18;

        goto LAB_14029be91;

      }

      if (bVar3 != 3) {

        if (bVar3 != 4) {

          uVar24 = 0;

          uVar14 = 0;

          uVar23 = uVar16;

          goto LAB_14029beea;

        }

        uVar16 = *puVar18;

        uVar21 = (ulonglong)uVar16;

        bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

                [(*(uint *)(lVar11 + 8) & uVar16) >> (*(byte *)(lVar11 + 0x1c) & 0x3f)];

        bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

                [(*(uint *)(lVar11 + 0xc) & uVar16) >> (*(byte *)(lVar11 + 0x1d) & 0x3f)];

        uVar17 = (ulonglong)(*(uint *)(lVar11 + 0x10) & uVar16);

        goto LAB_14029bed4;

      }

      uVar23 = 0;

      uVar24 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) + (longlong)puVar18);

      uVar16 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) + (longlong)puVar18);

      uVar14 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) + (longlong)puVar18);

    }

LAB_14029beea:

    if (uVar23 != uVar9) {

      pbVar2 = (byte *)(lVar13 + (ulonglong)*pbVar20 * 4);

      uVar24 = (uVar24 - *pbVar2) * (ushort)bVar4 + (ushort)*pbVar2 * 0xff + 1;

      uVar24 = (uVar24 >> 8) + uVar24;

      uVar22 = ((short)uVar16 - (ushort)pbVar2[1]) * (ushort)bVar4 + (ushort)pbVar2[1] * 0xff + 1;

      uVar22 = (uVar22 >> 8) + uVar22;

      uVar14 = (uVar14 - pbVar2[2]) * (ushort)bVar4 + (ushort)pbVar2[2] * 0xff + 1;

      uVar14 = (uVar14 >> 8) + uVar14;

      if (lVar12 == 0) {

        *pbVar20 = ((byte)(uVar22 >> 0xb) | (byte)(uVar24 >> 8) & 0xe3) & 0xfc |

                   (byte)(uVar14 >> 0xe);

      }

      else {

        *pbVar20 = *(byte *)((((ulonglong)(uVar22 >> 8) & 0xffffffe0 | (ulonglong)(uVar14 >> 0xb))

                              >> 3 | (ulonglong)(uVar24 >> 8) & 0xffffffe0) + lVar12);

      }

    }

    pbVar20 = pbVar20 + 1;

    puVar18 = (uint *)((longlong)puVar18 + (ulonglong)bVar3);

    iVar25 = iVar25 + -1;

    if (iVar25 < 1) goto LAB_14029bff6;

LAB_14029b7f7:

    uVar24 = 0;

    if (bVar3 == 1) {

      uVar21 = (ulonglong)(byte)*puVar18;

LAB_14029b8a4:

      bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

              [(*(uint *)(lVar11 + 8) & uVar21) >> (*(byte *)(lVar11 + 0x1c) & 0x3f)];

      bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

              [(*(uint *)(lVar11 + 0xc) & uVar21) >> (*(byte *)(lVar11 + 0x1d) & 0x3f)];

      uVar17 = *(uint *)(lVar11 + 0x10) & uVar21;

LAB_14029b8ec:

      uVar24 = (ushort)bVar5;

      uVar14 = (ushort)bVar6;

      uVar16 = (uint)uVar21;

      uVar22 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1a)]

                             [uVar17 >> (*(byte *)(lVar11 + 0x1e) & 0x3f)];

    }

    else {

      if (bVar3 == 2) {

        uVar21 = (ulonglong)(ushort)*puVar18;

        goto LAB_14029b8a4;

      }

      if (bVar3 != 3) {

        if (bVar3 != 4) {

          uVar16 = 0;

          uVar14 = 0;

          uVar22 = 0;

          goto LAB_14029b902;

        }

        uVar16 = *puVar18;

        uVar21 = (ulonglong)uVar16;

        bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

                [(*(uint *)(lVar11 + 8) & uVar16) >> (*(byte *)(lVar11 + 0x1c) & 0x3f)];

        bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

                [(*(uint *)(lVar11 + 0xc) & uVar16) >> (*(byte *)(lVar11 + 0x1d) & 0x3f)];

        uVar17 = (ulonglong)(*(uint *)(lVar11 + 0x10) & uVar16);

        goto LAB_14029b8ec;

      }

      uVar16 = 0;

      uVar14 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) + (longlong)puVar18);

      uVar24 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) + (longlong)puVar18);

      uVar22 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) + (longlong)puVar18);

    }

LAB_14029b902:

    if (uVar16 != uVar9) {

      bVar6 = *(byte *)(lVar13 + (ulonglong)*pbVar20 * 4);

      lVar1 = lVar13 + (ulonglong)*pbVar20 * 4;

      uVar14 = (uVar14 - bVar6) * (ushort)bVar4 + (ushort)bVar6 * 0xff + 1;

      bVar6 = *(byte *)(lVar1 + 1);

      uVar14 = (uVar14 >> 8) + uVar14;

      uVar24 = (uVar24 - bVar6) * (ushort)bVar4 + (ushort)bVar6 * 0xff + 1;

      bVar6 = *(byte *)(lVar1 + 2);

      uVar24 = (uVar24 >> 8) + uVar24;

      uVar22 = (uVar22 - bVar6) * (ushort)bVar4 + (ushort)bVar6 * 0xff + 1;

      uVar22 = (uVar22 >> 8) + uVar22;

      if (lVar12 == 0) {

        *pbVar20 = ((byte)(uVar24 >> 0xb) | (byte)(uVar14 >> 8) & 0xe3) & 0xfc |

                   (byte)(uVar22 >> 0xe);

      }

      else {

        *pbVar20 = *(byte *)((((ulonglong)(uVar24 >> 8) & 0xffffffe0 | (ulonglong)(uVar22 >> 0xb))

                              >> 3 | (ulonglong)(uVar14 >> 8) & 0xffffffe0) + lVar12);

      }

    }

    puVar18 = (uint *)((longlong)puVar18 + (longlong)(int)uVar19);

    pbVar20 = pbVar20 + 1;

  } while( true );

}




