// Address: 0x140295af0
// Ghidra name: FUN_140295af0
// ============ 0x140295af0 FUN_140295af0 (size=1411) ============


void FUN_140295af0(longlong param_1)



{

  byte *pbVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  byte bVar6;

  uint uVar7;

  uint *puVar8;

  uint *puVar9;

  uint uVar10;

  uint uVar11;

  ulonglong uVar12;

  uint *puVar13;

  uint uVar14;

  longlong lVar15;

  int iVar16;

  uint uVar17;

  uint *puVar18;

  longlong lVar19;

  ulonglong uVar20;

  uint uVar21;

  longlong lVar22;

  longlong lVar23;

  longlong lVar24;

  int iVar25;

  uint uVar26;

  longlong lVar27;

  int local_res10 [2];

  int local_res18 [2];

  int local_res20 [2];

  int local_58 [6];

  

  puVar8 = *(uint **)(param_1 + 0x48);

  puVar9 = *(uint **)(param_1 + 0x58);

  uVar7 = *(uint *)(param_1 + 0x38);

  iVar25 = *(int *)(param_1 + 0x3c);

  bVar2 = *(byte *)((longlong)puVar8 + 5);

  puVar18 = *(uint **)(param_1 + 8);

  lVar15 = (longlong)*(int *)(param_1 + 0x1c);

  puVar13 = *(uint **)(param_1 + 0x30);

  lVar27 = (longlong)*(int *)(param_1 + 0x44);

  bVar3 = *(byte *)((longlong)puVar9 + 5);

  uVar10 = (uint)bVar3;

  if ((((bVar2 == 4) && (uVar10 == 4)) &&

      ((uVar26 = *puVar8, uVar26 == 0 ||

       ((((uVar26 & 0xf0000000) != 0x10000000 || ((uVar26 & 0xf000000) != 0x6000000)) ||

        ((uVar26 & 0xf0000) != 0x70000)))))) &&

     (((uVar26 = *puVar9, uVar26 == 0 || ((uVar26 & 0xf0000000) != 0x10000000)) ||

      (((uVar26 & 0xf000000) != 0x6000000 || ((uVar26 & 0xf0000) != 0x70000)))))) {

    FUN_140298ae0(puVar8,puVar9,local_58,local_res20,local_res18,local_res10,0);

    lVar19 = (longlong)local_res10[0];

    lVar22 = (longlong)local_res18[0];

    lVar23 = (longlong)local_res20[0];

    lVar24 = (longlong)local_58[0];

    while (iVar25 != 0) {

      iVar16 = (int)(((int)(uVar7 + 3) >> 0x1f & 3U) + uVar7 + 3) >> 2;

      uVar10 = uVar7 & 3;

      if (uVar10 == 0) goto LAB_140295c59;

      if (uVar10 == 1) goto LAB_140295cce;

      if (uVar10 == 2) goto LAB_140295ca7;

      if (uVar10 == 3) {

        while( true ) {

          *(byte *)puVar13 = *(byte *)(lVar24 + (longlong)puVar18);

          *(byte *)((longlong)puVar13 + 1) = *(byte *)(lVar23 + (longlong)puVar18);

          *(byte *)((longlong)puVar13 + 2) = *(byte *)(lVar22 + (longlong)puVar18);

          pbVar1 = (byte *)(lVar19 + (longlong)puVar18);

          puVar18 = puVar18 + 1;

          *(byte *)((longlong)puVar13 + 3) = *pbVar1;

          puVar13 = puVar13 + 1;

LAB_140295ca7:

          *(byte *)puVar13 = *(byte *)(lVar24 + (longlong)puVar18);

          *(byte *)((longlong)puVar13 + 1) = *(byte *)(lVar23 + (longlong)puVar18);

          *(byte *)((longlong)puVar13 + 2) = *(byte *)(lVar22 + (longlong)puVar18);

          pbVar1 = (byte *)(lVar19 + (longlong)puVar18);

          puVar18 = puVar18 + 1;

          *(byte *)((longlong)puVar13 + 3) = *pbVar1;

          puVar13 = puVar13 + 1;

LAB_140295cce:

          iVar16 = iVar16 + -1;

          *(byte *)puVar13 = *(byte *)(lVar24 + (longlong)puVar18);

          *(byte *)((longlong)puVar13 + 1) = *(byte *)(lVar23 + (longlong)puVar18);

          *(byte *)((longlong)puVar13 + 2) = *(byte *)(lVar22 + (longlong)puVar18);

          pbVar1 = (byte *)(lVar19 + (longlong)puVar18);

          puVar18 = puVar18 + 1;

          *(byte *)((longlong)puVar13 + 3) = *pbVar1;

          puVar13 = puVar13 + 1;

          if (iVar16 < 1) break;

LAB_140295c59:

          *(byte *)puVar13 = *(byte *)(lVar24 + (longlong)puVar18);

          *(byte *)((longlong)puVar13 + 1) = *(byte *)(lVar23 + (longlong)puVar18);

          *(byte *)((longlong)puVar13 + 2) = *(byte *)(lVar22 + (longlong)puVar18);

          pbVar1 = (byte *)(lVar19 + (longlong)puVar18);

          puVar18 = puVar18 + 1;

          *(byte *)((longlong)puVar13 + 3) = *pbVar1;

          puVar13 = puVar13 + 1;

        }

        puVar18 = (uint *)((longlong)puVar18 + lVar15);

        puVar13 = (uint *)((longlong)puVar13 + lVar27);

        iVar25 = iVar25 + -1;

      }

      else {

        puVar18 = (uint *)((longlong)puVar18 + lVar15);

        puVar13 = (uint *)((longlong)puVar13 + lVar27);

        iVar25 = iVar25 + -1;

      }

    }

  }

  else {

    while (iVar25 != 0) {

      iVar25 = iVar25 + -1;

      if (uVar7 != 0) {

        uVar20 = (ulonglong)(int)uVar10;

        uVar26 = uVar7;

        do {

          if (bVar2 == 1) {

            uVar12 = (ulonglong)(byte)*puVar18;

            bVar4 = (&PTR_DAT_1403e28a0)[(byte)puVar8[6]]

                    [(puVar8[2] & uVar12) >> ((byte)puVar8[7] & 0x3f)];

            bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar8 + 0x19)]

                    [(puVar8[3] & uVar12) >> (*(byte *)((longlong)puVar8 + 0x1d) & 0x3f)];

            bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar8 + 0x1a)]

                    [(puVar8[4] & uVar12) >> (*(byte *)((longlong)puVar8 + 0x1e) & 0x3f)];

            uVar12 = puVar8[5] & uVar12;

            uVar20 = (ulonglong)bVar3;

LAB_140295e83:

            uVar21 = (uint)bVar6;

            uVar17 = (uint)bVar5;

            uVar14 = (uint)bVar4;

            uVar11 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar8 + 0x1b)]

                                 [uVar12 >> (*(byte *)((longlong)puVar8 + 0x1f) & 0x3f)];

          }

          else {

            if (bVar2 == 2) {

              uVar12 = (ulonglong)(ushort)*puVar18;

LAB_140295d81:

              bVar4 = (&PTR_DAT_1403e28a0)[(byte)puVar8[6]]

                      [(puVar8[2] & uVar12) >> ((byte)puVar8[7] & 0x3f)];

              bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar8 + 0x19)]

                      [(puVar8[3] & uVar12) >> (*(byte *)((longlong)puVar8 + 0x1d) & 0x3f)];

              bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar8 + 0x1a)]

                      [(puVar8[4] & uVar12) >> (*(byte *)((longlong)puVar8 + 0x1e) & 0x3f)];

              uVar12 = puVar8[5] & uVar12;

              uVar20 = (longlong)(int)uVar10;

              goto LAB_140295e83;

            }

            if (bVar2 == 3) {

              uVar11 = 0xff;

              uVar14 = (uint)*(byte *)((ulonglong)(byte)((byte)puVar8[7] >> 3) + (longlong)puVar18);

              uVar17 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar8 + 0x1d) >> 3) +

                                      (longlong)puVar18);

              uVar21 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar8 + 0x1e) >> 3) +

                                      (longlong)puVar18);

            }

            else {

              if (bVar2 == 4) {

                uVar12 = (ulonglong)*puVar18;

                goto LAB_140295d81;

              }

              uVar11 = 0;

              uVar21 = 0;

              uVar17 = 0;

              uVar14 = 0;

            }

          }

          if (bVar3 == 1) {

            *(char *)puVar13 =

                 (char)(uVar11 >> (8U - *(char *)((longlong)puVar9 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar9 + 0x1f) & 0x1f) |

                 (char)(uVar21 >> (8U - *(char *)((longlong)puVar9 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar9 + 0x1e) & 0x1f) |

                 (char)(uVar17 >> (8U - *(char *)((longlong)puVar9 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar9 + 0x1d) & 0x1f) |

                 (char)(uVar14 >> (8U - (char)puVar9[6] & 0x1f)) << ((byte)puVar9[7] & 0x1f);

          }

          else if (bVar3 == 2) {

            *(short *)puVar13 =

                 (short)(uVar11 >> (8U - *(char *)((longlong)puVar9 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar9 + 0x1f) & 0x1f) |

                 (short)(uVar21 >> (8U - *(char *)((longlong)puVar9 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar9 + 0x1e) & 0x1f) |

                 (short)(uVar17 >> (8U - *(char *)((longlong)puVar9 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar9 + 0x1d) & 0x1f) |

                 (short)(uVar14 >> (8U - (char)puVar9[6] & 0x1f)) << ((byte)puVar9[7] & 0x1f);

          }

          else if (bVar3 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar9[7] >> 3) + (longlong)puVar13) = (byte)uVar14;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar9 + 0x1d) >> 3) + (longlong)puVar13) =

                 (byte)uVar17;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar9 + 0x1e) >> 3) + (longlong)puVar13) =

                 (byte)uVar21;

          }

          else if (bVar3 == 4) {

            *puVar13 = (uVar11 >> (8U - *(char *)((longlong)puVar9 + 0x1b) & 0x1f)) <<

                       (*(byte *)((longlong)puVar9 + 0x1f) & 0x1f) |

                       (uVar21 >> (8U - *(char *)((longlong)puVar9 + 0x1a) & 0x1f)) <<

                       (*(byte *)((longlong)puVar9 + 0x1e) & 0x1f) |

                       (uVar17 >> (8U - *(char *)((longlong)puVar9 + 0x19) & 0x1f)) <<

                       (*(byte *)((longlong)puVar9 + 0x1d) & 0x1f) |

                       (uVar14 >> (8U - (char)puVar9[6] & 0x1f)) << ((byte)puVar9[7] & 0x1f);

          }

          puVar13 = (uint *)((longlong)puVar13 + uVar20);

          puVar18 = (uint *)((longlong)puVar18 + (ulonglong)bVar2);

          uVar26 = uVar26 - 1;

        } while (uVar26 != 0);

      }

      puVar18 = (uint *)((longlong)puVar18 + lVar15);

      puVar13 = (uint *)((longlong)puVar13 + lVar27);

    }

  }

  return;

}




