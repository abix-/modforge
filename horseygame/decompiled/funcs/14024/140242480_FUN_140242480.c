// Address: 0x140242480
// Ghidra name: FUN_140242480
// ============ 0x140242480 FUN_140242480 (size=13860) ============


undefined8

FUN_140242480(longlong param_1,int *param_2,undefined4 param_3,byte param_4,byte param_5,

             byte param_6,byte param_7)



{

  longlong lVar1;

  uint uVar2;

  uint uVar3;

  undefined8 uVar4;

  ulonglong uVar5;

  int iVar6;

  uint uVar7;

  uint uVar8;

  int iVar9;

  uint uVar10;

  uint *puVar11;

  ushort *puVar12;

  uint uVar13;

  uint uVar14;

  int iVar15;

  int local_res8;

  

  lVar1 = *(longlong *)(param_1 + 0x38);

  iVar15 = 0xff - (uint)param_7;

  uVar14 = (uint)param_4;

  if (*(char *)(lVar1 + 5) == '\x02') {

    switch(param_3) {

    case 1:

      uVar8 = param_2[2];

      iVar9 = *(int *)(param_1 + 0x10) / 2;

      iVar6 = iVar9 - uVar8;

      puVar12 = (ushort *)

                (*(longlong *)(param_1 + 0x18) +

                ((longlong)(iVar9 * param_2[1]) + (longlong)*param_2) * 2);

      uVar7 = param_2[3];

      while( true ) {

        uVar5 = (ulonglong)uVar7;

        if (uVar7 == 0) break;

        _param_7 = (int)(uVar8 + 3 + ((int)(uVar8 + 3) >> 0x1f & 3U)) >> 2;

        uVar10 = uVar8 & 3;

        if (uVar10 == 0) goto LAB_140243fef;

        if (uVar10 == 1) goto LAB_1402442dd;

        if (uVar10 == 2) goto LAB_1402441e3;

        if (uVar10 == 3) {

          while( true ) {

            uVar5 = (ulonglong)*puVar12;

            *puVar12 = (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                            [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff +

                               (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                            [(*(uint *)(lVar1 + 8) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff +

                               uVar14 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                            [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff +

                               (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

LAB_1402441e3:

            uVar5 = (ulonglong)*puVar12;

            *puVar12 = (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                            [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff +

                               (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                            [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff +

                               (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                            [(*(uint *)(lVar1 + 8) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff +

                               uVar14 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

LAB_1402442dd:

            uVar5 = (ulonglong)*puVar12;

            _param_7 = _param_7 + -1;

            *puVar12 = (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                            [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff +

                               (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                            [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff +

                               (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                            [(*(uint *)(lVar1 + 8) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff +

                               uVar14 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

            if (_param_7 < 1) break;

LAB_140243fef:

            uVar5 = (ulonglong)*puVar12;

            *puVar12 = (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                            [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff +

                               (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                            [(*(uint *)(lVar1 + 8) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff +

                               uVar14 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                            [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff +

                               (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

          }

          puVar12 = puVar12 + iVar6;

          uVar7 = uVar7 - 1;

        }

        else {

          puVar12 = puVar12 + iVar6;

          uVar7 = uVar7 - 1;

        }

      }

      break;

    case 2:

    case 0x20:

      uVar8 = param_2[2];

      iVar15 = *(int *)(param_1 + 0x10) / 2;

      iVar9 = iVar15 - uVar8;

      puVar12 = (ushort *)

                (*(longlong *)(param_1 + 0x18) +

                ((longlong)(iVar15 * param_2[1]) + (longlong)*param_2) * 2);

      uVar7 = param_2[3];

      while( true ) {

        uVar5 = (ulonglong)uVar7;

        if (uVar7 == 0) break;

        _param_7 = (int)(uVar8 + 3 + ((int)(uVar8 + 3) >> 0x1f & 3U)) >> 2;

        uVar10 = uVar8 & 3;

        if (uVar10 == 0) goto LAB_1402449ee;

        if (uVar10 == 1) goto LAB_140244c91;

        if (uVar10 == 2) goto LAB_140244bb0;

        if (uVar10 == 3) {

          while( true ) {

            uVar5 = (ulonglong)*puVar12;

            uVar10 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                           [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                     uVar14;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                             [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                       uVar14) {

              uVar10 = 0xff;

            }

            uVar13 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                   [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5) {

              uVar13 = 0xff;

            }

            uVar2 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                   [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6) {

              uVar2 = 0xff;

            }

            *puVar12 = (short)(uVar10 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(uVar2 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(uVar13 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

LAB_140244bb0:

            uVar5 = (ulonglong)*puVar12;

            uVar10 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                           [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                     uVar14;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                             [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                       uVar14) {

              uVar10 = 0xff;

            }

            uVar13 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                   [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5) {

              uVar13 = 0xff;

            }

            uVar2 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                   [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6) {

              uVar2 = 0xff;

            }

            *puVar12 = (short)(uVar10 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(uVar2 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(uVar13 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

LAB_140244c91:

            uVar5 = (ulonglong)*puVar12;

            uVar10 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                           [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                     uVar14;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                             [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                       uVar14) {

              uVar10 = 0xff;

            }

            uVar13 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                   [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5) {

              uVar13 = 0xff;

            }

            uVar2 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                   [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6) {

              uVar2 = 0xff;

            }

            _param_7 = _param_7 + -1;

            *puVar12 = (short)(uVar10 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(uVar2 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(uVar13 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

            if (_param_7 < 1) break;

LAB_1402449ee:

            uVar5 = (ulonglong)*puVar12;

            uVar10 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                           [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                     uVar14;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                             [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                       uVar14) {

              uVar10 = 0xff;

            }

            uVar13 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                   [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5) {

              uVar13 = 0xff;

            }

            uVar2 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                   [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6) {

              uVar2 = 0xff;

            }

            *puVar12 = (short)(uVar10 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(uVar2 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(uVar13 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

          }

          puVar12 = puVar12 + iVar9;

          uVar7 = uVar7 - 1;

        }

        else {

          puVar12 = puVar12 + iVar9;

          uVar7 = uVar7 - 1;

        }

      }

      break;

    default:

      uVar14 = param_2[2];

      iVar15 = *(int *)(param_1 + 0x10) / 2;

      iVar9 = iVar15 - uVar14;

      puVar12 = (ushort *)

                (*(longlong *)(param_1 + 0x18) +

                ((longlong)(iVar15 * param_2[1]) + (longlong)*param_2) * 2);

      uVar8 = param_2[3];

      while( true ) {

        uVar5 = (ulonglong)uVar8;

        if (uVar8 == 0) break;

        iVar15 = (int)(((int)(uVar14 + 3) >> 0x1f & 3U) + uVar14 + 3) >> 2;

        uVar7 = uVar14 & 3;

        if (uVar7 == 0) goto LAB_1402458e4;

        if (uVar7 == 1) goto LAB_140245a10;

        if (uVar7 == 2) goto LAB_1402459ac;

        if (uVar7 == 3) {

          while( true ) {

            *puVar12 = (ushort)(param_4 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (ushort)(param_5 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (ushort)(param_6 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

LAB_1402459ac:

            *puVar12 = (ushort)(param_4 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (ushort)(param_5 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (ushort)(param_6 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

LAB_140245a10:

            iVar15 = iVar15 + -1;

            *puVar12 = (ushort)(param_4 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (ushort)(param_5 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (ushort)(param_6 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

            if (iVar15 < 1) break;

LAB_1402458e4:

            *puVar12 = (ushort)(param_4 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (ushort)(param_5 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (ushort)(param_6 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

          }

          puVar12 = puVar12 + iVar9;

          uVar8 = uVar8 - 1;

        }

        else {

          puVar12 = puVar12 + iVar9;

          uVar8 = uVar8 - 1;

        }

      }

      break;

    case 4:

      uVar8 = param_2[2];

      iVar15 = *(int *)(param_1 + 0x10) / 2;

      iVar9 = iVar15 - uVar8;

      puVar12 = (ushort *)

                (*(longlong *)(param_1 + 0x18) +

                ((longlong)(iVar15 * param_2[1]) + (longlong)*param_2) * 2);

      uVar7 = param_2[3];

      while( true ) {

        uVar5 = (ulonglong)uVar7;

        if (uVar7 == 0) break;

        _param_7 = (int)(uVar8 + 3 + ((int)(uVar8 + 3) >> 0x1f & 3U)) >> 2;

        uVar10 = uVar8 & 3;

        if (uVar10 == 0) goto LAB_140244e36;

        if (uVar10 == 1) goto LAB_1402450f7;

        if (uVar10 == 2) goto LAB_14024500c;

        if (uVar10 == 3) {

          while( true ) {

            uVar5 = (ulonglong)*puVar12;

            *puVar12 = (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                            [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_6) /

                               0xff >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                            [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_5) /

                               0xff >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                      [(*(uint *)(lVar1 + 8) & uVar5) >>

                                       (*(byte *)(lVar1 + 0x1c) & 0x3f)] * uVar14) / 0xff >>

                              (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

LAB_14024500c:

            uVar5 = (ulonglong)*puVar12;

            *puVar12 = (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                            [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_6) /

                               0xff >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                            [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_5) /

                               0xff >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                      [(*(uint *)(lVar1 + 8) & uVar5) >>

                                       (*(byte *)(lVar1 + 0x1c) & 0x3f)] * uVar14) / 0xff >>

                              (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

LAB_1402450f7:

            uVar5 = (ulonglong)*puVar12;

            _param_7 = _param_7 + -1;

            *puVar12 = (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                            [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_6) /

                               0xff >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                            [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_5) /

                               0xff >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                      [(*(uint *)(lVar1 + 8) & uVar5) >>

                                       (*(byte *)(lVar1 + 0x1c) & 0x3f)] * uVar14) / 0xff >>

                              (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

            if (_param_7 < 1) break;

LAB_140244e36:

            uVar5 = (ulonglong)*puVar12;

            *puVar12 = (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                            [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_6) /

                               0xff >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                            [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                             (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_5) /

                               0xff >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (short)(((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                      [(*(uint *)(lVar1 + 8) & uVar5) >>

                                       (*(byte *)(lVar1 + 0x1c) & 0x3f)] * uVar14) / 0xff >>

                              (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

          }

          puVar12 = puVar12 + iVar9;

          uVar7 = uVar7 - 1;

        }

        else {

          puVar12 = puVar12 + iVar9;

          uVar7 = uVar7 - 1;

        }

      }

      break;

    case 8:

      uVar14 = param_2[2];

      iVar9 = *(int *)(param_1 + 0x10) / 2;

      iVar6 = iVar9 - uVar14;

      puVar12 = (ushort *)

                (*(longlong *)(param_1 + 0x18) +

                ((longlong)(iVar9 * param_2[1]) + (longlong)*param_2) * 2);

      uVar8 = param_2[3];

      while( true ) {

        uVar5 = (ulonglong)uVar8;

        if (uVar8 == 0) break;

        local_res8 = (int)(uVar14 + 3 + ((int)(uVar14 + 3) >> 0x1f & 3U)) >> 2;

        uVar7 = uVar14 & 3;

        if (uVar7 == 0) goto LAB_14024529c;

        if (uVar7 == 1) goto LAB_1402456d1;

        if (uVar7 == 2) goto LAB_14024556a;

        if (uVar7 == 3) {

          while( true ) {

            uVar5 = (ulonglong)*puVar12;

            uVar7 = ((uint)param_4 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                    ) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            uVar10 = ((uint)param_5 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = ((uint)param_6 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                  [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            *puVar12 = (short)(uVar7 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(uVar13 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(uVar10 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

LAB_14024556a:

            uVar5 = (ulonglong)*puVar12;

            uVar7 = ((uint)param_4 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                    ) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            uVar10 = ((uint)param_5 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = ((uint)param_6 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                  [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            *puVar12 = (short)(uVar7 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(uVar13 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(uVar10 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

LAB_1402456d1:

            uVar5 = (ulonglong)*puVar12;

            uVar7 = ((uint)param_4 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                    ) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            uVar10 = ((uint)param_5 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = ((uint)param_6 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                  [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            local_res8 = local_res8 + -1;

            *puVar12 = (short)(uVar7 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(uVar13 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(uVar10 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

            if (local_res8 < 1) break;

LAB_14024529c:

            uVar5 = (ulonglong)*puVar12;

            uVar7 = ((uint)param_4 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                    ) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            uVar10 = ((uint)param_5 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = ((uint)param_6 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                  [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            *puVar12 = (short)(uVar7 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(uVar13 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(uVar10 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

          }

          puVar12 = puVar12 + iVar6;

          uVar8 = uVar8 - 1;

        }

        else {

          puVar12 = puVar12 + iVar6;

          uVar8 = uVar8 - 1;

        }

      }

      break;

    case 0x10:

      uVar14 = param_2[2];

      iVar9 = *(int *)(param_1 + 0x10) / 2;

      iVar6 = iVar9 - uVar14;

      puVar12 = (ushort *)

                (*(longlong *)(param_1 + 0x18) +

                ((longlong)(iVar9 * param_2[1]) + (longlong)*param_2) * 2);

      uVar8 = param_2[3];

      while( true ) {

        uVar5 = (ulonglong)uVar8;

        if (uVar8 == 0) break;

        local_res8 = (int)(uVar14 + 3 + ((int)(uVar14 + 3) >> 0x1f & 3U)) >> 2;

        uVar7 = uVar14 & 3;

        if (uVar7 == 0) goto LAB_140244489;

        if (uVar7 == 1) goto LAB_14024480a;

        if (uVar7 == 2) goto LAB_1402446df;

        if (uVar7 == 3) {

          while( true ) {

            uVar5 = (ulonglong)*puVar12;

            uVar7 = (uint)param_4 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            uVar10 = (uint)param_5 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = (uint)param_6 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                  [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            *puVar12 = (short)(uVar7 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(uVar13 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(uVar10 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

LAB_1402446df:

            uVar5 = (ulonglong)*puVar12;

            uVar7 = (uint)param_4 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            uVar10 = (uint)param_5 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = (uint)param_6 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                  [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            *puVar12 = (short)(uVar7 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(uVar13 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(uVar10 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

LAB_14024480a:

            uVar5 = (ulonglong)*puVar12;

            uVar7 = (uint)param_4 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            uVar10 = (uint)param_5 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = (uint)param_6 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                  [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            local_res8 = local_res8 + -1;

            *puVar12 = (short)(uVar7 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(uVar13 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(uVar10 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

            if (local_res8 < 1) break;

LAB_140244489:

            uVar5 = (ulonglong)*puVar12;

            uVar7 = (uint)param_4 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            uVar10 = (uint)param_5 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = (uint)param_6 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                  [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            *puVar12 = (short)(uVar7 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (short)(uVar13 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (short)(uVar10 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(ushort *)(lVar1 + 0x14);

            puVar12 = puVar12 + 1;

          }

          puVar12 = puVar12 + iVar6;

          uVar8 = uVar8 - 1;

        }

        else {

          puVar12 = puVar12 + iVar6;

          uVar8 = uVar8 - 1;

        }

      }

    }

  }

  else {

    if (*(char *)(lVar1 + 5) != '\x04') {

      uVar4 = FUN_14012e850("That operation is not supported");

      return uVar4;

    }

    switch(param_3) {

    case 1:

      uVar8 = param_2[2];

      iVar9 = (int)(*(int *)(param_1 + 0x10) + (*(int *)(param_1 + 0x10) >> 0x1f & 3U)) >> 2;

      iVar6 = iVar9 - uVar8;

      puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) +

                        ((longlong)(iVar9 * param_2[1]) + (longlong)*param_2) * 4);

      uVar7 = param_2[3];

      while( true ) {

        uVar5 = (ulonglong)uVar7;

        if (uVar7 == 0) break;

        _param_7 = (int)(uVar8 + 3 + ((int)(uVar8 + 3) >> 0x1f & 3U)) >> 2;

        uVar10 = uVar8 & 3;

        if (uVar10 == 0) goto LAB_140242596;

        if (uVar10 == 1) goto LAB_14024286c;

        if (uVar10 == 2) goto LAB_14024277a;

        if (uVar10 == 3) {

          while( true ) {

            uVar10 = *puVar11;

            *puVar11 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                     [(*(uint *)(lVar1 + 0x10) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff +

                        (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                     [(*(uint *)(lVar1 + 0xc) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff +

                        (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                     [(*(uint *)(lVar1 + 8) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff + uVar14 >>

                       (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

LAB_14024277a:

            uVar10 = *puVar11;

            *puVar11 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                     [(*(uint *)(lVar1 + 0x10) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff +

                        (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                     [(*(uint *)(lVar1 + 0xc) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff +

                        (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                     [(*(uint *)(lVar1 + 8) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff + uVar14 >>

                       (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

LAB_14024286c:

            uVar10 = *puVar11;

            _param_7 = _param_7 + -1;

            *puVar11 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                     [(*(uint *)(lVar1 + 0x10) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff +

                        (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                     [(*(uint *)(lVar1 + 0xc) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff +

                        (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                     [(*(uint *)(lVar1 + 8) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff + uVar14 >>

                       (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

            if (_param_7 < 1) break;

LAB_140242596:

            uVar10 = *puVar11;

            *puVar11 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                     [(*(uint *)(lVar1 + 0x10) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff +

                        (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                     [(*(uint *)(lVar1 + 0xc) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff +

                        (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                     [(*(uint *)(lVar1 + 8) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff + uVar14 >>

                       (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

          }

          puVar11 = puVar11 + iVar6;

          uVar7 = uVar7 - 1;

        }

        else {

          puVar11 = puVar11 + iVar6;

          uVar7 = uVar7 - 1;

        }

      }

      break;

    case 2:

    case 0x20:

      uVar14 = param_2[2];

      iVar15 = *(int *)(param_1 + 0x10) / 4;

      iVar9 = iVar15 - uVar14;

      puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) +

                        ((longlong)(iVar15 * param_2[1]) + (longlong)*param_2) * 4);

      uVar8 = param_2[3];

      while( true ) {

        uVar5 = (ulonglong)uVar8;

        if (uVar8 == 0) break;

        _param_7 = (int)(uVar14 + 3 + ((int)(uVar14 + 3) >> 0x1f & 3U)) >> 2;

        uVar7 = uVar14 & 3;

        uVar10 = (uint)param_4;

        if (uVar7 == 0) goto LAB_140242f55;

        if (uVar7 == 1) goto LAB_1402431e0;

        if (uVar7 == 2) goto LAB_140243107;

        if (uVar7 == 3) {

          while( true ) {

            uVar7 = *puVar11;

            uVar13 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                           [(*(uint *)(lVar1 + 8) & uVar7) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                     uVar10;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                             [(*(uint *)(lVar1 + 8) & uVar7) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                       uVar10) {

              uVar13 = 0xff;

            }

            uVar2 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                 (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                   [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                    (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5) {

              uVar2 = 0xff;

            }

            uVar3 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                   [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                    (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6) {

              uVar3 = 0xff;

            }

            *puVar11 = (uVar13 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uVar3 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (uVar2 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

LAB_140243107:

            uVar7 = *puVar11;

            uVar13 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                           [(*(uint *)(lVar1 + 8) & uVar7) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                     uVar10;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                             [(*(uint *)(lVar1 + 8) & uVar7) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                       uVar10) {

              uVar13 = 0xff;

            }

            uVar2 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                 (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                   [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                    (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5) {

              uVar2 = 0xff;

            }

            uVar3 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                   [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                    (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6) {

              uVar3 = 0xff;

            }

            *puVar11 = (uVar13 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uVar3 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (uVar2 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

LAB_1402431e0:

            uVar7 = *puVar11;

            uVar13 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                           [(*(uint *)(lVar1 + 8) & uVar7) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                     uVar10;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                             [(*(uint *)(lVar1 + 8) & uVar7) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                       uVar10) {

              uVar13 = 0xff;

            }

            uVar2 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                 (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                   [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                    (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5) {

              uVar2 = 0xff;

            }

            uVar3 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                   [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                    (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6) {

              uVar3 = 0xff;

            }

            _param_7 = _param_7 + -1;

            *puVar11 = (uVar13 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uVar3 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (uVar2 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

            if (_param_7 < 1) break;

LAB_140242f55:

            uVar7 = *puVar11;

            uVar13 = (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                           [(*(uint *)(lVar1 + 8) & uVar7) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                     uVar10;

            if (0xff < (byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                             [(*(uint *)(lVar1 + 8) & uVar7) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] +

                       uVar10) {

              uVar13 = 0xff;

            }

            uVar2 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                 (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                   [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                    (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5) {

              uVar2 = 0xff;

            }

            uVar3 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                   [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                    (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6) {

              uVar3 = 0xff;

            }

            *puVar11 = (uVar13 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uVar3 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (uVar2 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

          }

          puVar11 = puVar11 + iVar9;

          uVar8 = uVar8 - 1;

        }

        else {

          puVar11 = puVar11 + iVar9;

          uVar8 = uVar8 - 1;

        }

      }

      break;

    default:

      uVar14 = param_2[2];

      iVar15 = *(int *)(param_1 + 0x10) / 4;

      iVar9 = iVar15 - uVar14;

      puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) +

                        ((longlong)(iVar15 * param_2[1]) + (longlong)*param_2) * 4);

      uVar8 = param_2[3];

      while( true ) {

        uVar5 = (ulonglong)uVar8;

        if (uVar8 == 0) break;

        iVar15 = (int)(((int)(uVar14 + 3) >> 0x1f & 3U) + uVar14 + 3) >> 2;

        uVar7 = uVar14 & 3;

        if (uVar7 == 0) goto LAB_140243df3;

        if (uVar7 == 1) goto LAB_140243edd;

        if (uVar7 == 2) goto LAB_140243e8f;

        if (uVar7 == 3) {

          while( true ) {

            *puVar11 = (uint)(param_4 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uint)(param_5 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (uint)(param_6 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

LAB_140243e8f:

            *puVar11 = (uint)(param_4 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uint)(param_5 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (uint)(param_6 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

LAB_140243edd:

            iVar15 = iVar15 + -1;

            *puVar11 = (uint)(param_4 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uint)(param_5 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (uint)(param_6 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

            if (iVar15 < 1) break;

LAB_140243df3:

            *puVar11 = (uint)(param_4 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uint)(param_5 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (uint)(param_6 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

          }

          puVar11 = puVar11 + iVar9;

          uVar8 = uVar8 - 1;

        }

        else {

          puVar11 = puVar11 + iVar9;

          uVar8 = uVar8 - 1;

        }

      }

      break;

    case 4:

      uVar8 = param_2[2];

      iVar15 = *(int *)(param_1 + 0x10) / 4;

      iVar9 = iVar15 - uVar8;

      puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) +

                        ((longlong)(iVar15 * param_2[1]) + (longlong)*param_2) * 4);

      uVar7 = param_2[3];

      while( true ) {

        uVar5 = (ulonglong)uVar7;

        if (uVar7 == 0) break;

        _param_7 = (int)(uVar8 + 3 + ((int)(uVar8 + 3) >> 0x1f & 3U)) >> 2;

        uVar10 = uVar8 & 3;

        if (uVar10 == 0) goto LAB_140243386;

        if (uVar10 == 1) goto LAB_14024362f;

        if (uVar10 == 2) goto LAB_14024354c;

        if (uVar10 == 3) {

          while( true ) {

            uVar10 = *puVar11;

            *puVar11 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                     [(*(uint *)(lVar1 + 0x10) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_6) / 0xff >>

                       (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                     [(*(uint *)(lVar1 + 0xc) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_5) / 0xff >>

                       (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                               [(*(uint *)(lVar1 + 8) & uVar10) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                        * uVar14) / 0xff >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

LAB_14024354c:

            uVar10 = *puVar11;

            *puVar11 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                     [(*(uint *)(lVar1 + 0x10) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_6) / 0xff >>

                       (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                     [(*(uint *)(lVar1 + 0xc) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_5) / 0xff >>

                       (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                               [(*(uint *)(lVar1 + 8) & uVar10) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                        * uVar14) / 0xff >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

LAB_14024362f:

            uVar10 = *puVar11;

            _param_7 = _param_7 + -1;

            *puVar11 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                     [(*(uint *)(lVar1 + 0x10) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_6) / 0xff >>

                       (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                     [(*(uint *)(lVar1 + 0xc) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_5) / 0xff >>

                       (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                               [(*(uint *)(lVar1 + 8) & uVar10) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                        * uVar14) / 0xff >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

            if (_param_7 < 1) break;

LAB_140243386:

            uVar10 = *puVar11;

            *puVar11 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                     [(*(uint *)(lVar1 + 0x10) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_6) / 0xff >>

                       (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                     [(*(uint *)(lVar1 + 0xc) & uVar10) >>

                                      (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_5) / 0xff >>

                       (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                               [(*(uint *)(lVar1 + 8) & uVar10) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                        * uVar14) / 0xff >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

          }

          puVar11 = puVar11 + iVar9;

          uVar7 = uVar7 - 1;

        }

        else {

          puVar11 = puVar11 + iVar9;

          uVar7 = uVar7 - 1;

        }

      }

      break;

    case 8:

      uVar14 = param_2[2];

      iVar9 = *(int *)(param_1 + 0x10) / 4;

      iVar6 = iVar9 - uVar14;

      puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) +

                        ((longlong)(iVar9 * param_2[1]) + (longlong)*param_2) * 4);

      uVar8 = param_2[3];

      while( true ) {

        uVar5 = (ulonglong)uVar8;

        if (uVar8 == 0) break;

        local_res8 = (int)(uVar14 + 3 + ((int)(uVar14 + 3) >> 0x1f & 3U)) >> 2;

        uVar7 = uVar14 & 3;

        if (uVar7 == 0) goto LAB_1402437cc;

        if (uVar7 == 1) goto LAB_140243be9;

        if (uVar7 == 2) goto LAB_140243a8a;

        if (uVar7 == 3) {

          while( true ) {

            uVar7 = *puVar11;

            uVar10 = ((uint)param_4 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar7) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                  [(*(uint *)(lVar1 + 8) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = ((uint)param_5 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar7 = ((uint)param_6 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)]) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            *puVar11 = (uVar10 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uVar7 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (uVar13 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

LAB_140243a8a:

            uVar7 = *puVar11;

            uVar10 = ((uint)param_4 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar7) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                  [(*(uint *)(lVar1 + 8) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = ((uint)param_5 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar7 = ((uint)param_6 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)]) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            *puVar11 = (uVar10 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uVar7 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (uVar13 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

LAB_140243be9:

            uVar7 = *puVar11;

            uVar10 = ((uint)param_4 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar7) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                  [(*(uint *)(lVar1 + 8) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = ((uint)param_5 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar7 = ((uint)param_6 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)]) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            local_res8 = local_res8 + -1;

            *puVar11 = (uVar10 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uVar7 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (uVar13 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

            if (local_res8 < 1) break;

LAB_1402437cc:

            uVar7 = *puVar11;

            uVar10 = ((uint)param_4 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar7) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                  [(*(uint *)(lVar1 + 8) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = ((uint)param_5 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar7 = ((uint)param_6 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)]) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            *puVar11 = (uVar10 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uVar7 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (uVar13 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

          }

          puVar11 = puVar11 + iVar6;

          uVar8 = uVar8 - 1;

        }

        else {

          puVar11 = puVar11 + iVar6;

          uVar8 = uVar8 - 1;

        }

      }

      break;

    case 0x10:

      uVar14 = param_2[2];

      iVar9 = *(int *)(param_1 + 0x10) / 4;

      iVar6 = iVar9 - uVar14;

      puVar11 = (uint *)(*(longlong *)(param_1 + 0x18) +

                        ((longlong)(iVar9 * param_2[1]) + (longlong)*param_2) * 4);

      uVar8 = param_2[3];

      while( true ) {

        uVar5 = (ulonglong)uVar8;

        if (uVar8 == 0) break;

        local_res8 = (int)(uVar14 + 3 + ((int)(uVar14 + 3) >> 0x1f & 3U)) >> 2;

        uVar7 = uVar14 & 3;

        if (uVar7 == 0) goto LAB_140242a10;

        if (uVar7 == 1) goto LAB_140242d79;

        if (uVar7 == 2) goto LAB_140242c56;

        if (uVar7 == 3) {

          while( true ) {

            uVar7 = *puVar11;

            uVar10 = (uint)param_4 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                  [(*(uint *)(lVar1 + 8) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = (uint)param_5 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar7 = (uint)param_6 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            *puVar11 = (uVar10 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uVar7 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (uVar13 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

LAB_140242c56:

            uVar7 = *puVar11;

            uVar10 = (uint)param_4 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                  [(*(uint *)(lVar1 + 8) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = (uint)param_5 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar7 = (uint)param_6 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            *puVar11 = (uVar10 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uVar7 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (uVar13 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

LAB_140242d79:

            uVar7 = *puVar11;

            uVar10 = (uint)param_4 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                  [(*(uint *)(lVar1 + 8) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = (uint)param_5 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar7 = (uint)param_6 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            local_res8 = local_res8 + -1;

            *puVar11 = (uVar10 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uVar7 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                       (uVar13 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

            if (local_res8 < 1) break;

LAB_140242a10:

            uVar7 = *puVar11;

            uVar10 = (uint)param_4 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                  [(*(uint *)(lVar1 + 8) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar10) {

              uVar10 = 0xff;

            }

            uVar13 = (uint)param_5 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar7) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar13) {

              uVar13 = 0xff;

            }

            uVar7 = (uint)param_6 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar7) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar15) / 0xff;

            if (0xff < uVar7) {

              uVar7 = 0xff;

            }

            *puVar11 = (uVar13 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                       (uVar10 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                       (uVar7 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar1 + 0x1e) & 0x1f) | *(uint *)(lVar1 + 0x14);

            puVar11 = puVar11 + 1;

          }

          puVar11 = puVar11 + iVar6;

          uVar8 = uVar8 - 1;

        }

        else {

          puVar11 = puVar11 + iVar6;

          uVar8 = uVar8 - 1;

        }

      }

    }

  }

  return CONCAT71((int7)(uVar5 >> 8),1);

}




