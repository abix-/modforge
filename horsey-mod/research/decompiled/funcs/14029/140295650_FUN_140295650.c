// Address: 0x140295650
// Ghidra name: FUN_140295650
// ============ 0x140295650 FUN_140295650 (size=613) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140295650(longlong param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  longlong lVar5;

  longlong lVar6;

  undefined1 auVar7 [16];

  bool bVar8;

  int iVar9;

  int iVar10;

  undefined1 (*pauVar11) [32];

  undefined1 (*pauVar12) [32];

  ulonglong uVar13;

  undefined1 auVar14 [32];

  undefined1 auVar15 [32];

  undefined1 auVar16 [32];

  uint local_9c;

  uint local_98;

  byte local_94 [4];

  int local_90;

  undefined1 local_8c [100];

  

  local_90 = *(int *)(param_1 + 0x3c);

  lVar5 = *(longlong *)(param_1 + 0x48);

  iVar1 = *(int *)(param_1 + 0x38);

  pauVar11 = *(undefined1 (**) [32])(param_1 + 8);

  iVar2 = *(int *)(param_1 + 0x1c);

  pauVar12 = *(undefined1 (**) [32])(param_1 + 0x30);

  lVar6 = *(longlong *)(param_1 + 0x58);

  iVar3 = *(int *)(param_1 + 0x44);

  if ((*(int *)(lVar5 + 0x14) == 0) || (*(int *)(lVar6 + 0x14) == 0)) {

    bVar8 = true;

  }

  else {

    bVar8 = false;

  }

  FUN_14017a300(lVar5,local_8c,&local_98);

  FUN_14017a300(lVar6,&local_9c,local_94);

  auVar16._4_4_ = local_9c;

  auVar16._0_4_ = local_9c;

  auVar16._8_4_ = local_9c;

  auVar16._12_4_ = local_9c;

  auVar16._16_4_ = local_9c;

  auVar16._20_4_ = local_9c;

  auVar16._24_4_ = local_9c;

  auVar16._28_4_ = local_9c;

  auVar7 = vpshufd_avx(ZEXT416((uint)(*(byte *)(lVar5 + 0x1d) >> 3) <<

                               (*(byte *)(lVar6 + 0x1d) & 0x1f) |

                               (uint)(*(byte *)(lVar5 + 0x1e) >> 3) <<

                               (*(byte *)(lVar6 + 0x1e) & 0x1f) |

                               (uint)(*(byte *)(lVar5 + 0x1c) >> 3) <<

                               (*(byte *)(lVar6 + 0x1c) & 0x1f) |

                               (local_98 >> 3) << (local_94[0] & 0x1f)),0);

  auVar14._16_16_ = auVar7;

  auVar14._0_16_ = auVar7;

  auVar14 = vpaddd_avx2(auVar14,_DAT_140383920);

  while (local_90 != 0) {

    local_90 = local_90 + -1;

    iVar10 = 0;

    if (7 < iVar1) {

      iVar9 = 8;

      do {

        auVar15 = vpshufb_avx2(*pauVar11,auVar14);

        if (bVar8) {

          auVar15 = vpor_avx2(auVar15,auVar16);

        }

        *pauVar12 = auVar15;

        pauVar12 = pauVar12 + 1;

        pauVar11 = pauVar11 + 1;

        iVar10 = iVar10 + 8;

        iVar9 = iVar9 + 8;

      } while (iVar9 <= iVar1);

    }

    if (iVar10 < iVar1) {

      uVar13 = (ulonglong)(uint)(iVar1 - iVar10);

      if (bVar8) {

        do {

          uVar4 = *(uint *)*pauVar11;

          pauVar11 = (undefined1 (*) [32])(*pauVar11 + 4);

          *(uint *)*pauVar12 =

               (uVar4 >> (*(byte *)(lVar5 + 0x1e) & 0x1f) & 0xff) <<

               (*(byte *)(lVar6 + 0x1e) & 0x1f) |

               (uVar4 >> (*(byte *)(lVar5 + 0x1c) & 0x1f) & 0xff) <<

               (*(byte *)(lVar6 + 0x1c) & 0x1f) |

               (uVar4 >> (*(byte *)(lVar5 + 0x1d) & 0x1f) & 0xff) <<

               (*(byte *)(lVar6 + 0x1d) & 0x1f) | local_9c;

          pauVar12 = (undefined1 (*) [32])(*pauVar12 + 4);

          uVar13 = uVar13 - 1;

        } while (uVar13 != 0);

      }

      else {

        do {

          uVar4 = *(uint *)*pauVar11;

          pauVar11 = (undefined1 (*) [32])(*pauVar11 + 4);

          *(uint *)*pauVar12 =

               (uVar4 >> (*(byte *)(lVar5 + 0x1e) & 0x1f) & 0xff) <<

               (*(byte *)(lVar6 + 0x1e) & 0x1f) |

               (uVar4 >> (*(byte *)(lVar5 + 0x1c) & 0x1f) & 0xff) <<

               (*(byte *)(lVar6 + 0x1c) & 0x1f) |

               (uVar4 >> (*(byte *)(lVar5 + 0x1f) & 0x1f) & 0xff) <<

               (*(byte *)(lVar6 + 0x1f) & 0x1f) |

               (uVar4 >> (*(byte *)(lVar5 + 0x1d) & 0x1f) & 0xff) <<

               (*(byte *)(lVar6 + 0x1d) & 0x1f);

          pauVar12 = (undefined1 (*) [32])(*pauVar12 + 4);

          uVar13 = uVar13 - 1;

        } while (uVar13 != 0);

      }

    }

    pauVar11 = (undefined1 (*) [32])(*pauVar11 + iVar2);

    pauVar12 = (undefined1 (*) [32])(*pauVar12 + iVar3);

  }

  return;

}




