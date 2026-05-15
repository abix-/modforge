// Address: 0x1400f9bd0
// Ghidra name: FUN_1400f9bd0
// ============ 0x1400f9bd0 FUN_1400f9bd0 (size=3092) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400f9bd0(longlong param_1)



{

  char *pcVar1;

  float fVar2;

  size_t sVar3;

  ulonglong uVar4;

  undefined1 uVar5;

  longlong lVar6;

  ulonglong uVar7;

  longlong *plVar8;

  size_t sVar9;

  longlong *plVar10;

  undefined8 uVar11;

  int iVar12;

  int iVar13;

  uint uVar14;

  uint uVar15;

  ulonglong uVar16;

  char **ppcVar17;

  undefined8 *puVar18;

  float fVar19;

  float fVar20;

  int local_res10;

  float local_res20;

  undefined4 uStackX_24;

  undefined8 local_2f8;

  undefined8 uStack_2f0;

  size_t local_2e8;

  ulonglong uStack_2e0;

  undefined4 local_2d8;

  char **local_2d0;

  char *local_2c8;

  char *pcStack_2c0;

  char *local_2b8;

  undefined4 local_2b0;

  char *local_2a8 [4];

  char *local_288;

  char *local_280;

  char *local_278;

  undefined *local_270;

  undefined *local_268;

  longlong local_258;

  undefined1 local_248 [528];

  

  uVar4 = _UNK_140304088;

  sVar3 = _DAT_140304080;

  fVar19 = DAT_140303750;

  fVar2 = DAT_1403033a4;

  plVar8 = (longlong *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    plVar8 = DAT_1403d9530;

  }

  if (DAT_1403d9540 == 5) {

    iVar12 = (int)*plVar8 + -0x7a697250;

    if (iVar12 == 0) {

      iVar12 = *(byte *)((longlong)plVar8 + 4) - 0x65;

    }

    if (iVar12 != 0) goto LAB_1400f9c4f;

    DAT_1403d9594 = 2;

  }

  else {

LAB_1400f9c4f:

    if (DAT_1403d9594 < 1) goto LAB_1400fa1b1;

  }

  local_2a8[0] = "Geraldo";

  local_2a8[1] = "Norse Horse";

  local_2a8[2] = &DAT_140313044;

  local_2a8[3] = "Grep";

  local_288 = "Boron";

  local_280 = "Argon";

  local_278 = "Krypton";

  local_270 = &DAT_140313000;

  local_268 = &DAT_140313010;

  local_2c8 = "crazy horse";

  pcStack_2c0 = "moose";

  local_2b8 = "tiger";

  local_res10 = 0;

  if (0 < DAT_1403d9594) {

    ppcVar17 = &local_2c8;

    do {

      iVar12 = local_res10 + (int)((ulonglong)(longlong)local_res10 / 9) * -9;

      local_2d0 = ppcVar17;

      local_258 = FUN_1402c704c(0x498);

      if (local_258 == 0) {

        lVar6 = 0;

      }

      else {

        lVar6 = FUN_1400aac60(local_258);

      }

      if (local_res10 == 0) {

        plVar8 = (longlong *)&DAT_1403d9530;

        if (0xf < DAT_1403d9548) {

          plVar8 = DAT_1403d9530;

        }

        if (DAT_1403d9540 != 5) goto LAB_1400f9e35;

        iVar13 = (int)*plVar8 + -0x696c6548;

        if (iVar13 == 0) {

          iVar13 = *(byte *)((longlong)plVar8 + 4) - 0x78;

        }

        if (iVar13 != 0) goto LAB_1400f9e35;

        uStack_2f0 = 0;

        local_2e8 = sVar3;

        uStack_2e0 = uVar4;

        local_2f8 = (ulonglong)CONCAT14(DAT_140313074,DAT_140313070);

        FUN_1400b2ee0(lVar6,&local_2f8);

        if (0xf < uStack_2e0) {

          if ((0xfff < uStack_2e0 + 1) && (0x1f < (local_2f8 - *(longlong *)(local_2f8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        FUN_1400b3650(lVar6,lVar6 + 0x2b8);

      }

      else {

LAB_1400f9e35:

        local_2e8 = 0xb;

        uStack_2e0 = 0xf;

        local_2f8._0_1_ = s_crazy_horse_140303b00[0];

        local_2f8._1_1_ = s_crazy_horse_140303b00[1];

        local_2f8._2_1_ = s_crazy_horse_140303b00[2];

        local_2f8._3_1_ = s_crazy_horse_140303b00[3];

        local_2f8._4_1_ = s_crazy_horse_140303b00[4];

        local_2f8._5_1_ = s_crazy_horse_140303b00[5];

        local_2f8._6_1_ = s_crazy_horse_140303b00[6];

        local_2f8._7_1_ = s_crazy_horse_140303b00[7];

        uStack_2f0 = (ulonglong)CONCAT12(s_crazy_horse_140303b00[10],s_crazy_horse_140303b00._8_2_);

        if ((ulonglong)(longlong)local_res10 < 3) {

          pcVar1 = *ppcVar17;

          sVar9 = strlen(pcVar1);

          if (sVar9 < 0x10) {

            local_2e8 = sVar9;

            FUN_1402f8e20(&local_2f8,pcVar1);

            *(undefined1 *)((longlong)&local_2f8 + sVar9) = 0;

            ppcVar17 = local_2d0;

          }

          else {

            if (0x7fffffffffffffff < sVar9) {

                    /* WARNING: Subroutine does not return */

              FUN_140024130();

            }

            uVar16 = sVar9 | 0xf;

            if (uVar16 < 0x8000000000000000) {

              if (uVar16 < 0x16) {

                uVar16 = 0x16;

              }

            }

            else {

              uVar16 = 0x7fffffffffffffff;

            }

            uVar7 = FUN_1400285e0(uVar16 + 1);

            local_2e8 = sVar9;

            uStack_2e0 = uVar16;

            FUN_1402f8e20(uVar7,pcVar1);

            *(undefined1 *)(uVar7 + sVar9) = 0;

            ppcVar17 = local_2d0;

            local_2f8 = uVar7;

          }

        }

        FUN_1400b2ee0(lVar6,&local_2f8);

        if (0xf < uStack_2e0) {

          if ((0xfff < uStack_2e0 + 1) && (0x1f < (local_2f8 - *(longlong *)(local_2f8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

      plVar8 = (longlong *)&DAT_1403d9530;

      if (0xf < DAT_1403d9548) {

        plVar8 = DAT_1403d9530;

      }

      if (DAT_1403d9540 == 5) {

        iVar13 = (int)*plVar8 + -0x65746e49;

        if (iVar13 == 0) {

          iVar13 = *(byte *)((longlong)plVar8 + 4) - 0x6c;

        }

        if (iVar13 == 0) {

          *(undefined1 *)(lVar6 + 0x38a) = 1;

          *(undefined1 *)(lVar6 + 0x47a) = 1;

          FUN_1400b3070(lVar6);

        }

      }

      *(undefined4 *)(lVar6 + 0x1fc) = 1;

      FUN_1400fb050(param_1,lVar6);

      local_res20 = ((float)iVar12 * fVar19) / (float)DAT_1403d9594 + fVar2;

      uStackX_24 = 0x41040000;

      FUN_1400b6610(lVar6,&local_res20);

      *(ulonglong *)(lVar6 + 0x1d4) = CONCAT44(uStackX_24,local_res20);

      pcVar1 = local_2a8[iVar12];

      local_2f8 = 0;

      uStack_2f0 = 0;

      local_2e8 = 0;

      uStack_2e0 = 0;

      sVar9 = strlen(pcVar1);

      FUN_140027e30(&local_2f8,pcVar1,sVar9);

      FUN_1400cf950(param_1,lVar6);

      if (0xf < uStack_2e0) {

        if ((0xfff < uStack_2e0 + 1) && (0x1f < (local_2f8 - *(longlong *)(local_2f8 + -8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      uVar5 = FUN_1400c66c0();

      *(undefined1 *)(lVar6 + 0x1a) = uVar5;

      local_res10 = local_res10 + 1;

      ppcVar17 = ppcVar17 + 1;

      local_2d0 = ppcVar17;

    } while (local_res10 < DAT_1403d9594);

  }

  plVar8 = (longlong *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    plVar8 = DAT_1403d9530;

  }

  if (DAT_1403d9540 == 9) {

    lVar6 = *plVar8 + -0x73726f4864616544;

    if (lVar6 == 0) {

      lVar6 = (ulonglong)*(byte *)(plVar8 + 1) - 0x65;

    }

    if (lVar6 == 0) {

      FUN_1400b8f90(**(undefined8 **)(param_1 + 0x130),6);

      goto LAB_1400fa1b1;

    }

  }

  plVar8 = (longlong *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    plVar8 = DAT_1403d9530;

  }

  if (DAT_1403d9540 == 5) {

    iVar12 = (int)*plVar8 + -0x6d616843;

    if (iVar12 == 0) {

      iVar12 = *(byte *)((longlong)plVar8 + 4) - 0x70;

    }

    if (iVar12 == 0) {

      *(undefined4 *)(**(longlong **)(param_1 + 0x130) + 0x1fc) = 3;

      lVar6 = FUN_1400c7520(*(undefined4 *)(**(longlong **)(param_1 + 0x130) + 0x1f8));

      *(undefined4 *)(lVar6 + 0x50) = 3;

      lVar6 = FUN_1400c7520(*(undefined4 *)(**(longlong **)(param_1 + 0x130) + 0x1f8));

      *(undefined4 *)(lVar6 + 0x54) = 3;

    }

  }

LAB_1400fa1b1:

  uVar4 = DAT_1403d9548;

  lVar6 = DAT_1403d9540;

  plVar8 = DAT_1403d9530;

  fVar2 = DAT_14039ca34;

  fVar19 = **(float **)(param_1 + 0x78) + DAT_14039ca34;

  fVar20 = (*(float **)(param_1 + 0x78))[1] + _DAT_1403130d4;

  plVar10 = (longlong *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    plVar10 = DAT_1403d9530;

  }

  if ((DAT_1403d9540 == 2) && ((short)*plVar10 == 0x5353)) {

    local_2c8 = _DAT_140313100;

    pcStack_2c0 = (char *)_UNK_140313108;

    local_2b8 = (char *)0x1300000015;

    local_2b0 = 5;

    uVar14 = 0;

    ppcVar17 = &local_2c8;

    do {

      FUN_1400cc9d0(param_1,*(undefined4 *)ppcVar17,(float)(int)uVar14 + fVar19,fVar20);

      uVar14 = uVar14 + 1;

      ppcVar17 = (char **)((longlong)ppcVar17 + 4);

    } while (uVar14 < 7);

  }

  else {

    plVar10 = (longlong *)&DAT_1403d9530;

    if (0xf < DAT_1403d9548) {

      plVar10 = DAT_1403d9530;

    }

    if ((DAT_1403d9540 == 5) && (iVar12 = memcmp(plVar10,"Stuff",5), iVar12 == 0)) {

      local_2f8 = _DAT_1403130f0;

      uStack_2f0 = _UNK_1403130f8;

      local_2e8 = _DAT_1403130e0;

      uStack_2e0 = _UNK_1403130e8;

      local_2d8 = 1;

      uVar14 = 0;

      puVar18 = &local_2f8;

      do {

        FUN_1400cc9d0(param_1,*(undefined4 *)puVar18,(float)(int)uVar14 + fVar19,fVar20);

        uVar14 = uVar14 + 1;

        puVar18 = (undefined8 *)((longlong)puVar18 + 4);

      } while (uVar14 < 9);

    }

    else {

      plVar10 = (longlong *)&DAT_1403d9530;

      if (0xf < uVar4) {

        plVar10 = plVar8;

      }

      if ((lVar6 == 5) && (iVar12 = memcmp(plVar10,"Sauce",5), iVar12 == 0)) {

        iVar12 = 0;

        do {

          FUN_1400cc9d0(param_1,4,(float)iVar12 + fVar19,fVar20);

          iVar12 = iVar12 + 1;

        } while (iVar12 < 5);

      }

      else {

        plVar10 = (longlong *)&DAT_1403d9530;

        if (0xf < uVar4) {

          plVar10 = plVar8;

        }

        if ((lVar6 == 9) && (iVar12 = memcmp(plVar10,"Plutonium",9), iVar12 == 0)) {

          iVar12 = 0;

          do {

            FUN_1400cc9d0(param_1,5,(float)iVar12 * fVar2 + fVar19,fVar20);

            iVar12 = iVar12 + 1;

          } while (iVar12 < 0xc);

        }

        else {

          plVar10 = (longlong *)&DAT_1403d9530;

          if (0xf < uVar4) {

            plVar10 = plVar8;

          }

          if ((lVar6 == 4) && (iVar12 = memcmp(plVar10,&DAT_140313088,4), iVar12 == 0)) {

            local_2f8 = _DAT_140313110;

            uStack_2f0 = _UNK_140313118;

            local_2e8 = _DAT_140313120;

            uStack_2e0 = _UNK_140313128;

            uVar14 = 0;

            puVar18 = &local_2f8;

            do {

              FUN_1400cc9d0(param_1,*(undefined4 *)puVar18,(float)(int)uVar14 + fVar19,fVar20);

              uVar14 = uVar14 + 1;

              puVar18 = (undefined8 *)((longlong)puVar18 + 4);

            } while (uVar14 < 8);

          }

          else {

            plVar10 = (longlong *)&DAT_1403d9530;

            if (0xf < uVar4) {

              plVar10 = plVar8;

            }

            if ((lVar6 == 6) && (iVar12 = memcmp(plVar10,"Abduct",6), iVar12 == 0)) {

              iVar12 = 0;

              do {

                FUN_1400cc9d0(param_1,3,(float)iVar12 * fVar2 + fVar19,fVar20);

                iVar12 = iVar12 + 1;

              } while (iVar12 < 10);

            }

            else {

              plVar10 = (longlong *)&DAT_1403d9530;

              if (0xf < uVar4) {

                plVar10 = plVar8;

              }

              if ((lVar6 == 9) && (iVar12 = memcmp(plVar10,"Biohacker",9), iVar12 == 0)) {

                uStack_2f0 = 0;

                local_2e8 = _DAT_140304cb0;

                uStack_2e0 = _UNK_140304cb8;

                local_2f8 = (ulonglong)(uint3)DAT_140306984;

                FUN_1400a2ed0(local_248,&local_2f8);

                if (0xf < uStack_2e0) {

                  if ((0xfff < uStack_2e0 + 1) &&

                     (0x1f < (local_2f8 - *(longlong *)(local_2f8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                  }

                  FUN_1402c7088();

                }

                uVar11 = FUN_1400cc9d0(param_1,0xc);

                FUN_14005d190(uVar11,local_248);

                uStack_2f0 = 0;

                local_2e8 = _DAT_140305680;

                uStack_2e0 = _UNK_140305688;

                local_2f8 = 0x6f6e6964;

                FUN_1400a2ed0(local_248,&local_2f8);

                if (0xf < uStack_2e0) {

                  if ((0xfff < uStack_2e0 + 1) &&

                     (0x1f < (local_2f8 - *(longlong *)(local_2f8 + -8)) - 8)) {

                    /* WARNING: Subroutine does not return */

                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                  }

                  FUN_1402c7088();

                }

                uVar11 = FUN_1400cc9d0(param_1,0xd,fVar19 + DAT_14030374c,fVar20);

                FUN_14005d190(uVar11,local_248);

                FUN_1400cc9d0(param_1,5,fVar19 + DAT_14030338c,fVar20);

                FUN_1400cc9d0(param_1,5);

              }

              else {

                plVar10 = (longlong *)&DAT_1403d9530;

                if (0xf < uVar4) {

                  plVar10 = plVar8;

                }

                if ((lVar6 == 5) && (iVar12 = memcmp(plVar10,&DAT_14030b5e0,5), iVar12 == 0)) {

                  local_2e8 = _DAT_1403040a0;

                  uStack_2e0 = _UNK_1403040a8;

                  local_2f8._0_1_ = s_alligator_140303b48[0];

                  local_2f8._1_1_ = s_alligator_140303b48[1];

                  local_2f8._2_1_ = s_alligator_140303b48[2];

                  local_2f8._3_1_ = s_alligator_140303b48[3];

                  local_2f8._4_1_ = s_alligator_140303b48[4];

                  local_2f8._5_1_ = s_alligator_140303b48[5];

                  local_2f8._6_1_ = s_alligator_140303b48[6];

                  local_2f8._7_1_ = s_alligator_140303b48[7];

                  uStack_2f0 = (ulonglong)(byte)s_alligator_140303b48[8];

                  FUN_1400a2ed0(local_248,&local_2f8);

                  if (0xf < uStack_2e0) {

                    if ((0xfff < uStack_2e0 + 1) &&

                       (0x1f < (local_2f8 - *(longlong *)(local_2f8 + -8)) - 8)) {

                    /* WARNING: Subroutine does not return */

                      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                    }

                    FUN_1402c7088();

                  }

                  uVar11 = FUN_1400cc9d0(param_1,0xc);

                  FUN_14005d190(uVar11,local_248);

                  uVar14 = 0;

                  do {

                    uVar15 = uVar14 + 1;

                    FUN_1400cc9d0(param_1,(uVar14 & 3) + 0x13,(float)(int)uVar15 * fVar2 + fVar19,

                                  fVar20);

                    uVar14 = uVar15;

                  } while ((int)uVar15 < 5);

                }

              }

            }

          }

        }

      }

    }

  }

  *(undefined4 *)(param_1 + 0x25c) = 0;

  *(bool *)(param_1 + 0x262) = DAT_1403d9599 == '\0';

  *(bool *)(param_1 + 0x261) = DAT_1403d9599 == '\0';

  *(bool *)(param_1 + 0x263) = DAT_1403d9599 == '\0';

  return;

}




