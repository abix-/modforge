// Address: 0x14010dff0
// Ghidra name: FUN_14010dff0
// ============ 0x14010dff0 FUN_14010dff0 (size=5627) ============


/* WARNING: Removing unreachable block (ram,0x00014010e5ad) */

/* WARNING: Removing unreachable block (ram,0x00014010e5c5) */

/* WARNING: Removing unreachable block (ram,0x00014010e5de) */

/* WARNING: Removing unreachable block (ram,0x00014010e5e5) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14010dff0(longlong param_1)



{

  int *piVar1;

  int iVar2;

  longlong lVar3;

  uint uVar4;

  float fVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  uint uVar9;

  ulonglong uVar10;

  longlong *plVar11;

  int iVar12;

  void *pvVar13;

  ulonglong uVar14;

  longlong *plVar15;

  uint uVar16;

  ulonglong uVar17;

  longlong *plVar18;

  uint7 uVar20;

  longlong *plVar19;

  longlong lVar21;

  float fVar22;

  int *piVar23;

  undefined *puVar24;

  longlong lVar25;

  int iVar26;

  undefined8 uVar27;

  undefined4 uVar28;

  float fVar29;

  float fVar30;

  float fVar31;

  float fVar32;

  float fVar33;

  float local_res8;

  float local_resc;

  float local_res10;

  float local_res14;

  float local_res18;

  float local_res1c;

  longlong local_res20;

  ulonglong in_stack_fffffffffffffeb8;

  longlong *local_108;

  longlong *plStack_100;

  longlong *local_f8;

  undefined8 local_f0;

  ulonglong uStack_e8;

  undefined8 local_e0;

  ulonglong uStack_d8;

  

  FUN_140070f90(DAT_1403dc2f4);

  fVar32 = *(float *)(*(longlong *)(param_1 + 0x300) + 0x2c);

  fVar8 = *(float *)(*(longlong *)(param_1 + 0x300) + 0x28);

  *(float *)(param_1 + 0x10c) = fVar8;

  *(float *)(param_1 + 0x110) = fVar32;

  fVar5 = DAT_14039ca44;

  fVar31 = DAT_14039ca44 / *(float *)(param_1 + 0x114);

  iVar6 = DAT_14030b684 / 2;

  *(float *)(param_1 + 0x10c) = fVar8 - (float)(DAT_14030b680 / 2) * fVar31;

  *(float *)(param_1 + 0x110) = fVar32 - (float)iVar6 * fVar31;

  uVar28 = FUN_1400c5f70();

  *(undefined4 *)(param_1 + 0x10c) = uVar28;

  uVar28 = FUN_1400c5f70();

  *(undefined4 *)(param_1 + 0x110) = uVar28;

  FUN_140040fc0();

  fVar32 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar32 * *(float *)(param_1 + 0x110),fVar32 * *(float *)(param_1 + 0x10c)))

  ;

  fVar22 = DAT_140303fb4;

  fVar31 = DAT_14030374c;

  fVar32 = *(float *)(param_1 + 0x114);

  fVar33 = (float)DAT_1403eda04;

  fVar8 = *(float *)(param_1 + 0x110);

  fVar29 = ((float)(DAT_14030b680 + DAT_1403eda00) / fVar32 + *(float *)(param_1 + 0x10c)) *

           DAT_140303fb4 + DAT_14030374c;

  fVar30 = ((float)(DAT_14030b684 + DAT_1403eda04) / fVar32 + fVar8) * DAT_140303fb4 + DAT_14030374c

  ;

  fVar7 = (float)FUN_1400c5c30(0,(int)((*(float *)(param_1 + 0x10c) - (float)DAT_1403eda00 / fVar32)

                                       * DAT_140303fb4 - DAT_14030374c));

  local_res18 = fVar7;

  iVar6 = FUN_1400c5c20(*(int *)(param_1 + 0x278) + -1,(int)fVar29);

  local_res20 = CONCAT44(local_res20._4_4_,iVar6);

  fVar32 = (float)FUN_1400c5c30(0,(int)((fVar8 - fVar33 / fVar32) * fVar22 - fVar31));

  local_res10 = fVar32;

  fVar8 = (float)FUN_1400c5c20(*(int *)(param_1 + 0x27c) + -1,(int)fVar30);

  local_res8 = fVar8;

  FUN_140072860(0);

  if ((int)fVar8 < (int)fVar32) {

    FUN_140072860(1);

  }

  else {

    iVar26 = (int)fVar32 << 5;

    fVar22 = local_res18;

    do {

      fVar7 = fVar22;

      for (; (int)fVar7 <= iVar6; fVar7 = (float)((int)fVar7 + 1)) {

        puVar24 = &DAT_1403132d8;

        if (((((int)fVar7 < 0) || (*(int *)(param_1 + 0x278) <= (int)fVar7)) || (iVar26 < 0)) ||

           (*(int *)(param_1 + 0x27c) <= (int)fVar32)) {

          piVar23 = &DAT_1403dc390;

        }

        else {

          piVar23 = (int *)(*(longlong *)(param_1 + 0x270) +

                           (longlong)(*(int *)(param_1 + 0x278) * (int)fVar32 + (int)fVar7) * 0x28);

        }

        piVar1 = piVar23 + 2;

        if (*piVar1 != 0) {

          iVar12 = 0;

          iVar2 = piVar23[1];

          if (0 < iVar2) {

            uVar16 = *(uint *)(&DAT_1403132d8 + (longlong)*piVar23 * 0x1c);

            puVar24 = (undefined *)(ulonglong)uVar16;

            if (0 < (int)uVar16) {

              piVar23 = (int *)((longlong)(iVar2 * 3) % (longlong)(int)uVar16 & 0xffffffff);

              iVar12 = (iVar2 * 3) / (int)uVar16 + 1;

            }

          }

          in_stack_fffffffffffffeb8 =

               CONCAT44((int)(in_stack_fffffffffffffeb8 >> 0x20),(float)(iVar26 + 0x20));

          FUN_1400735d0(iVar12 + *piVar1,piVar23,iVar2,puVar24,in_stack_fffffffffffffeb8);

        }

        fVar22 = local_res18;

        fVar8 = local_res8;

      }

      fVar32 = (float)((int)fVar32 + 1);

      iVar26 = iVar26 + 0x20;

    } while ((int)fVar32 <= (int)fVar8);

    FUN_140072860(1);

    uVar10 = (ulonglong)_tls_index;

    pvVar13 = ThreadLocalStoragePointer;

    fVar32 = local_res8;

    fVar8 = local_res10;

    do {

      if ((int)fVar22 <= iVar6) {

        lVar21 = *(longlong *)((longlong)pvVar13 + uVar10 * 8);

        fVar7 = fVar22;

        do {

          if ((((int)fVar7 < 0) || (*(int *)(param_1 + 0x278) <= (int)fVar7)) ||

             (((int)fVar8 < 0 || (*(int *)(param_1 + 0x27c) <= (int)fVar8)))) {

            piVar23 = &DAT_1403dc390;

          }

          else {

            piVar23 = (int *)(*(longlong *)(param_1 + 0x270) +

                             (longlong)(*(int *)(param_1 + 0x278) * (int)fVar8 + (int)fVar7) * 0x28)

            ;

          }

          iVar6 = *piVar23;

          if ((*(int *)(lVar21 + 4) < DAT_1403fb42c) &&

             (FUN_1402c7138(&DAT_1403fb42c), DAT_1403fb42c == -1)) {

            uStack_e8 = 0;

            local_e0 = 5;

            uStack_d8 = 0xf;

            local_f0._0_5_ = CONCAT14(s_Fence_1403136c4[4],s_Fence_1403136c4._0_4_);

            local_f0 = (ulonglong)(uint5)local_f0;

            DAT_1403fb428 = FUN_14006fe60(&local_f0);

            _Init_thread_footer(&DAT_1403fb42c);

          }

          if ((char)piVar23[3] != '\0') {

            iVar26 = 4;

            if (iVar6 != 6) {

              iVar26 = 0;

            }

            FUN_140071d20(iVar26 + DAT_1403fb428);

          }

          if (*(char *)((longlong)piVar23 + 0xd) != '\0') {

            iVar26 = 4;

            if (iVar6 != 6) {

              iVar26 = 0;

            }

            FUN_140071d20(iVar26 + DAT_1403fb428 + 1);

          }

          fVar7 = (float)((int)fVar7 + 1);

          pvVar13 = ThreadLocalStoragePointer;

          fVar22 = local_res18;

          fVar32 = local_res8;

          iVar6 = (int)local_res20;

        } while ((int)fVar7 <= (int)local_res20);

      }

      fVar8 = (float)((int)fVar8 + 1);

      fVar7 = local_res18;

    } while ((int)fVar8 <= (int)fVar32);

  }

  local_res10 = (float)((int)local_res10 << 5);

  local_res8 = (float)((int)local_res8 << 5);

  plStack_100 = (longlong *)0x0;

  local_f8 = (longlong *)0x0;

  uVar10 = *(longlong *)(param_1 + 0xc0) - *(longlong *)(param_1 + 0xb8) >> 3;

  if (uVar10 != 0) {

    if (0x1fffffffffffffff < uVar10) {

LAB_14010f3fe:

                    /* WARNING: Subroutine does not return */

      FUN_14002f0d0();

    }

    plStack_100 = (longlong *)FUN_1400285e0(uVar10 * 8);

    FUN_1402f8e20(plStack_100);

    local_f8 = plStack_100 + uVar10;

  }

  local_res18 = 0.0;

  lVar21 = *(longlong *)(param_1 + 0xb8);

  plVar19 = plStack_100;

  plVar11 = plStack_100;

  local_108 = plStack_100;

  if (*(longlong *)(param_1 + 0xc0) - lVar21 >> 3 != 0) {

    local_res20 = 0;

    plVar15 = local_f8;

    do {

      lVar21 = *(longlong *)(lVar21 + local_res20);

      if (((((float)((int)fVar7 << 5) <= *(float *)(lVar21 + 0x28)) &&

           (*(float *)(lVar21 + 0x28) <= (float)(iVar6 << 5))) &&

          ((float)(int)local_res10 <= *(float *)(lVar21 + 0x2c))) &&

         (*(float *)(lVar21 + 0x2c) <= (float)(int)local_res8)) {

        if (plVar19 == plVar15) {

          lVar25 = (longlong)plVar19 - (longlong)plVar11 >> 3;

          if (lVar25 == 0x1fffffffffffffff) goto LAB_14010f3fe;

          uVar10 = lVar25 + 1;

          uVar17 = (longlong)plVar15 - (longlong)plVar11 >> 3;

          if (0x1fffffffffffffff - (uVar17 >> 1) < uVar17) {

            uVar14 = 0x1fffffffffffffff;

          }

          else {

            uVar17 = uVar17 + (uVar17 >> 1);

            uVar14 = uVar10;

            if (uVar10 <= uVar17) {

              uVar14 = uVar17;

            }

            if (0x1fffffffffffffff < uVar14) {

                    /* WARNING: Subroutine does not return */

              FUN_140024090();

            }

          }

          plVar11 = (longlong *)FUN_1400285e0(uVar14 * 8);

          plVar11[lVar25] = lVar21;

          plVar15 = plVar11;

          plVar18 = local_108;

          if (plVar19 != plStack_100) {

            FUN_1402f8e20(plVar11,local_108,(longlong)plVar19 - (longlong)local_108);

            plVar15 = plVar11 + lVar25 + 1;

            plVar18 = plVar19;

          }

          FUN_1402f8e20(plVar15,plVar18);

          if (local_108 != (longlong *)0x0) {

            if ((0xfff < ((longlong)local_f8 - (longlong)local_108 & 0xfffffffffffffff8U)) &&

               (0x1f < (ulonglong)((longlong)local_108 + (-8 - local_108[-1])))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          plVar19 = plVar11 + uVar10;

          plVar15 = plVar11 + uVar14;

          local_108 = plVar11;

          plStack_100 = plVar19;

          local_f8 = plVar15;

        }

        else {

          *plVar19 = lVar21;

          plVar19 = plStack_100 + 1;

          plVar15 = local_f8;

          plVar11 = local_108;

          plStack_100 = plVar19;

        }

      }

      local_res18 = (float)((int)local_res18 + 1);

      local_res20 = local_res20 + 8;

      lVar21 = *(longlong *)(param_1 + 0xb8);

    } while ((ulonglong)(longlong)(int)local_res18 <

             (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar21 >> 3));

  }

  lVar25 = 0;

  FUN_140111c50(plVar11,plVar19,(longlong)plVar19 - (longlong)plVar11 >> 3);

  lVar21 = *(longlong *)(*(longlong *)(param_1 + 0x438) + 0xd8);

  if ((lVar21 == 0) || (*(char *)(lVar21 + 0x270) != '\0')) {

LAB_14010e8c0:

    uVar27 = 1;

  }

  else {

    piVar23 = (int *)&DAT_1403d9530;

    if (0xf < DAT_1403d9548) {

      piVar23 = DAT_1403d9530;

    }

    if (DAT_1403d9540 == 6) {

      iVar6 = *piVar23 + -0x73697243;

      if (iVar6 == 0) {

        iVar6 = *(ushort *)(piVar23 + 1) - 0x7270;

      }

      if (iVar6 == 0) goto LAB_14010e8c0;

    }

    uVar27 = 0;

  }

  iVar6 = 0;

  lVar21 = lVar25;

  if ((longlong)plStack_100 - (longlong)local_108 >> 3 != 0) {

    do {

      plVar19 = *(longlong **)((longlong)local_108 + lVar21);

      if ((int)plVar19[1] == 2) {

        uVar20 = (uint7)((ulonglong)local_108 >> 8);

        if ((*(int *)((longlong)plVar19 + 0xc) == 0x1b) ||

           (*(int *)((longlong)plVar19 + 0xc) == 0x10)) {

          FUN_1400a8f20(plVar19,CONCAT71(uVar20,1),uVar27);

        }

        else {

          FUN_1400a8f20(plVar19,(ulonglong)uVar20 << 8,uVar27);

        }

      }

      else {

        (**(code **)(*plVar19 + 0x38))();

      }

      iVar6 = iVar6 + 1;

      lVar21 = lVar21 + 8;

    } while ((ulonglong)(longlong)iVar6 <

             (ulonglong)((longlong)plStack_100 - (longlong)local_108 >> 3));

  }

  fVar32 = DAT_14039ca34;

  lVar21 = *(longlong *)(*(longlong *)(param_1 + 0x438) + 0xd8);

  if ((lVar21 != 0) && (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x438) + 0x80), lVar3 != 0)) {

    fVar8 = *(float *)(lVar3 + 0x10);

    fVar22 = *(float *)(lVar21 + 0x10);

    if ((fVar8 == fVar22) && (*(float *)(lVar3 + 0xc) < *(float *)(lVar21 + 0xc))) {

      fVar7 = *(float *)(lVar3 + 0xc) + DAT_140303fe8;

      local_res14 = fVar8 - DAT_14030fc18;

      fVar29 = *(float *)(lVar21 + 0xc) - DAT_140303fec;

      local_resc = fVar22 - DAT_14030fc18;

      local_res8 = fVar29;

      local_res10 = fVar7;

      FUN_140071990(&local_res10,&local_res8);

      local_res14 = fVar8 - DAT_140304bf0;

      local_resc = fVar22 - DAT_140304bf0;

      local_res8 = fVar29;

      local_res10 = fVar7;

      FUN_140071990(&local_res10,&local_res8);

    }

  }

  if (0 < *(int *)(param_1 + 0x3c4)) {

    fVar8 = (float)*(int *)(param_1 + 0x3c4) / DAT_140303754;

    lVar21 = *(longlong *)(param_1 + 0x300);

    in_stack_fffffffffffffeb8 = in_stack_fffffffffffffeb8 & 0xffffffff00000000;

    FUN_140071ed0(*(undefined4 *)(param_1 + 0x3c0),

                  (fVar8 * *(float *)(param_1 + 0x3b8) + *(float *)(lVar21 + 0x28)) -

                  (float)(*(int *)(lVar21 + 0x38) * 6),

                  (fVar8 * *(float *)(param_1 + 0x3bc) + *(float *)(lVar21 + 0x2c)) - fVar31,

                  fVar8 * DAT_140303364 + DAT_14039ca2c,in_stack_fffffffffffffeb8);

    *(int *)(param_1 + 0x3c4) = *(int *)(param_1 + 0x3c4) + -1;

  }

  fVar8 = DAT_140303750;

  uVar28 = (undefined4)(in_stack_fffffffffffffeb8 >> 0x20);

  local_res8 = -NAN;

  if ((((*(int *)(param_1 + 0xd0) != -1) &&

       (lVar21 = *(longlong *)

                  (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0xd0) * 8),

       *(int *)(lVar21 + 8) == 2)) &&

      (local_res8 = *(float *)(lVar21 + 0xc), local_res8 == 1.96182e-44)) &&

     (*(int *)(param_1 + 0x440) == 0xd)) {

    local_res8 = -NAN;

  }

  if ((*(int *)(param_1 + 0x268) < 3) &&

     (iVar6 = 0, (longlong)plStack_100 - (longlong)local_108 >> 3 != 0)) {

    do {

      uVar28 = (undefined4)(in_stack_fffffffffffffeb8 >> 0x20);

      lVar21 = *(longlong *)((longlong)local_108 + lVar25);

      if (*(int *)(lVar21 + 8) == 2) {

        fVar22 = *(float *)(lVar21 + 0xc);

        lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x438) + (longlong)(int)fVar22 * 8);

        if (((lVar3 != 0) && ((local_res8 == fVar22 || (*(float *)(param_1 + 0x440) == fVar22)))) &&

           (plVar19 = (longlong *)(lVar3 + 0x18), *(longlong *)(lVar3 + 0x28) != 0)) {

          if (0xf < *(ulonglong *)(lVar3 + 0x30)) {

            plVar19 = (longlong *)*plVar19;

          }

          iVar26 = FUN_140086450(DAT_1403ede60,plVar19);

          fVar7 = (*(float *)(lVar21 + 0x2c) - *(float *)(lVar21 + 0x34) * fVar32) - fVar31;

          if (*(float *)(param_1 + 0x440) == fVar22) {

            uVar16 = *(int *)(param_1 + 600) / 0x1e & 0x80000001;

            if ((int)uVar16 < 0) {

              uVar16 = (uVar16 - 1 | 0xfffffffe) + 1;

            }

            fVar7 = fVar7 - (float)(int)uVar16;

          }

          FUN_140071000((*(float *)(lVar21 + 0x28) - (float)iVar26 * fVar32) - fVar5,fVar7 - fVar8,

                        (float)iVar26 + fVar31);

          in_stack_fffffffffffffeb8 = CONCAT44(uVar28,fVar5);

          FUN_140086570(DAT_1403ede60);

        }

      }

      uVar28 = (undefined4)(in_stack_fffffffffffffeb8 >> 0x20);

      iVar6 = iVar6 + 1;

      lVar25 = lVar25 + 8;

    } while ((ulonglong)(longlong)iVar6 <

             (ulonglong)((longlong)plStack_100 - (longlong)local_108 >> 3));

  }

  if (*(int *)(param_1 + 0x34c) == 1) {

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4

                 ) < DAT_1403fb434) && (FUN_1402c7138(&DAT_1403fb434), DAT_1403fb434 == -1)) {

      uStack_e8 = 0;

      local_e0 = 5;

      uStack_d8 = 0xf;

      local_f0._0_5_ = CONCAT14(s_Lasso_14030ac4c[4],s_Lasso_14030ac4c._0_4_);

      local_f0 = (ulonglong)(uint5)local_f0;

      DAT_1403fb430 = FUN_14006fe60(&local_f0);

      _Init_thread_footer(&DAT_1403fb434);

    }

    local_res8 = DAT_1403dc2bc;

    if (*(char *)(param_1 + 0x328) != '\0') {

      local_res8 = DAT_1403dc334;

    }

    uVar16 = -(uint)(*(char *)(param_1 + 0x328) != '\0') & 2;

    if ((*(int *)(param_1 + 0x35c) == 0) || (*(int *)(param_1 + 0x35c) == 1)) {

      uVar4 = *(int *)(param_1 + 600) / 0xf;

      uVar9 = uVar4 & 0x80000001;

      if ((int)uVar9 < 0) {

        uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;

      }

      uVar16 = uVar16 + uVar9;

      if (*(int *)(param_1 + 600) == uVar4 * 0xf) {

        uStack_e8 = 0;

        local_e0 = _DAT_140304080;

        uStack_d8 = _UNK_140304088;

        local_f0._0_5_ = CONCAT14(s_Lasso_14030ac4c[4],s_Lasso_14030ac4c._0_4_);

        local_f0 = (ulonglong)(uint5)local_f0;

        FUN_140040fe0();

        FUN_140040ca0(&local_f0,0x14);

        if (0xf < uStack_d8) {

          if ((0xfff < uStack_d8 + 1) && (0x1f < (local_f0 - *(longlong *)(local_f0 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

    }

    if (((*(int *)(param_1 + 0x35c) != 3) || (iVar6 = *(int *)(param_1 + 0x360), iVar6 < 0x1e)) ||

       ((2 < iVar6 + (iVar6 / 6 + (iVar6 >> 0x1f) +

                     (int)(((longlong)iVar6 / 6 + ((longlong)iVar6 >> 0x3f) & 0xffffffffU) >> 0x1f))

                     * -6 && (iVar6 < 0x3d)))) {

      FUN_140071d20(DAT_1403fb430 + uVar16);

      local_res18 = *(float *)(param_1 + 0x354) + 0.0;

      local_res1c = *(float *)(param_1 + 0x358) + DAT_14030339c;

      local_res14 = *(float *)(*(longlong *)(param_1 + 0x300) + 0x2c) - DAT_140303394;

      local_res10 = *(float *)(*(longlong *)(param_1 + 0x300) + 0x28);

      FUN_140071990(&local_res18,&local_res10);

    }

  }

  else {

    if (*(int *)(param_1 + 0x35c) == 5) {

      uVar10 = (ulonglong)_tls_index;

      if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar10 * 8) + 4) <

           DAT_1403fb43c) && (FUN_1402c7138(&DAT_1403fb43c), DAT_1403fb43c == -1)) {

        uStack_e8 = 0;

        local_e0 = 7;

        uStack_d8 = 0xf;

        local_f0._0_6_ = CONCAT24(s_GunProj_1403139d8._4_2_,s_GunProj_1403139d8._0_4_);

        local_f0._0_7_ = CONCAT16(s_GunProj_1403139d8[6],(undefined6)local_f0);

        local_f0 = (ulonglong)(uint7)local_f0;

        DAT_1403fb438 = FUN_14006fe60(&local_f0);

        _Init_thread_footer(&DAT_1403fb43c);

      }

      FUN_140071ed0(DAT_1403fb438);

      goto LAB_14010eec9;

    }

    if ((*(int *)(param_1 + 0x35c) == 6) && (*(int *)(param_1 + 0x34c) == 2)) {

      uVar10 = (ulonglong)_tls_index;

      if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar10 * 8) + 4) <

           DAT_1403fb444) && (FUN_1402c7138(&DAT_1403fb444), DAT_1403fb444 == -1)) {

        local_e0 = 10;

        uStack_d8 = 0xf;

        local_f0._0_1_ = s_AnimShovel_1403139e0[0];

        local_f0._1_1_ = s_AnimShovel_1403139e0[1];

        local_f0._2_1_ = s_AnimShovel_1403139e0[2];

        local_f0._3_1_ = s_AnimShovel_1403139e0[3];

        local_f0._4_1_ = s_AnimShovel_1403139e0[4];

        local_f0._5_1_ = s_AnimShovel_1403139e0[5];

        local_f0._6_1_ = s_AnimShovel_1403139e0[6];

        local_f0._7_1_ = s_AnimShovel_1403139e0[7];

        uStack_e8 = (ulonglong)(ushort)s_AnimShovel_1403139e0._8_2_;

        _DAT_1403fb440 = FUN_14006fe60(&local_f0);

        _Init_thread_footer(&DAT_1403fb444);

      }

      FUN_140071d20((uint)(*(char *)(param_1 + 0x330) != '\0') + _DAT_1403fb440,

                    *(int *)(param_1 + 0x360) / 0xc,

                    *(float *)(param_1 + 0x358) - (float)(5 < *(int *)(param_1 + 0x360) % 0xc));

      goto LAB_14010eec9;

    }

  }

  uVar10 = (ulonglong)_tls_index;

LAB_14010eec9:

  if (((*(int *)(param_1 + 0x34c) == 4) && (*(int *)(param_1 + 0x35c) == 0)) &&

     (0 < *(int *)(param_1 + 0x378))) {

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar10 * 8) + 4) <

         DAT_1403fb44c) && (FUN_1402c7138(&DAT_1403fb44c), DAT_1403fb44c == -1)) {

      uStack_e8 = 0;

      local_e0 = 5;

      uStack_d8 = 0xf;

      local_f0._0_5_ = CONCAT14(s_Fence_1403136c4[4],s_Fence_1403136c4._0_4_);

      local_f0 = (ulonglong)(uint5)local_f0;

      _DAT_1403fb448 = FUN_14006fe60(&local_f0);

      _Init_thread_footer(&DAT_1403fb44c);

    }

    FUN_140072750(0x60);

    FUN_140071d20((uint)(*(int *)(param_1 + 0x378) == 1) + _DAT_1403fb448);

    FUN_1400727d0();

  }

  FUN_1400c9290(*(undefined8 *)(param_1 + 0x248));

  if ((0 < *(int *)(param_1 + 0x1f8)) && (lVar21 = *(longlong *)(param_1 + 0x3a8), lVar21 != 0)) {

    fVar8 = *(float *)(param_1 + 0x3b0);

    if (*(int *)(lVar21 + 0x38) == -1) {

      fVar8 = (float)(*(uint *)(param_1 + 0x1d0) ^ DAT_14039cac0) * fVar32 - fVar8;

    }

    *(int *)(param_1 + 0x200) = *(int *)(lVar21 + 0x38);

    FUN_140072fe0(CONCAT44(*(float *)(param_1 + 0x3b4) + *(float *)(lVar21 + 0x2c),

                           fVar8 + *(float *)(lVar21 + 0x28)));

    FUN_1400d2090(param_1);

    FUN_1400730f0();

  }

  FUN_1400730f0();

  if (*(char *)(*(longlong *)(param_1 + 0x300) + 0xad) != '\0') {

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar10 * 8) + 4) <

         DAT_1403fb454) && (FUN_1402c7138(&DAT_1403fb454), DAT_1403fb454 == -1)) {

      uStack_e8 = 0;

      local_e0 = 7;

      uStack_d8 = 0xf;

      local_f0._0_6_ = CONCAT24(s_Balloon_140306808._4_2_,s_Balloon_140306808._0_4_);

      local_f0._0_7_ = CONCAT16(s_Balloon_140306808[6],(undefined6)local_f0);

      local_f0 = (ulonglong)(uint7)local_f0;

      DAT_1403fb450 = FUN_14006fe60(&local_f0);

      _Init_thread_footer(&DAT_1403fb454);

    }

    fVar32 = *(float *)(param_1 + 0x114);

    fVar8 = fVar32;

    if (fVar32 <= fVar5) {

      fVar8 = fVar5;

    }

    lVar21 = *(longlong *)(param_1 + 0x300);

    fVar31 = fVar32;

    if (fVar5 <= fVar32) {

      fVar31 = fVar5;

    }

    FUN_140071ed0(DAT_1403fb450,(*(float *)(lVar21 + 0x28) - *(float *)(param_1 + 0x10c)) * fVar32,

                  ((*(float *)(lVar21 + 0x2c) - *(float *)(param_1 + 0x110)) * fVar32 -

                  DAT_140303390 / fVar31) - fVar8 * DAT_14039ca58,

                  (float)*(int *)(lVar21 + 0x38) * fVar8,CONCAT44(uVar28,fVar8));

    FUN_1401104f0(param_1);

  }

  FUN_14010f7e0(param_1);

  FUN_14010fc10(param_1,1);

  if (DAT_1403d95c4 == '\0') {

    lVar21 = *(longlong *)(param_1 + 0x60);

    *(float *)(lVar21 + 0x30c) = (float)(DAT_1403d9e68 + -0xd);

    *(float *)(lVar21 + 0x310) = (float)(DAT_1403ed998 + 4);

    FUN_140071000();

    FUN_140071000();

    FUN_140071d20(*(undefined4 *)(lVar21 + 0x304),*(float *)(lVar21 + 0x30c) + DAT_14030338c,

                  *(float *)(lVar21 + 0x310) + DAT_14030338c);

  }

  if (local_108 != (longlong *)0x0) {

    if ((0xfff < ((longlong)local_f8 - (longlong)local_108 & 0xfffffffffffffff8U)) &&

       (0x1f < (ulonglong)((longlong)local_108 + (-8 - local_108[-1])))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return;

}




