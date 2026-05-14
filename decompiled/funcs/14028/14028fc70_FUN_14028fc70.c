// Address: 0x14028fc70
// Ghidra name: FUN_14028fc70
// ============ 0x14028fc70 FUN_14028fc70 (size=2498) ============


void FUN_14028fc70(longlong param_1)



{

  int *piVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  int iVar5;

  uint uVar6;

  longlong lVar7;

  longlong lVar8;

  byte bVar9;

  uint uVar10;

  int iVar11;

  int iVar12;

  uint uVar13;

  ushort uVar14;

  ushort uVar15;

  ushort uVar16;

  ushort uVar17;

  ushort uVar18;

  ushort uVar19;

  int iVar20;

  ushort uVar21;

  int iVar22;

  ulonglong uVar23;

  uint *puVar24;

  byte *pbVar25;

  int iVar26;

  uint uVar27;

  byte bVar28;

  int *local_78;

  byte local_6c;

  

  iVar26 = *(int *)(param_1 + 0x3c);

  lVar7 = *(longlong *)(param_1 + 0x58);

  piVar1 = (int *)(param_1 + 0x20);

  pbVar25 = *(byte **)(param_1 + 8);

  puVar24 = *(uint **)(param_1 + 0x30);

  iVar20 = *(int *)(param_1 + 0x1c);

  iVar5 = *(int *)(param_1 + 0x44);

  iVar22 = *piVar1;

  bVar2 = *(byte *)(lVar7 + 5);

  bVar3 = *(byte *)((longlong)*(uint **)(param_1 + 0x48) + 5);

  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 8);

  bVar4 = *(byte *)(param_1 + 0x83);

  iVar11 = *(int *)(param_1 + 0x38) + iVar22;

  uVar6 = *(uint *)(param_1 + 0x7c);

  if (bVar3 == 4) {

    iVar12 = iVar11 - (iVar11 + 1) / 2;

  }

  else if (bVar3 == 2) {

    iVar12 = iVar11 - ((int)(iVar11 + 3 + (iVar11 + 3 >> 0x1f & 3U)) >> 2);

  }

  else {

    if (bVar3 != 1) goto LAB_14028fd34;

    iVar12 = iVar11 - ((int)(iVar11 + 7 + (iVar11 + 7 >> 0x1f & 7U)) >> 3);

  }

  iVar20 = iVar20 + iVar12;

LAB_14028fd34:

  local_78 = (int *)(param_1 + 0x20);

  local_6c = (char)(1 << (bVar3 & 0x1f)) - 1;

  uVar10 = 8 / bVar3 - 1;

  if (iVar26 != 0) {

    if ((**(uint **)(param_1 + 0x48) & 0xf00000) == 0x100000) {

      do {

        iVar26 = iVar26 + -1;

        bVar28 = 0;

        uVar27 = 0;

        if (0 < iVar22) {

          do {

            if ((uVar27 & uVar10) == 0) {

              bVar28 = *pbVar25;

              pbVar25 = pbVar25 + 1;

            }

            bVar28 = bVar28 >> (bVar3 & 0x1f);

            uVar27 = uVar27 + 1;

          } while ((int)uVar27 < iVar22);

          iVar22 = *piVar1;

        }

        if ((int)uVar27 < iVar11) {

          do {

            if ((uVar27 & uVar10) == 0) {

              bVar28 = *pbVar25;

              pbVar25 = pbVar25 + 1;

            }

            bVar9 = local_6c & bVar28;

            uVar13 = (uint)bVar9;

            if (uVar13 != uVar6) {

              if (bVar2 == 1) {

                uVar23 = (ulonglong)(byte)*puVar24;

LAB_14028febc:

                uVar21 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                                       [(*(uint *)(lVar7 + 8) & uVar23) >>

                                        (*(byte *)(lVar7 + 0x1c) & 0x3f)];

                uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                                       [(*(uint *)(lVar7 + 0xc) & uVar23) >>

                                        (*(byte *)(lVar7 + 0x1d) & 0x3f)];

                uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                                       [(*(uint *)(lVar7 + 0x10) & uVar23) >>

                                        (*(byte *)(lVar7 + 0x1e) & 0x3f)];

                uVar17 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1b)]

                                       [(*(uint *)(lVar7 + 0x14) & uVar23) >>

                                        (*(byte *)(lVar7 + 0x1f) & 0x3f)];

              }

              else {

                if (bVar2 == 2) {

                  uVar23 = (ulonglong)(ushort)*puVar24;

                  goto LAB_14028febc;

                }

                if (bVar2 == 3) {

                  uVar17 = 0xff;

                  uVar21 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) +

                                            (longlong)puVar24);

                  uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) +

                                            (longlong)puVar24);

                  uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) +

                                            (longlong)puVar24);

                }

                else {

                  if (bVar2 == 4) {

                    uVar23 = (ulonglong)*puVar24;

                    goto LAB_14028febc;

                  }

                  uVar21 = 0;

                  uVar19 = 0;

                  uVar18 = 0;

                  uVar17 = 0;

                }

              }

              uVar14 = (*(byte *)(lVar8 + (ulonglong)bVar9 * 4) - uVar21) * (ushort)bVar4 +

                       uVar21 * 0xff + 1;

              uVar14 = (uVar14 >> 8) + uVar14;

              uVar21 = uVar14 >> 8;

              uVar15 = (*(byte *)(lVar8 + 1 + (ulonglong)uVar13 * 4) - uVar19) * (ushort)bVar4 +

                       uVar19 * 0xff + 1;

              uVar15 = (uVar15 >> 8) + uVar15;

              uVar19 = uVar15 >> 8;

              uVar16 = (*(byte *)(lVar8 + 2 + (ulonglong)uVar13 * 4) - uVar18) * (ushort)bVar4 +

                       uVar18 * 0xff + 1;

              uVar16 = (uVar16 >> 8) + uVar16;

              uVar18 = uVar16 >> 8;

              uVar17 = (0xff - uVar17) * (ushort)bVar4 + uVar17 * 0xff + 1;

              uVar17 = (ushort)((uVar17 >> 8) + uVar17) >> 8;

              if (bVar2 == 1) {

                *(char *)puVar24 =

                     (char)(uVar17 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1f) & 0x1f) |

                     (char)(uVar18 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1e) & 0x1f) |

                     (char)(uVar19 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1d) & 0x1f) |

                     (char)(uVar21 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1c) & 0x1f);

              }

              else if (bVar2 == 2) {

                *(ushort *)puVar24 =

                     (uVar17 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1f) & 0x1f) |

                     (uVar18 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1e) & 0x1f) |

                     (uVar19 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1d) & 0x1f) |

                     (uVar21 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1c) & 0x1f);

              }

              else if (bVar2 == 3) {

                *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar24) =

                     (byte)(uVar14 >> 8);

                *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar24) =

                     (byte)(uVar15 >> 8);

                *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar24) =

                     (byte)(uVar16 >> 8);

              }

              else if (bVar2 == 4) {

                *puVar24 = (uint)(uVar17 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

                           (*(byte *)(lVar7 + 0x1f) & 0x1f) |

                           (uint)(uVar18 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

                           (*(byte *)(lVar7 + 0x1e) & 0x1f) |

                           (uint)(uVar19 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

                           (*(byte *)(lVar7 + 0x1d) & 0x1f) |

                           (uint)(uVar21 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

                           (*(byte *)(lVar7 + 0x1c) & 0x1f);

              }

            }

            uVar27 = uVar27 + 1;

            puVar24 = (uint *)((longlong)puVar24 + (longlong)(int)(uint)bVar2);

            bVar28 = bVar28 >> (bVar3 & 0x1f);

          } while ((int)uVar27 < iVar11);

          iVar22 = *piVar1;

        }

        pbVar25 = pbVar25 + iVar20;

        puVar24 = (uint *)((longlong)puVar24 + (longlong)iVar5);

      } while (iVar26 != 0);

    }

    else {

      do {

        iVar26 = iVar26 + -1;

        bVar28 = 0;

        uVar27 = 0;

        if (0 < iVar22) {

          do {

            if ((uVar27 & uVar10) == 0) {

              bVar28 = *pbVar25;

              pbVar25 = pbVar25 + 1;

            }

            bVar28 = bVar28 << (bVar3 & 0x1f);

            uVar27 = uVar27 + 1;

          } while ((int)uVar27 < iVar22);

          iVar22 = *local_78;

        }

        if ((int)uVar27 < iVar11) {

          do {

            if ((uVar27 & uVar10) == 0) {

              bVar28 = *pbVar25;

              pbVar25 = pbVar25 + 1;

            }

            bVar9 = bVar28 >> (8 - bVar3 & 0x1f) & local_6c;

            uVar13 = (uint)bVar9;

            if (uVar13 != uVar6) {

              if (bVar2 == 1) {

                uVar23 = (ulonglong)(byte)*puVar24;

LAB_14029030a:

                uVar21 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                                       [(*(uint *)(lVar7 + 8) & uVar23) >>

                                        (*(byte *)(lVar7 + 0x1c) & 0x3f)];

                uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                                       [(*(uint *)(lVar7 + 0xc) & uVar23) >>

                                        (*(byte *)(lVar7 + 0x1d) & 0x3f)];

                uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                                       [(*(uint *)(lVar7 + 0x10) & uVar23) >>

                                        (*(byte *)(lVar7 + 0x1e) & 0x3f)];

                uVar17 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1b)]

                                       [(*(uint *)(lVar7 + 0x14) & uVar23) >>

                                        (*(byte *)(lVar7 + 0x1f) & 0x3f)];

              }

              else {

                if (bVar2 == 2) {

                  uVar23 = (ulonglong)(ushort)*puVar24;

                  goto LAB_14029030a;

                }

                if (bVar2 == 3) {

                  uVar17 = 0xff;

                  uVar21 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) +

                                            (longlong)puVar24);

                  uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) +

                                            (longlong)puVar24);

                  uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) +

                                            (longlong)puVar24);

                }

                else {

                  if (bVar2 == 4) {

                    uVar23 = (ulonglong)*puVar24;

                    goto LAB_14029030a;

                  }

                  uVar21 = 0;

                  uVar19 = 0;

                  uVar18 = 0;

                  uVar17 = 0;

                }

              }

              uVar14 = (*(byte *)(lVar8 + (ulonglong)bVar9 * 4) - uVar21) * (ushort)bVar4 +

                       uVar21 * 0xff + 1;

              uVar14 = (uVar14 >> 8) + uVar14;

              uVar21 = uVar14 >> 8;

              uVar15 = (*(byte *)(lVar8 + 1 + (ulonglong)uVar13 * 4) - uVar19) * (ushort)bVar4 +

                       uVar19 * 0xff + 1;

              uVar15 = (uVar15 >> 8) + uVar15;

              uVar19 = uVar15 >> 8;

              uVar16 = (*(byte *)(lVar8 + 2 + (ulonglong)uVar13 * 4) - uVar18) * (ushort)bVar4 +

                       uVar18 * 0xff + 1;

              uVar16 = (uVar16 >> 8) + uVar16;

              uVar18 = uVar16 >> 8;

              uVar17 = (0xff - uVar17) * (ushort)bVar4 + uVar17 * 0xff + 1;

              uVar17 = (ushort)((uVar17 >> 8) + uVar17) >> 8;

              if (bVar2 == 1) {

                *(char *)puVar24 =

                     (char)(uVar17 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1f) & 0x1f) |

                     (char)(uVar18 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1e) & 0x1f) |

                     (char)(uVar19 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1d) & 0x1f) |

                     (char)(uVar21 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1c) & 0x1f);

              }

              else if (bVar2 == 2) {

                *(ushort *)puVar24 =

                     (uVar17 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1f) & 0x1f) |

                     (uVar18 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1e) & 0x1f) |

                     (uVar19 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1d) & 0x1f) |

                     (uVar21 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

                     (*(byte *)(lVar7 + 0x1c) & 0x1f);

              }

              else if (bVar2 == 3) {

                *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar24) =

                     (byte)(uVar14 >> 8);

                *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar24) =

                     (byte)(uVar15 >> 8);

                *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar24) =

                     (byte)(uVar16 >> 8);

              }

              else if (bVar2 == 4) {

                *puVar24 = (uint)(uVar17 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

                           (*(byte *)(lVar7 + 0x1f) & 0x1f) |

                           (uint)(uVar18 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

                           (*(byte *)(lVar7 + 0x1e) & 0x1f) |

                           (uint)(uVar19 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

                           (*(byte *)(lVar7 + 0x1d) & 0x1f) |

                           (uint)(uVar21 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

                           (*(byte *)(lVar7 + 0x1c) & 0x1f);

              }

            }

            uVar27 = uVar27 + 1;

            puVar24 = (uint *)((longlong)puVar24 + (longlong)(int)(uint)bVar2);

            bVar28 = bVar28 << (bVar3 & 0x1f);

          } while ((int)uVar27 < iVar11);

          iVar22 = *local_78;

        }

        pbVar25 = pbVar25 + iVar20;

        puVar24 = (uint *)((longlong)puVar24 + (longlong)iVar5);

      } while (iVar26 != 0);

    }

  }

  return;

}




