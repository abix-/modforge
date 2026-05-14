// Address: 0x14029e390
// Ghidra name: FUN_14029e390
// ============ 0x14029e390 FUN_14029e390 (size=4256) ============


void FUN_14029e390(longlong param_1)



{

  int iVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  int iVar8;

  longlong lVar9;

  longlong lVar10;

  ushort uVar11;

  ushort uVar12;

  ushort uVar13;

  ushort uVar14;

  ushort uVar15;

  int iVar16;

  uint uVar17;

  ushort uVar18;

  ushort uVar19;

  uint uVar20;

  ulonglong uVar21;

  uint *puVar22;

  uint *puVar23;

  uint uVar24;

  uint uVar25;

  int local_68;

  

  iVar5 = *(int *)(param_1 + 0x1c);

  lVar9 = *(longlong *)(param_1 + 0x48);

  lVar10 = *(longlong *)(param_1 + 0x58);

  bVar2 = *(byte *)(param_1 + 0x83);

  uVar6 = *(uint *)(param_1 + 0x38);

  uVar7 = *(uint *)(param_1 + 0x7c);

  bVar3 = *(byte *)(lVar9 + 5);

  bVar4 = *(byte *)(lVar10 + 5);

  puVar23 = *(uint **)(param_1 + 8);

  puVar22 = *(uint **)(param_1 + 0x30);

  iVar8 = *(int *)(param_1 + 0x44);

  iVar16 = *(int *)(param_1 + 0x3c);

  while( true ) {

    if (iVar16 == 0) {

      return;

    }

    iVar1 = uVar6 + 3;

    local_68 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;

    uVar17 = uVar6 & 3;

    uVar24 = (uint)bVar3;

    uVar25 = (uint)bVar4;

    if (uVar17 == 0) goto LAB_14029e448;

    if (uVar17 == 1) goto LAB_14029f006;

    if (uVar17 == 2) goto LAB_14029ec1c;

    if (uVar17 == 3) break;

LAB_14029f406:

    puVar23 = (uint *)((longlong)puVar23 + (longlong)iVar5);

    puVar22 = (uint *)((longlong)puVar22 + (longlong)iVar8);

    iVar16 = iVar16 + -1;

  }

  do {

    uVar19 = 0;

    if (bVar3 == 1) {

      uVar17 = (uint)(byte)*puVar23;

    }

    else if (bVar3 == 2) {

      uVar17 = (uint)(ushort)*puVar23;

    }

    else if (bVar3 == 3) {

      uVar17 = (uint)(uint3)*puVar23;

    }

    else if (bVar3 == 4) {

      uVar17 = *puVar23;

    }

    else {

      uVar17 = 0;

    }

    if ((bVar2 != 0) && (uVar17 != uVar7)) {

      if (bVar4 == 1) {

        uVar21 = (ulonglong)(byte)*puVar22;

LAB_14029e953:

        uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x18)]

                               [(*(uint *)(lVar10 + 8) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1c) & 0x3f)];

        uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x19)]

                               [(*(uint *)(lVar10 + 0xc) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1d) & 0x3f)];

        uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1a)]

                               [(*(uint *)(lVar10 + 0x10) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1e) & 0x3f)];

        uVar14 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1b)]

                               [(*(uint *)(lVar10 + 0x14) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1f) & 0x3f)];

      }

      else {

        if (bVar4 == 2) {

          uVar21 = (ulonglong)(ushort)*puVar22;

          goto LAB_14029e953;

        }

        if (bVar4 == 3) {

          uVar14 = 0xff;

          uVar15 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1c) >> 3) + (longlong)puVar22)

          ;

          uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1d) >> 3) + (longlong)puVar22)

          ;

          uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1e) >> 3) + (longlong)puVar22)

          ;

        }

        else {

          if (bVar4 == 4) {

            uVar21 = (ulonglong)*puVar22;

            goto LAB_14029e953;

          }

          uVar15 = 0;

          uVar14 = 0;

          uVar18 = uVar15;

        }

      }

      uVar11 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x18)]

                      [(*(uint *)(lVar9 + 8) & uVar17) >> (*(byte *)(lVar9 + 0x1c) & 0x3f)] - uVar15

               ) * (ushort)bVar2 + 1 + uVar15 * 0xff;

      uVar11 = (uVar11 >> 8) + uVar11;

      uVar15 = uVar11 >> 8;

      uVar12 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                      [(*(uint *)(lVar9 + 0xc) & uVar17) >> (*(byte *)(lVar9 + 0x1d) & 0x3f)] -

               uVar18) * (ushort)bVar2 + uVar18 * 0xff + 1;

      uVar12 = (uVar12 >> 8) + uVar12;

      uVar18 = uVar12 >> 8;

      uVar13 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1a)]

                      [(*(uint *)(lVar9 + 0x10) & uVar17) >> (*(byte *)(lVar9 + 0x1e) & 0x3f)] -

               uVar19) * (ushort)bVar2 + uVar19 * 0xff + 1;

      uVar13 = (uVar13 >> 8) + uVar13;

      uVar19 = uVar13 >> 8;

      uVar14 = (0xff - uVar14) * (ushort)bVar2 + uVar14 * 0xff + 1;

      uVar14 = (ushort)((uVar14 >> 8) + uVar14) >> 8;

      if (bVar4 == 1) {

        *(char *)puVar22 =

             (char)(uVar14 >> (8U - *(char *)(lVar10 + 0x1b) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1f) & 0x1f) |

             (char)(uVar19 >> (8U - *(char *)(lVar10 + 0x1a) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1e) & 0x1f) |

             (char)(uVar18 >> (8U - *(char *)(lVar10 + 0x19) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1d) & 0x1f) |

             (char)(uVar15 >> (8U - *(char *)(lVar10 + 0x18) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1c) & 0x1f);

      }

      else if (bVar4 == 2) {

        *(ushort *)puVar22 =

             (uVar14 >> (8U - *(char *)(lVar10 + 0x1b) & 0x1f)) << (*(byte *)(lVar10 + 0x1f) & 0x1f)

             | (uVar19 >> (8U - *(char *)(lVar10 + 0x1a) & 0x1f)) <<

               (*(byte *)(lVar10 + 0x1e) & 0x1f) |

             (uVar18 >> (8U - *(char *)(lVar10 + 0x19) & 0x1f)) << (*(byte *)(lVar10 + 0x1d) & 0x1f)

             | (uVar15 >> (8U - *(char *)(lVar10 + 0x18) & 0x1f)) <<

               (*(byte *)(lVar10 + 0x1c) & 0x1f);

      }

      else if (bVar4 == 3) {

        *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1c) >> 3) + (longlong)puVar22) =

             (byte)(uVar11 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1d) >> 3) + (longlong)puVar22) =

             (byte)(uVar12 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1e) >> 3) + (longlong)puVar22) =

             (byte)(uVar13 >> 8);

      }

      else if (bVar4 == 4) {

        *puVar22 = (uint)(uVar14 >> (8U - *(char *)(lVar10 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1f) & 0x1f) |

                   (uint)(uVar19 >> (8U - *(char *)(lVar10 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1e) & 0x1f) |

                   (uint)(uVar15 >> (8U - *(char *)(lVar10 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1c) & 0x1f) |

                   (uint)(uVar18 >> (8U - *(char *)(lVar10 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1d) & 0x1f);

      }

    }

    puVar23 = (uint *)((longlong)puVar23 + (longlong)(int)uVar24);

    puVar22 = (uint *)((longlong)puVar22 + (longlong)(int)uVar25);

LAB_14029ec1c:

    uVar19 = 0;

    if (bVar3 == 1) {

      uVar17 = (uint)(byte)*puVar23;

    }

    else if (bVar3 == 2) {

      uVar17 = (uint)(ushort)*puVar23;

    }

    else if (bVar3 == 3) {

      uVar17 = (uint)(uint3)*puVar23;

    }

    else if (bVar3 == 4) {

      uVar17 = *puVar23;

    }

    else {

      uVar17 = 0;

    }

    if ((bVar2 != 0) && (uVar17 != uVar7)) {

      if (bVar4 == 1) {

        uVar21 = (ulonglong)(byte)*puVar22;

LAB_14029ed3d:

        uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x18)]

                               [(*(uint *)(lVar10 + 8) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1c) & 0x3f)];

        uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x19)]

                               [(*(uint *)(lVar10 + 0xc) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1d) & 0x3f)];

        uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1a)]

                               [(*(uint *)(lVar10 + 0x10) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1e) & 0x3f)];

        uVar14 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1b)]

                               [(*(uint *)(lVar10 + 0x14) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1f) & 0x3f)];

      }

      else {

        if (bVar4 == 2) {

          uVar21 = (ulonglong)(ushort)*puVar22;

          goto LAB_14029ed3d;

        }

        if (bVar4 == 3) {

          uVar14 = 0xff;

          uVar15 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1c) >> 3) + (longlong)puVar22)

          ;

          uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1d) >> 3) + (longlong)puVar22)

          ;

          uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1e) >> 3) + (longlong)puVar22)

          ;

        }

        else {

          if (bVar4 == 4) {

            uVar21 = (ulonglong)*puVar22;

            goto LAB_14029ed3d;

          }

          uVar15 = 0;

          uVar14 = 0;

          uVar18 = uVar15;

        }

      }

      uVar11 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x18)]

                      [(*(uint *)(lVar9 + 8) & uVar17) >> (*(byte *)(lVar9 + 0x1c) & 0x3f)] - uVar15

               ) * (ushort)bVar2 + 1 + uVar15 * 0xff;

      uVar11 = (uVar11 >> 8) + uVar11;

      uVar15 = uVar11 >> 8;

      uVar12 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                      [(*(uint *)(lVar9 + 0xc) & uVar17) >> (*(byte *)(lVar9 + 0x1d) & 0x3f)] -

               uVar18) * (ushort)bVar2 + uVar18 * 0xff + 1;

      uVar12 = (uVar12 >> 8) + uVar12;

      uVar18 = uVar12 >> 8;

      uVar13 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1a)]

                      [(*(uint *)(lVar9 + 0x10) & uVar17) >> (*(byte *)(lVar9 + 0x1e) & 0x3f)] -

               uVar19) * (ushort)bVar2 + uVar19 * 0xff + 1;

      uVar13 = (uVar13 >> 8) + uVar13;

      uVar19 = uVar13 >> 8;

      uVar14 = (0xff - uVar14) * (ushort)bVar2 + uVar14 * 0xff + 1;

      uVar14 = (ushort)((uVar14 >> 8) + uVar14) >> 8;

      if (bVar4 == 1) {

        *(char *)puVar22 =

             (char)(uVar14 >> (8U - *(char *)(lVar10 + 0x1b) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1f) & 0x1f) |

             (char)(uVar19 >> (8U - *(char *)(lVar10 + 0x1a) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1e) & 0x1f) |

             (char)(uVar18 >> (8U - *(char *)(lVar10 + 0x19) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1d) & 0x1f) |

             (char)(uVar15 >> (8U - *(char *)(lVar10 + 0x18) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1c) & 0x1f);

      }

      else if (bVar4 == 2) {

        *(ushort *)puVar22 =

             (uVar14 >> (8U - *(char *)(lVar10 + 0x1b) & 0x1f)) << (*(byte *)(lVar10 + 0x1f) & 0x1f)

             | (uVar19 >> (8U - *(char *)(lVar10 + 0x1a) & 0x1f)) <<

               (*(byte *)(lVar10 + 0x1e) & 0x1f) |

             (uVar18 >> (8U - *(char *)(lVar10 + 0x19) & 0x1f)) << (*(byte *)(lVar10 + 0x1d) & 0x1f)

             | (uVar15 >> (8U - *(char *)(lVar10 + 0x18) & 0x1f)) <<

               (*(byte *)(lVar10 + 0x1c) & 0x1f);

      }

      else if (bVar4 == 3) {

        *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1c) >> 3) + (longlong)puVar22) =

             (byte)(uVar11 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1d) >> 3) + (longlong)puVar22) =

             (byte)(uVar12 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1e) >> 3) + (longlong)puVar22) =

             (byte)(uVar13 >> 8);

      }

      else if (bVar4 == 4) {

        *puVar22 = (uint)(uVar14 >> (8U - *(char *)(lVar10 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1f) & 0x1f) |

                   (uint)(uVar18 >> (8U - *(char *)(lVar10 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1d) & 0x1f) |

                   (uint)(uVar19 >> (8U - *(char *)(lVar10 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1e) & 0x1f) |

                   (uint)(uVar15 >> (8U - *(char *)(lVar10 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1c) & 0x1f);

      }

    }

    puVar23 = (uint *)((longlong)puVar23 + (longlong)(int)uVar24);

    puVar22 = (uint *)((longlong)puVar22 + (longlong)(int)uVar25);

LAB_14029f006:

    uVar17 = 0;

    if (bVar3 == 1) {

      uVar20 = (uint)(byte)*puVar23;

    }

    else if (bVar3 == 2) {

      uVar20 = (uint)(ushort)*puVar23;

    }

    else if (bVar3 == 3) {

      uVar20 = (uint)(uint3)*puVar23;

    }

    else {

      uVar20 = uVar17;

      if (bVar3 == 4) {

        uVar20 = *puVar23;

      }

    }

    if ((bVar2 != 0) && (uVar20 != uVar7)) {

      if (bVar4 == 1) {

        uVar21 = (ulonglong)(byte)*puVar22;

LAB_14029f127:

        uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x18)]

                               [(*(uint *)(lVar10 + 8) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1c) & 0x3f)];

        uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x19)]

                               [(*(uint *)(lVar10 + 0xc) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1d) & 0x3f)];

        uVar17 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1a)]

                             [(*(uint *)(lVar10 + 0x10) & uVar21) >>

                              (*(byte *)(lVar10 + 0x1e) & 0x3f)];

        uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1b)]

                               [(*(uint *)(lVar10 + 0x14) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1f) & 0x3f)];

      }

      else {

        if (bVar4 == 2) {

          uVar21 = (ulonglong)(ushort)*puVar22;

          goto LAB_14029f127;

        }

        if (bVar4 == 3) {

          uVar15 = 0xff;

          uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1c) >> 3) + (longlong)puVar22)

          ;

          uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1d) >> 3) + (longlong)puVar22)

          ;

          uVar17 = (uint)*(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1e) >> 3) + (longlong)puVar22);

        }

        else {

          if (bVar4 == 4) {

            uVar21 = (ulonglong)*puVar22;

            goto LAB_14029f127;

          }

          uVar18 = 0;

          uVar15 = 0;

          uVar19 = uVar18;

        }

      }

      uVar11 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x18)]

                      [(*(uint *)(lVar9 + 8) & uVar20) >> (*(byte *)(lVar9 + 0x1c) & 0x3f)] - uVar18

               ) * (ushort)bVar2 + 1 + uVar18 * 0xff;

      uVar11 = (uVar11 >> 8) + uVar11;

      uVar18 = uVar11 >> 8;

      uVar12 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                      [(*(uint *)(lVar9 + 0xc) & uVar20) >> (*(byte *)(lVar9 + 0x1d) & 0x3f)] -

               uVar19) * (ushort)bVar2 + uVar19 * 0xff + 1;

      uVar12 = (uVar12 >> 8) + uVar12;

      uVar19 = uVar12 >> 8;

      uVar13 = ((ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1a)]

                              [(*(uint *)(lVar9 + 0x10) & uVar20) >>

                               (*(byte *)(lVar9 + 0x1e) & 0x3f)] - (short)uVar17) * (ushort)bVar2 +

               (short)uVar17 * 0xff + 1;

      uVar13 = (uVar13 >> 8) + uVar13;

      uVar14 = uVar13 >> 8;

      uVar15 = (0xff - uVar15) * (ushort)bVar2 + uVar15 * 0xff + 1;

      uVar15 = (ushort)((uVar15 >> 8) + uVar15) >> 8;

      if (bVar4 == 1) {

        *(char *)puVar22 =

             (char)(uVar15 >> (8U - *(char *)(lVar10 + 0x1b) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1f) & 0x1f) |

             (char)(uVar14 >> (8U - *(char *)(lVar10 + 0x1a) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1e) & 0x1f) |

             (char)(uVar18 >> (8U - *(char *)(lVar10 + 0x18) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1c) & 0x1f) |

             (char)(uVar19 >> (8U - *(char *)(lVar10 + 0x19) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1d) & 0x1f);

      }

      else if (bVar4 == 2) {

        *(ushort *)puVar22 =

             (uVar15 >> (8U - *(char *)(lVar10 + 0x1b) & 0x1f)) << (*(byte *)(lVar10 + 0x1f) & 0x1f)

             | (uVar14 >> (8U - *(char *)(lVar10 + 0x1a) & 0x1f)) <<

               (*(byte *)(lVar10 + 0x1e) & 0x1f) |

             (uVar19 >> (8U - *(char *)(lVar10 + 0x19) & 0x1f)) << (*(byte *)(lVar10 + 0x1d) & 0x1f)

             | (uVar18 >> (8U - *(char *)(lVar10 + 0x18) & 0x1f)) <<

               (*(byte *)(lVar10 + 0x1c) & 0x1f);

      }

      else if (bVar4 == 3) {

        *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1c) >> 3) + (longlong)puVar22) =

             (byte)(uVar11 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1d) >> 3) + (longlong)puVar22) =

             (byte)(uVar12 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1e) >> 3) + (longlong)puVar22) =

             (byte)(uVar13 >> 8);

      }

      else if (bVar4 == 4) {

        *puVar22 = (uint)(uVar15 >> (8U - *(char *)(lVar10 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1f) & 0x1f) |

                   (uint)(uVar14 >> (8U - *(char *)(lVar10 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1e) & 0x1f) |

                   (uint)(uVar19 >> (8U - *(char *)(lVar10 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1d) & 0x1f) |

                   (uint)(uVar18 >> (8U - *(char *)(lVar10 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1c) & 0x1f);

      }

    }

    local_68 = local_68 + -1;

    puVar23 = (uint *)((longlong)puVar23 + (ulonglong)bVar3);

    puVar22 = (uint *)((longlong)puVar22 + (ulonglong)bVar4);

    if (local_68 < 1) goto LAB_14029f406;

LAB_14029e448:

    uVar19 = 0;

    if (bVar3 == 1) {

      uVar17 = (uint)(byte)*puVar23;

    }

    else if (bVar3 == 2) {

      uVar17 = (uint)(ushort)*puVar23;

    }

    else if (bVar3 == 3) {

      uVar17 = (uint)(uint3)*puVar23;

    }

    else if (bVar3 == 4) {

      uVar17 = *puVar23;

    }

    else {

      uVar17 = 0;

    }

    if ((bVar2 != 0) && (uVar17 != uVar7)) {

      if (bVar4 == 1) {

        uVar21 = (ulonglong)(byte)*puVar22;

LAB_14029e569:

        uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x18)]

                               [(*(uint *)(lVar10 + 8) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1c) & 0x3f)];

        uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x19)]

                               [(*(uint *)(lVar10 + 0xc) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1d) & 0x3f)];

        uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1a)]

                               [(*(uint *)(lVar10 + 0x10) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1e) & 0x3f)];

        uVar14 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar10 + 0x1b)]

                               [(*(uint *)(lVar10 + 0x14) & uVar21) >>

                                (*(byte *)(lVar10 + 0x1f) & 0x3f)];

      }

      else {

        if (bVar4 == 2) {

          uVar21 = (ulonglong)(ushort)*puVar22;

          goto LAB_14029e569;

        }

        if (bVar4 == 3) {

          uVar14 = 0xff;

          uVar15 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1c) >> 3) + (longlong)puVar22)

          ;

          uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1d) >> 3) + (longlong)puVar22)

          ;

          uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1e) >> 3) + (longlong)puVar22)

          ;

        }

        else {

          if (bVar4 == 4) {

            uVar21 = (ulonglong)*puVar22;

            goto LAB_14029e569;

          }

          uVar15 = 0;

          uVar14 = 0;

          uVar18 = uVar15;

        }

      }

      uVar11 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x18)]

                      [(*(uint *)(lVar9 + 8) & uVar17) >> (*(byte *)(lVar9 + 0x1c) & 0x3f)] - uVar15

               ) * (ushort)bVar2 + 1 + uVar15 * 0xff;

      uVar11 = (uVar11 >> 8) + uVar11;

      uVar15 = uVar11 >> 8;

      uVar12 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x19)]

                      [(*(uint *)(lVar9 + 0xc) & uVar17) >> (*(byte *)(lVar9 + 0x1d) & 0x3f)] -

               uVar18) * (ushort)bVar2 + uVar18 * 0xff + 1;

      uVar12 = (uVar12 >> 8) + uVar12;

      uVar18 = uVar12 >> 8;

      uVar13 = ((byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar9 + 0x1a)]

                      [(*(uint *)(lVar9 + 0x10) & uVar17) >> (*(byte *)(lVar9 + 0x1e) & 0x3f)] -

               uVar19) * (ushort)bVar2 + uVar19 * 0xff + 1;

      uVar13 = (uVar13 >> 8) + uVar13;

      uVar19 = uVar13 >> 8;

      uVar14 = (0xff - uVar14) * (ushort)bVar2 + uVar14 * 0xff + 1;

      uVar14 = (ushort)((uVar14 >> 8) + uVar14) >> 8;

      if (bVar4 == 1) {

        *(char *)puVar22 =

             (char)(uVar14 >> (8U - *(char *)(lVar10 + 0x1b) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1f) & 0x1f) |

             (char)(uVar19 >> (8U - *(char *)(lVar10 + 0x1a) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1e) & 0x1f) |

             (char)(uVar15 >> (8U - *(char *)(lVar10 + 0x18) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1c) & 0x1f) |

             (char)(uVar18 >> (8U - *(char *)(lVar10 + 0x19) & 0x1f)) <<

             (*(byte *)(lVar10 + 0x1d) & 0x1f);

      }

      else if (bVar4 == 2) {

        *(ushort *)puVar22 =

             (uVar14 >> (8U - *(char *)(lVar10 + 0x1b) & 0x1f)) << (*(byte *)(lVar10 + 0x1f) & 0x1f)

             | (uVar19 >> (8U - *(char *)(lVar10 + 0x1a) & 0x1f)) <<

               (*(byte *)(lVar10 + 0x1e) & 0x1f) |

             (uVar15 >> (8U - *(char *)(lVar10 + 0x18) & 0x1f)) << (*(byte *)(lVar10 + 0x1c) & 0x1f)

             | (uVar18 >> (8U - *(char *)(lVar10 + 0x19) & 0x1f)) <<

               (*(byte *)(lVar10 + 0x1d) & 0x1f);

      }

      else if (bVar4 == 3) {

        *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1c) >> 3) + (longlong)puVar22) =

             (byte)(uVar11 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1d) >> 3) + (longlong)puVar22) =

             (byte)(uVar12 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar10 + 0x1e) >> 3) + (longlong)puVar22) =

             (byte)(uVar13 >> 8);

      }

      else if (bVar4 == 4) {

        *puVar22 = (uint)(uVar14 >> (8U - *(char *)(lVar10 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1f) & 0x1f) |

                   (uint)(uVar19 >> (8U - *(char *)(lVar10 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1e) & 0x1f) |

                   (uint)(uVar18 >> (8U - *(char *)(lVar10 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1d) & 0x1f) |

                   (uint)(uVar15 >> (8U - *(char *)(lVar10 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar10 + 0x1c) & 0x1f);

      }

    }

    puVar23 = (uint *)((longlong)puVar23 + (longlong)(int)uVar24);

    puVar22 = (uint *)((longlong)puVar22 + (longlong)(int)uVar25);

  } while( true );

}




