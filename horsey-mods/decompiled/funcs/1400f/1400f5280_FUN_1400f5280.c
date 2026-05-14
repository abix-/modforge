// Address: 0x1400f5280
// Ghidra name: FUN_1400f5280
// ============ 0x1400f5280 FUN_1400f5280 (size=3288) ============


/* WARNING: Removing unreachable block (ram,0x0001400f5849) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400f5280(longlong param_1)



{

  int *piVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  float fVar4;

  float fVar5;

  char cVar6;

  int iVar7;

  int iVar8;

  undefined4 uVar9;

  undefined8 uVar10;

  longlong lVar11;

  ulonglong uVar12;

  longlong *plVar13;

  undefined8 *puVar14;

  int iVar15;

  ulonglong uVar16;

  ulonglong uVar17;

  longlong lVar18;

  uint uVar19;

  longlong lVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  undefined8 local_res8;

  undefined4 local_res10;

  undefined4 local_res14;

  ulonglong local_res18;

  longlong local_res20;

  undefined8 in_stack_fffffffffffffd18;

  undefined8 uVar25;

  longlong local_2c8;

  int *piStack_2c0;

  int *local_2b8;

  undefined8 local_2b0;

  undefined8 uStack_2a8;

  undefined8 local_2a0;

  ulonglong uStack_298;

  undefined1 local_288 [210];

  undefined1 local_1b6;

  undefined1 local_1b0;

  undefined1 local_c0;

  

  FUN_1400cd5a0(param_1,0 < *(int *)(param_1 + 0x260));

  uVar9 = (undefined4)((ulonglong)in_stack_fffffffffffffd18 >> 0x20);

  uVar17 = 0;

  *(longlong *)(param_1 + 600) = 0;

  fVar5 = DAT_14039ca58;

  fVar4 = DAT_14039ca34;

  iVar15 = 0;

  lVar18 = *(longlong *)(param_1 + 0x130);

  uVar12 = uVar17;

  uVar16 = uVar17;

  fVar21 = DAT_14030dc08;

  if (*(longlong *)(param_1 + 0x138) - lVar18 >> 3 != 0) {

    do {

      lVar18 = *(longlong *)(uVar12 + lVar18);

      if (lVar18 != *(longlong *)(param_1 + 0x148)) {

        FUN_1400b4a10(lVar18,&local_res8);

        lVar20 = *(longlong *)(param_1 + 0x78);

        if (local_res8._4_4_ < *(float *)(lVar20 + 0x2c) + *(float *)(lVar20 + 0x24)) {

          fVar24 = fVar5;

          if (*(int *)(lVar18 + 0x1c) == 3) {

            fVar24 = 0.0;

          }

        }

        else {

          if (*(int *)(lVar18 + 0x1c) != 3) goto LAB_1400f53dc;

          fVar24 = 0.0;

        }

        fVar23 = local_res8._4_4_ - (*(float *)(lVar20 + 0x2c) * fVar4 + *(float *)(lVar20 + 0x24));

        fVar22 = (float)local_res8 - (*(float *)(lVar20 + 0x28) * fVar4 + *(float *)(lVar20 + 0x20))

        ;

        fVar22 = fVar22 * fVar22 + fVar23 * fVar23;

        if (fVar22 < 0.0) {

          fVar22 = (float)FUN_1402cdfa0(fVar22);

        }

        else {

          fVar22 = SQRT(fVar22);

        }

        if (fVar22 + fVar24 < fVar21) {

          *(longlong *)(param_1 + 600) = lVar18;

          fVar21 = fVar22 + fVar24;

        }

      }

LAB_1400f53dc:

      uVar9 = (undefined4)((ulonglong)in_stack_fffffffffffffd18 >> 0x20);

      uVar19 = (int)uVar16 + 1;

      lVar18 = *(longlong *)(param_1 + 0x130);

      uVar12 = uVar12 + 8;

      uVar16 = (ulonglong)uVar19;

    } while ((ulonglong)(longlong)(int)uVar19 <

             (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar18 >> 3));

  }

  plVar13 = (longlong *)(param_1 + 600);

  if (*plVar13 != 0) {

    *(undefined1 *)(*plVar13 + 0x1a) = 1;

    *(uint *)(*plVar13 + 600) = *(uint *)(*plVar13 + 600) | 1;

    FUN_1400b6820(*plVar13,lVar18,DAT_140303394);

  }

  FUN_1400d0a00(param_1,0);

  FUN_1400ce540(param_1);

  lVar18 = *(longlong *)(param_1 + 0x78);

  uVar10 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),

                         CONCAT44(*(float *)(lVar18 + 0x2c) + *(float *)(lVar18 + 0x24),

                                  *(undefined4 *)(lVar18 + 0x20)),1);

  fVar5 = DAT_14039ca44;

  uVar19 = DAT_140304c88;

  uVar3 = DAT_14030374c;

  uVar2 = DAT_14030335c;

  uVar25 = CONCAT44(uVar9,DAT_14039ca44);

  FUN_140083480(uVar10,(ulonglong)DAT_140304c88 << 0x20,CONCAT44(DAT_14030374c,DAT_14030335c),0,

                uVar25,DAT_14039ca44,0);

  uVar25 = CONCAT44((int)((ulonglong)uVar25 >> 0x20),fVar5);

  FUN_140083480(uVar10,CONCAT44(uVar19,(float)((double)*(float *)(*(longlong *)(param_1 + 0x78) +

                                                                 0x28) - _DAT_140304b60)),

                CONCAT44(uVar3,uVar2),0,uVar25,fVar5,0);

  uVar25 = CONCAT44((int)((ulonglong)uVar25 >> 0x20),fVar5);

  FUN_140083480(uVar10,(ulonglong)DAT_14039ca80 << 0x20,

                CONCAT44(fVar5,*(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0x28)),0,uVar25,fVar5

                ,0);

  uVar9 = (undefined4)((ulonglong)uVar25 >> 0x20);

  FUN_140084570(uVar10,*(undefined4 *)(param_1 + 0x120),1);

  uVar10 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),CONCAT44(DAT_140304bf4,DAT_140304c5c),1);

  uVar25 = CONCAT44(uVar9,fVar5);

  FUN_140083480(uVar10,0,CONCAT44(uVar3,uVar2),0,uVar25,fVar5,0);

  if (*(longlong *)(param_1 + 0x148) != 0) {

    FUN_140084570(uVar10,*(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0x1dc));

  }

  lVar18 = *plVar13;

  if (lVar18 != 0) {

    fVar21 = *(float *)(lVar18 + 0x158) * DAT_140303390;

    piVar1 = *(int **)(*(longlong *)(lVar18 + 0x40) + 0x30);

    if (*piVar1 == 2) {

      if ((*(ushort *)(piVar1 + 1) & 2) == 0) {

        *(ushort *)(piVar1 + 1) = *(ushort *)(piVar1 + 1) | 2;

        piVar1[0x2b] = 0;

      }

      piVar1[0x12] = (int)(fVar21 * (float)piVar1[0x27] + (float)piVar1[0x12]);

    }

  }

  lVar18 = *(longlong *)(param_1 + 600);

  if ((((lVar18 != 0) && (*(int *)(lVar18 + 0x1c) != 3)) ||

      (iVar7 = *(int *)(param_1 + 0x260), iVar7 == 7)) || (iVar7 == 8)) {

    iVar7 = 5;

    *(undefined4 *)(param_1 + 0x260) = 5;

  }

  *(undefined4 *)(param_1 + 0x270) = 0;

  *(undefined1 *)(param_1 + 0x274) = 0;

  local_res8 = (ulonglong)(uint)local_res8._4_4_ << 0x20;

  local_2c8 = 0;

  piStack_2c0 = (int *)0x0;

  local_2b8 = (int *)0x0;

  if ((lVar18 != 0) && (iVar7 == 1)) {

    lVar18 = *(longlong *)(param_1 + 0xb8);

    if (*(longlong *)(param_1 + 0xc0) - lVar18 >> 3 == 0) {

LAB_1400f5b9c:

      if ((*(int *)(param_1 + 0x270) < 100) ||

         ((ulonglong)((longlong)piStack_2c0 - local_2c8 >> 2) < 3)) {

        *(undefined4 *)(param_1 + 0x270) = 0;

      }

      else {

        uVar16 = 0;

        uVar12 = uVar16;

        do {

          *(undefined1 *)

           (*(longlong *)

             (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(uVar12 + local_2c8) * 8) + 0x11) =

               1;

          uVar19 = (int)uVar16 + 1;

          uVar16 = (ulonglong)uVar19;

          uVar12 = uVar12 + 4;

        } while ((ulonglong)(longlong)(int)uVar19 <

                 (ulonglong)((longlong)piStack_2c0 - local_2c8 >> 2));

        FUN_1400cce00(param_1);

      }

    }

    else {

      lVar20 = 0;

      uVar12 = uVar17;

      uVar16 = uVar17;

      do {

        iVar7 = (int)uVar17;

        if (*(int *)(*(longlong *)(lVar20 + lVar18) + 8) == 3) {

          if ((*(int *)(param_1 + 0x278) == 0) &&

             (*(int *)(*(longlong *)(lVar20 + lVar18) + 0xc) == 9)) {

            *(undefined4 *)(param_1 + 0x278) = 1;

          }

          lVar11 = *(longlong *)(param_1 + 0x78);

          local_2b0 = CONCAT44(*(float *)(lVar11 + 0x34) - fVar4,*(float *)(lVar11 + 0x30) - fVar4);

          uStack_2a8 = CONCAT44(*(float *)(lVar11 + 0x3c) + fVar5,*(float *)(lVar11 + 0x38) + fVar5)

          ;

          local_res14 = *(undefined4 *)(*(longlong *)(lVar20 + lVar18) + 0x2c);

          local_res10 = *(undefined4 *)(*(longlong *)(lVar20 + lVar18) + 0x28);

          cVar6 = FUN_1400c5740(&local_res10,&local_2b0,0);

          if (cVar6 != '\0') {

            if (piStack_2c0 == local_2b8) {

              lVar18 = (longlong)piStack_2c0 - local_2c8 >> 2;

              if (lVar18 == 0x3fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

                FUN_14002f0d0();

              }

              local_res18 = lVar18 + 1;

              uVar16 = (longlong)local_2b8 - local_2c8 >> 2;

              if (0x3fffffffffffffff - (uVar16 >> 1) < uVar16) {

                uVar17 = 0x3fffffffffffffff;

              }

              else {

                uVar16 = uVar16 + (uVar16 >> 1);

                uVar17 = local_res18;

                if (local_res18 <= uVar16) {

                  uVar17 = uVar16;

                }

                if (0x3fffffffffffffff < uVar17) {

                    /* WARNING: Subroutine does not return */

                  FUN_140024090();

                }

              }

              local_res20 = uVar17 * 4;

              lVar11 = FUN_1400285e0(local_res20);

              *(int *)(lVar11 + lVar18 * 4) = iVar7;

              FUN_1402f8e20(lVar11,local_2c8);

              if (local_2c8 != 0) {

                if ((0xfff < ((longlong)local_2b8 - local_2c8 & 0xfffffffffffffffcU)) &&

                   (0x1f < (local_2c8 - *(longlong *)(local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                }

                FUN_1402c7088();

              }

              piStack_2c0 = (int *)(lVar11 + local_res18 * 4);

              local_2b8 = (int *)(local_res20 + lVar11);

              uVar16 = local_res8 & 0xffffffff;

              local_2c8 = lVar11;

            }

            else {

              *piStack_2c0 = iVar7;

              piStack_2c0 = piStack_2c0 + 1;

            }

            iVar15 = *(int *)(param_1 + 0x270);

            iVar8 = FUN_14005e230(*(undefined4 *)

                                   (*(longlong *)(lVar20 + *(longlong *)(param_1 + 0xb8)) + 0xc));

            *(int *)(param_1 + 0x270) = iVar8 + iVar15;

            iVar15 = *(int *)(*(longlong *)(lVar20 + *(longlong *)(param_1 + 0xb8)) + 0xc);

            if (iVar15 == 9) {

              uVar19 = (int)uVar16 + 1;

              uVar16 = (ulonglong)uVar19;

              local_res8 = CONCAT44(local_res8._4_4_,uVar19);

            }

            else {

              if (iVar15 - 0x13U < 4) {

                uVar12 = (ulonglong)((int)uVar12 + 1);

              }

              if (iVar15 == 0xc) {

                uVar12 = (ulonglong)((int)uVar12 + 2);

              }

            }

          }

        }

        uVar9 = (undefined4)((ulonglong)uVar25 >> 0x20);

        iVar15 = (int)uVar16;

        uVar17 = (ulonglong)(iVar7 + 1U);

        lVar20 = lVar20 + 8;

        lVar18 = *(longlong *)(param_1 + 0xb8);

      } while ((ulonglong)(longlong)(int)(iVar7 + 1U) <

               (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar18 >> 3));

      if ((int)uVar12 < 5) goto LAB_1400f5b9c;

      uVar12 = 0;

      if ((longlong)piStack_2c0 - local_2c8 >> 2 != 0) {

        lVar20 = 0;

        uVar16 = uVar12;

        do {

          lVar11 = *(longlong *)(lVar18 + (longlong)*(int *)(lVar20 + local_2c8) * 8);

          iVar7 = *(int *)(lVar11 + 0xc);

          if (((0x12 < iVar7) && (iVar7 < 0x17)) || (iVar7 == 0xc)) {

            *(undefined1 *)(lVar11 + 0x11) = 1;

            lVar18 = *(longlong *)(param_1 + 0xb8);

          }

          uVar19 = (int)uVar16 + 1;

          uVar16 = (ulonglong)uVar19;

          lVar20 = lVar20 + 4;

        } while ((ulonglong)(longlong)(int)uVar19 <

                 (ulonglong)((longlong)piStack_2c0 - local_2c8 >> 2));

      }

      FUN_1400cce00(param_1);

      local_res8 = FUN_1402c704c(0x498);

      if (local_res8 != 0) {

        uVar12 = FUN_1400aac60(local_res8);

      }

      uStack_2a8 = 0;

      local_2a0 = _DAT_140304080;

      uStack_298 = _UNK_140304088;

      local_2b0._0_5_ = CONCAT14(s_freak_140303b30[4],s_freak_140303b30._0_4_);

      local_2b0 = (ulonglong)(uint5)local_2b0;

      local_res8 = uVar12;

      FUN_1400b2ee0(uVar12,&local_2b0);

      if (0xf < uStack_298) {

        if ((0xfff < uStack_298 + 1) && (0x1f < (local_2b0 - *(longlong *)(local_2b0 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      uVar9 = FUN_1400c7600(0,4,0xffffffff,0xffffffff,CONCAT44(uVar9,0xffffffff));

      *(undefined4 *)(uVar12 + 0x1f8) = uVar9;

      local_2a0 = _DAT_1403033f0;

      uStack_298 = _UNK_1403033f8;

      local_2b0._0_1_ = s_Experiment_140312670[0];

      local_2b0._1_1_ = s_Experiment_140312670[1];

      local_2b0._2_1_ = s_Experiment_140312670[2];

      local_2b0._3_1_ = s_Experiment_140312670[3];

      local_2b0._4_1_ = s_Experiment_140312670[4];

      local_2b0._5_1_ = s_Experiment_140312670[5];

      local_2b0._6_1_ = s_Experiment_140312670[6];

      local_2b0._7_1_ = s_Experiment_140312670[7];

      uStack_2a8 = (ulonglong)(ushort)s_Experiment_140312670._8_2_;

      FUN_1400cf950(param_1,uVar12);

      if (0xf < uStack_298) {

        if ((0xfff < uStack_298 + 1) && (0x1f < (local_2b0 - *(longlong *)(local_2b0 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      *(undefined1 *)(uVar12 + 0x204) = 1;

      FUN_1400b6820(uVar12);

      if (*(ulonglong **)(param_1 + 0x138) == *(ulonglong **)(param_1 + 0x140)) {

        FUN_140030680();

      }

      else {

        **(ulonglong **)(param_1 + 0x138) = uVar12;

        *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

      }

      FUN_1400cead0(param_1,uVar12);

      FUN_1400b87e0(uVar12);

      *(undefined1 *)(param_1 + 0x274) = 1;

    }

    if ((0 < iVar15) && (0 < (int)(*(float *)(param_1 + 0x10) * DAT_140303fb4 - fVar5))) {

      FUN_140101120(DAT_1403fb0d8,(int)(*(float *)(param_1 + 0xc) * DAT_140303fb4));

    }

  }

  if (*(int *)(param_1 + 0x260) != 0) goto LAB_1400f5e15;

  plVar13 = (longlong *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    plVar13 = DAT_1403d9530;

  }

  if (DAT_1403d9540 == 9) {

    lVar18 = *plVar13 + -0x656e6f4d65727543;

    if (lVar18 == 0) {

      lVar18 = (ulonglong)*(byte *)(plVar13 + 1) - 0x79;

    }

    if (lVar18 != 0) goto LAB_1400f5cd1;

    *(int *)(DAT_1403fb0d8 + 0x308) = *(int *)(DAT_1403fb0d8 + 0x308) + 0xf3a7;

  }

  else {

LAB_1400f5cd1:

    plVar13 = (longlong *)&DAT_1403d9530;

    if (0xf < DAT_1403d9548) {

      plVar13 = DAT_1403d9530;

    }

    if ((DAT_1403d9540 == 8) && (*plVar13 == 0x6c61695665727543)) {

      uVar10 = FUN_1400cc9d0(param_1,0xc,DAT_140303750,DAT_14030339c);

      uStack_2a8 = 0;

      local_2a0 = _DAT_140304080;

      uStack_298 = _UNK_140304088;

      local_2b0._0_5_ = CONCAT14(s_freak_140303b30[4],s_freak_140303b30._0_4_);

      local_2b0 = (ulonglong)(uint5)local_2b0;

      FUN_1400a2ed0(local_288,&local_2b0);

      if (0xf < uStack_298) {

        if ((0xfff < uStack_298 + 1) && (0x1f < (local_2b0 - *(longlong *)(local_2b0 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      local_1b0 = 3;

      local_c0 = 3;

      local_1b6 = 1;

      FUN_14005d190(uVar10,local_288);

    }

    else {

      plVar13 = (longlong *)&DAT_1403d9530;

      if (0xf < DAT_1403d9548) {

        plVar13 = DAT_1403d9530;

      }

      if (DAT_1403d9540 != 7) goto LAB_1400f5e15;

      iVar15 = (int)*plVar13 + -0x64657243;

      if ((iVar15 == 0) && (iVar15 = *(ushort *)((longlong)plVar13 + 4) - 0x7469, iVar15 == 0)) {

        iVar15 = *(byte *)((longlong)plVar13 + 6) - 0x73;

      }

      if (iVar15 != 0) goto LAB_1400f5e15;

      *(undefined4 *)(*(longlong *)(param_1 + 600) + 0x1c) = 0;

      lVar18 = *(longlong *)(param_1 + 600);

      puVar14 = (undefined8 *)(lVar18 + 0x168);

      *(undefined8 *)(lVar18 + 0x178) = 0;

      if (0xf < *(ulonglong *)(lVar18 + 0x180)) {

        puVar14 = (undefined8 *)*puVar14;

      }

      *(undefined1 *)puVar14 = 0;

    }

  }

  *(undefined4 *)(param_1 + 0x260) = 1;

LAB_1400f5e15:

  iVar15 = *(int *)(param_1 + 0x260);

  if ((iVar15 == 2) || (iVar15 == 3)) {

    *(undefined4 *)(param_1 + 0x260) = 1;

    iVar15 = 1;

  }

  *(undefined4 *)(param_1 + 0x250) = 0;

  *(undefined1 *)(param_1 + 0x26c) = 0;

  *(undefined4 *)(param_1 + 0x27c) = 0;

  *(bool *)(*(longlong *)(param_1 + 0x60) + 0x5d) = 0 < iVar15;

  if (*(longlong *)(param_1 + 600) != 0) {

    lVar18 = 0x2d;

    do {

      FUN_1400ceb60(param_1);

      lVar18 = lVar18 + -1;

    } while (lVar18 != 0);

  }

  if (local_2c8 != 0) {

    if ((0xfff < ((longlong)local_2b8 - local_2c8 & 0xfffffffffffffffcU)) &&

       (0x1f < (local_2c8 - *(longlong *)(local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return 1;

}




