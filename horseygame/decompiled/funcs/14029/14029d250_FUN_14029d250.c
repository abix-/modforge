// Address: 0x14029d250
// Ghidra name: FUN_14029d250
// ============ 0x14029d250 FUN_14029d250 (size=4412) ============


void FUN_14029d250(longlong param_1)



{

  int iVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  byte bVar6;

  byte bVar7;

  int iVar8;

  uint uVar9;

  int iVar10;

  longlong lVar11;

  longlong lVar12;

  ushort uVar13;

  ushort uVar14;

  ushort uVar15;

  ushort uVar16;

  ushort uVar17;

  int iVar18;

  uint uVar19;

  uint *puVar20;

  ushort uVar21;

  ushort uVar22;

  ulonglong uVar23;

  uint *puVar24;

  ushort uVar25;

  uint uVar26;

  ushort local_res10;

  int local_60;

  

  iVar8 = *(int *)(param_1 + 0x1c);

  lVar11 = *(longlong *)(param_1 + 0x48);

  lVar12 = *(longlong *)(param_1 + 0x58);

  uVar9 = *(uint *)(param_1 + 0x38);

  iVar18 = *(int *)(param_1 + 0x3c);

  puVar20 = *(uint **)(param_1 + 8);

  puVar24 = *(uint **)(param_1 + 0x30);

  bVar2 = *(byte *)(lVar11 + 5);

  bVar3 = *(byte *)(lVar12 + 5);

  iVar10 = *(int *)(param_1 + 0x44);

  bVar4 = *(byte *)(param_1 + 0x83);

  if (bVar4 != 0) {

    while (iVar18 != 0) {

      iVar1 = uVar9 + 3;

      local_60 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;

      uVar19 = uVar9 & 3;

      uVar26 = (uint)bVar2;

      if (uVar19 == 0) goto LAB_14029d309;

      if (uVar19 == 1) goto LAB_14029df37;

      if (uVar19 == 2) goto LAB_14029db33;

      if (uVar19 == 3) {

        do {

          uVar25 = 0;

          if (bVar2 == 1) {

            uVar23 = (ulonglong)(byte)*puVar20;

LAB_14029d783:

            uVar17 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

                                   [(*(uint *)(lVar11 + 8) & uVar23) >>

                                    (*(byte *)(lVar11 + 0x1c) & 0x3f)];

            uVar21 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

                                   [(*(uint *)(lVar11 + 0xc) & uVar23) >>

                                    (*(byte *)(lVar11 + 0x1d) & 0x3f)];

            uVar22 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1a)]

                                   [(*(uint *)(lVar11 + 0x10) & uVar23) >>

                                    (*(byte *)(lVar11 + 0x1e) & 0x3f)];

          }

          else {

            if (bVar2 == 2) {

              uVar23 = (ulonglong)(ushort)*puVar20;

              goto LAB_14029d783;

            }

            if (bVar2 == 3) {

              uVar17 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) +

                                        (longlong)puVar20);

              uVar21 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) +

                                        (longlong)puVar20);

              uVar22 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) +

                                        (longlong)puVar20);

            }

            else {

              if (bVar2 == 4) {

                uVar23 = (ulonglong)*puVar20;

                goto LAB_14029d783;

              }

              uVar17 = 0;

              uVar21 = 0;

              uVar22 = 0;

            }

          }

          if (bVar3 == 1) {

            uVar23 = (ulonglong)(byte)*puVar24;

LAB_14029d851:

            bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x18)]

                    [(*(uint *)(lVar12 + 8) & uVar23) >> (*(byte *)(lVar12 + 0x1c) & 0x3f)];

            bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x19)]

                    [(*(uint *)(lVar12 + 0xc) & uVar23) >> (*(byte *)(lVar12 + 0x1d) & 0x3f)];

            bVar7 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x1a)]

                    [(*(uint *)(lVar12 + 0x10) & uVar23) >> (*(byte *)(lVar12 + 0x1e) & 0x3f)];

            uVar13 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x1b)]

                                   [(*(uint *)(lVar12 + 0x14) & uVar23) >>

                                    (*(byte *)(lVar12 + 0x1f) & 0x3f)];

LAB_14029d8d8:

            local_res10 = (ushort)bVar7;

            uVar15 = (ushort)bVar6;

            uVar25 = (ushort)bVar5;

          }

          else {

            if (bVar3 == 2) {

              uVar23 = (ulonglong)(ushort)*puVar24;

              goto LAB_14029d851;

            }

            if (bVar3 == 3) {

              bVar5 = *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1c) >> 3) + (longlong)puVar24);

              bVar6 = *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1d) >> 3) + (longlong)puVar24);

              bVar7 = *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1e) >> 3) + (longlong)puVar24);

              uVar13 = 0xff;

              goto LAB_14029d8d8;

            }

            if (bVar3 == 4) {

              uVar23 = (ulonglong)*puVar24;

              goto LAB_14029d851;

            }

            uVar15 = 0;

            local_res10 = 0;

            uVar13 = 0;

          }

          uVar14 = (uVar17 - uVar25) * (ushort)bVar4 + uVar25 * 0xff + 1;

          uVar14 = (uVar14 >> 8) + uVar14;

          uVar25 = uVar14 >> 8;

          uVar15 = (uVar21 - uVar15) * (ushort)bVar4 + uVar15 * 0xff + 1;

          uVar15 = (uVar15 >> 8) + uVar15;

          uVar21 = uVar15 >> 8;

          uVar16 = (uVar22 - local_res10) * (ushort)bVar4 + local_res10 * 0xff + 1;

          uVar16 = (uVar16 >> 8) + uVar16;

          uVar22 = uVar16 >> 8;

          uVar17 = (0xff - uVar13) * (ushort)bVar4 + uVar13 * 0xff + 1;

          uVar17 = (ushort)((uVar17 >> 8) + uVar17) >> 8;

          if (bVar3 == 1) {

            *(char *)puVar24 =

                 (char)(uVar17 >> (8U - *(char *)(lVar12 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1f) & 0x1f) |

                 (char)(uVar25 >> (8U - *(char *)(lVar12 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1c) & 0x1f) |

                 (char)(uVar22 >> (8U - *(char *)(lVar12 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1e) & 0x1f) |

                 (char)(uVar21 >> (8U - *(char *)(lVar12 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1d) & 0x1f);

          }

          else if (bVar3 == 2) {

            *(ushort *)puVar24 =

                 (uVar17 >> (8U - *(char *)(lVar12 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1f) & 0x1f) |

                 (uVar22 >> (8U - *(char *)(lVar12 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1e) & 0x1f) |

                 (uVar25 >> (8U - *(char *)(lVar12 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1c) & 0x1f) |

                 (uVar21 >> (8U - *(char *)(lVar12 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1d) & 0x1f);

          }

          else if (bVar3 == 3) {

            *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1c) >> 3) + (longlong)puVar24) =

                 (byte)(uVar14 >> 8);

            *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1d) >> 3) + (longlong)puVar24) =

                 (byte)(uVar15 >> 8);

            *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1e) >> 3) + (longlong)puVar24) =

                 (byte)(uVar16 >> 8);

          }

          else if (bVar3 == 4) {

            *puVar24 = (uint)(uVar17 >> (8U - *(char *)(lVar12 + 0x1b) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1f) & 0x1f) |

                       (uint)(uVar21 >> (8U - *(char *)(lVar12 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1d) & 0x1f) |

                       (uint)(uVar25 >> (8U - *(char *)(lVar12 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1c) & 0x1f) |

                       (uint)(uVar22 >> (8U - *(char *)(lVar12 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1e) & 0x1f);

          }

          puVar20 = (uint *)((longlong)puVar20 + (longlong)(int)uVar26);

          puVar24 = (uint *)((longlong)puVar24 + (longlong)(int)(uint)bVar3);

LAB_14029db33:

          uVar25 = 0;

          if (bVar2 == 1) {

            uVar23 = (ulonglong)(byte)*puVar20;

LAB_14029db93:

            uVar17 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

                                   [(*(uint *)(lVar11 + 8) & uVar23) >>

                                    (*(byte *)(lVar11 + 0x1c) & 0x3f)];

            uVar21 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

                                   [(*(uint *)(lVar11 + 0xc) & uVar23) >>

                                    (*(byte *)(lVar11 + 0x1d) & 0x3f)];

            uVar22 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1a)]

                                   [(*(uint *)(lVar11 + 0x10) & uVar23) >>

                                    (*(byte *)(lVar11 + 0x1e) & 0x3f)];

          }

          else {

            if (bVar2 == 2) {

              uVar23 = (ulonglong)(ushort)*puVar20;

              goto LAB_14029db93;

            }

            if (bVar2 == 3) {

              uVar17 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) +

                                        (longlong)puVar20);

              uVar21 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) +

                                        (longlong)puVar20);

              uVar22 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) +

                                        (longlong)puVar20);

            }

            else {

              if (bVar2 == 4) {

                uVar23 = (ulonglong)*puVar20;

                goto LAB_14029db93;

              }

              uVar17 = 0;

              uVar21 = 0;

              uVar22 = 0;

            }

          }

          if (bVar3 == 1) {

            uVar23 = (ulonglong)(byte)*puVar24;

LAB_14029dc5d:

            bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x18)]

                    [(*(uint *)(lVar12 + 8) & uVar23) >> (*(byte *)(lVar12 + 0x1c) & 0x3f)];

            bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x19)]

                    [(*(uint *)(lVar12 + 0xc) & uVar23) >> (*(byte *)(lVar12 + 0x1d) & 0x3f)];

            bVar7 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x1a)]

                    [(*(uint *)(lVar12 + 0x10) & uVar23) >> (*(byte *)(lVar12 + 0x1e) & 0x3f)];

            uVar13 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x1b)]

                                   [(*(uint *)(lVar12 + 0x14) & uVar23) >>

                                    (*(byte *)(lVar12 + 0x1f) & 0x3f)];

LAB_14029dce4:

            local_res10 = (ushort)bVar7;

            uVar15 = (ushort)bVar6;

            uVar25 = (ushort)bVar5;

          }

          else {

            if (bVar3 == 2) {

              uVar23 = (ulonglong)(ushort)*puVar24;

              goto LAB_14029dc5d;

            }

            if (bVar3 == 3) {

              bVar5 = *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1c) >> 3) + (longlong)puVar24);

              bVar6 = *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1d) >> 3) + (longlong)puVar24);

              bVar7 = *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1e) >> 3) + (longlong)puVar24);

              uVar13 = 0xff;

              goto LAB_14029dce4;

            }

            if (bVar3 == 4) {

              uVar23 = (ulonglong)*puVar24;

              goto LAB_14029dc5d;

            }

            uVar15 = 0;

            local_res10 = 0;

            uVar13 = 0;

          }

          uVar14 = (uVar17 - uVar25) * (ushort)bVar4 + uVar25 * 0xff + 1;

          uVar14 = (uVar14 >> 8) + uVar14;

          uVar25 = uVar14 >> 8;

          uVar15 = (uVar21 - uVar15) * (ushort)bVar4 + uVar15 * 0xff + 1;

          uVar15 = (uVar15 >> 8) + uVar15;

          uVar21 = uVar15 >> 8;

          uVar16 = (uVar22 - local_res10) * (ushort)bVar4 + local_res10 * 0xff + 1;

          uVar16 = (uVar16 >> 8) + uVar16;

          uVar22 = uVar16 >> 8;

          uVar17 = (0xff - uVar13) * (ushort)bVar4 + uVar13 * 0xff + 1;

          uVar17 = (ushort)((uVar17 >> 8) + uVar17) >> 8;

          if (bVar3 == 1) {

            *(char *)puVar24 =

                 (char)(uVar17 >> (8U - *(char *)(lVar12 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1f) & 0x1f) |

                 (char)(uVar21 >> (8U - *(char *)(lVar12 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1d) & 0x1f) |

                 (char)(uVar25 >> (8U - *(char *)(lVar12 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1c) & 0x1f) |

                 (char)(uVar22 >> (8U - *(char *)(lVar12 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1e) & 0x1f);

          }

          else if (bVar3 == 2) {

            *(ushort *)puVar24 =

                 (uVar17 >> (8U - *(char *)(lVar12 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1f) & 0x1f) |

                 (uVar22 >> (8U - *(char *)(lVar12 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1e) & 0x1f) |

                 (uVar21 >> (8U - *(char *)(lVar12 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1d) & 0x1f) |

                 (uVar25 >> (8U - *(char *)(lVar12 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1c) & 0x1f);

          }

          else if (bVar3 == 3) {

            *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1c) >> 3) + (longlong)puVar24) =

                 (byte)(uVar14 >> 8);

            *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1d) >> 3) + (longlong)puVar24) =

                 (byte)(uVar15 >> 8);

            *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1e) >> 3) + (longlong)puVar24) =

                 (byte)(uVar16 >> 8);

          }

          else if (bVar3 == 4) {

            *puVar24 = (uint)(uVar17 >> (8U - *(char *)(lVar12 + 0x1b) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1f) & 0x1f) |

                       (uint)(uVar22 >> (8U - *(char *)(lVar12 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1e) & 0x1f) |

                       (uint)(uVar21 >> (8U - *(char *)(lVar12 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1d) & 0x1f) |

                       (uint)(uVar25 >> (8U - *(char *)(lVar12 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1c) & 0x1f);

          }

          puVar20 = (uint *)((longlong)puVar20 + (longlong)(int)uVar26);

          puVar24 = (uint *)((longlong)puVar24 + (longlong)(int)(uint)bVar3);

LAB_14029df37:

          uVar25 = 0;

          if (bVar2 == 1) {

            uVar23 = (ulonglong)(byte)*puVar20;

LAB_14029df97:

            uVar17 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

                                   [(*(uint *)(lVar11 + 8) & uVar23) >>

                                    (*(byte *)(lVar11 + 0x1c) & 0x3f)];

            uVar21 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

                                   [(*(uint *)(lVar11 + 0xc) & uVar23) >>

                                    (*(byte *)(lVar11 + 0x1d) & 0x3f)];

            uVar22 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1a)]

                                   [(*(uint *)(lVar11 + 0x10) & uVar23) >>

                                    (*(byte *)(lVar11 + 0x1e) & 0x3f)];

          }

          else {

            if (bVar2 == 2) {

              uVar23 = (ulonglong)(ushort)*puVar20;

              goto LAB_14029df97;

            }

            if (bVar2 == 3) {

              uVar17 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) +

                                        (longlong)puVar20);

              uVar21 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) +

                                        (longlong)puVar20);

              uVar22 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) +

                                        (longlong)puVar20);

            }

            else {

              if (bVar2 == 4) {

                uVar23 = (ulonglong)*puVar20;

                goto LAB_14029df97;

              }

              uVar17 = 0;

              uVar21 = 0;

              uVar22 = 0;

            }

          }

          if (bVar3 == 1) {

            uVar23 = (ulonglong)(byte)*puVar24;

LAB_14029e062:

            bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x18)]

                    [(*(uint *)(lVar12 + 8) & uVar23) >> (*(byte *)(lVar12 + 0x1c) & 0x3f)];

            bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x19)]

                    [(*(uint *)(lVar12 + 0xc) & uVar23) >> (*(byte *)(lVar12 + 0x1d) & 0x3f)];

            bVar7 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x1a)]

                    [(*(uint *)(lVar12 + 0x10) & uVar23) >> (*(byte *)(lVar12 + 0x1e) & 0x3f)];

            uVar13 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x1b)]

                                   [(*(uint *)(lVar12 + 0x14) & uVar23) >>

                                    (*(byte *)(lVar12 + 0x1f) & 0x3f)];

LAB_14029e0e9:

            local_res10 = (ushort)bVar7;

            uVar15 = (ushort)bVar6;

            uVar25 = (ushort)bVar5;

          }

          else {

            if (bVar3 == 2) {

              uVar23 = (ulonglong)(ushort)*puVar24;

              goto LAB_14029e062;

            }

            if (bVar3 == 3) {

              bVar5 = *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1c) >> 3) + (longlong)puVar24);

              bVar6 = *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1d) >> 3) + (longlong)puVar24);

              bVar7 = *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1e) >> 3) + (longlong)puVar24);

              uVar13 = 0xff;

              goto LAB_14029e0e9;

            }

            if (bVar3 == 4) {

              uVar23 = (ulonglong)*puVar24;

              goto LAB_14029e062;

            }

            uVar15 = 0;

            local_res10 = 0;

            uVar13 = 0;

          }

          uVar14 = (uVar17 - uVar25) * (ushort)bVar4 + uVar25 * 0xff + 1;

          uVar14 = (uVar14 >> 8) + uVar14;

          uVar25 = uVar14 >> 8;

          uVar15 = (uVar21 - uVar15) * (ushort)bVar4 + uVar15 * 0xff + 1;

          uVar15 = (uVar15 >> 8) + uVar15;

          uVar21 = uVar15 >> 8;

          uVar16 = (uVar22 - local_res10) * (ushort)bVar4 + local_res10 * 0xff + 1;

          uVar16 = (uVar16 >> 8) + uVar16;

          uVar22 = uVar16 >> 8;

          uVar17 = (0xff - uVar13) * (ushort)bVar4 + uVar13 * 0xff + 1;

          uVar17 = (ushort)((uVar17 >> 8) + uVar17) >> 8;

          if (bVar3 == 1) {

            *(char *)puVar24 =

                 (char)(uVar17 >> (8U - *(char *)(lVar12 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1f) & 0x1f) |

                 (char)(uVar21 >> (8U - *(char *)(lVar12 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1d) & 0x1f) |

                 (char)(uVar25 >> (8U - *(char *)(lVar12 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1c) & 0x1f) |

                 (char)(uVar22 >> (8U - *(char *)(lVar12 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1e) & 0x1f);

          }

          else if (bVar3 == 2) {

            *(ushort *)puVar24 =

                 (uVar17 >> (8U - *(char *)(lVar12 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1f) & 0x1f) |

                 (uVar22 >> (8U - *(char *)(lVar12 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1e) & 0x1f) |

                 (uVar21 >> (8U - *(char *)(lVar12 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1d) & 0x1f) |

                 (uVar25 >> (8U - *(char *)(lVar12 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1c) & 0x1f);

          }

          else if (bVar3 == 3) {

            *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1c) >> 3) + (longlong)puVar24) =

                 (byte)(uVar14 >> 8);

            *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1d) >> 3) + (longlong)puVar24) =

                 (byte)(uVar15 >> 8);

            *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1e) >> 3) + (longlong)puVar24) =

                 (byte)(uVar16 >> 8);

          }

          else if (bVar3 == 4) {

            *puVar24 = (uint)(uVar17 >> (8U - *(char *)(lVar12 + 0x1b) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1f) & 0x1f) |

                       (uint)(uVar22 >> (8U - *(char *)(lVar12 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1e) & 0x1f) |

                       (uint)(uVar21 >> (8U - *(char *)(lVar12 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1d) & 0x1f) |

                       (uint)(uVar25 >> (8U - *(char *)(lVar12 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1c) & 0x1f);

          }

          local_60 = local_60 + -1;

          puVar20 = (uint *)((longlong)puVar20 + (ulonglong)bVar2);

          puVar24 = (uint *)((longlong)puVar24 + (ulonglong)bVar3);

          if (local_60 < 1) break;

LAB_14029d309:

          uVar25 = 0;

          if (bVar2 == 1) {

            uVar23 = (ulonglong)(byte)*puVar20;

LAB_14029d369:

            uVar17 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

                                   [(*(uint *)(lVar11 + 8) & uVar23) >>

                                    (*(byte *)(lVar11 + 0x1c) & 0x3f)];

            uVar22 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

                                   [(*(uint *)(lVar11 + 0xc) & uVar23) >>

                                    (*(byte *)(lVar11 + 0x1d) & 0x3f)];

            uVar21 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1a)]

                                   [(*(uint *)(lVar11 + 0x10) & uVar23) >>

                                    (*(byte *)(lVar11 + 0x1e) & 0x3f)];

          }

          else {

            if (bVar2 == 2) {

              uVar23 = (ulonglong)(ushort)*puVar20;

              goto LAB_14029d369;

            }

            if (bVar2 == 3) {

              uVar17 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) +

                                        (longlong)puVar20);

              uVar22 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) +

                                        (longlong)puVar20);

              uVar21 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) +

                                        (longlong)puVar20);

            }

            else {

              if (bVar2 == 4) {

                uVar23 = (ulonglong)*puVar20;

                goto LAB_14029d369;

              }

              uVar17 = 0;

              uVar22 = uVar17;

              uVar21 = uVar17;

            }

          }

          if (bVar3 == 1) {

            uVar23 = (ulonglong)(byte)*puVar24;

LAB_14029d43e:

            uVar25 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x18)]

                                   [(*(uint *)(lVar12 + 8) & uVar23) >>

                                    (*(byte *)(lVar12 + 0x1c) & 0x3f)];

            uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x19)]

                                   [(*(uint *)(lVar12 + 0xc) & uVar23) >>

                                    (*(byte *)(lVar12 + 0x1d) & 0x3f)];

            local_res10 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x1a)]

                                        [(*(uint *)(lVar12 + 0x10) & uVar23) >>

                                         (*(byte *)(lVar12 + 0x1e) & 0x3f)];

            uVar13 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar12 + 0x1b)]

                                   [(*(uint *)(lVar12 + 0x14) & uVar23) >>

                                    (*(byte *)(lVar12 + 0x1f) & 0x3f)];

          }

          else {

            if (bVar3 == 2) {

              uVar23 = (ulonglong)(ushort)*puVar24;

              goto LAB_14029d43e;

            }

            if (bVar3 == 3) {

              uVar13 = 0xff;

              uVar25 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1c) >> 3) +

                                        (longlong)puVar24);

              uVar15 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1d) >> 3) +

                                        (longlong)puVar24);

              local_res10 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1e) >> 3) +

                                             (longlong)puVar24);

            }

            else {

              if (bVar3 == 4) {

                uVar23 = (ulonglong)*puVar24;

                goto LAB_14029d43e;

              }

              uVar15 = 0;

              local_res10 = 0;

              uVar13 = 0;

            }

          }

          uVar14 = (uVar17 - uVar25) * (ushort)bVar4 + uVar25 * 0xff + 1;

          uVar14 = (uVar14 >> 8) + uVar14;

          uVar25 = uVar14 >> 8;

          uVar15 = (uVar22 - uVar15) * (ushort)bVar4 + uVar15 * 0xff + 1;

          uVar15 = (uVar15 >> 8) + uVar15;

          uVar22 = uVar15 >> 8;

          uVar16 = (uVar21 - local_res10) * (ushort)bVar4 + local_res10 * 0xff + 1;

          uVar16 = (uVar16 >> 8) + uVar16;

          uVar21 = uVar16 >> 8;

          uVar17 = (0xff - uVar13) * (ushort)bVar4 + uVar13 * 0xff + 1;

          uVar17 = (ushort)((uVar17 >> 8) + uVar17) >> 8;

          if (bVar3 == 1) {

            *(char *)puVar24 =

                 (char)(uVar17 >> (8U - *(char *)(lVar12 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1f) & 0x1f) |

                 (char)(uVar21 >> (8U - *(char *)(lVar12 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1e) & 0x1f) |

                 (char)(uVar22 >> (8U - *(char *)(lVar12 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1d) & 0x1f) |

                 (char)(uVar25 >> (8U - *(char *)(lVar12 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1c) & 0x1f);

          }

          else if (bVar3 == 2) {

            *(ushort *)puVar24 =

                 (uVar17 >> (8U - *(char *)(lVar12 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1f) & 0x1f) |

                 (uVar25 >> (8U - *(char *)(lVar12 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1c) & 0x1f) |

                 (uVar21 >> (8U - *(char *)(lVar12 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1e) & 0x1f) |

                 (uVar22 >> (8U - *(char *)(lVar12 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar12 + 0x1d) & 0x1f);

          }

          else if (bVar3 == 3) {

            *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1c) >> 3) + (longlong)puVar24) =

                 (byte)(uVar14 >> 8);

            *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1d) >> 3) + (longlong)puVar24) =

                 (byte)(uVar15 >> 8);

            *(byte *)((ulonglong)(*(byte *)(lVar12 + 0x1e) >> 3) + (longlong)puVar24) =

                 (byte)(uVar16 >> 8);

          }

          else if (bVar3 == 4) {

            *puVar24 = (uint)(uVar17 >> (8U - *(char *)(lVar12 + 0x1b) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1f) & 0x1f) |

                       (uint)(uVar25 >> (8U - *(char *)(lVar12 + 0x18) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1c) & 0x1f) |

                       (uint)(uVar21 >> (8U - *(char *)(lVar12 + 0x1a) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1e) & 0x1f) |

                       (uint)(uVar22 >> (8U - *(char *)(lVar12 + 0x19) & 0x1f)) <<

                       (*(byte *)(lVar12 + 0x1d) & 0x1f);

          }

          puVar20 = (uint *)((longlong)puVar20 + (longlong)(int)uVar26);

          puVar24 = (uint *)((longlong)puVar24 + (longlong)(int)(uint)bVar3);

        } while( true );

      }

      puVar20 = (uint *)((longlong)puVar20 + (longlong)iVar8);

      puVar24 = (uint *)((longlong)puVar24 + (longlong)iVar10);

      iVar18 = iVar18 + -1;

    }

  }

  return;

}




