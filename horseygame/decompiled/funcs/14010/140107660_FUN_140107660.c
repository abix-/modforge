// Address: 0x140107660
// Ghidra name: FUN_140107660
// ============ 0x140107660 FUN_140107660 (size=12134) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140107660(longlong param_1)



{

  float *pfVar1;

  undefined8 *puVar2;

  bool bVar3;

  bool bVar4;

  bool bVar5;

  char cVar6;

  char cVar7;

  undefined1 uVar8;

  uint uVar9;

  uint uVar10;

  undefined4 uVar11;

  int iVar12;

  undefined4 uVar13;

  ulonglong uVar14;

  int *piVar15;

  longlong lVar16;

  longlong *plVar17;

  longlong *plVar18;

  undefined1 *puVar19;

  char *pcVar20;

  int iVar21;

  int iVar22;

  ulonglong uVar23;

  ulonglong uVar24;

  uint uVar25;

  int iVar26;

  ulonglong uVar27;

  longlong lVar28;

  uint *puVar29;

  bool bVar30;

  float fVar31;

  float fVar32;

  float fVar33;

  float fVar34;

  float fVar35;

  float fVar36;

  float fVar37;

  float fVar38;

  float fVar39;

  undefined8 uVar40;

  undefined8 local_res8;

  undefined8 local_res10;

  int local_res18;

  undefined4 uStackX_1c;

  ulonglong in_stack_fffffffffffffe68;

  undefined8 in_stack_fffffffffffffe78;

  undefined1 local_168 [6];

  char cStack_162;

  undefined1 uStack_161;

  char acStack_160 [2];

  char cStack_15e;

  undefined1 uStack_15d;

  char acStack_15c [2];

  char cStack_15a;

  undefined1 uStack_159;

  undefined8 local_158;

  ulonglong uStack_150;

  char *local_148;

  undefined8 uStack_140;

  undefined8 local_138;

  ulonglong uStack_130;

  undefined8 local_128;

  undefined8 uStack_120;

  undefined8 local_118;

  undefined8 uStack_110;

  undefined8 local_108;

  undefined8 uStack_100;

  undefined8 local_f8;

  undefined8 uStack_f0;

  undefined4 local_e8;

  undefined4 local_e4;

  undefined4 local_e0;

  

  uVar24 = 0;

  if (*(int *)(param_1 + 0x34c) != -1) {

    *(undefined4 *)(*(longlong *)(param_1 + 0x300) + 0x78) = 0;

  }

  fVar38 = DAT_1403ed970 / *(float *)(param_1 + 0x114) + *(float *)(param_1 + 0x10c);

  fVar39 = DAT_1403ed978 / *(float *)(param_1 + 0x114) + *(float *)(param_1 + 0x110);

  if (0 < *(int *)(param_1 + 900)) {

    *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + -1;

  }

  *(int *)(param_1 + 600) = *(int *)(param_1 + 600) + 1;

  *(undefined4 *)(param_1 + 0xd0) = 0xffffffff;

  lVar16 = *(longlong *)(param_1 + 0xb8);

  uVar23 = uVar24;

  uVar27 = uVar24;

  if (*(longlong *)(param_1 + 0xc0) - lVar16 >> 3 != 0) {

    do {

      cVar6 = (**(code **)(**(longlong **)(uVar23 + lVar16) + 0x20))();

      if ((cVar6 != '\0') &&

         (*(int *)(param_1 + 0xd0) = (int)uVar27,

         *(int *)(*(longlong *)(uVar23 + *(longlong *)(param_1 + 0xb8)) + 8) == 0)) break;

      uVar25 = (int)uVar27 + 1;

      lVar16 = *(longlong *)(param_1 + 0xb8);

      uVar23 = uVar23 + 8;

      uVar27 = (ulonglong)uVar25;

    } while ((ulonglong)(longlong)(int)uVar25 <

             (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar16 >> 3));

  }

  fVar37 = DAT_140303fb4;

  uVar11 = (undefined4)((ulonglong)in_stack_fffffffffffffe78 >> 0x20);

  if (*(int *)(param_1 + 0x34c) == 4) {

    iVar22 = *(int *)(param_1 + 0x378);

    if (*(int *)(param_1 + 0x35c) == 8) {

      if (iVar22 == 1) {

        *(int *)(param_1 + 0x374) = (int)(fVar39 * DAT_140303fb4);

        *(int *)(param_1 + 0x360) = *(int *)(param_1 + 0x360) + 1;

      }

      else {

        *(int *)(param_1 + 0x370) = (int)(fVar38 * DAT_140303fb4);

        *(int *)(param_1 + 0x360) = *(int *)(param_1 + 0x360) + 1;

      }

    }

    else {

      fVar31 = fVar38 * DAT_140303fb4;

      *(int *)(param_1 + 0x370) = (int)fVar31;

      *(int *)(param_1 + 0x374) = (int)(fVar39 * fVar37);

      uVar25 = (int)fVar38 & 0x8000001f;

      if ((int)uVar25 < 0) {

        uVar25 = (uVar25 - 1 | 0xffffffe0) + 1;

      }

      uVar10 = (int)fVar39 & 0x8000001f;

      if ((int)uVar10 < 0) {

        uVar10 = (uVar10 - 1 | 0xffffffe0) + 1;

      }

      iVar12 = -(uVar25 - 0x10);

      if (iVar12 < 0) {

        iVar12 = uVar25 - 0x10;

      }

      iVar21 = -(uVar10 - 0x10);

      if (iVar21 < 0) {

        iVar21 = uVar10 - 0x10;

      }

      if (iVar22 == 0) {

        iVar22 = (iVar12 <= iVar21) + 1;

        *(int *)(param_1 + 0x378) = iVar22;

LAB_14010789c:

        if (iVar22 == 1) {

LAB_1401078a1:

          if (0x10 < (int)uVar25) {

            *(int *)(param_1 + 0x370) = (int)fVar31 + 1;

            *(int *)(param_1 + 0x360) = *(int *)(param_1 + 0x360) + 1;

            goto LAB_140107a37;

          }

        }

        else if (iVar22 == 2) goto LAB_1401078fb;

      }

      else {

        if (((iVar22 != 1) || (iVar21 < 0xb)) || (9 < iVar12)) {

          if (iVar22 != 2) goto LAB_14010789c;

          if ((iVar12 < 0xb) || (9 < iVar21)) goto LAB_1401078fb;

          *(undefined4 *)(param_1 + 0x378) = 1;

          goto LAB_1401078a1;

        }

        *(undefined4 *)(param_1 + 0x378) = 2;

LAB_1401078fb:

        if (0x10 < (int)uVar10) {

          *(int *)(param_1 + 0x374) = (int)(fVar39 * fVar37) + 1;

        }

      }

      *(int *)(param_1 + 0x360) = *(int *)(param_1 + 0x360) + 1;

    }

  }

  else {

    *(undefined4 *)(param_1 + 0x378) = 0;

    if (*(int *)(param_1 + 0x34c) == 2) {

      uVar23 = uVar24;

      fVar31 = DAT_140303fcc;

      do {

        uVar11 = (undefined4)(in_stack_fffffffffffffe68 >> 0x20);

        for (uVar27 = *(ulonglong *)

                       (*(longlong *)(param_1 + 0x270) + 0x10 +

                       (longlong)

                       (((&DAT_1403f4f38)[(longlong)(int)uVar23 * 10] + (int)(fVar39 * fVar37)) *

                        *(int *)(param_1 + 0x278) + (&DAT_1403f4f34)[(longlong)(int)uVar23 * 10] +

                       (int)(fVar38 * fVar37)) * 0x28); uVar27 != 0;

            uVar27 = *(ulonglong *)(uVar27 + 0x58)) {

          fVar32 = fVar39 - *(float *)(uVar27 + 0x2c);

          fVar35 = fVar38 - *(float *)(uVar27 + 0x28);

          fVar32 = fVar35 * fVar35 + fVar32 * fVar32;

          if (fVar32 < 0.0) {

            fVar32 = (float)FUN_1402cdfa0();

          }

          else {

            fVar32 = SQRT(fVar32);

          }

          uVar11 = (undefined4)(in_stack_fffffffffffffe68 >> 0x20);

          uVar14 = uVar27;

          if (fVar31 <= fVar32) {

            uVar14 = uVar24;

            fVar32 = fVar31;

          }

          uVar24 = uVar14;

          fVar31 = fVar32;

        }

        in_stack_fffffffffffffe68 = CONCAT44(uVar11,1);

        uVar25 = FUN_140100a40(param_1,uVar23,(int)(fVar38 * fVar37),(int)(fVar39 * fVar37),

                               in_stack_fffffffffffffe68,0);

        uVar11 = (undefined4)((ulonglong)in_stack_fffffffffffffe78 >> 0x20);

        uVar23 = (ulonglong)uVar25;

      } while (uVar25 != 0xffffffff);

      *(bool *)(param_1 + 0x380) = uVar24 == 0;

    }

  }

LAB_140107a37:

  lVar16 = 0;

  fVar31 = DAT_14039ca44;

  uVar40 = _DAT_1403040a0;

  uVar24 = _UNK_1403040a8;

  if (DAT_1403ed960 != 0) {

    iVar22 = *(int *)(param_1 + 0x34c);

    if (iVar22 == 1) {

      if ((*(int *)(param_1 + 0x35c) == 0) || (*(char *)(param_1 + 0x328) != '\0')) {

        if ((*(int *)(param_1 + 0xd0) == -1) ||

           (*(longlong *)(*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0xd0) * 8) !=

            *(longlong *)(param_1 + 0x300))) {

          if (*(int *)(param_1 + 0x388) != -1) {

            FUN_140040ea0();

          }

          _local_168 = ZEXT816(0);

          local_158 = 0;

          uStack_150 = 0;

          pcVar20 = (char *)FUN_1400285e0(0x20);

          uVar40 = s_LassoCastOutLoop_140313848._8_8_;

          _local_168 = (longlong)pcVar20;

          local_158 = _DAT_1403040e0;

          uStack_150 = _UNK_1403040e8;

          *(undefined8 *)pcVar20 = s_LassoCastOutLoop_140313848._0_8_;

          *(undefined8 *)(pcVar20 + 8) = uVar40;

          pcVar20[0x10] = '\0';

          fVar31 = DAT_14039ca44;

          in_stack_fffffffffffffe68 = CONCAT71((int7)(in_stack_fffffffffffffe68 >> 8),1);

          uVar13 = FUN_140040ca0(local_168,100,0,DAT_14039ca44,in_stack_fffffffffffffe68);

          *(undefined4 *)(param_1 + 0x388) = uVar13;

          if (0xf < uStack_150) {

            if ((0xfff < uStack_150 + 1) &&

               (0x1f < (_local_168 - *(longlong *)(_local_168 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          if (*(char *)(param_1 + 0x328) != '\0') {

            local_158 = _DAT_1403040a0;

            uStack_150 = _UNK_1403040a8;

            acStack_160[0] = s_UseSilver_1403128b0[8];

            local_168[0] = s_UseSilver_1403128b0[0];

            local_168[1] = s_UseSilver_1403128b0[1];

            local_168[2] = s_UseSilver_1403128b0[2];

            local_168[3] = s_UseSilver_1403128b0[3];

            local_168[4] = s_UseSilver_1403128b0[4];

            local_168[5] = s_UseSilver_1403128b0[5];

            cStack_162 = s_UseSilver_1403128b0[6];

            uStack_161 = s_UseSilver_1403128b0[7];

            stack0xfffffffffffffea1 = 0;

            in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

            FUN_140040ca0(local_168,100,0,fVar31,in_stack_fffffffffffffe68);

            if (0xf < uStack_150) {

              if ((0xfff < uStack_150 + 1) &&

                 (0x1f < (_local_168 - *(longlong *)(_local_168 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              FUN_1402c7088();

            }

          }

          *(undefined4 *)(param_1 + 0x35c) = 1;

          uVar40 = _DAT_1403040a0;

          uVar24 = _UNK_1403040a8;

        }

        else {

          *(undefined4 *)(param_1 + 0x34c) = 0xffffffff;

          *(undefined4 *)(param_1 + 0x35c) = 7;

          fVar31 = DAT_14039ca44;

          uVar40 = _DAT_1403040a0;

          uVar24 = _UNK_1403040a8;

        }

      }

    }

    else if (iVar22 == 3) {

      if (*(char *)(param_1 + 0x338) == '\0') {

        if (*(int *)(param_1 + 0x334) < 1) {

          *(undefined4 *)(param_1 + 0x34c) = 0xffffffff;

          fVar31 = DAT_14039ca44;

          uVar40 = _DAT_1403040a0;

          uVar24 = _UNK_1403040a8;

          goto LAB_14010803c;

        }

        *(int *)(param_1 + 0x334) = *(int *)(param_1 + 0x334) + -1;

      }

      fVar31 = DAT_14039ca44;

      lVar28 = *(longlong *)(param_1 + 0x300);

      fVar35 = (*(float *)(lVar28 + 0x2c) - *(float *)(lVar28 + 0x34) * DAT_14039ca34) +

               DAT_14039ca44;

      fVar32 = *(float *)(lVar28 + 0x28);

      *(float *)(param_1 + 0x354) = fVar32;

      *(float *)(param_1 + 0x358) = fVar35;

      *(undefined4 *)(param_1 + 0x35c) = 5;

      pfVar1 = (float *)(param_1 + 0x364);

      *pfVar1 = fVar38 - fVar32;

      *(float *)(param_1 + 0x368) = fVar39 - *(float *)(param_1 + 0x358);

      FUN_1400058e0(pfVar1);

      fVar32 = DAT_14030d9bc / *(float *)(param_1 + 0x114);

      *pfVar1 = fVar32 * *pfVar1;

      *(float *)(param_1 + 0x368) = fVar32 * *(float *)(param_1 + 0x368);

      *(undefined4 *)(param_1 + 0x360) = 0;

      local_158 = _DAT_140304cb0;

      uStack_150 = _UNK_140304cb8;

      _local_168 = ZEXT316((uint3)DAT_14031385c);

      in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

      FUN_140040ca0(local_168,100,0,fVar31,in_stack_fffffffffffffe68);

      if (0xf < uStack_150) {

        if ((0xfff < uStack_150 + 1) && (0x1f < (_local_168 - *(longlong *)(_local_168 + -8)) - 8U))

        {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      uVar24 = _UNK_1403040a8;

      uVar40 = _DAT_1403040a0;

      if (*(char *)(param_1 + 0x338) != '\0') {

        local_158 = _DAT_1403040a0;

        uStack_150 = _UNK_1403040a8;

        acStack_160[0] = s_UseSilver_1403128b0[8];

        local_168[0] = s_UseSilver_1403128b0[0];

        local_168[1] = s_UseSilver_1403128b0[1];

        local_168[2] = s_UseSilver_1403128b0[2];

        local_168[3] = s_UseSilver_1403128b0[3];

        local_168[4] = s_UseSilver_1403128b0[4];

        local_168[5] = s_UseSilver_1403128b0[5];

        cStack_162 = s_UseSilver_1403128b0[6];

        uStack_161 = s_UseSilver_1403128b0[7];

        stack0xfffffffffffffea1 = 0;

        in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

        FUN_140040ca0(local_168,100,0,fVar31,in_stack_fffffffffffffe68);

        if (0xf < uStack_150) {

          if ((0xfff < uStack_150 + 1) &&

             (0x1f < (_local_168 - *(longlong *)(_local_168 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

LAB_140108013:

          FUN_1402c7088();

        }

      }

    }

    else if (iVar22 == 2) {

      if (*(char *)(param_1 + 0x380) != '\0') {

        *(float *)(param_1 + 0x354) = fVar38;

        *(float *)(param_1 + 0x358) = fVar39;

        *(undefined8 *)(param_1 + 0x35c) = 6;

        local_158 = _DAT_140304cb0;

        uStack_150 = _UNK_140304cb8;

        _local_168 = ZEXT316((uint3)DAT_140313860);

        uVar13 = FUN_140040fe0();

        fVar31 = DAT_14039ca44;

        uVar23 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

        FUN_140040ca0(local_168,100,uVar13,DAT_14039ca44,uVar23);

        if (0xf < uStack_150) {

          if ((0xfff < uStack_150 + 1) &&

             (0x1f < (_local_168 - *(longlong *)(_local_168 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        uVar24 = _UNK_1403040a8;

        uVar40 = _DAT_1403040a0;

        if (*(char *)(param_1 + 0x330) != '\0') {

          local_158 = _DAT_1403040a0;

          uStack_150 = _UNK_1403040a8;

          acStack_160[0] = s_UseSilver_1403128b0[8];

          local_168[0] = s_UseSilver_1403128b0[0];

          local_168[1] = s_UseSilver_1403128b0[1];

          local_168[2] = s_UseSilver_1403128b0[2];

          local_168[3] = s_UseSilver_1403128b0[3];

          local_168[4] = s_UseSilver_1403128b0[4];

          local_168[5] = s_UseSilver_1403128b0[5];

          cStack_162 = s_UseSilver_1403128b0[6];

          uStack_161 = s_UseSilver_1403128b0[7];

          stack0xfffffffffffffea1 = 0;

          uVar13 = FUN_140040fe0();

          uVar23 = uVar23 & 0xffffffffffffff00;

          FUN_140040ca0(local_168,100,uVar13,fVar31,uVar23);

          FUN_140027900(local_168);

        }

        if (*(int *)(param_1 + 0x388) != -1) {

          FUN_140040ea0();

        }

        local_158 = _DAT_1403033e0;

        uStack_150 = _UNK_1403033e8;

        local_168 = (undefined1  [6])CONCAT24(s_DigLoop_140313868._4_2_,s_DigLoop_140313868._0_4_);

        _local_168 = ZEXT716(CONCAT16(s_DigLoop_140313868[6],local_168));

        uVar13 = FUN_140040fe0();

        in_stack_fffffffffffffe68 = CONCAT71((int7)(uVar23 >> 8),1);

        uVar13 = FUN_140040ca0(local_168,100,uVar13,fVar31,in_stack_fffffffffffffe68);

        *(undefined4 *)(param_1 + 0x388) = uVar13;

        if (0xf < uStack_150) {

          if ((0xfff < uStack_150 + 1) &&

             (0x1f < (_local_168 - *(longlong *)(_local_168 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          goto LAB_140108013;

        }

      }

    }

    else if (iVar22 == 4) {

      *(undefined8 *)(param_1 + 0x35c) = 8;

      fVar31 = DAT_14039ca44;

      uVar40 = _DAT_1403040a0;

      uVar24 = _UNK_1403040a8;

    }

  }

LAB_14010803c:

  uVar25 = _DAT_14039cab0;

  fVar32 = DAT_14039ca58;

  if (DAT_1403ed958 != 0) {

    iVar22 = *(int *)(param_1 + 0x35c);

    if (iVar22 == 2) {

      *(float *)(param_1 + 0x354) = fVar38;

      *(float *)(param_1 + 0x358) = fVar39;

      fVar32 = DAT_14039ca58;

    }

    else if (iVar22 == 1) {

      fVar32 = *(float *)(param_1 + 0x358);

      fVar34 = fVar39 - fVar32;

      fVar35 = *(float *)(param_1 + 0x354);

      fVar36 = fVar38 - fVar35;

      fVar33 = fVar36 * fVar36 + fVar34 * fVar34;

      if (fVar33 < 0.0) {

        fVar33 = (float)FUN_1402cdfa0();

      }

      else {

        fVar33 = SQRT(fVar33);

      }

      if (DAT_14039c9f0 <= fVar33) {

        fVar34 = fVar34 * (fVar31 / fVar33);

        fVar36 = fVar36 * (fVar31 / fVar33);

        if (DAT_14030374c < fVar33) {

          *(float *)(param_1 + 0x354) = fVar36 + fVar36 + fVar35;

          *(float *)(param_1 + 0x358) = fVar34 + fVar34 + fVar32;

          fVar32 = DAT_14039ca58;

          goto LAB_140108078;

        }

      }

      if (*(int *)(param_1 + 0x388) != -1) {

        FUN_140040ea0();

        *(undefined4 *)(param_1 + 0x388) = 0xffffffff;

      }

      *(int *)(param_1 + 0x350) = *(int *)(param_1 + 0xd0);

      iVar22 = (int)(fVar38 * fVar37);

      iVar12 = (int)(fVar39 * fVar37);

      if (*(int *)(param_1 + 0xd0) == -1) {

        if (((iVar22 < 0) || (*(int *)(param_1 + 0x278) <= iVar22)) ||

           ((iVar12 < 0 || (*(int *)(param_1 + 0x27c) <= iVar12)))) {

          piVar15 = &DAT_1403dc390;

        }

        else {

          piVar15 = (int *)(*(longlong *)(param_1 + 0x270) +

                           (longlong)(*(int *)(param_1 + 0x278) * iVar12 + iVar22) * 0x28);

        }

        if (((*piVar15 == 6) ||

            (piVar15 = (int *)FUN_1401010d0(param_1,iVar22,iVar12), *piVar15 == 0x14)) &&

           (iVar12 = FUN_1400c6580(4), iVar12 == 0)) {

          local_res8 = (undefined1 *)FUN_1402c704c(200);

          lVar28 = lVar16;

          if (local_res8 != (undefined1 *)0x0) {

            lVar28 = FUN_140080680(local_res8);

          }

          local_res8 = (undefined1 *)FUN_1402c704c(0x498);

          if (local_res8 != (undefined1 *)0x0) {

            lVar16 = FUN_1400aac60(local_res8);

          }

          local_158 = _DAT_140305680;

          uStack_150 = _UNK_140305688;

          stack0xfffffffffffffe9c = ZEXT412(0);

          local_168._0_5_ = 0x68736966;

          FUN_1400b2ee0(lVar16,local_168,0,0xffffffff);

          if (0xf < uStack_150) {

            FUN_140028310(local_168,_local_168);

          }

          uVar11 = FUN_1400c6580(*(int *)(lVar16 + 0x200) + -2);

          *(undefined4 *)(lVar16 + 0x1fc) = uVar11;

          FUN_140027f50(lVar16 + 0x288,&DAT_140313870,4);

          FUN_140080730(lVar28,lVar16,0,0);

          FUN_140100c90(param_1,lVar28,iVar22);

          iVar22 = (int)(*(longlong *)(param_1 + 0xc0) - *(longlong *)(param_1 + 0xb8) >> 3) + -1;

          *(int *)(param_1 + 0xd0) = iVar22;

          *(float *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + (longlong)iVar22 * 8) + 0x28) =

               fVar38;

          *(float *)(*(longlong *)

                      (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0xd0) * 8) +

                    0x2c) = fVar39;

          *(undefined4 *)(param_1 + 0x350) = *(undefined4 *)(param_1 + 0xd0);

          local_158 = _DAT_1403033d0;

          uStack_150 = _UNK_1403033d8;

          local_168 = (undefined1  [6])CONCAT24(s_Splash_140304ae8._4_2_,s_Splash_140304ae8._0_4_);

          _local_168 = ZEXT616((uint6)local_168);

          uVar11 = FUN_140040fe0();

          in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

          FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

          FUN_140027900(local_168);

          FUN_14010d7e0(param_1,*(undefined8 *)(param_1 + 0x354));

        }

      }

      lVar16 = (longlong)*(int *)(param_1 + 0x350);

      if (*(int *)(param_1 + 0x350) == -1) {

LAB_1401088f8:

        *(undefined4 *)(param_1 + 0x350) = 0xffffffff;

        *(undefined4 *)(param_1 + 0x35c) = 3;

        acStack_160[0] = s_LassoMiss_140313888[8];

        local_168[0] = s_LassoMiss_140313888[0];

        local_168[1] = s_LassoMiss_140313888[1];

        local_168[2] = s_LassoMiss_140313888[2];

        local_168[3] = s_LassoMiss_140313888[3];

        local_168[4] = s_LassoMiss_140313888[4];

        local_168[5] = s_LassoMiss_140313888[5];

        cStack_162 = s_LassoMiss_140313888[6];

        uStack_161 = s_LassoMiss_140313888[7];

        stack0xfffffffffffffea1 = 0;

        local_158 = uVar40;

        uStack_150 = uVar24;

        uVar11 = FUN_140040fe0();

        in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

        FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

        if (0xf < uStack_150) {

          if ((0xfff < uStack_150 + 1) &&

             (0x1f < (_local_168 - *(longlong *)(_local_168 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

      else {

        lVar28 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + lVar16 * 8);

        if (*(int *)(lVar28 + 8) == 0) {

          cVar6 = FUN_140081fa0(lVar28,*(undefined1 *)(param_1 + 0x328));

          if (cVar6 == '\0') {

            *(undefined4 *)(param_1 + 0x350) = 0xffffffff;

            *(undefined4 *)(param_1 + 0x35c) = 3;

            acStack_160[0] = s_LassoMiss_140313888[8];

            local_168[0] = s_LassoMiss_140313888[0];

            local_168[1] = s_LassoMiss_140313888[1];

            local_168[2] = s_LassoMiss_140313888[2];

            local_168[3] = s_LassoMiss_140313888[3];

            local_168[4] = s_LassoMiss_140313888[4];

            local_168[5] = s_LassoMiss_140313888[5];

            cStack_162 = s_LassoMiss_140313888[6];

            uStack_161 = s_LassoMiss_140313888[7];

            stack0xfffffffffffffea1 = 0;

            local_158 = uVar40;

            uStack_150 = uVar24;

            uVar11 = FUN_140040fe0();

            in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

            FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

            if (0xf < uStack_150) {

              FUN_140028310(local_168,_local_168);

            }

            local_res10 = CONCAT44(*(float *)(param_1 + 0x358) - DAT_1403033a4,

                                   *(float *)(param_1 + 0x354) + 0.0);

            fVar32 = DAT_14039ca58;

            if (*(char *)(param_1 + 0x260) != '\0') {

              if ((*(int *)(*(longlong *)

                             ((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

                   < DAT_1403fb424) && (FUN_1402c7138(&DAT_1403fb424), DAT_1403fb424 == -1)) {

                local_158 = 9;

                uStack_150 = 0xf;

                acStack_160[0] = s_PoofHeart_14030e9e0[8];

                local_168[0] = s_PoofHeart_14030e9e0[0];

                local_168[1] = s_PoofHeart_14030e9e0[1];

                local_168[2] = s_PoofHeart_14030e9e0[2];

                local_168[3] = s_PoofHeart_14030e9e0[3];

                local_168[4] = s_PoofHeart_14030e9e0[4];

                local_168[5] = s_PoofHeart_14030e9e0[5];

                cStack_162 = s_PoofHeart_14030e9e0[6];

                uStack_161 = s_PoofHeart_14030e9e0[7];

                stack0xfffffffffffffea1 = 0;

                DAT_1403fb420 = FUN_14006fe60(local_168);

                _Init_thread_footer(&DAT_1403fb424);

              }

              local_res8 = (undefined1 *)0xc000000000000000;

              in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;

              FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x248),DAT_1403fb420 + 1,&local_res10,

                            &local_res8,in_stack_fffffffffffffe68,0,&DAT_1403dc2b4,0x3c,fVar31);

              fVar32 = DAT_14039ca58;

            }

          }

          else {

            *(undefined4 *)(param_1 + 0x35c) = 2;

            fVar32 = DAT_14039ca58;

            lVar16 = *(longlong *)

                      (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0x350) * 8);

            fVar38 = (*(float *)(lVar16 + 0x2c) - *(float *)(param_1 + 0x358)) - DAT_14039ca58;

            *(float *)(param_1 + 0x17c) = *(float *)(lVar16 + 0x28) - *(float *)(param_1 + 0x354);

            *(float *)(param_1 + 0x180) = fVar38;

            local_158 = _DAT_1403040b0;

            uStack_150 = _UNK_1403040b8;

            acStack_160[0] = s_LassoCapture_140313878[8];

            acStack_160[1] = s_LassoCapture_140313878[9];

            cStack_15e = s_LassoCapture_140313878[10];

            uStack_15d = s_LassoCapture_140313878[0xb];

            local_168[0] = s_LassoCapture_140313878[0];

            local_168[1] = s_LassoCapture_140313878[1];

            local_168[2] = s_LassoCapture_140313878[2];

            local_168[3] = s_LassoCapture_140313878[3];

            local_168[4] = s_LassoCapture_140313878[4];

            local_168[5] = s_LassoCapture_140313878[5];

            cStack_162 = s_LassoCapture_140313878[6];

            uStack_161 = s_LassoCapture_140313878[7];

            _acStack_15c = 0;

            uVar11 = FUN_140040fe0();

            in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

            FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

            FUN_140027900(local_168);

            if (*(char *)(param_1 + 0x328) != '\0') {

              acStack_160[0] = s_UseSilver_1403128b0[8];

              local_168[0] = s_UseSilver_1403128b0[0];

              local_168[1] = s_UseSilver_1403128b0[1];

              local_168[2] = s_UseSilver_1403128b0[2];

              local_168[3] = s_UseSilver_1403128b0[3];

              local_168[4] = s_UseSilver_1403128b0[4];

              local_168[5] = s_UseSilver_1403128b0[5];

              cStack_162 = s_UseSilver_1403128b0[6];

              uStack_161 = s_UseSilver_1403128b0[7];

              stack0xfffffffffffffea1 = 0;

              local_158 = uVar40;

              uStack_150 = uVar24;

              uVar11 = FUN_140040fe0();

              in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

              FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

              FUN_140027900(local_168);

            }

          }

          FUN_140082550(lVar28);

          FUN_140102b40(param_1,lVar28);

          *(undefined4 *)(param_1 + 0x360) = 0;

          goto LAB_140108078;

        }

        if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + lVar16 * 8) + 8) != 3)

        goto LAB_1401088f8;

        *(undefined4 *)(param_1 + 0x35c) = 2;

        lVar16 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + lVar16 * 8);

        fVar38 = (*(float *)(lVar16 + 0x2c) - *(float *)(param_1 + 0x358)) - DAT_14030374c;

        *(float *)(param_1 + 0x17c) = *(float *)(lVar16 + 0x28) - *(float *)(param_1 + 0x354);

        *(float *)(param_1 + 0x180) = fVar38;

        local_158 = _DAT_1403040b0;

        uStack_150 = _UNK_1403040b8;

        acStack_160[0] = s_LassoCapture_140313878[8];

        acStack_160[1] = s_LassoCapture_140313878[9];

        cStack_15e = s_LassoCapture_140313878[10];

        uStack_15d = s_LassoCapture_140313878[0xb];

        local_168[0] = s_LassoCapture_140313878[0];

        local_168[1] = s_LassoCapture_140313878[1];

        local_168[2] = s_LassoCapture_140313878[2];

        local_168[3] = s_LassoCapture_140313878[3];

        local_168[4] = s_LassoCapture_140313878[4];

        local_168[5] = s_LassoCapture_140313878[5];

        cStack_162 = s_LassoCapture_140313878[6];

        uStack_161 = s_LassoCapture_140313878[7];

        _acStack_15c = 0;

        uVar11 = FUN_140040fe0();

        in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

        FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

        if (0xf < uStack_150) {

          FUN_140028310(local_168,_local_168);

        }

        if (*(char *)(param_1 + 0x328) != '\0') {

          acStack_160[0] = s_UseSilver_1403128b0[8];

          local_168[0] = s_UseSilver_1403128b0[0];

          local_168[1] = s_UseSilver_1403128b0[1];

          local_168[2] = s_UseSilver_1403128b0[2];

          local_168[3] = s_UseSilver_1403128b0[3];

          local_168[4] = s_UseSilver_1403128b0[4];

          local_168[5] = s_UseSilver_1403128b0[5];

          cStack_162 = s_UseSilver_1403128b0[6];

          uStack_161 = s_UseSilver_1403128b0[7];

          stack0xfffffffffffffea1 = 0;

          local_158 = uVar40;

          uStack_150 = uVar24;

          uVar11 = FUN_140040fe0();

          in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

          FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

          FUN_140027900(local_168);

        }

      }

      fVar32 = DAT_14039ca58;

      *(undefined4 *)(param_1 + 0x360) = 0;

    }

    else if (iVar22 == 6) {

      *(int *)(param_1 + 0x360) = *(int *)(param_1 + 0x360) + 1;

      if (*(int *)(param_1 + 0x360) == 1) {

        *(float *)(param_1 + 0x354) = fVar38;

        *(float *)(param_1 + 0x358) = fVar39;

      }

      uVar10 = *(uint *)(param_1 + 0x360);

      if (uVar10 == 0x5a) {

        bVar30 = true;

        iVar12 = (int)(*(float *)(param_1 + 0x354) * fVar37);

        iVar22 = (int)(*(float *)(param_1 + 0x358) * fVar37);

        if (((iVar12 < 0) || (*(int *)(param_1 + 0x278) <= iVar12)) ||

           ((iVar22 < 0 || (*(int *)(param_1 + 0x27c) <= iVar22)))) {

          puVar29 = &DAT_1403dc390;

        }

        else {

          puVar29 = (uint *)(*(longlong *)(param_1 + 0x270) +

                            (longlong)(iVar22 * *(int *)(param_1 + 0x278) + iVar12) * 0x28);

        }

        bVar4 = true;

        uVar9 = FUN_140101220(param_1,iVar12,iVar22);

        uVar10 = *puVar29;

        if ((uVar10 == 6) || ((uVar10 < 0x13 && ((0x50020U >> (uVar10 & 0x1f) & 1) != 0))))

        goto LAB_1401093cd;

        if (uVar9 == 0xffffffff) {

          if ((*(longlong *)(puVar29 + 4) == 0) &&

             ((((0 < iVar12 &&

                (piVar15 = (int *)FUN_1401010d0(param_1,iVar12 + -1,iVar22), *piVar15 == 6)) ||

               (((iVar12 < *(int *)(param_1 + 0x278) + -1 &&

                 (piVar15 = (int *)FUN_1401010d0(param_1,iVar12 + 1,iVar22), *piVar15 == 6)) ||

                ((0 < iVar22 &&

                 (piVar15 = (int *)FUN_1401010d0(param_1,iVar12,iVar22 + -1), *piVar15 == 6)))))) ||

              ((iVar22 < *(int *)(param_1 + 0x27c) + -1 &&

               (piVar15 = (int *)FUN_1401010d0(param_1,iVar12,iVar22 + 1), *piVar15 == 6)))))) {

            puVar29[0] = 6;

            puVar29[1] = 0;

            local_158 = 5;

            uStack_150 = 0xf;

            local_168._0_5_ = CONCAT14(s_Water_14030a274[4],s_Water_14030a274._0_4_);

            _local_168 = ZEXT516((uint5)local_168._0_5_);

            uVar10 = FUN_14006fe60(local_168);

            puVar29[2] = uVar10;

            iVar21 = FUN_1400c6580(5);

            bVar30 = iVar21 == 0;

            local_158 = _DAT_1403033d0;

            uStack_150 = _UNK_1403033d8;

            local_168 = (undefined1  [6])CONCAT24(s_Splash_140304ae8._4_2_,s_Splash_140304ae8._0_4_)

            ;

            _local_168 = ZEXT616((uint6)local_168);

            uVar11 = FUN_140040fe0();

            in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

            FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

            FUN_140027900(local_168);

            FUN_14010d7e0(param_1,CONCAT44((float)(iVar22 * 0x20 + 0x10),

                                           (float)(iVar12 * 0x20 + 0x10)));

LAB_1401093be:

            if (bVar30) goto LAB_140109623;

          }

          else {

            uVar10 = *puVar29;

            if (uVar10 != 0xf) goto LAB_140108ea9;

            if (iVar12 == 0x80) {

              if (iVar22 == 0x81) {

                plVar18 = (longlong *)0x0;

                *puVar29 = 0;

                _local_168 = ZEXT816(0);

                local_158 = 0;

                uStack_150 = 0;

                FUN_140027e30(local_168,"Plain",5);

                uVar10 = FUN_14006fe60(local_168);

                puVar29[2] = uVar10;

                FUN_14010d600(param_1,0x80,0x81);

                local_res8 = (undefined1 *)FUN_1402c704c(0x270);

                plVar17 = plVar18;

                if (local_res8 != (undefined1 *)0x0) {

                  plVar17 = (longlong *)FUN_14005e310(local_res8);

                }

                *(undefined4 *)(plVar17 + 1) = 0x26;

                (**(code **)(*plVar17 + 0x10))(plVar17);

                *(undefined4 *)((longlong)plVar17 + 0xc) = 0x45808000;

                *(undefined4 *)(plVar17 + 2) = 0x45818000;

                *(longlong **)(*(longlong *)(param_1 + 0x438) + 0x130) = plVar17;

                local_res8 = (undefined1 *)FUN_1402c704c(0x70);

                if (local_res8 != (undefined1 *)0x0) {

                  plVar18 = (longlong *)FUN_1400a8610(local_res8,2);

                }

                *(undefined4 *)((longlong)plVar18 + 0xc) = 0x26;

                _local_168 = ZEXT816(0);

                local_158 = 0;

                uStack_150 = 0;

                FUN_140027e30(local_168,&DAT_1403136f4,4);

                iVar22 = FUN_14006fe60(local_168);

                *(int *)((longlong)plVar18 + 0x3c) = iVar22 + 0x27;

                FUN_140100c90(param_1,plVar18,0x80);

                local_158 = _DAT_140304080;

                uStack_150 = _UNK_140304088;

                local_168._0_5_ = CONCAT14(s_Check_140305778[4],s_Check_140305778._0_4_);

                _local_168 = ZEXT516((uint5)local_168._0_5_);

                in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

                FUN_140040ca0(local_168,100,0,fVar31,in_stack_fffffffffffffe68);

                if (0xf < uStack_150) {

                  FUN_140028310(local_168,_local_168);

                }

                goto LAB_140109623;

              }

            }

            else if (iVar12 < 1) goto LAB_1401093cd;

            if (((iVar12 < *(int *)(param_1 + 0x278) + -1) && (0 < iVar22)) &&

               (iVar22 < *(int *)(param_1 + 0x27c) + -1)) {

              *puVar29 = 0xe;

              _local_168 = ZEXT816(0);

              local_158 = 0;

              uStack_150 = 0;

              FUN_140027e30(local_168,&DAT_140306538,4);

              uVar10 = FUN_14006fe60(local_168);

              puVar29[2] = uVar10;

              FUN_14010d600(param_1,iVar12,iVar22);

              local_158 = _DAT_140303400;

              uStack_150 = _UNK_140303408;

              acStack_160[0] = s_DestroyMountain_140313898[8];

              acStack_160[1] = s_DestroyMountain_140313898[9];

              cStack_15e = s_DestroyMountain_140313898[10];

              uStack_15d = s_DestroyMountain_140313898[0xb];

              local_168[0] = s_DestroyMountain_140313898[0];

              local_168[1] = s_DestroyMountain_140313898[1];

              local_168[2] = s_DestroyMountain_140313898[2];

              local_168[3] = s_DestroyMountain_140313898[3];

              local_168[4] = s_DestroyMountain_140313898[4];

              local_168[5] = s_DestroyMountain_140313898[5];

              cStack_162 = s_DestroyMountain_140313898[6];

              uStack_161 = s_DestroyMountain_140313898[7];

              acStack_15c[0] = s_DestroyMountain_140313898[0xc];

              acStack_15c[1] = s_DestroyMountain_140313898[0xd];

              cStack_15a = s_DestroyMountain_140313898[0xe];

              uStack_159 = 0;

              uVar11 = FUN_140040fe0();

              in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

              FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

              FUN_140027900(local_168);

              goto LAB_140109623;

            }

          }

        }

        else {

LAB_140108ea9:

          if ((uVar10 == 0x11) || (uVar10 == 0xe)) {

            if (uVar10 == 0x14) goto LAB_1401094ad;

            local_158 = _DAT_140303400;

            uStack_150 = _UNK_140303408;

            acStack_160[0] = s_DestroyMountain_140313898[8];

            acStack_160[1] = s_DestroyMountain_140313898[9];

            cStack_15e = s_DestroyMountain_140313898[10];

            uStack_15d = s_DestroyMountain_140313898[0xb];

            local_168[0] = s_DestroyMountain_140313898[0];

            local_168[1] = s_DestroyMountain_140313898[1];

            local_168[2] = s_DestroyMountain_140313898[2];

            local_168[3] = s_DestroyMountain_140313898[3];

            local_168[4] = s_DestroyMountain_140313898[4];

            local_168[5] = s_DestroyMountain_140313898[5];

            cStack_162 = s_DestroyMountain_140313898[6];

            uStack_161 = s_DestroyMountain_140313898[7];

            acStack_15c[0] = s_DestroyMountain_140313898[0xc];

            acStack_15c[1] = s_DestroyMountain_140313898[0xd];

            cStack_15a = s_DestroyMountain_140313898[0xe];

            uStack_159 = 0;

            uVar11 = FUN_140040fe0();

            in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

            FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

            if (0xf < uStack_150) {

              FUN_140028310(local_168,_local_168);

            }

            FUN_14010d600(param_1,iVar12,iVar22);

          }

          else {

            if (uVar10 != 0x14) {

              bVar5 = true;

              iVar21 = FUN_1400c6580(100);

              bVar3 = bVar4;

              if (uVar9 == 0xffffffff) {

                if ((iVar12 == 0x83) && (iVar22 == 0x7f)) {

                  lVar16 = 10;

                  uVar9 = 8;

                  do {

                    FUN_1400c6940();

                    FUN_1400c6940();

                    FUN_1400cc9d0(param_1,8);

                    fVar31 = DAT_14039ca44;

                    lVar16 = lVar16 + -1;

                  } while (lVar16 != 0);

                  local_158 = _DAT_1403033f0;

                  uStack_150 = _UNK_1403033f8;

                  acStack_160[0] = s_DungInCart_140307930[8];

                  acStack_160[1] = s_DungInCart_140307930[9];

                  local_168[0] = s_DungInCart_140307930[0];

                  local_168[1] = s_DungInCart_140307930[1];

                  local_168[2] = s_DungInCart_140307930[2];

                  local_168[3] = s_DungInCart_140307930[3];

                  local_168[4] = s_DungInCart_140307930[4];

                  local_168[5] = s_DungInCart_140307930[5];

                  cStack_162 = s_DungInCart_140307930[6];

                  uStack_161 = s_DungInCart_140307930[7];

                  _cStack_15e = 0;

                  in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

                  FUN_140040ca0(local_168,100,0,DAT_14039ca44,in_stack_fffffffffffffe68);

                  FUN_140027900(local_168);

                  fVar37 = DAT_140303fb4;

                  goto LAB_1401092e5;

                }

                uVar10 = *puVar29;

                bVar3 = bVar5;

                if (uVar10 == 4) {

                  iVar22 = FUN_1400c6580();

                  uVar9 = iVar22 + 0x13;

                  goto LAB_140109291;

                }

                if (*(int *)(param_1 + 0x37c) == 0) {

                  uVar9 = 0xe;

                  goto LAB_1401092e5;

                }

                if (uVar10 == 2) {

                  uVar9 = 5;

                  goto LAB_1401092e5;

                }

                if ((0x5e < iVar21) && (1 < *(int *)(param_1 + 0x37c))) {

                  local_res8 = local_168;

                  _local_168 = ZEXT816(0);

                  local_158 = 0;

                  uStack_150 = 0;

                  FUN_140027e30(local_168,"centipede",9);

                  uVar11 = (undefined4)(in_stack_fffffffffffffe68 >> 0x20);

                  local_148 = (char *)0x0;

                  uStack_140 = 0;

                  local_138 = 0;

                  uStack_130 = 0;

                  FUN_140027e30(&local_148,"centipede",9);

                  in_stack_fffffffffffffe68 = CONCAT44(uVar11,1);

                  FUN_140100230(param_1,iVar12,iVar22,&local_148,in_stack_fffffffffffffe68,0,

                                local_168);

                  goto LAB_140109314;

                }

                if ((uVar10 - 1 & 0xfffffffd) == 0) {

                  uVar9 = (uint)(puVar29[1] == 0x14);

                  *puVar29 = 0;

                  local_148 = (char *)0x0;

                  uStack_140 = 0;

                  local_138 = 0;

                  uStack_130 = 0;

                  FUN_140027e30(&local_148,"Plain",5);

                  uVar10 = FUN_14006fe60(&local_148);

                  puVar29[2] = uVar10;

                  puVar29[1] = 0;

                  bVar3 = false;

                  iVar22 = FUN_1400c6580(5);

                  bVar30 = iVar22 == 0;

                  goto LAB_140109291;

                }

                if (4 < uVar10 - 9) {

                  if (iVar21 < 0x46) {

                    local_128 = _DAT_140313b60;

                    uStack_120 = _UNK_140313b68;

                    local_118 = _DAT_140313b90;

                    uStack_110 = _UNK_140313b98;

                    local_108 = _DAT_140313ba0;

                    uStack_100 = _UNK_140313ba8;

                    local_f8 = _DAT_140313bb0;

                    uStack_f0 = _UNK_140313bb8;

                    local_e8 = 0x27;

                    local_e4 = 0x28;

                    local_e0 = 0x29;

                    iVar22 = FUN_1400c6580(0x13);

                    uVar9 = *(uint *)((longlong)&local_128 + (longlong)iVar22 * 4);

                    if ((3 < *(int *)(param_1 + 0x37c)) || (uVar9 != 0xe)) goto LAB_140109291;

                  }

                  uVar9 = 6;

                  goto LAB_140109297;

                }

                *puVar29 = 0;

                local_148 = (char *)0x0;

                uStack_140 = 0;

                local_138 = 0;

                uStack_130 = 0;

                FUN_140027e30(&local_148,"Plain",5);

                uVar10 = FUN_14006fe60(&local_148);

                puVar29[2] = uVar10;

                puVar29[1] = 0;

                local_158 = _DAT_140304cc0;

                uStack_150 = _UNK_140304cc8;

                acStack_160[0] = s_DestroyTree_1403138a8[8];

                acStack_160[1] = s_DestroyTree_1403138a8[9];

                local_168[0] = s_DestroyTree_1403138a8[0];

                local_168[1] = s_DestroyTree_1403138a8[1];

                local_168[2] = s_DestroyTree_1403138a8[2];

                local_168[3] = s_DestroyTree_1403138a8[3];

                local_168[4] = s_DestroyTree_1403138a8[4];

                local_168[5] = s_DestroyTree_1403138a8[5];

                cStack_162 = s_DestroyTree_1403138a8[6];

                uStack_161 = s_DestroyTree_1403138a8[7];

                cStack_15e = s_DestroyTree_1403138a8[10];

                _uStack_15d = 0;

                uVar11 = FUN_140040fe0();

                in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

                FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

                if (0xf < uStack_150) {

                  FUN_140028310(local_168,_local_168);

                }

                FUN_14010d260(param_1,iVar12,iVar22,1);

                FUN_14010d260(param_1,iVar12,iVar22);

              }

              else {

LAB_140109291:

                bVar4 = bVar3;

                if (uVar9 == 6) {

LAB_140109297:

                  local_158 = _DAT_1403033d0;

                  uStack_150 = _UNK_1403033d8;

                  local_168 = (undefined1  [6])

                              CONCAT24(s_fossil_140304364._4_2_,s_fossil_140304364._0_4_);

                  _local_168 = ZEXT616((uint6)local_168);

                  FUN_140037710(local_168);

                  FUN_140027900(local_168);

                  bVar3 = bVar4;

LAB_1401092e5:

                  FUN_1400cc9d0(param_1,uVar9);

                }

                else if (uVar9 != 0xffffffff) goto LAB_1401092e5;

                if (bVar3) {

LAB_140109314:

                  puVar19 = (undefined1 *)0x0;

                  uVar10 = *puVar29;

                  local_148 = (char *)0x0;

                  uStack_140 = 0;

                  local_138 = 0;

                  uStack_130 = 0;

                  FUN_140027e30(&local_148,&DAT_14031373c,4);

                  iVar22 = FUN_14006fe60(&local_148);

                  local_res8 = (undefined1 *)FUN_1402c704c(0x70);

                  if (local_res8 != (undefined1 *)0x0) {

                    puVar19 = (undefined1 *)FUN_1400a8680(local_res8,4,iVar22 + (uint)(uVar10 == 4))

                    ;

                  }

                  *(undefined4 *)(puVar19 + 0x28) = *(undefined4 *)(param_1 + 0x354);

                  *(float *)(puVar19 + 0x2c) = *(float *)(param_1 + 0x358) + fVar31;

                  local_res8 = puVar19;

                  FUN_14003e600(param_1 + 0xb8,&local_res8);

                }

              }

              *(int *)(param_1 + 0x37c) = *(int *)(param_1 + 0x37c) + 1;

              goto LAB_1401093be;

            }

LAB_1401094ad:

            local_158 = _DAT_1403033d0;

            uStack_150 = _UNK_1403033d8;

            local_168 = (undefined1  [6])CONCAT24(s_Splash_140304ae8._4_2_,s_Splash_140304ae8._0_4_)

            ;

            _local_168 = ZEXT616((uint6)local_168);

            uVar11 = FUN_140040fe0();

            in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

            FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

            FUN_140027900(local_168);

            FUN_14010d7e0(param_1,CONCAT44((float)(iVar22 * 0x20 + 0x10),

                                           (float)(iVar12 * 0x20 + 0x10)));

          }

          *puVar29 = 0;

          local_158 = 5;

          uStack_150 = 0xf;

          local_168._0_5_ = CONCAT14(s_Plain_14030a27c[4],s_Plain_14030a27c._0_4_);

          _local_168 = ZEXT516((uint5)local_168._0_5_);

          uVar10 = FUN_14006fe60(local_168);

          puVar29[2] = uVar10;

LAB_140109623:

          if (*(char *)(param_1 + 0x330) == '\0') {

            if (0 < *(int *)(param_1 + 0x32c)) {

              *(int *)(param_1 + 0x32c) = *(int *)(param_1 + 0x32c) + -1;

            }

          }

          else if (*(int *)(param_1 + 900) == 0) {

            *(undefined4 *)(param_1 + 900) = 0x78;

            *(undefined4 *)(param_1 + 0x34c) = 0xffffffff;

            goto LAB_1401093cd;

          }

          *(undefined4 *)(param_1 + 0x34c) = 0xffffffff;

        }

LAB_1401093cd:

        *(undefined4 *)(param_1 + 0x35c) = 7;

        *(undefined4 *)(param_1 + 0x350) = 0xffffffff;

        *(undefined4 *)(param_1 + 0xd0) = 0xffffffff;

        if (*(int *)(param_1 + 0x388) != -1) {

          FUN_140040ea0();

          *(undefined4 *)(param_1 + 0x388) = 0xffffffff;

        }

        uVar24 = _UNK_1403040a8;

        uVar40 = _DAT_1403040a0;

        local_158 = _DAT_1403040a0;

        uStack_150 = _UNK_1403040a8;

        acStack_160[0] = s_DigFinish_1403138b8[8];

        local_168[0] = s_DigFinish_1403138b8[0];

        local_168[1] = s_DigFinish_1403138b8[1];

        local_168[2] = s_DigFinish_1403138b8[2];

        local_168[3] = s_DigFinish_1403138b8[3];

        local_168[4] = s_DigFinish_1403138b8[4];

        local_168[5] = s_DigFinish_1403138b8[5];

        cStack_162 = s_DigFinish_1403138b8[6];

        uStack_161 = s_DigFinish_1403138b8[7];

        stack0xfffffffffffffea1 = 0;

        uVar11 = FUN_140040fe0();

        in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

        FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

        fVar32 = DAT_14039ca58;

        if (0xf < uStack_150) {

          if ((0xfff < uStack_150 + 1) &&

             (0x1f < (_local_168 - *(longlong *)(_local_168 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

          fVar32 = DAT_14039ca58;

        }

      }

      else {

        fVar32 = DAT_14039ca58;

        if ((int)uVar10 < 0x5a) {

          uVar10 = uVar10 & 0x80000003;

          if ((int)uVar10 < 0) {

            uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;

          }

          if (uVar10 == 0) {

            uVar11 = FUN_1400c6940();

            uVar13 = FUN_1400c6940();

            local_res8 = (undefined1 *)CONCAT44(uVar11,uVar13);

            in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;

            FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x248),0xffffffff,param_1 + 0x354,&local_res8,

                          in_stack_fffffffffffffe68,0,&DAT_1403dc2bc,0x2d,fVar31);

            fVar32 = DAT_14039ca58;

          }

        }

      }

    }

    else if (iVar22 == 8) {

      if ((0 < *(int *)(param_1 + 0x33c)) && (0 < *(int *)(param_1 + 0x378))) {

        iVar22 = *(int *)(param_1 + 0x370);

        iVar12 = *(int *)(param_1 + 0x374);

        if ((-1 < iVar22) &&

           (((iVar22 < *(int *)(param_1 + 0x278) && (-1 < iVar12)) &&

            (iVar12 < *(int *)(param_1 + 0x27c))))) {

          lVar16 = FUN_1401010d0(param_1,iVar22);

          fVar32 = DAT_14039ca58;

          if (*(char *)((ulonglong)(*(int *)(param_1 + 0x378) == 1) + 0xc + lVar16) == '\0') {

            *(undefined1 *)((ulonglong)(*(int *)(param_1 + 0x378) == 1) + 0xc + lVar16) = 1;

            FUN_140104f00(param_1,4,1);

            local_158 = _DAT_1403033f0;

            uStack_150 = _UNK_1403033f8;

            acStack_160[0] = s_FencePlace_1403138c8[8];

            acStack_160[1] = s_FencePlace_1403138c8[9];

            local_168[0] = s_FencePlace_1403138c8[0];

            local_168[1] = s_FencePlace_1403138c8[1];

            local_168[2] = s_FencePlace_1403138c8[2];

            local_168[3] = s_FencePlace_1403138c8[3];

            local_168[4] = s_FencePlace_1403138c8[4];

            local_168[5] = s_FencePlace_1403138c8[5];

            cStack_162 = s_FencePlace_1403138c8[6];

            uStack_161 = s_FencePlace_1403138c8[7];

            _cStack_15e = 0;

            in_stack_fffffffffffffe68 = CONCAT44((int)(in_stack_fffffffffffffe68 >> 0x20),0x14);

            FUN_14010de70(param_1,local_168,0,CONCAT44(fVar39,fVar38),in_stack_fffffffffffffe68,100,

                          CONCAT44(uVar11,fVar31));

            if (0xf < uStack_150) {

              FUN_140028310(local_168,_local_168);

            }

            cVar6 = FUN_1401035b0(param_1,iVar22,iVar12);

            if (*(int *)(param_1 + 0x378) == 1) {

              iVar22 = iVar22 + -1;

            }

            cVar7 = FUN_1401035b0(param_1,iVar22);

            fVar32 = DAT_14039ca58;

            if (cVar6 != '\0' || cVar7 != '\0') {

              local_158 = _DAT_140304cc0;

              uStack_150 = _UNK_140304cc8;

              acStack_160[0] = s_ReclaimLand_1403138d8[8];

              acStack_160[1] = s_ReclaimLand_1403138d8[9];

              local_168[0] = s_ReclaimLand_1403138d8[0];

              local_168[1] = s_ReclaimLand_1403138d8[1];

              local_168[2] = s_ReclaimLand_1403138d8[2];

              local_168[3] = s_ReclaimLand_1403138d8[3];

              local_168[4] = s_ReclaimLand_1403138d8[4];

              local_168[5] = s_ReclaimLand_1403138d8[5];

              cStack_162 = s_ReclaimLand_1403138d8[6];

              uStack_161 = s_ReclaimLand_1403138d8[7];

              cStack_15e = s_ReclaimLand_1403138d8[10];

              _uStack_15d = 0;

              in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

              FUN_140040ca0(local_168,100,0,fVar31,in_stack_fffffffffffffe68);

              if (0xf < uStack_150) {

                FUN_140028310(local_168,_local_168);

              }

              *(undefined4 *)(param_1 + 0x35c) = 0;

              fVar32 = DAT_14039ca58;

            }

          }

        }

      }

    }

    else if (((iVar22 == 0) && (*(int *)(param_1 + 0x34c) == -1)) &&

            ((*(int *)(param_1 + 0xd0) == -1 ||

             (*(int *)(*(longlong *)

                        (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0xd0) * 8) + 8

                      ) != 1)))) {

      *(float *)(*(longlong *)(param_1 + 0x300) + 0x7c) = fVar38;

      *(float *)(*(longlong *)(param_1 + 0x300) + 0x80) = fVar39;

      fVar35 = DAT_140303390;

      fVar32 = *(float *)(*(longlong *)(param_1 + 0x300) + 0x28);

      if ((float)((uint)(fVar32 - fVar38) & uVar25) < DAT_140303390) {

        *(float *)(*(longlong *)(param_1 + 0x300) + 0x7c) = fVar32;

      }

      fVar38 = *(float *)(*(longlong *)(param_1 + 0x300) + 0x2c);

      if ((float)((uint)(fVar38 - fVar39) & uVar25) < fVar35) {

        *(float *)(*(longlong *)(param_1 + 0x300) + 0x80) = fVar38;

      }

      in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffff00000000;

      FUN_1400a8890();

      fVar32 = DAT_14039ca58;

      if (0 < *(int *)(*(longlong *)(param_1 + 0x300) + 0x24)) {

        *(undefined1 *)(param_1 + 0x38c) = 1;

      }

    }

  }

LAB_140108078:

  fVar38 = DAT_140303394;

  if (((DAT_1403ed968 != 0) && (*(int *)(param_1 + 0xe0) == -1)) && (1 < *(int *)(param_1 + 600))) {

    if (*(int *)(param_1 + 0x388) != -1) {

      FUN_140040ea0();

      *(undefined4 *)(param_1 + 0x388) = 0xffffffff;

    }

    iVar22 = *(int *)(param_1 + 0x35c);

    if (iVar22 == 0) {

      if (((*(int *)(param_1 + 0xd0) != -1) && (*(char *)(param_1 + 0x38c) == '\0')) &&

         ((*(char *)(*(longlong *)(param_1 + 0x300) + 0xad) == '\0' &&

          ((*(int *)(*(longlong *)

                      (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0xd0) * 8) + 8)

            == 1 && (cVar6 = (**(code **)(*DAT_1403f4e00 + 0x18))(), cVar6 != '\0')))))) {

        FUN_1400a89f0(*(undefined8 *)(param_1 + 0x300));

        FUN_1400fb9c0(*(undefined8 *)(param_1 + 0x300));

        *(undefined4 *)(*(longlong *)(param_1 + 0x300) + 0x38) = 1;

        acStack_160[0] = s_ZoomTruck_1403138e8[8];

        local_168[0] = s_ZoomTruck_1403138e8[0];

        local_168[1] = s_ZoomTruck_1403138e8[1];

        local_168[2] = s_ZoomTruck_1403138e8[2];

        local_168[3] = s_ZoomTruck_1403138e8[3];

        local_168[4] = s_ZoomTruck_1403138e8[4];

        local_168[5] = s_ZoomTruck_1403138e8[5];

        cStack_162 = s_ZoomTruck_1403138e8[6];

        uStack_161 = s_ZoomTruck_1403138e8[7];

        stack0xfffffffffffffea1 = 0;

        in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

        local_158 = uVar40;

        uStack_150 = uVar24;

        FUN_140040ca0(local_168,100,0,fVar31,in_stack_fffffffffffffe68);

        if (0xf < uStack_150) {

          FUN_140028310(local_168,_local_168);

        }

        FUN_14009c780(DAT_1403ee020,DAT_1403f4e00);

        (**(code **)(*DAT_1403f4e00 + 0x40))();

      }

    }

    else if (iVar22 - 6U < 3) {

      *(undefined4 *)(param_1 + 0x35c) = 0;

    }

    else if (iVar22 == 1) {

      *(undefined4 *)(param_1 + 0x35c) = 4;

    }

    else if (iVar22 == 2) {

      cVar6 = (**(code **)(**(longlong **)(param_1 + 0x300) + 0x20))();

      if (cVar6 == '\0') {

        local_148 = (char *)0x0;

        uStack_140 = 0;

        local_138 = 0;

        uStack_130 = 0;

        local_148 = (char *)FUN_1400285e0(0x20);

        uVar40 = s_LassoReturnInLoop_1403138f8._8_8_;

        local_138 = _DAT_1403040f0;

        uStack_130 = _UNK_1403040f8;

        *(undefined8 *)local_148 = s_LassoReturnInLoop_1403138f8._0_8_;

        *(undefined8 *)(local_148 + 8) = uVar40;

        local_148[0x10] = s_LassoReturnInLoop_1403138f8[0x10];

        local_148[0x11] = '\0';

        in_stack_fffffffffffffe68 = CONCAT71((int7)(in_stack_fffffffffffffe68 >> 8),1);

        uVar11 = FUN_140040ca0(&local_148,100,0,fVar31,in_stack_fffffffffffffe68);

        *(undefined4 *)(param_1 + 0x388) = uVar11;

        FUN_140027900(&local_148);

        *(undefined4 *)(param_1 + 0x35c) = 4;

        uVar24 = _UNK_140304098;

        uVar40 = _DAT_140304090;

        fVar39 = DAT_140303750;

        if (*(char *)(param_1 + 0x328) != '\0') {

          lVar16 = *(longlong *)

                    (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0x350) * 8);

          if (*(int *)(lVar16 + 8) == 0) {

            FUN_140082010(lVar16);

          }

          else if (*(int *)(lVar16 + 8) == 3) {

            iVar21 = (int)(*(float *)(lVar16 + 0x28) * fVar37);

            iVar12 = (int)(*(float *)(lVar16 + 0x2c) * fVar37);

            iVar22 = iVar12 + -1;

            iVar12 = iVar12 + 1;

            local_res8 = (undefined1 *)CONCAT44(local_res8._4_4_,iVar12);

            if (iVar22 <= iVar12) {

              iVar26 = iVar21 + -1;

              local_res10 = CONCAT44(local_res10._4_4_,iVar26);

              iVar21 = iVar21 + 1;

              do {

                if (iVar26 <= iVar21) {

                  do {

                    if (((-1 < iVar26) && (iVar26 < *(int *)(param_1 + 0x278))) &&

                       ((-1 < iVar22 && (iVar22 < *(int *)(param_1 + 0x278))))) {

                      lVar28 = FUN_1401010d0(param_1,iVar26);

                      for (lVar28 = *(longlong *)(lVar28 + 0x10); lVar28 != 0;

                          lVar28 = *(longlong *)(lVar28 + 0x58)) {

                        if (((*(int *)(lVar28 + 8) == 4) &&

                            ((float)((uint)(*(float *)(lVar28 + 0x28) - *(float *)(lVar16 + 0x28)) &

                                    uVar25) < fVar39)) &&

                           ((float)((uint)(*(float *)(lVar28 + 0x2c) - *(float *)(lVar16 + 0x2c)) &

                                   uVar25) < fVar38)) {

                          *(undefined1 *)(lVar28 + 0x11) = 1;

                          *(undefined1 *)(lVar16 + 0x11) = 1;

                          uVar11 = *(undefined4 *)(lVar16 + 0xc);

                          if (((iVar26 < *(int *)(param_1 + 0x278)) &&

                              (iVar22 < *(int *)(param_1 + 0x27c))) &&

                             (iVar12 = FUN_140101220(param_1,iVar26,iVar22), iVar12 == -1)) {

                            local_res18 = iVar22 * *(int *)(param_1 + 0x278) + iVar26;

                            puVar2 = *(undefined8 **)(param_1 + 0x428);

                            uStackX_1c = uVar11;

                            if (puVar2 == *(undefined8 **)(param_1 + 0x430)) {

                              FUN_140030680(param_1 + 0x420,puVar2,&local_res18);

                            }

                            else {

                              *puVar2 = CONCAT44(uVar11,local_res18);

                              *(longlong *)(param_1 + 0x428) = *(longlong *)(param_1 + 0x428) + 8;

                            }

                          }

                          local_158 = uVar40;

                          uStack_150 = uVar24;

                          _local_168 = (unkuint9)0x656c6f486c6c6946;

                          stack0xfffffffffffffea1 = 0;

                          uVar11 = FUN_140040fe0();

                          in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00

                          ;

                          FUN_140040ca0(local_168,100,uVar11,fVar31,in_stack_fffffffffffffe68);

                          if (0xf < uStack_150) {

                            FUN_140028310(local_168,_local_168);

                          }

                          break;

                        }

                      }

                    }

                    iVar26 = iVar26 + 1;

                  } while (iVar26 <= iVar21);

                  iVar12 = (int)local_res8;

                  iVar26 = (int)local_res10;

                }

                iVar22 = iVar22 + 1;

              } while (iVar22 <= iVar12);

            }

          }

          *(undefined4 *)(param_1 + 0x350) = 0xffffffff;

          local_158 = _DAT_140304080;

          uStack_150 = _UNK_140304088;

          local_168._0_5_ = CONCAT14(s_Lasso_14030ac4c[4],s_Lasso_14030ac4c._0_4_);

          _local_168 = ZEXT516((uint5)local_168._0_5_);

          in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

          FUN_140040ca0(local_168,100,0,fVar31,in_stack_fffffffffffffe68);

          FUN_140027900(local_168);

        }

      }

      else {

        *(undefined4 *)(param_1 + 0x35c) = 4;

      }

    }

  }

  uVar11 = 0xffffffff;

  if (DAT_1403ed958 == 0) {

    *(undefined1 *)(param_1 + 0x38c) = 0;

  }

  if (*(int *)(param_1 + 0x35c) == 5) {

    *(int *)(param_1 + 0x360) = *(int *)(param_1 + 0x360) + 1;

    *(float *)(param_1 + 0x354) = *(float *)(param_1 + 0x354) + *(float *)(param_1 + 0x364);

    *(float *)(param_1 + 0x358) = *(float *)(param_1 + 0x368) + *(float *)(param_1 + 0x358);

    iVar22 = 0;

    lVar16 = *(longlong *)(param_1 + 0xb8);

    if (*(longlong *)(param_1 + 0xc0) - lVar16 >> 3 != 0) {

      lVar28 = 0;

      do {

        if (((int)(*(longlong **)(lVar28 + lVar16))[1] == 0) &&

           (cVar6 = (**(code **)(**(longlong **)(lVar28 + lVar16) + 0x20))(), cVar6 != '\0')) {

          uVar40 = *(undefined8 *)(*(longlong *)(param_1 + 0xb8) + (longlong)iVar22 * 8);

          local_158 = _DAT_140305680;

          uStack_150 = _UNK_140305688;

          stack0xfffffffffffffe9c = ZEXT412(0);

          local_168._0_5_ = 0x746f6853;

          uVar13 = FUN_140040fe0();

          in_stack_fffffffffffffe68 = in_stack_fffffffffffffe68 & 0xffffffffffffff00;

          FUN_140040ca0(local_168,100,uVar13,fVar31,in_stack_fffffffffffffe68);

          if (0xf < uStack_150) {

            if ((0xfff < uStack_150 + 1) &&

               (0x1f < (_local_168 - *(longlong *)(_local_168 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          FUN_140102b40(param_1,uVar40);

          FUN_1400820a0(uVar40);

          *(undefined4 *)(param_1 + 0x35c) = 0;

          break;

        }

        iVar22 = iVar22 + 1;

        lVar28 = lVar28 + 8;

        lVar16 = *(longlong *)(param_1 + 0xb8);

      } while ((ulonglong)(longlong)iVar22 <

               (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar16 >> 3));

    }

    if ((*(int *)(param_1 + 0x360) == 0x3c) &&

       (*(undefined4 *)(param_1 + 0x35c) = 0,

       *(int *)(param_1 + 0x31c + (longlong)*(int *)(param_1 + 0x34c) * 8) == 0)) {

      *(undefined4 *)(param_1 + 0x34c) = 0xffffffff;

    }

  }

  if (*(int *)(param_1 + 0x350) != -1) {

    fVar39 = *(float *)(param_1 + 0x180);

    fVar37 = *(float *)(param_1 + 0x358);

    *(float *)(*(longlong *)

                (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0x350) * 8) + 0x28) =

         *(float *)(param_1 + 0x17c) + *(float *)(param_1 + 0x354);

    *(float *)(*(longlong *)

                (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0x350) * 8) + 0x2c) =

         fVar39 + fVar37;

  }

  fVar39 = DAT_14030339c;

  if (*(int *)(param_1 + 0x35c) == 3) {

    *(int *)(param_1 + 0x360) = *(int *)(param_1 + 0x360) + 1;

    if ((*(int *)(param_1 + 0x360) < 0x4b) || (DAT_1403ed958 != 0)) goto LAB_14010a2ee;

  }

  else {

    if (*(int *)(param_1 + 0x35c) != 4) goto LAB_14010a2ee;

    lVar16 = *(longlong *)(param_1 + 0x300);

    fVar35 = *(float *)(lVar16 + 0x2c) - fVar38;

    fVar37 = *(float *)(lVar16 + 0x28);

    iVar22 = *(int *)(param_1 + 0x350);

    uVar24 = (ulonglong)iVar22;

    if (iVar22 == -1) {

      fVar35 = fVar35 - DAT_14030339c;

    }

    else {

      fVar37 = fVar37 - (float)(*(int *)(lVar16 + 0x38) * 0xe);

    }

    fVar35 = fVar35 - *(float *)(param_1 + 0x358);

    fVar37 = fVar37 - *(float *)(param_1 + 0x354);

    fVar33 = fVar37 * fVar37 + fVar35 * fVar35;

    if (fVar33 < 0.0) {

      fVar33 = (float)FUN_1402cdfa0();

    }

    else {

      fVar33 = SQRT(fVar33);

    }

    if (DAT_14039c9f0 <= fVar33) {

      fVar37 = fVar37 * (fVar31 / fVar33);

      fVar35 = fVar35 * (fVar31 / fVar33);

      if (DAT_14030374c < fVar33) {

        if ((iVar22 != -1) &&

           (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + uVar24 * 8) + 8) == 0)) {

          *(undefined1 *)(lVar16 + 0x9c) = 1;

        }

        *(float *)(param_1 + 0x354) = fVar37 + fVar37 + *(float *)(param_1 + 0x354);

        *(float *)(param_1 + 0x358) = fVar35 + fVar35 + *(float *)(param_1 + 0x358);

        goto LAB_14010a2ee;

      }

    }

    if ((-1 < iVar22) &&

       (uVar24 < (ulonglong)(*(longlong *)(param_1 + 0xc0) - *(longlong *)(param_1 + 0xb8) >> 3))) {

      lVar16 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + uVar24 * 8);

      if (*(int *)(lVar16 + 8) == 0) {

        lVar28 = *(longlong *)(lVar16 + 0x80);

        if (lVar28 != 0) {

          if ((((*(int *)(lVar16 + 0x74) < *(int *)(lVar16 + 0x8c) / 2) &&

               (*(int *)(lVar28 + 0x1c) < 4)) && (0 < *(int *)(lVar28 + 0x1fc))) &&

             (*(int *)(lVar28 + 0x24c) != 0)) {

            uVar8 = 1;

          }

          else {

            uVar8 = 0;

          }

          *(undefined1 *)(lVar28 + 0x205) = uVar8;

          *(undefined1 *)(lVar28 + 0x206) = 0;

          FUN_1400fb050(DAT_1403f4e00,lVar28);

          *(undefined8 *)(lVar16 + 0x80) = 0;

          *(undefined1 *)(lVar16 + 0x11) = 1;

          if ((*(char *)(param_1 + 0x328) == '\0') && (0 < *(int *)(param_1 + 0x324))) {

            *(int *)(param_1 + 0x324) = *(int *)(param_1 + 0x324) + -1;

          }

          *(undefined4 *)(param_1 + 0x34c) = 0xffffffff;

          _local_168 = ZEXT816(0);

          local_158 = 0;

          uStack_150 = 0;

          pcVar20 = (char *)FUN_1400285e0(0x20);

          uVar40 = s_LassoArriveWithHorse_140313910._8_8_;

          _local_168 = (longlong)pcVar20;

          local_158 = _DAT_140303420;

          uStack_150 = _UNK_140303428;

          *(undefined8 *)pcVar20 = s_LassoArriveWithHorse_140313910._0_8_;

          *(undefined8 *)(pcVar20 + 8) = uVar40;

          *(undefined4 *)(pcVar20 + 0x10) = s_LassoArriveWithHorse_140313910._16_4_;

          pcVar20[0x14] = '\0';

          FUN_140040ca0(local_168,100,0,fVar31,in_stack_fffffffffffffe68 & 0xffffffffffffff00);

          if (0xf < uStack_150) {

            if ((0xfff < uStack_150 + 1) &&

               (0x1f < (_local_168 - *(longlong *)(_local_168 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          local_158 = _DAT_140304080;

          uStack_150 = _UNK_140304088;

          local_168._0_5_ = CONCAT14(s_lasso_1403043dc[4],s_lasso_1403043dc._0_4_);

          _local_168 = ZEXT516((uint5)local_168._0_5_);

          FUN_140037710(local_168);

          if (0xf < uStack_150) {

            FUN_140028310(local_168,_local_168);

          }

        }

      }

      else if (*(int *)(lVar16 + 8) == 3) {

        *(float *)(lVar16 + 0x2c) = *(float *)(lVar16 + 0x2c) + fVar32;

        if ((*(char *)(param_1 + 0x328) == '\0') && (0 < *(int *)(param_1 + 0x324))) {

          *(int *)(param_1 + 0x324) = *(int *)(param_1 + 0x324) + -1;

        }

        *(undefined4 *)(param_1 + 0x34c) = 0xffffffff;

        local_148 = (char *)0x0;

        uStack_140 = 0;

        local_138 = 0;

        uStack_130 = 0;

        local_148 = (char *)FUN_1400285e0(0x20);

        uVar40 = s_LassoArriveWithHorse_140313910._8_8_;

        local_138 = _DAT_140303420;

        uStack_130 = _UNK_140303428;

        *(undefined8 *)local_148 = s_LassoArriveWithHorse_140313910._0_8_;

        *(undefined8 *)(local_148 + 8) = uVar40;

        *(undefined4 *)(local_148 + 0x10) = s_LassoArriveWithHorse_140313910._16_4_;

        local_148[0x14] = '\0';

        FUN_140040ca0(&local_148,100,0,fVar31,in_stack_fffffffffffffe68 & 0xffffffffffffff00);

        FUN_140027900(&local_148);

      }

    }

    if (*(int *)(param_1 + 0x388) != -1) {

      FUN_140040ea0();

      *(undefined4 *)(param_1 + 0x388) = 0xffffffff;

    }

    *(undefined4 *)(param_1 + 0x350) = 0xffffffff;

  }

  *(undefined4 *)(param_1 + 0x35c) = 0;

LAB_14010a2ee:

  if ((*(int *)(param_1 + 0x34c) == 1) && (*(int *)(param_1 + 0x35c) == 0)) {

    fVar37 = *(float *)(*(longlong *)(param_1 + 0x300) + 0x2c);

    *(undefined4 *)(param_1 + 0x354) = *(undefined4 *)(*(longlong *)(param_1 + 0x300) + 0x28);

    *(float *)(param_1 + 0x358) = (fVar37 - fVar39) - fVar38;

  }

  if (((DAT_1403ed96c != 0) || (cVar6 = FUN_1400ca0f0(param_1,1), cVar6 != '\0')) &&

     (*(int *)(param_1 + 0x35c) == 0)) {

    *(undefined4 *)(param_1 + 0x34c) = 0xffffffff;

  }

  *(undefined4 *)(param_1 + 0x124) = 0;

  if (*(int *)(param_1 + 0xd8) - 0xdU < 6) {

    *(undefined4 *)(param_1 + 0x124) = 9;

    return;

  }

  iVar22 = *(int *)(param_1 + 0x34c);

  if (iVar22 == 1) {

    if (*(int *)(param_1 + 0x350) == -1) {

      uVar11 = 7;

    }

  }

  else {

    if (iVar22 == 3) {

      *(undefined4 *)(param_1 + 0x124) = 7;

      return;

    }

    if (iVar22 != 2) {

      if (*(int *)(param_1 + 0xd0) == -1) {

        return;

      }

      iVar22 = *(int *)(*(longlong *)

                         (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0xd0) * 8) +

                       8);

      if (iVar22 != 1) {

        if (iVar22 != 2) {

          return;

        }

        if (2 < *(int *)(param_1 + 0x268)) {

          return;

        }

        *(undefined4 *)(param_1 + 0x124) = 5;

        return;

      }

      if (*(char *)(param_1 + 0x38c) != '\0') {

        return;

      }

      if (*(char *)(*(longlong *)(param_1 + 0x300) + 0xad) != '\0') {

        return;

      }

      *(undefined4 *)(param_1 + 0x124) = 4;

      return;

    }

    if (*(int *)(param_1 + 0x35c) != 6) {

      if (*(char *)(param_1 + 0x380) == '\0') {

        return;

      }

      *(undefined4 *)(param_1 + 0x124) = 8;

      return;

    }

  }

  *(undefined4 *)(param_1 + 0x124) = uVar11;

  return;

}




