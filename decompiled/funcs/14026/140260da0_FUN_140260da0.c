// Address: 0x140260da0
// Ghidra name: FUN_140260da0
// ============ 0x140260da0 FUN_140260da0 (size=4101) ============


ulonglong FUN_140260da0(byte *param_1,int *param_2,int *param_3,int *param_4,byte *param_5,

                       int *param_6,int *param_7,int *param_8,uint param_9,undefined4 param_10,

                       undefined4 param_11,int param_12,int param_13)



{

  bool bVar1;

  bool bVar2;

  char cVar3;

  char cVar4;

  uint uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  int iVar8;

  longlong lVar9;

  uint uVar10;

  longlong lVar11;

  longlong lVar12;

  undefined1 *puVar13;

  char cVar14;

  int iVar15;

  longlong lVar16;

  int *piVar17;

  longlong lVar18;

  int iVar19;

  int iVar20;

  int iVar21;

  int iVar22;

  int iVar23;

  int iVar24;

  byte local_res8;

  char local_1b8;

  int local_1ac;

  int local_1a8;

  undefined8 local_1a0;

  longlong local_198;

  uint local_190;

  int iStack_18c;

  int local_188;

  longlong local_180;

  longlong local_178;

  uint local_170;

  uint local_16c;

  int local_168;

  int local_164;

  int local_160;

  int local_15c;

  int local_158;

  int local_154;

  int local_148;

  int iStack_144;

  int iStack_140;

  int iStack_13c;

  int local_138;

  ulonglong local_130;

  longlong local_128;

  longlong local_120;

  longlong local_118;

  longlong local_110;

  undefined8 local_108;

  int iStack_100;

  int iStack_fc;

  int local_f8;

  int local_f4;

  ulonglong local_f0;

  longlong local_e8;

  longlong local_e0;

  byte *local_d8;

  longlong lStack_d0;

  undefined8 local_c8;

  ulonglong uStack_c0;

  undefined8 local_b8;

  undefined8 uStack_b0;

  longlong local_a8;

  undefined8 uStack_a0;

  ulonglong local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  uint uStack_60;

  undefined4 uStack_5c;

  ulonglong local_58;

  

  bVar2 = false;

  local_res8 = 1;

  local_f8 = 0;

  cVar3 = FUN_1401489c0();

  if (cVar3 == '\0') {

    uVar6 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

    return uVar6;

  }

  cVar3 = FUN_1401489c0(param_5);

  if (cVar3 == '\0') {

    uVar6 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e9c);

    return uVar6;

  }

  local_130 = FUN_140263080(param_6,param_7,*param_8,param_8[1]);

  if (local_130 == 0) {

    return 1;

  }

  if ((*param_5 & 2) != 0) {

    uVar6 = FUN_140146f20(param_5);

    if ((char)uVar6 == '\0') {

      return uVar6;

    }

    local_f8 = 1;

  }

  bVar1 = false;

  if ((*param_1 & 2) != 0) {

    cVar3 = FUN_140146f20(param_1);

    if (cVar3 == '\0') {

      local_res8 = 0;

      goto LAB_140261d58;

    }

    bVar1 = true;

  }

  bVar2 = bVar1;

  cVar14 = (char)param_10;

  cVar3 = (char)param_9;

  if ((((cVar3 == cVar14) && (param_9._1_1_ == param_10._1_1_)) && (param_9._2_1_ == param_10._2_1_)

      ) && (((param_9._3_1_ == param_10._3_1_ && (cVar14 == (char)param_11)) &&

            ((param_10._1_1_ == param_11._1_1_ &&

             ((param_10._2_1_ == param_11._2_1_ && (param_10._3_1_ == param_11._3_1_)))))))) {

    local_1b8 = '\x01';

    FUN_140262fc0(param_6,param_7,param_8,&local_148);

    FUN_1401465d0(param_1,&local_f4);

    if ((((cVar3 != -1) || (param_9._1_1_ != -1)) || (param_9._2_1_ != -1)) || (param_9._3_1_ != -1)

       ) goto LAB_140260f9c;

    bVar1 = false;

  }

  else {

    local_1b8 = '\0';

    FUN_140262fc0(param_6,param_7,param_8,&local_148);

    FUN_1401465d0(param_1,&local_f4);

LAB_140260f9c:

    bVar1 = true;

  }

  FUN_1401466d0(param_5,&local_108);

  FUN_140185790(&local_148,&local_108,&local_148);

  local_1a0._0_4_ = local_148;

  local_1a0._4_4_ = iStack_144;

  local_170 = (uint)*(byte *)(*(longlong *)(param_5 + 0x38) + 5);

  local_e8 = *(longlong *)(param_1 + 0x18);

  local_198 = (longlong)(*(int *)(param_5 + 0x10) * iStack_144) +

              (longlong)(int)(local_148 * local_170) + *(longlong *)(param_5 + 0x18);

  local_16c = *(uint *)(param_1 + 0x10);

  local_190 = (uint)(0 < (longlong)local_130);

  local_f0 = -local_130;

  if ((longlong)-local_130 < 0) {

    local_f0 = local_130;

  }

  local_188 = (param_7[1] - param_8[1]) * 2;

  iVar8 = param_8[1] - param_6[1];

  iVar15 = param_6[1] - param_7[1];

  local_1a8 = iVar8 * 2;

  local_1ac = iVar15 * 2;

  iVar21 = *param_6 - *param_8;

  iVar19 = *param_8 - *param_7;

  iVar23 = *param_7 - *param_6;

  iVar20 = iVar19 * 2;

  iVar22 = iVar21 * 2;

  iVar24 = iVar23 * 2;

  local_15c = *param_2 - *param_4;

  local_160 = *param_3 - *param_4;

  local_164 = param_2[1] - param_4[1];

  local_168 = param_3[1] - param_4[1];

  FUN_140263160(&local_1a0);

  uVar7 = (ulonglong)((int)local_1a0 + 1);

  uVar6 = (ulonglong)(local_1a0._4_4_ + 1);

  local_180 = FUN_140263080(param_7,param_8,uVar7,uVar6);

  local_178 = FUN_140263080(param_8,param_6,uVar7 & 0xffffffff,uVar6 & 0xffffffff);

  piVar17 = param_7;

  local_1a0 = FUN_140263080(param_6,param_7,uVar7 & 0xffffffff,uVar6 & 0xffffffff);

  if ((longlong)local_130 < 1) {

    iVar20 = iVar19 * -2;

    local_188 = -local_188;

    iVar22 = iVar21 * -2;

    iVar24 = iVar23 * -2;

    local_1a8 = iVar8 * -2;

    local_1ac = iVar15 * -2;

    local_180 = -local_180;

    local_178 = -local_178;

    local_1a0 = -local_1a0;

  }

  cVar4 = FUN_140263120(piVar17,param_8,local_190);

  local_154 = (cVar4 != '\0') - 1;

  cVar4 = FUN_140263120(param_8,param_6);

  local_158 = (cVar4 != '\0') - 1;

  cVar4 = FUN_140263120(param_6,param_7);

  local_108 = 0xffffffff;

  local_138 = (cVar4 != '\0') - 1;

  local_e0 = (longlong)*param_4 * local_f0;

  if (local_e0 + 0x80000000U < 0x100000000) {

    local_130 = (longlong)param_4[1] * local_f0;

    uVar10 = (uint)local_e0;

    local_190 = uVar10;

    if (local_130 + 0x80000000 < 0x100000000) {

      iStack_18c = (int)local_130;

      if (((local_f4 != 0) || (*(int *)(param_1 + 4) != *(int *)(param_5 + 4))) ||

         ((bVar1 || (local_1b8 == '\0')))) {

        uStack_90 = *(undefined8 *)(param_1 + 0x38);

        uStack_80 = *(undefined8 *)(param_5 + 0x38);

        local_88 = 0;

        uVar5 = *(uint *)(param_1 + 0x108) & 0xfffffffc;

        local_58 = (ulonglong)param_9;

        local_68 = 0;

        local_c8 = 0;

        local_b8 = 0;

        uStack_b0 = 0;

        uStack_a0 = 0;

        local_78 = 0;

        uStack_70 = 0;

        if (((((cVar3 != -1) || (cVar14 != -1)) || ((char)param_11 != -1)) ||

            ((((param_9._1_1_ != -1 || (param_10._1_1_ != -1)) || (param_11._1_1_ != -1)) ||

             ((param_9._2_1_ != -1 || (param_10._2_1_ != -1)))))) || (param_11._2_1_ != -1)) {

          uVar5 = uVar5 | 1;

        }

        if (((param_9._3_1_ != -1) || (param_10._3_1_ != -1)) || (param_11._3_1_ != -1)) {

          uVar5 = uVar5 | 2;

        }

        _uStack_60 = CONCAT44(*(undefined4 *)(param_1 + 0x10c),uVar5);

        lStack_d0 = local_e8;

        uStack_c0 = (ulonglong)local_16c;

        local_a8 = local_198;

        local_98 = (ulonglong)*(uint *)(param_5 + 0x10);

        local_d8 = param_1;

        if (local_f0 + 0x80000000 < 0x100000000) {

          if (local_180 + 0x80000000U < 0x100000000) {

            if (local_178 + 0x80000000U < 0x100000000) {

              if (local_1a0 + 0x80000000U < 0x100000000) {

                local_108 = CONCAT44(iStack_144,local_148);

                iStack_100 = iStack_140;

                iStack_fc = iStack_13c;

                FUN_14025fef0(&local_d8,CONCAT44(iStack_18c,uVar10),&local_108,local_f0 & 0xffffffff

                              ,local_154,local_158,local_138,local_188,iVar20,local_1a8,iVar22,

                              local_1ac,iVar24,local_15c,local_160,local_164,local_168,

                              (int)local_180,(int)local_178,(int)local_1a0,param_9,param_10,param_11

                              ,local_1b8,param_12,param_13);

              }

              else {

                local_res8 = FUN_14012e850("integer overflow (%s = %I64d)","w2_row");

              }

            }

            else {

              local_res8 = FUN_14012e850("integer overflow (%s = %I64d)","w1_row",local_178);

            }

          }

          else {

            local_res8 = FUN_14012e850("integer overflow (%s = %I64d)","w0_row",local_180);

          }

        }

        else {

          local_res8 = FUN_14012e850("integer overflow (%s = %I64d)",&DAT_14036f658,local_f0);

        }

      }

      else if (local_170 == 4) {

        local_190 = 0;

        if (0 < iStack_13c) {

          local_120 = (longlong)iVar20;

          local_118 = (longlong)iVar22;

          local_110 = (longlong)iVar24;

          local_108 = (longlong)*(int *)(param_5 + 0x10);

          do {

            iVar20 = 0;

            if (0 < iStack_140) {

              local_128 = (longlong)local_154;

              iVar22 = 0;

              lVar12 = local_1a0;

              lVar16 = local_178;

              lVar18 = local_180;

              do {

                if (((-1 < local_128 + lVar18) && (-1 < local_158 + lVar16)) &&

                   (-1 < local_138 + lVar12)) {

                  uVar6 = (local_160 * lVar16 + local_15c * lVar18 + (longlong)(int)uVar10) /

                          (longlong)local_f0;

                  uVar7 = (local_168 * lVar16 + local_164 * lVar18 + (longlong)iStack_18c) /

                          (longlong)local_f0;

                  iVar8 = (int)uVar7;

                  iVar24 = (int)uVar6;

                  if (param_12 == 1) {

                    if (iVar24 < 0) {

                      iVar24 = 0;

                    }

                    else if (*(int *)(param_1 + 8) <= iVar24) {

                      iVar24 = *(int *)(param_1 + 8) + -1;

                    }

                  }

                  else if (param_12 == 2) {

                    iVar24 = (int)((longlong)

                                   ((ulonglong)(uint)(iVar24 >> 0x1f) << 0x20 | uVar6 & 0xffffffff)

                                  % (longlong)*(int *)(param_1 + 8));

                    if (iVar24 < 0) {

                      iVar24 = iVar24 + -1 + *(int *)(param_1 + 8);

                    }

                  }

                  if (param_13 == 1) {

                    if (iVar8 < 0) {

                      iVar8 = 0;

                    }

                    else if (*(int *)(param_1 + 0xc) <= iVar8) {

                      iVar8 = *(int *)(param_1 + 0xc) + -1;

                    }

                  }

                  else if (param_13 == 2) {

                    iVar8 = (int)((longlong)

                                  ((ulonglong)(uint)(iVar8 >> 0x1f) << 0x20 | uVar7 & 0xffffffff) %

                                 (longlong)*(int *)(param_1 + 0xc));

                    if (iVar8 < 0) {

                      iVar8 = iVar8 + -1 + *(int *)(param_1 + 0xc);

                    }

                  }

                  *(undefined4 *)(local_198 + iVar22) =

                       *(undefined4 *)((int)(iVar8 * local_16c) + local_e8 + (longlong)iVar24 * 4);

                }

                iVar20 = iVar20 + 1;

                iVar22 = iVar22 + 4;

                lVar18 = lVar18 + local_188;

                lVar16 = lVar16 + local_1a8;

                lVar12 = lVar12 + local_1ac;

              } while (iVar20 < iStack_140);

            }

            local_190 = local_190 + 1;

            local_178 = local_178 + local_118;

            local_180 = local_180 + local_120;

            local_198 = local_198 + local_108;

            local_1a0 = local_1a0 + local_110;

          } while ((int)local_190 < iStack_13c);

        }

      }

      else {

        cVar3 = (char)local_170;

        if (cVar3 == '\x03') {

          local_190 = 0;

          if (0 < iStack_13c) {

            local_110 = (longlong)iVar20;

            local_118 = (longlong)iVar22;

            local_120 = (longlong)iVar24;

            local_128 = (longlong)*(int *)(param_5 + 0x10);

            do {

              iVar20 = 0;

              if (0 < iStack_140) {

                local_108 = (longlong)local_154;

                iVar22 = 0;

                lVar12 = local_1a0;

                lVar16 = local_178;

                lVar18 = local_180;

                do {

                  if (((-1 < local_108 + lVar18) && (-1 < local_158 + lVar16)) &&

                     (-1 < local_138 + lVar12)) {

                    puVar13 = (undefined1 *)(iVar22 + local_198);

                    uVar6 = (local_160 * lVar16 + local_15c * lVar18 + (longlong)(int)uVar10) /

                            (longlong)local_f0;

                    iVar24 = (int)uVar6;

                    uVar7 = (local_168 * lVar16 + local_164 * lVar18 + (longlong)iStack_18c) /

                            (longlong)local_f0;

                    iVar8 = (int)uVar7;

                    if (param_12 == 1) {

                      if (iVar24 < 0) {

                        iVar24 = 0;

                      }

                      else if (*(int *)(param_1 + 8) <= iVar24) {

                        iVar24 = *(int *)(param_1 + 8) + -1;

                      }

                    }

                    else if (param_12 == 2) {

                      iVar24 = (int)((longlong)

                                     ((ulonglong)(uint)(iVar24 >> 0x1f) << 0x20 | uVar6 & 0xffffffff

                                     ) % (longlong)*(int *)(param_1 + 8));

                      if (iVar24 < 0) {

                        iVar24 = iVar24 + -1 + *(int *)(param_1 + 8);

                      }

                    }

                    if (param_13 == 1) {

                      if (iVar8 < 0) {

                        iVar8 = 0;

                      }

                      else if (*(int *)(param_1 + 0xc) <= iVar8) {

                        iVar8 = *(int *)(param_1 + 0xc) + -1;

                      }

                    }

                    else if (param_13 == 2) {

                      iVar8 = (int)((longlong)

                                    ((ulonglong)(uint)(iVar8 >> 0x1f) << 0x20 | uVar7 & 0xffffffff)

                                   % (longlong)*(int *)(param_1 + 0xc));

                      if (iVar8 < 0) {

                        iVar8 = iVar8 + -1 + *(int *)(param_1 + 0xc);

                      }

                    }

                    lVar11 = (int)(iVar8 * local_16c) + local_e8;

                    lVar9 = (longlong)(iVar24 * 3);

                    *puVar13 = *(undefined1 *)(lVar11 + lVar9);

                    puVar13[1] = *(undefined1 *)(lVar11 + 1 + lVar9);

                    puVar13[2] = *(undefined1 *)(lVar11 + 2 + lVar9);

                  }

                  iVar20 = iVar20 + 1;

                  iVar22 = iVar22 + local_170;

                  lVar18 = lVar18 + local_188;

                  lVar16 = lVar16 + local_1a8;

                  lVar12 = lVar12 + local_1ac;

                } while (iVar20 < iStack_140);

              }

              local_190 = local_190 + 1;

              local_178 = local_178 + local_118;

              local_180 = local_180 + local_110;

              local_198 = local_198 + local_128;

              local_1a0 = local_1a0 + local_120;

            } while ((int)local_190 < iStack_13c);

          }

        }

        else if (cVar3 == '\x02') {

          local_190 = 0;

          if (0 < iStack_13c) {

            local_110 = (longlong)iVar20;

            local_118 = (longlong)iVar22;

            local_120 = (longlong)iVar24;

            local_128 = (longlong)*(int *)(param_5 + 0x10);

            do {

              iVar20 = 0;

              if (0 < iStack_140) {

                local_108 = (longlong)local_154;

                iVar22 = 0;

                lVar12 = local_1a0;

                lVar16 = local_178;

                lVar18 = local_180;

                do {

                  if (((-1 < local_108 + lVar18) && (-1 < local_158 + lVar16)) &&

                     (-1 < local_138 + lVar12)) {

                    uVar6 = (local_160 * lVar16 + local_15c * lVar18 + (longlong)(int)uVar10) /

                            (longlong)local_f0;

                    uVar7 = (local_168 * lVar16 + local_164 * lVar18 + (longlong)iStack_18c) /

                            (longlong)local_f0;

                    iVar8 = (int)uVar7;

                    iVar24 = (int)uVar6;

                    if (param_12 == 1) {

                      if (iVar24 < 0) {

                        iVar24 = 0;

                      }

                      else if (*(int *)(param_1 + 8) <= iVar24) {

                        iVar24 = *(int *)(param_1 + 8) + -1;

                      }

                    }

                    else if (param_12 == 2) {

                      iVar24 = (int)((longlong)

                                     ((ulonglong)(uint)(iVar24 >> 0x1f) << 0x20 | uVar6 & 0xffffffff

                                     ) % (longlong)*(int *)(param_1 + 8));

                      if (iVar24 < 0) {

                        iVar24 = iVar24 + -1 + *(int *)(param_1 + 8);

                      }

                    }

                    if (param_13 == 1) {

                      if (iVar8 < 0) {

                        iVar8 = 0;

                      }

                      else if (*(int *)(param_1 + 0xc) <= iVar8) {

                        iVar8 = *(int *)(param_1 + 0xc) + -1;

                      }

                    }

                    else if (param_13 == 2) {

                      iVar8 = (int)((longlong)

                                    ((ulonglong)(uint)(iVar8 >> 0x1f) << 0x20 | uVar7 & 0xffffffff)

                                   % (longlong)*(int *)(param_1 + 0xc));

                      if (iVar8 < 0) {

                        iVar8 = iVar8 + -1 + *(int *)(param_1 + 0xc);

                      }

                    }

                    *(undefined2 *)(local_198 + iVar22) =

                         *(undefined2 *)((int)(iVar8 * local_16c) + local_e8 + (longlong)iVar24 * 2)

                    ;

                  }

                  iVar20 = iVar20 + 1;

                  iVar22 = iVar22 + local_170;

                  lVar18 = lVar18 + local_188;

                  lVar16 = lVar16 + local_1a8;

                  lVar12 = lVar12 + local_1ac;

                } while (iVar20 < iStack_140);

              }

              local_190 = local_190 + 1;

              local_178 = local_178 + local_118;

              local_180 = local_180 + local_110;

              local_198 = local_198 + local_128;

              local_1a0 = local_1a0 + local_120;

            } while ((int)local_190 < iStack_13c);

          }

        }

        else if ((cVar3 == '\x01') && (local_190 = 0, 0 < iStack_13c)) {

          local_110 = (longlong)iVar20;

          local_118 = (longlong)iVar22;

          local_120 = (longlong)iVar24;

          local_128 = (longlong)*(int *)(param_5 + 0x10);

          do {

            iVar20 = 0;

            if (0 < iStack_140) {

              local_108 = (longlong)local_154;

              iVar22 = 0;

              lVar12 = local_1a0;

              lVar16 = local_178;

              lVar18 = local_180;

              do {

                if (((-1 < local_108 + lVar18) && (-1 < local_158 + lVar16)) &&

                   (-1 < local_138 + lVar12)) {

                  uVar6 = (local_160 * lVar16 + local_15c * lVar18 + (longlong)(int)uVar10) /

                          (longlong)local_f0;

                  uVar7 = (local_168 * lVar16 + local_164 * lVar18 + (longlong)iStack_18c) /

                          (longlong)local_f0;

                  iVar8 = (int)uVar7;

                  iVar24 = (int)uVar6;

                  if (param_12 == 1) {

                    if (iVar24 < 0) {

                      iVar24 = 0;

                    }

                    else if (*(int *)(param_1 + 8) <= iVar24) {

                      iVar24 = *(int *)(param_1 + 8) + -1;

                    }

                  }

                  else if (param_12 == 2) {

                    iVar24 = (int)((longlong)

                                   ((ulonglong)(uint)(iVar24 >> 0x1f) << 0x20 | uVar6 & 0xffffffff)

                                  % (longlong)*(int *)(param_1 + 8));

                    if (iVar24 < 0) {

                      iVar24 = iVar24 + -1 + *(int *)(param_1 + 8);

                    }

                  }

                  if (param_13 == 1) {

                    if (iVar8 < 0) {

                      iVar8 = 0;

                    }

                    else if (*(int *)(param_1 + 0xc) <= iVar8) {

                      iVar8 = *(int *)(param_1 + 0xc) + -1;

                    }

                  }

                  else if (param_13 == 2) {

                    iVar8 = (int)((longlong)

                                  ((ulonglong)(uint)(iVar8 >> 0x1f) << 0x20 | uVar7 & 0xffffffff) %

                                 (longlong)*(int *)(param_1 + 0xc));

                    if (iVar8 < 0) {

                      iVar8 = iVar8 + -1 + *(int *)(param_1 + 0xc);

                    }

                  }

                  *(undefined1 *)(iVar22 + local_198) =

                       *(undefined1 *)((longlong)iVar24 + (int)(iVar8 * local_16c) + local_e8);

                }

                iVar20 = iVar20 + 1;

                iVar22 = iVar22 + local_170;

                lVar18 = lVar18 + local_188;

                lVar16 = lVar16 + local_1a8;

                lVar12 = lVar12 + local_1ac;

              } while (iVar20 < iStack_140);

            }

            local_190 = local_190 + 1;

            local_178 = local_178 + local_118;

            local_180 = local_180 + local_110;

            local_198 = local_198 + local_128;

            local_1a0 = local_1a0 + local_120;

          } while ((int)local_190 < iStack_13c);

        }

      }

      goto LAB_140261d58;

    }

  }

  local_res8 = FUN_14012e850("triangle area overflow");

LAB_140261d58:

  if (local_f8 != 0) {

    FUN_1401489e0(param_5);

  }

  if (bVar2) {

    FUN_1401489e0(param_1);

  }

  return (ulonglong)local_res8;

}




