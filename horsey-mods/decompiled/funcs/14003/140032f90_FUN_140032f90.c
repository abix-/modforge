// Address: 0x140032f90
// Ghidra name: FUN_140032f90
// ============ 0x140032f90 FUN_140032f90 (size=2677) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140032f90(longlong param_1)



{

  longlong *plVar1;

  float *pfVar2;

  float fVar3;

  undefined8 uVar4;

  undefined8 *puVar5;

  float fVar6;

  undefined8 uVar7;

  float fVar8;

  float fVar9;

  undefined8 uVar10;

  char cVar11;

  int *piVar12;

  longlong lVar13;

  longlong lVar14;

  int iVar15;

  ulonglong uVar16;

  uint uVar17;

  ulonglong uVar19;

  int iVar20;

  ulonglong uVar21;

  uint uVar22;

  undefined4 uVar23;

  undefined4 uVar24;

  int local_res8;

  uint local_resc;

  float local_res10 [2];

  longlong local_res18;

  ulonglong in_stack_ffffffffffffff18;

  undefined4 uVar25;

  undefined4 uVar26;

  char *local_b8;

  ulonglong uStack_b0;

  undefined1 local_a8 [16];

  ulonglong uVar18;

  

  iVar15 = *(int *)(param_1 + 0x27c);

  if (iVar15 == 2) {

    lVar14 = 0xf0;

    do {

      FUN_1400b9540(*(undefined8 *)

                     (*(longlong *)(param_1 + 0x260) + (longlong)**(int **)(param_1 + 0x2a0) * 8),1)

      ;

      FUN_1400b9540(*(undefined8 *)

                     (*(longlong *)(param_1 + 0x260) +

                     (longlong)*(int *)(*(longlong *)(param_1 + 0x2a0) + 0x10) * 8),1);

      FUN_1400b9540(*(undefined8 *)

                     (*(longlong *)(param_1 + 0x260) +

                     (longlong)*(int *)(*(longlong *)(param_1 + 0x2a0) + 0x20) * 8),1);

      FUN_1400b9540(*(undefined8 *)

                     (*(longlong *)(param_1 + 0x260) +

                     (longlong)*(int *)(*(longlong *)(param_1 + 0x2a0) + 0x30) * 8),1);

      FUN_140007610(*(undefined8 *)(param_1 + 600));

      lVar14 = lVar14 + -1;

    } while (lVar14 != 0);

    iVar15 = 2;

    if (*(int *)(param_1 + 0x288) == 0) {

      iVar15 = 0x1e;

    }

    if (*(int *)(param_1 + 0x280) == iVar15) {

      iVar15 = 0;

      lVar13 = *(longlong *)(param_1 + 0x2a0);

      lVar14 = 0;

      if (*(longlong *)(param_1 + 0x2a8) - lVar13 >> 4 != 0) {

        do {

          FUN_1400b7fe0(*(undefined8 *)

                         (*(longlong *)(param_1 + 0x260) + (longlong)*(int *)(lVar14 + lVar13) * 8),

                        0);

          iVar15 = iVar15 + 1;

          lVar14 = lVar14 + 0x10;

          lVar13 = *(longlong *)(param_1 + 0x2a0);

        } while ((ulonglong)(longlong)iVar15 <

                 (ulonglong)(*(longlong *)(param_1 + 0x2a8) - lVar13 >> 4));

      }

      local_a8._0_8_ = _DAT_1403040b0;

      local_a8._8_8_ = _UNK_1403040b8;

      local_b8 = (char *)s_SimStartRace_140303bb0._0_8_;

      uStack_b0 = (ulonglong)(uint)s_SimStartRace_140303bb0._8_4_;

      FUN_140040ca0(&local_b8,100,0,DAT_14039ca44,in_stack_ffffffffffffff18 & 0xffffffffffffff00);

      if (0xf < (ulonglong)local_a8._8_8_) {

        if ((0xfff < local_a8._8_8_ + 1) &&

           ((char *)0x1f < local_b8 + (-8 - *(longlong *)(local_b8 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      *(undefined8 *)(param_1 + 0x27c) = 3;

      *(undefined4 *)(param_1 + 0x284) = 0;

    }

  }

  else if (iVar15 == 3) {

    FUN_14003f330(1);

    uVar26 = DAT_14039ca44;

    uVar10 = _UNK_1403040e8;

    uVar4 = _DAT_1403040e0;

    fVar9 = DAT_140304074;

    fVar8 = DAT_140304070;

    fVar6 = DAT_140303fe4;

    uVar16 = 0;

    local_res8 = 0;

    uVar19 = uVar16;

    do {

      iVar15 = (int)uVar19;

      if (3 < iVar15) goto LAB_140033334;

      *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + 1;

      uVar19 = uVar16;

      uVar21 = uVar16;

      do {

        lVar14 = *(longlong *)

                  (*(longlong *)(param_1 + 0x260) +

                  (longlong)*(int *)(uVar21 + *(longlong *)(param_1 + 0x2a0)) * 8);

        cVar11 = FUN_1400b4990(lVar14);

        if (cVar11 == '\0') {

          uVar19 = (ulonglong)((int)uVar19 + 1);

        }

        else {

          FUN_1400b9540(lVar14,1);

          lVar13 = *(longlong *)(param_1 + 0x2a0);

          uVar23 = FUN_1400b5fe0(lVar14);

          *(undefined4 *)(uVar21 + 8 + lVar13) = uVar23;

          if (*(int *)(param_1 + 0x284) < 0x2a30) {

            if (*(char *)(lVar14 + 0x22) == '\0') {

              lVar13 = *(longlong *)(param_1 + 0x2a0);

              fVar3 = *(float *)(uVar21 + 8 + lVar13);

              if (fVar6 <= fVar3) {

                local_b8 = (char *)0x0;

                uStack_b0 = 0;

                local_a8 = ZEXT816(0);

                local_b8 = (char *)FUN_1400285e0(0x20);

                uVar7 = s_SimHorseFinished_140303bd0._8_8_;

                local_a8._8_8_ = uVar10;

                local_a8._0_8_ = uVar4;

                *(undefined8 *)local_b8 = s_SimHorseFinished_140303bd0._0_8_;

                *(undefined8 *)(local_b8 + 8) = uVar7;

                local_b8[0x10] = '\0';

                in_stack_ffffffffffffff18 = in_stack_ffffffffffffff18 & 0xffffffffffffff00;

                FUN_140040ca0(&local_b8,100,0,uVar26,in_stack_ffffffffffffff18);

                if (0xf < (ulonglong)local_a8._8_8_) {

                  if ((0xfff < local_a8._8_8_ + 1) &&

                     ((char *)0x1f < local_b8 + (-8 - *(longlong *)(local_b8 + -8)))) {

                    /* WARNING: Subroutine does not return */

                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                  }

                  FUN_1402c7088();

                }

                iVar15 = *(int *)(param_1 + 0x284);

                if (299 < iVar15) goto LAB_1400335b2;

                *(undefined4 *)(lVar14 + 0x228) = 20000;

                FUN_1400c4320("culled one glitchy cheating horse");

                goto LAB_1400335b8;

              }

              pfVar2 = (float *)(uVar21 + 0xc + lVar13);

              if (fVar3 < *pfVar2 || fVar3 == *pfVar2) {

                piVar12 = (int *)(uVar21 + 4 + lVar13);

                *piVar12 = *piVar12 + 1;

                if (300 < *(int *)(uVar21 + 4 + lVar13)) goto LAB_140033595;

              }

              else {

                *(float *)(uVar21 + 0xc + lVar13) = fVar3;

                *(undefined4 *)(uVar21 + 4 + *(longlong *)(param_1 + 0x2a0)) = 0;

              }

            }

            else {

              FUN_1400c4320("Phys Err");

              *(undefined4 *)(lVar14 + 0x228) = 20000;

              FUN_1400b47e0(lVar14);

              piVar12 = (int *)&DAT_1403d9530;

              if (0xf < DAT_1403d9548) {

                piVar12 = DAT_1403d9530;

              }

              if (DAT_1403d9540 == 6) {

                iVar15 = *piVar12 + -0x74696c47;

                if (iVar15 == 0) {

                  iVar15 = *(ushort *)(piVar12 + 1) - 0x6863;

                }

                if (iVar15 == 0) {

                  FUN_1400a33b0(lVar14 + 0x2b8);

                  uVar19 = 4;

                  *(undefined4 *)(param_1 + 0x278) = 1000;

                  *(int *)(param_1 + 0x288) = *(int *)(param_1 + 0x6a8) + -1;

                  *(undefined4 *)(lVar14 + 0x228) = 0xffffffff;

                  break;

                }

              }

            }

          }

          else {

LAB_140033595:

            iVar15 = (int)(fVar9 - *(float *)(uVar21 + 0xc + *(longlong *)(param_1 + 0x2a0)) * fVar8

                          );

LAB_1400335b2:

            *(int *)(lVar14 + 0x228) = iVar15;

LAB_1400335b8:

            FUN_1400b47e0(lVar14);

          }

        }

        uVar21 = uVar21 + 0x10;

      } while ((longlong)uVar21 < 0x40);

      FUN_140007610(*(undefined8 *)(param_1 + 600));

      local_res8 = local_res8 + 1;

    } while (local_res8 < 0xf0);

    iVar15 = (int)uVar19;

LAB_140033334:

    if (iVar15 == 4) {

      *(undefined8 *)(param_1 + 0x27c) = 4;

    }

    FUN_14003f330(0);

    uVar17 = DAT_14039cac0;

    uVar26 = DAT_14039ca24;

    fVar6 = DAT_140303354;

    piVar12 = (int *)&DAT_1403d9530;

    if (0xf < DAT_1403d9548) {

      piVar12 = DAT_1403d9530;

    }

    if (DAT_1403d9540 == 6) {

      iVar15 = *piVar12 + -0x74696c47;

      if (iVar15 == 0) {

        iVar15 = *(ushort *)(piVar12 + 1) - 0x6863;

      }

      if (iVar15 == 0) {

        return;

      }

    }

    if (((8 < *(int *)(param_1 + 0x288)) &&

        (*(int *)(param_1 + 0x254) == (*(int *)(param_1 + 0x254) / 5) * 5)) &&

       (0 < *(int *)(param_1 + 0x288) + -8)) {

      do {

        uVar25 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);

        local_resc = FUN_1400c6940();

        local_resc = local_resc ^ uVar17;

        local_res8 = 0;

        iVar15 = FUN_1400c6580(0x1f);

        local_res10[0] = (float)(iVar15 + 0xc9) * fVar6;

        local_res10[1] = 4.1875;

        uVar4 = *(undefined8 *)(param_1 + 0x248);

        uVar23 = FUN_1400c6940();

        uVar24 = FUN_1400c6940();

        in_stack_ffffffffffffff18 = CONCAT44(uVar25,uVar24);

        FUN_1400c8dc0(uVar4,0xffffffff,local_res10,&local_res8,in_stack_ffffffffffffff18,uVar23,

                      &DAT_1403d4144,0x2d,uVar26);

        uVar22 = (int)uVar16 + 1;

        uVar16 = (ulonglong)uVar22;

      } while ((int)uVar22 < *(int *)(param_1 + 0x288) + -8);

    }

  }

  else if ((iVar15 == 4) && (*(int *)(param_1 + 0x280) == 2)) {

    if (*(int *)(param_1 + 0x278) * 4 < *(int *)(param_1 + 0x6ac) + -4) {

      *(int *)(param_1 + 0x278) = *(int *)(param_1 + 0x278) + 1;

    }

    else {

      uVar19 = 0;

      *(undefined4 *)(param_1 + 0x298) = 0;

      if (0 < *(int *)(param_1 + 0x6ac)) {

        lVar14 = *(longlong *)(param_1 + 0x260);

        iVar15 = *(int *)(param_1 + 0x6ac);

        uVar16 = uVar19;

        uVar21 = uVar19;

        uVar18 = uVar19;

        do {

          lVar13 = *(longlong *)(lVar14 + uVar21);

          if (((*(char *)(lVar13 + 0x22) != '\0') || ((*(byte *)(lVar13 + 600) & 0x40) != 0)) ||

             (*(int *)(lVar13 + 0x1c) == 6)) {

            *(undefined4 *)(lVar13 + 0x228) = 20000;

            lVar14 = *(longlong *)(param_1 + 0x260);

            iVar15 = *(int *)(param_1 + 0x6ac);

          }

          if (*(int *)(lVar13 + 0x228) < 10000) {

            *(int *)(param_1 + 0x298) =

                 *(int *)(param_1 + 0x298) + *(int *)(*(longlong *)(uVar21 + lVar14) + 0x228);

            lVar14 = *(longlong *)(param_1 + 0x260);

            uVar17 = *(uint *)(*(longlong *)(lVar14 + uVar21) + 0x228);

            if ((int)uVar19 < (int)uVar17) {

              uVar19 = (ulonglong)uVar17;

            }

            uVar16 = (ulonglong)((int)uVar16 + 1);

          }

          uVar17 = (int)uVar18 + 1;

          uVar18 = (ulonglong)uVar17;

          uVar21 = uVar21 + 8;

        } while ((int)uVar17 < iVar15);

        if (0 < (int)uVar16) {

          *(int *)(param_1 + 0x298) = *(int *)(param_1 + 0x298) / (int)uVar16;

        }

      }

      plVar1 = (longlong *)(param_1 + 0x260);

      FUN_140036d00(*plVar1,*(longlong *)(param_1 + 0x268),

                    *(longlong *)(param_1 + 0x268) - *plVar1 >> 3,(undefined1)local_res8);

      FUN_1400c4320("gen: %d  avg: %d  best: %d",*(undefined4 *)(param_1 + 0x298),

                    *(undefined4 *)(*(longlong *)*plVar1 + 0x228));

      uVar26 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);

      if (*(int *)(param_1 + 0x288) == *(int *)(param_1 + 0x6a8) + -1) {

        lVar14 = *(longlong *)(param_1 + 600);

        if (lVar14 != 0) {

          FUN_140005cf0(lVar14);

          FUN_1402c7088(lVar14,0x19380);

        }

        *(undefined8 *)(param_1 + 600) = 0;

        iVar15 = 1;

        if (1 < *(int *)(param_1 + 0x6ac)) {

          lVar14 = 8;

          do {

            puVar5 = *(undefined8 **)(lVar14 + *plVar1);

            if (puVar5 != (undefined8 *)0x0) {

              (**(code **)*puVar5)(puVar5,1);

            }

            iVar15 = iVar15 + 1;

            lVar14 = lVar14 + 8;

          } while (iVar15 < *(int *)(param_1 + 0x6ac));

        }

        FUN_140037550(param_1 + 0x260,1);

        *(undefined8 *)(param_1 + 0x27c) = 5;

        return;

      }

      iVar15 = (*(int *)(param_1 + 0x6ac) * 0x19) / 100;

      if (iVar15 < *(int *)(param_1 + 0x6ac)) {

        lVar14 = (longlong)iVar15 * 8;

        iVar20 = iVar15;

        do {

          puVar5 = *(undefined8 **)(lVar14 + *plVar1);

          if (puVar5 != (undefined8 *)0x0) {

            (**(code **)*puVar5)(puVar5,1);

          }

          local_res10[0] = (float)FUN_1400c6580(iVar15);

          local_res8 = FUN_1400c6580(iVar15);

          local_res18 = FUN_1402c704c(0x498);

          if (local_res18 == 0) {

            lVar13 = 0;

          }

          else {

            lVar13 = FUN_1400aac60(local_res18);

          }

          FUN_1400b2e30(lVar13,*(undefined8 *)(*plVar1 + (longlong)(int)local_res10[0] * 8),

                        *(undefined8 *)(*plVar1 + (longlong)local_res8 * 8));

          uVar26 = (undefined4)(in_stack_ffffffffffffff18 >> 0x20);

          *(undefined4 *)(lVar13 + 0x1fc) = 1;

          *(undefined4 *)(lVar13 + 0x224) = *(undefined4 *)(param_1 + 0x28c);

          *(int *)(param_1 + 0x28c) = *(int *)(param_1 + 0x28c) + 1;

          *(int *)(lVar13 + 0x21c) = *(int *)(param_1 + 0x288);

          *(longlong *)(lVar14 + *plVar1) = lVar13;

          iVar20 = iVar20 + 1;

          lVar14 = lVar14 + 8;

        } while (iVar20 < *(int *)(param_1 + 0x6ac));

      }

      if ((*(int *)(param_1 + 0x288) == *(int *)(param_1 + 0x6a8) / 2 + -1) &&

         (*(longlong *)(param_1 + 0x148) != 0)) {

        local_b8 = (char *)0x0;

        uStack_b0 = 0;

        local_a8 = ZEXT816(0);

        local_b8 = (char *)FUN_1400285e0(0x20);

        uVar4 = s_This_is_exciting_140303c30._8_8_;

        local_a8._8_8_ = _UNK_1403040e8;

        local_a8._0_8_ = _DAT_1403040e0;

        *(undefined8 *)local_b8 = s_This_is_exciting_140303c30._0_8_;

        *(undefined8 *)(local_b8 + 8) = uVar4;

        local_b8[0x10] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_b8,0,

                      CONCAT44(uVar26,DAT_140303758));

        if (0xf < (ulonglong)local_a8._8_8_) {

          if ((0xfff < local_a8._8_8_ + 1) &&

             ((char *)0x1f < local_b8 + (-8 - *(longlong *)(local_b8 + -8)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        FUN_1400b8720(*(undefined8 *)(param_1 + 0x148));

      }

      *(int *)(param_1 + 0x288) = *(int *)(param_1 + 0x288) + 1;

      *(undefined4 *)(param_1 + 0x278) = 0;

    }

    FUN_140032ac0(param_1);

  }

  return;

}




