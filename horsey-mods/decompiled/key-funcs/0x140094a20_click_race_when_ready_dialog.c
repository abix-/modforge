// Hint: click_race_when_ready_dialog
// Address: 0x140094a20
// Ghidra name: FUN_140094a20
// ============ 0x140094a20 FUN_140094a20 (size=13205) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140094a20(longlong param_1)



{

  int *piVar1;

  undefined1 uVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  char cVar9;

  int iVar10;

  undefined4 uVar11;

  int iVar12;

  undefined8 uVar13;

  undefined8 uVar14;

  undefined8 *puVar15;

  undefined8 *puVar16;

  longlong lVar17;

  ulonglong uVar18;

  float *pfVar19;

  int iVar20;

  longlong lVar21;

  longlong lVar22;

  uint uVar23;

  char *pcVar24;

  ulonglong uVar25;

  ulonglong uVar26;

  ulonglong uVar27;

  undefined8 uVar28;

  ulonglong uVar29;

  ulonglong uVar30;

  ulonglong uVar31;

  int iVar32;

  ulonglong uVar33;

  float fVar34;

  float fVar35;

  float fVar36;

  float fVar37;

  undefined8 *local_res8;

  int local_res10;

  ulonglong in_stack_fffffffffffffec8;

  undefined8 local_128;

  undefined8 uStack_120;

  undefined1 local_118 [16];

  undefined8 local_100;

  undefined8 uStack_f8;

  undefined8 local_f0;

  ulonglong uStack_e8;

  

  if ((DAT_1403d959b != '\0') && (DAT_1403ed63e != '\0')) {

    FUN_140092150();

    FUN_140092380(param_1);

    FUN_14008ffc0(param_1);

  }

  uVar25 = 0;

  *(undefined4 *)(param_1 + 0x124) = 0;

  *(int *)(param_1 + 0x254) = *(int *)(param_1 + 0x254) + 1;

  if (*(char *)(param_1 + 600) == '\0') {

    FUN_140040fc0();

  }

  FUN_1400c8e70(*(undefined8 *)(param_1 + 0x328));

  if (0 < *(int *)(param_1 + 800)) {

    *(int *)(param_1 + 800) = *(int *)(param_1 + 800) + -1;

  }

  FUN_1400ca260(param_1);

  _DAT_1403da0bc = *(int *)(param_1 + 0xd8);

  if (((*(int *)(param_1 + 0x3d4) < 9) && ((*(int *)(param_1 + 0x3d4) - 3U & 0xfffffffb) != 0)) &&

     ((0 < *(int *)(param_1 + 0x3d0) || (*(longlong *)(param_1 + 0x3c0) != 0)))) {

    iVar10 = *(int *)(param_1 + 0xe0);

    if ((iVar10 == 0x18) || (iVar10 == 0x19)) {

LAB_140094b59:

      *(undefined4 *)(param_1 + 0x1fc) = 3;

    }

    else {

      if (1 < _DAT_1403da0bc - 0x18U) goto LAB_140094b9d;

      if (iVar10 != -1) goto LAB_140094b59;

    }

    *(undefined8 *)(param_1 + 0xd8) = 0xffffffffffffffff;

    *(undefined4 *)(param_1 + 0xe0) = 0xffffffff;

  }

  else {

    FUN_1400ca150(param_1,0,0x18);

    FUN_1400ca150(param_1,1,0x19);

  }

LAB_140094b9d:

  FUN_1400ca150(param_1,3,0x1a);

  FUN_1400ca150(param_1,2,0x1b);

  if ((((*(char *)(param_1 + 0x259) != '\0') && (*(int *)(param_1 + 0x250) == 8)) &&

      (0xb4 < *(int *)(param_1 + 0x254))) && ((DAT_1403ed570 != '\0' || (DAT_1403ed968 != 0)))) {

    *(undefined4 *)(param_1 + 0xe0) = 0x1b;

  }

  if (*(int *)(param_1 + 0xe0) == 0x1a) {

    *(undefined4 *)(param_1 + 0xe0) = 0xffffffff;

  }

  uVar33 = uVar25;

  if (*(int *)(param_1 + 0xdc) == 0x1a) {

    iVar10 = *(int *)(param_1 + 0x2cc);

    if (iVar10 == 0) {

LAB_140094c4a:

      *(undefined4 *)(param_1 + 0xe0) = 0x1a;

    }

    else if (0x1d < iVar10) {

      iVar20 = 10;

      if (299 < iVar10) {

        iVar20 = 5;

      }

      if (iVar10 % iVar20 == 0) goto LAB_140094c4a;

    }

    uVar33 = (ulonglong)(iVar10 + 1);

  }

  *(int *)(param_1 + 0x2cc) = (int)uVar33;

  if ((*(int *)(param_1 + 0x1f8) == 0) && (*(longlong *)(param_1 + 0x3c0) != 0)) {

    *(undefined4 *)(param_1 + 0x1f8) = 1;

    local_res8 = &local_100;

    uStack_f8 = 0;

    local_f0 = 0;

    uStack_e8 = 0xf;

    local_100 = (char *)0x0;

    uVar13 = FUN_1400279c0(&local_128);

    FUN_140094810(param_1,uVar13);

  }

  *(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0xa60) = 0x431d0000;

  if ((*(int *)(param_1 + 0x3d4) == 8) && (*(int *)(param_1 + 0x250) == 3)) {

    uVar23 = *(int *)(param_1 + 0x254) / 0xf & 0x80000001;

    if ((int)uVar23 < 0) {

      uVar23 = (uVar23 - 1 | 0xfffffffe) + 1;

    }

    *(float *)(*(longlong *)(param_1 + 0x60) + 0xa60) =

         *(float *)(*(longlong *)(param_1 + 0x60) + 0xa60) - (float)(int)uVar23;

  }

  fVar37 = DAT_14030c2ac;

  if ((*(char *)(param_1 + 0x2b0) != '\0') && (*(char *)(param_1 + 600) != '\0')) {

    return;

  }

  if ((*(int *)(param_1 + 0xe0) == 0x19) || (*(char *)(param_1 + 0x2b0) != '\0')) {

    DAT_1403eded8 = DAT_1403eded8 + -1;

    FUN_14003f6f0();

    if (*(int *)(param_1 + 0x298) != 0) {

      *(undefined8 *)(param_1 + 0x250) = 0xc;

      return;

    }

    FUN_1400fb2b0(DAT_1403f4e00);

    if (*(longlong *)(param_1 + 0x278) == 0) {

      FUN_1400cdae0(param_1);

      return;

    }

    *(undefined4 *)(*(longlong *)(param_1 + 0x278) + 0x254) = 4;

    FUN_1400cd560(param_1,*(undefined4 *)(*(longlong *)(param_1 + 0x278) + 8));

    return;

  }

  *(undefined4 *)(param_1 + 0x15c) = 0xffffffff;

  if (((*(int *)(param_1 + 0xd8) == -1) && (1 < DAT_1403eded8)) &&

     (*(int *)(param_1 + 0x250) - 3U < 2)) {

    fVar36 = DAT_1403ed978 / *(float *)(param_1 + 0x114);

    fVar35 = *(float *)(param_1 + 0x110);

    lVar22 = *(longlong *)(param_1 + 0x130);

    uVar33 = uVar25;

    uVar27 = uVar25;

    if (*(longlong *)(param_1 + 0x138) - lVar22 >> 3 != 0) {

      do {

        cVar9 = FUN_1400b6fd0(*(undefined8 *)(lVar22 + uVar33));

        if ((cVar9 != '\0') &&

           (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x130) + uVar33) + 0x1f8) != -1)) {

          *(int *)(param_1 + 0x15c) = (int)uVar27;

          *(undefined4 *)(param_1 + 0x124) = 4;

        }

        uVar23 = (int)uVar27 + 1;

        lVar22 = *(longlong *)(param_1 + 0x130);

        uVar33 = uVar33 + 8;

        uVar27 = (ulonglong)uVar23;

      } while ((ulonglong)(longlong)(int)uVar23 <

               (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar22 >> 3));

    }

    if ((*(int *)(param_1 + 0x18c) != -1) && (*(int *)(param_1 + 400) - 0x10U < 0x2d)) {

      *(undefined4 *)(param_1 + 0x124) = 0xb;

    }

    if ((((*(longlong *)(param_1 + 0x3a8) != 0) && (*(int *)(param_1 + 0x250) == 3)) &&

        (0x87 < *(int *)(param_1 + 0x254))) &&

       ((fVar36 + fVar35 <= DAT_140303384 && (cVar9 = FUN_1400b6fd0(), cVar9 != '\0')))) {

      *(undefined4 *)(param_1 + 0x124) = 10;

    }

  }

  if (*(int *)(param_1 + 0x324) < 1) {

    if ((*(int *)(param_1 + 0x250) < 9) && (*(char *)(param_1 + 0xb0) == '\0')) {

      uVar2 = *(undefined1 *)(param_1 + 600);

      lVar22 = *(longlong *)(param_1 + 0x130);

      uVar33 = uVar25;

      uVar27 = uVar25;

      if (*(longlong *)(param_1 + 0x138) - lVar22 >> 3 != 0) {

        do {

          FUN_1400b9540(*(undefined8 *)(lVar22 + uVar33),uVar2);

          if (*(longlong *)(param_1 + 0x378) != *(longlong *)(param_1 + 0x380)) {

            FUN_1400b9540(*(undefined8 *)(uVar33 + *(longlong *)(param_1 + 0x378)),uVar2);

          }

          if (*(longlong *)(param_1 + 0x3a8) != 0) {

            FUN_1400b9540(*(longlong *)(param_1 + 0x3a8),0);

          }

          uVar23 = (int)uVar27 + 1;

          lVar22 = *(longlong *)(param_1 + 0x130);

          uVar33 = uVar33 + 8;

          uVar27 = (ulonglong)uVar23;

        } while ((ulonglong)(longlong)(int)uVar23 <

                 (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar22 >> 3));

      }

      if (*(longlong *)(param_1 + 0x98) != 0) {

        FUN_140007610();

      }

      lVar22 = *(longlong *)(param_1 + 0xa0);

      if (lVar22 != 0) {

        cVar9 = FUN_14000f890(lVar22 + 0xc);

        if (cVar9 != '\0') {

          local_res8 = *(undefined8 **)(lVar22 + 0x40);

          cVar9 = FUN_14000f890(&local_res8);

          if (cVar9 != '\0') goto LAB_140094fd0;

        }

        *(undefined1 *)(param_1 + 0xb0) = 1;

      }

    }

  }

  else {

    *(int *)(param_1 + 0x324) = *(int *)(param_1 + 0x324) + -1;

  }

LAB_140094fd0:

  if (*(int *)(param_1 + 0x250) - 3U < 2) {

    if (((DAT_1403ed968 != 0) && (*(int *)(param_1 + 0x15c) != -1)) &&

       (*(int *)(*(longlong *)

                  (*(longlong *)(param_1 + 0x130) + (longlong)*(int *)(param_1 + 0x15c) * 8) + 0x1f8

                ) != -1)) {

      FUN_14009c7d0(DAT_1403ee020);

    }

    if ((*(int *)(param_1 + 0x254) == 0xf) &&

       (lVar22 = *(longlong *)(param_1 + 0x130), uVar33 = uVar25, uVar27 = uVar25,

       *(longlong *)(param_1 + 0x138) - lVar22 >> 3 != 0)) {

      do {

        if ((*(int *)(*(longlong *)(uVar33 + lVar22) + 0x1c) == 2) &&

           (iVar10 = FUN_1400c6580(10), iVar10 == 0)) {

          FUN_1400b7fe0(*(undefined8 *)(uVar33 + *(longlong *)(param_1 + 0x130)),0);

        }

        uVar23 = (int)uVar27 + 1;

        lVar22 = *(longlong *)(param_1 + 0x130);

        uVar33 = uVar33 + 8;

        uVar27 = (ulonglong)uVar23;

      } while ((ulonglong)(longlong)(int)uVar23 <

               (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar22 >> 3));

    }

  }

  fVar6 = DAT_14039ca44;

  fVar36 = DAT_1403033cc;

  fVar35 = DAT_140303354;

  iVar10 = *(int *)(param_1 + 0x250);

  if (iVar10 == 0) {

    if ((0x78 < *(int *)(param_1 + 0x254)) && (DAT_1403ed968 != 0)) {

      local_118._8_8_ = _UNK_1403033f8;

      local_118._0_8_ = _DAT_1403033f0;

      local_128 = (char *)s_OnYourMark_14030bc10._0_8_;

      uStack_120 = (ulonglong)(ushort)s_OnYourMark_14030bc10._8_2_;

      uVar11 = FUN_140040ca0(&local_128,100);

      *(undefined4 *)(param_1 + 0x2f4) = uVar11;

      if (0xf < (ulonglong)local_118._8_8_) {

        if ((0xfff < local_118._8_8_ + 1) &&

           ((char *)0x1f < local_128 + (-8 - *(longlong *)(local_128 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      *(undefined8 *)(param_1 + 0x250) = 1;

    }

    goto LAB_1400975ff;

  }

  if (iVar10 == 1) {

    fVar34 = *(float *)(param_1 + 0x10c) - DAT_140303354;

    if (fVar34 <= DAT_1403033cc) {

      fVar34 = DAT_1403033cc;

    }

    *(float *)(param_1 + 0x10c) = fVar34;

    if (fVar34 == fVar36) {

      *(undefined8 *)(param_1 + 0x250) = 2;

    }

    goto LAB_1400975ff;

  }

  if (iVar10 == 2) {

    if (*(int *)(param_1 + 0x254) == 1) {

      local_118._8_8_ = _UNK_1403040b8;

      local_118._0_8_ = _DAT_1403040b0;

      local_128 = (char *)s_BoothSlideIn_14030bcf0._0_8_;

      uStack_120 = (ulonglong)(uint)s_BoothSlideIn_14030bcf0._8_4_;

      FUN_140040ca0(&local_128,100);

      if (0xf < (ulonglong)local_118._8_8_) {

        if ((0xfff < local_118._8_8_ + 1) &&

           ((char *)0x1f < local_128 + (-8 - *(longlong *)(local_128 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    if (*(int *)(param_1 + 0x254) == 0x3c) {

      local_res8 = &local_100;

      uStack_f8 = 0;

      local_f0 = 0;

      uStack_e8 = 0xf;

      local_100 = (char *)0x0;

      local_128 = (char *)0x0;

      uStack_120 = 0;

      local_118 = ZEXT816(0);

      local_128 = (char *)FUN_1400285e0(0x20);

      uVar13 = s_Welcome__new_player__14030bd00._8_8_;

      local_118._8_8_ = 0x1f;

      local_118._0_8_ = 0x14;

      *(undefined8 *)local_128 = s_Welcome__new_player__14030bd00._0_8_;

      *(undefined8 *)(local_128 + 8) = uVar13;

      *(undefined4 *)(local_128 + 0x10) = s_Welcome__new_player__14030bd00._16_4_;

      local_128[0x14] = '\0';

      FUN_140094810(param_1,&local_128,&local_100);

    }

    if (*(int *)(param_1 + 0x254) == 0xb4) {

      *(undefined8 *)(param_1 + 0x250) = 3;

    }

    goto LAB_1400975ff;

  }

  if (iVar10 == 3) {

    FUN_1400d2740(param_1);

    if ((*(int *)(param_1 + 0x124) == 10) && (DAT_1403ed968 != 0)) {

      local_res8 = &local_100;

      uStack_f8 = 0;

      local_f0 = 0;

      uStack_e8 = 0xf;

      local_100 = (char *)0x0;

      local_128 = (char *)0x0;

      uStack_120 = 0;

      local_118 = ZEXT816(0);

      local_128 = (char *)FUN_1400285e0(0x20);

      uVar13 = s_Place_your_bets__14030bd18._8_8_;

      local_118._8_8_ = 0x1f;

      local_118._0_8_ = 0x10;

      *(undefined8 *)local_128 = s_Place_your_bets__14030bd18._0_8_;

      *(undefined8 *)(local_128 + 8) = uVar13;

      local_128[0x10] = '\0';

      FUN_140094810(param_1,&local_128);

      DAT_1403ed968 = 0;

    }

    if ((*(int *)(param_1 + 0x254) == 1) && (1 < DAT_1403eded8)) {

      local_118._8_8_ = _UNK_1403040b8;

      local_118._0_8_ = _DAT_1403040b0;

      local_128 = (char *)s_BoothSlideIn_14030bcf0._0_8_;

      uStack_120 = (ulonglong)(uint)s_BoothSlideIn_14030bcf0._8_4_;

      in_stack_fffffffffffffec8 = in_stack_fffffffffffffec8 & 0xffffffffffffff00;

      FUN_140040ca0(&local_128,100);

      if (0xf < (ulonglong)local_118._8_8_) {

        if ((0xfff < local_118._8_8_ + 1) &&

           ((char *)0x1f < local_128 + (-8 - *(longlong *)(local_128 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    if (*(int *)(param_1 + 0x254) == 0xf) {

      if ((*(int *)(param_1 + 0x3d4) == 3) && (1 < *(int *)(param_1 + 0x268))) {

        *(undefined4 *)(param_1 + 0x3d4) = 5;

      }

    }

    else if (*(int *)(param_1 + 0x254) == 0x87) {

      uStack_120 = 0;

      local_118._8_8_ = 0xf;

      local_118._0_8_ = 7;

      local_128._0_6_ = CONCAT24(s_Betting_140303270._4_2_,s_Betting_140303270._0_4_);

      local_128._0_7_ = CONCAT16(s_Betting_140303270[6],(uint6)local_128);

      local_128 = (char *)(ulonglong)(uint7)local_128;

      FUN_14003f340(&local_128,1);

      if (*(int *)(param_1 + 0x298) == 0) {

        local_res8 = &local_100;

        uStack_f8 = 0;

        local_f0 = 0;

        uStack_e8 = 0xf;

        local_100 = (char *)0x0;

        local_128 = (char *)0x0;

        uStack_120 = 0;

        local_118 = ZEXT816(0);

        local_128 = (char *)FUN_1400285e0(0x30);

        uVar13 = s_Where_have_all_the_horses_gone___14030bd30._8_8_;

        local_118._8_8_ = 0x2f;

        local_118._0_8_ = 0x20;

        *(undefined8 *)local_128 = s_Where_have_all_the_horses_gone___14030bd30._0_8_;

        *(undefined8 *)(local_128 + 8) = uVar13;

        uVar13 = s_Where_have_all_the_horses_gone___14030bd30._24_8_;

        *(undefined8 *)(local_128 + 0x10) = s_Where_have_all_the_horses_gone___14030bd30._16_8_;

        *(undefined8 *)(local_128 + 0x18) = uVar13;

        local_128[0x20] = '\0';

        puVar15 = &local_100;

        puVar16 = &local_128;

LAB_140095d5b:

        FUN_140094810(param_1,puVar16,puVar15);

      }

      else if (*(char *)(param_1 + 0x270) == '\0') {

        if (((DAT_1403eded8 < 8) || (*(int *)(param_1 + 0x3d4) != 7)) ||

           (*(int *)(DAT_1403fb0d8 + 0x308) < 100)) {

          iVar10 = *(int *)(param_1 + 0x3d4);

          if (iVar10 == 0) {

            *(undefined4 *)(param_1 + 0x1f8) = 1;

            local_res8 = &local_100;

            uStack_f8 = 0;

            local_f0 = 0;

            uStack_e8 = 0xf;

            local_100 = (char *)0x0;

            local_128 = (char *)0x0;

            uStack_120 = 0;

            local_118 = ZEXT816(0);

            local_128 = (char *)FUN_1400285e0(0x20);

            uVar13 = s_Pick_a_horse_to_win__14030bef8._8_8_;

            local_118._8_8_ = 0x1f;

            local_118._0_8_ = 0x14;

            *(undefined8 *)local_128 = s_Pick_a_horse_to_win__14030bef8._0_8_;

            *(undefined8 *)(local_128 + 8) = uVar13;

            *(undefined4 *)(local_128 + 0x10) = s_Pick_a_horse_to_win__14030bef8._16_4_;

            local_128[0x14] = '\0';

            FUN_140094810(param_1,&local_128,&local_100);

            *(undefined4 *)(param_1 + 0x1f8) = 36000;

          }

          else {

            if (iVar10 != 2) {

              if (*(longlong *)(param_1 + 0x3a8) == **(longlong **)(param_1 + 0x130)) {

                local_res8 = &local_100;

                local_100 = (char *)0x0;

                uStack_f8 = 0;

                local_f0 = 0;

                uStack_e8 = 0;

                FUN_140027e30(&local_100,"On me! ha ha!",0xd);

                local_128 = (char *)0x0;

                uStack_120 = 0;

                local_118 = ZEXT816(0);

                FUN_140027e30(&local_128,"Place your bets!",0x10);

                puVar15 = &local_100;

                puVar16 = &local_128;

                goto LAB_140095d5b;

              }

              iVar20 = *(int *)(param_1 + 0x2a0);

              if (iVar20 == 7) {

                if (iVar10 < 9) goto LAB_140095cd5;

                local_res8 = &local_100;

                puVar15 = (undefined8 *)FUN_140027b00(&local_100);

                pcVar24 = "None of these horses have ever raced before!";

              }

              else if (iVar20 == 8) {

                if (iVar10 < 9) goto LAB_140095cd5;

                local_res8 = &local_100;

                puVar15 = (undefined8 *)FUN_140027b00(&local_100);

                pcVar24 = "These horses are hopeless!";

              }

              else if (iVar20 == 4) {

                if (iVar10 < 9) goto LAB_140095cd5;

                local_res8 = &local_100;

                puVar15 = (undefined8 *)FUN_140027b00(&local_100);

                pcVar24 = "These horses are underdogs!";

              }

              else if (iVar20 == 3) {

                if (iVar10 < 9) goto LAB_140095cd5;

                local_res8 = &local_100;

                puVar15 = (undefined8 *)FUN_140027b00(&local_100);

                pcVar24 = "This will be an exciting race!";

              }

              else if (iVar20 == 2) {

                if (iVar10 < 9) {

LAB_140095cd5:

                  if ((*(char *)(param_1 + 0x3d8) == '\0') && (*(char *)(param_1 + 0x264) != '\0'))

                  {

                    local_res8 = &local_100;

                    uVar13 = FUN_140027980(&local_100,"Place your bets!");

                    uVar14 = FUN_140027980(&local_128,"Congrats! Have another go");

                    FUN_140094810(param_1,uVar14,uVar13);

                    *(undefined1 *)(param_1 + 0x3d8) = 1;

                    goto LAB_140095d63;

                  }

                  local_res8 = &local_100;

                  puVar15 = (undefined8 *)FUN_140027b00(&local_100);

                  pcVar24 = "Place your bets!";

                }

                else {

                  local_res8 = &local_100;

                  puVar15 = (undefined8 *)FUN_140027b00(&local_100);

                  pcVar24 = "These horses are all winners!";

                }

              }

              else {

                if ((iVar20 != 5) || (iVar10 < 9)) goto LAB_140095cd5;

                local_res8 = &local_100;

                puVar15 = (undefined8 *)FUN_140027b00(&local_100);

                pcVar24 = "It\'s a Champion race!";

              }

              puVar16 = (undefined8 *)FUN_140027980(&local_128,pcVar24);

              goto LAB_140095d5b;

            }

            local_res8 = &local_100;

            local_f0 = 0;

            local_100 = (char *)0x0;

            uStack_f8 = 0;

            if (*(char *)(param_1 + 0x264) == '\0') {

              uStack_e8 = 0;

              FUN_140027e30(&local_100,"Place your bets!",0x10);

              uVar13 = 0x1e;

              pcVar24 = "Better luck with the next race";

            }

            else {

              if (*(char *)(param_1 + 0x3d8) == '\0') {

                uStack_e8 = 0;

                FUN_140027e30(&local_100,"Place your bets!",0x10);

                local_128 = (char *)0x0;

                uStack_120 = 0;

                local_118 = ZEXT816(0);

                FUN_140027e30(&local_128,"Congrats! Have another go",0x19);

                FUN_140094810(param_1,&local_128,&local_100);

                *(undefined1 *)(param_1 + 0x3d8) = 1;

                *(undefined4 *)(param_1 + 0x3d4) = 3;

                goto LAB_140095d63;

              }

              uStack_e8 = 0xf;

              local_100 = (char *)0x0;

              uVar13 = 0x10;

              pcVar24 = "Place your bets!";

            }

            local_128 = (char *)0x0;

            uStack_120 = 0;

            local_118 = ZEXT816(0);

            FUN_140027e30(&local_128,pcVar24,uVar13);

            FUN_140094810(param_1,&local_128,&local_100);

            *(undefined4 *)(param_1 + 0x3d4) = 3;

          }

        }

        else if ((*(longlong *)(param_1 + 0x278) == 0) ||

                (*(char *)(*(longlong *)(param_1 + 0x278) + 0x26e) != '\0')) {

          *(undefined4 *)(param_1 + 0x3d4) = 9;

        }

        else {

          local_res8 = &local_100;

          uVar13 = FUN_140027980(&local_100,"And see what that\'s all about");

          uVar14 = FUN_140027980(&local_128,"Why not go on over to the paddock");

          FUN_140094810(param_1,uVar14,uVar13);

          *(undefined4 *)(param_1 + 0x3d4) = 8;

        }

      }

      else {

        iVar10 = *(int *)(param_1 + 0x26c);

        iVar20 = *(int *)(param_1 + 0x268);

        if (iVar20 == 3) {

          local_res8 = &local_100;

          if (iVar10 < 3) {

            uVar14 = FUN_14008d760(&local_100,"Minimum bet is now $%d, sir",

                                   *(undefined4 *)(param_1 + 0x2c8));

            local_128 = (char *)0x0;

            uStack_120 = 0;

            local_118 = ZEXT816(0);

            local_128 = (char *)FUN_1400285e0(0x50);

            uVar13 = _UNK_14030bd88;

            local_118._8_8_ = 0x4f;

            local_118._0_8_ = 0x43;

            *(undefined8 *)local_128 = _DAT_14030bd80;

            *(undefined8 *)(local_128 + 8) = uVar13;

            uVar13 = _UNK_14030bd98;

            *(undefined8 *)(local_128 + 0x10) = _DAT_14030bd90;

            *(undefined8 *)(local_128 + 0x18) = uVar13;

            uVar13 = _UNK_14030bda8;

            *(undefined8 *)(local_128 + 0x20) = _DAT_14030bda0;

            *(undefined8 *)(local_128 + 0x28) = uVar13;

            uVar13 = _UNK_14030bdb8;

            *(undefined8 *)(local_128 + 0x30) = _DAT_14030bdb0;

            *(undefined8 *)(local_128 + 0x38) = uVar13;

            *(undefined2 *)(local_128 + 0x40) = DAT_14030bdc0;

            local_128[0x42] = DAT_14030bdc2;

            local_128[0x43] = '\0';

            FUN_140094810(param_1,&local_128,uVar14);

            *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(param_1 + 0x268);

          }

          else {

            uStack_f8 = 0;

            local_f0 = 0;

            uStack_e8 = 0xf;

            local_100 = (char *)0x0;

            local_128 = (char *)0x0;

            uStack_120 = 0;

            local_118 = ZEXT816(0);

            local_128 = (char *)FUN_1400285e0(0x40);

            uVar13 = _UNK_14030bdd0;

            local_118._8_8_ = 0x3f;

            local_118._0_8_ = 0x3c;

            *(undefined8 *)local_128 = _DAT_14030bdc8;

            *(undefined8 *)(local_128 + 8) = uVar13;

            uVar13 = _UNK_14030bde0;

            *(undefined8 *)(local_128 + 0x10) = _DAT_14030bdd8;

            *(undefined8 *)(local_128 + 0x18) = uVar13;

            uVar13 = _UNK_14030bdf0;

            *(undefined8 *)(local_128 + 0x20) = _DAT_14030bde8;

            *(undefined8 *)(local_128 + 0x28) = uVar13;

            *(undefined8 *)(local_128 + 0x30) = DAT_14030bdf8;

            *(undefined4 *)(local_128 + 0x38) = DAT_14030be00;

            local_128[0x3c] = '\0';

LAB_1400957a3:

            FUN_140094810(param_1,&local_128,&local_100);

            *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(param_1 + 0x268);

          }

        }

        else if (iVar20 == 2) {

          if (1 < iVar10) {

            local_res8 = &local_100;

            local_100 = (char *)0x0;

            uStack_f8 = 0;

            local_f0 = 0;

            uStack_e8 = 0;

            FUN_140027e30(&local_100,"Your money is always welcome here",0x21);

            local_128 = (char *)0x0;

            uStack_120 = 0;

            local_118 = ZEXT816(0);

            FUN_140027e30(&local_128,"Welcome back to the VIP lounge",0x1e);

            goto LAB_1400957a3;

          }

          local_res8 = &local_128;

          uVar13 = FUN_14008d760(&local_128,"Minimum bet is now $%d",

                                 *(undefined4 *)(param_1 + 0x2c8));

          local_100 = (char *)0x0;

          uStack_f8 = 0;

          local_f0 = 0;

          uStack_e8 = 0;

          FUN_140027e30(&local_100,"Welcome To the VIP lounge. We have plants!",0x2a);

          FUN_140094810(param_1,&local_100,uVar13);

          *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(param_1 + 0x268);

        }

        else {

          local_res8 = &local_100;

          if (iVar10 < iVar20) {

            puVar15 = (undefined8 *)

                      FUN_14008d760(&local_100,"Minimum bet is now $%d",

                                    *(undefined4 *)(param_1 + 0x2c8));

            local_128 = (char *)0x0;

            uStack_120 = 0;

            local_118 = ZEXT816(0);

            local_128 = (char *)FUN_1400285e0(0x20);

            uVar13 = s_Let_s_raise_the_stakes__14030be98._8_8_;

            local_118._8_8_ = 0x1f;

            local_118._0_8_ = 0x17;

            *(undefined8 *)local_128 = s_Let_s_raise_the_stakes__14030be98._0_8_;

            *(undefined8 *)(local_128 + 8) = uVar13;

            *(undefined4 *)(local_128 + 0x10) = s_Let_s_raise_the_stakes__14030be98._16_4_;

            *(undefined2 *)(local_128 + 0x14) = s_Let_s_raise_the_stakes__14030be98._20_2_;

            local_128[0x16] = s_Let_s_raise_the_stakes__14030be98[0x16];

            local_128[0x17] = '\0';

          }

          else {

            uStack_f8 = 0;

            local_f0 = 0;

            uStack_e8 = 0xf;

            local_100 = (char *)0x0;

            local_128 = (char *)0x0;

            uStack_120 = 0;

            local_118 = ZEXT816(0);

            FUN_140027e30(&local_128,"Let\'s raise the stakes!",0x17);

            puVar15 = &local_100;

          }

          FUN_140094810(param_1,&local_128,puVar15);

          if (*(int *)(param_1 + 0x3d4) == 3) {

            *(undefined4 *)(param_1 + 0x3d4) = 4;

          }

          *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(param_1 + 0x268);

        }

      }

    }

LAB_140095d63:

    if ((0 < *(int *)(param_1 + 0x3d0)) &&

       (iVar10 = *(int *)(param_1 + 0x3d0) + -1, *(int *)(param_1 + 0x3d0) = iVar10, iVar10 == 0)) {

      iVar10 = *(int *)(param_1 + 0x3d4);

      if (iVar10 == 0) {

        *(undefined4 *)(param_1 + 0x1f8) = 1;

        local_res8 = &local_100;

        uStack_f8 = 0;

        local_f0 = 0;

        uStack_e8 = 0xf;

        local_100 = (char *)0x0;

        local_128 = (char *)0x0;

        uStack_120 = 0;

        local_118 = ZEXT816(0);

        local_128 = (char *)FUN_1400285e0(0x20);

        uVar13 = s_How_much_will_you_bet__14030c028._8_8_;

        local_118._8_8_ = 0x1f;

        local_118._0_8_ = 0x16;

        *(undefined8 *)local_128 = s_How_much_will_you_bet__14030c028._0_8_;

        *(undefined8 *)(local_128 + 8) = uVar13;

        *(undefined4 *)(local_128 + 0x10) = s_How_much_will_you_bet__14030c028._16_4_;

        *(undefined2 *)(local_128 + 0x14) = s_How_much_will_you_bet__14030c028._20_2_;

        local_128[0x16] = '\0';

        FUN_140094810(param_1,&local_128,&local_100);

        *(undefined4 *)(param_1 + 0x3d4) = 1;

      }

      else if (iVar10 == 1) {

        *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0xa1d) = 1;

        *(undefined4 *)(param_1 + 0x1f8) = 1;

        local_res8 = &local_100;

        uStack_f8 = 0;

        local_f0 = 0;

        uStack_e8 = 0xf;

        local_100 = (char *)0x0;

        local_128 = (char *)0x0;

        uStack_120 = 0;

        local_118 = ZEXT816(0);

        local_128 = (char *)FUN_1400285e0(0x20);

        uVar13 = s_Click_Race_when_ready__14030c040._8_8_;

        local_118._8_8_ = 0x1f;

        local_118._0_8_ = 0x16;

        *(undefined8 *)local_128 = s_Click_Race_when_ready__14030c040._0_8_;

        *(undefined8 *)(local_128 + 8) = uVar13;

        *(undefined4 *)(local_128 + 0x10) = s_Click_Race_when_ready__14030c040._16_4_;

        *(undefined2 *)(local_128 + 0x14) = s_Click_Race_when_ready__14030c040._20_2_;

        local_128[0x16] = '\0';

        FUN_140094810(param_1,&local_128,&local_100);

        *(undefined4 *)(param_1 + 0x3d4) = 2;

      }

      else if (iVar10 == 5) {

        *(undefined4 *)(param_1 + 0x1f8) = 1;

        local_res8 = &local_128;

        local_128 = (char *)0x0;

        uStack_120 = 0;

        local_118 = ZEXT816(0);

        local_128 = (char *)FUN_1400285e0(0x20);

        uVar13 = s_But_the_odds_are_slim_14030c058._8_8_;

        local_118._8_8_ = 0x1f;

        local_118._0_8_ = 0x15;

        *(undefined8 *)local_128 = s_But_the_odds_are_slim_14030c058._0_8_;

        *(undefined8 *)(local_128 + 8) = uVar13;

        *(undefined4 *)(local_128 + 0x10) = s_But_the_odds_are_slim_14030c058._16_4_;

        local_128[0x14] = s_But_the_odds_are_slim_14030c058[0x14];

        local_128[0x15] = '\0';

        local_100 = (char *)0x0;

        uStack_f8 = 0;

        local_f0 = 0;

        uStack_e8 = 0;

        local_100 = (char *)FUN_1400285e0(0x30);

        uVar13 = s_You_can_pick_a_horse_to_finish_s_14030c070._8_8_;

        local_f0 = 0x25;

        uStack_e8 = 0x2f;

        *(undefined8 *)local_100 = s_You_can_pick_a_horse_to_finish_s_14030c070._0_8_;

        *(undefined8 *)(local_100 + 8) = uVar13;

        uVar13 = s_You_can_pick_a_horse_to_finish_s_14030c070._24_8_;

        *(undefined8 *)(local_100 + 0x10) = s_You_can_pick_a_horse_to_finish_s_14030c070._16_8_;

        *(undefined8 *)(local_100 + 0x18) = uVar13;

        *(undefined4 *)(local_100 + 0x20) = s_You_can_pick_a_horse_to_finish_s_14030c070._32_4_;

        local_100[0x24] = s_You_can_pick_a_horse_to_finish_s_14030c070[0x24];

        local_100[0x25] = '\0';

        FUN_140094810(param_1,&local_100,&local_128);

        *(undefined4 *)(param_1 + 0x3d4) = 6;

      }

      else {

        if (iVar10 != 6) goto LAB_1400960bb;

        *(undefined4 *)(param_1 + 0x1f8) = 1;

        local_res8 = &local_100;

        local_100 = (char *)0x0;

        uStack_f8 = 0;

        local_f0 = 0;

        uStack_e8 = 0;

        local_100 = (char *)FUN_1400285e0(0x20);

        uVar13 = s_If_you_re_a_real_gambler_14030c098._8_8_;

        local_f0 = 0x18;

        uStack_e8 = 0x1f;

        *(undefined8 *)local_100 = s_If_you_re_a_real_gambler_14030c098._0_8_;

        *(undefined8 *)(local_100 + 8) = uVar13;

        *(undefined8 *)(local_100 + 0x10) = s_If_you_re_a_real_gambler_14030c098._16_8_;

        local_100[0x18] = '\0';

        local_128 = (char *)0x0;

        uStack_120 = 0;

        local_118 = ZEXT816(0);

        local_128 = (char *)FUN_1400285e0(0x20);

        uVar13 = s_Pick_a_horse_to_finish_third_14030c0b8._8_8_;

        local_118._8_8_ = 0x1f;

        local_118._0_8_ = 0x1c;

        *(undefined8 *)local_128 = s_Pick_a_horse_to_finish_third_14030c0b8._0_8_;

        *(undefined8 *)(local_128 + 8) = uVar13;

        *(undefined8 *)(local_128 + 0x10) = s_Pick_a_horse_to_finish_third_14030c0b8._16_8_;

        *(undefined4 *)(local_128 + 0x18) = s_Pick_a_horse_to_finish_third_14030c0b8._24_4_;

        local_128[0x1c] = '\0';

        FUN_140094810(param_1,&local_128,&local_100);

        *(undefined4 *)(param_1 + 0x3d4) = 7;

      }

      *(undefined4 *)(param_1 + 0x1f8) = 36000;

    }

LAB_1400960bb:

    if (((*(int *)(param_1 + 0x298) == 0) && (0x87 < *(int *)(param_1 + 0x254))) &&

       (*(int *)(param_1 + 0x1f8) == 0)) {

      FUN_14008ff60(param_1,4);

    }

    iVar10 = *(int *)(param_1 + 0xe0);

    if ((7 < iVar10) && (iVar10 < *(int *)(param_1 + 0x298) + 8)) {

      uVar33 = (longlong)iVar10 - 8;

      if (*(int *)(*(longlong *)(param_1 + 0x280) + 8 + uVar33 * 0x70) == -1) {

        iVar10 = *(int *)(param_1 + 700);

        *(int *)(param_1 + 700) = iVar10 + 1;

        *(int *)(*(longlong *)(param_1 + 0x280) + 8 + uVar33 * 0x70) = iVar10;

        FUN_1400b87e0(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + uVar33 * 8));

        if ((*(int *)(param_1 + 0x3d4) < 5) &&

           (uVar27 = uVar25, uVar29 = uVar25,

           *(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3 != 0)) {

          do {

            if (uVar25 != uVar33) {

              *(undefined1 *)(uVar27 + 0x39d + *(longlong *)(param_1 + 0x60)) = 0;

            }

            uVar23 = (int)uVar29 + 1;

            uVar25 = uVar25 + 1;

            uVar27 = uVar27 + 0x68;

            uVar29 = (ulonglong)uVar23;

          } while ((ulonglong)(longlong)(int)uVar23 <

                   (ulonglong)(*(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3)

                  );

        }

        iVar10 = *(int *)(param_1 + 0x3d4);

        if (iVar10 == 0) {

          *(undefined4 *)(param_1 + 0x3d0) = 0x5a;

        }

        else if ((iVar10 == 5) || ((iVar10 == 6 && (*(int *)(param_1 + 700) == 2)))) {

          *(undefined4 *)(param_1 + 0x1f8) = 0;

          *(undefined4 *)(param_1 + 0x3d0) = 0x3c;

        }

      }

      if ((1 < *(int *)(param_1 + 0x3d4)) && (0 < *(int *)(param_1 + 0x2c0))) {

        uVar13 = 1;

LAB_140096539:

        FUN_1400ca240(param_1,0x18,uVar13);

      }

      FUN_140093d90(param_1);

      goto LAB_1400975ff;

    }

    if (iVar10 == 0x1a) {

      iVar10 = *(int *)(param_1 + 0x2c0);

      if ((iVar10 != *(int *)(param_1 + 0x2c4)) && (iVar10 != *(int *)(DAT_1403fb0d8 + 0x308))) {

        iVar10 = iVar10 + *(int *)(param_1 + 0x2c8);

        *(int *)(param_1 + 0x2c0) = iVar10;

        uVar11 = FUN_1400c5c20(iVar10,*(undefined4 *)(DAT_1403fb0d8 + 0x308));

        *(undefined4 *)(param_1 + 0x2c0) = uVar11;

        iVar10 = FUN_1400c5c20(uVar11,*(undefined4 *)(param_1 + 0x2c4));

        *(int *)(param_1 + 0x2c0) = iVar10;

        if ((iVar10 == *(int *)(param_1 + 0x2c4)) || (iVar10 == *(int *)(DAT_1403fb0d8 + 0x308))) {

          uStack_120 = 0;

          local_118._8_8_ = _UNK_1403033d8;

          local_118._0_8_ = _DAT_1403033d0;

          local_128._0_6_ = CONCAT24(s_BetMax_14030c0d8._4_2_,s_BetMax_14030c0d8._0_4_);

          local_128 = (char *)(ulonglong)(uint6)local_128;

          FUN_140040ca0(&local_128,100,0);

        }

        else {

          uStack_120 = 0;

          local_118._8_8_ = _UNK_1403033e8;

          local_118._0_8_ = _DAT_1403033e0;

          local_128._0_6_ = CONCAT24(s_BetMore_14030c0e0._4_2_,s_BetMore_14030c0e0._0_4_);

          local_128._0_7_ = CONCAT16(s_BetMore_14030c0e0[6],(uint6)local_128);

          local_128 = (char *)(ulonglong)(uint7)local_128;

          FUN_140040ca0(&local_128,100,0,

                        ((float)iVar10 * DAT_14030335c) / (float)*(int *)(param_1 + 0x2c4) +

                        DAT_14039ca38,in_stack_fffffffffffffec8 & 0xffffffffffffff00);

        }

        if (0xf < (ulonglong)local_118._8_8_) {

          FUN_140028310(&local_128,local_128);

        }

        if (*(int *)(param_1 + 0x3d4) == 1) {

          *(undefined4 *)(param_1 + 0x3d0) = 0x3c;

        }

      }

      goto LAB_1400975ff;

    }

    if (iVar10 != 0x18) {

      if ((iVar10 != 0x1b) || (*(int *)(param_1 + 700) < 1)) goto LAB_1400975ff;

      uStack_f8 = 0;

      local_f0 = _DAT_140305680;

      uStack_e8 = _UNK_140305688;

      local_100 = (char *)0x72616554;

      FUN_140040ca0(&local_100,100,0);

      FUN_140027900(&local_100);

      FUN_140094540(param_1);

      lVar22 = *(longlong *)(param_1 + 0x280);

      lVar21 = *(longlong *)(param_1 + 0x288) - lVar22;

      lVar17 = lVar21 >> 0x3f;

      uVar33 = uVar25;

      uVar27 = uVar25;

      if (lVar21 / 0x70 + lVar17 != lVar17) {

        do {

          *(undefined4 *)(uVar33 + 8 + lVar22) = 0xffffffff;

          *(undefined1 *)(uVar25 + 0x39d + *(longlong *)(param_1 + 0x60)) = 1;

          uVar23 = (int)uVar27 + 1;

          uVar25 = uVar25 + 0x68;

          lVar22 = *(longlong *)(param_1 + 0x280);

          uVar33 = uVar33 + 0x70;

          uVar27 = (ulonglong)uVar23;

        } while ((ulonglong)(longlong)(int)uVar23 <

                 (ulonglong)((*(longlong *)(param_1 + 0x288) - lVar22) / 0x70));

      }

      *(undefined4 *)(param_1 + 0x1f8) = 0;

      *(undefined4 *)(param_1 + 700) = 0;

      *(undefined4 *)(param_1 + 0x2c0) = *(undefined4 *)(param_1 + 0x2c8);

      uVar13 = 0;

      goto LAB_140096539;

    }

    if (*(int *)(param_1 + 700) < 1) goto LAB_1400975ff;

    if (*(int *)(param_1 + 0x3d4) == 4) {

      *(undefined4 *)(param_1 + 0x3d4) = 5;

    }

    FUN_1400ca240(param_1,0x1a,0);

    FUN_1400ca240(param_1,0x18,0);

    FUN_1400ca240(param_1,0x19,0);

    *(undefined4 *)(param_1 + 0x1f8) = 0;

    FUN_140104c00(DAT_1403fb0d8,*(undefined4 *)(param_1 + 0x2c0),1,0);

    *(int *)(param_1 + 0x2e0) =

         ((*(int *)(param_1 + 0x2d4) + *(int *)(param_1 + 0x2d8)) * *(int *)(param_1 + 0x2c0)) /

         *(int *)(param_1 + 0x2d8);

  }

  else {

    if (iVar10 == 4) {

      FUN_1400d2740(param_1);

      if (*(int *)(param_1 + 0xe0) == 0x18) {

        FUN_1400ca240(param_1,0x18,0);

        FUN_1400ca240(param_1,0x19,0);

        *(undefined8 *)(param_1 + 0x250) = 7;

        *(undefined4 *)(param_1 + 0x1f8) = 0;

        *(undefined4 *)(param_1 + 0x2ec) = 0;

      }

      goto LAB_1400975ff;

    }

    if (iVar10 == 6) {

      if (*(int *)(param_1 + 0x254) == 0x78) {

        uStack_120 = 0;

        local_118._8_8_ = 0xf;

        local_118._0_8_ = 7;

        local_128._0_6_ = CONCAT24(s_Betting_140303270._4_2_,s_Betting_140303270._0_4_);

        local_128._0_7_ = CONCAT16(s_Betting_140303270[6],(uint6)local_128);

        local_128 = (char *)(ulonglong)(uint7)local_128;

        FUN_14003f340(&local_128,1);

      }

      if ((DAT_1403ed570 == '\0') && (DAT_1403ed968 == 0)) goto LAB_1400975ff;

      FUN_1400ca240(param_1,0x18,0);

      iVar10 = *(int *)(param_1 + 0x298);

    }

    else {

      if (iVar10 != 5) {

        if (iVar10 == 7) {

          if (((*(int *)(param_1 + 0x254) == 1) && (*(char *)(param_1 + 0x2a5) == '\0')) &&

             (*(char *)(param_1 + 0x259) == '\0')) {

            local_118._8_8_ = _UNK_1403040b8;

            local_118._0_8_ = _DAT_1403040b0;

            local_128 = (char *)s_BoothSlideIn_14030bcf0._0_8_;

            uStack_120 = (ulonglong)(uint)s_BoothSlideIn_14030bcf0._8_4_;

            FUN_140040ca0(&local_128,100,0);

            if (0xf < (ulonglong)local_118._8_8_) {

              FUN_140028310(&local_128,local_128);

            }

          }

          if (*(int *)(param_1 + 0x254) == *(int *)(param_1 + 0x2ec) + 1) {

            FUN_14003f6f0();

            if (*(int *)(param_1 + 0x2f4) != -1) {

              FUN_140040ea0();

            }

            local_118._8_8_ = _UNK_1403033f8;

            local_118._0_8_ = _DAT_1403033f0;

            local_128 = (char *)s_RaceGetSet_140303290._0_8_;

            uStack_120 = (ulonglong)(ushort)s_RaceGetSet_140303290._8_2_;

            FUN_140040ca0(&local_128,100,0);

            if (0xf < (ulonglong)local_118._8_8_) {

              FUN_140028310(&local_128,local_128);

            }

          }

          if ((DAT_1403d9500 == '\0') || (DAT_1403d9504 < 1)) {

            iVar10 = 0x3c;

            iVar20 = 0x69;

            iVar12 = 0x5a;

          }

          else {

            iVar10 = 0x87;

            iVar20 = 0xb4;

            iVar12 = 0xa5;

          }

          iVar32 = *(int *)(param_1 + 0x2ec);

          if (((*(int *)(param_1 + 0x254) == iVar10 + iVar32) && (3 < DAT_1403eded8)) &&

             (lVar22 = *(longlong *)(param_1 + 0x130), uVar33 = uVar25, uVar27 = uVar25,

             *(longlong *)(param_1 + 0x138) - lVar22 >> 3 != 0)) {

            do {

              if (((*(uint *)(*(longlong *)(uVar33 + lVar22) + 600) & 0x400000) == 0) ||

                 (iVar10 = FUN_1400c6580(6), iVar10 != 0)) {

                lVar22 = *(longlong *)(uVar33 + *(longlong *)(param_1 + 0x130));

                if ((*(uint *)(lVar22 + 600) & 0x100) != 0) goto LAB_140096862;

              }

              else {

                lVar22 = *(longlong *)(uVar33 + *(longlong *)(param_1 + 0x130));

LAB_140096862:

                FUN_1400b7fe0(lVar22,0);

              }

              uVar23 = (int)uVar27 + 1;

              lVar22 = *(longlong *)(param_1 + 0x130);

              uVar33 = uVar33 + 8;

              uVar27 = (ulonglong)uVar23;

            } while ((ulonglong)(longlong)(int)uVar23 <

                     (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar22 >> 3));

          }

          if ((*(int *)(param_1 + 0x254) == iVar32 + iVar12) &&

             (lVar22 = *(longlong *)(param_1 + 0x130), uVar33 = uVar25, uVar27 = uVar25,

             *(longlong *)(param_1 + 0x138) - lVar22 >> 3 != 0)) {

            do {

              if ((*(int *)(*(longlong *)(uVar33 + lVar22) + 0x1c) == 1) &&

                 (cVar9 = FUN_1400c66c0(), cVar9 != '\0')) {

                FUN_1400b7fe0(*(undefined8 *)(uVar33 + *(longlong *)(param_1 + 0x130)),0);

              }

              uVar23 = (int)uVar27 + 1;

              lVar22 = *(longlong *)(param_1 + 0x130);

              uVar33 = uVar33 + 8;

              uVar27 = (ulonglong)uVar23;

            } while ((ulonglong)(longlong)(int)uVar23 <

                     (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar22 >> 3));

          }

          if (*(int *)(param_1 + 0x254) == iVar32 + iVar20) {

            lVar22 = *(longlong *)(param_1 + 0x130);

            uVar33 = uVar25;

            uVar27 = uVar25;

            if (*(longlong *)(param_1 + 0x138) - lVar22 >> 3 != 0) {

              do {

                lVar22 = *(longlong *)(uVar33 + lVar22);

                if (*(int *)(lVar22 + 0x1f8) != -1) {

                  lVar17 = FUN_1400c7520();

                  *(int *)(lVar17 + 0x50) = *(int *)(lVar17 + 0x50) + 1;

                }

                cVar9 = FUN_1400b7730(lVar22);

                if (cVar9 == '\0') {

LAB_1400969cb:

                  FUN_1400d1e10(param_1,uVar27);

                }

                else if (*(int *)(lVar22 + 0xc) != 4) {

                  uVar29 = uVar25;

                  if ((3 < DAT_1403eded8) &&

                     ((uVar29 = 0, (*(uint *)(lVar22 + 600) & 0x20000) != 0 ||

                      (*(int *)(lVar22 + 0x1c) == 2)))) {

                    iVar10 = FUN_1400c6580(0x14);

                    if (iVar10 == 0) {

                      uVar29 = 300;

                    }

                    else if (iVar10 < 0x13) {

                      iVar10 = FUN_1400c6580(4);

                      uVar29 = (ulonglong)(uint)((iVar10 + 1) * 0x1e);

                    }

                  }

                  FUN_1400b7fe0(lVar22,uVar29);

                  goto LAB_1400969cb;

                }

                uVar23 = (int)uVar27 + 1;

                lVar22 = *(longlong *)(param_1 + 0x130);

                uVar33 = uVar33 + 8;

                uVar27 = (ulonglong)uVar23;

              } while ((ulonglong)(longlong)(int)uVar23 <

                       (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar22 >> 3));

            }

            uStack_f8 = 0;

            local_f0 = _DAT_1403033d0;

            uStack_e8 = _UNK_1403033d8;

            local_100._0_6_ = CONCAT24(DAT_1403032a0,DAT_14030329c);

            local_100 = (char *)(ulonglong)(uint6)local_100;

            FUN_140040ca0(&local_100,100);

            if (0xf < uStack_e8) {

              if ((0xfff < uStack_e8 + 1) &&

                 ((char *)0x1f < local_100 + (-8 - *(longlong *)(local_100 + -8)))) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              FUN_1402c7088();

            }

            FUN_140027f50(param_1 + 0x300,"\"And They\'re Off!!\"",0x13);

            *(undefined4 *)(param_1 + 800) = 0xb4;

            *(undefined1 *)(param_1 + 0x264) = 0;

            *(undefined8 *)(param_1 + 0x250) = 8;

          }

          goto LAB_1400975ff;

        }

        if (iVar10 != 8) {

          if (iVar10 == 9) {

            fVar37 = *(float *)(param_1 + 0x2f8);

            if (*(int *)(param_1 + 0x254) == 1) {

              *(undefined1 *)(param_1 + 0x2b1) = 0;

            }

            else if (*(int *)(param_1 + 0x254) == 0x1e) {

              uStack_f8 = 0;

              local_f0 = _DAT_1403033e0;

              uStack_e8 = _UNK_1403033e8;

              local_100._0_6_ = CONCAT24(s_WonRace_1403032c0._4_2_,s_WonRace_1403032c0._0_4_);

              local_100 = (char *)(ulonglong)CONCAT16(s_WonRace_1403032c0[6],(uint6)local_100);

              FUN_140040ca0(&local_100,100,0);

              FUN_140027900(&local_100);

            }

            iVar10 = *(int *)(param_1 + 0x254);

            if (iVar10 == 0x78) {

              local_f0 = _DAT_140304090;

              uStack_e8 = _UNK_140304098;

              local_100 = (char *)0x676e697070616c43;

              uStack_f8 = 0;

              FUN_140040ca0(&local_100,100,0);

              FUN_140027900(&local_100);

              iVar10 = *(int *)(param_1 + 0x254);

            }

            if (((DAT_1403ed968 == 0) || (iVar10 < 0x1e)) || (599 < iVar10)) {

              if (iVar10 == 0x267) {

                FUN_140104b20(DAT_1403fb0d8,*(undefined4 *)(param_1 + 0x2e0),0);

                if (*(char *)(param_1 + 0x2a5) == '\0') {

                  FUN_140027980(&local_100,&DAT_140304274);

                  FUN_140037710(&local_100);

                  FUN_140027900(&local_100);

                  if (*(int *)(param_1 + 700) == 3) {

                    FUN_140027980(&local_100,&DAT_140304504);

                    FUN_140037710(&local_100);

                    FUN_140027900(&local_100);

                  }

                  if (999 < *(int *)(param_1 + 0x2e0)) {

                    FUN_140027980(&local_100,&DAT_1403044a0);

                    FUN_140037710(&local_100);

                    FUN_140027900(&local_100);

                  }

                  *(undefined1 *)(param_1 + 0x264) = 1;

                }

                else {

                  uStack_f8 = 0;

                  local_f0 = _DAT_140305680;

                  uStack_e8 = _UNK_140305688;

                  local_100 = (char *)0x65636172;

                  FUN_140037710(&local_100);

                  FUN_140027900(&local_100);

                  *(undefined1 *)

                   (*(longlong *)(*(longlong *)(param_1 + 0x278) + 0x298) + 10 +

                   (longlong)*(int *)(param_1 + 0x2a8) * 0x10) = 1;

                  *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 1;

                }

                *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + *(int *)(param_1 + 0x2e0);

                uVar11 = FUN_1400c5c30(*(undefined4 *)(param_1 + 0x260),

                                       *(undefined4 *)(DAT_1403fb0d8 + 0x308));

                *(undefined4 *)(param_1 + 0x260) = uVar11;

              }

            }

            else {

              *(undefined4 *)(param_1 + 0x254) = 600;

            }

            if (*(int *)(param_1 + 0x254) == 0x294) {

              *(undefined8 *)(param_1 + 0x250) = 0xb;

            }

          }

          else if (iVar10 == 10) {

            if ((*(char *)(param_1 + 0x259) != '\0') && (*(int *)(param_1 + 0x254) == 0x78)) {

              FUN_140027980(&local_100,"Clapping");

              FUN_140040ca0(&local_100,100,0);

              FUN_140027900(&local_100);

            }

            if (((*(char *)(param_1 + 600) != '\0') && (*(int *)(param_1 + 0x254) == 0xf0)) ||

               ((*(char *)(param_1 + 0x259) != '\0' &&

                ((DAT_1403ed570 != '\0' || (DAT_1403ed968 != 0)))))) {

              *(undefined8 *)(param_1 + 0x250) = 0xb;

            }

          }

          else if (*(int *)(param_1 + 0x250) == 0xb) {

            if (*(int *)(param_1 + 0x254) == 1) {

              FUN_140027980(&local_100,&DAT_1403078ec);

              FUN_140040ca0(&local_100,0x32,0);

              FUN_140027900(&local_100);

            }

            if (*(int *)(param_1 + 0x254) == 0x10) {

              if (*(char *)(param_1 + 0x2f0) == '\0') {

                FUN_140092150(param_1);

              }

              else if (*(char *)(param_1 + 0x2a5) != '\0') {

                FUN_1400b9220(*(undefined8 *)

                               (*(longlong *)(param_1 + 0x130) +

                               (longlong)*(int *)(param_1 + 0x2ac) * 8));

              }

              uVar33 = (ulonglong)(*(int *)(param_1 + 0x2a8) + 1);

              uVar25 = *(longlong *)(*(longlong *)(param_1 + 0x278) + 0x2a0) -

                       *(longlong *)(*(longlong *)(param_1 + 0x278) + 0x298) >> 4;

              FUN_140092380(param_1);

              if ((((*(int *)(DAT_1403fb0d8 + 0x308) == 0) && (*(char *)(param_1 + 600) == '\0')) &&

                  (*(char *)(param_1 + 0x259) == '\0')) &&

                 ((*(longlong *)(param_1 + 0x278) != 0 && (uVar25 <= uVar33)))) {

                iVar10 = *(int *)(param_1 + 0x268);

                if (0 < iVar10) {

                  uVar25 = (ulonglong)(iVar10 != 1);

                  *(uint *)(param_1 + 0x268) = (uint)(iVar10 != 1);

                  *(undefined4 *)(param_1 + 0x2c4) = *(undefined4 *)(&DAT_14030bac0 + uVar25 * 0xc);

                  *(undefined4 *)(param_1 + 0x2c8) = *(undefined4 *)(&DAT_14030babc + uVar25 * 0xc);

                }

                FUN_14008ff60(param_1,5);

              }

              else {

                if ((*(char *)(param_1 + 0x2a5) != '\0') &&

                   ((*(longlong *)(param_1 + 0x278) != 0 && (uVar25 <= uVar33)))) {

                  lVar22 = *(longlong *)(*(longlong *)(param_1 + 0x278) + 0x298);

                  if ((*(char *)(lVar22 + 10 + (longlong)*(int *)(param_1 + 0x2a8) * 0x10) != '\0')

                     && ((*(char *)(lVar22 + 9 + (longlong)*(int *)(param_1 + 0x2a8) * 0x10) != '\0'

                         || (*(int *)(param_1 + 0x3e0) == 1)))) {

                    FUN_14008ff60(param_1,1);

                    goto LAB_1400975ff;

                  }

                }

                FUN_140027980(&local_100,"StartNextRace");

                FUN_140040ca0(&local_100,100,0);

                FUN_140027900(&local_100);

                FUN_14008ffc0(param_1);

              }

            }

          }

          else if (*(int *)(param_1 + 0x250) == 0xc) {

            if (*(int *)(param_1 + 0x254) == 1) {

              FUN_140027980(&local_100,&DAT_1403078ec);

              FUN_140040ca0(&local_100,0x32,0);

              FUN_140027900(&local_100);

            }

            if (*(int *)(param_1 + 0x254) == 0x10) {

              FUN_140092380(param_1);

              FUN_14008ff60(param_1,1);

            }

          }

          goto LAB_1400975ff;

        }

        if (*(int *)(param_1 + 0x254) == 0x3c) {

          uStack_f8 = 0;

          local_f0 = 6;

          uStack_e8 = 0xf;

          local_100._0_6_ = CONCAT24(s_Racing_1403032a4._4_2_,s_Racing_1403032a4._0_4_);

          local_100 = (char *)(ulonglong)(uint6)local_100;

          FUN_14003f340(&local_100,0);

        }

        if (((*(char *)(param_1 + 600) == '\0') && (*(int *)(param_1 + 0x230) != -1)) &&

           ((*(int *)(param_1 + 0x22c) != -1 && (*(int *)(param_1 + 0x1f8) == 0)))) {

          lVar22 = *(longlong *)

                    (*(longlong *)(param_1 + 0x130) + (longlong)*(int *)(param_1 + 0x230) * 8);

          uVar13 = FUN_140067ad0(&local_100,*(undefined4 *)(lVar22 + 0x284));

          in_stack_fffffffffffffec8 =

               CONCAT44((int)(in_stack_fffffffffffffec8 >> 0x20),DAT_140303758);

          FUN_1400d0c80(param_1,lVar22,uVar13,0,in_stack_fffffffffffffec8);

          FUN_140027900(&local_100);

          *(undefined4 *)(param_1 + 0x22c) = 0xffffffff;

        }

        iVar10 = *(int *)(param_1 + 0x254);

        if (((0xef < iVar10) && (iVar10 == (iVar10 / 0x3c) * 0x3c)) &&

           (iVar10 = FUN_1400c6580(10), iVar10 == 0)) {

          iVar10 = FUN_1400c6580(*(undefined4 *)(param_1 + 0x298));

          lVar22 = (longlong)iVar10 * 0x70;

          if ((*(int *)(lVar22 + 0x14 + *(longlong *)(param_1 + 0x280)) < 300) &&

             (*(int *)(lVar22 + 0xc + *(longlong *)(param_1 + 0x280)) == -1)) {

            FUN_1400985e0(param_1,iVar10);

            lVar22 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)iVar10 * 8);

            uVar11 = FUN_1400c6940();

            *(undefined4 *)(lVar22 + 0x264) = uVar11;

          }

        }

        fVar8 = DAT_14039ca90;

        fVar7 = DAT_14039ca68;

        fVar5 = DAT_14039ca24;

        fVar34 = DAT_14039c9fc;

        uVar27 = _UNK_140304098;

        uVar4 = _DAT_140304090;

        uVar3 = _UNK_140303408;

        uVar14 = _DAT_140303400;

        uVar33 = _UNK_1403033e8;

        uVar13 = _DAT_1403033e0;

        fVar36 = DAT_140303358;

        local_res8 = (undefined8 *)((ulonglong)local_res8 & 0xffffffff00000000);

        iVar32 = 10000;

        iVar12 = 10000;

        local_res10 = 10000;

        iVar10 = *(int *)(param_1 + 0x298);

        uVar29 = uVar25;

        uVar18 = uVar25;

        uVar31 = uVar25;

        iVar20 = 0;

        if (0 < iVar10) {

          do {

            iVar20 = (int)uVar18;

            if ((*(int *)(uVar31 + 0xc + *(longlong *)(param_1 + 0x280)) == -1) ||

               (cVar9 = FUN_1400b4990(*(undefined8 *)(uVar29 + *(longlong *)(param_1 + 0x130))),

               iVar12 = iVar32, cVar9 != '\0')) {

              FUN_140097dd0(param_1,uVar18);

              if (*(int *)(uVar31 + 0x14 + *(longlong *)(param_1 + 0x280)) < 0xb4) {

                piVar1 = (int *)((longlong)iVar20 * 0x70 + 0x10 + *(longlong *)(param_1 + 0x280));

                *piVar1 = *piVar1 + 1;

              }

              fVar35 = (float)FUN_1400b5fe0(*(undefined8 *)

                                             (*(longlong *)(param_1 + 0x130) + (longlong)iVar20 * 8)

                                           );

              if ((fVar8 < fVar35) && (fVar35 < fVar7)) {

                if (*(float *)(param_1 + 0x2f8) <= fVar35) {

                  fVar35 = *(float *)(param_1 + 0x2f8) + fVar34;

                }

                *(float *)(uVar31 + 0x24 + *(longlong *)(param_1 + 0x280)) = fVar35;

              }

              fVar35 = *(float *)(uVar31 + 0x24 + *(longlong *)(param_1 + 0x280));

              if ((fVar37 < fVar35) &&

                 (*(int *)(uVar31 + 0x14 + *(longlong *)(param_1 + 0x280)) < 0xb4)) {

                fVar37 = fVar35;

              }

              if (*(float *)(param_1 + 0x2f8) <= fVar35) {

                iVar10 = *(int *)(param_1 + 0x2fc);

                *(int *)(param_1 + 0x2fc) = iVar10 + 1;

                FUN_1400d1e10(param_1,uVar18,0x1d);

                *(int *)(uVar31 + 0xc + *(longlong *)(param_1 + 0x280)) = iVar10;

                if (iVar10 < 3) {

                  local_118._8_8_ = uVar3;

                  local_118._0_8_ = uVar14;

                  local_128 = (char *)s_CrossFinishLine_1403032b0._0_8_;

                  uStack_120 = (ulonglong)

                               CONCAT16(s_CrossFinishLine_1403032b0[0xe],

                                        CONCAT24(s_CrossFinishLine_1403032b0._12_2_,

                                                 s_CrossFinishLine_1403032b0._8_4_));

                  in_stack_fffffffffffffec8 = in_stack_fffffffffffffec8 & 0xffffffffffffff00;

                  FUN_140040ca0(&local_128,100,0x32,fVar6 - (float)iVar10 * fVar5,

                                in_stack_fffffffffffffec8);

                  FUN_140027900(&local_128);

                }

                FUN_1400b47e0(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + uVar29));

                if (((*(longlong *)(param_1 + 0x378) != *(longlong *)(param_1 + 0x380)) &&

                    (*(longlong *)(uVar29 + *(longlong *)(param_1 + 0x378)) != 0)) &&

                   (iVar12 = FUN_1400c6580(0x14), 0 < iVar12)) {

                  FUN_1400b47e0(*(undefined8 *)(uVar29 + *(longlong *)(param_1 + 0x378)));

                }

                if (iVar10 == 0) {

                  if ((*(int *)(param_1 + 0x2a0) == 5) || (*(int *)(param_1 + 0x2a0) == 6)) {

                    uVar28 = 1;

                  }

                  else {

                    uVar28 = 0;

                  }

                  FUN_140105980(DAT_1403fb0d8,

                                *(undefined8 *)(*(longlong *)(param_1 + 0x130) + uVar29),uVar28);

                }

                if (((*(char *)(param_1 + 600) == '\0') && (*(char *)(param_1 + 0x259) == '\0')) ||

                   (*(int *)(param_1 + 0x2fc) != 1)) {

                  iVar10 = *(int *)(param_1 + 0x2fc);

                  if (*(int *)(param_1 + 700) < iVar10) {

LAB_14009711b:

                    if ((iVar10 == *(int *)(param_1 + 0x298)) &&

                       (*(char *)(param_1 + 0x2e4) == '\0')) {

                      FUN_14003f6f0();

                      local_f0 = uVar4;

                      uStack_e8 = uVar27;

                      local_100 = (char *)0x6563615265736f4c;

                      uStack_f8 = 0;

                      in_stack_fffffffffffffec8 = in_stack_fffffffffffffec8 & 0xffffffffffffff00;

                      FUN_140040ca0(&local_100,100);

                      FUN_140027900(&local_100);

LAB_14009717a:

                      *(undefined1 *)(param_1 + 0x2e4) = 1;

                    }

                  }

                  else if (*(int *)(uVar31 + 8 + *(longlong *)(param_1 + 0x280)) ==

                           *(int *)(uVar31 + 0xc + *(longlong *)(param_1 + 0x280))) {

                    if ((iVar10 != *(int *)(param_1 + 700)) || (*(char *)(param_1 + 0x2e4) != '\0'))

                    goto LAB_14009711b;

                    FUN_1400ca240(param_1,0x1b);

                    FUN_14003f6f0();

                    *(undefined8 *)(param_1 + 0x250) = 9;

                  }

                  else if (*(char *)(param_1 + 0x2e4) == '\0') {

                    FUN_14003f6f0();

                    local_f0 = uVar4;

                    uStack_e8 = uVar27;

                    local_100 = (char *)0x6563615265736f4c;

                    uStack_f8 = 0;

                    in_stack_fffffffffffffec8 = in_stack_fffffffffffffec8 & 0xffffffffffffff00;

                    FUN_140040ca0(&local_100,100,0);

                    if (0xf < uStack_e8) {

                      FUN_140028310(&local_100,local_100);

                    }

                    goto LAB_14009717a;

                  }

                }

                else {

                  lVar22 = DAT_1403edf30 - DAT_1403edf28;

                  *(longlong *)(DAT_1403edf28 + (longlong)DAT_1403edee8 * 8) =

                       (longlong)*(int *)(param_1 + 0x254);

                  iVar10 = (int)(lVar22 >> 3);

                  DAT_1403edee8 = (DAT_1403edee8 + 1) % iVar10;

                  uVar18 = uVar25;

                  uVar26 = uVar25;

                  if (0 < iVar10) {

                    do {

                      uVar18 = uVar18 + *(longlong *)(DAT_1403edf28 + uVar26 * 8);

                      uVar26 = uVar26 + 1;

                    } while ((longlong)uVar26 < (longlong)iVar10);

                  }

                  DAT_1403edee0 = uVar18 / (ulonglong)(longlong)iVar10;

                  *(uint *)(DAT_1403edf08 + ((ulonglong)(longlong)(int)DAT_1403edef0 >> 5) * 4) =

                       *(uint *)(DAT_1403edf08 + ((ulonglong)(longlong)(int)DAT_1403edef0 >> 5) * 4)

                       & ~(1 << (DAT_1403edef0 & 0x1f));

                  DAT_1403edef0 =

                       (uint)((ulonglong)(longlong)(int)(DAT_1403edef0 + 1) % DAT_1403edf20);

                  DAT_1403edeec = 0;

                  uVar18 = uVar25;

                  uVar26 = uVar25;

                  uVar30 = uVar25;

                  if (DAT_1403edf20 != 0) {

                    do {

                      if ((*(uint *)(DAT_1403edf08 + (uVar18 >> 5) * 4) >> ((byte)uVar18 & 0x1f) & 1

                          ) != 0) {

                        DAT_1403edeec = (int)uVar26 + 1;

                        uVar26 = (ulonglong)DAT_1403edeec;

                      }

                      uVar23 = (int)uVar30 + 1;

                      uVar18 = (longlong)(int)uVar23;

                      uVar30 = (ulonglong)uVar23;

                    } while ((ulonglong)(longlong)(int)uVar23 < DAT_1403edf20);

                  }

                  FUN_14003f6f0();

                  uStack_120 = 0;

                  local_118._8_8_ = uVar33;

                  local_118._0_8_ = uVar13;

                  local_128._0_6_ = CONCAT24(s_WonRace_1403032c0._4_2_,s_WonRace_1403032c0._0_4_);

                  local_128._0_7_ = CONCAT16(s_WonRace_1403032c0[6],(uint6)local_128);

                  local_128 = (char *)(ulonglong)(uint7)local_128;

                  in_stack_fffffffffffffec8 = in_stack_fffffffffffffec8 & 0xffffffffffffff00;

                  FUN_140040ca0(&local_128,100);

                  if (0xf < (ulonglong)local_118._8_8_) {

                    if ((0xfff < local_118._8_8_ + 1) &&

                       ((char *)0x1f < local_128 + (-8 - *(longlong *)(local_128 + -8)))) {

                    /* WARNING: Subroutine does not return */

                      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                    }

                    FUN_1402c7088();

                  }

                  *(undefined8 *)(param_1 + 0x250) = 10;

                }

              }

              lVar22 = *(longlong *)(param_1 + 0x280);

              fVar35 = *(float *)(uVar31 + 0x24 + lVar22);

              pfVar19 = (float *)(uVar31 + 0x20 + lVar22);

              if (fVar35 < *pfVar19 || fVar35 == *pfVar19) {

                piVar1 = (int *)(uVar31 + 0x14 + lVar22);

                *piVar1 = *piVar1 + 1;

                if (300 < *(int *)(uVar31 + 0x14 + lVar22)) {

                  lVar22 = *(longlong *)(uVar29 + *(longlong *)(param_1 + 0x130));

                  *(undefined4 *)(lVar22 + 0x260) = *(undefined4 *)(lVar22 + 0x25c);

                  local_res8 = (undefined8 *)CONCAT44(local_res8._4_4_,(int)local_res8 + 1);

                }

              }

              else {

                *(float *)(uVar31 + 0x20 + lVar22) = fVar35 + fVar36;

                *(undefined4 *)(uVar31 + 0x14 + *(longlong *)(param_1 + 0x280)) = 0;

              }

              lVar22 = *(longlong *)(uVar29 + *(longlong *)(param_1 + 0x130));

              if (((*(int *)(lVar22 + 0x270) == 1) && ((*(uint *)(lVar22 + 600) & 0x20000) != 0)) &&

                 (*(char *)(param_1 + 600) == '\0')) {

                uVar23 = *(uint *)(uVar31 + 0x1c + *(longlong *)(param_1 + 0x280));

                if ((uVar23 >> 0x11 & 1) == 0) {

                  *(uint *)(uVar31 + 0x1c + *(longlong *)(param_1 + 0x280)) = uVar23 | 0x20000;

                  FUN_1400b87e0(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + uVar29));

                  FUN_1400d4f50(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x130) + uVar29));

                }

              }

              iVar10 = *(int *)(uVar31 + 0x14 + *(longlong *)(param_1 + 0x280));

              iVar12 = local_res10;

              if (*(int *)(uVar31 + 0x14 + *(longlong *)(param_1 + 0x280)) < local_res10) {

                local_res10 = iVar10;

                iVar12 = iVar10;

              }

            }

            iVar10 = *(int *)(param_1 + 0x298);

            uVar29 = uVar29 + 8;

            uVar18 = (ulonglong)(iVar20 + 1U);

            uVar31 = uVar31 + 0x70;

            iVar32 = iVar12;

          } while ((int)(iVar20 + 1U) < iVar10);

          fVar35 = DAT_140303354;

          iVar20 = (int)local_res8;

        }

        fVar36 = (fVar37 * DAT_14030338c + DAT_140304014) * DAT_140304014;

        if (*(char *)(param_1 + 600) != '\0') {

          if (iVar20 == iVar10) {

            if (fVar36 < (float)*(int *)(param_1 + 0x254)) goto LAB_1400972d4;

          }

          else {

            if ((float)*(int *)(param_1 + 0x254) <= fVar36) goto LAB_140097395;

LAB_1400972d4:

            if (DAT_1403d9528 != '\0') {

              DAT_1403edf88 = DAT_1403edf88 + 1;

              FUN_1400c4320("TV Time Out %d");

            }

            FUN_1400924b0(param_1);

          }

          *(uint *)(DAT_1403edf08 + ((ulonglong)(longlong)(int)DAT_1403edef0 >> 5) * 4) =

               *(uint *)(DAT_1403edf08 + ((ulonglong)(longlong)(int)DAT_1403edef0 >> 5) * 4) |

               1 << (DAT_1403edef0 & 0x1f);

          DAT_1403edef0 = (uint)((ulonglong)(longlong)(int)(DAT_1403edef0 + 1) % DAT_1403edf20);

          DAT_1403edeec = 0;

          uVar33 = uVar25;

          uVar29 = uVar25;

          uVar18 = uVar25;

          if (DAT_1403edf20 != 0) {

            do {

              if ((*(uint *)(DAT_1403edf08 + (uVar33 >> 5) * 4) >> ((byte)uVar33 & 0x1f) & 1) != 0)

              {

                DAT_1403edeec = (int)uVar29 + 1;

                uVar29 = (ulonglong)DAT_1403edeec;

              }

              uVar23 = (int)uVar18 + 1;

              uVar33 = (longlong)(int)uVar23;

              uVar18 = (ulonglong)uVar23;

            } while ((ulonglong)(longlong)(int)uVar23 < DAT_1403edf20);

          }

          *(undefined8 *)(param_1 + 0x250) = 10;

        }

LAB_140097395:

        fVar36 = DAT_14030c2b0;

        if (((iVar20 == *(int *)(param_1 + 0x298)) && (899 < iVar12)) &&

           ((*(int *)(param_1 + 0x2fc) == 0 && (*(char *)(param_1 + 0x2e4) == '\0')))) {

          uVar29 = 1;

          uVar33 = uVar25;

          if (0 < *(int *)(param_1 + 700)) {

            do {

              if ((char)uVar29 == '\0') goto LAB_140097485;

              uVar18 = 0xffffffff;

              uVar31 = 0xffffffffffffffff;

              iVar10 = (int)uVar33;

              if (0 < *(int *)(param_1 + 0x298)) {

                pfVar19 = (float *)(*(longlong *)(param_1 + 0x280) + 0x24);

                uVar33 = uVar25;

                uVar26 = uVar25;

                fVar34 = fVar36;

                do {

                  if ((pfVar19[-6] == -NAN) && (fVar34 < *pfVar19)) {

                    uVar18 = uVar33;

                    uVar31 = uVar26;

                    fVar34 = *pfVar19;

                  }

                  uVar23 = (int)uVar33 + 1;

                  uVar33 = (ulonglong)uVar23;

                  uVar26 = uVar26 + 1;

                  pfVar19 = pfVar19 + 0x1c;

                } while ((int)uVar23 < *(int *)(param_1 + 0x298));

                if ((int)uVar18 != -1) {

                  *(int *)(*(longlong *)(param_1 + 0x280) + 0xc + uVar31 * 0x70) = iVar10;

                  FUN_1400c4320("flip win %d");

                  if (*(int *)(*(longlong *)(param_1 + 0x280) + 8 + uVar31 * 0x70) != iVar10) {

                    uVar29 = uVar25;

                  }

                }

              }

              uVar33 = (ulonglong)(iVar10 + 1U);

            } while ((int)(iVar10 + 1U) < *(int *)(param_1 + 700));

            if ((char)uVar29 == '\0') {

LAB_140097485:

              *(undefined1 *)(param_1 + 0x2e4) = 1;

              goto LAB_1400974ae;

            }

          }

          FUN_1400ca240(param_1,0x1b);

          FUN_14003f6f0();

          *(undefined8 *)(param_1 + 0x250) = 9;

        }

LAB_1400974ae:

        if ((*(int *)(param_1 + 0xe0) == 0x1b) ||

           (fVar36 = DAT_1403033cc, *(char *)(param_1 + 0x2e5) != '\0')) {

          FUN_1400ca240(param_1,0x1b);

          uStack_f8 = 0;

          local_f0 = _DAT_140305680;

          uStack_e8 = _UNK_140305688;

          local_100 = (char *)0x72616554;

          FUN_140040ca0(&local_100,100);

          if (0xf < uStack_e8) {

            if ((0xfff < uStack_e8 + 1) &&

               ((char *)0x1f < local_100 + (-8 - *(longlong *)(local_100 + -8)))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          if (*(char *)(param_1 + 0x2e4) == '\0') {

            *(undefined1 *)(param_1 + 0x2e4) = 1;

            FUN_14003f6f0();

            local_f0 = uVar4;

            uStack_e8 = uVar27;

            local_100 = (char *)0x6563615265736f4c;

            uStack_f8 = 0;

            FUN_140040ca0(&local_100,100,0);

            FUN_140027900(&local_100);

          }

          *(undefined1 *)(param_1 + 0x2e5) = 1;

          FUN_140094540(param_1);

          if (*(int *)(param_1 + 0x2fc) == 0) {

            if (*(int *)(param_1 + 0x254) < 0xb4) {

              *(undefined1 *)(param_1 + 0x2f0) = 1;

            }

            else {

              FUN_1400924b0(param_1);

            }

          }

          *(undefined4 *)(param_1 + 0x250) = 0xb;

          *(undefined4 *)(param_1 + 0x254) = 0xffffffc4;

          fVar36 = DAT_1403033cc;

        }

        goto LAB_1400975ff;

      }

      if (*(int *)(param_1 + 0x254) != 0xf0) goto LAB_1400975ff;

      iVar10 = *(int *)(param_1 + 0x298);

    }

    if (iVar10 < 1) {

      FUN_140092150(param_1);

      FUN_140092380(param_1);

      FUN_14008ffc0(param_1);

      goto LAB_1400975ff;

    }

  }

  *(undefined8 *)(param_1 + 0x250) = 7;

  *(undefined4 *)(param_1 + 0x2ec) = 0;

LAB_1400975ff:

  if ((*(int *)(param_1 + 0x250) == 8) || (*(int *)(param_1 + 0x250) == 9)) {

    fVar37 = (fVar37 - *(float *)(param_1 + 0x118)) + DAT_140303398;

    if ((DAT_1403ed6a0 == '\0') && (DAT_1403ed654 == '\0')) {

      if ((DAT_1403ed69f != '\0') || (DAT_1403ed657 != '\0')) {

        fVar36 = (*(float *)(param_1 + 0x2f8) - *(float *)(param_1 + 0x118)) + DAT_140303398;

        fVar35 = *(float *)(param_1 + 0x10c) + fVar35;

        if (fVar35 <= fVar36) {

          fVar36 = fVar35;

        }

        *(float *)(param_1 + 0x10c) = fVar36;

        *(bool *)(param_1 + 0x2b1) = fVar36 < fVar37 - fVar6;

      }

    }

    else {

      fVar35 = *(float *)(param_1 + 0x10c) - fVar35;

      if (fVar36 <= fVar35) {

        fVar36 = fVar35;

      }

      *(float *)(param_1 + 0x10c) = fVar36;

      *(undefined1 *)(param_1 + 0x2b1) = 1;

    }

    if (*(char *)(param_1 + 0x2b1) == '\0') {

      fVar35 = DAT_14039ca34;

      if (*(int *)(param_1 + 0x2fc) < 1) {

        fVar35 = 0.0;

      }

      if (*(float *)(param_1 + 0x10c) < fVar37 - fVar35) {

        uVar11 = FUN_1400c5f70(*(float *)(param_1 + 0x10c) * DAT_14039ca3c + fVar37 * _DAT_14030334c

                               + _DAT_140303348);

        *(undefined4 *)(param_1 + 0x10c) = uVar11;

      }

    }

  }

  return;

}




