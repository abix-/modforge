// Address: 0x140247f90
// Ghidra name: FUN_140247f90
// ============ 0x140247f90 FUN_140247f90 (size=8669) ============


undefined8

FUN_140247f90(longlong param_1,int *param_2,undefined4 param_3,byte param_4,byte param_5,

             byte param_6,byte param_7)



{

  longlong lVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  uint uVar8;

  uint *puVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  int iVar13;

  int local_58;

  

  lVar1 = *(longlong *)(param_1 + 0x38);

  uVar12 = (uint)param_4;

  iVar7 = 0xff - (uint)param_7;

  if (*(char *)(lVar1 + 5) == '\x04') {

    switch(param_3) {

    case 1:

      uVar10 = param_2[2];

      iVar13 = (int)(*(int *)(param_1 + 0x10) + (*(int *)(param_1 + 0x10) >> 0x1f & 3U)) >> 2;

      iVar4 = iVar13 - uVar10;

      puVar9 = (uint *)(*(longlong *)(param_1 + 0x18) +

                       ((longlong)(iVar13 * param_2[1]) + (longlong)*param_2) * 4);

      uVar5 = param_2[3];

      while( true ) {

        uVar3 = (ulonglong)uVar5;

        if (uVar5 == 0) break;

        local_58 = (int)(uVar10 + 3 + ((int)(uVar10 + 3) >> 0x1f & 3U)) >> 2;

        uVar6 = uVar10 & 3;

        if (uVar6 == 0) goto LAB_1402480b0;

        if (uVar6 == 1) goto LAB_1402484c0;

        if (uVar6 == 2) goto LAB_140248365;

        if (uVar6 == 3) {

          while( true ) {

            uVar6 = *puVar9;

            *puVar9 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                    [(*(uint *)(lVar1 + 0x10) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff +

                       (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                    [(*(uint *)(lVar1 + 0xc) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff +

                       (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                    [(*(uint *)(lVar1 + 8) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar7) / 0xff + uVar12 >>

                      (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                    [(*(uint *)(lVar1 + 0x14) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1f) & 0x3f)] * iVar7) / 0xff +

                       (uint)param_7 >> (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

LAB_140248365:

            uVar6 = *puVar9;

            *puVar9 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                    [(*(uint *)(lVar1 + 0xc) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff +

                       (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                    [(*(uint *)(lVar1 + 8) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar7) / 0xff + uVar12 >>

                      (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                    [(*(uint *)(lVar1 + 0x10) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff +

                       (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                    [(*(uint *)(lVar1 + 0x14) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1f) & 0x3f)] * iVar7) / 0xff +

                       (uint)param_7 >> (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

LAB_1402484c0:

            uVar6 = *puVar9;

            *puVar9 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                    [(*(uint *)(lVar1 + 8) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar7) / 0xff + uVar12 >>

                      (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                    [(*(uint *)(lVar1 + 0x10) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff +

                       (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                    [(*(uint *)(lVar1 + 0xc) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff +

                       (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                    [(*(uint *)(lVar1 + 0x14) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1f) & 0x3f)] * iVar7) / 0xff +

                       (uint)param_7 >> (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

            local_58 = local_58 + -1;

            if (local_58 < 1) break;

LAB_1402480b0:

            uVar6 = *puVar9;

            *puVar9 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                    [(*(uint *)(lVar1 + 8) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1c) & 0x3f)] * iVar7) / 0xff + uVar12 >>

                      (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) << (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                    [(*(uint *)(lVar1 + 0x10) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff +

                       (uint)param_6 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                    [(*(uint *)(lVar1 + 0xc) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff +

                       (uint)param_5 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                    [(*(uint *)(lVar1 + 0x14) & uVar6) >>

                                     (*(byte *)(lVar1 + 0x1f) & 0x3f)] * iVar7) / 0xff +

                       (uint)param_7 >> (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

          }

          puVar9 = puVar9 + iVar4;

          uVar5 = uVar5 - 1;

        }

        else {

          puVar9 = puVar9 + iVar4;

          uVar5 = uVar5 - 1;

        }

      }

      break;

    case 2:

    case 0x20:

      uVar12 = param_2[2];

      iVar7 = *(int *)(param_1 + 0x10) / 4;

      iVar13 = iVar7 - uVar12;

      puVar9 = (uint *)(*(longlong *)(param_1 + 0x18) +

                       ((longlong)(iVar7 * param_2[1]) + (longlong)*param_2) * 4);

      uVar10 = param_2[3];

      while( true ) {

        uVar3 = (ulonglong)uVar10;

        if (uVar10 == 0) break;

        _param_7 = (int)(uVar12 + 3 + ((int)(uVar12 + 3) >> 0x1f & 3U)) >> 2;

        uVar5 = uVar12 & 3;

        if (uVar5 == 0) goto LAB_140248d9a;

        if (uVar5 == 1) goto LAB_14024911b;

        if (uVar5 == 2) goto LAB_140248ff0;

        if (uVar5 == 3) {

          while( true ) {

            uVar5 = *puVar9;

            uVar6 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                    + (uint)param_4;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                   [(*(uint *)(lVar1 + 8) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1c) & 0x3f)] + (uint)param_4) {

              uVar6 = 0xff;

            }

            uVar11 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                   [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5) {

              uVar11 = 0xff;

            }

            uVar8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                   [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6) {

              uVar8 = 0xff;

            }

            *puVar9 = (uVar6 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                   [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                            (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                      (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uVar11 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f);

            puVar9 = puVar9 + 1;

LAB_140248ff0:

            uVar5 = *puVar9;

            uVar6 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                    + (uint)param_4;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                   [(*(uint *)(lVar1 + 8) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1c) & 0x3f)] + (uint)param_4) {

              uVar6 = 0xff;

            }

            uVar11 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                   [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5) {

              uVar11 = 0xff;

            }

            uVar8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                   [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6) {

              uVar8 = 0xff;

            }

            *puVar9 = (uVar6 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                   [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                            (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                      (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uVar11 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f);

            puVar9 = puVar9 + 1;

LAB_14024911b:

            uVar5 = *puVar9;

            uVar6 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                    + (uint)param_4;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                   [(*(uint *)(lVar1 + 8) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1c) & 0x3f)] + (uint)param_4) {

              uVar6 = 0xff;

            }

            uVar11 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                   [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5) {

              uVar11 = 0xff;

            }

            uVar8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                   [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6) {

              uVar8 = 0xff;

            }

            _param_7 = _param_7 + -1;

            *puVar9 = (uVar6 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                   [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                            (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                      (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uVar11 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f);

            puVar9 = puVar9 + 1;

            if (_param_7 < 1) break;

LAB_140248d9a:

            uVar5 = *puVar9;

            uVar6 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                    + (uint)param_4;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                   [(*(uint *)(lVar1 + 8) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1c) & 0x3f)] + (uint)param_4) {

              uVar6 = 0xff;

            }

            uVar11 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                   [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1d) & 0x3f)] + (uint)param_5) {

              uVar11 = 0xff;

            }

            uVar8 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6;

            if (0xff < (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                   [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1e) & 0x3f)] + (uint)param_6) {

              uVar8 = 0xff;

            }

            *puVar9 = (uVar6 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                   [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                            (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                      (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uVar11 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f);

            puVar9 = puVar9 + 1;

          }

          puVar9 = puVar9 + iVar13;

          uVar10 = uVar10 - 1;

        }

        else {

          puVar9 = puVar9 + iVar13;

          uVar10 = uVar10 - 1;

        }

      }

      break;

    default:

      uVar12 = param_2[2];

      iVar7 = *(int *)(param_1 + 0x10) / 4;

      iVar13 = iVar7 - uVar12;

      puVar9 = (uint *)(*(longlong *)(param_1 + 0x18) +

                       ((longlong)(iVar7 * param_2[1]) + (longlong)*param_2) * 4);

      uVar10 = param_2[3];

      while( true ) {

        uVar3 = (ulonglong)uVar10;

        if (uVar10 == 0) break;

        iVar7 = (int)(((int)(uVar12 + 3) >> 0x1f & 3U) + uVar12 + 3) >> 2;

        uVar5 = uVar12 & 3;

        if (uVar5 == 0) goto LAB_140249fb0;

        if (uVar5 == 1) goto LAB_14024a0d0;

        if (uVar5 == 2) goto LAB_14024a070;

        if (uVar5 == 3) {

          while( true ) {

            *puVar9 = (uint)(param_4 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)(param_5 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (uint)(param_6 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uint)(param_7 >> (8U - *(char *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

LAB_14024a070:

            *puVar9 = (uint)(param_4 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)(param_5 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (uint)(param_6 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uint)(param_7 >> (8U - *(char *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

LAB_14024a0d0:

            iVar7 = iVar7 + -1;

            *puVar9 = (uint)(param_4 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)(param_5 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (uint)(param_6 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uint)(param_7 >> (8U - *(char *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

            if (iVar7 < 1) break;

LAB_140249fb0:

            *puVar9 = (uint)(param_4 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)(param_5 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (uint)(param_6 >> (8U - *(char *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uint)(param_7 >> (8U - *(char *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

          }

          puVar9 = puVar9 + iVar13;

          uVar10 = uVar10 - 1;

        }

        else {

          puVar9 = puVar9 + iVar13;

          uVar10 = uVar10 - 1;

        }

      }

      break;

    case 4:

      uVar12 = param_2[2];

      iVar7 = *(int *)(param_1 + 0x10) / 4;

      iVar13 = iVar7 - uVar12;

      puVar9 = (uint *)(*(longlong *)(param_1 + 0x18) +

                       ((longlong)(iVar7 * param_2[1]) + (longlong)*param_2) * 4);

      uVar10 = param_2[3];

      while( true ) {

        uVar3 = (ulonglong)uVar10;

        if (uVar10 == 0) break;

        _param_7 = (int)(uVar12 + 3 + ((int)(uVar12 + 3) >> 0x1f & 3U)) >> 2;

        uVar5 = uVar12 & 3;

        uVar6 = (uint)param_4;

        if (uVar5 == 0) goto LAB_140249305;

        if (uVar5 == 1) goto LAB_14024967b;

        if (uVar5 == 2) goto LAB_140249559;

        if (uVar5 == 3) {

          while( true ) {

            uVar5 = *puVar9;

            *puVar9 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                    [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                     (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_6) / 0xff >>

                      (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                    [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                     (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_5) / 0xff >>

                      (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                              [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] *

                       uVar6) / 0xff >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                   [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                            (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

LAB_140249559:

            uVar5 = *puVar9;

            *puVar9 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                    [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                     (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_6) / 0xff >>

                      (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                    [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                     (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_5) / 0xff >>

                      (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                              [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] *

                       uVar6) / 0xff >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                   [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                            (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

LAB_14024967b:

            uVar5 = *puVar9;

            _param_7 = _param_7 + -1;

            *puVar9 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                    [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                     (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_5) / 0xff >>

                      (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                              [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] *

                       uVar6) / 0xff >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                    [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                     (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_6) / 0xff >>

                      (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                   [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                            (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

            if (_param_7 < 1) break;

LAB_140249305:

            uVar5 = *puVar9;

            *puVar9 = (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                    [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                     (*(byte *)(lVar1 + 0x1e) & 0x3f)] * (uint)param_6) / 0xff >>

                      (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) << (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                    [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                     (*(byte *)(lVar1 + 0x1d) & 0x3f)] * (uint)param_5) / 0xff >>

                      (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) << (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                              [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)] *

                       uVar6) / 0xff >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                   [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                            (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

          }

          puVar9 = puVar9 + iVar13;

          uVar10 = uVar10 - 1;

        }

        else {

          puVar9 = puVar9 + iVar13;

          uVar10 = uVar10 - 1;

        }

      }

      break;

    case 8:

      uVar12 = param_2[2];

      iVar13 = *(int *)(param_1 + 0x10) / 4;

      iVar4 = iVar13 - uVar12;

      puVar9 = (uint *)(*(longlong *)(param_1 + 0x18) +

                       ((longlong)(iVar13 * param_2[1]) + (longlong)*param_2) * 4);

      uVar10 = param_2[3];

      while( true ) {

        uVar3 = (ulonglong)uVar10;

        if (uVar10 == 0) break;

        _param_7 = (int)(uVar12 + 3 + ((int)(uVar12 + 3) >> 0x1f & 3U)) >> 2;

        uVar5 = uVar12 & 3;

        if (uVar5 == 0) goto LAB_140249865;

        if (uVar5 == 1) goto LAB_140249d53;

        if (uVar5 == 2) goto LAB_140249baa;

        if (uVar5 == 3) {

          while( true ) {

            uVar5 = *puVar9;

            uVar6 = ((uint)param_4 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                    ) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar7) / 0xff;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar11 = ((uint)param_5 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar11) {

              uVar11 = 0xff;

            }

            uVar8 = ((uint)param_6 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)]) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            *puVar9 = (uVar11 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (uVar6 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                   [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                            (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                      (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f);

            puVar9 = puVar9 + 1;

LAB_140249baa:

            uVar5 = *puVar9;

            uVar6 = ((uint)param_4 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                    ) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar7) / 0xff;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar11 = ((uint)param_5 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar11) {

              uVar11 = 0xff;

            }

            uVar8 = ((uint)param_6 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)]) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            *puVar9 = (uVar6 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                   [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                            (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                      (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uVar11 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f);

            puVar9 = puVar9 + 1;

LAB_140249d53:

            uVar5 = *puVar9;

            uVar6 = ((uint)param_4 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                    ) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar7) / 0xff;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar11 = ((uint)param_5 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar11) {

              uVar11 = 0xff;

            }

            uVar8 = ((uint)param_6 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)]) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            _param_7 = _param_7 + -1;

            *puVar9 = (uVar6 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                   [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                            (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                      (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uVar11 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f);

            puVar9 = puVar9 + 1;

            if (_param_7 < 1) break;

LAB_140249865:

            uVar5 = *puVar9;

            uVar6 = ((uint)param_4 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)]

                    ) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar7) / 0xff;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar11 = ((uint)param_5 *

                     (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                 [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1d) & 0x3f)]) / 0xff +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar11) {

              uVar11 = 0xff;

            }

            uVar8 = ((uint)param_6 *

                    (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                 (*(byte *)(lVar1 + 0x1e) & 0x3f)]) / 0xff +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            *puVar9 = (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uVar11 >> (8 - *(byte *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f) |

                      (uVar6 >> (8U - *(char *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uint)((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                   [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                    (*(byte *)(lVar1 + 0x1f) & 0x3f)] >>

                            (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f);

            puVar9 = puVar9 + 1;

          }

          puVar9 = puVar9 + iVar4;

          uVar10 = uVar10 - 1;

        }

        else {

          puVar9 = puVar9 + iVar4;

          uVar10 = uVar10 - 1;

        }

      }

      break;

    case 0x10:

      uVar12 = param_2[2];

      iVar13 = *(int *)(param_1 + 0x10) / 4;

      iVar4 = iVar13 - uVar12;

      puVar9 = (uint *)(*(longlong *)(param_1 + 0x18) +

                       ((longlong)(iVar13 * param_2[1]) + (longlong)*param_2) * 4);

      uVar10 = param_2[3];

      while( true ) {

        uVar3 = (ulonglong)uVar10;

        if (uVar10 == 0) break;

        local_58 = (int)(uVar12 + 3 + ((int)(uVar12 + 3) >> 0x1f & 3U)) >> 2;

        uVar5 = uVar12 & 3;

        if (uVar5 == 0) goto LAB_1402486cc;

        if (uVar5 == 1) goto LAB_140248b64;

        if (uVar5 == 2) goto LAB_1402489dc;

        if (uVar5 == 3) {

          while( true ) {

            uVar5 = *puVar9;

            uVar6 = (uint)param_4 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar7) / 0xff;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar11 = (uint)param_5 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar11) {

              uVar11 = 0xff;

            }

            uVar8 = (uint)param_6 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            uVar5 = (uint)param_7 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                 [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1f) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar5) {

              uVar5 = 0xff;

            }

            *puVar9 = (uVar6 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uVar5 >> (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                      (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uVar11 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f);

            puVar9 = puVar9 + 1;

LAB_1402489dc:

            uVar5 = *puVar9;

            uVar6 = (uint)param_4 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar7) / 0xff;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar11 = (uint)param_5 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar11) {

              uVar11 = 0xff;

            }

            uVar8 = (uint)param_6 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            uVar5 = (uint)param_7 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                 [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1f) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar5) {

              uVar5 = 0xff;

            }

            *puVar9 = (uVar6 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uVar5 >> (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                      (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uVar11 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f);

            puVar9 = puVar9 + 1;

LAB_140248b64:

            uVar5 = *puVar9;

            uVar6 = (uint)param_4 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar7) / 0xff;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar11 = (uint)param_5 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar11) {

              uVar11 = 0xff;

            }

            uVar8 = (uint)param_6 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            uVar5 = (uint)param_7 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                 [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1f) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar5) {

              uVar5 = 0xff;

            }

            local_58 = local_58 + -1;

            *puVar9 = (uVar6 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uVar5 >> (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                      (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uVar11 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f);

            puVar9 = puVar9 + 1;

            if (local_58 < 1) break;

LAB_1402486cc:

            uVar5 = *puVar9;

            uVar6 = (uint)param_4 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x18)]

                                 [(*(uint *)(lVar1 + 8) & uVar5) >> (*(byte *)(lVar1 + 0x1c) & 0x3f)

                                 ] * iVar7) / 0xff;

            if (0xff < uVar6) {

              uVar6 = 0xff;

            }

            uVar11 = (uint)param_5 +

                     ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x19)]

                                  [(*(uint *)(lVar1 + 0xc) & uVar5) >>

                                   (*(byte *)(lVar1 + 0x1d) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar11) {

              uVar11 = 0xff;

            }

            uVar8 = (uint)param_6 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1a)]

                                 [(*(uint *)(lVar1 + 0x10) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1e) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar8) {

              uVar8 = 0xff;

            }

            uVar5 = (uint)param_7 +

                    ((uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar1 + 0x1b)]

                                 [(*(uint *)(lVar1 + 0x14) & uVar5) >>

                                  (*(byte *)(lVar1 + 0x1f) & 0x3f)] * iVar7) / 0xff;

            if (0xff < uVar5) {

              uVar5 = 0xff;

            }

            *puVar9 = (uVar6 >> (8 - *(byte *)(lVar1 + 0x18) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1c) & 0x1f) |

                      (uVar5 >> (8 - *(byte *)(lVar1 + 0x1b) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1f) & 0x1f) |

                      (uVar8 >> (8 - *(byte *)(lVar1 + 0x1a) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1e) & 0x1f) |

                      (uVar11 >> (8U - *(char *)(lVar1 + 0x19) & 0x1f)) <<

                      (*(byte *)(lVar1 + 0x1d) & 0x1f);

            puVar9 = puVar9 + 1;

          }

          puVar9 = puVar9 + iVar4;

          uVar10 = uVar10 - 1;

        }

        else {

          puVar9 = puVar9 + iVar4;

          uVar10 = uVar10 - 1;

        }

      }

    }

    return CONCAT71((int7)(uVar3 >> 8),1);

  }

  uVar2 = FUN_14012e850("That operation is not supported");

  return uVar2;

}




