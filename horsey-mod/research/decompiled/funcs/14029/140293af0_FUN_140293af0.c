// Address: 0x140293af0
// Ghidra name: FUN_140293af0
// ============ 0x140293af0 FUN_140293af0 (size=3828) ============


void FUN_140293af0(longlong param_1)



{

  byte *pbVar1;

  byte bVar2;

  byte bVar3;

  uint uVar4;

  uint *puVar5;

  uint *puVar6;

  uint uVar7;

  uint uVar8;

  uint *puVar9;

  uint uVar10;

  ulonglong uVar11;

  longlong lVar12;

  uint *puVar13;

  longlong lVar14;

  uint uVar15;

  longlong lVar16;

  longlong lVar17;

  longlong lVar18;

  byte bVar19;

  int iVar20;

  int iVar21;

  uint uVar22;

  uint uVar23;

  int local_res8 [2];

  int local_res10;

  uint local_res18 [2];

  uint local_res20 [2];

  int local_58;

  int local_54;

  int local_50 [4];

  

  puVar5 = *(uint **)(param_1 + 0x58);

  puVar6 = *(uint **)(param_1 + 0x48);

  local_res18[0] = *(uint *)(param_1 + 0x1c);

  uVar11 = (ulonglong)(int)local_res18[0];

  uVar4 = *(uint *)(param_1 + 0x38);

  local_res10 = *(int *)(param_1 + 0x44);

  iVar21 = *(int *)(param_1 + 0x3c);

  puVar13 = *(uint **)(param_1 + 8);

  puVar9 = *(uint **)(param_1 + 0x30);

  bVar2 = *(byte *)((longlong)puVar6 + 5);

  bVar3 = *(byte *)((longlong)puVar5 + 5);

  if (puVar5[5] == 0) {

    uVar7 = 0;

  }

  else {

    uVar7 = (uint)*(byte *)(param_1 + 0x83);

  }

  uVar23 = (uint)bVar3;

  bVar19 = (byte)uVar7;

  local_res20[0] = uVar4;

  if ((((bVar2 == 4) && (uVar23 == 4)) &&

      ((uVar8 = *puVar6, uVar8 == 0 ||

       ((((uVar8 & 0xf0000000) != 0x10000000 || ((uVar8 & 0xf000000) != 0x6000000)) ||

        ((uVar8 & 0xf0000) != 0x70000)))))) &&

     (((uVar8 = *puVar5, uVar8 == 0 || ((uVar8 & 0xf0000000) != 0x10000000)) ||

      (((uVar8 & 0xf000000) != 0x6000000 || ((uVar8 & 0xf0000) != 0x70000)))))) {

    FUN_140298ae0(puVar6,puVar5,local_50,&local_54,&local_58,local_res20,local_res8);

    lVar14 = (longlong)local_res8[0];

    lVar16 = (longlong)(int)local_res20[0];

    lVar17 = (longlong)local_58;

    lVar18 = (longlong)local_54;

    lVar12 = (longlong)local_50[0];

    while (iVar21 != 0) {

      iVar20 = (int)(((int)(uVar4 + 3) >> 0x1f & 3U) + uVar4 + 3) >> 2;

      uVar7 = uVar4 & 3;

      if (uVar7 == 0) goto LAB_140293c5d;

      if (uVar7 == 1) goto LAB_140293cdb;

      if (uVar7 == 2) goto LAB_140293cb1;

      if (uVar7 == 3) {

        while( true ) {

          *(byte *)puVar9 = *(byte *)(lVar12 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 1) = *(byte *)(lVar18 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 2) = *(byte *)(lVar17 + (longlong)puVar13);

          pbVar1 = (byte *)(lVar16 + (longlong)puVar13);

          puVar13 = puVar13 + 1;

          *(byte *)((longlong)puVar9 + 3) = *pbVar1;

          *(byte *)(lVar14 + (longlong)puVar9) = bVar19;

          puVar9 = puVar9 + 1;

LAB_140293cb1:

          *(byte *)puVar9 = *(byte *)(lVar12 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 1) = *(byte *)(lVar18 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 2) = *(byte *)(lVar17 + (longlong)puVar13);

          pbVar1 = (byte *)(lVar16 + (longlong)puVar13);

          puVar13 = puVar13 + 1;

          *(byte *)((longlong)puVar9 + 3) = *pbVar1;

          *(byte *)(lVar14 + (longlong)puVar9) = bVar19;

          puVar9 = puVar9 + 1;

LAB_140293cdb:

          iVar20 = iVar20 + -1;

          *(byte *)puVar9 = *(byte *)(lVar12 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 1) = *(byte *)(lVar18 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 2) = *(byte *)(lVar17 + (longlong)puVar13);

          pbVar1 = (byte *)(lVar16 + (longlong)puVar13);

          puVar13 = puVar13 + 1;

          *(byte *)((longlong)puVar9 + 3) = *pbVar1;

          *(byte *)(lVar14 + (longlong)puVar9) = bVar19;

          puVar9 = puVar9 + 1;

          if (iVar20 < 1) break;

LAB_140293c5d:

          *(byte *)puVar9 = *(byte *)(lVar12 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 1) = *(byte *)(lVar18 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 2) = *(byte *)(lVar17 + (longlong)puVar13);

          pbVar1 = (byte *)(lVar16 + (longlong)puVar13);

          puVar13 = puVar13 + 1;

          *(byte *)((longlong)puVar9 + 3) = *pbVar1;

          *(byte *)(lVar14 + (longlong)puVar9) = bVar19;

          puVar9 = puVar9 + 1;

        }

        puVar13 = (uint *)((longlong)puVar13 + (longlong)(int)local_res18[0]);

        puVar9 = (uint *)((longlong)puVar9 + (longlong)local_res10);

        iVar21 = iVar21 + -1;

      }

      else {

        puVar13 = (uint *)((longlong)puVar13 + (longlong)(int)local_res18[0]);

        puVar9 = (uint *)((longlong)puVar9 + (longlong)local_res10);

        iVar21 = iVar21 + -1;

      }

    }

  }

  else if (bVar2 == 4) {

    if ((bVar3 != 3) ||

       (((uVar8 = *puVar6, uVar8 != 0 && ((uVar8 & 0xf0000000) == 0x10000000)) &&

        (((uVar8 & 0xf000000) == 0x6000000 && ((uVar8 & 0xf0000) == 0x70000)))))) {

LAB_140294030:

      if (iVar21 == 0) {

        return;

      }

      iVar20 = (int)(((int)(uVar4 + 3) >> 0x1f & 3U) + uVar4 + 3) >> 2;

      uVar8 = uVar4 & 3;

      uVar15 = (uint)bVar2;

      if (uVar8 == 0) goto LAB_14029407a;

      if (uVar8 == 1) goto LAB_14029476a;

      if (uVar8 == 2) goto LAB_14029451a;

      if (uVar8 == 3) {

        do {

          if (uVar15 == 1) {

            uVar11 = (ulonglong)(byte)*puVar13;

LAB_140294326:

            uVar22 = (uint)(byte)(&PTR_DAT_1403e28a0)[(byte)puVar6[6]]

                                 [(puVar6[2] & uVar11) >> ((byte)puVar6[7] & 0x3f)];

            uVar10 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar6 + 0x19)]

                                 [(puVar6[3] & uVar11) >>

                                  (*(byte *)((longlong)puVar6 + 0x1d) & 0x3f)];

            uVar8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar6 + 0x1a)]

                                [(puVar6[4] & uVar11) >> (*(byte *)((longlong)puVar6 + 0x1e) & 0x3f)

                                ];

          }

          else {

            if (uVar15 == 2) {

              uVar11 = (ulonglong)(ushort)*puVar13;

              goto LAB_140294326;

            }

            if (uVar15 == 3) {

              uVar22 = (uint)*(byte *)((ulonglong)(byte)((byte)puVar6[7] >> 3) + (longlong)puVar13);

              uVar10 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar6 + 0x1d) >> 3) +

                                      (longlong)puVar13);

              uVar8 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar6 + 0x1e) >> 3) +

                                     (longlong)puVar13);

            }

            else {

              if (uVar15 == 4) {

                uVar11 = (ulonglong)*puVar13;

                goto LAB_140294326;

              }

              uVar8 = 0;

              uVar10 = 0;

              uVar22 = 0;

            }

          }

          if (bVar3 == 1) {

            *(char *)puVar9 =

                 (char)(uVar8 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                 (char)(uVar10 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (char)(uVar22 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (char)(uVar7 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

          else if (bVar3 == 2) {

            *(short *)puVar9 =

                 (short)(uVar8 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                 (short)(uVar10 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (short)(uVar22 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (short)(uVar7 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

          else if (bVar3 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar5[7] >> 3) + (longlong)puVar9) = (byte)uVar22;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1d) >> 3) + (longlong)puVar9) =

                 (byte)uVar10;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1e) >> 3) + (longlong)puVar9) =

                 (byte)uVar8;

          }

          else if (bVar3 == 4) {

            *puVar9 = (uVar8 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                      (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                      (uVar10 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                      (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                      (uVar22 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                      (uVar7 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                      (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

          puVar9 = (uint *)((longlong)puVar9 + (longlong)(int)uVar23);

          puVar13 = (uint *)((longlong)puVar13 + (longlong)(int)uVar15);

LAB_14029451a:

          if (uVar15 == 1) {

            uVar11 = (ulonglong)(byte)*puVar13;

LAB_140294576:

            uVar22 = (uint)(byte)(&PTR_DAT_1403e28a0)[(byte)puVar6[6]]

                                 [(puVar6[2] & uVar11) >> ((byte)puVar6[7] & 0x3f)];

            uVar10 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar6 + 0x19)]

                                 [(puVar6[3] & uVar11) >>

                                  (*(byte *)((longlong)puVar6 + 0x1d) & 0x3f)];

            uVar8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar6 + 0x1a)]

                                [(puVar6[4] & uVar11) >> (*(byte *)((longlong)puVar6 + 0x1e) & 0x3f)

                                ];

          }

          else {

            if (uVar15 == 2) {

              uVar11 = (ulonglong)(ushort)*puVar13;

              goto LAB_140294576;

            }

            if (uVar15 == 3) {

              uVar22 = (uint)*(byte *)((ulonglong)(byte)((byte)puVar6[7] >> 3) + (longlong)puVar13);

              uVar10 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar6 + 0x1d) >> 3) +

                                      (longlong)puVar13);

              uVar8 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar6 + 0x1e) >> 3) +

                                     (longlong)puVar13);

            }

            else {

              if (uVar15 == 4) {

                uVar11 = (ulonglong)*puVar13;

                goto LAB_140294576;

              }

              uVar8 = 0;

              uVar10 = 0;

              uVar22 = 0;

            }

          }

          if (bVar3 == 1) {

            *(char *)puVar9 =

                 (char)(uVar8 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                 (char)(uVar10 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (char)(uVar22 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (char)(uVar7 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

          else if (bVar3 == 2) {

            *(short *)puVar9 =

                 (short)(uVar8 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                 (short)(uVar10 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (short)(uVar22 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (short)(uVar7 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

          else if (bVar3 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar5[7] >> 3) + (longlong)puVar9) = (byte)uVar22;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1d) >> 3) + (longlong)puVar9) =

                 (byte)uVar10;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1e) >> 3) + (longlong)puVar9) =

                 (byte)uVar8;

          }

          else if (bVar3 == 4) {

            *puVar9 = (uVar8 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                      (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                      (uVar10 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                      (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                      (uVar22 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                      (uVar7 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                      (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

          puVar9 = (uint *)((longlong)puVar9 + (longlong)(int)uVar23);

          puVar13 = (uint *)((longlong)puVar13 + (longlong)(int)uVar15);

LAB_14029476a:

          if (uVar15 == 1) {

            uVar11 = (ulonglong)(byte)*puVar13;

LAB_1402947c6:

            uVar22 = (uint)(byte)(&PTR_DAT_1403e28a0)[(byte)puVar6[6]]

                                 [(puVar6[2] & uVar11) >> ((byte)puVar6[7] & 0x3f)];

            uVar10 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar6 + 0x19)]

                                 [(puVar6[3] & uVar11) >>

                                  (*(byte *)((longlong)puVar6 + 0x1d) & 0x3f)];

            uVar8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar6 + 0x1a)]

                                [(puVar6[4] & uVar11) >> (*(byte *)((longlong)puVar6 + 0x1e) & 0x3f)

                                ];

          }

          else {

            if (uVar15 == 2) {

              uVar11 = (ulonglong)(ushort)*puVar13;

              goto LAB_1402947c6;

            }

            if (uVar15 == 3) {

              uVar22 = (uint)*(byte *)((ulonglong)(byte)((byte)puVar6[7] >> 3) + (longlong)puVar13);

              uVar10 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar6 + 0x1d) >> 3) +

                                      (longlong)puVar13);

              uVar8 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar6 + 0x1e) >> 3) +

                                     (longlong)puVar13);

            }

            else {

              if (uVar15 == 4) {

                uVar11 = (ulonglong)*puVar13;

                goto LAB_1402947c6;

              }

              uVar8 = 0;

              uVar10 = 0;

              uVar22 = 0;

            }

          }

          if (bVar3 == 1) {

            *(char *)puVar9 =

                 (char)(uVar8 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                 (char)(uVar10 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (char)(uVar22 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (char)(uVar7 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

          else if (bVar3 == 2) {

            *(short *)puVar9 =

                 (short)(uVar8 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                 (short)(uVar10 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (short)(uVar22 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (short)(uVar7 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

          else if (bVar3 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar5[7] >> 3) + (longlong)puVar9) = (byte)uVar22;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1d) >> 3) + (longlong)puVar9) =

                 (byte)uVar10;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1e) >> 3) + (longlong)puVar9) =

                 (byte)uVar8;

          }

          else if (bVar3 == 4) {

            *puVar9 = (uVar8 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                      (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                      (uVar10 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                      (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                      (uVar22 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                      (uVar7 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                      (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

          puVar9 = (uint *)((longlong)puVar9 + (ulonglong)bVar3);

          puVar13 = (uint *)((longlong)puVar13 + (ulonglong)bVar2);

          iVar20 = iVar20 + -1;

          if (iVar20 < 1) goto code_r0x0001402949c0;

LAB_14029407a:

          if (uVar15 == 1) {

            uVar11 = (ulonglong)(byte)*puVar13;

LAB_1402940d6:

            uVar22 = (uint)(byte)(&PTR_DAT_1403e28a0)[(byte)puVar6[6]]

                                 [(puVar6[2] & uVar11) >> ((byte)puVar6[7] & 0x3f)];

            uVar10 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar6 + 0x19)]

                                 [(puVar6[3] & uVar11) >>

                                  (*(byte *)((longlong)puVar6 + 0x1d) & 0x3f)];

            uVar8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar6 + 0x1a)]

                                [(puVar6[4] & uVar11) >> (*(byte *)((longlong)puVar6 + 0x1e) & 0x3f)

                                ];

          }

          else {

            if (uVar15 == 2) {

              uVar11 = (ulonglong)(ushort)*puVar13;

              goto LAB_1402940d6;

            }

            if (uVar15 == 3) {

              uVar22 = (uint)*(byte *)((ulonglong)(byte)((byte)puVar6[7] >> 3) + (longlong)puVar13);

              uVar10 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar6 + 0x1d) >> 3) +

                                      (longlong)puVar13);

              uVar8 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar6 + 0x1e) >> 3) +

                                     (longlong)puVar13);

            }

            else {

              if (uVar15 == 4) {

                uVar11 = (ulonglong)*puVar13;

                goto LAB_1402940d6;

              }

              uVar8 = 0;

              uVar10 = 0;

              uVar22 = 0;

            }

          }

          if (bVar3 == 1) {

            *(char *)puVar9 =

                 (char)(uVar8 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                 (char)(uVar10 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (char)(uVar22 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (char)(uVar7 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

          else if (bVar3 == 2) {

            *(short *)puVar9 =

                 (short)(uVar8 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                 (short)(uVar10 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                 (short)(uVar22 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                 (short)(uVar7 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

          else if (bVar3 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar5[7] >> 3) + (longlong)puVar9) = (byte)uVar22;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1d) >> 3) + (longlong)puVar9) =

                 (byte)uVar10;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar5 + 0x1e) >> 3) + (longlong)puVar9) =

                 (byte)uVar8;

          }

          else if (bVar3 == 4) {

            *puVar9 = (uVar8 >> (8U - *(char *)((longlong)puVar5 + 0x1a) & 0x1f)) <<

                      (*(byte *)((longlong)puVar5 + 0x1e) & 0x1f) |

                      (uVar10 >> (8U - *(char *)((longlong)puVar5 + 0x19) & 0x1f)) <<

                      (*(byte *)((longlong)puVar5 + 0x1d) & 0x1f) |

                      (uVar22 >> (8U - (char)puVar5[6] & 0x1f)) << ((byte)puVar5[7] & 0x1f) |

                      (uVar7 >> (8U - *(char *)((longlong)puVar5 + 0x1b) & 0x1f)) <<

                      (*(byte *)((longlong)puVar5 + 0x1f) & 0x1f);

          }

          puVar9 = (uint *)((longlong)puVar9 + (longlong)(int)uVar23);

          puVar13 = (uint *)((longlong)puVar13 + (longlong)(int)uVar15);

        } while( true );

      }

      goto LAB_1402949c7;

    }

    FUN_140298ae0(puVar6,puVar5,local_res20,local_res18,local_res8,local_50,0);

    lVar12 = (longlong)local_res8[0];

    lVar14 = (longlong)(int)local_res18[0];

    lVar16 = (longlong)(int)local_res20[0];

    while (iVar21 != 0) {

      iVar20 = (int)(((int)(uVar4 + 3) >> 0x1f & 3U) + uVar4 + 3) >> 2;

      uVar7 = uVar4 & 3;

      if (uVar7 == 0) goto LAB_140293dee;

      if (uVar7 == 1) goto LAB_140293e4b;

      if (uVar7 == 2) goto LAB_140293e2c;

      if (uVar7 == 3) {

        while( true ) {

          *(byte *)puVar9 = *(byte *)(lVar16 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 1) = *(byte *)(lVar14 + (longlong)puVar13);

          pbVar1 = (byte *)(lVar12 + (longlong)puVar13);

          puVar13 = puVar13 + 1;

          *(byte *)((longlong)puVar9 + 2) = *pbVar1;

          puVar9 = (uint *)((longlong)puVar9 + 3);

LAB_140293e2c:

          *(byte *)puVar9 = *(byte *)(lVar16 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 1) = *(byte *)(lVar14 + (longlong)puVar13);

          pbVar1 = (byte *)(lVar12 + (longlong)puVar13);

          puVar13 = puVar13 + 1;

          *(byte *)((longlong)puVar9 + 2) = *pbVar1;

          puVar9 = (uint *)((longlong)puVar9 + 3);

LAB_140293e4b:

          iVar20 = iVar20 + -1;

          *(byte *)puVar9 = *(byte *)(lVar16 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 1) = *(byte *)(lVar14 + (longlong)puVar13);

          pbVar1 = (byte *)(lVar12 + (longlong)puVar13);

          puVar13 = puVar13 + 1;

          *(byte *)((longlong)puVar9 + 2) = *pbVar1;

          puVar9 = (uint *)((longlong)puVar9 + 3);

          if (iVar20 < 1) break;

LAB_140293dee:

          *(byte *)puVar9 = *(byte *)(lVar16 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 1) = *(byte *)(lVar14 + (longlong)puVar13);

          pbVar1 = (byte *)(lVar12 + (longlong)puVar13);

          puVar13 = puVar13 + 1;

          *(byte *)((longlong)puVar9 + 2) = *pbVar1;

          puVar9 = (uint *)((longlong)puVar9 + 3);

        }

        puVar13 = (uint *)((longlong)puVar13 + uVar11);

        puVar9 = (uint *)((longlong)puVar9 + (longlong)local_res10);

        iVar21 = iVar21 + -1;

      }

      else {

        puVar13 = (uint *)((longlong)puVar13 + uVar11);

        puVar9 = (uint *)((longlong)puVar9 + (longlong)local_res10);

        iVar21 = iVar21 + -1;

      }

    }

  }

  else {

    if (((bVar2 != 3) || (bVar3 != 4)) ||

       ((uVar8 = *puVar5, uVar8 != 0 &&

        ((((uVar8 & 0xf0000000) == 0x10000000 && ((uVar8 & 0xf000000) == 0x6000000)) &&

         ((uVar8 & 0xf0000) == 0x70000)))))) goto LAB_140294030;

    FUN_140298ae0(puVar6,puVar5,&local_58,&local_54,local_50,local_res20,local_res8);

    lVar14 = (longlong)local_res8[0];

    lVar16 = (longlong)(int)local_res20[0];

    lVar17 = (longlong)local_50[0];

    lVar18 = (longlong)local_54;

    lVar12 = (longlong)local_58;

    while (iVar21 != 0) {

      iVar20 = (int)(((int)(uVar4 + 3) >> 0x1f & 3U) + uVar4 + 3) >> 2;

      uVar7 = uVar4 & 3;

      if (uVar7 == 0) goto LAB_140293f5f;

      if (uVar7 == 1) goto LAB_140293fdd;

      if (uVar7 == 2) goto LAB_140293fb3;

      if (uVar7 == 3) {

        while( true ) {

          *(byte *)puVar9 = *(byte *)(lVar12 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 1) = *(byte *)(lVar18 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 2) = *(byte *)(lVar17 + (longlong)puVar13);

          pbVar1 = (byte *)(lVar16 + (longlong)puVar13);

          puVar13 = (uint *)((longlong)puVar13 + 3);

          *(byte *)((longlong)puVar9 + 3) = *pbVar1;

          *(byte *)(lVar14 + (longlong)puVar9) = bVar19;

          puVar9 = puVar9 + 1;

LAB_140293fb3:

          *(byte *)puVar9 = *(byte *)(lVar12 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 1) = *(byte *)(lVar18 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 2) = *(byte *)(lVar17 + (longlong)puVar13);

          pbVar1 = (byte *)(lVar16 + (longlong)puVar13);

          puVar13 = (uint *)((longlong)puVar13 + 3);

          *(byte *)((longlong)puVar9 + 3) = *pbVar1;

          *(byte *)(lVar14 + (longlong)puVar9) = bVar19;

          puVar9 = puVar9 + 1;

LAB_140293fdd:

          iVar20 = iVar20 + -1;

          *(byte *)puVar9 = *(byte *)(lVar12 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 1) = *(byte *)(lVar18 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 2) = *(byte *)(lVar17 + (longlong)puVar13);

          pbVar1 = (byte *)(lVar16 + (longlong)puVar13);

          puVar13 = (uint *)((longlong)puVar13 + 3);

          *(byte *)((longlong)puVar9 + 3) = *pbVar1;

          *(byte *)(lVar14 + (longlong)puVar9) = bVar19;

          puVar9 = puVar9 + 1;

          if (iVar20 < 1) break;

LAB_140293f5f:

          *(byte *)puVar9 = *(byte *)(lVar12 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 1) = *(byte *)(lVar18 + (longlong)puVar13);

          *(byte *)((longlong)puVar9 + 2) = *(byte *)(lVar17 + (longlong)puVar13);

          pbVar1 = (byte *)(lVar16 + (longlong)puVar13);

          puVar13 = (uint *)((longlong)puVar13 + 3);

          *(byte *)((longlong)puVar9 + 3) = *pbVar1;

          *(byte *)(lVar14 + (longlong)puVar9) = bVar19;

          puVar9 = puVar9 + 1;

        }

        puVar13 = (uint *)((longlong)puVar13 + (longlong)(int)local_res18[0]);

        puVar9 = (uint *)((longlong)puVar9 + (longlong)local_res10);

        iVar21 = iVar21 + -1;

      }

      else {

        puVar13 = (uint *)((longlong)puVar13 + (longlong)(int)local_res18[0]);

        puVar9 = (uint *)((longlong)puVar9 + (longlong)local_res10);

        iVar21 = iVar21 + -1;

      }

    }

  }

  return;

code_r0x0001402949c0:

  uVar11 = (ulonglong)local_res18[0];

LAB_1402949c7:

  puVar13 = (uint *)((longlong)puVar13 + (longlong)(int)uVar11);

  puVar9 = (uint *)((longlong)puVar9 + (longlong)local_res10);

  iVar21 = iVar21 + -1;

  goto LAB_140294030;

}




