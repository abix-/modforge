// Address: 0x14012f4b0
// Ghidra name: thunk_FUN_1402c9340
// ============ 0x14012f4b0 thunk_FUN_1402c9340 (size=5) ============


undefined1 (*) [16] thunk_FUN_1402c9340(undefined1 (*param_1) [16],undefined1 (*param_2) [16])



{

  uint uVar1;

  ushort uVar2;

  undefined1 (*pauVar3) [16];

  ulonglong uVar4;

  longlong lVar5;

  int iVar6;

  byte bVar7;

  undefined1 (*pauVar8) [16];

  undefined1 auVar9 [16];

  undefined1 auVar10 [16];

  undefined1 in_XMM1 [16];

  undefined1 auVar11 [16];

  undefined1 auVar12 [16];

  undefined1 auVar13 [16];

  undefined1 auVar14 [16];

  char cVar15;

  char cVar16;

  char cVar17;

  char cVar18;

  

  bVar7 = (*param_2)[0];

  if (bVar7 != 0) {

    if (1 < DAT_1403e8ad0) {

      if (((ulonglong)param_2 & 0xfff) < 0xff1) {

        auVar10 = *param_2;

      }

      else {

        lVar5 = 0x10;

        pauVar3 = param_2;

        auVar11 = ZEXT816(0);

        do {

          auVar10._0_8_ = auVar11._1_8_;

          auVar10._8_8_ = auVar11._8_8_ >> 8 | (ulonglong)bVar7 << 0x38;

          if (bVar7 != 0) {

            bVar7 = (*(undefined1 (*) [16])(*pauVar3 + 1))[0];

            pauVar3 = (undefined1 (*) [16])(*pauVar3 + 1);

          }

          lVar5 = lVar5 + -1;

          auVar11 = auVar10;

        } while (lVar5 != 0);

        bVar7 = (*param_2)[0];

      }

      do {

        while( true ) {

          uVar4 = (ulonglong)param_1 & 0xfff;

          pauVar3 = param_2;

          if (uVar4 < 0xff1) break;

          if ((*param_1)[0] == '\0') goto LAB_1402c9526;

          pauVar8 = param_1;

          if ((*param_1)[0] == bVar7) {

LAB_1402c94ce:

            do {

              if (((ulonglong)param_1 & 0xfff) < 0xff1) {

                uVar4 = (ulonglong)pauVar3 & 0xfff;

                if (0xff0 < uVar4) goto LAB_1402c9502;

                pcmpistri(*pauVar3,*param_1,0xc);

                if (!SBORROW8(uVar4,0xff0)) break;

                if ((longlong)(uVar4 - 0xff0) < 0) {

                  return pauVar8;

                }

                lVar5 = 0x10;

              }

              else {

LAB_1402c9502:

                if ((*pauVar3)[0] == '\0') {

                  return pauVar8;

                }

                if ((*param_1)[0] != (*pauVar3)[0]) break;

                lVar5 = 1;

              }

              param_1 = (undefined1 (*) [16])(*param_1 + lVar5);

              pauVar3 = (undefined1 (*) [16])(*pauVar3 + lVar5);

            } while( true );

          }

          param_1 = (undefined1 (*) [16])(*pauVar8 + 1);

        }

        pcmpistri(auVar10,*param_1,0xc);

        if (uVar4 < 0xff1) {

          if (uVar4 < 0xff0) {

            iVar6 = pcmpistri(auVar10,*param_1,0xc);

            param_1 = (undefined1 (*) [16])(*param_1 + iVar6);

            pauVar8 = param_1;

            goto LAB_1402c94ce;

          }

          goto LAB_1402c9526;

        }

        param_1 = param_1 + 1;

      } while( true );

    }

    auVar11 = pshuflw(in_XMM1,ZEXT216(CONCAT11(bVar7,bVar7)),0);

LAB_1402c938e:

    for (; ((ulonglong)param_1 & 0xfff) < 0xff1; param_1 = param_1 + 1) {

      cVar15 = auVar11[0];

      auVar9[0] = -((*param_1)[0] == cVar15);

      cVar16 = auVar11[1];

      auVar9[1] = -((*param_1)[1] == cVar16);

      cVar17 = auVar11[2];

      auVar9[2] = -((*param_1)[2] == cVar17);

      cVar18 = auVar11[3];

      auVar9[3] = -((*param_1)[3] == cVar18);

      auVar9[4] = -((*param_1)[4] == cVar15);

      auVar9[5] = -((*param_1)[5] == cVar16);

      auVar9[6] = -((*param_1)[6] == cVar17);

      auVar9[7] = -((*param_1)[7] == cVar18);

      auVar9[8] = -((*param_1)[8] == cVar15);

      auVar9[9] = -((*param_1)[9] == cVar16);

      auVar9[10] = -((*param_1)[10] == cVar17);

      auVar9[0xb] = -((*param_1)[0xb] == cVar18);

      auVar9[0xc] = -((*param_1)[0xc] == cVar15);

      auVar9[0xd] = -((*param_1)[0xd] == cVar16);

      auVar9[0xe] = -((*param_1)[0xe] == cVar17);

      auVar9[0xf] = -((*param_1)[0xf] == cVar18);

      auVar12[0] = -((*param_1)[0] == '\0');

      auVar12[1] = -((*param_1)[1] == '\0');

      auVar12[2] = -((*param_1)[2] == '\0');

      auVar12[3] = -((*param_1)[3] == '\0');

      auVar12[4] = -((*param_1)[4] == '\0');

      auVar12[5] = -((*param_1)[5] == '\0');

      auVar12[6] = -((*param_1)[6] == '\0');

      auVar12[7] = -((*param_1)[7] == '\0');

      auVar12[8] = -((*param_1)[8] == '\0');

      auVar12[9] = -((*param_1)[9] == '\0');

      auVar12[10] = -((*param_1)[10] == '\0');

      auVar12[0xb] = -((*param_1)[0xb] == '\0');

      auVar12[0xc] = -((*param_1)[0xc] == '\0');

      auVar12[0xd] = -((*param_1)[0xd] == '\0');

      auVar12[0xe] = -((*param_1)[0xe] == '\0');

      auVar12[0xf] = -((*param_1)[0xf] == '\0');

      auVar12 = auVar12 | auVar9;

      uVar2 = (ushort)(SUB161(auVar12 >> 7,0) & 1) | (ushort)(SUB161(auVar12 >> 0xf,0) & 1) << 1 |

              (ushort)(SUB161(auVar12 >> 0x17,0) & 1) << 2 |

              (ushort)(SUB161(auVar12 >> 0x1f,0) & 1) << 3 |

              (ushort)(SUB161(auVar12 >> 0x27,0) & 1) << 4 |

              (ushort)(SUB161(auVar12 >> 0x2f,0) & 1) << 5 |

              (ushort)(SUB161(auVar12 >> 0x37,0) & 1) << 6 |

              (ushort)(SUB161(auVar12 >> 0x3f,0) & 1) << 7 |

              (ushort)(SUB161(auVar12 >> 0x47,0) & 1) << 8 |

              (ushort)(SUB161(auVar12 >> 0x4f,0) & 1) << 9 |

              (ushort)(SUB161(auVar12 >> 0x57,0) & 1) << 10 |

              (ushort)(SUB161(auVar12 >> 0x5f,0) & 1) << 0xb |

              (ushort)(SUB161(auVar12 >> 0x67,0) & 1) << 0xc |

              (ushort)(SUB161(auVar12 >> 0x6f,0) & 1) << 0xd |

              (ushort)(SUB161(auVar12 >> 0x77,0) & 1) << 0xe |

              (ushort)(byte)(auVar12[0xf] >> 7) << 0xf;

      if (uVar2 != 0) {

        uVar1 = 0;

        if (uVar2 != 0) {

          for (; (uVar2 >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {

          }

        }

        param_1 = (undefined1 (*) [16])(*param_1 + uVar1);

        break;

      }

    }

    if ((*param_1)[0] != '\0') {

      pauVar3 = param_1;

      pauVar8 = param_2;

      if (bVar7 == (*param_1)[0]) {

LAB_1402c93d6:

        for (; (((ulonglong)pauVar8 & 0xfff) < 0xff1 && (((ulonglong)pauVar3 & 0xfff) < 0xff1));

            pauVar3 = pauVar3 + 1) {

          auVar13[0] = -((*pauVar8)[0] == '\0');

          auVar13[1] = -((*pauVar8)[1] == '\0');

          auVar13[2] = -((*pauVar8)[2] == '\0');

          auVar13[3] = -((*pauVar8)[3] == '\0');

          auVar13[4] = -((*pauVar8)[4] == '\0');

          auVar13[5] = -((*pauVar8)[5] == '\0');

          auVar13[6] = -((*pauVar8)[6] == '\0');

          auVar13[7] = -((*pauVar8)[7] == '\0');

          auVar13[8] = -((*pauVar8)[8] == '\0');

          auVar13[9] = -((*pauVar8)[9] == '\0');

          auVar13[10] = -((*pauVar8)[10] == '\0');

          auVar13[0xb] = -((*pauVar8)[0xb] == '\0');

          auVar13[0xc] = -((*pauVar8)[0xc] == '\0');

          auVar13[0xd] = -((*pauVar8)[0xd] == '\0');

          auVar13[0xe] = -((*pauVar8)[0xe] == '\0');

          auVar13[0xf] = -((*pauVar8)[0xf] == '\0');

          auVar14[0] = -((*pauVar8)[0] != (*pauVar3)[0]);

          auVar14[1] = -((*pauVar8)[1] != (*pauVar3)[1]);

          auVar14[2] = -((*pauVar8)[2] != (*pauVar3)[2]);

          auVar14[3] = -((*pauVar8)[3] != (*pauVar3)[3]);

          auVar14[4] = -((*pauVar8)[4] != (*pauVar3)[4]);

          auVar14[5] = -((*pauVar8)[5] != (*pauVar3)[5]);

          auVar14[6] = -((*pauVar8)[6] != (*pauVar3)[6]);

          auVar14[7] = -((*pauVar8)[7] != (*pauVar3)[7]);

          auVar14[8] = -((*pauVar8)[8] != (*pauVar3)[8]);

          auVar14[9] = -((*pauVar8)[9] != (*pauVar3)[9]);

          auVar14[10] = -((*pauVar8)[10] != (*pauVar3)[10]);

          auVar14[0xb] = -((*pauVar8)[0xb] != (*pauVar3)[0xb]);

          auVar14[0xc] = -((*pauVar8)[0xc] != (*pauVar3)[0xc]);

          auVar14[0xd] = -((*pauVar8)[0xd] != (*pauVar3)[0xd]);

          auVar14[0xe] = -((*pauVar8)[0xe] != (*pauVar3)[0xe]);

          auVar14[0xf] = -((*pauVar8)[0xf] != (*pauVar3)[0xf]);

          auVar14 = auVar14 | auVar13;

          uVar2 = (ushort)(SUB161(auVar14 >> 7,0) & 1) | (ushort)(SUB161(auVar14 >> 0xf,0) & 1) << 1

                  | (ushort)(SUB161(auVar14 >> 0x17,0) & 1) << 2 |

                  (ushort)(SUB161(auVar14 >> 0x1f,0) & 1) << 3 |

                  (ushort)(SUB161(auVar14 >> 0x27,0) & 1) << 4 |

                  (ushort)(SUB161(auVar14 >> 0x2f,0) & 1) << 5 |

                  (ushort)(SUB161(auVar14 >> 0x37,0) & 1) << 6 |

                  (ushort)(SUB161(auVar14 >> 0x3f,0) & 1) << 7 |

                  (ushort)(SUB161(auVar14 >> 0x47,0) & 1) << 8 |

                  (ushort)(SUB161(auVar14 >> 0x4f,0) & 1) << 9 |

                  (ushort)(SUB161(auVar14 >> 0x57,0) & 1) << 10 |

                  (ushort)(SUB161(auVar14 >> 0x5f,0) & 1) << 0xb |

                  (ushort)(SUB161(auVar14 >> 0x67,0) & 1) << 0xc |

                  (ushort)(SUB161(auVar14 >> 0x6f,0) & 1) << 0xd |

                  (ushort)(SUB161(auVar14 >> 0x77,0) & 1) << 0xe |

                  (ushort)(byte)(auVar14[0xf] >> 7) << 0xf;

          if (uVar2 != 0) {

            uVar1 = 0;

            if (uVar2 != 0) {

              for (; (uVar2 >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {

              }

            }

            pauVar3 = (undefined1 (*) [16])(*pauVar3 + uVar1);

            pauVar8 = (undefined1 (*) [16])(*pauVar8 + uVar1);

            break;

          }

          pauVar8 = pauVar8 + 1;

        }

        if ((*pauVar8)[0] == '\0') {

          return param_1;

        }

        if ((*pauVar3)[0] == (*pauVar8)[0]) {

          pauVar3 = (undefined1 (*) [16])(*pauVar3 + 1);

          pauVar8 = (undefined1 (*) [16])(*pauVar8 + 1);

          goto LAB_1402c93d6;

        }

      }

      param_1 = (undefined1 (*) [16])(*param_1 + 1);

      goto LAB_1402c938e;

    }

LAB_1402c9526:

    param_1 = (undefined1 (*) [16])0x0;

  }

  return param_1;

}




