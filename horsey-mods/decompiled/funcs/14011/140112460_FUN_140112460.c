// Address: 0x140112460
// Ghidra name: FUN_140112460
// ============ 0x140112460 FUN_140112460 (size=1690) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140112460(longlong param_1)



{

  longlong *plVar1;

  char *pcVar2;

  bool bVar3;

  bool bVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  undefined8 uVar8;

  undefined4 uVar9;

  undefined4 uVar10;

  undefined4 uVar11;

  ulonglong uVar12;

  int iVar13;

  undefined4 uVar14;

  longlong lVar15;

  char **ppcVar16;

  size_t sVar17;

  longlong lVar18;

  int iVar19;

  float local_res10;

  float local_res14;

  longlong local_res18;

  longlong local_res20;

  undefined8 in_stack_fffffffffffffe18;

  char *local_1d8;

  undefined8 uStack_1d0;

  undefined8 local_1c8;

  ulonglong uStack_1c0;

  longlong local_1b8 [4];

  char *local_198 [4];

  char *local_178;

  char *local_170;

  char *local_168;

  undefined *local_160;

  undefined4 *local_158;

  undefined4 *local_150;

  undefined *local_148;

  char *local_140;

  char *local_138;

  undefined4 *local_130;

  char *local_128;

  char *local_120;

  char *local_118;

  char *local_110;

  char *local_108;

  char *local_100;

  char *local_f8;

  char *local_f0;

  char *local_e8;

  undefined *local_e0;

  undefined4 *local_d8;

  longlong local_c8;

  longlong local_c0 [3];

  ulonglong local_a8;

  

  bVar4 = false;

  bVar3 = false;

  plVar1 = (longlong *)(param_1 + 0x130);

  lVar15 = *(longlong *)(param_1 + 0x138) - *plVar1;

  while (lVar15 >> 3 != 0) {

    FUN_1400cf7f0(param_1,0);

    lVar15 = *(longlong *)(param_1 + 0x138) - *plVar1;

  }

  FUN_1400d01d0(param_1,"Zookeeper",0,DAT_1403d9e74);

  uVar12 = _UNK_14039caa8;

  uVar8 = _DAT_14039caa0;

  fVar7 = DAT_140303fd0;

  fVar6 = DAT_14030374c;

  fVar5 = DAT_140303384;

  local_198[0] = "tiger";

  local_198[1] = "giraffe";

  local_198[2] = "moose";

  local_198[3] = "alligator";

  local_178 = "centipede";

  local_170 = "rabbit";

  local_168 = "impala";

  local_160 = &DAT_14030696c;

  local_158 = &DAT_140306984;

  local_150 = &DAT_140303b54;

  local_148 = &DAT_14030e7fc;

  local_140 = "leprechaun";

  local_138 = "dachshund";

  local_130 = &DAT_1403065f4;

  local_128 = "pepper";

  local_120 = "yeast";

  local_118 = "tiger";

  local_110 = "giraffe";

  local_108 = "moose";

  local_100 = "alligator";

  local_f8 = "centipede";

  local_f0 = "rabbit";

  local_e8 = "impala";

  local_e0 = &DAT_14030696c;

  local_d8 = &DAT_140306984;

  local_res20 = 0x10;

  if (DAT_1403d959a != '\0') {

    local_res20 = 9;

  }

  iVar19 = 0;

  lVar15 = 0;

  iVar13 = (int)local_res20;

  do {

    uVar14 = (undefined4)((ulonglong)in_stack_fffffffffffffe18 >> 0x20);

    ppcVar16 = &local_118;

    if (DAT_1403d959a == '\0') {

      ppcVar16 = local_198;

    }

    pcVar2 = ppcVar16[lVar15];

    local_1b8[0] = 0;

    local_1b8[1] = 0;

    local_1b8[2] = 0;

    local_1b8[3] = 0;

    sVar17 = strlen(pcVar2);

    FUN_140027e30(local_1b8,pcVar2,sVar17);

    local_c8 = FUN_1402c704c(0x498);

    if (local_c8 == 0) {

      lVar18 = 0;

    }

    else {

      lVar18 = FUN_1400aac60(local_c8);

    }

    local_res18 = lVar18;

    FUN_1400b2ee0(lVar18,local_1b8,0,0xffffffff);

    local_res10 = ((float)iVar19 * fVar7) / (float)(iVar13 + -1) + fVar6;

    local_res14 = (float)(iVar19 + (iVar19 / 3 + (iVar19 >> 0x1f) +

                                   (int)(((longlong)iVar19 / 3 + ((longlong)iVar19 >> 0x3f) &

                                         0xffffffffU) >> 0x1f)) * -3) * fVar5 + fVar6;

    FUN_1400b6610(lVar18,&local_res10);

    *(undefined4 *)(lVar18 + 0x1fc) = 1;

    in_stack_fffffffffffffe18 = CONCAT44(uVar14,0xffffffff);

    uVar14 = FUN_1400c7600(0,7,0xffffffff,0xffffffff,in_stack_fffffffffffffe18);

    *(undefined4 *)(lVar18 + 0x1f8) = uVar14;

    if (DAT_1403d959a == '\0') {

      pcVar2 = local_198[lVar15];

      local_1d8 = (char *)0x0;

      uStack_1d0 = 0;

      local_1c8 = 0;

      uStack_1c0 = 0;

      sVar17 = strlen(pcVar2);

      FUN_140027e30(&local_1d8,pcVar2,sVar17);

      bVar3 = true;

    }

    else {

      FUN_14008d760(local_c0,"Horse%d",iVar19);

      bVar4 = true;

    }

    FUN_1400cf950(param_1,lVar18);

    if (bVar3) {

      bVar3 = false;

      if (0xf < uStack_1c0) {

        if ((0xfff < uStack_1c0 + 1) &&

           ((char *)0x1f < local_1d8 + (-8 - *(longlong *)(local_1d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      local_1c8 = uVar8;

      uStack_1c0 = uVar12;

      local_1d8 = (char *)((ulonglong)local_1d8 & 0xffffffffffffff00);

    }

    if ((bVar4) && (bVar4 = false, 0xf < local_a8)) {

      if ((0xfff < local_a8 + 1) && (0x1f < (local_c0[0] - *(longlong *)(local_c0[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    if (*(longlong **)(param_1 + 0x138) == *(longlong **)(param_1 + 0x140)) {

      FUN_140030680(plVar1);

    }

    else {

      **(longlong **)(param_1 + 0x138) = lVar18;

      *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

    }

    if (0xf < (ulonglong)local_1b8[3]) {

      if ((0xfff < local_1b8[3] + 1U) &&

         (0x1f < (local_1b8[0] - *(longlong *)(local_1b8[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    uVar14 = (undefined4)((ulonglong)in_stack_fffffffffffffe18 >> 0x20);

    iVar19 = iVar19 + 1;

    lVar15 = lVar15 + 1;

  } while (lVar15 < local_res20);

  FUN_1400d0a00(param_1,0);

  FUN_1400cd5a0(param_1,1);

  FUN_1400ce540(param_1,0,0);

  local_1d8 = (char *)0x0;

  uStack_1d0 = 0;

  local_1c8 = 0;

  uStack_1c0 = 0;

  if (DAT_1403d959a == '\0') {

    local_1d8 = (char *)FUN_1400285e0(0x40);

    uVar8 = s_Hover_over_a_horse_and_press_W_t_140313cf8._8_8_;

    local_1c8 = _DAT_1403041b0;

    uStack_1c0 = _UNK_1403041b8;

    *(undefined8 *)local_1d8 = s_Hover_over_a_horse_and_press_W_t_140313cf8._0_8_;

    *(undefined8 *)(local_1d8 + 8) = uVar8;

    uVar11 = s_Hover_over_a_horse_and_press_W_t_140313cf8._28_4_;

    uVar10 = s_Hover_over_a_horse_and_press_W_t_140313cf8._24_4_;

    uVar9 = s_Hover_over_a_horse_and_press_W_t_140313cf8._20_4_;

    *(undefined4 *)(local_1d8 + 0x10) = s_Hover_over_a_horse_and_press_W_t_140313cf8._16_4_;

    *(undefined4 *)(local_1d8 + 0x14) = uVar9;

    *(undefined4 *)(local_1d8 + 0x18) = uVar10;

    *(undefined4 *)(local_1d8 + 0x1c) = uVar11;

    uVar8 = s_Hover_over_a_horse_and_press_W_t_140313cf8._40_8_;

    *(undefined8 *)(local_1d8 + 0x20) = s_Hover_over_a_horse_and_press_W_t_140313cf8._32_8_;

    *(undefined8 *)(local_1d8 + 0x28) = uVar8;

    local_1d8[0x30] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_1d8,0,

                  CONCAT44(uVar14,DAT_140303758));

    if (uStack_1c0 < 0x10) {

      return 1;

    }

    if ((0xfff < uStack_1c0 + 1) &&

       ((char *)0x1f < local_1d8 + (-8 - *(longlong *)(local_1d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else {

    local_1d8 = (char *)FUN_1400285e0(0x40);

    uVar8 = s_Special_Zoo_access_is_for_Vancou_140313cc0._8_8_;

    local_1c8 = _DAT_1403041c0;

    uStack_1c0 = _UNK_1403041c8;

    *(undefined8 *)local_1d8 = s_Special_Zoo_access_is_for_Vancou_140313cc0._0_8_;

    *(undefined8 *)(local_1d8 + 8) = uVar8;

    uVar11 = s_Special_Zoo_access_is_for_Vancou_140313cc0._28_4_;

    uVar10 = s_Special_Zoo_access_is_for_Vancou_140313cc0._24_4_;

    uVar9 = s_Special_Zoo_access_is_for_Vancou_140313cc0._20_4_;

    *(undefined4 *)(local_1d8 + 0x10) = s_Special_Zoo_access_is_for_Vancou_140313cc0._16_4_;

    *(undefined4 *)(local_1d8 + 0x14) = uVar9;

    *(undefined4 *)(local_1d8 + 0x18) = uVar10;

    *(undefined4 *)(local_1d8 + 0x1c) = uVar11;

    uVar8 = s_Special_Zoo_access_is_for_Vancou_140313cc0._40_8_;

    *(undefined8 *)(local_1d8 + 0x20) = s_Special_Zoo_access_is_for_Vancou_140313cc0._32_8_;

    *(undefined8 *)(local_1d8 + 0x28) = uVar8;

    *(undefined4 *)(local_1d8 + 0x30) = s_Special_Zoo_access_is_for_Vancou_140313cc0._48_4_;

    local_1d8[0x34] = s_Special_Zoo_access_is_for_Vancou_140313cc0[0x34];

    local_1d8[0x35] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_1d8,0,

                  CONCAT44(uVar14,DAT_140303758));

    if (uStack_1c0 < 0x10) {

      return 1;

    }

    if ((0xfff < uStack_1c0 + 1) &&

       ((char *)0x1f < local_1d8 + (-8 - *(longlong *)(local_1d8 + -8)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

  return 1;

}




