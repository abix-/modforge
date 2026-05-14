// Address: 0x1402958c0
// Ghidra name: FUN_1402958c0
// ============ 0x1402958c0 FUN_1402958c0 (size=545) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402958c0(longlong param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  bool bVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  undefined1 (*pauVar10) [16];

  undefined1 (*pauVar11) [16];

  ulonglong uVar12;

  undefined1 auVar13 [16];

  undefined1 auVar14 [16];

  undefined1 auVar15 [16];

  uint local_res8 [2];

  uint local_res10 [2];

  byte local_res18 [8];

  int local_res20;

  undefined1 local_58 [24];

  

  lVar4 = *(longlong *)(param_1 + 0x48);

  local_res20 = *(int *)(param_1 + 0x3c);

  iVar1 = *(int *)(param_1 + 0x38);

  pauVar10 = *(undefined1 (**) [16])(param_1 + 8);

  iVar2 = *(int *)(param_1 + 0x1c);

  pauVar11 = *(undefined1 (**) [16])(param_1 + 0x30);

  iVar3 = *(int *)(param_1 + 0x44);

  lVar5 = *(longlong *)(param_1 + 0x58);

  if ((*(int *)(lVar4 + 0x14) == 0) || (*(int *)(lVar5 + 0x14) == 0)) {

    bVar6 = true;

  }

  else {

    bVar6 = false;

  }

  FUN_14017a300(lVar4,local_58,local_res10);

  FUN_14017a300(lVar5,local_res8,local_res18);

  uVar9 = (uint)(*(byte *)(lVar4 + 0x1e) >> 3) << (*(byte *)(lVar5 + 0x1e) & 0x1f) |

          (uint)(*(byte *)(lVar4 + 0x1c) >> 3) << (*(byte *)(lVar5 + 0x1c) & 0x1f) |

          (uint)(*(byte *)(lVar4 + 0x1d) >> 3) << (*(byte *)(lVar5 + 0x1d) & 0x1f) |

          (local_res10[0] >> 3) << (local_res18[0] & 0x1f);

  auVar15._4_4_ = local_res8[0];

  auVar15._0_4_ = local_res8[0];

  auVar15._8_4_ = local_res8[0];

  auVar15._12_4_ = local_res8[0];

  auVar14._0_4_ = uVar9 + _DAT_140383910;

  auVar14._4_4_ = uVar9 + _UNK_140383914;

  auVar14._8_4_ = uVar9 + _UNK_140383918;

  auVar14._12_4_ = uVar9 + _UNK_14038391c;

  while (local_res20 != 0) {

    local_res20 = local_res20 + -1;

    iVar8 = 0;

    if (3 < iVar1) {

      iVar7 = 4;

      do {

        auVar13 = pshufb(*pauVar10,auVar14);

        if (bVar6) {

          auVar13 = auVar13 | auVar15;

        }

        *pauVar11 = auVar13;

        pauVar11 = pauVar11 + 1;

        pauVar10 = pauVar10 + 1;

        iVar8 = iVar8 + 4;

        iVar7 = iVar7 + 4;

      } while (iVar7 <= iVar1);

    }

    if (iVar8 < iVar1) {

      uVar12 = (ulonglong)(uint)(iVar1 - iVar8);

      if (bVar6) {

        do {

          uVar9 = *(uint *)*pauVar10;

          pauVar10 = (undefined1 (*) [16])(*pauVar10 + 4);

          *(uint *)*pauVar11 =

               (uVar9 >> (*(byte *)(lVar4 + 0x1e) & 0x1f) & 0xff) <<

               (*(byte *)(lVar5 + 0x1e) & 0x1f) |

               (uVar9 >> (*(byte *)(lVar4 + 0x1c) & 0x1f) & 0xff) <<

               (*(byte *)(lVar5 + 0x1c) & 0x1f) |

               (uVar9 >> (*(byte *)(lVar4 + 0x1d) & 0x1f) & 0xff) <<

               (*(byte *)(lVar5 + 0x1d) & 0x1f) | local_res8[0];

          pauVar11 = (undefined1 (*) [16])(*pauVar11 + 4);

          uVar12 = uVar12 - 1;

        } while (uVar12 != 0);

      }

      else {

        do {

          uVar9 = *(uint *)*pauVar10;

          pauVar10 = (undefined1 (*) [16])(*pauVar10 + 4);

          *(uint *)*pauVar11 =

               (uVar9 >> (*(byte *)(lVar4 + 0x1e) & 0x1f) & 0xff) <<

               (*(byte *)(lVar5 + 0x1e) & 0x1f) |

               (uVar9 >> (*(byte *)(lVar4 + 0x1c) & 0x1f) & 0xff) <<

               (*(byte *)(lVar5 + 0x1c) & 0x1f) |

               (uVar9 >> (*(byte *)(lVar4 + 0x1f) & 0x1f) & 0xff) <<

               (*(byte *)(lVar5 + 0x1f) & 0x1f) |

               (uVar9 >> (*(byte *)(lVar4 + 0x1d) & 0x1f) & 0xff) <<

               (*(byte *)(lVar5 + 0x1d) & 0x1f);

          pauVar11 = (undefined1 (*) [16])(*pauVar11 + 4);

          uVar12 = uVar12 - 1;

        } while (uVar12 != 0);

      }

    }

    pauVar10 = (undefined1 (*) [16])(*pauVar10 + iVar2);

    pauVar11 = (undefined1 (*) [16])(*pauVar11 + iVar3);

  }

  return;

}




