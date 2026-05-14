// Address: 0x140299770
// Ghidra name: FUN_140299770
// ============ 0x140299770 FUN_140299770 (size=1059) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140299770(longlong param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  longlong lVar5;

  longlong lVar6;

  undefined1 auVar7 [16];

  undefined1 auVar8 [32];

  undefined1 auVar9 [32];

  undefined1 auVar10 [32];

  undefined1 auVar11 [32];

  undefined1 auVar12 [32];

  undefined1 auVar13 [32];

  undefined1 auVar14 [32];

  undefined1 auVar15 [32];

  undefined1 auVar16 [32];

  int iVar17;

  int iVar18;

  int iVar19;

  undefined1 (*pauVar20) [32];

  int iVar21;

  undefined1 (*pauVar22) [32];

  ulonglong uVar23;

  ulonglong uVar24;

  ulonglong uVar25;

  undefined1 auVar26 [32];

  undefined1 auVar27 [32];

  undefined1 auVar28 [32];

  uint local_138;

  int local_134;

  undefined1 local_120 [248];

  

  iVar17 = *(int *)(param_1 + 0x3c);

  lVar5 = *(longlong *)(param_1 + 0x58);

  iVar21 = *(int *)(param_1 + 0x38);

  pauVar22 = *(undefined1 (**) [32])(param_1 + 8);

  iVar1 = *(int *)(param_1 + 0x1c);

  pauVar20 = *(undefined1 (**) [32])(param_1 + 0x30);

  iVar2 = *(int *)(param_1 + 0x44);

  lVar6 = *(longlong *)(param_1 + 0x48);

  iVar3 = *(int *)(lVar5 + 0x14);

  local_134 = iVar21;

  FUN_14017a300(lVar5,&local_138,local_120);

  auVar28._4_4_ = local_138;

  auVar28._0_4_ = local_138;

  auVar28._8_4_ = local_138;

  auVar28._12_4_ = local_138;

  auVar28._16_4_ = local_138;

  auVar28._20_4_ = local_138;

  auVar28._24_4_ = local_138;

  auVar28._28_4_ = local_138;

  auVar7 = vpshufd_avx(ZEXT416((uint)(*(byte *)(lVar6 + 0x1e) >> 3) <<

                               (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                               (uint)(*(byte *)(lVar6 + 0x1c) >> 3) <<

                               (*(byte *)(lVar5 + 0x1c) & 0x1f) |

                               (uint)(*(byte *)(lVar6 + 0x1d) >> 3) <<

                               (*(byte *)(lVar5 + 0x1d) & 0x1f)),0);

  auVar26._16_16_ = auVar7;

  auVar26._0_16_ = auVar7;

  auVar8 = vpaddd_avx2(auVar26,_DAT_140383920);

  auVar7 = vpshufb_avx(ZEXT116(*(byte *)(lVar6 + 0x1f) >> 3),(undefined1  [16])0x0);

  auVar27._16_16_ = auVar7;

  auVar27._0_16_ = auVar7;

  auVar26 = vpaddb_avx2(auVar27,_DAT_140383920);

  auVar27 = _DAT_140383980;

  auVar14 = _DAT_1403839a0;

  auVar15 = _DAT_1403839c0;

  auVar16 = _DAT_1403839e0;

  while (iVar17 != 0) {

    iVar17 = iVar17 + -1;

    iVar19 = 0;

    _DAT_140383980 = auVar27;

    _DAT_1403839a0 = auVar14;

    _DAT_1403839c0 = auVar15;

    _DAT_1403839e0 = auVar16;

    if (7 < iVar21) {

      iVar18 = 8;

      do {

        auVar9 = vpshufb_avx2(*pauVar22,auVar26);

        auVar10 = vpshufb_avx2(*pauVar22,auVar8);

        auVar10 = vpor_avx2(auVar10,auVar28);

        auVar11 = vpsubb_avx2(*pauVar20,auVar15);

        auVar12 = vpsubb_avx2(auVar10,auVar15);

        auVar10 = vpunpckhbw_avx2(auVar9,auVar9);

        auVar13 = vpunpckhbw_avx2(auVar12,auVar11);

        auVar10 = vpmaddubsw_avx2(auVar10 ^ auVar16,auVar13);

        auVar10 = vpaddw_avx2(auVar10,auVar14);

        auVar13 = vpunpcklbw_avx2(auVar9,auVar9);

        auVar9 = vpmulhuw_avx2(auVar10,auVar27);

        auVar10 = vpunpcklbw_avx2(auVar12,auVar11);

        auVar10 = vpmaddubsw_avx2(auVar13 ^ auVar16,auVar10);

        auVar10 = vpaddw_avx2(auVar10,auVar14);

        auVar10 = vpmulhuw_avx2(auVar10,auVar27);

        auVar10 = vpackuswb_avx2(auVar10,auVar9);

        if (iVar3 == 0) {

          auVar10 = vpor_avx2(auVar10,auVar28);

        }

        *pauVar20 = auVar10;

        pauVar20 = pauVar20 + 1;

        pauVar22 = pauVar22 + 1;

        iVar19 = iVar19 + 8;

        iVar18 = iVar18 + 8;

      } while (iVar18 <= iVar21);

    }

    if (iVar19 < iVar21) {

      uVar25 = (ulonglong)(uint)(iVar21 - iVar19);

      iVar21 = local_134;

      if (iVar3 == 0) {

        do {

          uVar4 = *(uint *)*pauVar22;

          pauVar22 = (undefined1 (*) [32])(*pauVar22 + 4);

          uVar24 = (ulonglong)

                   ((uVar4 >> (*(byte *)(lVar6 + 0x1e) & 0x1f) & 0xff) <<

                    (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                    (uVar4 >> (*(byte *)(lVar6 + 0x1d) & 0x1f) & 0xff) <<

                    (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                    (uVar4 >> (*(byte *)(lVar6 + 0x1c) & 0x1f) & 0xff) <<

                    (*(byte *)(lVar5 + 0x1c) & 0x1f) | *(uint *)(lVar5 + 0x14));

          uVar23 = ((ulonglong)*(uint *)*pauVar20 << 0x18 | (ulonglong)*(uint *)*pauVar20) &

                   0xff00ff00ff00ff;

          uVar23 = (((uVar24 << 0x18 | uVar24) & 0xff00ff00ff00ff) - uVar23) *

                   ((ulonglong)(uVar4 >> (*(byte *)(lVar6 + 0x1f) & 0x3f)) & 0xff) + 0x1000100010001

                   + uVar23 * 0xff;

          uVar23 = (uVar23 >> 8 & 0xff00ff00ff00ff) + uVar23 & 0xff00ff00ff00ff00;

          *(uint *)*pauVar20 = (uint)(uVar23 >> 0x20) | (uint)(uVar23 >> 8) | local_138;

          pauVar20 = (undefined1 (*) [32])(*pauVar20 + 4);

          uVar25 = uVar25 - 1;

        } while (uVar25 != 0);

      }

      else {

        do {

          uVar4 = *(uint *)*pauVar22;

          pauVar22 = (undefined1 (*) [32])(*pauVar22 + 4);

          uVar24 = (ulonglong)

                   ((uVar4 >> (*(byte *)(lVar6 + 0x1e) & 0x1f) & 0xff) <<

                    (*(byte *)(lVar5 + 0x1e) & 0x1f) |

                    (uVar4 >> (*(byte *)(lVar6 + 0x1d) & 0x1f) & 0xff) <<

                    (*(byte *)(lVar5 + 0x1d) & 0x1f) |

                    (uVar4 >> (*(byte *)(lVar6 + 0x1c) & 0x1f) & 0xff) <<

                    (*(byte *)(lVar5 + 0x1c) & 0x1f) | *(uint *)(lVar5 + 0x14));

          uVar23 = ((ulonglong)*(uint *)*pauVar20 << 0x18 | (ulonglong)*(uint *)*pauVar20) &

                   0xff00ff00ff00ff;

          uVar23 = (((uVar24 << 0x18 | uVar24) & 0xff00ff00ff00ff) - uVar23) *

                   ((ulonglong)(uVar4 >> (*(byte *)(lVar6 + 0x1f) & 0x3f)) & 0xff) + 0x1000100010001

                   + uVar23 * 0xff;

          uVar23 = (uVar23 >> 8 & 0xff00ff00ff00ff) + uVar23 & 0xff00ff00ff00ff00;

          *(uint *)*pauVar20 = (uint)(uVar23 >> 0x20) | (uint)(uVar23 >> 8);

          pauVar20 = (undefined1 (*) [32])(*pauVar20 + 4);

          uVar25 = uVar25 - 1;

        } while (uVar25 != 0);

      }

    }

    pauVar22 = (undefined1 (*) [32])(*pauVar22 + iVar1);

    pauVar20 = (undefined1 (*) [32])(*pauVar20 + iVar2);

    auVar27 = _DAT_140383980;

    auVar14 = _DAT_1403839a0;

    auVar15 = _DAT_1403839c0;

    auVar16 = _DAT_1403839e0;

  }

  _DAT_140383980 = auVar27;

  _DAT_1403839a0 = auVar14;

  _DAT_1403839c0 = auVar15;

  _DAT_1403839e0 = auVar16;

  return;

}




