// Address: 0x1400fc520
// Ghidra name: FUN_1400fc520
// ============ 0x1400fc520 FUN_1400fc520 (size=2096) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400fc520(longlong param_1)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  bool bVar4;

  bool bVar5;

  uint uVar6;

  uint uVar7;

  int iVar8;

  uint uVar9;

  float local_res18;

  float local_res1c;

  float local_res20;

  float local_res24;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  ulonglong uStack_80;

  

  uVar9 = (int)((*(int *)(param_1 + 0x74) >> 0x1f & 3U) + *(int *)(param_1 + 0x74)) >> 2 &

          0x80000001;

  if ((int)uVar9 < 0) {

    uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;

  }

  iVar8 = 0;

  if (*(char *)(param_1 + 0xad) != '\0') {

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4

                 ) < DAT_1403f4ec4) && (FUN_1402c7138(&DAT_1403f4ec4), DAT_1403f4ec4 == -1)) {

      local_88 = 0xd;

      uStack_80 = 0xf;

      local_98._0_1_ = s_BalloonShadow_1403131d8[0];

      local_98._1_1_ = s_BalloonShadow_1403131d8[1];

      local_98._2_1_ = s_BalloonShadow_1403131d8[2];

      local_98._3_1_ = s_BalloonShadow_1403131d8[3];

      local_98._4_1_ = s_BalloonShadow_1403131d8[4];

      local_98._5_1_ = s_BalloonShadow_1403131d8[5];

      local_98._6_1_ = s_BalloonShadow_1403131d8[6];

      local_98._7_1_ = s_BalloonShadow_1403131d8[7];

      uStack_90 = (ulonglong)

                  CONCAT14(s_BalloonShadow_1403131d8[0xc],s_BalloonShadow_1403131d8._8_4_);

      DAT_1403f4ec0 = FUN_14006fe60(&local_98);

      _Init_thread_footer(&DAT_1403f4ec4);

    }

    FUN_140072750(0x60);

    FUN_140071d20(DAT_1403f4ec0);

    FUN_1400727d0();

    return;

  }

  iVar3 = *(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +

                  4);

  if (*(char *)(param_1 + 0xac) != '\0') {

    if ((iVar3 < DAT_1403f4ecc) && (FUN_1402c7138(&DAT_1403f4ecc), DAT_1403f4ecc == -1)) {

      uStack_90 = 0;

      local_88 = 4;

      uStack_80 = 0xf;

      local_98 = 0x39736143;

      DAT_1403f4ec8 = FUN_14006fe60(&local_98);

      _Init_thread_footer(&DAT_1403f4ecc);

    }

    if (7 < (int)*(uint *)(param_1 + 0x78)) {

      uVar6 = *(uint *)(param_1 + 0x78) & 0x8000000f;

      if ((int)uVar6 < 0) {

        uVar6 = (uVar6 - 1 | 0xfffffff0) + 1;

      }

      if ((int)uVar6 < 8) {

        iVar8 = -1;

      }

    }

    FUN_140071ed0(DAT_1403f4ec8 + iVar8);

    FUN_140071ed0(DAT_1403f4ec8 + uVar9 + 1);

    FUN_140071ed0(DAT_1403f4ec8 + 5);

    return;

  }

  if ((iVar3 < DAT_1403f4ed4) && (FUN_1402c7138(&DAT_1403f4ed4), DAT_1403f4ed4 == -1)) {

    uStack_90 = 0;

    local_88 = 5;

    uStack_80 = 0xf;

    local_98._0_5_ = CONCAT14(s_Truck_1403131e8[4],s_Truck_1403131e8._0_4_);

    local_98 = (ulonglong)(uint5)local_98;

    DAT_1403f4ed0 = FUN_14006fe60(&local_98);

    _Init_thread_footer(&DAT_1403f4ed4);

  }

  iVar8 = *(int *)(param_1 + 0xa0);

  bVar4 = 0 < iVar8;

  if (1 < iVar8) {

    *(int *)(param_1 + 0xa0) = iVar8 + -1;

    if (iVar8 + -1 == 1) {

      *(uint *)(DAT_1403fb0d8 + 0x268) = (0 < *(int *)(param_1 + 0xa4)) + 1;

    }

    if (*(int *)(param_1 + 0xa0) == 0x5a) {

      local_88 = _DAT_1403040a0;

      uStack_80 = _UNK_1403040a8;

      local_98._0_1_ = s_StripesOn_1403131f0[0];

      local_98._1_1_ = s_StripesOn_1403131f0[1];

      local_98._2_1_ = s_StripesOn_1403131f0[2];

      local_98._3_1_ = s_StripesOn_1403131f0[3];

      local_98._4_1_ = s_StripesOn_1403131f0[4];

      local_98._5_1_ = s_StripesOn_1403131f0[5];

      local_98._6_1_ = s_StripesOn_1403131f0[6];

      local_98._7_1_ = s_StripesOn_1403131f0[7];

      uStack_90 = (ulonglong)(byte)s_StripesOn_1403131f0[8];

      FUN_140040ca0(&local_98,100);

      if (0xf < uStack_80) {

        if ((0xfff < uStack_80 + 1) && (0x1f < (local_98 - *(longlong *)(local_98 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    uVar6 = *(uint *)(param_1 + 0xa0);

    if ((int)uVar6 < 0x1e) {

LAB_1400fc8c5:

      bVar4 = true;

    }

    else {

      if ((int)uVar6 < 0x5a) {

        uVar6 = uVar6 & 0x80000007;

        if ((int)uVar6 < 0) {

          uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;

        }

        if (3 < (int)uVar6) goto LAB_1400fc8c5;

      }

      bVar4 = false;

    }

  }

  piVar1 = (int *)(param_1 + 0xa4);

  iVar8 = *piVar1;

  if (1 < iVar8) {

    *piVar1 = iVar8 + -1;

    if (iVar8 + -1 == 1) {

      *(undefined4 *)(DAT_1403fb0d8 + 0x268) = 2;

    }

    if (*piVar1 == 0x5a) {

      uStack_90 = 0;

      local_88 = _DAT_1403033d0;

      uStack_80 = _UNK_1403033d8;

      local_98 = (ulonglong)CONCAT24(s_LiftOn_1403131fc._4_2_,s_LiftOn_1403131fc._0_4_);

      FUN_140040ca0(&local_98,100);

      if (0xf < uStack_80) {

        if ((0xfff < uStack_80 + 1) && (0x1f < (local_98 - *(longlong *)(local_98 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    iVar8 = *(int *)(param_1 + 0xa4);

  }

  puVar2 = (uint *)(param_1 + 0xa8);

  uVar6 = *puVar2;

  bVar5 = 0 < (int)uVar6;

  if ((int)uVar6 < 2) goto LAB_1400fcae4;

  *puVar2 = uVar6 - 1;

  if (uVar6 - 1 == 1) {

    *(uint *)(DAT_1403fb0d8 + 0x268) = (0 < iVar8) + 1;

  }

  if (*puVar2 == 0x5a) {

    uStack_90 = 0;

    local_88 = _DAT_140304080;

    uStack_80 = _UNK_140304088;

    local_98._0_5_ = CONCAT14(s_RamOn_140313204[4],s_RamOn_140313204._0_4_);

    local_98 = (ulonglong)(uint5)local_98;

    FUN_140040ca0(&local_98,100);

    if (0xf < uStack_80) {

      if ((0xfff < uStack_80 + 1) && (0x1f < (local_98 - *(longlong *)(local_98 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  uVar6 = *(uint *)(param_1 + 0xa8);

  if ((int)uVar6 < 0x1e) {

LAB_1400fcad3:

    bVar5 = true;

  }

  else {

    if ((int)uVar6 < 0x5a) {

      uVar7 = uVar6 & 0x8000000f;

      if ((int)uVar7 < 0) {

        uVar7 = (uVar7 - 1 | 0xfffffff0) + 1;

      }

      if (7 < (int)uVar7) goto LAB_1400fcad3;

    }

    bVar5 = false;

  }

LAB_1400fcae4:

  if (*(int *)(param_1 + 0xa4) == 2) {

    *(undefined4 *)(DAT_1403fb0d8 + 0x268) = 2;

  }

  else if ((*(int *)(param_1 + 0xa0) == 2) || (uVar6 == 2)) {

    *(undefined4 *)(DAT_1403fb0d8 + 0x268) = 1;

  }

  if (*(char *)(param_1 + 0x9c) != '\0') {

    if (*(int *)(param_1 + 0x94) == 0) {

      local_res18 = *(float *)(param_1 + 0x28) - (float)(*(int *)(param_1 + 0x38) * 0x13);

      local_res1c = *(float *)(param_1 + 0x2c) + DAT_14030339c;

      local_res20 = *(float *)(param_1 + 0x28) - (float)(*(int *)(param_1 + 0x38) << 4);

      local_res24 = *(float *)(param_1 + 0x2c) + DAT_140303390;

      FUN_140071990(&local_res20,&local_res18,DAT_14039ca34,&DAT_1403dc168);

    }

    *(undefined1 *)(param_1 + 0x9c) = 0;

  }

  FUN_140071f00(DAT_1403f4ed0);

  if (bVar4) {

    FUN_140071f00(DAT_1403f4ed0 + 3);

  }

  if (bVar5) {

    FUN_140071f00(DAT_1403f4ed0 + 4);

  }

  FUN_140071f00(DAT_1403f4ed0 + uVar9 + 1);

  return;

}




