// Address: 0x140292310
// Ghidra name: FUN_140292310
// ============ 0x140292310 FUN_140292310 (size=3844) ============


void FUN_140292310(longlong param_1)



{

  int iVar1;

  byte bVar2;

  byte bVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  longlong lVar8;

  longlong lVar9;

  short sVar10;

  ulonglong uVar11;

  ushort uVar12;

  ushort uVar13;

  ushort uVar14;

  ushort uVar15;

  int iVar16;

  uint uVar17;

  ushort uVar18;

  ushort uVar19;

  uint uVar20;

  byte *pbVar21;

  ulonglong uVar22;

  uint *puVar23;

  ushort uVar24;

  int local_res20;

  

  iVar4 = *(int *)(param_1 + 0x1c);

  lVar8 = *(longlong *)(param_1 + 0x58);

  bVar2 = *(byte *)(param_1 + 0x83);

  uVar5 = *(uint *)(param_1 + 0x38);

  uVar6 = *(uint *)(param_1 + 0x7c);

  pbVar21 = *(byte **)(param_1 + 8);

  puVar23 = *(uint **)(param_1 + 0x30);

  bVar3 = *(byte *)(lVar8 + 5);

  iVar7 = *(int *)(param_1 + 0x44);

  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 8);

  iVar16 = *(int *)(param_1 + 0x3c);

  while( true ) {

    if (iVar16 == 0) {

      return;

    }

    iVar1 = uVar5 + 3;

    local_res20 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;

    uVar17 = uVar5 & 3;

    uVar20 = (uint)bVar3;

    if (uVar17 == 0) goto LAB_1402923be;

    if (uVar17 == 1) goto LAB_140292e4e;

    if (uVar17 == 2) goto LAB_140292ac4;

    if (uVar17 == 3) break;

LAB_1402931ea:

    pbVar21 = pbVar21 + iVar4;

    puVar23 = (uint *)((longlong)puVar23 + (longlong)iVar7);

    iVar16 = iVar16 + -1;

  }

  do {

    uVar11 = (ulonglong)*pbVar21;

    if (*pbVar21 != uVar6) {

      if (bVar3 == 1) {

        uVar22 = (ulonglong)(byte)*puVar23;

LAB_1402927e8:

        uVar24 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x18)]

                               [(*(uint *)(lVar8 + 8) & uVar22) >> (*(byte *)(lVar8 + 0x1c) & 0x3f)]

        ;

        uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x19)]

                               [(*(uint *)(lVar8 + 0xc) & uVar22) >>

                                (*(byte *)(lVar8 + 0x1d) & 0x3f)];

        uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x1a)]

                               [(*(uint *)(lVar8 + 0x10) & uVar22) >>

                                (*(byte *)(lVar8 + 0x1e) & 0x3f)];

        uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x1b)]

                               [(*(uint *)(lVar8 + 0x14) & uVar22) >>

                                (*(byte *)(lVar8 + 0x1f) & 0x3f)];

      }

      else {

        if (bVar3 == 2) {

          uVar22 = (ulonglong)(ushort)*puVar23;

          goto LAB_1402927e8;

        }

        if (bVar3 == 3) {

          uVar15 = 0xff;

          uVar24 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1c) >> 3) + (longlong)puVar23);

          uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1d) >> 3) + (longlong)puVar23);

          uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1e) >> 3) + (longlong)puVar23);

        }

        else {

          if (bVar3 == 4) {

            uVar22 = (ulonglong)*puVar23;

            goto LAB_1402927e8;

          }

          uVar24 = 0;

          uVar18 = 0;

          uVar19 = 0;

          uVar15 = 0;

        }

      }

      sVar10 = (short)(((uint)*(byte *)(lVar9 + 3 + uVar11 * 4) * (uint)bVar2) / 0xff);

      uVar12 = (*(byte *)(lVar9 + uVar11 * 4) - uVar24) * sVar10 + uVar24 * 0xff + 1;

      uVar12 = (uVar12 >> 8) + uVar12;

      uVar24 = uVar12 >> 8;

      uVar13 = (*(byte *)(lVar9 + 1 + uVar11 * 4) - uVar18) * sVar10 + uVar18 * 0xff + 1;

      uVar13 = (uVar13 >> 8) + uVar13;

      uVar18 = uVar13 >> 8;

      uVar14 = (*(byte *)(lVar9 + 2 + uVar11 * 4) - uVar19) * sVar10 + uVar19 * 0xff + 1;

      uVar14 = (uVar14 >> 8) + uVar14;

      uVar19 = uVar14 >> 8;

      uVar15 = (0xff - uVar15) * sVar10 + uVar15 * 0xff + 1;

      uVar15 = (ushort)((uVar15 >> 8) + uVar15) >> 8;

      if (bVar3 == 1) {

        *(char *)puVar23 =

             (char)(uVar15 >> (8U - *(char *)(lVar8 + 0x1b) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1f) & 0x1f) |

             (char)(uVar18 >> (8U - *(char *)(lVar8 + 0x19) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1d) & 0x1f) |

             (char)(uVar24 >> (8U - *(char *)(lVar8 + 0x18) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1c) & 0x1f) |

             (char)(uVar19 >> (8U - *(char *)(lVar8 + 0x1a) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1e) & 0x1f);

      }

      else if (bVar3 == 2) {

        *(ushort *)puVar23 =

             (uVar15 >> (8U - *(char *)(lVar8 + 0x1b) & 0x1f)) << (*(byte *)(lVar8 + 0x1f) & 0x1f) |

             (uVar18 >> (8U - *(char *)(lVar8 + 0x19) & 0x1f)) << (*(byte *)(lVar8 + 0x1d) & 0x1f) |

             (uVar24 >> (8U - *(char *)(lVar8 + 0x18) & 0x1f)) << (*(byte *)(lVar8 + 0x1c) & 0x1f) |

             (uVar19 >> (8U - *(char *)(lVar8 + 0x1a) & 0x1f)) << (*(byte *)(lVar8 + 0x1e) & 0x1f);

      }

      else if (bVar3 == 3) {

        *(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1c) >> 3) + (longlong)puVar23) =

             (byte)(uVar12 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1d) >> 3) + (longlong)puVar23) =

             (byte)(uVar13 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1e) >> 3) + (longlong)puVar23) =

             (byte)(uVar14 >> 8);

      }

      else if (bVar3 == 4) {

        *puVar23 = (uint)(uVar15 >> (8U - *(char *)(lVar8 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1f) & 0x1f) |

                   (uint)(uVar18 >> (8U - *(char *)(lVar8 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1d) & 0x1f) |

                   (uint)(uVar24 >> (8U - *(char *)(lVar8 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1c) & 0x1f) |

                   (uint)(uVar19 >> (8U - *(char *)(lVar8 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1e) & 0x1f);

      }

    }

    pbVar21 = pbVar21 + 1;

    puVar23 = (uint *)((longlong)puVar23 + (longlong)(int)uVar20);

LAB_140292ac4:

    uVar11 = (ulonglong)*pbVar21;

    if (*pbVar21 != uVar6) {

      if (bVar3 == 1) {

        uVar22 = (ulonglong)(byte)*puVar23;

LAB_140292b6b:

        uVar24 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x18)]

                               [(*(uint *)(lVar8 + 8) & uVar22) >> (*(byte *)(lVar8 + 0x1c) & 0x3f)]

        ;

        uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x19)]

                               [(*(uint *)(lVar8 + 0xc) & uVar22) >>

                                (*(byte *)(lVar8 + 0x1d) & 0x3f)];

        uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x1a)]

                               [(*(uint *)(lVar8 + 0x10) & uVar22) >>

                                (*(byte *)(lVar8 + 0x1e) & 0x3f)];

        uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x1b)]

                               [(*(uint *)(lVar8 + 0x14) & uVar22) >>

                                (*(byte *)(lVar8 + 0x1f) & 0x3f)];

      }

      else {

        if (bVar3 == 2) {

          uVar22 = (ulonglong)(ushort)*puVar23;

          goto LAB_140292b6b;

        }

        if (bVar3 == 3) {

          uVar15 = 0xff;

          uVar24 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1c) >> 3) + (longlong)puVar23);

          uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1d) >> 3) + (longlong)puVar23);

          uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1e) >> 3) + (longlong)puVar23);

        }

        else {

          if (bVar3 == 4) {

            uVar22 = (ulonglong)*puVar23;

            goto LAB_140292b6b;

          }

          uVar24 = 0;

          uVar18 = 0;

          uVar19 = 0;

          uVar15 = 0;

        }

      }

      sVar10 = (short)(((uint)*(byte *)(lVar9 + 3 + uVar11 * 4) * (uint)bVar2) / 0xff);

      uVar12 = (*(byte *)(lVar9 + uVar11 * 4) - uVar24) * sVar10 + uVar24 * 0xff + 1;

      uVar12 = (uVar12 >> 8) + uVar12;

      uVar24 = uVar12 >> 8;

      uVar13 = (*(byte *)(lVar9 + 1 + uVar11 * 4) - uVar18) * sVar10 + uVar18 * 0xff + 1;

      uVar13 = (uVar13 >> 8) + uVar13;

      uVar18 = uVar13 >> 8;

      uVar14 = (*(byte *)(lVar9 + 2 + uVar11 * 4) - uVar19) * sVar10 + uVar19 * 0xff + 1;

      uVar14 = (uVar14 >> 8) + uVar14;

      uVar19 = uVar14 >> 8;

      uVar15 = (0xff - uVar15) * sVar10 + uVar15 * 0xff + 1;

      uVar15 = (ushort)((uVar15 >> 8) + uVar15) >> 8;

      if (bVar3 == 1) {

        *(char *)puVar23 =

             (char)(uVar15 >> (8U - *(char *)(lVar8 + 0x1b) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1f) & 0x1f) |

             (char)(uVar19 >> (8U - *(char *)(lVar8 + 0x1a) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1e) & 0x1f) |

             (char)(uVar18 >> (8U - *(char *)(lVar8 + 0x19) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1d) & 0x1f) |

             (char)(uVar24 >> (8U - *(char *)(lVar8 + 0x18) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1c) & 0x1f);

      }

      else if (bVar3 == 2) {

        *(ushort *)puVar23 =

             (uVar15 >> (8U - *(char *)(lVar8 + 0x1b) & 0x1f)) << (*(byte *)(lVar8 + 0x1f) & 0x1f) |

             (uVar19 >> (8U - *(char *)(lVar8 + 0x1a) & 0x1f)) << (*(byte *)(lVar8 + 0x1e) & 0x1f) |

             (uVar18 >> (8U - *(char *)(lVar8 + 0x19) & 0x1f)) << (*(byte *)(lVar8 + 0x1d) & 0x1f) |

             (uVar24 >> (8U - *(char *)(lVar8 + 0x18) & 0x1f)) << (*(byte *)(lVar8 + 0x1c) & 0x1f);

      }

      else if (bVar3 == 3) {

        *(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1c) >> 3) + (longlong)puVar23) =

             (byte)(uVar12 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1d) >> 3) + (longlong)puVar23) =

             (byte)(uVar13 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1e) >> 3) + (longlong)puVar23) =

             (byte)(uVar14 >> 8);

      }

      else if (bVar3 == 4) {

        *puVar23 = (uint)(uVar15 >> (8U - *(char *)(lVar8 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1f) & 0x1f) |

                   (uint)(uVar19 >> (8U - *(char *)(lVar8 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1e) & 0x1f) |

                   (uint)(uVar24 >> (8U - *(char *)(lVar8 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1c) & 0x1f) |

                   (uint)(uVar18 >> (8U - *(char *)(lVar8 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1d) & 0x1f);

      }

    }

    pbVar21 = pbVar21 + 1;

    puVar23 = (uint *)((longlong)puVar23 + (longlong)(int)uVar20);

LAB_140292e4e:

    uVar11 = (ulonglong)*pbVar21;

    if (*pbVar21 != uVar6) {

      if (bVar3 == 1) {

        uVar22 = (ulonglong)(byte)*puVar23;

LAB_140292ef5:

        uVar24 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x18)]

                               [(*(uint *)(lVar8 + 8) & uVar22) >> (*(byte *)(lVar8 + 0x1c) & 0x3f)]

        ;

        uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x19)]

                               [(*(uint *)(lVar8 + 0xc) & uVar22) >>

                                (*(byte *)(lVar8 + 0x1d) & 0x3f)];

        uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x1a)]

                               [(*(uint *)(lVar8 + 0x10) & uVar22) >>

                                (*(byte *)(lVar8 + 0x1e) & 0x3f)];

        uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x1b)]

                               [(*(uint *)(lVar8 + 0x14) & uVar22) >>

                                (*(byte *)(lVar8 + 0x1f) & 0x3f)];

      }

      else {

        if (bVar3 == 2) {

          uVar22 = (ulonglong)(ushort)*puVar23;

          goto LAB_140292ef5;

        }

        if (bVar3 == 3) {

          uVar15 = 0xff;

          uVar24 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1c) >> 3) + (longlong)puVar23);

          uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1d) >> 3) + (longlong)puVar23);

          uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1e) >> 3) + (longlong)puVar23);

        }

        else {

          if (bVar3 == 4) {

            uVar22 = (ulonglong)*puVar23;

            goto LAB_140292ef5;

          }

          uVar24 = 0;

          uVar18 = 0;

          uVar19 = 0;

          uVar15 = 0;

        }

      }

      sVar10 = (short)(((uint)*(byte *)(lVar9 + 3 + uVar11 * 4) * (uint)bVar2) / 0xff);

      uVar12 = (*(byte *)(lVar9 + uVar11 * 4) - uVar24) * sVar10 + uVar24 * 0xff + 1;

      uVar12 = (uVar12 >> 8) + uVar12;

      uVar24 = uVar12 >> 8;

      uVar13 = (*(byte *)(lVar9 + 1 + uVar11 * 4) - uVar18) * sVar10 + uVar18 * 0xff + 1;

      uVar13 = (uVar13 >> 8) + uVar13;

      uVar18 = uVar13 >> 8;

      uVar14 = (*(byte *)(lVar9 + 2 + uVar11 * 4) - uVar19) * sVar10 + uVar19 * 0xff + 1;

      uVar14 = (uVar14 >> 8) + uVar14;

      uVar19 = uVar14 >> 8;

      uVar15 = (0xff - uVar15) * sVar10 + uVar15 * 0xff + 1;

      uVar15 = (ushort)((uVar15 >> 8) + uVar15) >> 8;

      if (bVar3 == 1) {

        *(char *)puVar23 =

             (char)(uVar15 >> (8U - *(char *)(lVar8 + 0x1b) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1f) & 0x1f) |

             (char)(uVar19 >> (8U - *(char *)(lVar8 + 0x1a) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1e) & 0x1f) |

             (char)(uVar18 >> (8U - *(char *)(lVar8 + 0x19) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1d) & 0x1f) |

             (char)(uVar24 >> (8U - *(char *)(lVar8 + 0x18) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1c) & 0x1f);

      }

      else if (bVar3 == 2) {

        *(ushort *)puVar23 =

             (uVar15 >> (8U - *(char *)(lVar8 + 0x1b) & 0x1f)) << (*(byte *)(lVar8 + 0x1f) & 0x1f) |

             (uVar18 >> (8U - *(char *)(lVar8 + 0x19) & 0x1f)) << (*(byte *)(lVar8 + 0x1d) & 0x1f) |

             (uVar19 >> (8U - *(char *)(lVar8 + 0x1a) & 0x1f)) << (*(byte *)(lVar8 + 0x1e) & 0x1f) |

             (uVar24 >> (8U - *(char *)(lVar8 + 0x18) & 0x1f)) << (*(byte *)(lVar8 + 0x1c) & 0x1f);

      }

      else if (bVar3 == 3) {

        *(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1c) >> 3) + (longlong)puVar23) =

             (byte)(uVar12 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1d) >> 3) + (longlong)puVar23) =

             (byte)(uVar13 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1e) >> 3) + (longlong)puVar23) =

             (byte)(uVar14 >> 8);

      }

      else if (bVar3 == 4) {

        *puVar23 = (uint)(uVar15 >> (8U - *(char *)(lVar8 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1f) & 0x1f) |

                   (uint)(uVar19 >> (8U - *(char *)(lVar8 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1e) & 0x1f) |

                   (uint)(uVar18 >> (8U - *(char *)(lVar8 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1d) & 0x1f) |

                   (uint)(uVar24 >> (8U - *(char *)(lVar8 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1c) & 0x1f);

      }

    }

    local_res20 = local_res20 + -1;

    pbVar21 = pbVar21 + 1;

    puVar23 = (uint *)((longlong)puVar23 + (ulonglong)bVar3);

    if (local_res20 < 1) goto LAB_1402931ea;

LAB_1402923be:

    uVar11 = (ulonglong)*pbVar21;

    if (*pbVar21 != uVar6) {

      if (bVar3 == 1) {

        uVar22 = (ulonglong)(byte)*puVar23;

LAB_140292465:

        uVar24 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x18)]

                               [(*(uint *)(lVar8 + 8) & uVar22) >> (*(byte *)(lVar8 + 0x1c) & 0x3f)]

        ;

        uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x19)]

                               [(*(uint *)(lVar8 + 0xc) & uVar22) >>

                                (*(byte *)(lVar8 + 0x1d) & 0x3f)];

        uVar19 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x1a)]

                               [(*(uint *)(lVar8 + 0x10) & uVar22) >>

                                (*(byte *)(lVar8 + 0x1e) & 0x3f)];

        uVar15 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar8 + 0x1b)]

                               [(*(uint *)(lVar8 + 0x14) & uVar22) >>

                                (*(byte *)(lVar8 + 0x1f) & 0x3f)];

      }

      else {

        if (bVar3 == 2) {

          uVar22 = (ulonglong)(ushort)*puVar23;

          goto LAB_140292465;

        }

        if (bVar3 == 3) {

          uVar15 = 0xff;

          uVar24 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1c) >> 3) + (longlong)puVar23);

          uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1d) >> 3) + (longlong)puVar23);

          uVar19 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1e) >> 3) + (longlong)puVar23);

        }

        else {

          if (bVar3 == 4) {

            uVar22 = (ulonglong)*puVar23;

            goto LAB_140292465;

          }

          uVar24 = 0;

          uVar18 = 0;

          uVar19 = 0;

          uVar15 = 0;

        }

      }

      sVar10 = (short)(((uint)*(byte *)(lVar9 + 3 + uVar11 * 4) * (uint)bVar2) / 0xff);

      uVar12 = (*(byte *)(lVar9 + uVar11 * 4) - uVar24) * sVar10 + uVar24 * 0xff + 1;

      uVar12 = (uVar12 >> 8) + uVar12;

      uVar24 = uVar12 >> 8;

      uVar13 = (*(byte *)(lVar9 + 1 + uVar11 * 4) - uVar18) * sVar10 + uVar18 * 0xff + 1;

      uVar13 = (uVar13 >> 8) + uVar13;

      uVar18 = uVar13 >> 8;

      uVar14 = (*(byte *)(lVar9 + 2 + uVar11 * 4) - uVar19) * sVar10 + uVar19 * 0xff + 1;

      uVar14 = (uVar14 >> 8) + uVar14;

      uVar19 = uVar14 >> 8;

      uVar15 = (0xff - uVar15) * sVar10 + uVar15 * 0xff + 1;

      uVar15 = (ushort)((uVar15 >> 8) + uVar15) >> 8;

      if (bVar3 == 1) {

        *(char *)puVar23 =

             (char)(uVar15 >> (8U - *(char *)(lVar8 + 0x1b) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1f) & 0x1f) |

             (char)(uVar19 >> (8U - *(char *)(lVar8 + 0x1a) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1e) & 0x1f) |

             (char)(uVar18 >> (8U - *(char *)(lVar8 + 0x19) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1d) & 0x1f) |

             (char)(uVar24 >> (8U - *(char *)(lVar8 + 0x18) & 0x1f)) <<

             (*(byte *)(lVar8 + 0x1c) & 0x1f);

      }

      else if (bVar3 == 2) {

        *(ushort *)puVar23 =

             (uVar15 >> (8U - *(char *)(lVar8 + 0x1b) & 0x1f)) << (*(byte *)(lVar8 + 0x1f) & 0x1f) |

             (uVar19 >> (8U - *(char *)(lVar8 + 0x1a) & 0x1f)) << (*(byte *)(lVar8 + 0x1e) & 0x1f) |

             (uVar18 >> (8U - *(char *)(lVar8 + 0x19) & 0x1f)) << (*(byte *)(lVar8 + 0x1d) & 0x1f) |

             (uVar24 >> (8U - *(char *)(lVar8 + 0x18) & 0x1f)) << (*(byte *)(lVar8 + 0x1c) & 0x1f);

      }

      else if (bVar3 == 3) {

        *(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1c) >> 3) + (longlong)puVar23) =

             (byte)(uVar12 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1d) >> 3) + (longlong)puVar23) =

             (byte)(uVar13 >> 8);

        *(byte *)((ulonglong)(*(byte *)(lVar8 + 0x1e) >> 3) + (longlong)puVar23) =

             (byte)(uVar14 >> 8);

      }

      else if (bVar3 == 4) {

        *puVar23 = (uint)(uVar15 >> (8U - *(char *)(lVar8 + 0x1b) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1f) & 0x1f) |

                   (uint)(uVar18 >> (8U - *(char *)(lVar8 + 0x19) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1d) & 0x1f) |

                   (uint)(uVar24 >> (8U - *(char *)(lVar8 + 0x18) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1c) & 0x1f) |

                   (uint)(uVar19 >> (8U - *(char *)(lVar8 + 0x1a) & 0x1f)) <<

                   (*(byte *)(lVar8 + 0x1e) & 0x1f);

      }

    }

    pbVar21 = pbVar21 + 1;

    puVar23 = (uint *)((longlong)puVar23 + (longlong)(int)uVar20);

  } while( true );

}




