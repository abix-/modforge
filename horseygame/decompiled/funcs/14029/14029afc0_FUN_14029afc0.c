// Address: 0x14029afc0
// Ghidra name: FUN_14029afc0
// ============ 0x14029afc0 FUN_14029afc0 (size=1913) ============


void FUN_14029afc0(longlong param_1)



{

  longlong lVar1;

  byte bVar2;

  byte bVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  byte bVar10;

  ushort uVar11;

  ushort uVar12;

  int iVar13;

  uint uVar14;

  uint *puVar15;

  uint uVar16;

  byte *pbVar17;

  ulonglong uVar18;

  ushort uVar19;

  ushort uVar20;

  int iVar21;

  

  iVar4 = *(int *)(param_1 + 0x1c);

  lVar7 = *(longlong *)(param_1 + 0x48);

  bVar2 = *(byte *)(param_1 + 0x83);

  uVar5 = *(uint *)(param_1 + 0x38);

  puVar15 = *(uint **)(param_1 + 8);

  pbVar17 = *(byte **)(param_1 + 0x30);

  lVar8 = *(longlong *)(param_1 + 0x68);

  bVar3 = *(byte *)(lVar7 + 5);

  iVar6 = *(int *)(param_1 + 0x44);

  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x60) + 8);

  iVar13 = *(int *)(param_1 + 0x3c);

  while( true ) {

    if (iVar13 == 0) {

      return;

    }

    iVar21 = uVar5 + 3;

    iVar21 = (int)((iVar21 >> 0x1f & 3U) + iVar21) >> 2;

    uVar14 = uVar5 & 3;

    uVar16 = (uint)bVar3;

    if (uVar14 == 0) goto LAB_14029b067;

    if (uVar14 == 1) goto LAB_14029b559;

    if (uVar14 == 2) goto LAB_14029b3b3;

    if (uVar14 == 3) break;

LAB_14029b710:

    puVar15 = (uint *)((longlong)puVar15 + (longlong)iVar4);

    pbVar17 = pbVar17 + iVar6;

    iVar13 = iVar13 + -1;

  }

  do {

    uVar19 = 0;

    if (bVar3 == 1) {

      uVar18 = (ulonglong)(byte)*puVar15;

LAB_14029b269:

      uVar20 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                             [(*(uint *)(lVar7 + 8) & uVar18) >> (*(byte *)(lVar7 + 0x1c) & 0x3f)];

      uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                             [(*(uint *)(lVar7 + 0xc) & uVar18) >> (*(byte *)(lVar7 + 0x1d) & 0x3f)]

      ;

      uVar12 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                             [(*(uint *)(lVar7 + 0x10) & uVar18) >> (*(byte *)(lVar7 + 0x1e) & 0x3f)

                             ];

    }

    else {

      if (bVar3 == 2) {

        uVar18 = (ulonglong)(ushort)*puVar15;

        goto LAB_14029b269;

      }

      if (bVar3 == 3) {

        uVar20 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar15);

        uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar15);

        uVar12 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar15);

      }

      else {

        if (bVar3 == 4) {

          uVar18 = (ulonglong)*puVar15;

          goto LAB_14029b269;

        }

        uVar12 = 0;

        uVar20 = uVar19;

      }

    }

    lVar1 = (ulonglong)*pbVar17 * 4;

    uVar20 = (uVar20 - *(byte *)(lVar1 + lVar9)) * (ushort)bVar2 +

             (ushort)*(byte *)(lVar1 + lVar9) * 0xff + 1;

    uVar11 = (ushort)*(byte *)(lVar1 + 1 + lVar9);

    uVar20 = (uVar20 >> 8) + uVar20;

    uVar19 = (uVar19 - uVar11) * (ushort)bVar2 + uVar11 * 0xff + 1;

    uVar11 = (ushort)*(byte *)(lVar1 + 2 + lVar9);

    uVar19 = (uVar19 >> 8) + uVar19;

    uVar12 = (uVar12 - uVar11) * (ushort)bVar2 + uVar11 * 0xff + 1;

    uVar12 = (uVar12 >> 8) + uVar12;

    if (lVar8 == 0) {

      bVar10 = ((byte)(uVar19 >> 0xb) | (byte)(uVar20 >> 8) & 0xe3) & 0xfc | (byte)(uVar12 >> 0xe);

    }

    else {

      bVar10 = *(byte *)((((ulonglong)(uVar19 >> 8) & 0xffffffe0 | (ulonglong)(uVar12 >> 0xb)) >> 3

                         | (ulonglong)(uVar20 >> 8) & 0xffffffe0) + lVar8);

    }

    *pbVar17 = bVar10;

    puVar15 = (uint *)((longlong)puVar15 + (longlong)(int)uVar16);

    pbVar17 = pbVar17 + 1;

LAB_14029b3b3:

    uVar19 = 0;

    if (bVar3 == 1) {

      uVar18 = (ulonglong)(byte)*puVar15;

LAB_14029b40f:

      uVar20 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                             [(*(uint *)(lVar7 + 8) & uVar18) >> (*(byte *)(lVar7 + 0x1c) & 0x3f)];

      uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                             [(*(uint *)(lVar7 + 0xc) & uVar18) >> (*(byte *)(lVar7 + 0x1d) & 0x3f)]

      ;

      uVar12 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                             [(*(uint *)(lVar7 + 0x10) & uVar18) >> (*(byte *)(lVar7 + 0x1e) & 0x3f)

                             ];

    }

    else {

      if (bVar3 == 2) {

        uVar18 = (ulonglong)(ushort)*puVar15;

        goto LAB_14029b40f;

      }

      if (bVar3 == 3) {

        uVar20 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar15);

        uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar15);

        uVar12 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar15);

      }

      else {

        if (bVar3 == 4) {

          uVar18 = (ulonglong)*puVar15;

          goto LAB_14029b40f;

        }

        uVar12 = 0;

        uVar20 = uVar19;

      }

    }

    lVar1 = (ulonglong)*pbVar17 * 4;

    uVar20 = (uVar20 - *(byte *)(lVar1 + lVar9)) * (ushort)bVar2 +

             (ushort)*(byte *)(lVar1 + lVar9) * 0xff + 1;

    uVar11 = (ushort)*(byte *)(lVar1 + 1 + lVar9);

    uVar20 = (uVar20 >> 8) + uVar20;

    uVar19 = (uVar19 - uVar11) * (ushort)bVar2 + uVar11 * 0xff + 1;

    uVar11 = (ushort)*(byte *)(lVar1 + 2 + lVar9);

    uVar19 = (uVar19 >> 8) + uVar19;

    uVar12 = (uVar12 - uVar11) * (ushort)bVar2 + uVar11 * 0xff + 1;

    uVar12 = (uVar12 >> 8) + uVar12;

    if (lVar8 == 0) {

      bVar10 = ((byte)(uVar19 >> 0xb) | (byte)(uVar20 >> 8) & 0xe3) & 0xfc | (byte)(uVar12 >> 0xe);

    }

    else {

      bVar10 = *(byte *)((((ulonglong)(uVar19 >> 8) & 0xffffffe0 | (ulonglong)(uVar12 >> 0xb)) >> 3

                         | (ulonglong)(uVar20 >> 8) & 0xffffffe0) + lVar8);

    }

    *pbVar17 = bVar10;

    puVar15 = (uint *)((longlong)puVar15 + (longlong)(int)uVar16);

    pbVar17 = pbVar17 + 1;

LAB_14029b559:

    uVar19 = 0;

    if (bVar3 == 1) {

      uVar18 = (ulonglong)(byte)*puVar15;

LAB_14029b5b5:

      uVar20 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                             [(*(uint *)(lVar7 + 8) & uVar18) >> (*(byte *)(lVar7 + 0x1c) & 0x3f)];

      uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                             [(*(uint *)(lVar7 + 0xc) & uVar18) >> (*(byte *)(lVar7 + 0x1d) & 0x3f)]

      ;

      uVar12 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                             [(*(uint *)(lVar7 + 0x10) & uVar18) >> (*(byte *)(lVar7 + 0x1e) & 0x3f)

                             ];

    }

    else {

      if (bVar3 == 2) {

        uVar18 = (ulonglong)(ushort)*puVar15;

        goto LAB_14029b5b5;

      }

      if (bVar3 == 3) {

        uVar20 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar15);

        uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar15);

        uVar12 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar15);

      }

      else {

        if (bVar3 == 4) {

          uVar18 = (ulonglong)*puVar15;

          goto LAB_14029b5b5;

        }

        uVar12 = 0;

        uVar20 = uVar19;

      }

    }

    lVar1 = (ulonglong)*pbVar17 * 4;

    uVar20 = (uVar20 - *(byte *)(lVar1 + lVar9)) * (ushort)bVar2 +

             (ushort)*(byte *)(lVar1 + lVar9) * 0xff + 1;

    bVar10 = *(byte *)(lVar1 + 1 + lVar9);

    uVar20 = (uVar20 >> 8) + uVar20;

    uVar19 = (uVar19 - bVar10) * (ushort)bVar2 + (ushort)bVar10 * 0xff + 1;

    bVar10 = *(byte *)(lVar1 + 2 + lVar9);

    uVar19 = (uVar19 >> 8) + uVar19;

    uVar12 = (uVar12 - bVar10) * (ushort)bVar2 + (ushort)bVar10 * 0xff + 1;

    uVar12 = (uVar12 >> 8) + uVar12;

    if (lVar8 == 0) {

      bVar10 = ((byte)(uVar19 >> 0xb) | (byte)(uVar20 >> 8) & 0xe3) & 0xfc | (byte)(uVar12 >> 0xe);

    }

    else {

      bVar10 = *(byte *)((((ulonglong)(uVar19 >> 8) & 0xffffffe0 | (ulonglong)(uVar12 >> 0xb)) >> 3

                         | (ulonglong)(uVar20 >> 8) & 0xffffffe0) + lVar8);

    }

    *pbVar17 = bVar10;

    puVar15 = (uint *)((longlong)puVar15 + (ulonglong)bVar3);

    pbVar17 = pbVar17 + 1;

    iVar21 = iVar21 + -1;

    if (iVar21 < 1) goto LAB_14029b710;

LAB_14029b067:

    uVar19 = 0;

    if (bVar3 == 1) {

      uVar18 = (ulonglong)(byte)*puVar15;

LAB_14029b0c3:

      uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                             [(*(uint *)(lVar7 + 8) & uVar18) >> (*(byte *)(lVar7 + 0x1c) & 0x3f)];

      uVar20 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                             [(*(uint *)(lVar7 + 0xc) & uVar18) >> (*(byte *)(lVar7 + 0x1d) & 0x3f)]

      ;

      uVar12 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                             [(*(uint *)(lVar7 + 0x10) & uVar18) >> (*(byte *)(lVar7 + 0x1e) & 0x3f)

                             ];

    }

    else {

      if (bVar3 == 2) {

        uVar18 = (ulonglong)(ushort)*puVar15;

        goto LAB_14029b0c3;

      }

      if (bVar3 == 3) {

        uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar15);

        uVar20 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar15);

        uVar12 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar15);

      }

      else {

        if (bVar3 == 4) {

          uVar18 = (ulonglong)*puVar15;

          goto LAB_14029b0c3;

        }

        uVar12 = 0;

        uVar20 = uVar19;

      }

    }

    lVar1 = (ulonglong)*pbVar17 * 4;

    uVar19 = (uVar19 - *(byte *)(lVar1 + lVar9)) * (ushort)bVar2 +

             (ushort)*(byte *)(lVar1 + lVar9) * 0xff + 1;

    uVar11 = (ushort)*(byte *)(lVar1 + 1 + lVar9);

    uVar19 = (uVar19 >> 8) + uVar19;

    uVar20 = (uVar20 - uVar11) * (ushort)bVar2 + uVar11 * 0xff + 1;

    uVar11 = (ushort)*(byte *)(lVar1 + 2 + lVar9);

    uVar20 = (uVar20 >> 8) + uVar20;

    uVar12 = (uVar12 - uVar11) * (ushort)bVar2 + uVar11 * 0xff + 1;

    uVar12 = (uVar12 >> 8) + uVar12;

    if (lVar8 == 0) {

      bVar10 = ((byte)(uVar20 >> 0xb) | (byte)(uVar19 >> 8) & 0xe3) & 0xfc | (byte)(uVar12 >> 0xe);

    }

    else {

      bVar10 = *(byte *)((((ulonglong)(uVar20 >> 8) & 0xffffffe0 | (ulonglong)(uVar12 >> 0xb)) >> 3

                         | (ulonglong)(uVar19 >> 8) & 0xffffffe0) + lVar8);

    }

    *pbVar17 = bVar10;

    puVar15 = (uint *)((longlong)puVar15 + (longlong)(int)uVar16);

    pbVar17 = pbVar17 + 1;

  } while( true );

}




