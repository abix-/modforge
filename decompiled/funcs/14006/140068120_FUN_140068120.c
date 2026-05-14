// Address: 0x140068120
// Ghidra name: FUN_140068120
// ============ 0x140068120 FUN_140068120 (size=1759) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140068120(longlong param_1)



{

  int *piVar1;

  float fVar2;

  float fVar3;

  longlong *plVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  longlong *plVar8;

  longlong *plVar9;

  longlong lVar10;

  uint uVar11;

  longlong *plVar12;

  ulonglong uVar13;

  float *pfVar14;

  longlong lVar15;

  longlong *plVar16;

  float fVar17;

  undefined4 uVar18;

  undefined4 uVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  longlong local_res8;

  longlong *local_res10;

  ulonglong in_stack_fffffffffffffe28;

  longlong *local_1c8;

  longlong *plStack_1c0;

  longlong *local_1b8;

  longlong local_1b0;

  undefined8 uStack_1a8;

  undefined8 local_1a0;

  ulonglong uStack_198;

  float local_188 [84];

  

  FUN_1400d0a00(param_1,0);

  FUN_1400cd5a0(param_1,1);

  local_1c8 = (longlong *)0x0;

  plStack_1c0 = (longlong *)0x0;

  plVar9 = (longlong *)0x0;

  local_1b8 = (longlong *)0x0;

  plVar16 = *(longlong **)(param_1 + 0x130);

  local_res10 = *(longlong **)(param_1 + 0x138);

  if (plVar16 != local_res10) {

    plVar12 = (longlong *)0x0;

    plVar4 = (longlong *)0x0;

    do {

      lVar10 = *plVar16;

      if (*(int *)(lVar10 + 0x1dc) == *(int *)(param_1 + 0x120) + -1) {

        if (plVar12 == plVar9) {

          lVar15 = (longlong)plVar12 - (longlong)plVar4 >> 3;

          if (lVar15 == 0x1fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

            FUN_14002f0d0();

          }

          uVar13 = lVar15 + 1;

          uVar7 = (longlong)plVar9 - (longlong)plVar4 >> 3;

          if (0x1fffffffffffffff - (uVar7 >> 1) < uVar7) {

            uVar6 = 0x1fffffffffffffff;

          }

          else {

            uVar7 = (uVar7 >> 1) + uVar7;

            uVar6 = uVar13;

            if (uVar13 <= uVar7) {

              uVar6 = uVar7;

            }

            if (0x1fffffffffffffff < uVar6) {

                    /* WARNING: Subroutine does not return */

              FUN_140024090();

            }

          }

          local_res8 = uVar6 * 8;

          plVar4 = (longlong *)FUN_1400285e0(local_res8);

          plVar4[lVar15] = lVar10;

          plVar9 = plVar4;

          plVar8 = local_1c8;

          if (plVar12 != plStack_1c0) {

            FUN_1402f8e20(plVar4,local_1c8,(longlong)plVar12 - (longlong)local_1c8);

            plVar9 = plVar4 + lVar15 + 1;

            plVar8 = plVar12;

          }

          FUN_1402f8e20(plVar9,plVar8);

          if (local_1c8 != (longlong *)0x0) {

            if ((0xfff < ((longlong)local_1b8 - (longlong)local_1c8 & 0xfffffffffffffff8U)) &&

               (0x1f < (ulonglong)((longlong)local_1c8 + (-8 - local_1c8[-1])))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          plVar12 = plVar4 + uVar13;

          plVar9 = (longlong *)(local_res8 + (longlong)plVar4);

          local_1c8 = plVar4;

          plStack_1c0 = plVar12;

          local_1b8 = plVar9;

        }

        else {

          *plVar12 = lVar10;

          plVar12 = plStack_1c0 + 1;

          plVar9 = local_1b8;

          plVar4 = local_1c8;

          plStack_1c0 = plVar12;

        }

      }

      plVar16 = plVar16 + 1;

    } while (plVar16 != local_res10);

  }

  uVar13 = 0;

  FUN_1400ce540(param_1,plVar9,0);

  for (plVar16 = local_1c8; plVar16 != plStack_1c0; plVar16 = plVar16 + 1) {

    lVar10 = *plVar16;

    FUN_1400b6610(lVar10,&DAT_1403d9178);

    FUN_1400b6990(lVar10,*(int *)(param_1 + 0x120) + -1,0);

    *(undefined4 *)(lVar10 + 0x1cc) = 0xffffffff;

    FUN_1400b7fe0(lVar10,0);

  }

  uVar5 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),DAT_1403d9178,0);

  *(undefined8 *)(param_1 + 600) = uVar5;

  fVar3 = DAT_14039ca54;

  fVar21 = DAT_140309c20;

  fVar20 = DAT_140309bf0;

  fVar2 = DAT_140303fb4;

  pfVar14 = local_188 + 1;

  uVar7 = uVar13;

  do {

    fVar22 = (float)(int)uVar7 * fVar3 * fVar2;

    fVar17 = (float)FUN_1402cfda0(fVar22);

    pfVar14[-1] = fVar17 * fVar20;

    fVar17 = (float)FUN_1402cdc50(fVar22);

    *pfVar14 = fVar17 * fVar21;

    uVar11 = (int)uVar7 + 1;

    uVar7 = (ulonglong)uVar11;

    pfVar14 = pfVar14 + 2;

  } while ((int)uVar11 < 0x20);

  in_stack_fffffffffffffe28 = in_stack_fffffffffffffe28 & 0xffffffff00000000;

  uVar5 = FUN_140083b50(uVar5,local_188,0x20,DAT_140309be4,in_stack_fffffffffffffe28,1);

  *(undefined8 *)(param_1 + 0x260) = uVar5;

  fVar2 = DAT_14039ca44;

  uVar11 = 0;

  uVar7 = CONCAT44((int)(in_stack_fffffffffffffe28 >> 0x20),DAT_14039ca44);

  uVar5 = FUN_140083770(*(undefined8 *)(param_1 + 600),DAT_1403ffbe8,fVar20,DAT_1403069d4,uVar7,0);

  FUN_1400845c0(*(undefined8 *)(param_1 + 0x260),*(int *)(param_1 + 0x120) + -1,1);

  FUN_1400845c0(uVar5,0,0);

  *(undefined8 *)(*(longlong *)(param_1 + 0x260) + 0x40) = 999;

  FUN_140083c30(*(undefined8 *)(param_1 + 0xa0),*(undefined8 *)(param_1 + 600),DAT_1403d9178,0,

                uVar7 & 0xffffffff00000000,uVar11 & 0xffffff00);

  *(undefined4 *)(*(longlong *)(param_1 + 600) + 0xa4) = 0x3e051eb8;

  if ((*(char *)(param_1 + 0x270) != '\0') &&

     (lVar10 = *(longlong *)(param_1 + 0xb8), uVar7 = uVar13,

     *(longlong *)(param_1 + 0xc0) - lVar10 >> 3 != 0)) {

    do {

      if (*(int *)(*(longlong *)(uVar13 + lVar10) + 0xc) == 5) {

        local_res8 = *(longlong *)(*(longlong *)(uVar13 + lVar10) + 0x28);

        FUN_1400c5740(&local_res8,*(undefined8 *)(param_1 + 0x78),0);

      }

      uVar11 = (int)uVar7 + 1;

      uVar13 = uVar13 + 8;

      lVar10 = *(longlong *)(param_1 + 0xb8);

      uVar7 = (ulonglong)uVar11;

    } while ((ulonglong)(longlong)(int)uVar11 <

             (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar10 >> 3));

  }

  if (*(int *)(param_1 + 0x284) < *(int *)(DAT_1403fb0d8 + 0x314)) {

    uVar18 = FUN_1400c6940(DAT_1403033a0);

    uVar19 = FUN_1400c6940(DAT_140304bf0);

    FUN_1400cc9d0(param_1,5,uVar19,uVar18);

    *(undefined4 *)(param_1 + 0x284) = *(undefined4 *)(DAT_1403fb0d8 + 0x314);

  }

  if (DAT_140309bfc <= (float)((uint)*(float *)(param_1 + 0x268) & _DAT_14039cab0)) {

    if (local_1c8 != plStack_1c0) {

      fVar20 = DAT_1403d90d0;

      if (*(float *)(param_1 + 0x268) <= 0.0) {

        fVar20 = (float)((uint)DAT_1403d90d0 ^ DAT_14039cac0);

      }

      *(float *)(param_1 + 0x268) = fVar20;

      fVar21 = DAT_14039ca80;

      if (0.0 < fVar20) {

        fVar21 = fVar2;

      }

      fVar21 = fVar21 * _DAT_140309bdc;

      piVar1 = *(int **)(param_1 + 600);

      if (*piVar1 != 0) {

        if ((0.0 < fVar21 * fVar21) && ((*(ushort *)(piVar1 + 1) & 2) == 0)) {

          *(ushort *)(piVar1 + 1) = *(ushort *)(piVar1 + 1) | 2;

          piVar1[0x2b] = 0;

        }

        piVar1[0x12] = (int)fVar21;

      }

    }

  }

  else {

    *(undefined4 *)(param_1 + 0x268) = 0;

    *(undefined1 *)(param_1 + 0x270) = 0;

  }

  local_1a0 = _DAT_140304cc0;

  uStack_198 = _UNK_140304cc8;

  local_1b0._0_1_ = s_TurbineSpin_140309a90[0];

  local_1b0._1_1_ = s_TurbineSpin_140309a90[1];

  local_1b0._2_1_ = s_TurbineSpin_140309a90[2];

  local_1b0._3_1_ = s_TurbineSpin_140309a90[3];

  local_1b0._4_1_ = s_TurbineSpin_140309a90[4];

  local_1b0._5_1_ = s_TurbineSpin_140309a90[5];

  local_1b0._6_1_ = s_TurbineSpin_140309a90[6];

  local_1b0._7_1_ = s_TurbineSpin_140309a90[7];

  uStack_1a8 = (ulonglong)CONCAT12(s_TurbineSpin_140309a90[10],s_TurbineSpin_140309a90._8_2_);

  uVar18 = FUN_140040ca0(&local_1b0,0,0,fVar2,1);

  *(undefined4 *)(param_1 + 0x278) = uVar18;

  if (0xf < uStack_198) {

    if ((0xfff < uStack_198 + 1) && (0x1f < (local_1b0 - *(longlong *)(local_1b0 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  *(undefined4 *)(param_1 + 0x26c) = 0;

  *(undefined4 *)(param_1 + 0x27c) = 0;

  *(undefined1 *)(param_1 + 0x280) = 0;

  *(undefined4 *)(param_1 + 0x250) = 0;

  if (local_1c8 != (longlong *)0x0) {

    if ((0xfff < ((longlong)local_1b8 - (longlong)local_1c8 & 0xfffffffffffffff8U)) &&

       (0x1f < (ulonglong)((longlong)local_1c8 + (-8 - local_1c8[-1])))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return 1;

}




