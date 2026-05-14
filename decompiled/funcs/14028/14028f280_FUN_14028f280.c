// Address: 0x14028f280
// Ghidra name: FUN_14028f280
// ============ 0x14028f280 FUN_14028f280 (size=2533) ============


void FUN_14028f280(longlong param_1)



{

  int *piVar1;

  byte bVar2;

  byte bVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  uint uVar7;

  int iVar8;

  int iVar9;

  ulonglong uVar10;

  ushort uVar11;

  ushort uVar12;

  ushort uVar13;

  ushort uVar14;

  uint uVar15;

  ushort uVar16;

  int iVar17;

  ushort uVar18;

  uint *puVar19;

  byte *pbVar20;

  ushort uVar21;

  uint uVar22;

  ulonglong uVar23;

  int iVar24;

  byte bVar25;

  int iVar26;

  int *local_a0;

  byte local_88;

  

  iVar26 = *(int *)(param_1 + 0x3c);

  pbVar20 = *(byte **)(param_1 + 8);

  piVar1 = (int *)(param_1 + 0x20);

  puVar19 = *(uint **)(param_1 + 0x30);

  iVar17 = *(int *)(param_1 + 0x1c);

  lVar5 = *(longlong *)(param_1 + 0x58);

  iVar4 = *(int *)(param_1 + 0x44);

  bVar2 = *(byte *)((longlong)*(uint **)(param_1 + 0x48) + 5);

  iVar9 = *piVar1;

  iVar24 = *(int *)(param_1 + 0x38) + iVar9;

  uVar23 = (ulonglong)*(byte *)(lVar5 + 5);

  lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 8);

  bVar3 = *(byte *)(param_1 + 0x83);

  uVar22 = (uint)*(byte *)(lVar5 + 5);

  if (bVar2 == 4) {

    iVar8 = iVar24 - (iVar24 + 1) / 2;

  }

  else if (bVar2 == 2) {

    iVar8 = iVar24 - ((int)(iVar24 + 3 + (iVar24 + 3 >> 0x1f & 3U)) >> 2);

  }

  else {

    if (bVar2 != 1) goto LAB_14028f34d;

    iVar8 = iVar24 - ((int)(iVar24 + 7 + (iVar24 + 7 >> 0x1f & 7U)) >> 3);

  }

  iVar17 = iVar17 + iVar8;

LAB_14028f34d:

  local_a0 = (int *)(param_1 + 0x20);

  local_88 = (char)(1 << (bVar2 & 0x1f)) - 1;

  uVar7 = 8 / bVar2 - 1;

  if (iVar26 != 0) {

    if ((**(uint **)(param_1 + 0x48) & 0xf00000) == 0x100000) {

      do {

        iVar26 = iVar26 + -1;

        uVar15 = 0;

        bVar25 = 0;

        if (0 < iVar9) {

          do {

            if ((uVar15 & uVar7) == 0) {

              bVar25 = *pbVar20;

              pbVar20 = pbVar20 + 1;

            }

            bVar25 = bVar25 >> (bVar2 & 0x1f);

            uVar15 = uVar15 + 1;

          } while ((int)uVar15 < iVar9);

          iVar9 = *piVar1;

          uVar23 = (ulonglong)uVar22;

        }

        if ((int)uVar15 < iVar24) {

          do {

            if ((uVar7 & uVar15) == 0) {

              bVar25 = *pbVar20;

              pbVar20 = pbVar20 + 1;

            }

            uVar10 = (ulonglong)(local_88 & bVar25);

            iVar9 = (int)uVar23;

            if (iVar9 == 1) {

              uVar23 = (ulonglong)(byte)*puVar19;

LAB_14028f4b4:

              uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                     [(*(uint *)(lVar5 + 8) & uVar23) >>

                                      (*(byte *)(lVar5 + 0x1c) & 0x3f)];

              uVar16 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                                     [(*(uint *)(lVar5 + 0xc) & uVar23) >>

                                      (*(byte *)(lVar5 + 0x1d) & 0x3f)];

              uVar21 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                                     [(*(uint *)(lVar5 + 0x10) & uVar23) >>

                                      (*(byte *)(lVar5 + 0x1e) & 0x3f)];

              uVar14 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                                     [(*(uint *)(lVar5 + 0x14) & uVar23) >>

                                      (*(byte *)(lVar5 + 0x1f) & 0x3f)];

            }

            else {

              if (iVar9 == 2) {

                uVar23 = (ulonglong)(ushort)*puVar19;

                goto LAB_14028f4b4;

              }

              if (iVar9 == 3) {

                uVar14 = 0xff;

                uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar5 + 0x1c) >> 3) +

                                          (longlong)puVar19);

                uVar16 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar5 + 0x1d) >> 3) +

                                          (longlong)puVar19);

                uVar21 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar5 + 0x1e) >> 3) +

                                          (longlong)puVar19);

              }

              else {

                if (iVar9 == 4) {

                  uVar23 = (ulonglong)*puVar19;

                  goto LAB_14028f4b4;

                }

                uVar18 = 0;

                uVar16 = 0;

                uVar21 = 0;

                uVar14 = 0;

              }

            }

            uVar11 = (*(byte *)(lVar6 + uVar10 * 4) - uVar18) * (ushort)bVar3 + uVar18 * 0xff + 1;

            uVar11 = (uVar11 >> 8) + uVar11;

            uVar18 = uVar11 >> 8;

            uVar12 = (*(byte *)(lVar6 + 1 + uVar10 * 4) - uVar16) * (ushort)bVar3 +

                     uVar16 * 0xff + 1;

            uVar12 = (uVar12 >> 8) + uVar12;

            uVar16 = uVar12 >> 8;

            uVar13 = (*(byte *)(lVar6 + 2 + uVar10 * 4) - uVar21) * (ushort)bVar3 +

                     uVar21 * 0xff + 1;

            uVar13 = (uVar13 >> 8) + uVar13;

            uVar21 = uVar13 >> 8;

            uVar23 = (ulonglong)(int)uVar22;

            uVar14 = (0xff - uVar14) * (ushort)bVar3 + uVar14 * 0xff + 1;

            uVar14 = (ushort)((uVar14 >> 8) + uVar14) >> 8;

            if (uVar22 == 1) {

              *(char *)puVar19 =

                   (char)(uVar14 >> (8U - *(char *)(lVar5 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                   (char)(uVar21 >> (8U - *(char *)(lVar5 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                   (char)(uVar16 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                   (char)(uVar18 >> (8U - *(char *)(lVar5 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1c) & 0x1f);

            }

            else if (uVar22 == 2) {

              *(ushort *)puVar19 =

                   (uVar14 >> (8U - *(char *)(lVar5 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                   (uVar21 >> (8U - *(char *)(lVar5 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                   (uVar16 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                   (uVar18 >> (8U - *(char *)(lVar5 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1c) & 0x1f);

            }

            else if (uVar22 == 3) {

              *(byte *)((ulonglong)(*(byte *)(lVar5 + 0x1c) >> 3) + (longlong)puVar19) =

                   (byte)(uVar11 >> 8);

              *(byte *)((ulonglong)(*(byte *)(lVar5 + 0x1d) >> 3) + (longlong)puVar19) =

                   (byte)(uVar12 >> 8);

              *(byte *)((ulonglong)(*(byte *)(lVar5 + 0x1e) >> 3) + (longlong)puVar19) =

                   (byte)(uVar13 >> 8);

            }

            else if (uVar22 == 4) {

              *puVar19 = (uint)(uVar14 >> (8U - *(char *)(lVar5 + 0x1b) & 0x1f)) <<

                         (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                         (uint)(uVar21 >> (8U - *(char *)(lVar5 + 0x1a) & 0x1f)) <<

                         (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                         (uint)(uVar16 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                         (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                         (uint)(uVar18 >> (8U - *(char *)(lVar5 + 0x18) & 0x1f)) <<

                         (*(byte *)(lVar5 + 0x1c) & 0x1f);

            }

            puVar19 = (uint *)((longlong)puVar19 + uVar23);

            uVar15 = uVar15 + 1;

            bVar25 = bVar25 >> (bVar2 & 0x1f);

          } while ((int)uVar15 < iVar24);

          iVar9 = *piVar1;

        }

        pbVar20 = pbVar20 + iVar17;

        puVar19 = (uint *)((longlong)puVar19 + (longlong)iVar4);

      } while (iVar26 != 0);

    }

    else {

      do {

        iVar26 = iVar26 + -1;

        uVar15 = 0;

        bVar25 = 0;

        if (0 < iVar9) {

          do {

            if ((uVar15 & uVar7) == 0) {

              bVar25 = *pbVar20;

              pbVar20 = pbVar20 + 1;

            }

            bVar25 = bVar25 << (bVar2 & 0x1f);

            uVar15 = uVar15 + 1;

          } while ((int)uVar15 < iVar9);

          iVar9 = *local_a0;

        }

        if ((int)uVar15 < iVar24) {

          do {

            if ((uVar7 & uVar15) == 0) {

              bVar25 = *pbVar20;

              pbVar20 = pbVar20 + 1;

            }

            uVar10 = (ulonglong)(bVar25 >> (8 - bVar2 & 0x3f) & local_88);

            iVar9 = (int)uVar23;

            if (iVar9 == 1) {

              uVar23 = (ulonglong)(byte)*puVar19;

LAB_14028f91d:

              uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x18)]

                                     [(*(uint *)(lVar5 + 8) & uVar23) >>

                                      (*(byte *)(lVar5 + 0x1c) & 0x3f)];

              uVar16 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x19)]

                                     [(*(uint *)(lVar5 + 0xc) & uVar23) >>

                                      (*(byte *)(lVar5 + 0x1d) & 0x3f)];

              uVar21 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1a)]

                                     [(*(uint *)(lVar5 + 0x10) & uVar23) >>

                                      (*(byte *)(lVar5 + 0x1e) & 0x3f)];

              uVar14 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar5 + 0x1b)]

                                     [(*(uint *)(lVar5 + 0x14) & uVar23) >>

                                      (*(byte *)(lVar5 + 0x1f) & 0x3f)];

            }

            else {

              if (iVar9 == 2) {

                uVar23 = (ulonglong)(ushort)*puVar19;

                goto LAB_14028f91d;

              }

              if (iVar9 == 3) {

                uVar14 = 0xff;

                uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar5 + 0x1c) >> 3) +

                                          (longlong)puVar19);

                uVar16 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar5 + 0x1d) >> 3) +

                                          (longlong)puVar19);

                uVar21 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar5 + 0x1e) >> 3) +

                                          (longlong)puVar19);

              }

              else {

                if (iVar9 == 4) {

                  uVar23 = (ulonglong)*puVar19;

                  goto LAB_14028f91d;

                }

                uVar18 = 0;

                uVar16 = 0;

                uVar21 = 0;

                uVar14 = 0;

              }

            }

            uVar11 = (*(byte *)(lVar6 + uVar10 * 4) - uVar18) * (ushort)bVar3 + uVar18 * 0xff + 1;

            uVar11 = (uVar11 >> 8) + uVar11;

            uVar18 = uVar11 >> 8;

            uVar12 = (*(byte *)(lVar6 + 1 + uVar10 * 4) - uVar16) * (ushort)bVar3 +

                     uVar16 * 0xff + 1;

            uVar12 = (uVar12 >> 8) + uVar12;

            uVar16 = uVar12 >> 8;

            uVar13 = (*(byte *)(lVar6 + 2 + uVar10 * 4) - uVar21) * (ushort)bVar3 +

                     uVar21 * 0xff + 1;

            uVar13 = (uVar13 >> 8) + uVar13;

            uVar21 = uVar13 >> 8;

            uVar23 = (ulonglong)(int)uVar22;

            uVar14 = (0xff - uVar14) * (ushort)bVar3 + uVar14 * 0xff + 1;

            uVar14 = (ushort)((uVar14 >> 8) + uVar14) >> 8;

            if (uVar22 == 1) {

              *(char *)puVar19 =

                   (char)(uVar14 >> (8U - *(char *)(lVar5 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                   (char)(uVar21 >> (8U - *(char *)(lVar5 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                   (char)(uVar16 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                   (char)(uVar18 >> (8U - *(char *)(lVar5 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1c) & 0x1f);

            }

            else if (uVar22 == 2) {

              *(ushort *)puVar19 =

                   (uVar14 >> (8U - *(char *)(lVar5 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                   (uVar21 >> (8U - *(char *)(lVar5 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                   (uVar16 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                   (uVar18 >> (8U - *(char *)(lVar5 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar5 + 0x1c) & 0x1f);

            }

            else if (uVar22 == 3) {

              *(byte *)((ulonglong)(*(byte *)(lVar5 + 0x1c) >> 3) + (longlong)puVar19) =

                   (byte)(uVar11 >> 8);

              *(byte *)((ulonglong)(*(byte *)(lVar5 + 0x1d) >> 3) + (longlong)puVar19) =

                   (byte)(uVar12 >> 8);

              *(byte *)((ulonglong)(*(byte *)(lVar5 + 0x1e) >> 3) + (longlong)puVar19) =

                   (byte)(uVar13 >> 8);

            }

            else if (uVar22 == 4) {

              *puVar19 = (uint)(uVar14 >> (8U - *(char *)(lVar5 + 0x1b) & 0x1f)) <<

                         (*(byte *)(lVar5 + 0x1f) & 0x1f) |

                         (uint)(uVar21 >> (8U - *(char *)(lVar5 + 0x1a) & 0x1f)) <<

                         (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                         (uint)(uVar16 >> (8U - *(char *)(lVar5 + 0x19) & 0x1f)) <<

                         (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                         (uint)(uVar18 >> (8U - *(char *)(lVar5 + 0x18) & 0x1f)) <<

                         (*(byte *)(lVar5 + 0x1c) & 0x1f);

            }

            puVar19 = (uint *)((longlong)puVar19 + uVar23);

            uVar15 = uVar15 + 1;

            bVar25 = bVar25 << (bVar2 & 0x1f);

          } while ((int)uVar15 < iVar24);

          iVar9 = *local_a0;

        }

        pbVar20 = pbVar20 + iVar17;

        puVar19 = (uint *)((longlong)puVar19 + (longlong)iVar4);

      } while (iVar26 != 0);

    }

  }

  return;

}




