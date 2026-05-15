// Address: 0x14029a780
// Ghidra name: FUN_14029a780
// ============ 0x14029a780 FUN_14029a780 (size=2111) ============


void FUN_14029a780(longlong param_1)



{

  longlong lVar1;

  byte bVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  byte bVar9;

  ushort uVar10;

  ushort uVar11;

  int iVar12;

  uint uVar13;

  byte *pbVar14;

  uint uVar15;

  ushort uVar16;

  ulonglong uVar17;

  ushort uVar18;

  ushort uVar19;

  uint *puVar20;

  int iVar21;

  

  iVar3 = *(int *)(param_1 + 0x1c);

  lVar6 = *(longlong *)(param_1 + 0x48);

  uVar4 = *(uint *)(param_1 + 0x38);

  puVar20 = *(uint **)(param_1 + 8);

  pbVar14 = *(byte **)(param_1 + 0x30);

  lVar7 = *(longlong *)(param_1 + 0x68);

  bVar2 = *(byte *)(lVar6 + 5);

  iVar5 = *(int *)(param_1 + 0x44);

  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x60) + 8);

  iVar12 = *(int *)(param_1 + 0x3c);

  while( true ) {

    if (iVar12 == 0) {

      return;

    }

    iVar21 = uVar4 + 3;

    iVar21 = (int)((iVar21 >> 0x1f & 3U) + iVar21) >> 2;

    uVar13 = uVar4 & 3;

    uVar15 = (uint)bVar2;

    if (uVar13 == 0) goto LAB_14029a828;

    if (uVar13 == 1) goto LAB_14029adb0;

    if (uVar13 == 2) goto LAB_14029abd8;

    if (uVar13 == 3) break;

LAB_14029af99:

    puVar20 = (uint *)((longlong)puVar20 + (longlong)iVar3);

    pbVar14 = pbVar14 + iVar5;

    iVar12 = iVar12 + -1;

  }

  do {

    uVar16 = 0;

    if (bVar2 == 1) {

      uVar17 = (ulonglong)(byte)*puVar20;

LAB_14029aa66:

      uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x1b)]

                             [(*(uint *)(lVar6 + 0x14) & uVar17) >> (*(byte *)(lVar6 + 0x1f) & 0x3f)

                             ];

      uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x18)]

                             [(*(uint *)(lVar6 + 8) & uVar17) >> (*(byte *)(lVar6 + 0x1c) & 0x3f)];

      uVar16 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x19)]

                             [(*(uint *)(lVar6 + 0xc) & uVar17) >> (*(byte *)(lVar6 + 0x1d) & 0x3f)]

      ;

      uVar11 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x1a)]

                             [(*(uint *)(lVar6 + 0x10) & uVar17) >> (*(byte *)(lVar6 + 0x1e) & 0x3f)

                             ];

    }

    else {

      if (bVar2 == 2) {

        uVar17 = (ulonglong)(ushort)*puVar20;

        goto LAB_14029aa66;

      }

      if (bVar2 == 3) {

        uVar18 = 0xff;

        uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar6 + 0x1c) >> 3) + (longlong)puVar20);

        uVar16 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar6 + 0x1d) >> 3) + (longlong)puVar20);

        uVar11 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar6 + 0x1e) >> 3) + (longlong)puVar20);

      }

      else {

        if (bVar2 == 4) {

          uVar17 = (ulonglong)*puVar20;

          goto LAB_14029aa66;

        }

        uVar18 = 0;

        uVar11 = 0;

        uVar19 = uVar16;

      }

    }

    lVar1 = (ulonglong)*pbVar14 * 4;

    uVar19 = (uVar19 - *(byte *)(lVar1 + lVar8)) * uVar18 +

             (ushort)*(byte *)(lVar1 + lVar8) * 0xff + 1;

    uVar10 = (ushort)*(byte *)(lVar1 + 1 + lVar8);

    uVar16 = (uVar16 - uVar10) * uVar18 + uVar10 * 0xff + 1;

    uVar10 = (ushort)*(byte *)(lVar1 + 2 + lVar8);

    uVar19 = (uVar19 >> 8) + uVar19;

    uVar11 = (uVar11 - uVar10) * uVar18 + uVar10 * 0xff + 1;

    uVar16 = (uVar16 >> 8) + uVar16;

    uVar11 = (uVar11 >> 8) + uVar11;

    if (lVar7 == 0) {

      bVar9 = ((byte)(uVar16 >> 0xb) | (byte)(uVar19 >> 8) & 0xe3) & 0xfc | (byte)(uVar11 >> 0xe);

    }

    else {

      bVar9 = *(byte *)((((ulonglong)(uVar16 >> 8) & 0xffffffe0 | (ulonglong)(uVar11 >> 0xb)) >> 3 |

                        (ulonglong)(uVar19 >> 8) & 0xffffffe0) + lVar7);

    }

    *pbVar14 = bVar9;

    puVar20 = (uint *)((longlong)puVar20 + (longlong)(int)uVar15);

    pbVar14 = pbVar14 + 1;

LAB_14029abd8:

    uVar16 = 0;

    if (bVar2 == 1) {

      uVar17 = (ulonglong)(byte)*puVar20;

LAB_14029ac3e:

      uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x1b)]

                             [(*(uint *)(lVar6 + 0x14) & uVar17) >> (*(byte *)(lVar6 + 0x1f) & 0x3f)

                             ];

      uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x18)]

                             [(*(uint *)(lVar6 + 8) & uVar17) >> (*(byte *)(lVar6 + 0x1c) & 0x3f)];

      uVar16 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x19)]

                             [(*(uint *)(lVar6 + 0xc) & uVar17) >> (*(byte *)(lVar6 + 0x1d) & 0x3f)]

      ;

      uVar11 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x1a)]

                             [(*(uint *)(lVar6 + 0x10) & uVar17) >> (*(byte *)(lVar6 + 0x1e) & 0x3f)

                             ];

    }

    else {

      if (bVar2 == 2) {

        uVar17 = (ulonglong)(ushort)*puVar20;

        goto LAB_14029ac3e;

      }

      if (bVar2 == 3) {

        uVar18 = 0xff;

        uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar6 + 0x1c) >> 3) + (longlong)puVar20);

        uVar16 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar6 + 0x1d) >> 3) + (longlong)puVar20);

        uVar11 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar6 + 0x1e) >> 3) + (longlong)puVar20);

      }

      else {

        if (bVar2 == 4) {

          uVar17 = (ulonglong)*puVar20;

          goto LAB_14029ac3e;

        }

        uVar18 = 0;

        uVar11 = 0;

        uVar19 = uVar16;

      }

    }

    lVar1 = (ulonglong)*pbVar14 * 4;

    uVar19 = (uVar19 - *(byte *)(lVar1 + lVar8)) * uVar18 +

             (ushort)*(byte *)(lVar1 + lVar8) * 0xff + 1;

    uVar10 = (ushort)*(byte *)(lVar1 + 1 + lVar8);

    uVar16 = (uVar16 - uVar10) * uVar18 + uVar10 * 0xff + 1;

    uVar10 = (ushort)*(byte *)(lVar1 + 2 + lVar8);

    uVar19 = (uVar19 >> 8) + uVar19;

    uVar11 = (uVar11 - uVar10) * uVar18 + uVar10 * 0xff + 1;

    uVar16 = (uVar16 >> 8) + uVar16;

    uVar11 = (uVar11 >> 8) + uVar11;

    if (lVar7 == 0) {

      bVar9 = ((byte)(uVar16 >> 0xb) | (byte)(uVar19 >> 8) & 0xe3) & 0xfc | (byte)(uVar11 >> 0xe);

    }

    else {

      bVar9 = *(byte *)((((ulonglong)(uVar16 >> 8) & 0xffffffe0 | (ulonglong)(uVar11 >> 0xb)) >> 3 |

                        (ulonglong)(uVar19 >> 8) & 0xffffffe0) + lVar7);

    }

    *pbVar14 = bVar9;

    puVar20 = (uint *)((longlong)puVar20 + (longlong)(int)uVar15);

    pbVar14 = pbVar14 + 1;

LAB_14029adb0:

    uVar16 = 0;

    if (bVar2 == 1) {

      uVar17 = (ulonglong)(byte)*puVar20;

LAB_14029ae16:

      uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x1b)]

                             [(*(uint *)(lVar6 + 0x14) & uVar17) >> (*(byte *)(lVar6 + 0x1f) & 0x3f)

                             ];

      uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x18)]

                             [(*(uint *)(lVar6 + 8) & uVar17) >> (*(byte *)(lVar6 + 0x1c) & 0x3f)];

      uVar16 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x19)]

                             [(*(uint *)(lVar6 + 0xc) & uVar17) >> (*(byte *)(lVar6 + 0x1d) & 0x3f)]

      ;

      uVar11 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x1a)]

                             [(*(uint *)(lVar6 + 0x10) & uVar17) >> (*(byte *)(lVar6 + 0x1e) & 0x3f)

                             ];

    }

    else {

      if (bVar2 == 2) {

        uVar17 = (ulonglong)(ushort)*puVar20;

        goto LAB_14029ae16;

      }

      if (bVar2 == 3) {

        uVar18 = 0xff;

        uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar6 + 0x1c) >> 3) + (longlong)puVar20);

        uVar16 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar6 + 0x1d) >> 3) + (longlong)puVar20);

        uVar11 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar6 + 0x1e) >> 3) + (longlong)puVar20);

      }

      else {

        if (bVar2 == 4) {

          uVar17 = (ulonglong)*puVar20;

          goto LAB_14029ae16;

        }

        uVar18 = 0;

        uVar11 = 0;

        uVar19 = uVar16;

      }

    }

    lVar1 = (ulonglong)*pbVar14 * 4;

    uVar19 = (uVar19 - *(byte *)(lVar1 + lVar8)) * uVar18 +

             (ushort)*(byte *)(lVar1 + lVar8) * 0xff + 1;

    bVar9 = *(byte *)(lVar1 + 1 + lVar8);

    uVar16 = (uVar16 - bVar9) * uVar18 + (ushort)bVar9 * 0xff + 1;

    bVar9 = *(byte *)(lVar1 + 2 + lVar8);

    uVar19 = (uVar19 >> 8) + uVar19;

    uVar11 = (uVar11 - bVar9) * uVar18 + (ushort)bVar9 * 0xff + 1;

    uVar16 = (uVar16 >> 8) + uVar16;

    uVar11 = (uVar11 >> 8) + uVar11;

    if (lVar7 == 0) {

      bVar9 = ((byte)(uVar16 >> 0xb) | (byte)(uVar19 >> 8) & 0xe3) & 0xfc | (byte)(uVar11 >> 0xe);

    }

    else {

      bVar9 = *(byte *)((((ulonglong)(uVar16 >> 8) & 0xffffffe0 | (ulonglong)(uVar11 >> 0xb)) >> 3 |

                        (ulonglong)(uVar19 >> 8) & 0xffffffe0) + lVar7);

    }

    *pbVar14 = bVar9;

    pbVar14 = pbVar14 + 1;

    puVar20 = (uint *)((longlong)puVar20 + (ulonglong)bVar2);

    iVar21 = iVar21 + -1;

    if (iVar21 < 1) goto LAB_14029af99;

LAB_14029a828:

    uVar16 = 0;

    if (bVar2 == 1) {

      uVar17 = (ulonglong)(byte)*puVar20;

LAB_14029a88e:

      uVar16 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x1b)]

                             [(*(uint *)(lVar6 + 0x14) & uVar17) >> (*(byte *)(lVar6 + 0x1f) & 0x3f)

                             ];

      uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x18)]

                             [(*(uint *)(lVar6 + 8) & uVar17) >> (*(byte *)(lVar6 + 0x1c) & 0x3f)];

      uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x19)]

                             [(*(uint *)(lVar6 + 0xc) & uVar17) >> (*(byte *)(lVar6 + 0x1d) & 0x3f)]

      ;

      uVar11 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar6 + 0x1a)]

                             [(*(uint *)(lVar6 + 0x10) & uVar17) >> (*(byte *)(lVar6 + 0x1e) & 0x3f)

                             ];

    }

    else {

      if (bVar2 == 2) {

        uVar17 = (ulonglong)(ushort)*puVar20;

        goto LAB_14029a88e;

      }

      if (bVar2 == 3) {

        uVar16 = 0xff;

        uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar6 + 0x1c) >> 3) + (longlong)puVar20);

        uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar6 + 0x1d) >> 3) + (longlong)puVar20);

        uVar11 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar6 + 0x1e) >> 3) + (longlong)puVar20);

      }

      else {

        if (bVar2 == 4) {

          uVar17 = (ulonglong)*puVar20;

          goto LAB_14029a88e;

        }

        uVar18 = 0;

        uVar11 = 0;

        uVar19 = uVar16;

      }

    }

    lVar1 = (ulonglong)*pbVar14 * 4;

    uVar18 = (uVar18 - *(byte *)(lVar1 + lVar8)) * uVar16 +

             (ushort)*(byte *)(lVar1 + lVar8) * 0xff + 1;

    uVar10 = (ushort)*(byte *)(lVar1 + 1 + lVar8);

    uVar19 = (uVar19 - uVar10) * uVar16 + uVar10 * 0xff + 1;

    uVar10 = (ushort)*(byte *)(lVar1 + 2 + lVar8);

    uVar18 = (uVar18 >> 8) + uVar18;

    uVar16 = (uVar11 - uVar10) * uVar16 + uVar10 * 0xff + 1;

    uVar19 = (uVar19 >> 8) + uVar19;

    uVar16 = (uVar16 >> 8) + uVar16;

    if (lVar7 == 0) {

      bVar9 = ((byte)(uVar19 >> 0xb) | (byte)(uVar18 >> 8) & 0xe3) & 0xfc | (byte)(uVar16 >> 0xe);

    }

    else {

      bVar9 = *(byte *)((((ulonglong)(uVar19 >> 8) & 0xffffffe0 | (ulonglong)(uVar16 >> 0xb)) >> 3 |

                        (ulonglong)(uVar18 >> 8) & 0xffffffe0) + lVar7);

    }

    *pbVar14 = bVar9;

    puVar20 = (uint *)((longlong)puVar20 + (longlong)(int)uVar15);

    pbVar14 = pbVar14 + 1;

  } while( true );

}




