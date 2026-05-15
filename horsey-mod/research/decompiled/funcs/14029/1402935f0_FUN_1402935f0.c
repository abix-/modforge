// Address: 0x1402935f0
// Ghidra name: FUN_1402935f0
// ============ 0x1402935f0 FUN_1402935f0 (size=1176) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402935f0(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  ushort uVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  longlong lVar7;

  int iVar8;

  byte bVar9;

  uint uVar10;

  undefined1 (*pauVar11) [16];

  int iVar12;

  undefined1 (*pauVar13) [16];

  undefined1 auVar14 [16];

  undefined1 auVar15 [16];

  undefined1 auVar16 [16];

  undefined1 auVar24 [16];

  undefined1 auVar25 [16];

  undefined1 auVar26 [16];

  undefined1 auVar27 [16];

  undefined1 auVar28 [16];

  undefined1 auVar29 [16];

  uint local_res8 [2];

  byte local_res10 [8];

  uint local_res18;

  undefined1 auVar17 [16];

  undefined1 auVar18 [16];

  undefined1 auVar19 [16];

  undefined1 auVar20 [16];

  undefined1 auVar21 [16];

  undefined1 auVar22 [16];

  undefined1 auVar23 [16];

  

  iVar4 = *(int *)(param_1 + 0x1c);

  uVar5 = *(uint *)(param_1 + 0x38);

  iVar12 = *(int *)(param_1 + 0x3c);

  pauVar13 = *(undefined1 (**) [16])(param_1 + 8);

  pauVar11 = *(undefined1 (**) [16])(param_1 + 0x30);

  iVar6 = *(int *)(param_1 + 0x44);

  lVar7 = *(longlong *)(param_1 + 0x58);

  bVar1 = *(byte *)(lVar7 + 0x1c);

  bVar2 = *(byte *)(lVar7 + 0x1d);

  local_res18 = (uint)*(byte *)(lVar7 + 0x1e);

  FUN_14017a300(0xff00ff00,local_res8,local_res10);

  uVar10 = 3 << (local_res10[0] & 0x1f) | 2 << (bVar1 & 0x1f) | 1 << (bVar2 & 0x1f);

  auVar29._0_4_ = uVar10 + _DAT_140383910;

  auVar29._4_4_ = uVar10 + _UNK_140383914;

  auVar29._8_4_ = uVar10 + _UNK_140383918;

  auVar29._12_4_ = uVar10 + _UNK_14038391c;

  if (iVar12 != 0) {

    do {

      iVar12 = iVar12 + -1;

      for (iVar8 = (int)(uVar5 + ((int)uVar5 >> 0x1f & 7U)) >> 3; iVar8 != 0; iVar8 = iVar8 + -1) {

        auVar15 = *pauVar13;

        pauVar13 = pauVar13 + 1;

        auVar26._0_8_ = auVar15._0_8_ & 0xf800f800f800f800;

        auVar26._8_4_ = auVar15._8_4_ & 0xf800f800;

        auVar26._12_4_ = auVar15._12_4_ & 0xf800f800;

        auVar14 = psllw(auVar15,0xb);

        auVar25._8_4_ = 0x1080108;

        auVar25._0_8_ = 0x108010801080108;

        auVar25._12_4_ = 0x1080108;

        auVar27 = pmulhuw(auVar26,auVar25);

        auVar24._0_8_ = auVar15._0_8_ & 0x7e007e007e007e0;

        auVar24._8_4_ = auVar15._8_4_ & 0x7e007e0;

        auVar24._12_4_ = auVar15._12_4_ & 0x7e007e0;

        auVar15._8_4_ = 0x1080108;

        auVar15._0_8_ = 0x108010801080108;

        auVar15._12_4_ = 0x1080108;

        auVar15 = pmulhuw(auVar14,auVar15);

        auVar14._8_4_ = 0x20802080;

        auVar14._0_8_ = 0x2080208020802080;

        auVar14._12_4_ = 0x20802080;

        auVar25 = pmulhuw(auVar24,auVar14);

        auVar14 = psllw(auVar27,8);

        auVar14 = auVar14 | auVar15;

        auVar27._8_4_ = 0xff00ff00;

        auVar27._0_8_ = 0xff00ff00ff00ff00;

        auVar27._12_4_ = 0xff00ff00;

        auVar25 = auVar25 | auVar27;

        auVar23._0_14_ = auVar14._0_14_;

        auVar23[0xe] = auVar14[7];

        auVar23[0xf] = auVar25[7];

        auVar22._14_2_ = auVar23._14_2_;

        auVar22._0_13_ = auVar14._0_13_;

        auVar22[0xd] = auVar25[6];

        auVar21._13_3_ = auVar22._13_3_;

        auVar21._0_12_ = auVar14._0_12_;

        auVar21[0xc] = auVar14[6];

        auVar20._12_4_ = auVar21._12_4_;

        auVar20._0_11_ = auVar14._0_11_;

        auVar20[0xb] = auVar25[5];

        auVar19._11_5_ = auVar20._11_5_;

        auVar19._0_10_ = auVar14._0_10_;

        auVar19[10] = auVar14[5];

        auVar18._10_6_ = auVar19._10_6_;

        auVar18._0_9_ = auVar14._0_9_;

        auVar18[9] = auVar25[4];

        auVar17._9_7_ = auVar18._9_7_;

        auVar17._0_8_ = auVar14._0_8_;

        auVar17[8] = auVar14[4];

        auVar16._8_8_ = auVar17._8_8_;

        auVar16[7] = auVar25[3];

        auVar16[6] = auVar14[3];

        auVar16[5] = auVar25[2];

        auVar16[4] = auVar14[2];

        auVar16[3] = auVar25[1];

        auVar16[2] = auVar14[1];

        auVar16[0] = auVar14[0];

        auVar16[1] = auVar25[0];

        auVar28[1] = auVar25[8];

        auVar28[0] = auVar14[8];

        auVar28[2] = auVar14[9];

        auVar28[3] = auVar25[9];

        auVar28[4] = auVar14[10];

        auVar28[5] = auVar25[10];

        auVar28[6] = auVar14[0xb];

        auVar28[7] = auVar25[0xb];

        auVar28[8] = auVar14[0xc];

        auVar28[9] = auVar25[0xc];

        auVar28[10] = auVar14[0xd];

        auVar28[0xb] = auVar25[0xd];

        auVar28[0xc] = auVar14[0xe];

        auVar28[0xd] = auVar25[0xe];

        auVar28[0xe] = auVar14[0xf];

        auVar28[0xf] = auVar25[0xf];

        auVar15 = pshufb(auVar16,auVar29);

        auVar25 = pshufb(auVar28,auVar29);

        *pauVar11 = auVar15;

        pauVar11[1] = auVar25;

        pauVar11 = pauVar11 + 2;

      }

      bVar9 = (byte)local_res18;

      switch(uVar5 & 7) {

      case 7:

        uVar3 = *(ushort *)*pauVar13;

        *(uint *)*pauVar11 =

             (uint)(byte)PTR_DAT_1403e28d0[uVar3 >> 5 & 0x3f] << (bVar2 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 >> 0xb] << (bVar1 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 & 0x1f] << (bVar9 & 0x1f) | local_res8[0];

        pauVar11 = (undefined1 (*) [16])(*pauVar11 + 4);

        pauVar13 = (undefined1 (*) [16])(*pauVar13 + 2);

      case 6:

        uVar3 = *(ushort *)*pauVar13;

        *(uint *)*pauVar11 =

             (uint)(byte)PTR_DAT_1403e28d0[uVar3 >> 5 & 0x3f] << (bVar2 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 >> 0xb] << (bVar1 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 & 0x1f] << (bVar9 & 0x1f) | local_res8[0];

        pauVar11 = (undefined1 (*) [16])(*pauVar11 + 4);

        pauVar13 = (undefined1 (*) [16])(*pauVar13 + 2);

      case 5:

        uVar3 = *(ushort *)*pauVar13;

        *(uint *)*pauVar11 =

             (uint)(byte)PTR_DAT_1403e28d0[uVar3 >> 5 & 0x3f] << (bVar2 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 >> 0xb] << (bVar1 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 & 0x1f] << (bVar9 & 0x1f) | local_res8[0];

        pauVar11 = (undefined1 (*) [16])(*pauVar11 + 4);

        pauVar13 = (undefined1 (*) [16])(*pauVar13 + 2);

      case 4:

        uVar3 = *(ushort *)*pauVar13;

        *(uint *)*pauVar11 =

             (uint)(byte)PTR_DAT_1403e28d0[uVar3 >> 5 & 0x3f] << (bVar2 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 >> 0xb] << (bVar1 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 & 0x1f] << (bVar9 & 0x1f) | local_res8[0];

        pauVar11 = (undefined1 (*) [16])(*pauVar11 + 4);

        pauVar13 = (undefined1 (*) [16])(*pauVar13 + 2);

      case 3:

        uVar3 = *(ushort *)*pauVar13;

        *(uint *)*pauVar11 =

             (uint)(byte)PTR_DAT_1403e28d0[uVar3 >> 5 & 0x3f] << (bVar2 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 >> 0xb] << (bVar1 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 & 0x1f] << (bVar9 & 0x1f) | local_res8[0];

        pauVar11 = (undefined1 (*) [16])(*pauVar11 + 4);

        pauVar13 = (undefined1 (*) [16])(*pauVar13 + 2);

      case 2:

        uVar3 = *(ushort *)*pauVar13;

        *(uint *)*pauVar11 =

             (uint)(byte)PTR_DAT_1403e28d0[uVar3 >> 5 & 0x3f] << (bVar2 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 >> 0xb] << (bVar1 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 & 0x1f] << (bVar9 & 0x1f) | local_res8[0];

        pauVar11 = (undefined1 (*) [16])(*pauVar11 + 4);

        pauVar13 = (undefined1 (*) [16])(*pauVar13 + 2);

      case 1:

        uVar3 = *(ushort *)*pauVar13;

        *(uint *)*pauVar11 =

             (uint)(byte)PTR_DAT_1403e28d0[uVar3 >> 5 & 0x3f] << (bVar2 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 >> 0xb] << (bVar1 & 0x1f) |

             (uint)(byte)PTR_DAT_1403e28c8[uVar3 & 0x1f] << (bVar9 & 0x1f) | local_res8[0];

        pauVar11 = (undefined1 (*) [16])(*pauVar11 + 4);

        pauVar13 = (undefined1 (*) [16])(*pauVar13 + 2);

      }

      pauVar13 = (undefined1 (*) [16])(*pauVar13 + (longlong)(iVar4 / 2) * 2);

      pauVar11 = (undefined1 (*) [16])

                 (*pauVar11 + (longlong)((int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2) * 4);

    } while (iVar12 != 0);

  }

  return;

}




