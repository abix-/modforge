// Address: 0x14019c230
// Ghidra name: FUN_14019c230
// ============ 0x14019c230 FUN_14019c230 (size=350) ============


int FUN_14019c230(uint param_1,byte *param_2,ulonglong param_3)



{

  undefined1 auVar1 [16];

  int iVar2;

  int iVar3;

  longlong lVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  uint uVar12;

  ulonglong uVar13;

  

  uVar7 = param_1 & 0xffff;

  auVar1._8_8_ = 0;

  auVar1._0_8_ = param_3;

  lVar4 = SUB168(ZEXT816(0x79baa6bb6398b6f7) * auVar1,8);

  param_1 = param_1 >> 0x10;

  uVar13 = param_3 + ((param_3 - lVar4 >> 1) + lVar4 >> 0xc) * -0x15b0;

  if (param_2 != (byte *)0x0) {

    while (param_3 != 0) {

      uVar6 = 0;

      if (7 < uVar13) {

        uVar12 = 7;

        do {

          uVar12 = uVar12 + 8;

          iVar8 = *param_2 + uVar7;

          iVar5 = (uint)param_2[1] + iVar8;

          iVar11 = (uint)param_2[2] + iVar5;

          iVar10 = (uint)param_2[3] + iVar11;

          iVar9 = (uint)param_2[4] + iVar10;

          iVar3 = (uint)param_2[5] + iVar9;

          iVar2 = (uint)param_2[6] + iVar3;

          uVar7 = (uint)param_2[7] + iVar2;

          uVar6 = uVar6 + 8;

          param_2 = param_2 + 8;

          param_1 = param_1 + iVar2 + iVar3 + iVar9 + iVar10 + iVar11 + iVar5 + iVar8 + uVar7;

        } while (uVar12 < uVar13);

      }

      for (; uVar6 < uVar13; uVar6 = uVar6 + 1) {

        uVar7 = uVar7 + *param_2;

        param_2 = param_2 + 1;

        param_1 = param_1 + uVar7;

      }

      uVar7 = uVar7 % 0xfff1;

      param_1 = param_1 % 0xfff1;

      param_3 = param_3 - uVar13;

      uVar13 = 0x15b0;

    }

    return uVar7 + param_1 * 0x10000;

  }

  return 1;

}




