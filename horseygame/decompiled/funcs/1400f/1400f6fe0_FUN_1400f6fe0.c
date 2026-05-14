// Address: 0x1400f6fe0
// Ghidra name: FUN_1400f6fe0
// ============ 0x1400f6fe0 FUN_1400f6fe0 (size=9683) ============


/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400f6fe0(longlong param_1)



{

  ulonglong uVar1;

  ulonglong uVar2;

  bool bVar3;

  bool bVar4;

  float fVar5;

  char cVar6;

  int iVar7;

  undefined8 *puVar8;

  longlong lVar9;

  float *pfVar10;

  undefined8 uVar11;

  char *pcVar12;

  size_t sVar13;

  ulonglong *puVar14;

  ulonglong uVar15;

  uint uVar16;

  longlong *plVar17;

  longlong lVar18;

  ulonglong uVar19;

  ulonglong uVar20;

  ulonglong uVar21;

  float fVar22;

  float local_res8;

  float local_resc;

  float local_res10;

  float local_res14;

  float local_res18;

  float local_res1c;

  ulonglong in_stack_fffffffffffffd08;

  undefined4 uVar23;

  undefined4 uVar24;

  uint in_stack_fffffffffffffd10;

  undefined1 local_2c8 [5];

  undefined1 auStack_2c3 [11];

  undefined8 local_2b8;

  ulonglong uStack_2b0;

  longlong *local_2a0;

  longlong *plStack_298;

  longlong *local_290;

  ulonglong local_288;

  ulonglong uStack_280;

  ulonglong local_278;

  ulonglong uStack_270;

  char *local_268 [2];

  undefined4 local_258 [2];

  char *local_250;

  char *local_248;

  undefined4 local_240;

  char *local_238;

  char *local_230;

  undefined4 local_228;

  char *local_220;

  char *local_218;

  undefined4 local_210;

  char *local_208;

  char *local_200;

  int local_1f8;

  char *local_1f0;

  char *local_1e8;

  undefined4 local_1e0;

  char *local_1d8;

  char *local_1d0;

  undefined4 local_1c8;

  char *local_1c0;

  char *local_1b8;

  undefined4 local_1b0;

  char *local_1a8;

  char *local_1a0;

  undefined4 local_198;

  char *local_190;

  char *local_188;

  undefined4 local_180;

  char *local_178;

  char *local_170;

  undefined4 local_168;

  undefined1 local_a0;

  

  uVar19 = 0;

  *(int *)(param_1 + 0x250) = *(int *)(param_1 + 0x250) + 1;

  FUN_1400ca260();

  FUN_1400ceb60(param_1);

  fVar22 = (float)(DAT_1403eda00 + -8) * DAT_14030375c;

  if (fVar22 <= *(float *)(param_1 + 0x1c8)) {

    fVar22 = *(float *)(param_1 + 0x1c8);

  }

  *(float *)(param_1 + 0x1c8) = fVar22;

  fVar22 = (float)(DAT_1403eda04 + -0x18) * DAT_14030375c;

  if (fVar22 <= *(float *)(param_1 + 0x1cc)) {

    fVar22 = *(float *)(param_1 + 0x1cc);

  }

  *(float *)(param_1 + 0x1cc) = fVar22;

  uVar24 = DAT_14039ca44;

  iVar7 = *(int *)(param_1 + 0x260);

  if (iVar7 == 0) {

    iVar7 = *(int *)(param_1 + 0x250);

    if (iVar7 == 1) {

      FUN_1400f6010(param_1);

LAB_1400f70d2:

      *(undefined1 *)(param_1 + 0x204) = 1;

    }

    else if ((iVar7 == 0x92964) || ((iVar7 - 2U < 0x92962 && (*(int *)(param_1 + 0x1f8) == 0)))) {

      FUN_1400f6410(param_1);

      *(undefined4 *)(param_1 + 0x250) = 0x92964;

      goto LAB_1400f70d2;

    }

    if ((0x929a0 < *(int *)(param_1 + 0x250)) &&

       (*(longlong *)(param_1 + 0x210) == *(longlong *)(param_1 + 0x218))) {

      *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5d) = 1;

      uVar16 = *(int *)(param_1 + 0x250) / 0xf & 0x80000001;

      if ((int)uVar16 < 0) {

        uVar16 = (uVar16 - 1 | 0xfffffffe) + 1;

      }

      *(float *)(*(longlong *)(param_1 + 0x60) + 0x34) =

           (float)(int)uVar16 + *(float *)(*(longlong *)(param_1 + 0x60) + 0x34);

    }

  }

  else {

    uVar23 = (undefined4)(in_stack_fffffffffffffd08 >> 0x20);

    if (iVar7 == 1) {

      if (((*(int *)(param_1 + 0x250) < 0x3c) || (lVar9 = *(longlong *)(param_1 + 600), lVar9 == 0))

         || (*(int *)(lVar9 + 0x1c) == 3)) {

        lVar9 = *(longlong *)(param_1 + 600);

        if (*(int *)(param_1 + 0x250) == 0x3c) {

          if (lVar9 == 0) {

            _local_2c8 = ZEXT812(0);

            auStack_2c3._7_4_ = 0;

            local_2b8 = 0;

            uStack_2b0 = 0;

            pcVar12 = (char *)FUN_1400285e0(0x20);

            uVar11 = s_The_patient_has_escaped_1403128c0._8_8_;

            _local_2c8 = pcVar12;

            local_2b8 = _DAT_140304cd0;

            uStack_2b0 = _UNK_140304cd8;

            *(undefined8 *)pcVar12 = s_The_patient_has_escaped_1403128c0._0_8_;

            *(undefined8 *)(pcVar12 + 8) = uVar11;

            *(undefined4 *)(pcVar12 + 0x10) = s_The_patient_has_escaped_1403128c0._16_4_;

            *(undefined2 *)(pcVar12 + 0x14) = s_The_patient_has_escaped_1403128c0._20_2_;

            pcVar12[0x16] = s_The_patient_has_escaped_1403128c0[0x16];

            pcVar12[0x17] = '\0';

            FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_2c8,0,DAT_140303758);

            if (0xf < uStack_2b0) {

              if ((0xfff < uStack_2b0 + 1) &&

                 (0x1f < ((longlong)_local_2c8 - *(longlong *)((longlong)_local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

LAB_1400f92db:

              FUN_1402c7088();

            }

          }

          else if (*(longlong *)(param_1 + 0x148) == 0) {

            _local_2c8 = ZEXT812(0);

            auStack_2c3._7_4_ = 0;

            local_2b8 = 0;

            uStack_2b0 = 0;

            pcVar12 = (char *)FUN_1400285e0(0x20);

            uVar11 = s_Where_s_the_doctor___1403128d8._8_8_;

            _local_2c8 = pcVar12;

            local_2b8 = _DAT_140303420;

            uStack_2b0 = _UNK_140303428;

            *(undefined8 *)pcVar12 = s_Where_s_the_doctor___1403128d8._0_8_;

            *(undefined8 *)(pcVar12 + 8) = uVar11;

            *(undefined4 *)(pcVar12 + 0x10) = s_Where_s_the_doctor___1403128d8._16_4_;

            pcVar12[0x14] = '\0';

            FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),local_2c8,0,DAT_140303758);

            if (0xf < uStack_2b0) {

              if ((0xfff < uStack_2b0 + 1) &&

                 (0x1f < ((longlong)_local_2c8 - *(longlong *)((longlong)_local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              goto LAB_1400f92db;

            }

          }

          else if (*(int *)(DAT_1403fb0d8 + 0x308) <

                   *(int *)(&DAT_140312628 + (longlong)*(int *)(param_1 + 0x264) * 4)) {

            if (*(int *)(param_1 + 0x278) == 1) {

              _local_2c8 = ZEXT812(0);

              auStack_2c3._7_4_ = 0;

              local_2b8 = 0;

              uStack_2b0 = 0;

              pcVar12 = (char *)FUN_1400285e0(0x30);

              uVar11 = s_Put_that_trophy_on_my_shelf_so_I_1403128f0._8_8_;

              _local_2c8 = pcVar12;

              local_2b8 = _DAT_140306020;

              uStack_2b0 = _UNK_140306028;

              *(undefined8 *)pcVar12 = s_Put_that_trophy_on_my_shelf_so_I_1403128f0._0_8_;

              *(undefined8 *)(pcVar12 + 8) = uVar11;

              uVar11 = s_Put_that_trophy_on_my_shelf_so_I_1403128f0._24_8_;

              *(undefined8 *)(pcVar12 + 0x10) = s_Put_that_trophy_on_my_shelf_so_I_1403128f0._16_8_;

              *(undefined8 *)(pcVar12 + 0x18) = uVar11;

              *(undefined8 *)(pcVar12 + 0x20) = s_Put_that_trophy_on_my_shelf_so_I_1403128f0._32_8_;

              *(undefined4 *)(pcVar12 + 0x28) = s_Put_that_trophy_on_my_shelf_so_I_1403128f0._40_4_;

              *(undefined2 *)(pcVar12 + 0x2c) = s_Put_that_trophy_on_my_shelf_so_I_1403128f0._44_2_;

              pcVar12[0x2e] = '\0';

              FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),local_2c8,0,DAT_140303758);

              if (0xf < uStack_2b0) {

                FUN_140028310(local_2c8,_local_2c8);

              }

              *(undefined4 *)(param_1 + 0x278) = 2;

            }

            else if (*(char *)(param_1 + 0x274) == '\0') {

              if (*(int *)(param_1 + 0x270) < 1) {

                _local_2c8 = ZEXT812(0);

                auStack_2c3._7_4_ = 0;

                local_2b8 = 0;

                uStack_2b0 = 0;

                if (*(int *)(DAT_1403fb0d8 + 0x308) == 0) {

                  *(undefined4 *)(param_1 + 0x270) = 0x32;

                  pcVar12 = (char *)FUN_1400285e0(0x30);

                  uVar11 = s_I_ve_sold_some_stocks_and_bonds_f_140312998._8_8_;

                  local_2b8 = _DAT_140306000;

                  uStack_2b0 = _UNK_140306008;

                  *(undefined8 *)pcVar12 = s_I_ve_sold_some_stocks_and_bonds_f_140312998._0_8_;

                  *(undefined8 *)(pcVar12 + 8) = uVar11;

                  uVar11 = s_I_ve_sold_some_stocks_and_bonds_f_140312998._24_8_;

                  *(undefined8 *)(pcVar12 + 0x10) =

                       s_I_ve_sold_some_stocks_and_bonds_f_140312998._16_8_;

                  *(undefined8 *)(pcVar12 + 0x18) = uVar11;

                  *(undefined4 *)(pcVar12 + 0x20) =

                       s_I_ve_sold_some_stocks_and_bonds_f_140312998._32_4_;

                  *(undefined2 *)(pcVar12 + 0x24) =

                       s_I_ve_sold_some_stocks_and_bonds_f_140312998._36_2_;

                  pcVar12[0x26] = s_I_ve_sold_some_stocks_and_bonds_f_140312998[0x26];

                  pcVar12[0x27] = '\0';

                  uVar24 = DAT_140303758;

                  uVar11 = CONCAT44((int)(in_stack_fffffffffffffd08 >> 0x20),DAT_140303758);

                  _local_2c8 = pcVar12;

                  FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),local_2c8,0,uVar11);

                  uVar23 = (undefined4)((ulonglong)uVar11 >> 0x20);

                  FUN_140027900(local_2c8);

                  local_2b8 = _DAT_1403040b0;

                  uStack_2b0 = _UNK_1403040b8;

                  auStack_2c3[3] = s_Here_take_it_140312988[8];

                  auStack_2c3[4] = s_Here_take_it_140312988[9];

                  auStack_2c3[5] = s_Here_take_it_140312988[10];

                  auStack_2c3[6] = s_Here_take_it_140312988[0xb];

                  local_2c8[0] = s_Here_take_it_140312988[0];

                  local_2c8[1] = s_Here_take_it_140312988[1];

                  local_2c8[2] = s_Here_take_it_140312988[2];

                  local_2c8[3] = s_Here_take_it_140312988[3];

                  local_2c8[4] = s_Here_take_it_140312988[4];

                  auStack_2c3[0] = s_Here_take_it_140312988[5];

                  auStack_2c3[1] = s_Here_take_it_140312988[6];

                  auStack_2c3[2] = s_Here_take_it_140312988[7];

                  auStack_2c3._7_4_ = 0;

                  FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),local_2c8,0,

                                CONCAT44(uVar23,uVar24));

                  FUN_140027900(local_2c8);

                }

                else {

                  pcVar12 = (char *)FUN_1400285e0(0x20);

                  uVar11 = s_It_s_so_nice_to_see_you__1403129c0._8_8_;

                  _local_2c8 = pcVar12;

                  local_2b8 = _DAT_140304120;

                  uStack_2b0 = _UNK_140304128;

                  *(undefined8 *)pcVar12 = s_It_s_so_nice_to_see_you__1403129c0._0_8_;

                  *(undefined8 *)(pcVar12 + 8) = uVar11;

                  *(undefined8 *)(pcVar12 + 0x10) = s_It_s_so_nice_to_see_you__1403129c0._16_8_;

                  pcVar12[0x18] = '\0';

                  FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),local_2c8,0,DAT_140303758);

                  FUN_140027900(local_2c8);

                  lVar9 = *(longlong *)(param_1 + 0x130);

                  uVar20 = uVar19;

                  if (*(longlong *)(param_1 + 0x138) - lVar9 >> 3 != 0) {

                    do {

                      if (((*(char *)(*(longlong *)(uVar20 + lVar9) + 0x204) != '\0') &&

                          (*(longlong *)(uVar20 + lVar9) != *(longlong *)(param_1 + 600))) &&

                         (cVar6 = FUN_1400b7720(), cVar6 != '\0')) {

                        FUN_1400d1e10(param_1,uVar19,0x12);

                        break;

                      }

                      uVar16 = (int)uVar19 + 1;

                      uVar19 = (ulonglong)uVar16;

                      lVar9 = *(longlong *)(param_1 + 0x130);

                      uVar20 = uVar20 + 8;

                    } while ((ulonglong)(longlong)(int)uVar16 <

                             (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar9 >> 3));

                  }

                }

              }

              else {

                FUN_1400d1c40(param_1,lVar9,"I sold some of that junk for $%d");

                local_2b8 = _DAT_1403040b0;

                uStack_2b0 = _UNK_1403040b8;

                auStack_2c3[3] = s_Here_take_it_140312988[8];

                auStack_2c3[4] = s_Here_take_it_140312988[9];

                auStack_2c3[5] = s_Here_take_it_140312988[10];

                auStack_2c3[6] = s_Here_take_it_140312988[0xb];

                local_2c8[0] = s_Here_take_it_140312988[0];

                local_2c8[1] = s_Here_take_it_140312988[1];

                local_2c8[2] = s_Here_take_it_140312988[2];

                local_2c8[3] = s_Here_take_it_140312988[3];

                local_2c8[4] = s_Here_take_it_140312988[4];

                auStack_2c3[0] = s_Here_take_it_140312988[5];

                auStack_2c3[1] = s_Here_take_it_140312988[6];

                auStack_2c3[2] = s_Here_take_it_140312988[7];

                auStack_2c3._7_4_ = 0;

                FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),local_2c8,0,DAT_140303758);

                FUN_140027900(local_2c8);

              }

            }

            else {

              _local_2c8 = ZEXT416(0);

              local_2b8 = 0;

              uStack_2b0 = 0;

              puVar8 = (undefined8 *)FUN_1400285e0(0x40);

              uVar11 = _UNK_140312928;

              _local_2c8 = (char *)puVar8;

              local_2b8 = _DAT_1403037b0;

              uStack_2b0 = _UNK_1403037b8;

              *puVar8 = _DAT_140312920;

              puVar8[1] = uVar11;

              uVar11 = _UNK_140312938;

              puVar8[2] = _DAT_140312930;

              puVar8[3] = uVar11;

              uVar11 = _UNK_140312948;

              puVar8[4] = _DAT_140312940;

              puVar8[5] = uVar11;

              puVar8[6] = s_you_left_here_14031294a._6_8_;

              *(undefined1 *)(puVar8 + 7) = 0;

              FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),local_2c8,0,DAT_140303758);

              FUN_140027900(local_2c8);

            }

          }

          else {

            FUN_1400f6410(param_1);

          }

        }

        else if (((lVar9 != 0) && (*(longlong *)(lVar9 + 0x240) != 0)) &&

                ((*(int *)(lVar9 + 0x238) == 0xb3 &&

                 (*(int *)(*(longlong *)(lVar9 + 0x240) + 0xc) != 0xc)))) {

          _local_2c8 = ZEXT812(0);

          auStack_2c3._7_4_ = 0;

          local_2b8 = 0;

          uStack_2b0 = 0;

          puVar8 = (undefined8 *)FUN_1400285e0(0x50);

          uVar11 = _UNK_1403129e8;

          _local_2c8 = (char *)puVar8;

          local_2b8 = _DAT_140312f30;

          uStack_2b0 = _UNK_140312f38;

          *puVar8 = _DAT_1403129e0;

          puVar8[1] = uVar11;

          uVar11 = _UNK_1403129f8;

          puVar8[2] = _DAT_1403129f0;

          puVar8[3] = uVar11;

          uVar11 = _UNK_140312a08;

          puVar8[4] = _DAT_140312a00;

          puVar8[5] = uVar11;

          uVar11 = _UNK_140312a18;

          puVar8[6] = _DAT_140312a10;

          puVar8[7] = uVar11;

          puVar8[8] = DAT_140312a20;

          *(undefined2 *)(puVar8 + 9) = DAT_140312a28;

          *(undefined1 *)((longlong)puVar8 + 0x4a) = 0;

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_2c8,0,DAT_140303758);

          if (0xf < uStack_2b0) {

            FUN_140028310(local_2c8,_local_2c8);

          }

        }

      }

      else {

        puVar8 = (undefined8 *)(lVar9 + 0x168);

        *(undefined8 *)(lVar9 + 0x178) = 0;

        if (0xf < *(ulonglong *)(lVar9 + 0x180)) {

          puVar8 = (undefined8 *)*puVar8;

        }

        *(undefined1 *)puVar8 = 0;

        local_2b8 = _DAT_1403033f0;

        uStack_2b0 = _UNK_1403033f8;

        auStack_2c3[3] = s_I_m_cured__1403128a0[8];

        auStack_2c3[4] = s_I_m_cured__1403128a0[9];

        local_2c8[0] = s_I_m_cured__1403128a0[0];

        local_2c8[1] = s_I_m_cured__1403128a0[1];

        local_2c8[2] = s_I_m_cured__1403128a0[2];

        local_2c8[3] = s_I_m_cured__1403128a0[3];

        local_2c8[4] = s_I_m_cured__1403128a0[4];

        auStack_2c3[0] = s_I_m_cured__1403128a0[5];

        auStack_2c3[1] = s_I_m_cured__1403128a0[6];

        auStack_2c3[2] = s_I_m_cured__1403128a0[7];

        auStack_2c3._5_6_ = 0;

        uVar19 = CONCAT44(uVar23,DAT_140303758);

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),local_2c8,0,uVar19);

        if (0xf < uStack_2b0) {

          if ((0xfff < uStack_2b0 + 1) &&

             (0x1f < ((longlong)_local_2c8 - *(longlong *)((longlong)_local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        local_2b8 = _DAT_1403040a0;

        uStack_2b0 = _UNK_1403040a8;

        auStack_2c3[3] = s_UseSilver_1403128b0[8];

        local_2c8[0] = s_UseSilver_1403128b0[0];

        local_2c8[1] = s_UseSilver_1403128b0[1];

        local_2c8[2] = s_UseSilver_1403128b0[2];

        local_2c8[3] = s_UseSilver_1403128b0[3];

        local_2c8[4] = s_UseSilver_1403128b0[4];

        auStack_2c3[0] = s_UseSilver_1403128b0[5];

        auStack_2c3[1] = s_UseSilver_1403128b0[6];

        auStack_2c3[2] = s_UseSilver_1403128b0[7];

        auStack_2c3._4_7_ = 0;

        FUN_140040ca0(local_2c8,100,0,DAT_14039ca44,uVar19 & 0xffffffffffffff00);

        if (0xf < uStack_2b0) {

          if ((0xfff < uStack_2b0 + 1) &&

             (0x1f < ((longlong)_local_2c8 - *(longlong *)((longlong)_local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        FUN_1400b6820(*(undefined8 *)(param_1 + 600));

        FUN_1400cead0(param_1,*(undefined8 *)(param_1 + 600));

        *(undefined1 *)(param_1 + 0x26c) = 0;

        local_2b8 = _DAT_140305680;

        uStack_2b0 = _UNK_140305688;

        stack0xfffffffffffffd3c = ZEXT412(0);

        local_2c8 = (undefined1  [5])0x65727563;

        FUN_140037710(local_2c8);

        if (0xf < uStack_2b0) {

          if ((0xfff < uStack_2b0 + 1) &&

             (0x1f < ((longlong)_local_2c8 - *(longlong *)((longlong)_local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        *(undefined4 *)(param_1 + 0x260) = 4;

      }

    }

    else if (iVar7 == 2) {

      if ((*(int *)(param_1 + 0x1f8) == 0x10e) &&

         ((*(longlong *)(param_1 + 0x218) - *(longlong *)(param_1 + 0x210) & 0xffffffffffffffe0U) ==

          0x20)) {

        local_2b8 = _DAT_140305680;

        uStack_2b0 = _UNK_140305688;

        auStack_2c3._7_4_ = 0;

        auStack_2c3._0_7_ = SUB127(ZEXT812(0),5);

        local_2c8 = (undefined1  [5])0x72756f50;

        in_stack_fffffffffffffd08 = in_stack_fffffffffffffd08 & 0xffffffffffffff00;

        FUN_140040ca0(local_2c8,100,0,DAT_14039ca44,in_stack_fffffffffffffd08);

        if (0xf < uStack_2b0) {

          if ((0xfff < uStack_2b0 + 1) &&

             (0x1f < ((longlong)_local_2c8 - *(longlong *)((longlong)_local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

      if (*(longlong *)(param_1 + 0x210) == *(longlong *)(param_1 + 0x218)) {

        lVar9 = FUN_1400cc9d0(param_1,0xc,DAT_140303750,DAT_140303750);

        local_2b8 = _DAT_140304080;

        uStack_2b0 = _UNK_140304088;

        local_2c8 = (undefined1  [5])CONCAT14(s_freak_140303b30[4],s_freak_140303b30._0_4_);

        _local_2c8 = ZEXT516((uint5)local_2c8);

        FUN_1400a2ed0(local_268,local_2c8);

        if (0xf < uStack_2b0) {

          if ((0xfff < uStack_2b0 + 1) &&

             (0x1f < ((longlong)_local_2c8 - *(longlong *)((longlong)_local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        local_190 = (char *)CONCAT71(local_190._1_7_,3);

        local_a0 = 3;

        FUN_14005d190(lVar9,local_268);

        FUN_140104c00(DAT_1403fb0d8,

                      *(undefined4 *)(&DAT_140312628 + (longlong)*(int *)(param_1 + 0x264) * 4),0,0)

        ;

        *(undefined1 *)(param_1 + 0x26c) = 1;

        fVar5 = DAT_14030374c;

        fVar22 = DAT_14030335c;

        uVar23 = DAT_140303354;

        lVar18 = 0x20;

        do {

          FUN_1400c6ab0(&local_res8);

          local_res18 = local_res8 * fVar22 + *(float *)(lVar9 + 0x28);

          local_res1c = local_resc * fVar22 + *(float *)(lVar9 + 0x2c);

          local_res10 = local_res8 * fVar5;

          local_res14 = local_resc * fVar5;

          iVar7 = FUN_1400c6580(4);

          in_stack_fffffffffffffd08 = in_stack_fffffffffffffd08 & 0xffffffff00000000;

          FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x248),0xffffffff,&local_res18,&local_res10,

                        in_stack_fffffffffffffd08,0,&DAT_1403f4d90 + (longlong)iVar7 * 4,0x3c,uVar23

                       );

          lVar18 = lVar18 + -1;

        } while (lVar18 != 0);

        local_2b8 = _DAT_140304cc0;

        uStack_2b0 = _UNK_140304cc8;

        auStack_2c3[3] = s_PrizeAppear_14030e7f0[8];

        auStack_2c3[4] = s_PrizeAppear_14030e7f0[9];

        local_2c8[0] = s_PrizeAppear_14030e7f0[0];

        local_2c8[1] = s_PrizeAppear_14030e7f0[1];

        local_2c8[2] = s_PrizeAppear_14030e7f0[2];

        local_2c8[3] = s_PrizeAppear_14030e7f0[3];

        local_2c8[4] = s_PrizeAppear_14030e7f0[4];

        auStack_2c3[0] = s_PrizeAppear_14030e7f0[5];

        auStack_2c3[1] = s_PrizeAppear_14030e7f0[6];

        auStack_2c3[2] = s_PrizeAppear_14030e7f0[7];

        auStack_2c3[5] = s_PrizeAppear_14030e7f0[10];

        auStack_2c3._6_5_ = 0;

        FUN_140040ca0(local_2c8,100,0,uVar24,in_stack_fffffffffffffd08 & 0xffffffffffffff00);

        if (0xf < uStack_2b0) {

          if ((0xfff < uStack_2b0 + 1) &&

             (0x1f < ((longlong)_local_2c8 - *(longlong *)((longlong)_local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        *(undefined4 *)(param_1 + 0x260) = 3;

      }

    }

    else if (iVar7 == 3) {

      if (*(int *)(param_1 + 0x1f8) == 0) {

        *(undefined4 *)(param_1 + 0x260) = 1;

        FUN_1400f6010(param_1);

      }

    }

    else if (iVar7 == 4) {

      if (*(int *)(param_1 + 0x1f8) == 0) {

        local_2b8 = _DAT_140304cc0;

        uStack_2b0 = _UNK_140304cc8;

        auStack_2c3[3] = s_Remarkable__140312a30[8];

        auStack_2c3[4] = s_Remarkable__140312a30[9];

        local_2c8[0] = s_Remarkable__140312a30[0];

        local_2c8[1] = s_Remarkable__140312a30[1];

        local_2c8[2] = s_Remarkable__140312a30[2];

        local_2c8[3] = s_Remarkable__140312a30[3];

        local_2c8[4] = s_Remarkable__140312a30[4];

        auStack_2c3[0] = s_Remarkable__140312a30[5];

        auStack_2c3[1] = s_Remarkable__140312a30[6];

        auStack_2c3[2] = s_Remarkable__140312a30[7];

        auStack_2c3[5] = s_Remarkable__140312a30[10];

        auStack_2c3._6_5_ = 0;

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_2c8,0,

                      CONCAT44(uVar23,DAT_140303758));

        if (0xf < uStack_2b0) {

          if ((0xfff < uStack_2b0 + 1) &&

             (0x1f < ((longlong)_local_2c8 - *(longlong *)((longlong)_local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        *(undefined4 *)(param_1 + 0x260) = 6;

      }

    }

    else if (iVar7 == 5) {

      if (*(int *)(param_1 + 0x250) == 0x3c) {

        _local_2c8 = ZEXT416(0);

        local_2b8 = 0;

        uStack_2b0 = 0;

        pcVar12 = (char *)FUN_1400285e0(0x20);

        uVar11 = s_You_cured_me__I_m_so_happy__140312a40._8_8_;

        _local_2c8 = pcVar12;

        local_2b8 = _DAT_140304130;

        uStack_2b0 = _UNK_140304138;

        *(undefined8 *)pcVar12 = s_You_cured_me__I_m_so_happy__140312a40._0_8_;

        *(undefined8 *)(pcVar12 + 8) = uVar11;

        *(undefined8 *)(pcVar12 + 0x10) = s_You_cured_me__I_m_so_happy__140312a40._16_8_;

        *(undefined2 *)(pcVar12 + 0x18) = s_You_cured_me__I_m_so_happy__140312a40._24_2_;

        pcVar12[0x1a] = s_You_cured_me__I_m_so_happy__140312a40[0x1a];

        pcVar12[0x1b] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),local_2c8,0,DAT_140303758);

        if (0xf < uStack_2b0) {

          if ((0xfff < uStack_2b0 + 1) &&

             (0x1f < ((longlong)_local_2c8 - *(longlong *)((longlong)_local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        *(int *)(param_1 + 0x27c) = *(int *)(param_1 + 0x27c) + 1;

      }

      else if ((*(int *)(param_1 + 0x27c) == 1) && (*(int *)(param_1 + 0x1f8) == 0)) {

        _local_2c8 = ZEXT812(0);

        auStack_2c3._7_4_ = 0;

        local_2b8 = 0;

        uStack_2b0 = 0;

        pcVar12 = (char *)FUN_1400285e0(0x20);

        uVar11 = s_My_work_here_is_done_140312a60._8_8_;

        _local_2c8 = pcVar12;

        local_2b8 = _DAT_140303420;

        uStack_2b0 = _UNK_140303428;

        *(undefined8 *)pcVar12 = s_My_work_here_is_done_140312a60._0_8_;

        *(undefined8 *)(pcVar12 + 8) = uVar11;

        *(undefined4 *)(pcVar12 + 0x10) = s_My_work_here_is_done_140312a60._16_4_;

        pcVar12[0x14] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_2c8,0,DAT_140303758);

        if (0xf < uStack_2b0) {

          FUN_140028310(local_2c8,_local_2c8);

        }

        *(undefined4 *)(param_1 + 0x260) = 6;

        *(undefined4 *)(param_1 + 0x250) = 0;

      }

    }

    else if (iVar7 == 6) {

      if (*(int *)(param_1 + 0x1f8) == 0) {

        if (*(longlong *)(param_1 + 0x148) != 0) {

          local_2b8 = _DAT_1403040b0;

          uStack_2b0 = _UNK_1403040b8;

          auStack_2c3[3] = s_Justin_Smith_140307748[8];

          auStack_2c3[4] = s_Justin_Smith_140307748[9];

          auStack_2c3[5] = s_Justin_Smith_140307748[10];

          auStack_2c3[6] = s_Justin_Smith_140307748[0xb];

          local_2c8[0] = s_Justin_Smith_140307748[0];

          local_2c8[1] = s_Justin_Smith_140307748[1];

          local_2c8[2] = s_Justin_Smith_140307748[2];

          local_2c8[3] = s_Justin_Smith_140307748[3];

          local_2c8[4] = s_Justin_Smith_140307748[4];

          auStack_2c3[0] = s_Justin_Smith_140307748[5];

          auStack_2c3[1] = s_Justin_Smith_140307748[6];

          auStack_2c3[2] = s_Justin_Smith_140307748[7];

          auStack_2c3._7_4_ = 0;

          FUN_1400cf950(param_1,*(longlong *)(param_1 + 0x148),local_2c8);

          if (0xf < uStack_2b0) {

            FUN_140028310(local_2c8,_local_2c8);

          }

        }

        uVar23 = (undefined4)(in_stack_fffffffffffffd08 >> 0x20);

        _local_2c8 = ZEXT816(0);

        local_2b8 = 0;

        uStack_2b0 = 0;

        puVar8 = (undefined8 *)FUN_1400285e0(0x30);

        uVar11 = _UNK_140312a80;

        _local_2c8 = (char *)puVar8;

        local_2b8 = _DAT_140304d10;

        uStack_2b0 = _UNK_140304d18;

        *puVar8 = _DAT_140312a78;

        puVar8[1] = uVar11;

        uVar11 = _UNK_140312a90;

        puVar8[2] = _DAT_140312a88;

        puVar8[3] = uVar11;

        *(undefined4 *)(puVar8 + 4) = s_Horsey_Game_140312a91._7_4_;

        *(undefined1 *)((longlong)puVar8 + 0x24) = 0;

        uVar24 = DAT_140303758;

        uVar11 = CONCAT44(uVar23,DAT_140303758);

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_2c8,0,uVar11);

        uVar23 = (undefined4)((ulonglong)uVar11 >> 0x20);

        if (0xf < uStack_2b0) {

          FUN_140028310(local_2c8,_local_2c8);

        }

        _local_2c8 = ZEXT816(0);

        local_2b8 = 0;

        uStack_2b0 = 0;

        puVar8 = (undefined8 *)FUN_1400285e0(0x40);

        uVar11 = _UNK_140312aa8;

        _local_2c8 = (char *)puVar8;

        local_2b8 = _DAT_140306040;

        uStack_2b0 = _UNK_140306048;

        *puVar8 = _DAT_140312aa0;

        puVar8[1] = uVar11;

        uVar11 = _UNK_140312ab8;

        puVar8[2] = _DAT_140312ab0;

        puVar8[3] = uVar11;

        uVar11 = s_and_I_m_responsible_for_this_gam_140312abe._10_8_;

        puVar8[4] = s_and_I_m_responsible_for_this_gam_140312abe._2_8_;

        puVar8[5] = uVar11;

        puVar8[6] = s_and_I_m_responsible_for_this_gam_140312abe._18_8_;

        *(undefined4 *)(puVar8 + 7) = s_and_I_m_responsible_for_this_gam_140312abe._26_4_;

        *(undefined2 *)((longlong)puVar8 + 0x3c) =

             s_and_I_m_responsible_for_this_gam_140312abe._30_2_;

        *(char *)((longlong)puVar8 + 0x3e) = s_and_I_m_responsible_for_this_gam_140312abe[0x20];

        *(undefined1 *)((longlong)puVar8 + 0x3f) = 0;

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_2c8,0,CONCAT44(uVar23,uVar24));

        FUN_140027900(local_2c8);

        if (*(longlong *)(param_1 + 600) != 0) {

          uVar11 = *(undefined8 *)(param_1 + 0x148);

          FUN_1400cf9a0(param_1);

          FUN_1400d1c40(param_1,uVar11,"Show the credits, %s");

        }

        *(undefined4 *)(param_1 + 0x260) = 7;

        *(undefined4 *)(param_1 + 0x27c) = 0;

        *(undefined4 *)(param_1 + 0x250) = 0;

      }

    }

    else if (iVar7 == 7) {

      if ((*(longlong *)(param_1 + 0x148) == 0) || (cVar6 = FUN_1400b4af0(), cVar6 == '\0')) {

        bVar3 = false;

      }

      else {

        bVar3 = true;

      }

      if ((*(longlong *)(param_1 + 600) == 0) || (cVar6 = FUN_1400b4af0(), cVar6 == '\0')) {

        bVar4 = false;

      }

      else {

        bVar4 = true;

      }

      if ((bVar3) || (bVar4)) {

        if (*(int *)(param_1 + 0x1f8) == 0) {

          local_2a0 = (longlong *)0x0;

          plStack_298 = (longlong *)0x0;

          local_290 = (longlong *)0x0;

          lVar9 = *(longlong *)(param_1 + 0x130);

          plVar17 = (longlong *)0x0;

          uVar20 = uVar19;

          if (*(longlong *)(param_1 + 0x138) - lVar9 >> 3 != 0) {

            do {

              lVar9 = *(longlong *)(lVar9 + uVar19);

              if ((lVar9 != *(longlong *)(param_1 + 600)) &&

                 (lVar9 != *(longlong *)(param_1 + 0x148))) {

                if (plVar17 == local_290) {

                  FUN_140030680(&local_2a0);

                  plVar17 = plStack_298;

                }

                else {

                  *plVar17 = lVar9;

                  plStack_298 = plStack_298 + 1;

                  plVar17 = plStack_298;

                }

              }

              uVar16 = (int)uVar20 + 1;

              uVar19 = uVar19 + 8;

              lVar9 = *(longlong *)(param_1 + 0x130);

              uVar20 = (ulonglong)uVar16;

            } while ((ulonglong)(longlong)(int)uVar16 <

                     (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar9 >> 3));

          }

          if (*(uint *)(param_1 + 0x27c) == 3) {

            if (local_2a0 == plVar17) {

LAB_1400f83c4:

              lVar9 = 0x148;

              if (!bVar3) {

                lVar9 = 600;

              }

              lVar9 = *(longlong *)(lVar9 + param_1);

            }

            else {

              lVar9 = *local_2a0;

              local_2b8 = _DAT_140303400;

              uStack_2b0 = _UNK_140303408;

              auStack_2c3[3] = s_Thx_For_Playing_140312af8[8];

              auStack_2c3[4] = s_Thx_For_Playing_140312af8[9];

              auStack_2c3[5] = s_Thx_For_Playing_140312af8[10];

              auStack_2c3[6] = s_Thx_For_Playing_140312af8[0xb];

              local_2c8[0] = s_Thx_For_Playing_140312af8[0];

              local_2c8[1] = s_Thx_For_Playing_140312af8[1];

              local_2c8[2] = s_Thx_For_Playing_140312af8[2];

              local_2c8[3] = s_Thx_For_Playing_140312af8[3];

              local_2c8[4] = s_Thx_For_Playing_140312af8[4];

              auStack_2c3[0] = s_Thx_For_Playing_140312af8[5];

              auStack_2c3[1] = s_Thx_For_Playing_140312af8[6];

              auStack_2c3[2] = s_Thx_For_Playing_140312af8[7];

              auStack_2c3[7] = s_Thx_For_Playing_140312af8[0xc];

              auStack_2c3[8] = s_Thx_For_Playing_140312af8[0xd];

              auStack_2c3[9] = s_Thx_For_Playing_140312af8[0xe];

              auStack_2c3[10] = 0;

              FUN_1400cf950(param_1,lVar9,local_2c8);

              if (0xf < uStack_2b0) {

                FUN_140028310(local_2c8,_local_2c8);

              }

              if ((*(char *)(lVar9 + 0x1a) == '\0') &&

                 (pfVar10 = (float *)FUN_1400b4a10(lVar9,&local_res8), DAT_14039ca58 < *pfVar10)) {

                *(undefined1 *)(lVar9 + 0x1a) = 1;

                FUN_1400b47e0(lVar9);

                FUN_1400cead0(param_1,lVar9);

              }

            }

          }

          else {

            uVar16 = *(uint *)(param_1 + 0x27c) & 0x80000001;

            if ((int)uVar16 < 0) {

              uVar16 = (uVar16 - 1 | 0xfffffffe) + 1;

            }

            if (uVar16 == 1) goto LAB_1400f83c4;

            lVar9 = 600;

            if (!bVar4) {

              lVar9 = 0x148;

            }

            lVar9 = *(longlong *)(lVar9 + param_1);

          }

          uVar24 = DAT_140303758;

          iVar7 = *(int *)(param_1 + 0x27c);

          if (iVar7 == 0) {

            local_2b8 = _DAT_140304090;

            uStack_2b0 = _UNK_140304098;

            _local_2c8 = (unkuint9)0x6c6c6f726d757244;

            auStack_2c3._4_7_ = 0;

            in_stack_fffffffffffffd08 = in_stack_fffffffffffffd08 & 0xffffffffffffff00;

            FUN_140040ca0(local_2c8,100,0,DAT_14039ca44,in_stack_fffffffffffffd08);

            uVar23 = (undefined4)(in_stack_fffffffffffffd08 >> 0x20);

            FUN_140027900(local_2c8);

            uVar24 = DAT_140303758;

            local_2b8 = _DAT_140303400;

            uStack_2b0 = _UNK_140303408;

            auStack_2c3[3] = s_Game_credits____140312b08[8];

            auStack_2c3[4] = s_Game_credits____140312b08[9];

            auStack_2c3[5] = s_Game_credits____140312b08[10];

            auStack_2c3[6] = s_Game_credits____140312b08[0xb];

            local_2c8[0] = s_Game_credits____140312b08[0];

            local_2c8[1] = s_Game_credits____140312b08[1];

            local_2c8[2] = s_Game_credits____140312b08[2];

            local_2c8[3] = s_Game_credits____140312b08[3];

            local_2c8[4] = s_Game_credits____140312b08[4];

            auStack_2c3[0] = s_Game_credits____140312b08[5];

            auStack_2c3[1] = s_Game_credits____140312b08[6];

            auStack_2c3[2] = s_Game_credits____140312b08[7];

            auStack_2c3[7] = s_Game_credits____140312b08[0xc];

            auStack_2c3[8] = s_Game_credits____140312b08[0xd];

            auStack_2c3[9] = s_Game_credits____140312b08[0xe];

            auStack_2c3[10] = 0;

            uVar11 = CONCAT44(uVar23,DAT_140303758);

            FUN_1400d0c80(param_1,lVar9,local_2c8,0,uVar11);

            uVar23 = (undefined4)((ulonglong)uVar11 >> 0x20);

            if (0xf < uStack_2b0) {

              FUN_140028310(local_2c8,_local_2c8);

            }

            _local_2c8 = ZEXT816(0);

            local_2b8 = 0;

            uStack_2b0 = 0;

            puVar8 = (undefined8 *)FUN_1400285e0(0x30);

            uVar11 = _UNK_140312b20;

            _local_2c8 = (char *)puVar8;

            local_2b8 = _DAT_140304160;

            uStack_2b0 = _UNK_140304168;

            *puVar8 = _DAT_140312b18;

            puVar8[1] = uVar11;

            uVar11 = s_Marlon_Wiebe_140312b2d._3_8_;

            puVar8[2] = _DAT_140312b28;

            puVar8[3] = uVar11;

            *(char *)(puVar8 + 4) = s_Marlon_Wiebe_140312b2d[0xb];

            *(undefined1 *)((longlong)puVar8 + 0x21) = 0;

            FUN_1400d0c80(param_1,lVar9,local_2c8,0,CONCAT44(uVar23,uVar24));

LAB_1400f8fb4:

            if (0xf < uStack_2b0) {

              FUN_140028310(local_2c8,_local_2c8);

            }

          }

          else {

            if (iVar7 == 1) {

              if (lVar9 != DAT_1403f4de0) {

                local_2b8 = _DAT_140304090;

                uStack_2b0 = _UNK_140304098;

                _local_2c8 = (unkuint9)0x21676e697a616d41;

                auStack_2c3._4_7_ = 0;

                in_stack_fffffffffffffd08 =

                     CONCAT44((int)(in_stack_fffffffffffffd08 >> 0x20),DAT_140303758);

                FUN_1400d0c80(param_1,lVar9,local_2c8,0,in_stack_fffffffffffffd08);

                if (0xf < uStack_2b0) {

                  FUN_140028310(local_2c8,_local_2c8);

                }

                local_2b8 = _DAT_140304090;

                uStack_2b0 = _UNK_140304098;

                _local_2c8 = (unkuint9)0x676e697070616c43;

                auStack_2c3._4_7_ = 0;

                in_stack_fffffffffffffd08 = in_stack_fffffffffffffd08 & 0xffffffffffffff00;

                FUN_140040ca0(local_2c8,100,0,DAT_14039ca44,in_stack_fffffffffffffd08);

                if (0xf < uStack_2b0) {

                  FUN_140028310(local_2c8,_local_2c8);

                }

              }

              uVar23 = (undefined4)(in_stack_fffffffffffffd08 >> 0x20);

              _local_2c8 = ZEXT816(0);

              local_2b8 = 0;

              uStack_2b0 = 0;

              puVar8 = (undefined8 *)FUN_1400285e0(0x20);

              uVar11 = _UNK_140312b48;

              _local_2c8 = (char *)puVar8;

              local_2b8 = _DAT_140303770;

              uStack_2b0 = _UNK_140303778;

              *puVar8 = _DAT_140312b40;

              puVar8[1] = uVar11;

              puVar8[2] = s_Chevy_Ray_Johnston_140312b4c._4_8_;

              *(undefined4 *)(puVar8 + 3) = s_Chevy_Ray_Johnston_140312b4c._12_4_;

              *(undefined2 *)((longlong)puVar8 + 0x1c) = s_Chevy_Ray_Johnston_140312b4c._16_2_;

              *(undefined1 *)((longlong)puVar8 + 0x1e) = 0;

              FUN_1400d0c80(param_1,lVar9,local_2c8,0,CONCAT44(uVar23,uVar24));

              goto LAB_1400f8fb4;

            }

            if (iVar7 == 2) {

              if (lVar9 != DAT_1403f4de0) {

                _local_2c8 = ZEXT816(0);

                local_2b8 = 0;

                uStack_2b0 = 0;

                pcVar12 = (char *)FUN_1400285e0(0x20);

                uVar11 = s_Deserves_some_credit__140312b60._8_8_;

                _local_2c8 = pcVar12;

                local_2b8 = _DAT_140304110;

                uStack_2b0 = _UNK_140304118;

                *(undefined8 *)pcVar12 = s_Deserves_some_credit__140312b60._0_8_;

                *(undefined8 *)(pcVar12 + 8) = uVar11;

                *(undefined4 *)(pcVar12 + 0x10) = s_Deserves_some_credit__140312b60._16_4_;

                pcVar12[0x14] = s_Deserves_some_credit__140312b60[0x14];

                pcVar12[0x15] = '\0';

                in_stack_fffffffffffffd08 =

                     CONCAT44((int)(in_stack_fffffffffffffd08 >> 0x20),uVar24);

                FUN_1400d0c80(param_1,lVar9,local_2c8,0,in_stack_fffffffffffffd08);

                if (0xf < uStack_2b0) {

                  FUN_140028310(local_2c8,_local_2c8);

                }

                local_2b8 = _DAT_140304090;

                uStack_2b0 = _UNK_140304098;

                _local_2c8 = (unkuint9)0x676e697070616c43;

                auStack_2c3._4_7_ = 0;

                in_stack_fffffffffffffd08 = in_stack_fffffffffffffd08 & 0xffffffffffffff00;

                FUN_140040ca0(local_2c8,100,0,DAT_14039ca44,in_stack_fffffffffffffd08);

                if (0xf < uStack_2b0) {

                  FUN_140028310(local_2c8,_local_2c8);

                }

              }

              uVar23 = (undefined4)(in_stack_fffffffffffffd08 >> 0x20);

              _local_2c8 = ZEXT816(0);

              local_2b8 = 0;

              uStack_2b0 = 0;

              puVar8 = (undefined8 *)FUN_1400285e0(0x50);

              uVar11 = _UNK_140312b88;

              _local_2c8 = (char *)puVar8;

              local_2b8 = _DAT_140306050;

              uStack_2b0 = _UNK_140306058;

              *puVar8 = _DAT_140312b80;

              puVar8[1] = uVar11;

              uVar11 = _UNK_140312b98;

              puVar8[2] = _DAT_140312b90;

              puVar8[3] = uVar11;

              uVar11 = _UNK_140312ba8;

              puVar8[4] = _DAT_140312ba0;

              puVar8[5] = uVar11;

              uVar11 = s_Kris_Piotrowski_140312bb4._4_8_;

              puVar8[6] = _DAT_140312bb0;

              puVar8[7] = uVar11;

              *(undefined2 *)(puVar8 + 8) = s_Kris_Piotrowski_140312bb4._12_2_;

              *(char *)((longlong)puVar8 + 0x42) = s_Kris_Piotrowski_140312bb4[0xe];

              *(undefined1 *)((longlong)puVar8 + 0x43) = 0;

              uVar11 = CONCAT44(uVar23,uVar24);

              FUN_1400d0c80(param_1,lVar9,local_2c8,0,uVar11);

              uVar24 = (undefined4)((ulonglong)uVar11 >> 0x20);

              if (0xf < uStack_2b0) {

                FUN_140028310(local_2c8,_local_2c8);

              }

              _local_2c8 = ZEXT816(0);

              local_2b8 = 0;

              uStack_2b0 = 0;

              puVar8 = (undefined8 *)FUN_1400285e0(0x30);

              uVar11 = _UNK_140312bd0;

              _local_2c8 = (char *)puVar8;

              local_2b8 = _DAT_1403041a0;

              uStack_2b0 = _UNK_1403041a8;

              *puVar8 = _DAT_140312bc8;

              puVar8[1] = uVar11;

              uVar11 = s_Vancouver_Game_Garden_140312bde._2_8_;

              puVar8[2] = _DAT_140312bd8;

              puVar8[3] = uVar11;

              puVar8[4] = s_Vancouver_Game_Garden_140312bde._10_8_;

              *(undefined2 *)(puVar8 + 5) = s_Vancouver_Game_Garden_140312bde._18_2_;

              *(char *)((longlong)puVar8 + 0x2a) = s_Vancouver_Game_Garden_140312bde[0x14];

              *(undefined1 *)((longlong)puVar8 + 0x2b) = 0;

              FUN_1400d0c80(param_1,lVar9,local_2c8,0,CONCAT44(uVar24,DAT_140304c38));

              if (0xf < uStack_2b0) {

                FUN_140028310(local_2c8,_local_2c8);

              }

              *(undefined4 *)(param_1 + 0x280) = 0xffffffff;

            }

            else {

              if (iVar7 != 3) {

                if (iVar7 == 4) {

                  _local_2c8 = ZEXT816(0);

                  local_2b8 = 0;

                  uStack_2b0 = 0;

                  pcVar12 = (char *)FUN_1400285e0(0x20);

                  uVar11 = s_Big_list_of_thanks_coming_up____140312ce0._8_8_;

                  _local_2c8 = pcVar12;

                  local_2b8 = _DAT_140304140;

                  uStack_2b0 = _UNK_140304148;

                  *(undefined8 *)pcVar12 = s_Big_list_of_thanks_coming_up____140312ce0._0_8_;

                  *(undefined8 *)(pcVar12 + 8) = uVar11;

                  *(undefined8 *)(pcVar12 + 0x10) =

                       s_Big_list_of_thanks_coming_up____140312ce0._16_8_;

                  *(undefined4 *)(pcVar12 + 0x18) =

                       s_Big_list_of_thanks_coming_up____140312ce0._24_4_;

                  *(undefined2 *)(pcVar12 + 0x1c) =

                       s_Big_list_of_thanks_coming_up____140312ce0._28_2_;

                  pcVar12[0x1e] = s_Big_list_of_thanks_coming_up____140312ce0[0x1e];

                  pcVar12[0x1f] = '\0';

                  uVar24 = DAT_140303758;

                  uVar11 = CONCAT44((int)(in_stack_fffffffffffffd08 >> 0x20),DAT_140303758);

                  FUN_1400d0c80(param_1,lVar9,local_2c8,0,uVar11);

                  uVar23 = (undefined4)((ulonglong)uVar11 >> 0x20);

                  if (0xf < uStack_2b0) {

                    FUN_140028310(local_2c8,_local_2c8);

                  }

                  _local_2c8 = ZEXT816(0);

                  local_2b8 = 0;

                  uStack_2b0 = 0;

                  pcVar12 = (char *)FUN_1400285e0(0x40);

                  uVar11 = s_Thanks_to_Christa_Kaufmann__Lan_R_140312d00._8_8_;

                  _local_2c8 = pcVar12;

                  local_2b8 = _DAT_14030fc40;

                  uStack_2b0 = _UNK_14030fc48;

                  *(undefined8 *)pcVar12 = s_Thanks_to_Christa_Kaufmann__Lan_R_140312d00._0_8_;

                  *(undefined8 *)(pcVar12 + 8) = uVar11;

                  uVar11 = s_Thanks_to_Christa_Kaufmann__Lan_R_140312d00._24_8_;

                  *(undefined8 *)(pcVar12 + 0x10) =

                       s_Thanks_to_Christa_Kaufmann__Lan_R_140312d00._16_8_;

                  *(undefined8 *)(pcVar12 + 0x18) = uVar11;

                  uVar11 = s_Thanks_to_Christa_Kaufmann__Lan_R_140312d00._40_8_;

                  *(undefined8 *)(pcVar12 + 0x20) =

                       s_Thanks_to_Christa_Kaufmann__Lan_R_140312d00._32_8_;

                  *(undefined8 *)(pcVar12 + 0x28) = uVar11;

                  *(undefined8 *)(pcVar12 + 0x30) =

                       s_Thanks_to_Christa_Kaufmann__Lan_R_140312d00._48_8_;

                  *(undefined4 *)(pcVar12 + 0x38) =

                       s_Thanks_to_Christa_Kaufmann__Lan_R_140312d00._56_4_;

                  pcVar12[0x3c] = '\0';

                  FUN_1400d0c80(param_1,lVar9,local_2c8,0,CONCAT44(uVar23,uVar24));

                }

                else {

                  if (iVar7 != 5) {

                    if (iVar7 == 6) {

                      _local_2c8 = ZEXT816(0);

                      local_2b8 = 0;

                      uStack_2b0 = 0;

                      pcVar12 = (char *)FUN_1400285e0(0x40);

                      uVar11 = s_Brace_Yourself_Games_and_The_Exp_140312d78._8_8_;

                      _local_2c8 = pcVar12;

                      local_2b8 = _DAT_140312f20;

                      uStack_2b0 = _UNK_140312f28;

                      *(undefined8 *)pcVar12 = s_Brace_Yourself_Games_and_The_Exp_140312d78._0_8_;

                      *(undefined8 *)(pcVar12 + 8) = uVar11;

                      uVar11 = s_Brace_Yourself_Games_and_The_Exp_140312d78._24_8_;

                      *(undefined8 *)(pcVar12 + 0x10) =

                           s_Brace_Yourself_Games_and_The_Exp_140312d78._16_8_;

                      *(undefined8 *)(pcVar12 + 0x18) = uVar11;

                      uVar11 = s_Brace_Yourself_Games_and_The_Exp_140312d78._40_8_;

                      *(undefined8 *)(pcVar12 + 0x20) =

                           s_Brace_Yourself_Games_and_The_Exp_140312d78._32_8_;

                      *(undefined8 *)(pcVar12 + 0x28) = uVar11;

                      *(undefined8 *)(pcVar12 + 0x30) =

                           s_Brace_Yourself_Games_and_The_Exp_140312d78._48_8_;

                      pcVar12[0x38] = s_Brace_Yourself_Games_and_The_Exp_140312d78[0x38];

                      pcVar12[0x39] = '\0';

                      FUN_1400d0c80(param_1,lVar9,local_2c8,0,DAT_140303758);

                      FUN_140027900(local_2c8);

                    }

                    else {

                      if (iVar7 == 7) {

                        _local_2c8 = ZEXT816(0);

                        local_2b8 = 0;

                        uStack_2b0 = 0;

                        pcVar12 = (char *)FUN_1400285e0(0x20);

                        uVar11 = s_and_on_the_technical_side____140312db8._8_8_;

                        local_2b8 = _DAT_140304cf0;

                        uStack_2b0 = _UNK_140304cf8;

                        *(undefined8 *)pcVar12 = s_and_on_the_technical_side____140312db8._0_8_;

                        *(undefined8 *)(pcVar12 + 8) = uVar11;

                        *(undefined8 *)(pcVar12 + 0x10) =

                             s_and_on_the_technical_side____140312db8._16_8_;

                        *(undefined4 *)(pcVar12 + 0x18) =

                             s_and_on_the_technical_side____140312db8._24_4_;

                        pcVar12[0x1c] = '\0';

                        uVar24 = DAT_140303758;

                        uVar11 = CONCAT44((int)(in_stack_fffffffffffffd08 >> 0x20),DAT_140303758);

                        _local_2c8 = pcVar12;

                        FUN_1400d0c80(param_1,lVar9,local_2c8,0,uVar11);

                        uVar23 = (undefined4)((ulonglong)uVar11 >> 0x20);

                        FUN_140027900(local_2c8);

                        FUN_140027980(local_2c8,"Erin Catto, Randy Gaul, Brian Fiete,  ");

                        uVar11 = CONCAT44(uVar23,uVar24);

                        FUN_1400d0c80(param_1,lVar9,local_2c8,0,uVar11);

                        uVar23 = (undefined4)((ulonglong)uVar11 >> 0x20);

                        FUN_140027900(local_2c8);

                        FUN_140027980(local_2c8,&DAT_140312e00);

                        uVar11 = CONCAT44(uVar23,uVar24);

                        FUN_1400d0c80(param_1,lVar9,local_2c8,0,uVar11);

                        uVar23 = (undefined4)((ulonglong)uVar11 >> 0x20);

                        FUN_140027900(local_2c8);

                        _local_2c8 = ZEXT816(0);

                        local_2b8 = 0;

                        uStack_2b0 = 0;

                        pcVar12 = (char *)FUN_1400285e0(0x30);

                        uVar11 = s_and_everyone_who_contributed_hor_140312e28._8_8_;

                        _local_2c8 = pcVar12;

                        local_2b8 = _DAT_14030fc30;

                        uStack_2b0 = _UNK_14030fc38;

                        *(undefined8 *)pcVar12 = s_and_everyone_who_contributed_hor_140312e28._0_8_;

                        *(undefined8 *)(pcVar12 + 8) = uVar11;

                        uVar11 = s_and_everyone_who_contributed_hor_140312e28._24_8_;

                        *(undefined8 *)(pcVar12 + 0x10) =

                             s_and_everyone_who_contributed_hor_140312e28._16_8_;

                        *(undefined8 *)(pcVar12 + 0x18) = uVar11;

                        *(undefined8 *)(pcVar12 + 0x20) =

                             s_and_everyone_who_contributed_hor_140312e28._32_8_;

                        pcVar12[0x28] = s_and_everyone_who_contributed_hor_140312e28[0x28];

                        pcVar12[0x29] = '\0';

                        FUN_1400d0c80(param_1,lVar9,local_2c8,0,CONCAT44(uVar23,uVar24));

                        goto LAB_1400f8fb4;

                      }

                      uVar16 = iVar7 - 8;

                      if ((int)uVar16 < 0xa2) {

                        if (uVar16 == 0) {

                          if (lVar9 != DAT_1403f4de0) {

                            FUN_140027980(local_2c8,"Don\'t forget freesound.org!");

                            in_stack_fffffffffffffd08 =

                                 CONCAT44((int)(in_stack_fffffffffffffd08 >> 0x20),DAT_140303758);

                            FUN_1400d0c80(param_1,lVar9,local_2c8,0,in_stack_fffffffffffffd08);

                            FUN_140027900(local_2c8);

                            FUN_140027980(local_2c8,"Clapping");

                            in_stack_fffffffffffffd08 =

                                 in_stack_fffffffffffffd08 & 0xffffffffffffff00;

                            FUN_140040ca0(local_2c8,100,0,DAT_14039ca44,in_stack_fffffffffffffd08);

                            FUN_140027900(local_2c8);

                          }

                        }

                        else if ((0 < (int)uVar16) && (lVar9 != DAT_1403f4de0)) {

                          FUN_140027980(local_2c8,

                                        (&PTR_s_Ting__1403db100)[((longlong)iVar7 + -9) * 3]);

                          in_stack_fffffffffffffd08 =

                               CONCAT44((int)(in_stack_fffffffffffffd08 >> 0x20),DAT_140303758);

                          FUN_1400d0c80(param_1,lVar9,local_2c8,0,in_stack_fffffffffffffd08);

                          FUN_140027900(local_2c8);

                          if (4 < (int)uVar16) {

                            uVar16 = uVar16 & 0x80000003;

                            if ((int)uVar16 < 0) {

                              uVar16 = (uVar16 - 1 | 0xfffffffc) + 1;

                            }

                            if (uVar16 == 1) {

                              FUN_140027980(local_2c8,"Clapping");

                              in_stack_fffffffffffffd08 =

                                   in_stack_fffffffffffffd08 & 0xffffffffffffff00;

                              FUN_140040ca0(local_2c8,100,0,DAT_14039ca44,in_stack_fffffffffffffd08)

                              ;

                              FUN_140027900(local_2c8);

                            }

                          }

                          if ((iVar7 == 0xa2) && (local_2a0 != plStack_298)) {

                            FUN_1400f9b20(*local_2a0 + 0x168);

                            FUN_1400b87e0(*local_2a0);

                          }

                        }

                        uVar24 = (undefined4)(in_stack_fffffffffffffd08 >> 0x20);

                        uVar11 = FUN_14008d760(local_2c8,&DAT_140312e78,

                                               (&PTR_s_metal_tube_1_1403db0f8)

                                               [((longlong)iVar7 + -8) * 3]);

                        FUN_1400d0c80(param_1,lVar9,uVar11,0,CONCAT44(uVar24,DAT_140304c38));

                        FUN_140027900(local_2c8);

                      }

                      else if (iVar7 == 0xaa) {

                        FUN_140027980(local_2c8,"That\'s it\nThanks everyone");

                        FUN_1400d0c80(param_1,lVar9,local_2c8,0,DAT_140303758);

                        FUN_140027900(local_2c8);

                      }

                      else if (iVar7 == 0xab) {

                        FUN_140027980(local_2c8,"You can keep playing if you want");

                        uVar24 = DAT_140303758;

                        uVar11 = CONCAT44((int)(in_stack_fffffffffffffd08 >> 0x20),DAT_140303758);

                        FUN_1400d0c80(param_1,lVar9,local_2c8,0,uVar11);

                        uVar23 = (undefined4)((ulonglong)uVar11 >> 0x20);

                        FUN_140027900(local_2c8);

                        FUN_140027980(local_2c8,"What if there\'s stuff you missed?!");

                        FUN_1400d0c80(param_1,lVar9,local_2c8,0,CONCAT44(uVar23,uVar24));

                        FUN_140027900(local_2c8);

                        *(undefined4 *)(param_1 + 0x260) = 8;

                        *(undefined4 *)(param_1 + 0x250) = 0;

                      }

                    }

                    goto LAB_1400f9294;

                  }

                  _local_2c8 = ZEXT816(0);

                  local_2b8 = 0;

                  uStack_2b0 = 0;

                  pcVar12 = (char *)FUN_1400285e0(0x40);

                  uVar11 = s_John_Guerra__Lindsay_Jorgensen__A_140312d40._8_8_;

                  _local_2c8 = pcVar12;

                  local_2b8 = _DAT_140307a70;

                  uStack_2b0 = _UNK_140307a78;

                  *(undefined8 *)pcVar12 = s_John_Guerra__Lindsay_Jorgensen__A_140312d40._0_8_;

                  *(undefined8 *)(pcVar12 + 8) = uVar11;

                  uVar11 = s_John_Guerra__Lindsay_Jorgensen__A_140312d40._24_8_;

                  *(undefined8 *)(pcVar12 + 0x10) =

                       s_John_Guerra__Lindsay_Jorgensen__A_140312d40._16_8_;

                  *(undefined8 *)(pcVar12 + 0x18) = uVar11;

                  uVar11 = s_John_Guerra__Lindsay_Jorgensen__A_140312d40._40_8_;

                  *(undefined8 *)(pcVar12 + 0x20) =

                       s_John_Guerra__Lindsay_Jorgensen__A_140312d40._32_8_;

                  *(undefined8 *)(pcVar12 + 0x28) = uVar11;

                  *(undefined4 *)(pcVar12 + 0x30) =

                       s_John_Guerra__Lindsay_Jorgensen__A_140312d40._48_4_;

                  *(undefined2 *)(pcVar12 + 0x34) =

                       s_John_Guerra__Lindsay_Jorgensen__A_140312d40._52_2_;

                  pcVar12[0x36] = '\0';

                  FUN_1400d0c80(param_1,lVar9,local_2c8,0,DAT_140303758);

                }

                goto LAB_1400f8fb4;

              }

              local_268[0] = "Aaron Gordon";

              local_268[1] = "Horse";

              local_258[0] = 0x1e;

              local_250 = "Andrew Stewart";

              local_248 = "Horse";

              local_240 = 0;

              local_238 = "Dakota Bosman-Kennedy";

              local_230 = "Horse";

              local_228 = 6;

              local_220 = "David \"Doc\" Froese";

              local_218 = "Horse";

              local_210 = 0x26;

              local_208 = "Helen Phan";

              local_200 = "Horse";

              local_1f0 = "Hide Sakanoi";

              local_1e8 = "SmartHuman";

              local_1e0 = 10;

              local_1d8 = "Katie Rand";

              local_1d0 = "Horse";

              local_1c8 = 0x2d;

              local_1c0 = "Kyle Engelmann";

              local_1b8 = "Horse";

              local_1b0 = 10;

              local_1a8 = "Marlon Wiebe";

              local_1a0 = "Horse";

              local_198 = 0xd;

              local_190 = "Matthew Dawson";

              local_188 = "Horse";

              local_180 = 0x10;

              local_178 = "Ryan Clark";

              local_170 = "Horse";

              local_168 = 0x13;

              *(uint *)(lVar9 + 600) = *(uint *)(lVar9 + 600) | 1;

              puVar8 = (undefined8 *)(lVar9 + 0x168);

              local_1f8 = iVar7;

              FUN_1400278e0(puVar8,&DAT_14030db60);

              uVar24 = (undefined4)(in_stack_fffffffffffffd08 >> 0x20);

              _local_2c8 = ZEXT816(0);

              local_2b8 = 0;

              uStack_2b0 = 0;

              if (*(int *)(param_1 + 0x280) == -1) {

                pcVar12 = (char *)FUN_1400285e0(0x20);

                uVar11 = s_Horse_whinnies_by____140312cc8._8_8_;

                _local_2c8 = pcVar12;

                local_2b8 = _DAT_140303420;

                uStack_2b0 = _UNK_140303428;

                *(undefined8 *)pcVar12 = s_Horse_whinnies_by____140312cc8._0_8_;

                *(undefined8 *)(pcVar12 + 8) = uVar11;

                *(undefined4 *)(pcVar12 + 0x10) = s_Horse_whinnies_by____140312cc8._16_4_;

                pcVar12[0x14] = '\0';

                FUN_1400d0c80(param_1,lVar9,local_2c8,0,CONCAT44(uVar24,DAT_140303758));

                FUN_140027900(local_2c8);

              }

              else {

                pcVar12 = *(char **)((longlong)local_258 +

                                    ((longlong)*(int *)(param_1 + 0x280) * 3 + -1) * 8);

                sVar13 = strlen(pcVar12);

                FUN_140027e30(local_2c8,pcVar12,sVar13);

                uVar11 = CONCAT44(uVar24,DAT_14039ca44);

                FUN_140040b20(local_2c8,

                              *(undefined4 *)

                               ((longlong)local_258 + (longlong)*(int *)(param_1 + 0x280) * 3 * 8),

                              100,0,uVar11,in_stack_fffffffffffffd10 & 0xffffff00);

                uVar24 = (undefined4)((ulonglong)uVar11 >> 0x20);

                FUN_140027900(local_2c8);

                pcVar12 = local_268[(longlong)*(int *)(param_1 + 0x280) * 3];

                _local_2c8 = ZEXT816(0);

                local_2b8 = 0;

                uStack_2b0 = 0;

                sVar13 = strlen(pcVar12);

                FUN_140027e30(local_2c8,pcVar12,sVar13);

                FUN_1400d0c80(param_1,lVar9,local_2c8,0,CONCAT44(uVar24,DAT_140303758));

                if (0xf < uStack_2b0) {

                  FUN_140028310(local_2c8,_local_2c8);

                }

              }

              *(undefined8 *)(lVar9 + 0x178) = 0;

              if (0xf < *(ulonglong *)(lVar9 + 0x180)) {

                puVar8 = (undefined8 *)*puVar8;

              }

              *(undefined1 *)puVar8 = 0;

              *(int *)(param_1 + 0x280) = *(int *)(param_1 + 0x280) + 1;

              if (*(uint *)(param_1 + 0x280) < 0xb) {

                *(int *)(param_1 + 0x27c) = *(int *)(param_1 + 0x27c) + -1;

              }

            }

          }

LAB_1400f9294:

          DAT_1403f4de0 = lVar9;

          *(int *)(param_1 + 0x27c) = *(int *)(param_1 + 0x27c) + 1;

          if (local_2a0 != (longlong *)0x0) {

            if ((0xfff < ((longlong)local_290 - (longlong)local_2a0 & 0xfffffffffffffff8U)) &&

               (0x1f < (ulonglong)((longlong)local_2a0 + (-8 - local_2a0[-1])))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            goto LAB_1400f92db;

          }

        }

      }

      else {

        *(undefined4 *)(param_1 + 0x260) = 8;

      }

    }

  }

  if (((*(int *)(param_1 + 0xe0) == 1) || (*(int *)(param_1 + 0xe0) == 0)) &&

     (0 < *(int *)(param_1 + 0x270))) {

    FUN_140104b20(DAT_1403fb0d8,*(int *)(param_1 + 0x270),0);

    *(undefined4 *)(param_1 + 0x270) = 0;

  }

  if (*(int *)(param_1 + 0xe0) == 0) {

    if (*(int *)(param_1 + 0x260) == 0) {

      *(undefined4 *)(param_1 + 0x260) = 1;

    }

    if (*(longlong *)(param_1 + 600) != 0) {

      pcVar12 = (char *)FUN_1400cf970(param_1);

      _local_2c8 = ZEXT816(0);

      local_2b8 = 0;

      uStack_2b0 = 0;

      sVar13 = strlen(pcVar12);

      FUN_140027e30(local_2c8,pcVar12,sVar13);

      puVar14 = (ulonglong *)FUN_140027810(local_2c8,"\'s House");

      uVar19 = *puVar14;

      uVar20 = puVar14[1];

      uVar2 = puVar14[2];

      uVar21 = puVar14[3];

      puVar14[2] = 0;

      puVar14[3] = 0xf;

      *(undefined1 *)puVar14 = 0;

      puVar14 = (ulonglong *)(param_1 + 0x18);

      local_288 = uVar19;

      uStack_280 = uVar20;

      local_278 = uVar2;

      uStack_270 = uVar21;

      if (puVar14 != &local_288) {

        if (0xf < *(ulonglong *)(param_1 + 0x30)) {

          uVar1 = *puVar14;

          uVar15 = uVar1;

          if ((0xfff < *(ulonglong *)(param_1 + 0x30) + 1) &&

             (uVar15 = *(ulonglong *)(uVar1 - 8), 0x1f < (uVar1 - uVar15) - 8)) goto LAB_1400f95ab;

          FUN_1402c7088(uVar15);

        }

        *puVar14 = uVar19;

        *(ulonglong *)(param_1 + 0x20) = uVar20;

        *(ulonglong *)(param_1 + 0x28) = uVar2;

        *(ulonglong *)(param_1 + 0x30) = uVar21;

        local_288 = local_288 & 0xffffffffffffff00;

        uVar21 = 0xf;

      }

      if (0xf < uVar21) {

        if ((0xfff < uVar21 + 1) && (0x1f < (local_288 - *(longlong *)(local_288 - 8)) - 8)) {

LAB_1400f95ab:

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      if (0xf < uStack_2b0) {

        if ((0xfff < uStack_2b0 + 1) &&

           (0x1f < ((longlong)_local_2c8 - *(longlong *)((longlong)_local_2c8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    FUN_1400cdae0(param_1);

  }

  return;

}




