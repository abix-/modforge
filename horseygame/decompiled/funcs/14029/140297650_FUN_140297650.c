// Address: 0x140297650
// Ghidra name: FUN_140297650
// ============ 0x140297650 FUN_140297650 (size=4317) ============


void FUN_140297650(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  uint uVar6;

  uint *puVar7;

  uint *puVar8;

  uint uVar9;

  ulonglong uVar10;

  uint *puVar11;

  uint uVar12;

  uint uVar13;

  uint *puVar14;

  int iVar15;

  longlong lVar16;

  uint uVar17;

  longlong lVar18;

  longlong lVar19;

  longlong lVar20;

  uint uVar21;

  ulonglong uVar22;

  ulonglong uVar23;

  int iVar24;

  uint uVar25;

  uint uVar26;

  int local_res8 [2];

  int local_res10;

  int local_res18 [2];

  int local_res20 [2];

  uint local_58;

  uint local_54;

  

  puVar7 = *(uint **)(param_1 + 0x48);

  puVar8 = *(uint **)(param_1 + 0x58);

  uVar6 = *(uint *)(param_1 + 0x38);

  local_54 = *(uint *)(param_1 + 0x1c);

  uVar22 = (ulonglong)(int)local_54;

  local_res10 = *(int *)(param_1 + 0x44);

  iVar24 = *(int *)(param_1 + 0x3c);

  uVar13 = ~puVar7[5];

  puVar11 = *(uint **)(param_1 + 8);

  uVar12 = *(uint *)(param_1 + 0x7c) & uVar13;

  puVar14 = *(uint **)(param_1 + 0x30);

  bVar1 = *(byte *)((longlong)puVar8 + 5);

  uVar9 = *puVar8;

  uVar17 = *puVar7;

  bVar2 = *(byte *)((longlong)puVar7 + 5);

  uVar23 = (ulonglong)bVar2;

  local_res8[0] = CONCAT31(local_res8[0]._1_3_,bVar1);

  if (uVar17 == uVar9) {

    if ((uVar17 + 0xe9c9dffc & 0xffafffff) == 0) {

      while (iVar24 != 0) {

        iVar15 = (int)(((int)(uVar6 + 7) >> 0x1f & 7U) + uVar6 + 7) >> 3;

        switch(uVar6 & 7) {

        case 0:

          do {

            if ((*puVar11 & uVar13) != uVar12) {

              *puVar14 = *puVar11;

            }

            puVar11 = puVar11 + 1;

            puVar14 = puVar14 + 1;

switchD_140297712_caseD_7:

            if ((*puVar11 & uVar13) != uVar12) {

              *puVar14 = *puVar11;

            }

            puVar11 = puVar11 + 1;

            puVar14 = puVar14 + 1;

switchD_140297712_caseD_6:

            if ((*puVar11 & uVar13) != uVar12) {

              *puVar14 = *puVar11;

            }

            puVar11 = puVar11 + 1;

            puVar14 = puVar14 + 1;

switchD_140297712_caseD_5:

            if ((*puVar11 & uVar13) != uVar12) {

              *puVar14 = *puVar11;

            }

            puVar11 = puVar11 + 1;

            puVar14 = puVar14 + 1;

switchD_140297712_caseD_4:

            if ((*puVar11 & uVar13) != uVar12) {

              *puVar14 = *puVar11;

            }

            puVar11 = puVar11 + 1;

            puVar14 = puVar14 + 1;

switchD_140297712_caseD_3:

            if ((*puVar11 & uVar13) != uVar12) {

              *puVar14 = *puVar11;

            }

            puVar11 = puVar11 + 1;

            puVar14 = puVar14 + 1;

switchD_140297712_caseD_2:

            if ((*puVar11 & uVar13) != uVar12) {

              *puVar14 = *puVar11;

            }

            puVar11 = puVar11 + 1;

            puVar14 = puVar14 + 1;

switchD_140297712_caseD_1:

            if ((*puVar11 & uVar13) != uVar12) {

              *puVar14 = *puVar11;

            }

            puVar11 = puVar11 + 1;

            puVar14 = puVar14 + 1;

            iVar15 = iVar15 + -1;

          } while (0 < iVar15);

          break;

        case 1:

          goto switchD_140297712_caseD_1;

        case 2:

          goto switchD_140297712_caseD_2;

        case 3:

          goto switchD_140297712_caseD_3;

        case 4:

          goto switchD_140297712_caseD_4;

        case 5:

          goto switchD_140297712_caseD_5;

        case 6:

          goto switchD_140297712_caseD_6;

        case 7:

          goto switchD_140297712_caseD_7;

        }

        puVar11 = (uint *)((longlong)puVar11 + uVar22);

        puVar14 = (uint *)((longlong)puVar14 + (longlong)local_res10);

        iVar24 = iVar24 + -1;

      }

    }

  }

  else {

    if ((((bVar2 != 4) || (bVar1 != 4)) ||

        ((uVar17 != 0 &&

         ((((uVar17 & 0xf0000000) == 0x10000000 && ((uVar17 & 0xf000000) == 0x6000000)) &&

          ((uVar17 & 0xf0000) == 0x70000)))))) ||

       (((uVar9 != 0 && ((uVar9 & 0xf0000000) == 0x10000000)) &&

        (((uVar9 & 0xf000000) == 0x6000000 && ((uVar9 & 0xf0000) == 0x70000)))))) {

LAB_1402979d0:

      while( true ) {

        if (iVar24 == 0) {

          return;

        }

        local_res18[0] = (int)(uVar6 + 3 + ((int)(uVar6 + 3) >> 0x1f & 3U)) >> 2;

        uVar9 = uVar6 & 3;

        if (uVar9 == 0) goto LAB_140297a30;

        if (uVar9 == 1) goto LAB_1402983ae;

        if (uVar9 == 2) goto LAB_140298084;

        if (uVar9 == 3) break;

        puVar11 = (uint *)((longlong)puVar11 + (longlong)(int)uVar22);

        puVar14 = (uint *)((longlong)puVar14 + (longlong)local_res10);

        iVar24 = iVar24 + -1;

      }

      do {

        if (bVar2 == 1) {

          uVar22 = (ulonglong)(byte)*puVar11;

LAB_140297e43:

          bVar3 = (&PTR_DAT_1403e28a0)[(byte)puVar7[6]]

                  [(puVar7[2] & uVar22) >> ((byte)puVar7[7] & 0x3f)];

          bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x19)]

                  [(puVar7[3] & uVar22) >> (*(byte *)((longlong)puVar7 + 0x1d) & 0x3f)];

          bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x1a)]

                  [(puVar7[4] & uVar22) >> (*(byte *)((longlong)puVar7 + 0x1e) & 0x3f)];

          uVar10 = puVar7[5] & uVar22;

LAB_140297eb9:

          uVar17 = (uint)bVar5;

          uVar26 = (uint)bVar3;

          uVar25 = (uint)bVar4;

          uVar21 = (uint)uVar22;

          uVar9 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x1b)]

                              [uVar10 >> (*(byte *)((longlong)puVar7 + 0x1f) & 0x3f)];

        }

        else {

          if (bVar2 == 2) {

            uVar22 = (ulonglong)(ushort)*puVar11;

            goto LAB_140297e43;

          }

          if (bVar2 != 3) {

            if (bVar2 != 4) {

              uVar21 = 0;

              uVar9 = 0;

              uVar17 = 0;

              uVar25 = 0;

              uVar26 = 0;

              goto LAB_140297ed9;

            }

            uVar9 = *puVar11;

            uVar22 = (ulonglong)uVar9;

            bVar3 = (&PTR_DAT_1403e28a0)[(byte)puVar7[6]]

                    [(puVar7[2] & uVar9) >> ((byte)puVar7[7] & 0x3f)];

            bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x19)]

                    [(puVar7[3] & uVar9) >> (*(byte *)((longlong)puVar7 + 0x1d) & 0x3f)];

            bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x1a)]

                    [(puVar7[4] & uVar9) >> (*(byte *)((longlong)puVar7 + 0x1e) & 0x3f)];

            uVar10 = (ulonglong)(puVar7[5] & uVar9);

            goto LAB_140297eb9;

          }

          uVar21 = 0;

          uVar9 = 0xff;

          uVar26 = (uint)*(byte *)((ulonglong)(byte)((byte)puVar7[7] >> 3) + (longlong)puVar11);

          uVar25 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar7 + 0x1d) >> 3) +

                                  (longlong)puVar11);

          uVar17 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar7 + 0x1e) >> 3) +

                                  (longlong)puVar11);

        }

LAB_140297ed9:

        if ((uVar21 & uVar13) != uVar12) {

          if (bVar1 == 1) {

            *(char *)puVar14 =

                 (char)(uVar9 >> (8U - *(char *)((longlong)puVar8 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1f) & 0x1f) |

                 (char)(uVar17 >> (8U - *(char *)((longlong)puVar8 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1e) & 0x1f) |

                 (char)(uVar25 >> (8U - *(char *)((longlong)puVar8 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1d) & 0x1f) |

                 (char)(uVar26 >> (8U - (char)puVar8[6] & 0x1f)) << ((byte)puVar8[7] & 0x1f);

          }

          else if (bVar1 == 2) {

            *(short *)puVar14 =

                 (short)(uVar9 >> (8U - *(char *)((longlong)puVar8 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1f) & 0x1f) |

                 (short)(uVar17 >> (8U - *(char *)((longlong)puVar8 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1e) & 0x1f) |

                 (short)(uVar25 >> (8U - *(char *)((longlong)puVar8 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1d) & 0x1f) |

                 (short)(uVar26 >> (8U - (char)puVar8[6] & 0x1f)) << ((byte)puVar8[7] & 0x1f);

          }

          else if (bVar1 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar8[7] >> 3) + (longlong)puVar14) = (byte)uVar26;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar8 + 0x1d) >> 3) + (longlong)puVar14) =

                 (byte)uVar25;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar8 + 0x1e) >> 3) + (longlong)puVar14) =

                 (byte)uVar17;

          }

          else if (bVar1 == 4) {

            *puVar14 = (uVar9 >> (8U - *(char *)((longlong)puVar8 + 0x1b) & 0x1f)) <<

                       (*(byte *)((longlong)puVar8 + 0x1f) & 0x1f) |

                       (uVar17 >> (8U - *(char *)((longlong)puVar8 + 0x1a) & 0x1f)) <<

                       (*(byte *)((longlong)puVar8 + 0x1e) & 0x1f) |

                       (uVar25 >> (8U - *(char *)((longlong)puVar8 + 0x19) & 0x1f)) <<

                       (*(byte *)((longlong)puVar8 + 0x1d) & 0x1f) |

                       (uVar26 >> (8U - (char)puVar8[6] & 0x1f)) << ((byte)puVar8[7] & 0x1f);

          }

        }

        puVar14 = (uint *)((longlong)puVar14 + (ulonglong)bVar1);

        puVar11 = (uint *)((longlong)puVar11 + uVar23);

LAB_140298084:

        if (bVar2 == 1) {

          uVar22 = (ulonglong)(byte)*puVar11;

LAB_14029816d:

          bVar3 = (&PTR_DAT_1403e28a0)[(byte)puVar7[6]]

                  [(puVar7[2] & uVar22) >> ((byte)puVar7[7] & 0x3f)];

          bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x19)]

                  [(puVar7[3] & uVar22) >> (*(byte *)((longlong)puVar7 + 0x1d) & 0x3f)];

          bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x1a)]

                  [(puVar7[4] & uVar22) >> (*(byte *)((longlong)puVar7 + 0x1e) & 0x3f)];

          uVar10 = puVar7[5] & uVar22;

LAB_1402981e3:

          uVar17 = (uint)bVar5;

          uVar26 = (uint)bVar3;

          uVar25 = (uint)bVar4;

          uVar21 = (uint)uVar22;

          uVar9 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x1b)]

                              [uVar10 >> (*(byte *)((longlong)puVar7 + 0x1f) & 0x3f)];

        }

        else {

          if (bVar2 == 2) {

            uVar22 = (ulonglong)(ushort)*puVar11;

            goto LAB_14029816d;

          }

          if (bVar2 != 3) {

            if (bVar2 != 4) {

              uVar21 = 0;

              uVar9 = 0;

              uVar17 = 0;

              uVar25 = 0;

              uVar26 = 0;

              goto LAB_140298203;

            }

            uVar9 = *puVar11;

            uVar22 = (ulonglong)uVar9;

            bVar3 = (&PTR_DAT_1403e28a0)[(byte)puVar7[6]]

                    [(puVar7[2] & uVar9) >> ((byte)puVar7[7] & 0x3f)];

            bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x19)]

                    [(puVar7[3] & uVar9) >> (*(byte *)((longlong)puVar7 + 0x1d) & 0x3f)];

            bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x1a)]

                    [(puVar7[4] & uVar9) >> (*(byte *)((longlong)puVar7 + 0x1e) & 0x3f)];

            uVar10 = (ulonglong)(puVar7[5] & uVar9);

            goto LAB_1402981e3;

          }

          uVar21 = 0;

          uVar9 = 0xff;

          uVar26 = (uint)*(byte *)((ulonglong)(byte)((byte)puVar7[7] >> 3) + (longlong)puVar11);

          uVar25 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar7 + 0x1d) >> 3) +

                                  (longlong)puVar11);

          uVar17 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar7 + 0x1e) >> 3) +

                                  (longlong)puVar11);

        }

LAB_140298203:

        if ((uVar21 & uVar13) != uVar12) {

          if (bVar1 == 1) {

            *(char *)puVar14 =

                 (char)(uVar9 >> (8U - *(char *)((longlong)puVar8 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1f) & 0x1f) |

                 (char)(uVar17 >> (8U - *(char *)((longlong)puVar8 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1e) & 0x1f) |

                 (char)(uVar25 >> (8U - *(char *)((longlong)puVar8 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1d) & 0x1f) |

                 (char)(uVar26 >> (8U - (char)puVar8[6] & 0x1f)) << ((byte)puVar8[7] & 0x1f);

          }

          else if (bVar1 == 2) {

            *(short *)puVar14 =

                 (short)(uVar9 >> (8U - *(char *)((longlong)puVar8 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1f) & 0x1f) |

                 (short)(uVar17 >> (8U - *(char *)((longlong)puVar8 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1e) & 0x1f) |

                 (short)(uVar25 >> (8U - *(char *)((longlong)puVar8 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1d) & 0x1f) |

                 (short)(uVar26 >> (8U - (char)puVar8[6] & 0x1f)) << ((byte)puVar8[7] & 0x1f);

          }

          else if (bVar1 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar8[7] >> 3) + (longlong)puVar14) = (byte)uVar26;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar8 + 0x1d) >> 3) + (longlong)puVar14) =

                 (byte)uVar25;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar8 + 0x1e) >> 3) + (longlong)puVar14) =

                 (byte)uVar17;

          }

          else if (bVar1 == 4) {

            *puVar14 = (uVar9 >> (8U - *(char *)((longlong)puVar8 + 0x1b) & 0x1f)) <<

                       (*(byte *)((longlong)puVar8 + 0x1f) & 0x1f) |

                       (uVar17 >> (8U - *(char *)((longlong)puVar8 + 0x1a) & 0x1f)) <<

                       (*(byte *)((longlong)puVar8 + 0x1e) & 0x1f) |

                       (uVar25 >> (8U - *(char *)((longlong)puVar8 + 0x19) & 0x1f)) <<

                       (*(byte *)((longlong)puVar8 + 0x1d) & 0x1f) |

                       (uVar26 >> (8U - (char)puVar8[6] & 0x1f)) << ((byte)puVar8[7] & 0x1f);

          }

        }

        puVar14 = (uint *)((longlong)puVar14 + (ulonglong)bVar1);

        puVar11 = (uint *)((longlong)puVar11 + uVar23);

LAB_1402983ae:

        if (bVar2 == 1) {

          uVar22 = (ulonglong)(byte)*puVar11;

LAB_140298497:

          bVar3 = (&PTR_DAT_1403e28a0)[(byte)puVar7[6]]

                  [(puVar7[2] & uVar22) >> ((byte)puVar7[7] & 0x3f)];

          bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x19)]

                  [(puVar7[3] & uVar22) >> (*(byte *)((longlong)puVar7 + 0x1d) & 0x3f)];

          bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x1a)]

                  [(puVar7[4] & uVar22) >> (*(byte *)((longlong)puVar7 + 0x1e) & 0x3f)];

          uVar10 = puVar7[5] & uVar22;

LAB_14029850d:

          uVar25 = (uint)bVar4;

          uVar17 = (uint)bVar5;

          uVar26 = (uint)bVar3;

          uVar21 = (uint)uVar22;

          uVar9 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x1b)]

                              [uVar10 >> (*(byte *)((longlong)puVar7 + 0x1f) & 0x3f)];

        }

        else {

          if (bVar2 == 2) {

            uVar22 = (ulonglong)(ushort)*puVar11;

            goto LAB_140298497;

          }

          if (bVar2 != 3) {

            if (bVar2 != 4) {

              uVar21 = 0;

              uVar9 = 0;

              uVar17 = 0;

              uVar25 = 0;

              uVar26 = 0;

              goto LAB_14029852d;

            }

            uVar9 = *puVar11;

            uVar22 = (ulonglong)uVar9;

            bVar3 = (&PTR_DAT_1403e28a0)[(byte)puVar7[6]]

                    [(puVar7[2] & uVar9) >> ((byte)puVar7[7] & 0x3f)];

            bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x19)]

                    [(puVar7[3] & uVar9) >> (*(byte *)((longlong)puVar7 + 0x1d) & 0x3f)];

            bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x1a)]

                    [(puVar7[4] & uVar9) >> (*(byte *)((longlong)puVar7 + 0x1e) & 0x3f)];

            uVar10 = (ulonglong)(puVar7[5] & uVar9);

            goto LAB_14029850d;

          }

          uVar21 = 0;

          uVar9 = 0xff;

          uVar26 = (uint)*(byte *)((ulonglong)(byte)((byte)puVar7[7] >> 3) + (longlong)puVar11);

          uVar25 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar7 + 0x1d) >> 3) +

                                  (longlong)puVar11);

          uVar17 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar7 + 0x1e) >> 3) +

                                  (longlong)puVar11);

        }

LAB_14029852d:

        if ((uVar21 & uVar13) != uVar12) {

          if (bVar1 == 1) {

            *(char *)puVar14 =

                 (char)(uVar9 >> (8U - *(char *)((longlong)puVar8 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1f) & 0x1f) |

                 (char)(uVar17 >> (8U - *(char *)((longlong)puVar8 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1e) & 0x1f) |

                 (char)(uVar25 >> (8U - *(char *)((longlong)puVar8 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1d) & 0x1f) |

                 (char)(uVar26 >> (8U - (char)puVar8[6] & 0x1f)) << ((byte)puVar8[7] & 0x1f);

          }

          else if (bVar1 == 2) {

            *(short *)puVar14 =

                 (short)(uVar9 >> (8U - *(char *)((longlong)puVar8 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1f) & 0x1f) |

                 (short)(uVar17 >> (8U - *(char *)((longlong)puVar8 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1e) & 0x1f) |

                 (short)(uVar25 >> (8U - *(char *)((longlong)puVar8 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1d) & 0x1f) |

                 (short)(uVar26 >> (8U - (char)puVar8[6] & 0x1f)) << ((byte)puVar8[7] & 0x1f);

          }

          else if (bVar1 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar8[7] >> 3) + (longlong)puVar14) = (byte)uVar26;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar8 + 0x1d) >> 3) + (longlong)puVar14) =

                 (byte)uVar25;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar8 + 0x1e) >> 3) + (longlong)puVar14) =

                 (byte)uVar17;

          }

          else if (bVar1 == 4) {

            *puVar14 = (uVar9 >> (8U - *(char *)((longlong)puVar8 + 0x1b) & 0x1f)) <<

                       (*(byte *)((longlong)puVar8 + 0x1f) & 0x1f) |

                       (uVar17 >> (8U - *(char *)((longlong)puVar8 + 0x1a) & 0x1f)) <<

                       (*(byte *)((longlong)puVar8 + 0x1e) & 0x1f) |

                       (uVar25 >> (8U - *(char *)((longlong)puVar8 + 0x19) & 0x1f)) <<

                       (*(byte *)((longlong)puVar8 + 0x1d) & 0x1f) |

                       (uVar26 >> (8U - (char)puVar8[6] & 0x1f)) << ((byte)puVar8[7] & 0x1f);

          }

        }

        local_res18[0] = local_res18[0] + -1;

        puVar14 = (uint *)((longlong)puVar14 + (ulonglong)bVar1);

        puVar11 = (uint *)((longlong)puVar11 + uVar23);

        if (local_res18[0] < 1) goto code_r0x0001402986f4;

LAB_140297a30:

        if (bVar2 == 1) {

          uVar22 = (ulonglong)(byte)*puVar11;

LAB_140297b19:

          bVar3 = (&PTR_DAT_1403e28a0)[(byte)puVar7[6]]

                  [(puVar7[2] & uVar22) >> ((byte)puVar7[7] & 0x3f)];

          bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x19)]

                  [(puVar7[3] & uVar22) >> (*(byte *)((longlong)puVar7 + 0x1d) & 0x3f)];

          bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x1a)]

                  [(puVar7[4] & uVar22) >> (*(byte *)((longlong)puVar7 + 0x1e) & 0x3f)];

          uVar10 = puVar7[5] & uVar22;

LAB_140297b8f:

          uVar17 = (uint)bVar5;

          uVar26 = (uint)bVar3;

          uVar25 = (uint)bVar4;

          uVar21 = (uint)uVar22;

          uVar9 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x1b)]

                              [uVar10 >> (*(byte *)((longlong)puVar7 + 0x1f) & 0x3f)];

        }

        else {

          if (bVar2 == 2) {

            uVar22 = (ulonglong)(ushort)*puVar11;

            goto LAB_140297b19;

          }

          if (bVar2 != 3) {

            if (bVar2 != 4) {

              uVar21 = 0;

              uVar9 = 0;

              uVar17 = 0;

              uVar25 = 0;

              uVar26 = 0;

              goto LAB_140297baf;

            }

            uVar9 = *puVar11;

            uVar22 = (ulonglong)uVar9;

            bVar3 = (&PTR_DAT_1403e28a0)[(byte)puVar7[6]]

                    [(puVar7[2] & uVar9) >> ((byte)puVar7[7] & 0x3f)];

            bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x19)]

                    [(puVar7[3] & uVar9) >> (*(byte *)((longlong)puVar7 + 0x1d) & 0x3f)];

            bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)puVar7 + 0x1a)]

                    [(puVar7[4] & uVar9) >> (*(byte *)((longlong)puVar7 + 0x1e) & 0x3f)];

            uVar10 = (ulonglong)(puVar7[5] & uVar9);

            goto LAB_140297b8f;

          }

          uVar21 = 0;

          uVar9 = 0xff;

          uVar26 = (uint)*(byte *)((ulonglong)(byte)((byte)puVar7[7] >> 3) + (longlong)puVar11);

          uVar25 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar7 + 0x1d) >> 3) +

                                  (longlong)puVar11);

          uVar17 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)puVar7 + 0x1e) >> 3) +

                                  (longlong)puVar11);

        }

LAB_140297baf:

        if ((uVar21 & uVar13) != uVar12) {

          if (bVar1 == 1) {

            *(char *)puVar14 =

                 (char)(uVar9 >> (8U - *(char *)((longlong)puVar8 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1f) & 0x1f) |

                 (char)(uVar17 >> (8U - *(char *)((longlong)puVar8 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1e) & 0x1f) |

                 (char)(uVar25 >> (8U - *(char *)((longlong)puVar8 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1d) & 0x1f) |

                 (char)(uVar26 >> (8U - (char)puVar8[6] & 0x1f)) << ((byte)puVar8[7] & 0x1f);

          }

          else if (bVar1 == 2) {

            *(short *)puVar14 =

                 (short)(uVar9 >> (8U - *(char *)((longlong)puVar8 + 0x1b) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1f) & 0x1f) |

                 (short)(uVar17 >> (8U - *(char *)((longlong)puVar8 + 0x1a) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1e) & 0x1f) |

                 (short)(uVar25 >> (8U - *(char *)((longlong)puVar8 + 0x19) & 0x1f)) <<

                 (*(byte *)((longlong)puVar8 + 0x1d) & 0x1f) |

                 (short)(uVar26 >> (8U - (char)puVar8[6] & 0x1f)) << ((byte)puVar8[7] & 0x1f);

          }

          else if (bVar1 == 3) {

            *(byte *)((ulonglong)(byte)((byte)puVar8[7] >> 3) + (longlong)puVar14) = (byte)uVar26;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar8 + 0x1d) >> 3) + (longlong)puVar14) =

                 (byte)uVar25;

            *(byte *)((ulonglong)(*(byte *)((longlong)puVar8 + 0x1e) >> 3) + (longlong)puVar14) =

                 (byte)uVar17;

          }

          else if (bVar1 == 4) {

            *puVar14 = (uVar9 >> (8U - *(char *)((longlong)puVar8 + 0x1b) & 0x1f)) <<

                       (*(byte *)((longlong)puVar8 + 0x1f) & 0x1f) |

                       (uVar17 >> (8U - *(char *)((longlong)puVar8 + 0x1a) & 0x1f)) <<

                       (*(byte *)((longlong)puVar8 + 0x1e) & 0x1f) |

                       (uVar25 >> (8U - *(char *)((longlong)puVar8 + 0x19) & 0x1f)) <<

                       (*(byte *)((longlong)puVar8 + 0x1d) & 0x1f) |

                       (uVar26 >> (8U - (char)puVar8[6] & 0x1f)) << ((byte)puVar8[7] & 0x1f);

          }

        }

        puVar14 = (uint *)((longlong)puVar14 + (ulonglong)bVar1);

        puVar11 = (uint *)((longlong)puVar11 + uVar23);

      } while( true );

    }

    local_58 = uVar6;

    FUN_140298ae0(puVar7,puVar8,&local_58,local_res20,local_res18,local_res8,0);

    lVar16 = (longlong)local_res8[0];

    lVar18 = (longlong)local_res18[0];

    lVar19 = (longlong)local_res20[0];

    lVar20 = (longlong)(int)local_58;

    while (iVar24 != 0) {

      iVar15 = (int)(((int)(uVar6 + 3) >> 0x1f & 3U) + uVar6 + 3) >> 2;

      uVar9 = uVar6 & 3;

      if (uVar9 == 0) goto LAB_1402978ee;

      if (uVar9 == 1) goto LAB_14029797b;

      if (uVar9 == 2) goto LAB_14029794c;

      if (uVar9 == 3) {

        while( true ) {

          if ((*puVar11 & uVar13) != uVar12) {

            *(byte *)puVar14 = *(byte *)(lVar20 + (longlong)puVar11);

            *(byte *)((longlong)puVar14 + 1) = *(byte *)(lVar19 + (longlong)puVar11);

            *(byte *)((longlong)puVar14 + 2) = *(byte *)(lVar18 + (longlong)puVar11);

            *(byte *)((longlong)puVar14 + 3) = *(byte *)(lVar16 + (longlong)puVar11);

          }

          puVar11 = puVar11 + 1;

          puVar14 = puVar14 + 1;

LAB_14029794c:

          if ((*puVar11 & uVar13) != uVar12) {

            *(byte *)puVar14 = *(byte *)(lVar20 + (longlong)puVar11);

            *(byte *)((longlong)puVar14 + 1) = *(byte *)(lVar19 + (longlong)puVar11);

            *(byte *)((longlong)puVar14 + 2) = *(byte *)(lVar18 + (longlong)puVar11);

            *(byte *)((longlong)puVar14 + 3) = *(byte *)(lVar16 + (longlong)puVar11);

          }

          puVar11 = puVar11 + 1;

          puVar14 = puVar14 + 1;

LAB_14029797b:

          if ((*puVar11 & uVar13) != uVar12) {

            *(byte *)puVar14 = *(byte *)(lVar20 + (longlong)puVar11);

            *(byte *)((longlong)puVar14 + 1) = *(byte *)(lVar19 + (longlong)puVar11);

            *(byte *)((longlong)puVar14 + 2) = *(byte *)(lVar18 + (longlong)puVar11);

            *(byte *)((longlong)puVar14 + 3) = *(byte *)(lVar16 + (longlong)puVar11);

          }

          puVar11 = puVar11 + 1;

          puVar14 = puVar14 + 1;

          iVar15 = iVar15 + -1;

          if (iVar15 < 1) break;

LAB_1402978ee:

          if ((*puVar11 & uVar13) != uVar12) {

            *(byte *)puVar14 = *(byte *)(lVar20 + (longlong)puVar11);

            *(byte *)((longlong)puVar14 + 1) = *(byte *)(lVar19 + (longlong)puVar11);

            *(byte *)((longlong)puVar14 + 2) = *(byte *)(lVar18 + (longlong)puVar11);

            *(byte *)((longlong)puVar14 + 3) = *(byte *)(lVar16 + (longlong)puVar11);

          }

          puVar11 = puVar11 + 1;

          puVar14 = puVar14 + 1;

        }

        puVar11 = (uint *)((longlong)puVar11 + uVar22);

        puVar14 = (uint *)((longlong)puVar14 + (longlong)local_res10);

        iVar24 = iVar24 + -1;

      }

      else {

        puVar11 = (uint *)((longlong)puVar11 + uVar22);

        puVar14 = (uint *)((longlong)puVar14 + (longlong)local_res10);

        iVar24 = iVar24 + -1;

      }

    }

  }

  return;

code_r0x0001402986f4:

  uVar22 = (ulonglong)local_54;

  puVar11 = (uint *)((longlong)puVar11 + (longlong)(int)local_54);

  puVar14 = (uint *)((longlong)puVar14 + (longlong)local_res10);

  iVar24 = iVar24 + -1;

  goto LAB_1402979d0;

}




