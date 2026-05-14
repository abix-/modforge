// Address: 0x14029c020
// Ghidra name: FUN_14029c020
// ============ 0x14029c020 FUN_14029c020 (size=4653) ============


void FUN_14029c020(longlong param_1)



{

  int iVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  byte bVar6;

  int iVar7;

  uint uVar8;

  int iVar9;

  longlong lVar10;

  longlong lVar11;

  ushort uVar12;

  ushort uVar13;

  ushort uVar14;

  ushort uVar15;

  int iVar16;

  uint uVar17;

  uint *puVar18;

  uint uVar19;

  ushort uVar20;

  ushort uVar21;

  ulonglong uVar22;

  uint *puVar23;

  ushort uVar24;

  uint uVar25;

  ushort uVar26;

  ushort local_res8;

  ushort local_res10;

  ushort local_res18;

  int local_res20;

  

  iVar7 = *(int *)(param_1 + 0x1c);

  lVar10 = *(longlong *)(param_1 + 0x48);

  lVar11 = *(longlong *)(param_1 + 0x58);

  uVar8 = *(uint *)(param_1 + 0x38);

  bVar2 = *(byte *)(lVar10 + 5);

  bVar3 = *(byte *)(lVar11 + 5);

  puVar18 = *(uint **)(param_1 + 8);

  puVar23 = *(uint **)(param_1 + 0x30);

  iVar9 = *(int *)(param_1 + 0x44);

  iVar16 = *(int *)(param_1 + 0x3c);

  while( true ) {

    if (iVar16 == 0) {

      return;

    }

    iVar1 = uVar8 + 3;

    local_res20 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;

    uVar17 = uVar8 & 3;

    uVar25 = (uint)bVar2;

    uVar19 = (uint)bVar3;

    if (uVar17 == 0) goto LAB_14029c0ca;

    if (uVar17 == 1) goto LAB_14029cdc1;

    if (uVar17 == 2) goto LAB_14029c973;

    if (uVar17 == 3) break;

LAB_14029d223:

    puVar18 = (uint *)((longlong)puVar18 + (longlong)iVar7);

    puVar23 = (uint *)((longlong)puVar23 + (longlong)iVar9);

    iVar16 = iVar16 + -1;

  }

  do {

    uVar15 = 0xff;

    if (bVar2 == 1) {

      uVar22 = (ulonglong)(byte)*puVar18;

LAB_14029c592:

      uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1b)]

                             [(*(uint *)(lVar10 + 0x14) & uVar22) >>

                              (*(byte *)(lVar10 + 0x1f) & 0x3f)];

      bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x18)]

              [(*(uint *)(lVar10 + 8) & uVar22) >> (*(byte *)(lVar10 + 0x1c) & 0x3f)];

      bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x19)]

              [(*(uint *)(lVar10 + 0xc) & uVar22) >> (*(byte *)(lVar10 + 0x1d) & 0x3f)];

      bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1a)]

              [(*(uint *)(lVar10 + 0x10) & uVar22) >> (*(byte *)(lVar10 + 0x1e) & 0x3f)];

      if ((&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1b)]

          [(*(uint *)(lVar10 + 0x14) & uVar22) >> (*(byte *)(lVar10 + 0x1f) & 0x3f)] != 0) {

LAB_14029c62a:

        local_res18 = (ushort)bVar6;

        local_res10 = (ushort)bVar5;

        local_res8 = (ushort)bVar4;

        if (bVar3 == 1) {

          uVar22 = (ulonglong)(byte)*puVar23;

LAB_14029c696:

          uVar21 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

                                 [(*(uint *)(lVar11 + 8) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1c) & 0x3f)];

          uVar26 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

                                 [(*(uint *)(lVar11 + 0xc) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1d) & 0x3f)];

          uVar24 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1a)]

                                 [(*(uint *)(lVar11 + 0x10) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1e) & 0x3f)];

          uVar20 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1b)]

                                 [(*(uint *)(lVar11 + 0x14) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1f) & 0x3f)];

        }

        else {

          if (bVar3 == 2) {

            uVar22 = (ulonglong)(ushort)*puVar23;

            goto LAB_14029c696;

          }

          if (bVar3 == 3) {

            uVar20 = 0xff;

            uVar21 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) +

                                      (longlong)puVar23);

            uVar26 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) +

                                      (longlong)puVar23);

            uVar24 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) +

                                      (longlong)puVar23);

          }

          else {

            if (bVar3 == 4) {

              uVar22 = (ulonglong)*puVar23;

              goto LAB_14029c696;

            }

            uVar21 = 0;

            uVar26 = 0;

            uVar24 = 0;

            uVar20 = 0;

          }

        }

        uVar12 = (local_res8 - uVar21) * uVar15 + uVar21 * 0xff + 1;

        uVar12 = (uVar12 >> 8) + uVar12;

        uVar21 = uVar12 >> 8;

        uVar13 = (local_res10 - uVar26) * uVar15 + uVar26 * 0xff + 1;

        uVar13 = (uVar13 >> 8) + uVar13;

        uVar26 = uVar13 >> 8;

        uVar14 = (local_res18 - uVar24) * uVar15 + uVar24 * 0xff + 1;

        uVar14 = (uVar14 >> 8) + uVar14;

        uVar24 = uVar14 >> 8;

        uVar15 = (0xff - uVar20) * uVar15 + uVar20 * 0xff + 1;

        uVar15 = (ushort)((uVar15 >> 8) + uVar15) >> 8;

        if (bVar3 == 1) {

          *(char *)puVar23 =

               (char)(uVar15 >> (8U - *(char *)(lVar11 + 0x1b) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1f) & 0x1f) |

               (char)(uVar26 >> (8U - *(char *)(lVar11 + 0x19) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1d) & 0x1f) |

               (char)(uVar24 >> (8U - *(char *)(lVar11 + 0x1a) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1e) & 0x1f) |

               (char)(uVar21 >> (8U - *(char *)(lVar11 + 0x18) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1c) & 0x1f);

        }

        else if (bVar3 == 2) {

          *(ushort *)puVar23 =

               (uVar15 >> (8U - *(char *)(lVar11 + 0x1b) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1f) & 0x1f) |

               (uVar24 >> (8U - *(char *)(lVar11 + 0x1a) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1e) & 0x1f) |

               (uVar21 >> (8U - *(char *)(lVar11 + 0x18) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1c) & 0x1f) |

               (uVar26 >> (8U - *(char *)(lVar11 + 0x19) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1d) & 0x1f);

        }

        else if (bVar3 == 3) {

          *(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) + (longlong)puVar23) =

               (byte)(uVar12 >> 8);

          *(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) + (longlong)puVar23) =

               (byte)(uVar13 >> 8);

          *(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) + (longlong)puVar23) =

               (byte)(uVar14 >> 8);

        }

        else if (bVar3 == 4) {

          *puVar23 = (uint)(uVar15 >> (8U - *(char *)(lVar11 + 0x1b) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1f) & 0x1f) |

                     (uint)(uVar24 >> (8U - *(char *)(lVar11 + 0x1a) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1e) & 0x1f) |

                     (uint)(uVar26 >> (8U - *(char *)(lVar11 + 0x19) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1d) & 0x1f) |

                     (uint)(uVar21 >> (8U - *(char *)(lVar11 + 0x18) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1c) & 0x1f);

        }

      }

    }

    else {

      if (bVar2 == 2) {

        uVar22 = (ulonglong)(ushort)*puVar18;

        goto LAB_14029c592;

      }

      if (bVar2 == 3) {

        bVar4 = *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1c) >> 3) + (longlong)puVar18);

        bVar5 = *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1d) >> 3) + (longlong)puVar18);

        bVar6 = *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1e) >> 3) + (longlong)puVar18);

        goto LAB_14029c62a;

      }

      if (bVar2 == 4) {

        uVar22 = (ulonglong)*puVar18;

        goto LAB_14029c592;

      }

    }

    puVar18 = (uint *)((longlong)puVar18 + (longlong)(int)uVar25);

    puVar23 = (uint *)((longlong)puVar23 + (longlong)(int)uVar19);

LAB_14029c973:

    if (bVar2 == 1) {

      uVar22 = (ulonglong)(byte)*puVar18;

LAB_14029c9db:

      uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1b)]

                             [(*(uint *)(lVar10 + 0x14) & uVar22) >>

                              (*(byte *)(lVar10 + 0x1f) & 0x3f)];

      bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x18)]

              [(*(uint *)(lVar10 + 8) & uVar22) >> (*(byte *)(lVar10 + 0x1c) & 0x3f)];

      bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x19)]

              [(*(uint *)(lVar10 + 0xc) & uVar22) >> (*(byte *)(lVar10 + 0x1d) & 0x3f)];

      bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1a)]

              [(*(uint *)(lVar10 + 0x10) & uVar22) >> (*(byte *)(lVar10 + 0x1e) & 0x3f)];

      if ((&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1b)]

          [(*(uint *)(lVar10 + 0x14) & uVar22) >> (*(byte *)(lVar10 + 0x1f) & 0x3f)] != 0) {

LAB_14029ca73:

        local_res18 = (ushort)bVar6;

        local_res10 = (ushort)bVar5;

        local_res8 = (ushort)bVar4;

        if (bVar3 == 1) {

          uVar22 = (ulonglong)(byte)*puVar23;

LAB_14029cadf:

          uVar21 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

                                 [(*(uint *)(lVar11 + 8) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1c) & 0x3f)];

          uVar26 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

                                 [(*(uint *)(lVar11 + 0xc) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1d) & 0x3f)];

          uVar24 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1a)]

                                 [(*(uint *)(lVar11 + 0x10) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1e) & 0x3f)];

          uVar20 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1b)]

                                 [(*(uint *)(lVar11 + 0x14) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1f) & 0x3f)];

        }

        else {

          if (bVar3 == 2) {

            uVar22 = (ulonglong)(ushort)*puVar23;

            goto LAB_14029cadf;

          }

          if (bVar3 == 3) {

            uVar20 = 0xff;

            uVar21 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) +

                                      (longlong)puVar23);

            uVar26 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) +

                                      (longlong)puVar23);

            uVar24 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) +

                                      (longlong)puVar23);

          }

          else {

            if (bVar3 == 4) {

              uVar22 = (ulonglong)*puVar23;

              goto LAB_14029cadf;

            }

            uVar21 = 0;

            uVar26 = 0;

            uVar24 = 0;

            uVar20 = 0;

          }

        }

        uVar12 = (local_res8 - uVar21) * uVar15 + uVar21 * 0xff + 1;

        uVar12 = (uVar12 >> 8) + uVar12;

        uVar21 = uVar12 >> 8;

        uVar13 = (local_res10 - uVar26) * uVar15 + uVar26 * 0xff + 1;

        uVar13 = (uVar13 >> 8) + uVar13;

        uVar26 = uVar13 >> 8;

        uVar14 = (local_res18 - uVar24) * uVar15 + uVar24 * 0xff + 1;

        uVar14 = (uVar14 >> 8) + uVar14;

        uVar24 = uVar14 >> 8;

        uVar15 = (0xff - uVar20) * uVar15 + uVar20 * 0xff + 1;

        uVar15 = (ushort)((uVar15 >> 8) + uVar15) >> 8;

        if (bVar3 == 1) {

          *(char *)puVar23 =

               (char)(uVar15 >> (8U - *(char *)(lVar11 + 0x1b) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1f) & 0x1f) |

               (char)(uVar24 >> (8U - *(char *)(lVar11 + 0x1a) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1e) & 0x1f) |

               (char)(uVar26 >> (8U - *(char *)(lVar11 + 0x19) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1d) & 0x1f) |

               (char)(uVar21 >> (8U - *(char *)(lVar11 + 0x18) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1c) & 0x1f);

        }

        else if (bVar3 == 2) {

          *(ushort *)puVar23 =

               (uVar15 >> (8U - *(char *)(lVar11 + 0x1b) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1f) & 0x1f) |

               (uVar26 >> (8U - *(char *)(lVar11 + 0x19) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1d) & 0x1f) |

               (uVar24 >> (8U - *(char *)(lVar11 + 0x1a) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1e) & 0x1f) |

               (uVar21 >> (8U - *(char *)(lVar11 + 0x18) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1c) & 0x1f);

        }

        else if (bVar3 == 3) {

          *(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) + (longlong)puVar23) =

               (byte)(uVar12 >> 8);

          *(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) + (longlong)puVar23) =

               (byte)(uVar13 >> 8);

          *(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) + (longlong)puVar23) =

               (byte)(uVar14 >> 8);

        }

        else if (bVar3 == 4) {

          *puVar23 = (uint)(uVar15 >> (8U - *(char *)(lVar11 + 0x1b) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1f) & 0x1f) |

                     (uint)(uVar24 >> (8U - *(char *)(lVar11 + 0x1a) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1e) & 0x1f) |

                     (uint)(uVar26 >> (8U - *(char *)(lVar11 + 0x19) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1d) & 0x1f) |

                     (uint)(uVar21 >> (8U - *(char *)(lVar11 + 0x18) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1c) & 0x1f);

        }

      }

    }

    else {

      if (bVar2 == 2) {

        uVar22 = (ulonglong)(ushort)*puVar18;

        goto LAB_14029c9db;

      }

      if (bVar2 == 3) {

        uVar15 = 0xff;

        bVar4 = *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1c) >> 3) + (longlong)puVar18);

        bVar5 = *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1d) >> 3) + (longlong)puVar18);

        bVar6 = *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1e) >> 3) + (longlong)puVar18);

        goto LAB_14029ca73;

      }

      if (bVar2 == 4) {

        uVar22 = (ulonglong)*puVar18;

        goto LAB_14029c9db;

      }

    }

    puVar18 = (uint *)((longlong)puVar18 + (longlong)(int)uVar25);

    puVar23 = (uint *)((longlong)puVar23 + (longlong)(int)uVar19);

LAB_14029cdc1:

    if (bVar2 == 1) {

      uVar22 = (ulonglong)(byte)*puVar18;

LAB_14029ce29:

      uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1b)]

                             [(*(uint *)(lVar10 + 0x14) & uVar22) >>

                              (*(byte *)(lVar10 + 0x1f) & 0x3f)];

      bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x18)]

              [(*(uint *)(lVar10 + 8) & uVar22) >> (*(byte *)(lVar10 + 0x1c) & 0x3f)];

      bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x19)]

              [(*(uint *)(lVar10 + 0xc) & uVar22) >> (*(byte *)(lVar10 + 0x1d) & 0x3f)];

      bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1a)]

              [(*(uint *)(lVar10 + 0x10) & uVar22) >> (*(byte *)(lVar10 + 0x1e) & 0x3f)];

      if ((&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1b)]

          [(*(uint *)(lVar10 + 0x14) & uVar22) >> (*(byte *)(lVar10 + 0x1f) & 0x3f)] != 0) {

LAB_14029cec1:

        local_res18 = (ushort)bVar6;

        local_res10 = (ushort)bVar5;

        local_res8 = (ushort)bVar4;

        if (bVar3 == 1) {

          uVar22 = (ulonglong)(byte)*puVar23;

LAB_14029cf2d:

          uVar21 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

                                 [(*(uint *)(lVar11 + 8) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1c) & 0x3f)];

          uVar26 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

                                 [(*(uint *)(lVar11 + 0xc) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1d) & 0x3f)];

          uVar24 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1a)]

                                 [(*(uint *)(lVar11 + 0x10) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1e) & 0x3f)];

          uVar20 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1b)]

                                 [(*(uint *)(lVar11 + 0x14) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1f) & 0x3f)];

        }

        else {

          if (bVar3 == 2) {

            uVar22 = (ulonglong)(ushort)*puVar23;

            goto LAB_14029cf2d;

          }

          if (bVar3 == 3) {

            uVar20 = 0xff;

            uVar21 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) +

                                      (longlong)puVar23);

            uVar26 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) +

                                      (longlong)puVar23);

            uVar24 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) +

                                      (longlong)puVar23);

          }

          else {

            if (bVar3 == 4) {

              uVar22 = (ulonglong)*puVar23;

              goto LAB_14029cf2d;

            }

            uVar21 = 0;

            uVar26 = 0;

            uVar24 = 0;

            uVar20 = 0;

          }

        }

        uVar12 = (local_res8 - uVar21) * uVar15 + uVar21 * 0xff + 1;

        uVar12 = (uVar12 >> 8) + uVar12;

        uVar21 = uVar12 >> 8;

        uVar13 = (local_res10 - uVar26) * uVar15 + uVar26 * 0xff + 1;

        uVar13 = (uVar13 >> 8) + uVar13;

        uVar26 = uVar13 >> 8;

        uVar14 = (local_res18 - uVar24) * uVar15 + uVar24 * 0xff + 1;

        uVar14 = (uVar14 >> 8) + uVar14;

        uVar24 = uVar14 >> 8;

        uVar15 = (0xff - uVar20) * uVar15 + uVar20 * 0xff + 1;

        uVar15 = (ushort)((uVar15 >> 8) + uVar15) >> 8;

        if (bVar3 == 1) {

          *(char *)puVar23 =

               (char)(uVar15 >> (8U - *(char *)(lVar11 + 0x1b) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1f) & 0x1f) |

               (char)(uVar21 >> (8U - *(char *)(lVar11 + 0x18) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1c) & 0x1f) |

               (char)(uVar24 >> (8U - *(char *)(lVar11 + 0x1a) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1e) & 0x1f) |

               (char)(uVar26 >> (8U - *(char *)(lVar11 + 0x19) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1d) & 0x1f);

        }

        else if (bVar3 == 2) {

          *(ushort *)puVar23 =

               (uVar15 >> (8U - *(char *)(lVar11 + 0x1b) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1f) & 0x1f) |

               (uVar24 >> (8U - *(char *)(lVar11 + 0x1a) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1e) & 0x1f) |

               (uVar26 >> (8U - *(char *)(lVar11 + 0x19) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1d) & 0x1f) |

               (uVar21 >> (8U - *(char *)(lVar11 + 0x18) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1c) & 0x1f);

        }

        else if (bVar3 == 3) {

          *(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) + (longlong)puVar23) =

               (byte)(uVar12 >> 8);

          *(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) + (longlong)puVar23) =

               (byte)(uVar13 >> 8);

          *(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) + (longlong)puVar23) =

               (byte)(uVar14 >> 8);

        }

        else if (bVar3 == 4) {

          *puVar23 = (uint)(uVar15 >> (8U - *(char *)(lVar11 + 0x1b) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1f) & 0x1f) |

                     (uint)(uVar24 >> (8U - *(char *)(lVar11 + 0x1a) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1e) & 0x1f) |

                     (uint)(uVar26 >> (8U - *(char *)(lVar11 + 0x19) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1d) & 0x1f) |

                     (uint)(uVar21 >> (8U - *(char *)(lVar11 + 0x18) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1c) & 0x1f);

        }

      }

    }

    else {

      if (bVar2 == 2) {

        uVar22 = (ulonglong)(ushort)*puVar18;

        goto LAB_14029ce29;

      }

      if (bVar2 == 3) {

        uVar15 = 0xff;

        bVar4 = *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1c) >> 3) + (longlong)puVar18);

        bVar5 = *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1d) >> 3) + (longlong)puVar18);

        bVar6 = *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1e) >> 3) + (longlong)puVar18);

        goto LAB_14029cec1;

      }

      if (bVar2 == 4) {

        uVar22 = (ulonglong)*puVar18;

        goto LAB_14029ce29;

      }

    }

    local_res20 = local_res20 + -1;

    puVar18 = (uint *)((longlong)puVar18 + (ulonglong)bVar2);

    puVar23 = (uint *)((longlong)puVar23 + (ulonglong)bVar3);

    if (local_res20 < 1) goto LAB_14029d223;

LAB_14029c0ca:

    if (bVar2 == 1) {

      uVar22 = (ulonglong)(byte)*puVar18;

LAB_14029c132:

      uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1b)]

                             [(*(uint *)(lVar10 + 0x14) & uVar22) >>

                              (*(byte *)(lVar10 + 0x1f) & 0x3f)];

      bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x18)]

              [(*(uint *)(lVar10 + 8) & uVar22) >> (*(byte *)(lVar10 + 0x1c) & 0x3f)];

      bVar5 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x19)]

              [(*(uint *)(lVar10 + 0xc) & uVar22) >> (*(byte *)(lVar10 + 0x1d) & 0x3f)];

      bVar6 = (&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1a)]

              [(*(uint *)(lVar10 + 0x10) & uVar22) >> (*(byte *)(lVar10 + 0x1e) & 0x3f)];

      if ((&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1b)]

          [(*(uint *)(lVar10 + 0x14) & uVar22) >> (*(byte *)(lVar10 + 0x1f) & 0x3f)] != 0) {

LAB_14029c1cd:

        local_res18 = (ushort)bVar6;

        local_res10 = (ushort)bVar5;

        local_res8 = (ushort)bVar4;

        uVar26 = 0;

        if (bVar3 == 1) {

          uVar22 = (ulonglong)(byte)*puVar23;

LAB_14029c23a:

          uVar20 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x18)]

                                 [(*(uint *)(lVar11 + 8) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1c) & 0x3f)];

          uVar21 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x19)]

                                 [(*(uint *)(lVar11 + 0xc) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1d) & 0x3f)];

          uVar26 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1a)]

                                 [(*(uint *)(lVar11 + 0x10) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1e) & 0x3f)];

          uVar24 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar11 + 0x1b)]

                                 [(*(uint *)(lVar11 + 0x14) & uVar22) >>

                                  (*(byte *)(lVar11 + 0x1f) & 0x3f)];

        }

        else {

          if (bVar3 == 2) {

            uVar22 = (ulonglong)(ushort)*puVar23;

            goto LAB_14029c23a;

          }

          if (bVar3 == 3) {

            uVar24 = 0xff;

            uVar20 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) +

                                      (longlong)puVar23);

            uVar21 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) +

                                      (longlong)puVar23);

            uVar26 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) +

                                      (longlong)puVar23);

          }

          else {

            if (bVar3 == 4) {

              uVar22 = (ulonglong)*puVar23;

              goto LAB_14029c23a;

            }

            uVar20 = 0;

            uVar21 = 0;

            uVar24 = 0;

          }

        }

        uVar12 = (local_res8 - uVar20) * uVar15 + uVar20 * 0xff + 1;

        uVar12 = (uVar12 >> 8) + uVar12;

        uVar20 = uVar12 >> 8;

        uVar13 = (local_res10 - uVar21) * uVar15 + uVar21 * 0xff + 1;

        uVar13 = (uVar13 >> 8) + uVar13;

        uVar21 = uVar13 >> 8;

        uVar14 = (local_res18 - uVar26) * uVar15 + uVar26 * 0xff + 1;

        uVar14 = (uVar14 >> 8) + uVar14;

        uVar26 = uVar14 >> 8;

        uVar15 = (0xff - uVar24) * uVar15 + uVar24 * 0xff + 1;

        uVar15 = (ushort)((uVar15 >> 8) + uVar15) >> 8;

        if (bVar3 == 1) {

          *(char *)puVar23 =

               (char)(uVar15 >> (8U - *(char *)(lVar11 + 0x1b) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1f) & 0x1f) |

               (char)(uVar26 >> (8U - *(char *)(lVar11 + 0x1a) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1e) & 0x1f) |

               (char)(uVar21 >> (8U - *(char *)(lVar11 + 0x19) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1d) & 0x1f) |

               (char)(uVar20 >> (8U - *(char *)(lVar11 + 0x18) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1c) & 0x1f);

        }

        else if (bVar3 == 2) {

          *(ushort *)puVar23 =

               (uVar15 >> (8U - *(char *)(lVar11 + 0x1b) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1f) & 0x1f) |

               (uVar20 >> (8U - *(char *)(lVar11 + 0x18) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1c) & 0x1f) |

               (uVar26 >> (8U - *(char *)(lVar11 + 0x1a) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1e) & 0x1f) |

               (uVar21 >> (8U - *(char *)(lVar11 + 0x19) & 0x1f)) <<

               (*(byte *)(lVar11 + 0x1d) & 0x1f);

        }

        else if (bVar3 == 3) {

          *(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1c) >> 3) + (longlong)puVar23) =

               (byte)(uVar12 >> 8);

          *(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1d) >> 3) + (longlong)puVar23) =

               (byte)(uVar13 >> 8);

          *(byte *)((ulonglong)(*(byte *)(lVar11 + 0x1e) >> 3) + (longlong)puVar23) =

               (byte)(uVar14 >> 8);

        }

        else if (bVar3 == 4) {

          *puVar23 = (uint)(uVar15 >> (8U - *(char *)(lVar11 + 0x1b) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1f) & 0x1f) |

                     (uint)(uVar26 >> (8U - *(char *)(lVar11 + 0x1a) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1e) & 0x1f) |

                     (uint)(uVar21 >> (8U - *(char *)(lVar11 + 0x19) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1d) & 0x1f) |

                     (uint)(uVar20 >> (8U - *(char *)(lVar11 + 0x18) & 0x1f)) <<

                     (*(byte *)(lVar11 + 0x1c) & 0x1f);

        }

      }

    }

    else {

      if (bVar2 == 2) {

        uVar22 = (ulonglong)(ushort)*puVar18;

        goto LAB_14029c132;

      }

      if (bVar2 == 3) {

        uVar15 = 0xff;

        bVar4 = *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1c) >> 3) + (longlong)puVar18);

        bVar5 = *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1d) >> 3) + (longlong)puVar18);

        bVar6 = *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1e) >> 3) + (longlong)puVar18);

        goto LAB_14029c1cd;

      }

      if (bVar2 == 4) {

        uVar22 = (ulonglong)*puVar18;

        goto LAB_14029c132;

      }

    }

    puVar18 = (uint *)((longlong)puVar18 + (longlong)(int)uVar25);

    puVar23 = (uint *)((longlong)puVar23 + (longlong)(int)uVar19);

  } while( true );

}




