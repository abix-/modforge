// Address: 0x140063410
// Ghidra name: FUN_140063410
// ============ 0x140063410 FUN_140063410 (size=1834) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140063410(longlong param_1)



{

  int *piVar1;

  longlong lVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  longlong local_88;

  ulonglong uStack_80;

  undefined8 local_78;

  ulonglong local_70;

  

  lVar2 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);

  piVar1 = (int *)(lVar2 + 4);

  if ((*piVar1 < DAT_1403eaa18) && (FUN_1402c7138(&DAT_1403eaa18), DAT_1403eaa18 == -1)) {

    local_78 = 0xc;

    local_70 = 0xf;

    local_88._0_1_ = s_PrizePresent_140307a00[0];

    local_88._1_1_ = s_PrizePresent_140307a00[1];

    local_88._2_1_ = s_PrizePresent_140307a00[2];

    local_88._3_1_ = s_PrizePresent_140307a00[3];

    local_88._4_1_ = s_PrizePresent_140307a00[4];

    local_88._5_1_ = s_PrizePresent_140307a00[5];

    local_88._6_1_ = s_PrizePresent_140307a00[6];

    local_88._7_1_ = s_PrizePresent_140307a00[7];

    uStack_80 = (ulonglong)(uint)s_PrizePresent_140307a00._8_4_;

    _DAT_1403eaa14 = FUN_14006fe60(&local_88);

    _Init_thread_footer(&DAT_1403eaa18);

  }

  FUN_140070f90(DAT_1403d6250);

  FUN_1400d6500(param_1,DAT_1403d6260);

  fVar3 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar3 * *(float *)(param_1 + 0x110),fVar3 * *(float *)(param_1 + 0x10c)));

  FUN_1400d5ba0(param_1,3);

  if (*(int *)(param_1 + 0x254) < 4) {

    FUN_1400d5d90(param_1,1);

  }

  FUN_1400730f0();

  fVar3 = DAT_140303fd0;

  if (*(int *)(param_1 + 0x254) < 4) {

    fVar4 = (*(float *)(*(longlong *)(param_1 + 0x78) + 0x38) * DAT_14039ca34 +

            *(float *)(*(longlong *)(param_1 + 0x78) + 0x30)) * DAT_140303fd0;

    FUN_140063b50(param_1);

    FUN_140071000(fVar4 - DAT_140304004);

    FUN_14008d760(&local_88,"Entry Fee $%d");

    FUN_140086570(DAT_1403ede40);

    if (0xf < local_70) {

      if ((0xfff < local_70 + 1) && (0x1f < (local_88 - *(longlong *)(local_88 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    if ((*piVar1 < DAT_1403eaa20) && (FUN_1402c7138(&DAT_1403eaa20), DAT_1403eaa20 == -1)) {

      local_78 = 9;

      local_70 = 0xf;

      local_88._0_1_ = s_ChampRing_140307a20[0];

      local_88._1_1_ = s_ChampRing_140307a20[1];

      local_88._2_1_ = s_ChampRing_140307a20[2];

      local_88._3_1_ = s_ChampRing_140307a20[3];

      local_88._4_1_ = s_ChampRing_140307a20[4];

      local_88._5_1_ = s_ChampRing_140307a20[5];

      local_88._6_1_ = s_ChampRing_140307a20[6];

      local_88._7_1_ = s_ChampRing_140307a20[7];

      uStack_80 = (ulonglong)(byte)s_ChampRing_140307a20[8];

      DAT_1403eaa1c = FUN_14006fe60(&local_88);

      _Init_thread_footer(&DAT_1403eaa20);

    }

    fVar5 = *(float *)(*(longlong *)(param_1 + 0x78) + 0x48) * DAT_14039ca34;

    fVar4 = *(float *)(*(longlong *)(param_1 + 0x78) + 0x40);

    FUN_140071d20(DAT_1403eaa1c + -1);

    if (*(int *)(param_1 + 0x1b0) == 0) {

      FUN_140071d20(DAT_1403eaa1c);

    }

    if (*(char *)(param_1 + 0x295) != '\0') {

      FUN_140071d20(DAT_1403eaa1c + 1);

      if ((*(int *)(param_1 + 0x1c0) == 4) || (*(char *)(param_1 + 0x2b0) != '\0')) {

        FUN_140071d20(DAT_1403eaa1c + 2);

      }

      FUN_140063b50(param_1);

      if (*(char *)(param_1 + 0x2b0) == '\0') {

        FUN_140071000((fVar5 + fVar4) * fVar3 - DAT_140307a54);

        FUN_14008d760(&local_88,"Fee $%d");

        FUN_140086570(DAT_1403ede40);

        if (0xf < local_70) {

          if ((0xfff < local_70 + 1) && (0x1f < (local_88 - *(longlong *)(local_88 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

    }

    if (0.0 < *(float *)(param_1 + 0x2c8)) {

      FUN_140071000();

      FUN_140071000();

      FUN_140071000();

    }

  }

  else if (*(int *)(param_1 + 0x254) - 6U < 3) {

    if ((*(int *)(lVar2 + 4) < DAT_1403eaa28) &&

       (FUN_1402c7138(&DAT_1403eaa28), DAT_1403eaa28 == -1)) {

      local_78 = 8;

      local_70 = 0xf;

      local_88 = 0x74726143676e7544;

      uStack_80 = 0;

      DAT_1403eaa24 = FUN_14006fe60(&local_88);

      _Init_thread_footer(&DAT_1403eaa28);

    }

    FUN_140071d20(DAT_1403eaa24,*(float *)(*(longlong *)(param_1 + 0x78) + 0x40) * DAT_140303fd0,

                  *(float *)(*(longlong *)(param_1 + 0x78) + 0x44) * DAT_140303fd0);

  }

  fVar3 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar3 * *(float *)(param_1 + 0x110),fVar3 * *(float *)(param_1 + 0x10c)));

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  FUN_1400cacd0(param_1,1);

  if (*(int *)(param_1 + 0x254) == 3) {

    if (0xf < *(int *)(param_1 + 600)) {

      return;

    }

    FUN_1400c5c20(0x10);

  }

  else {

    if ((*(int *)(param_1 + 0x254) - 1U & 0xfffffffb) != 0) {

      return;

    }

    if (0xf < *(int *)(param_1 + 600)) {

      return;

    }

  }

  FUN_140071000();

  return;

}




