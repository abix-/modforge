// Address: 0x140291460
// Ghidra name: FUN_140291460
// ============ 0x140291460 FUN_140291460 (size=3750) ============


void FUN_140291460(longlong param_1)



{

  int iVar1;

  byte bVar2;

  byte bVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  longlong lVar7;

  longlong lVar8;

  short sVar9;

  ulonglong uVar10;

  ushort uVar11;

  ushort uVar12;

  ushort uVar13;

  ushort uVar14;

  int iVar15;

  uint uVar16;

  ushort uVar17;

  ushort uVar18;

  byte *pbVar19;

  ulonglong uVar20;

  uint *puVar21;

  ushort uVar22;

  int local_res18;

  

  iVar4 = *(int *)(param_1 + 0x1c);

  lVar7 = *(longlong *)(param_1 + 0x58);

  bVar2 = *(byte *)(param_1 + 0x83);

  uVar5 = *(uint *)(param_1 + 0x38);

  pbVar19 = *(byte **)(param_1 + 8);

  puVar21 = *(uint **)(param_1 + 0x30);

  bVar3 = *(byte *)(lVar7 + 5);

  iVar6 = *(int *)(param_1 + 0x44);

  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 8);

  iVar15 = *(int *)(param_1 + 0x3c);

  while( true ) {

    if (iVar15 == 0) {

      return;

    }

    iVar1 = uVar5 + 3;

    local_res18 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;

    uVar16 = uVar5 & 3;

    if (uVar16 == 0) goto LAB_14029150a;

    if (uVar16 == 1) goto LAB_140291f51;

    if (uVar16 == 2) goto LAB_140291be4;

    if (uVar16 == 3) break;

LAB_1402922dd:

    pbVar19 = pbVar19 + iVar4;

    puVar21 = (uint *)((longlong)puVar21 + (longlong)iVar6);

    iVar15 = iVar15 + -1;

  }

  do {

    uVar22 = 0;

    uVar10 = (ulonglong)*pbVar19;

    if (bVar3 == 1) {

      uVar20 = (ulonglong)(byte)*puVar21;

LAB_14029190d:

      uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                             [(*(uint *)(lVar7 + 8) & uVar20) >> (*(byte *)(lVar7 + 0x1c) & 0x3f)];

      uVar17 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                             [(*(uint *)(lVar7 + 0xc) & uVar20) >> (*(byte *)(lVar7 + 0x1d) & 0x3f)]

      ;

      uVar22 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                             [(*(uint *)(lVar7 + 0x10) & uVar20) >> (*(byte *)(lVar7 + 0x1e) & 0x3f)

                             ];

      uVar14 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1b)]

                             [(*(uint *)(lVar7 + 0x14) & uVar20) >> (*(byte *)(lVar7 + 0x1f) & 0x3f)

                             ];

    }

    else {

      if (bVar3 == 2) {

        uVar20 = (ulonglong)(ushort)*puVar21;

        goto LAB_14029190d;

      }

      if (bVar3 == 3) {

        uVar14 = 0xff;

        uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar21);

        uVar17 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar21);

        uVar22 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar21);

      }

      else {

        if (bVar3 == 4) {

          uVar20 = (ulonglong)*puVar21;

          goto LAB_14029190d;

        }

        uVar14 = 0;

        uVar18 = uVar22;

        uVar17 = uVar22;

      }

    }

    sVar9 = (short)(((uint)*(byte *)(lVar8 + 3 + uVar10 * 4) * (uint)bVar2) / 0xff);

    uVar11 = (*(byte *)(lVar8 + uVar10 * 4) - uVar18) * sVar9 + uVar18 * 0xff + 1;

    uVar11 = (uVar11 >> 8) + uVar11;

    uVar18 = uVar11 >> 8;

    uVar12 = (*(byte *)(lVar8 + 1 + uVar10 * 4) - uVar17) * sVar9 + uVar17 * 0xff + 1;

    uVar12 = (uVar12 >> 8) + uVar12;

    uVar17 = uVar12 >> 8;

    uVar13 = (*(byte *)(lVar8 + 2 + uVar10 * 4) - uVar22) * sVar9 + uVar22 * 0xff + 1;

    uVar13 = (uVar13 >> 8) + uVar13;

    uVar22 = uVar13 >> 8;

    uVar14 = (0xff - uVar14) * sVar9 + uVar14 * 0xff + 1;

    uVar14 = (ushort)((uVar14 >> 8) + uVar14) >> 8;

    if (bVar3 == 1) {

      *(char *)puVar21 =

           (char)(uVar14 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1f) & 0x1f) |

           (char)(uVar17 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1d) & 0x1f) |

           (char)(uVar18 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1c) & 0x1f) |

           (char)(uVar22 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1e) & 0x1f);

    }

    else if (bVar3 == 2) {

      *(ushort *)puVar21 =

           (uVar14 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) << (*(byte *)(lVar7 + 0x1f) & 0x1f) |

           (uVar17 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) << (*(byte *)(lVar7 + 0x1d) & 0x1f) |

           (uVar22 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) << (*(byte *)(lVar7 + 0x1e) & 0x1f) |

           (uVar18 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) << (*(byte *)(lVar7 + 0x1c) & 0x1f);

    }

    else if (bVar3 == 3) {

      *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar21) = (byte)(uVar11 >> 8)

      ;

      *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar21) = (byte)(uVar12 >> 8)

      ;

      *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar21) = (byte)(uVar13 >> 8)

      ;

    }

    else if (bVar3 == 4) {

      *puVar21 = (uint)(uVar14 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1f) & 0x1f) |

                 (uint)(uVar22 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1e) & 0x1f) |

                 (uint)(uVar17 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1d) & 0x1f) |

                 (uint)(uVar18 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1c) & 0x1f);

    }

    pbVar19 = pbVar19 + 1;

    puVar21 = (uint *)((longlong)puVar21 + (longlong)(int)(uint)bVar3);

LAB_140291be4:

    uVar22 = 0;

    uVar10 = (ulonglong)*pbVar19;

    if (bVar3 == 1) {

      uVar20 = (ulonglong)(byte)*puVar21;

LAB_140291c7a:

      uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                             [(*(uint *)(lVar7 + 8) & uVar20) >> (*(byte *)(lVar7 + 0x1c) & 0x3f)];

      uVar17 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                             [(*(uint *)(lVar7 + 0xc) & uVar20) >> (*(byte *)(lVar7 + 0x1d) & 0x3f)]

      ;

      uVar22 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                             [(*(uint *)(lVar7 + 0x10) & uVar20) >> (*(byte *)(lVar7 + 0x1e) & 0x3f)

                             ];

      uVar14 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1b)]

                             [(*(uint *)(lVar7 + 0x14) & uVar20) >> (*(byte *)(lVar7 + 0x1f) & 0x3f)

                             ];

    }

    else {

      if (bVar3 == 2) {

        uVar20 = (ulonglong)(ushort)*puVar21;

        goto LAB_140291c7a;

      }

      if (bVar3 == 3) {

        uVar14 = 0xff;

        uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar21);

        uVar17 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar21);

        uVar22 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar21);

      }

      else {

        if (bVar3 == 4) {

          uVar20 = (ulonglong)*puVar21;

          goto LAB_140291c7a;

        }

        uVar14 = 0;

        uVar18 = uVar22;

        uVar17 = uVar22;

      }

    }

    sVar9 = (short)(((uint)*(byte *)(lVar8 + 3 + uVar10 * 4) * (uint)bVar2) / 0xff);

    uVar11 = (*(byte *)(lVar8 + uVar10 * 4) - uVar18) * sVar9 + uVar18 * 0xff + 1;

    uVar11 = (uVar11 >> 8) + uVar11;

    uVar18 = uVar11 >> 8;

    uVar12 = (*(byte *)(lVar8 + 1 + uVar10 * 4) - uVar17) * sVar9 + uVar17 * 0xff + 1;

    uVar12 = (uVar12 >> 8) + uVar12;

    uVar17 = uVar12 >> 8;

    uVar13 = (*(byte *)(lVar8 + 2 + uVar10 * 4) - uVar22) * sVar9 + uVar22 * 0xff + 1;

    uVar13 = (uVar13 >> 8) + uVar13;

    uVar22 = uVar13 >> 8;

    uVar14 = (0xff - uVar14) * sVar9 + uVar14 * 0xff + 1;

    uVar14 = (ushort)((uVar14 >> 8) + uVar14) >> 8;

    if (bVar3 == 1) {

      *(char *)puVar21 =

           (char)(uVar14 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1f) & 0x1f) |

           (char)(uVar22 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1e) & 0x1f) |

           (char)(uVar18 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1c) & 0x1f) |

           (char)(uVar17 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1d) & 0x1f);

    }

    else if (bVar3 == 2) {

      *(ushort *)puVar21 =

           (uVar14 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) << (*(byte *)(lVar7 + 0x1f) & 0x1f) |

           (uVar22 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) << (*(byte *)(lVar7 + 0x1e) & 0x1f) |

           (uVar17 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) << (*(byte *)(lVar7 + 0x1d) & 0x1f) |

           (uVar18 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) << (*(byte *)(lVar7 + 0x1c) & 0x1f);

    }

    else if (bVar3 == 3) {

      *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar21) = (byte)(uVar11 >> 8)

      ;

      *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar21) = (byte)(uVar12 >> 8)

      ;

      *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar21) = (byte)(uVar13 >> 8)

      ;

    }

    else if (bVar3 == 4) {

      *puVar21 = (uint)(uVar14 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1f) & 0x1f) |

                 (uint)(uVar22 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1e) & 0x1f) |

                 (uint)(uVar17 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1d) & 0x1f) |

                 (uint)(uVar18 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1c) & 0x1f);

    }

    pbVar19 = pbVar19 + 1;

    puVar21 = (uint *)((longlong)puVar21 + (longlong)(int)(uint)bVar3);

LAB_140291f51:

    uVar22 = 0;

    uVar10 = (ulonglong)*pbVar19;

    if (bVar3 == 1) {

      uVar20 = (ulonglong)(byte)*puVar21;

LAB_140291fe7:

      uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                             [(*(uint *)(lVar7 + 8) & uVar20) >> (*(byte *)(lVar7 + 0x1c) & 0x3f)];

      uVar17 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                             [(*(uint *)(lVar7 + 0xc) & uVar20) >> (*(byte *)(lVar7 + 0x1d) & 0x3f)]

      ;

      uVar22 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                             [(*(uint *)(lVar7 + 0x10) & uVar20) >> (*(byte *)(lVar7 + 0x1e) & 0x3f)

                             ];

      uVar14 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1b)]

                             [(*(uint *)(lVar7 + 0x14) & uVar20) >> (*(byte *)(lVar7 + 0x1f) & 0x3f)

                             ];

    }

    else {

      if (bVar3 == 2) {

        uVar20 = (ulonglong)(ushort)*puVar21;

        goto LAB_140291fe7;

      }

      if (bVar3 == 3) {

        uVar14 = 0xff;

        uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar21);

        uVar17 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar21);

        uVar22 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar21);

      }

      else {

        if (bVar3 == 4) {

          uVar20 = (ulonglong)*puVar21;

          goto LAB_140291fe7;

        }

        uVar14 = 0;

        uVar18 = uVar22;

        uVar17 = uVar22;

      }

    }

    sVar9 = (short)(((uint)*(byte *)(lVar8 + 3 + uVar10 * 4) * (uint)bVar2) / 0xff);

    uVar11 = (*(byte *)(lVar8 + uVar10 * 4) - uVar18) * sVar9 + uVar18 * 0xff + 1;

    uVar11 = (uVar11 >> 8) + uVar11;

    uVar18 = uVar11 >> 8;

    uVar12 = (*(byte *)(lVar8 + 1 + uVar10 * 4) - uVar17) * sVar9 + uVar17 * 0xff + 1;

    uVar12 = (uVar12 >> 8) + uVar12;

    uVar17 = uVar12 >> 8;

    uVar13 = (*(byte *)(lVar8 + 2 + uVar10 * 4) - uVar22) * sVar9 + uVar22 * 0xff + 1;

    uVar13 = (uVar13 >> 8) + uVar13;

    uVar22 = uVar13 >> 8;

    uVar14 = (0xff - uVar14) * sVar9 + uVar14 * 0xff + 1;

    uVar14 = (ushort)((uVar14 >> 8) + uVar14) >> 8;

    if (bVar3 == 1) {

      *(char *)puVar21 =

           (char)(uVar14 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1f) & 0x1f) |

           (char)(uVar17 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1d) & 0x1f) |

           (char)(uVar22 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1e) & 0x1f) |

           (char)(uVar18 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1c) & 0x1f);

    }

    else if (bVar3 == 2) {

      *(ushort *)puVar21 =

           (uVar14 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) << (*(byte *)(lVar7 + 0x1f) & 0x1f) |

           (uVar18 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) << (*(byte *)(lVar7 + 0x1c) & 0x1f) |

           (uVar22 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) << (*(byte *)(lVar7 + 0x1e) & 0x1f) |

           (uVar17 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) << (*(byte *)(lVar7 + 0x1d) & 0x1f);

    }

    else if (bVar3 == 3) {

      *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar21) = (byte)(uVar11 >> 8)

      ;

      *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar21) = (byte)(uVar12 >> 8)

      ;

      *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar21) = (byte)(uVar13 >> 8)

      ;

    }

    else if (bVar3 == 4) {

      *puVar21 = (uint)(uVar14 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1f) & 0x1f) |

                 (uint)(uVar22 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1e) & 0x1f) |

                 (uint)(uVar17 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1d) & 0x1f) |

                 (uint)(uVar18 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1c) & 0x1f);

    }

    local_res18 = local_res18 + -1;

    pbVar19 = pbVar19 + 1;

    puVar21 = (uint *)((longlong)puVar21 + (ulonglong)bVar3);

    if (local_res18 < 1) goto LAB_1402922dd;

LAB_14029150a:

    uVar22 = 0;

    uVar10 = (ulonglong)*pbVar19;

    if (bVar3 == 1) {

      uVar20 = (ulonglong)(byte)*puVar21;

LAB_1402915a0:

      uVar22 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x18)]

                             [(*(uint *)(lVar7 + 8) & uVar20) >> (*(byte *)(lVar7 + 0x1c) & 0x3f)];

      uVar17 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x19)]

                             [(*(uint *)(lVar7 + 0xc) & uVar20) >> (*(byte *)(lVar7 + 0x1d) & 0x3f)]

      ;

      uVar18 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1a)]

                             [(*(uint *)(lVar7 + 0x10) & uVar20) >> (*(byte *)(lVar7 + 0x1e) & 0x3f)

                             ];

      uVar14 = (ushort)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(lVar7 + 0x1b)]

                             [(*(uint *)(lVar7 + 0x14) & uVar20) >> (*(byte *)(lVar7 + 0x1f) & 0x3f)

                             ];

    }

    else {

      if (bVar3 == 2) {

        uVar20 = (ulonglong)(ushort)*puVar21;

        goto LAB_1402915a0;

      }

      if (bVar3 == 3) {

        uVar14 = 0xff;

        uVar22 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar21);

        uVar17 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar21);

        uVar18 = (ushort)*(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar21);

      }

      else {

        if (bVar3 == 4) {

          uVar20 = (ulonglong)*puVar21;

          goto LAB_1402915a0;

        }

        uVar17 = 0;

        uVar14 = 0;

        uVar18 = uVar22;

      }

    }

    sVar9 = (short)(((uint)*(byte *)(lVar8 + 3 + uVar10 * 4) * (uint)bVar2) / 0xff);

    uVar11 = (*(byte *)(lVar8 + uVar10 * 4) - uVar22) * sVar9 + uVar22 * 0xff + 1;

    uVar11 = (uVar11 >> 8) + uVar11;

    uVar22 = uVar11 >> 8;

    uVar12 = (*(byte *)(lVar8 + 1 + uVar10 * 4) - uVar17) * sVar9 + uVar17 * 0xff + 1;

    uVar12 = (uVar12 >> 8) + uVar12;

    uVar17 = uVar12 >> 8;

    uVar13 = (*(byte *)(lVar8 + 2 + uVar10 * 4) - uVar18) * sVar9 + uVar18 * 0xff + 1;

    uVar13 = (uVar13 >> 8) + uVar13;

    uVar18 = uVar13 >> 8;

    uVar14 = (0xff - uVar14) * sVar9 + uVar14 * 0xff + 1;

    uVar14 = (ushort)((uVar14 >> 8) + uVar14) >> 8;

    if (bVar3 == 1) {

      *(char *)puVar21 =

           (char)(uVar14 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1f) & 0x1f) |

           (char)(uVar18 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1e) & 0x1f) |

           (char)(uVar22 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1c) & 0x1f) |

           (char)(uVar17 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

           (*(byte *)(lVar7 + 0x1d) & 0x1f);

    }

    else if (bVar3 == 2) {

      *(ushort *)puVar21 =

           (uVar14 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) << (*(byte *)(lVar7 + 0x1f) & 0x1f) |

           (uVar17 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) << (*(byte *)(lVar7 + 0x1d) & 0x1f) |

           (uVar22 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) << (*(byte *)(lVar7 + 0x1c) & 0x1f) |

           (uVar18 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) << (*(byte *)(lVar7 + 0x1e) & 0x1f);

    }

    else if (bVar3 == 3) {

      *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1c) >> 3) + (longlong)puVar21) = (byte)(uVar11 >> 8)

      ;

      *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1d) >> 3) + (longlong)puVar21) = (byte)(uVar12 >> 8)

      ;

      *(byte *)((ulonglong)(*(byte *)(lVar7 + 0x1e) >> 3) + (longlong)puVar21) = (byte)(uVar13 >> 8)

      ;

    }

    else if (bVar3 == 4) {

      *puVar21 = (uint)(uVar14 >> (8U - *(char *)(lVar7 + 0x1b) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1f) & 0x1f) |

                 (uint)(uVar18 >> (8U - *(char *)(lVar7 + 0x1a) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1e) & 0x1f) |

                 (uint)(uVar17 >> (8U - *(char *)(lVar7 + 0x19) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1d) & 0x1f) |

                 (uint)(uVar22 >> (8U - *(char *)(lVar7 + 0x18) & 0x1f)) <<

                 (*(byte *)(lVar7 + 0x1c) & 0x1f);

    }

    pbVar19 = pbVar19 + 1;

    puVar21 = (uint *)((longlong)puVar21 + (longlong)(int)(uint)bVar3);

  } while( true );

}




