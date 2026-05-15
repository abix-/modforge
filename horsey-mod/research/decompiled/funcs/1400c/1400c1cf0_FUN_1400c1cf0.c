// Address: 0x1400c1cf0
// Ghidra name: FUN_1400c1cf0
// ============ 0x1400c1cf0 FUN_1400c1cf0 (size=5311) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400c1cf0(longlong param_1)



{

  int iVar1;

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  bool bVar4;

  float fVar5;

  uint uVar6;

  int iVar7;

  undefined4 *puVar8;

  undefined *puVar9;

  longlong lVar10;

  undefined1 (*pauVar11) [16];

  undefined1 *puVar12;

  undefined4 uVar13;

  int iVar14;

  int *piVar15;

  undefined8 *puVar16;

  longlong lVar17;

  undefined4 *puVar18;

  int iVar19;

  int iVar20;

  int iVar21;

  int iVar22;

  ulonglong uVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  float fVar27;

  float fVar28;

  int local_res10;

  ulonglong local_res18;

  longlong local_res20;

  ulonglong in_stack_fffffffffffffdc8;

  uint uVar31;

  undefined4 uVar32;

  undefined8 uVar29;

  undefined8 uVar30;

  undefined8 *in_stack_fffffffffffffde0;

  undefined4 uVar33;

  undefined4 uVar34;

  int local_214;

  longlong local_210;

  undefined4 local_208;

  int *local_200;

  undefined1 local_1f8 [16];

  undefined8 local_1e8;

  ulonglong uStack_1e0;

  longlong local_1d8;

  longlong local_1d0;

  longlong local_1c8;

  undefined8 local_1b8;

  undefined *local_1b0;

  undefined *local_1a8;

  undefined *local_1a0;

  undefined *local_198;

  undefined *local_190;

  undefined *local_188;

  undefined *local_180;

  undefined *local_178;

  longlong local_168;

  longlong local_160;

  undefined *local_158;

  undefined8 local_148;

  undefined8 uStack_140;

  undefined8 local_138;

  undefined8 uStack_130;

  undefined8 local_128;

  undefined8 uStack_120;

  undefined8 local_118;

  undefined8 uStack_110;

  undefined8 local_108;

  undefined8 uStack_100;

  undefined4 local_f8;

  

  uVar6 = (uint)(in_stack_fffffffffffffdc8 >> 0x20);

  if (*(int *)(param_1 + 0x280) == 0) {

    FUN_140070f90(DAT_1403d9e74);

  }

  else if (*(int *)(param_1 + 0x280) == 1) {

    FUN_140070f90(DAT_1403da5d8);

  }

  else {

    FUN_140070f90(DAT_1403da5d8);

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4

                 ) < DAT_1403f32f4) && (FUN_1402c7138(&DAT_1403f32f4), DAT_1403f32f4 == -1)) {

      local_1b0 = (undefined *)0x0;

      local_1a8 = (undefined *)0x7;

      local_1a0 = (undefined *)0xf;

      local_1b8 = (undefined *)

                  (ulonglong)

                  CONCAT16(s_filmset_14030db58[6],

                           CONCAT24(s_filmset_14030db58._4_2_,s_filmset_14030db58._0_4_));

      DAT_1403f32f0 = FUN_14006fe60(&local_1b8);

      _Init_thread_footer(&DAT_1403f32f4);

    }

    in_stack_fffffffffffffdc8 = (ulonglong)uVar6 << 0x20;

    FUN_140071ed0(DAT_1403f32f0);

  }

  if (*(char *)(param_1 + 0x234) != '\0') {

    fVar25 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

    FUN_140072fe0(CONCAT44(fVar25 * *(float *)(param_1 + 0x110),fVar25 * *(float *)(param_1 + 0x10c)

                          ));

    FUN_1400d5d90(param_1,1);

    FUN_1400730f0();

  }

  if (*(char *)(param_1 + 0x27c) != '\0') {

    FUN_140072fe0((ulonglong)(uint)(float)-DAT_1403eda04 << 0x20);

    local_210 = CONCAT44(local_210._4_4_,0xffffee00);

    local_208 = 0xffd1b432;

    uVar33 = 0xff646496;

    puVar18 = &DAT_1403f3300;

    iVar19 = 0x78;

    do {

      puVar8 = (undefined4 *)FUN_140072a10(&local_214,iVar19,0x30);

      *puVar18 = *puVar8;

      fVar24 = DAT_14030a5d0;

      fVar5 = DAT_14030374c;

      fVar28 = DAT_1403033b4;

      fVar25 = DAT_140303390;

      iVar19 = iVar19 + -6;

      puVar18 = puVar18 + 1;

    } while ((longlong)puVar18 < 0x1403f3350);

    local_214 = 0;

    if (0 < *(int *)(param_1 + 0x278)) {

      local_168 = (longlong)*(int *)(&DAT_1403da474 + (longlong)*(int *)(param_1 + 600) * 8);

      local_1d8 = local_168 * 0x28;

      local_1c8 = local_168 * 8;

      local_160 = local_168 * 4;

      local_200 = &DAT_1403ee4a8 + local_168 * 8;

      local_210 = local_168 * 0x10 + 0x28;

      uVar34 = uVar33;

      do {

        fVar27 = (float)local_214 * *(float *)(param_1 + 0x26c) + DAT_14030401c;

        if ((*(int *)(param_1 + 0x250) < 1) ||

           (bVar4 = true,

           *(char *)((longlong)*(int *)(param_1 + 0x250) * 0x1018 + local_168 + 0xf28 +

                    DAT_1403f2fc0) == '\0')) {

          bVar4 = false;

        }

        iVar19 = 0;

        local_1d0 = 0;

        local_158 = &DAT_1403ee488 + (local_1c8 - local_160) * 4;

        do {

          uVar31 = (uint)(in_stack_fffffffffffffdc8 >> 0x20);

          fVar26 = (float)iVar19 * fVar28 + fVar24;

          uVar6 = (uint)((float)*local_200 * *(float *)(local_158 + local_210));

          iVar7 = FUN_1400c5f50(*(undefined4 *)

                                 (DAT_1403f2fc0 + 0x28 +

                                 ((longlong)*(int *)(param_1 + 0x250) * 0x406 + local_1d0 +

                                 local_160) * 4),0);

          if ((((*(char *)(param_1 + 0x27d) != '\0') && (*(int *)(param_1 + 0x15c) != -1)) &&

              ((lVar17 = *(longlong *)

                          (*(longlong *)(param_1 + 0x130) + (longlong)*(int *)(param_1 + 0x15c) * 8)

               , *(char *)(lVar17 + 0x2b8 + local_168) == iVar19 ||

               (*(char *)(lVar17 + 0x3a8 + local_168) == iVar19)))) ||

             ((*(int *)(param_1 + 0x260) == local_214 && (*(int *)(param_1 + 0x264) == iVar19)))) {

            FUN_140071000(fVar26 - fVar5,fVar27 - fVar5);

          }

          in_stack_fffffffffffffdc8 = (ulonglong)uVar31 << 0x20;

          FUN_140071000();

          if (0 < iVar7) {

            iVar20 = iVar7;

            if (iVar7 == 0x14) {

              iVar20 = 0x13;

            }

            in_stack_fffffffffffffdc8 = in_stack_fffffffffffffdc8 & 0xffffffff00000000;

            FUN_140071000(fVar26 + fVar5,fVar27 + fVar5 + (float)(iVar20 + -1));

          }

          iVar20 = 0;

          lVar17 = (DAT_1403f2fc8 - DAT_1403f2fc0) / 0x1018;

          uVar13 = uVar33;

          if (lVar17 != 1) {

            piVar15 = (int *)(local_210 + DAT_1403f2fc0);

            do {

              if (0 < *piVar15) {

                uVar13 = DAT_1403da56c;

                if (iVar7 == 0) {

                  uVar13 = 0xff969696;

                }

                break;

              }

              iVar20 = iVar20 + 1;

              piVar15 = piVar15 + 0x406;

            } while ((ulonglong)(longlong)iVar20 < lVar17 - 1U);

          }

          iVar7 = *(int *)(*(longlong *)(param_1 + 0x470) + 0x20 + local_1d8);

          uVar32 = (undefined4)(in_stack_fffffffffffffdc8 >> 0x20);

          if (iVar7 == 0) {

            in_stack_fffffffffffffde0 =

                 (undefined8 *)CONCAT44((int)((ulonglong)in_stack_fffffffffffffde0 >> 0x20),uVar6);

            puVar9 = &DAT_14039bf04;

LAB_1400c2417:

            in_stack_fffffffffffffdc8 = CONCAT44(uVar32,fVar5);

            FUN_14009e700(DAT_1403ede10,fVar26 + fVar25,fVar27 + fVar25,0,in_stack_fffffffffffffdc8,

                          uVar13,puVar9,in_stack_fffffffffffffde0);

          }

          else {

            if (iVar7 != 1) {

              if (iVar7 == 2) {

                local_1b8 = &DAT_14030db60;

                local_1b0 = &DAT_14030db68;

                local_1a8 = &DAT_14030db70;

                local_1a0 = &DAT_14030db74;

                local_198 = &DAT_14030db7c;

                local_190 = &DAT_14030db84;

                local_188 = &DAT_14030db88;

                if (uVar6 < 7) {

                  in_stack_fffffffffffffde0 = (undefined8 *)(&local_1b8)[(int)uVar6];

                }

                else {

LAB_1400c2404:

                  in_stack_fffffffffffffde0 = (undefined8 *)&DAT_14030db8c;

                }

              }

              else if (iVar7 == 3) {

                local_1b8 = &DAT_14030db60;

                local_1b0 = &DAT_14030db90;

                local_1a8 = &DAT_14030db94;

                local_1a0 = &DAT_14030d7e4;

                local_198 = &DAT_14030db98;

                local_190 = &DAT_14030dba0;

                local_188 = &DAT_14030dba8;

                local_180 = &DAT_14030d7f4;

                local_178 = &DAT_14030a29c;

                if (((int)uVar6 < 0) || (8 < uVar6)) goto LAB_1400c2404;

                in_stack_fffffffffffffde0 = (undefined8 *)(&local_1b8)[(int)uVar6];

              }

              else {

                if (iVar7 != 4) goto LAB_1400c244f;

                local_1b8 = &DAT_14030db60;

                local_1b0 = &DAT_14030dbb0;

                local_1a8 = &DAT_14030dbb8;

                local_1a0 = &DAT_14030dbc0;

                local_198 = &DAT_14030dbc8;

                local_190 = &DAT_14030dbcc;

                local_188 = &DAT_14030dbd4;

                if (4 < uVar6) goto LAB_1400c2404;

                in_stack_fffffffffffffde0 = (undefined8 *)(&local_1b8)[(int)uVar6];

              }

              local_1b8 = &DAT_14030db60;

              puVar9 = &DAT_14039bf30;

              goto LAB_1400c2417;

            }

            puVar9 = &DAT_14030db64;

            if (uVar6 == 0) {

              puVar9 = &DAT_14030db60;

            }

            in_stack_fffffffffffffdc8 = CONCAT44(uVar32,fVar5);

            FUN_14009e2c0(DAT_1403ede10,fVar26 + fVar25,fVar27 + fVar25,0,in_stack_fffffffffffffdc8,

                          uVar13,puVar9);

          }

LAB_1400c244f:

          if (bVar4) {

            uVar34 = 0x96000000;

            in_stack_fffffffffffffdc8 =

                 CONCAT44((int)(in_stack_fffffffffffffdc8 >> 0x20),0x96000000);

            FUN_140071000();

          }

          iVar7 = local_214;

          uVar32 = (undefined4)((ulonglong)in_stack_fffffffffffffde0 >> 0x20);

          uVar13 = (undefined4)(in_stack_fffffffffffffdc8 >> 0x20);

          iVar19 = iVar19 + 1;

          local_1d0 = local_1d0 + 1;

          local_210 = local_210 + 4;

        } while (iVar19 < 4);

        local_res20._0_4_ = 0xffd7d7d7;

        if ((*(int *)(param_1 + 0x260) == local_214) && (*(int *)(param_1 + 0x264) == 4)) {

          FUN_140071000(local_1d0,fVar27 - DAT_14039ca44);

        }

        FUN_140071000();

        in_stack_fffffffffffffde0 = (undefined8 *)CONCAT44(uVar32,local_200[-1]);

        uVar29 = CONCAT44(uVar13,DAT_14039ca44);

        FUN_14009e700(DAT_1403ede10,DAT_14030dbf0,fVar27 + DAT_14030338c,0,uVar29,0xff969696,

                      &DAT_14039bf04,in_stack_fffffffffffffde0,uVar34);

        uVar13 = (undefined4)((ulonglong)uVar29 >> 0x20);

        if (9 < *local_200) {

          FUN_140071000();

        }

        if (99 < *local_200) {

          FUN_140071000();

        }

        if (999 < *local_200) {

          FUN_140071000();

        }

        if (bVar4) {

          local_res20._0_4_ = 0xff323232;

        }

        puVar16 = (undefined8 *)(local_1d8 + *(longlong *)(param_1 + 0x470));

        if (0xf < (ulonglong)puVar16[3]) {

          puVar16 = (undefined8 *)*puVar16;

        }

        in_stack_fffffffffffffdc8 = CONCAT44(uVar13,fVar5);

        FUN_14009e2c0(DAT_1403ede10,puVar16,fVar27 + DAT_140303398,1,in_stack_fffffffffffffdc8,

                      (undefined4)local_res20,puVar16);

        if (local_200[1] != 0) {

          in_stack_fffffffffffffdc8 =

               CONCAT44((int)(in_stack_fffffffffffffdc8 >> 0x20),DAT_1403da594);

          FUN_140071000();

        }

        local_168 = local_168 + 1;

        local_160 = local_160 + 4;

        local_1c8 = local_1c8 + 8;

        local_1d8 = local_1d8 + 0x28;

        local_200 = local_200 + 8;

        local_214 = iVar7 + 1;

      } while (local_214 < *(int *)(param_1 + 0x278));

    }

    uVar13 = local_208;

    uVar23 = _UNK_14039caa8;

    uVar29 = _DAT_14039caa0;

    fVar5 = DAT_14039ca0c;

    uVar34 = DAT_14030dc04;

    uVar33 = DAT_14030dc00;

    fVar28 = DAT_140304c00;

    if (((-1 < *(int *)(param_1 + 0x260)) && (-1 < *(int *)(param_1 + 0x264))) &&

       (*(int *)(param_1 + 0x264) < 4)) {

      local_148 = _DAT_14030cdc0;

      uStack_140 = _UNK_14030cdc8;

      local_138 = _DAT_14030cdb0;

      uStack_130 = _UNK_14030cdb8;

      local_128 = _DAT_14030cda0;

      uStack_120 = _UNK_14030cda8;

      local_118 = _DAT_14030cd90;

      uStack_110 = _UNK_14030cd98;

      local_108 = _DAT_14030cd80;

      uStack_100 = _UNK_14030cd88;

      local_f8 = 1;

      local_res18._0_4_ = 0x40;

      local_res10 = 0;

      lVar17 = DAT_1403f2fc8 - DAT_1403f2fc0 >> 0x3f;

      if ((DAT_1403f2fc8 - DAT_1403f2fc0) / 0x1018 + lVar17 != lVar17) {

        local_158 = (undefined *)

                    (longlong)

                    (*(int *)(&DAT_1403da474 + (longlong)*(int *)(param_1 + 600) * 8) +

                    *(int *)(param_1 + 0x260));

        lVar10 = (longlong)local_158 * 0x10;

        local_res20 = 0;

        local_1d0 = 0x30;

        lVar17 = DAT_1403f2fc0;

        local_1c8 = lVar10;

        do {

          uVar32 = (undefined4)(in_stack_fffffffffffffdc8 >> 0x20);

          iVar19 = *(int *)(param_1 + 0x264);

          iVar7 = *(int *)((longlong)&local_148 + (longlong)*(int *)(lVar17 + 0x28 + lVar10) * 4);

          iVar20 = iVar7;

          if (0 < iVar19) {

            iVar20 = 0;

          }

          iVar14 = iVar7;

          if (-1 < iVar19) {

            iVar14 = 0;

          }

          iVar1 = *(int *)((longlong)&local_148 + (longlong)*(int *)(lVar17 + 0x2c + lVar10) * 4);

          iVar21 = iVar1 + iVar20;

          if (1 < iVar19) {

            iVar21 = iVar20;

          }

          iVar20 = iVar1 + iVar14;

          if (0 < iVar19) {

            iVar20 = iVar14;

          }

          iVar14 = *(int *)((longlong)&local_148 +

                           (longlong)*(int *)(local_1d0 + lVar10 + lVar17) * 4);

          iVar22 = iVar14 + iVar21;

          if (2 < iVar19) {

            iVar22 = iVar21;

          }

          iVar21 = iVar14 + iVar20;

          if (1 < iVar19) {

            iVar21 = iVar20;

          }

          iVar20 = *(int *)((longlong)&local_148 + (longlong)*(int *)(lVar17 + 0x34 + lVar10) * 4);

          iVar7 = iVar1 + iVar20 + iVar14 + iVar7;

          iVar14 = iVar20 + iVar22;

          if (3 < iVar19) {

            iVar14 = iVar22;

          }

          iVar20 = iVar20 + iVar21;

          if (2 < iVar19) {

            iVar20 = iVar21;

          }

          if (0 < iVar7) {

            fVar27 = (float)iVar7;

            fVar24 = (float)*(int *)((longlong)&local_148 +

                                    (longlong)

                                    *(int *)(lVar17 + 0x28 +

                                            (local_res20 + iVar19 + (longlong)local_158 * 4) * 4) *

                                    4) / fVar27;

            fVar24 = ((float)iVar14 * fVar24) / fVar27 + ((float)iVar20 * fVar24) / fVar27;

            local_1e8 = uVar29;

            uStack_1e0 = uVar23;

            local_1f8._1_15_ = SUB1615(ZEXT416(0),1);

            auVar3[0xf] = 0;

            auVar3._0_15_ = local_1f8._1_15_;

            local_1f8 = auVar3 << 8;

            if ((fVar24 <= 0.0) || (fVar5 <= fVar24)) {

              pauVar11 = (undefined1 (*) [16])FUN_14008d760(&local_1b8,&DAT_14039bf04);

              if (&local_1f8 != pauVar11) {

                if (0xf < uStack_1e0) {

                  if ((0xfff < uStack_1e0 + 1) &&

                     (0x1f < (local_1f8._0_8_ - *(longlong *)(local_1f8._0_8_ + -8)) - 8U))

                  goto LAB_1400c319b;

                  FUN_1402c7088();

                }

                local_1f8 = *pauVar11;

                local_1e8 = *(undefined8 *)pauVar11[1];

                uStack_1e0 = *(ulonglong *)(pauVar11[1] + 8);

                *(undefined8 *)pauVar11[1] = 0;

                *(undefined8 *)(pauVar11[1] + 8) = 0xf;

                (*pauVar11)[0] = 0;

              }

              if ((undefined *)0xf < local_1a0) {

                if (((undefined *)0xfff < local_1a0 + 1) &&

                   ((undefined *)0x1f < local_1b8 + (-8 - *(longlong *)(local_1b8 + -8)))) {

LAB_1400c319b:

                    /* WARNING: Subroutine does not return */

                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                }

                goto LAB_1400c2adb;

              }

            }

            else {

              pauVar11 = (undefined1 (*) [16])FUN_14008d760(&local_1b8,".%02d");

              if (&local_1f8 != pauVar11) {

                if (0xf < uStack_1e0) {

                  if ((0xfff < uStack_1e0 + 1) &&

                     (0x1f < (local_1f8._0_8_ - *(longlong *)(local_1f8._0_8_ + -8)) - 8U))

                  goto LAB_1400c3114;

                  FUN_1402c7088();

                }

                local_1f8 = *pauVar11;

                local_1e8 = *(undefined8 *)pauVar11[1];

                uStack_1e0 = *(ulonglong *)(pauVar11[1] + 8);

                *(undefined8 *)pauVar11[1] = 0;

                *(undefined8 *)(pauVar11[1] + 8) = 0xf;

                (*pauVar11)[0] = 0;

              }

              if ((undefined *)0xf < local_1a0) {

                if (((undefined *)0xfff < local_1a0 + 1) &&

                   ((undefined *)0x1f < local_1b8 + (-8 - *(longlong *)(local_1b8 + -8)))) {

LAB_1400c3114:

                    /* WARNING: Subroutine does not return */

                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                }

LAB_1400c2adb:

                FUN_1402c7088();

              }

            }

            puVar12 = local_1f8;

            if (0xf < uStack_1e0) {

              puVar12 = (undefined1 *)local_1f8._0_8_;

            }

            uVar30 = CONCAT44(uVar32,DAT_14039ca44);

            FUN_14009e700(DAT_1403ede10,uVar33,(float)(int)local_res18,1,uVar30,uVar13,puVar12);

            in_stack_fffffffffffffde0 = (undefined8 *)((DAT_1403f2fc0 - local_1c8) + 8 + lVar10);

            if (0xf < (ulonglong)in_stack_fffffffffffffde0[3]) {

              in_stack_fffffffffffffde0 = (undefined8 *)*in_stack_fffffffffffffde0;

            }

            in_stack_fffffffffffffdc8 = CONCAT44((int)((ulonglong)uVar30 >> 0x20),DAT_14039ca44);

            FUN_14009e700(DAT_1403ede10,uVar34,(float)(int)local_res18,0,in_stack_fffffffffffffdc8,

                          uVar13,&DAT_14039bf30,in_stack_fffffffffffffde0);

            uVar32 = (undefined4)(in_stack_fffffffffffffdc8 >> 0x20);

            local_res18._0_4_ = (int)local_res18 + 0x10;

            if ((0.0 < fVar24) && (local_res10 == *(int *)(param_1 + 0x250))) {

              FUN_140027810(local_1f8,&DAT_14030dbe0,2);

              puVar12 = local_1f8;

              if (0xf < uStack_1e0) {

                puVar12 = (undefined1 *)local_1f8._0_8_;

              }

              in_stack_fffffffffffffdc8 = CONCAT44(uVar32,DAT_14039ca44);

              FUN_14009e700(DAT_1403ede10,DAT_14030dbf0,

                            (float)*(int *)(param_1 + 0x260) * *(float *)(param_1 + 0x26c) +

                            DAT_14030401c + fVar28,0,in_stack_fffffffffffffdc8,uVar13,puVar12,

                            in_stack_fffffffffffffde0);

            }

            lVar17 = DAT_1403f2fc0;

            if (0xf < uStack_1e0) {

              if ((0xfff < uStack_1e0 + 1) &&

                 (0x1f < (local_1f8._0_8_ - *(longlong *)(local_1f8._0_8_ + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              FUN_1402c7088();

              lVar17 = DAT_1403f2fc0;

            }

          }

          local_res10 = local_res10 + 1;

          local_res20 = local_res20 + 0x406;

          lVar10 = lVar10 + 0x1018;

        } while ((ulonglong)(longlong)local_res10 < (ulonglong)((DAT_1403f2fc8 - lVar17) / 0x1018));

      }

    }

    fVar24 = DAT_140303fd0;

    fVar5 = DAT_14030374c;

    fVar28 = DAT_1403033ac;

    uVar33 = (undefined4)(in_stack_fffffffffffffdc8 >> 0x20);

    puVar18 = &DAT_1403da470;

    iVar19 = 0;

    if (0 < *(int *)(param_1 + 0x25c)) {

      do {

        uVar34 = (undefined4)((ulonglong)in_stack_fffffffffffffde0 >> 0x20);

        uVar33 = (undefined4)(in_stack_fffffffffffffdc8 >> 0x20);

        FUN_140071000();

        in_stack_fffffffffffffde0 = (undefined8 *)CONCAT44(uVar34,*puVar18);

        in_stack_fffffffffffffdc8 = CONCAT44(uVar33,fVar5);

        FUN_14009e700(DAT_1403ede10,(float)iVar19 * fVar28 + fVar24 + fVar25,

                      *(float *)(param_1 + 0x270) + fVar25,0,in_stack_fffffffffffffdc8,DAT_1403d9e78

                      ,&DAT_14030c160,in_stack_fffffffffffffde0);

        uVar33 = (undefined4)(in_stack_fffffffffffffdc8 >> 0x20);

        iVar19 = iVar19 + 1;

        puVar18 = puVar18 + 2;

      } while (iVar19 < *(int *)(param_1 + 0x25c));

    }

    if (*(char *)(param_1 + 0x269) == '\0') {

      FUN_140071000();

      puVar16 = (undefined8 *)(DAT_1403f2fc0 + 8 + (longlong)*(int *)(param_1 + 0x250) * 0x1018);

      if (0xf < (ulonglong)puVar16[3]) {

        puVar16 = (undefined8 *)*puVar16;

      }

      FUN_14009e2c0(DAT_1403ede10,puVar16,*(float *)(param_1 + 0x274) + fVar25,0,

                    CONCAT44(uVar33,fVar5),0xff323232,puVar16);

    }

    else {

      FUN_140071000();

      local_res10 = 0;

      local_res18 = 0;

      do {

        iVar19 = 0;

        fVar28 = (float)local_res10 * DAT_14030cd34;

        uVar23 = local_res18;

        do {

          if ((ulonglong)((DAT_1403f2fc8 - DAT_1403f2fc0) / 0x1018) <= uVar23) break;

          FUN_140071000();

          FUN_14009e2c0(DAT_1403ede10,fVar28 + fVar24 + fVar25);

          iVar19 = iVar19 + 1;

          uVar23 = uVar23 + 1;

        } while (iVar19 < 7);

        local_res10 = local_res10 + 1;

        local_res18 = local_res18 + 7;

        uVar23 = (DAT_1403f2fc8 - DAT_1403f2fc0) / 0x1018 - 1;

        auVar2._8_8_ = 0;

        auVar2._0_8_ = uVar23;

        lVar17 = SUB168(ZEXT816(0x2492492492492493) * auVar2,8);

      } while ((ulonglong)(longlong)local_res10 <= (uVar23 - lVar17 >> 1) + lVar17 >> 2);

    }

    FUN_1400730f0();

  }

  fVar25 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar25 * *(float *)(param_1 + 0x110),fVar25 * *(float *)(param_1 + 0x10c)))

  ;

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  return;

}




