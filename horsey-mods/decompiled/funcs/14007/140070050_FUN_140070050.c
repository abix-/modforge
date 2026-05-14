// Address: 0x140070050
// Ghidra name: FUN_140070050
// ============ 0x140070050 FUN_140070050 (size=3463) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140070050(undefined8 ****param_1,char param_2,float param_3,float param_4)



{

  longlong *plVar1;

  char cVar2;

  int iVar3;

  uint uVar4;

  undefined8 ****ppppuVar5;

  ulonglong uVar6;

  undefined8 uVar7;

  longlong lVar8;

  longlong *plVar9;

  longlong lVar10;

  char *_Str;

  size_t sVar11;

  longlong *plVar12;

  undefined8 ****ppppuVar13;

  longlong lVar14;

  ulonglong uVar15;

  undefined8 ***pppuVar16;

  longlong *plVar17;

  ulonglong uVar18;

  int iVar19;

  ulonglong uVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  int local_228;

  int local_224;

  int local_220;

  int local_21c;

  int local_218;

  int local_214;

  int local_210;

  undefined4 local_20c;

  undefined8 ***local_208;

  undefined8 **ppuStack_200;

  undefined8 **local_1f8;

  ulonglong uStack_1f0;

  int local_1e8;

  int local_1e4;

  undefined4 local_1e0 [2];

  undefined8 ***local_1d8;

  undefined8 **ppuStack_1d0;

  undefined1 local_1c8 [16];

  int local_1b8;

  longlong local_1b0;

  undefined8 ***local_1a8;

  undefined1 local_1a0;

  undefined7 uStack_19f;

  undefined8 local_190;

  ulonglong uStack_188;

  undefined8 ***local_180;

  undefined8 uStack_178;

  undefined8 **local_170;

  ulonglong uStack_168;

  undefined8 ***local_160;

  undefined8 **ppuStack_158;

  undefined1 local_150 [16];

  ulonglong local_140;

  longlong local_138;

  undefined8 ***local_130;

  longlong lStack_128;

  undefined1 local_120 [16];

  double local_110;

  double local_108 [2];

  undefined1 local_f8 [16];

  undefined **local_e8 [14];

  undefined1 local_78 [80];

  

  uStack_178 = 0;

  local_170 = (undefined8 ***)0x0;

  uStack_168 = 0xf;

  local_180 = (undefined8 ****)0x0;

  ppppuVar13 = param_1;

  if ((undefined8 ***)0xf < param_1[3]) {

    ppppuVar13 = (undefined8 ****)*param_1;

  }

  if (param_1[2] == (undefined8 ***)0x0) {

LAB_1400700ce:

    iVar3 = -1;

  }

  else {

    lVar14 = (longlong)param_1[2] + -1;

    lVar10 = -1;

    if (lVar14 != -1) {

      lVar10 = lVar14;

    }

    lVar14 = lVar10 + 1 + (longlong)ppppuVar13;

    lVar10 = thunk_FUN_1402c6070(ppppuVar13,lVar14,0x2e);

    if (lVar10 == lVar14) goto LAB_1400700ce;

    iVar3 = (int)lVar10 - (int)ppppuVar13;

  }

  if (iVar3 == -1) {

    pppuVar16 = (undefined8 ***)0x0;

    uVar6 = 0xf;

    if (&local_180 != param_1) {

      ppppuVar13 = param_1;

      if ((undefined8 ***)0xf < param_1[3]) {

        ppppuVar13 = (undefined8 ****)*param_1;

      }

      FUN_140027f50(&local_180,ppppuVar13,param_1[2]);

      pppuVar16 = (undefined8 ***)local_170;

      uVar6 = uStack_168;

    }

    FUN_140027810(param_1,&DAT_14030a284);

  }

  else {

    local_208 = (undefined8 ****)0x0;

    ppuStack_200 = (undefined8 **)0x0;

    pppuVar16 = (undefined8 ***)(longlong)iVar3;

    if (param_1[2] < (undefined8 ***)(longlong)iVar3) {

      pppuVar16 = param_1[2];

    }

    ppppuVar13 = param_1;

    if ((undefined8 ***)0xf < param_1[3]) {

      ppppuVar13 = (undefined8 ****)*param_1;

    }

    if ((undefined8 ***)0x7fffffffffffffff < pppuVar16) {

                    /* WARNING: Subroutine does not return */

      FUN_140024130();

    }

    local_1f8 = pppuVar16;

    if (pppuVar16 < (undefined8 ***)0x10) {

      uStack_1f0 = 0xf;

      FUN_1402f8e20(&local_208,ppppuVar13);

      *(undefined1 *)((longlong)&local_208 + (longlong)pppuVar16) = 0;

    }

    else {

      uVar6 = (ulonglong)pppuVar16 | 0xf;

      if (uVar6 < 0x8000000000000000) {

        if (uVar6 < 0x16) {

          uVar6 = 0x16;

        }

      }

      else {

        uVar6 = 0x7fffffffffffffff;

      }

      ppppuVar5 = (undefined8 ****)FUN_1400285e0(uVar6 + 1);

      local_208 = ppppuVar5;

      uStack_1f0 = uVar6;

      FUN_1402f8e20(ppppuVar5,ppppuVar13);

      *(undefined1 *)((longlong)ppppuVar5 + (longlong)pppuVar16) = 0;

    }

    local_180 = local_208;

    uStack_178 = ppuStack_200;

    local_170 = local_1f8;

    uStack_168 = uStack_1f0;

    pppuVar16 = (undefined8 ***)local_1f8;

    uVar6 = uStack_1f0;

  }

  ppppuVar13 = (undefined8 ****)local_180;

  local_208 = (undefined8 ***)0x0;

  ppuStack_200 = (undefined8 ***)0x0;

  local_1f8 = (undefined8 **)0x0;

  uStack_1f0 = 0;

  ppppuVar5 = &local_180;

  if (0xf < uVar6) {

    ppppuVar5 = (undefined8 ****)local_180;

  }

  if ((undefined8 ***)0x7fffffffffffffff < pppuVar16) {

                    /* WARNING: Subroutine does not return */

    FUN_140024130();

  }

  if (pppuVar16 < (undefined8 ***)0x10) {

    uStack_1f0 = 0xf;

    local_208 = *ppppuVar5;

    ppuStack_200 = ppppuVar5[1];

    local_1f8 = pppuVar16;

  }

  else {

    uVar20 = (ulonglong)pppuVar16 | 0xf;

    if (uVar20 < 0x8000000000000000) {

      if (uVar20 < 0x16) {

        uVar20 = 0x16;

      }

    }

    else {

      uVar20 = 0x7fffffffffffffff;

    }

    local_208 = (undefined8 ***)FUN_1400285e0(uVar20 + 1);

    local_1f8 = pppuVar16;

    uStack_1f0 = uVar20;

    FUN_1402f8e20(local_208,ppppuVar5);

  }

  plVar1 = DAT_1403ead08;

  local_1a8 = &local_208;

  plVar9 = (longlong *)DAT_1403ead08[1];

  cVar2 = *(char *)((longlong)plVar9 + 0x19);

  plVar17 = DAT_1403ead08;

  while (cVar2 == '\0') {

    cVar2 = FUN_140046de0(plVar9 + 4,&local_208);

    plVar12 = plVar9 + 2;

    if (cVar2 == '\0') {

      plVar12 = plVar9;

      plVar17 = plVar9;

    }

    plVar9 = (longlong *)*plVar12;

    cVar2 = *(char *)((longlong)plVar9 + 0x19);

  }

  if ((*(char *)((longlong)plVar17 + 0x19) != '\0') ||

     (cVar2 = FUN_140046de0(&local_208,plVar17 + 4), cVar2 != '\0')) {

    plVar17 = plVar1;

  }

  if (plVar17 == plVar1) {

    uVar20 = (DAT_1403eace0 - DAT_1403eacd8) / 0x38;

    iVar3 = (int)uVar20;

    local_140 = uVar20;

    FUN_140075320(&DAT_1403eacd8,(longlong)(iVar3 + 1));

    *(undefined8 *)((longlong)iVar3 * 0x38 + DAT_1403eacd8) = 0;

    *(undefined4 *)((longlong)iVar3 * 0x38 + 8 + DAT_1403eacd8) = 0xffffffff;

    FUN_1400279c0(&local_1d8,&local_208);

    local_1b8 = iVar3;

    FUN_140074f80(&DAT_1403ead08,local_108);

    FUN_140027900(&local_1d8);

  }

  else {

    uVar20 = (ulonglong)*(uint *)(plVar17 + 8);

    local_140 = uVar20;

  }

  FUN_140027900();

  lVar10 = DAT_1403eacd8;

  lVar14 = (longlong)(int)uVar20 * 0x38;

  if (*(int *)(lVar14 + 8 + DAT_1403eacd8) == -1) {

    if (*(longlong *)(lVar14 + DAT_1403eacd8) != 0) goto LAB_140070409;

    uVar7 = FUN_1400c4e00();

    FUN_1400748b0(&local_1a0,uVar7);

    lVar8 = SDL_LoadPNG();

    if (lVar8 == 0) {

LAB_1400704b3:

      if (0xf < uStack_188) {

        if ((0xfff < uStack_188 + 1) &&

           (0x1f < (CONCAT71(uStack_19f,local_1a0) -

                   *(longlong *)(CONCAT71(uStack_19f,local_1a0) + -8)) - 8U)) {

LAB_140070d44:

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      local_190 = _DAT_14039caa0;

      uStack_188 = _UNK_14039caa8;

      local_1a0 = 0;

      goto LAB_140070409;

    }

    uVar7 = FUN_1400c43c0();

    lVar8 = SDL_CreateTextureFromSurface(uVar7,lVar8);

    local_1b0 = lVar8;

    SDL_DestroySurface();

    if (lVar8 == 0) goto LAB_1400704b3;

    if (param_2 == '\0') {

      SDL_SetTextureScaleMode(lVar8,0);

    }

    *(longlong *)(lVar14 + lVar10) = lVar8;

    *(float *)(lVar14 + 0xc + lVar10) = (float)*(int *)(lVar8 + 4);

    *(float *)(lVar14 + 0x10 + lVar10) = (float)*(int *)(lVar8 + 8);

    *(undefined8 *)(lVar14 + 0x14 + lVar10) = 0;

    *(float *)(lVar14 + 0x1c + lVar10) = param_3;

    *(float *)(lVar14 + 0x20 + lVar10) = param_4;

    *(undefined4 *)(lVar14 + 0x24 + lVar10) = 0;

    *(undefined8 *)(lVar14 + 0x28 + lVar10) = 0x3f800000;

    *(undefined4 *)(lVar14 + 0x30 + lVar10) = 0x3f800000;

    *(undefined4 *)(lVar14 + 8 + lVar10) = 0xffffffff;

    uVar7 = FUN_1400c4e00();

    uVar7 = FUN_1400748b0(&local_160,uVar7,&local_180);

    plVar9 = (longlong *)FUN_140027810(uVar7,&DAT_14030a28c);

    local_130 = (undefined8 ***)*plVar9;

    lStack_128 = plVar9[1];

    local_120 = *(undefined1 (*) [16])(plVar9 + 2);

    plVar9[2] = 0;

    plVar9[3] = 0xf;

    *(undefined1 *)plVar9 = 0;

    if (0xf < (ulonglong)local_150._8_8_) {

      if ((0xfff < local_150._8_8_ + 1) &&

         (0x1f < (ulonglong)((longlong)local_160 + (-8 - (longlong)local_160[-1])))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    local_150._8_8_ = _UNK_14039caa8;

    local_150._0_8_ = _DAT_14039caa0;

    local_160 = (undefined8 ***)((ulonglong)local_160 & 0xffffffffffffff00);

    FUN_140025e00(local_e8);

    ppppuVar13 = &local_130;

    if (0xf < (ulonglong)local_120._8_8_) {

      ppppuVar13 = (undefined8 ****)local_130;

    }

    FUN_140025f00(local_e8,ppppuVar13);

    lVar10 = FUN_140025320(local_e8);

    if (lVar10 != 0) {

      lVar10 = FUN_140025320(lVar10);

      local_224 = 0;

      local_228 = 0;

      local_220 = 0;

      local_21c = 0;

      local_214 = 0;

      local_210 = 0;

      local_1e0[0] = 0;

      local_20c = 0;

      fVar22 = 0.0;

      fVar23 = 0.0;

      local_138 = lVar10;

      while (lVar10 != 0) {

        uVar6 = 0;

        ppuStack_158 = (undefined8 ***)0x0;

        uVar20 = 0xf;

        local_150 = ZEXT816(0xf) << 0x40;

        local_160 = (undefined8 ****)0x0;

        _Str = (char *)FUN_1400256d0(lVar10,&DAT_140305358);

        if (_Str != (char *)0x0) {

          local_1d8 = (undefined8 ****)0x0;

          ppuStack_1d0 = (undefined8 ***)0x0;

          local_1c8 = ZEXT816(0);

          sVar11 = strlen(_Str);

          FUN_140027e30(&local_1d8,_Str,sVar11);

          local_160 = local_1d8;

          ppuStack_158 = ppuStack_1d0;

          local_150 = local_1c8;

          uVar20 = local_1c8._8_8_;

          uVar6 = local_1c8._0_8_;

        }

        local_1e4 = 0;

        local_1e8 = 0;

        FUN_140025730(lVar10,&DAT_14030a294,&local_1e4);

        FUN_140025730(lVar10,&DAT_14030a298,&local_1e8);

        if ((local_1e4 == 0) && (local_1e8 == 0)) {

          local_224 = 0;

          local_228 = 0;

          local_220 = 0;

          local_21c = 0;

          local_214 = 0;

          local_210 = 0;

          local_1e0[0] = 0;

          local_20c = 0;

          fVar22 = 0.0;

          fVar23 = 0.0;

          FUN_140025730(lVar10,&DAT_14030a29c,&local_224);

          FUN_140025730(lVar10,&DAT_14030a2a0,&local_228);

          FUN_140025730(lVar10,&DAT_14039bee0,&local_220);

          FUN_140025730(lVar10,&DAT_14030a2a4,&local_21c);

          FUN_140025730(lVar10,&DAT_14030a2a8,&local_214);

          FUN_140025730(lVar10,&DAT_14030a2ac,&local_210);

          FUN_140025730(lVar10,&DAT_14030a2b0,local_1e0);

          FUN_140025730(lVar10,&DAT_14030a2b4,&local_20c);

          iVar3 = FUN_140025830(lVar10,&DAT_14030a2b8,&local_110);

          if (iVar3 == 0) {

            fVar22 = (float)local_110;

          }

          iVar3 = FUN_140025830(lVar10,&DAT_14030a2bc,local_108);

          if (iVar3 == 0) {

            fVar23 = (float)local_108[0];

          }

        }

        else {

          local_224 = local_224 + local_1e4;

          local_228 = local_228 + local_1e8;

        }

        local_218 = 1;

        FUN_140025730(lVar10,&DAT_14030a2c0);

        ppppuVar13 = (undefined8 ****)local_160;

        plVar1 = DAT_1403ead08;

        plVar9 = (longlong *)DAT_1403ead08[1];

        cVar2 = *(char *)((longlong)plVar9 + 0x19);

        local_1a8 = local_160;

        plVar17 = DAT_1403ead08;

        while (cVar2 == '\0') {

          plVar12 = plVar9 + 4;

          ppppuVar5 = &local_160;

          if (0xf < uVar20) {

            ppppuVar5 = ppppuVar13;

          }

          if (0xf < (ulonglong)plVar9[7]) {

            plVar12 = (longlong *)*plVar12;

          }

          uVar15 = plVar9[6];

          uVar18 = uVar15;

          if (uVar6 < uVar15) {

            uVar18 = uVar6;

          }

          uVar4 = memcmp(plVar12,ppppuVar5,uVar18);

          if (uVar4 == 0) {

            if (uVar15 < uVar6) {

              uVar4 = 0xffffffff;

            }

            else {

              uVar4 = (uint)(uVar6 < uVar15);

            }

          }

          plVar12 = plVar9 + 2;

          if (-1 < (int)uVar4) {

            plVar12 = plVar9;

            plVar17 = plVar9;

          }

          plVar9 = (longlong *)*plVar12;

          cVar2 = *(char *)((longlong)plVar9 + 0x19);

        }

        if (*(char *)((longlong)plVar17 + 0x19) == '\0') {

          plVar9 = plVar17 + 4;

          if (0xf < (ulonglong)plVar17[7]) {

            plVar9 = (longlong *)*plVar9;

          }

          ppppuVar5 = &local_160;

          if (0xf < uVar20) {

            ppppuVar5 = ppppuVar13;

          }

          uVar15 = plVar17[6];

          uVar18 = uVar6;

          if (uVar15 < uVar6) {

            uVar18 = uVar15;

          }

          uVar4 = memcmp(ppppuVar5,plVar9,uVar18);

          if (uVar4 == 0) {

            if (uVar6 < uVar15) {

              uVar4 = 0xffffffff;

            }

            else {

              uVar4 = (uint)(uVar15 < uVar6);

            }

          }

          if ((int)uVar4 < 0) goto LAB_140070984;

        }

        else {

LAB_140070984:

          plVar17 = plVar1;

        }

        if (plVar17 == plVar1) {

          iVar3 = (int)((DAT_1403eace0 - DAT_1403eacd8) / 0x38);

          FUN_140075320(&DAT_1403eacd8,(longlong)(local_218 + iVar3));

          local_1d8 = (undefined8 ***)0x0;

          ppuStack_1d0 = (undefined8 ***)0x0;

          local_1c8 = ZEXT816(0);

          ppppuVar5 = &local_160;

          if (0xf < uVar20) {

            ppppuVar5 = ppppuVar13;

          }

          if (0x7fffffffffffffff < uVar6) {

                    /* WARNING: Subroutine does not return */

            FUN_140024130();

          }

          if (uVar6 < 0x10) {

            local_1c8._8_8_ = 0xf;

            local_1c8._0_8_ = uVar6;

            local_1d8 = *ppppuVar5;

            ppuStack_1d0 = ppppuVar5[1];

          }

          else {

            uVar15 = uVar6 | 0xf;

            if (uVar15 < 0x8000000000000000) {

              if (uVar15 < 0x16) {

                uVar15 = 0x16;

              }

            }

            else {

              uVar15 = 0x7fffffffffffffff;

            }

            local_1d8 = (undefined8 ***)FUN_1400285e0(uVar15 + 1);

            local_1c8._8_8_ = uVar15;

            local_1c8._0_8_ = uVar6;

            FUN_1402f8e20(local_1d8,ppppuVar5,uVar6 + 1);

          }

          local_1b8 = iVar3;

          FUN_140074f80(&DAT_1403ead08,local_f8);

          if (0xf < (ulonglong)local_1c8._8_8_) {

            if ((0xfff < local_1c8._8_8_ + 1) &&

               (0x1f < (ulonglong)((longlong)local_1d8 + (-8 - (longlong)local_1d8[-1])))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

        }

        else {

          iVar3 = (int)plVar17[8];

        }

        iVar19 = 0;

        if (0 < local_218) {

          lVar10 = (longlong)iVar3 * 0x38;

          do {

            lVar14 = DAT_1403eacd8;

            *(longlong *)(lVar10 + DAT_1403eacd8) = local_1b0;

            *(int *)(lVar10 + 8 + lVar14) = (int)local_140;

            *(float *)(lVar10 + 0xc + lVar14) = (float)local_220;

            *(float *)(lVar10 + 0x10 + lVar14) = (float)local_21c;

            fVar21 = (float)iVar19 * (float)local_220 + (float)local_224;

            *(float *)(lVar10 + 0x14 + lVar14) = fVar21;

            *(float *)(lVar10 + 0x18 + lVar14) = (float)local_228;

            *(float *)(lVar10 + 0x1c + lVar14) = fVar22 - (float)local_214;

            *(float *)(lVar10 + 0x20 + lVar14) = fVar23 - (float)local_210;

            *(float *)(lVar10 + 0x24 + lVar14) = fVar21 / (float)*(int *)(local_1b0 + 4);

            *(float *)(lVar10 + 0x28 + lVar14) =

                 ((float)local_220 + fVar21) / (float)*(int *)(local_1b0 + 4);

            *(float *)(lVar10 + 0x2c + lVar14) = (float)local_228 / (float)*(int *)(local_1b0 + 8);

            *(float *)(lVar10 + 0x30 + lVar14) =

                 (float)(local_228 + local_21c) / (float)*(int *)(local_1b0 + 8);

            iVar19 = iVar19 + 1;

            lVar10 = lVar10 + 0x38;

            ppppuVar13 = (undefined8 ****)local_1a8;

          } while (iVar19 < local_218);

        }

        lVar10 = FUN_140025450();

        local_138 = lVar10;

        if (0xf < uVar20) {

          ppppuVar5 = ppppuVar13;

          if ((0xfff < uVar20 + 1) &&

             (ppppuVar5 = (undefined8 ****)ppppuVar13[-1],

             0x1f < (ulonglong)((longlong)ppppuVar13 + (-8 - (longlong)ppppuVar5)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088(ppppuVar5);

        }

      }

    }

    local_e8[0] = TiXmlDocument::vftable;

    FUN_140027900(local_78);

    FUN_140024a60(local_e8);

    if (0xf < (ulonglong)local_120._8_8_) {

      if ((0xfff < local_120._8_8_ + 1) &&

         (0x1f < (ulonglong)((longlong)local_130 + (-8 - (longlong)local_130[-1])))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    local_120._8_8_ = _UNK_14039caa8;

    local_120._0_8_ = _DAT_14039caa0;

    local_130 = (undefined8 ***)((ulonglong)local_130 & 0xffffffffffffff00);

    if (0xf < uStack_188) {

      if ((0xfff < uStack_188 + 1) &&

         (0x1f < (CONCAT71(uStack_19f,local_1a0) -

                 *(longlong *)(CONCAT71(uStack_19f,local_1a0) + -8)) - 8U)) goto LAB_140070d44;

      FUN_1402c7088();

    }

    local_1a0 = 0;

    local_190 = _DAT_14039caa0;

    uStack_188 = _UNK_14039caa8;

    if (uStack_168 < 0x10) goto LAB_140070441;

    ppppuVar13 = (undefined8 ****)local_180;

    if (0xfff < uStack_168 + 1) {

      uVar6 = (longlong)local_180 + (-8 - (longlong)local_180[-1]);

      ppppuVar13 = (undefined8 ****)local_180[-1];

      goto joined_r0x000140070d3d;

    }

  }

  else {

    *(float *)(lVar14 + 0x1c + DAT_1403eacd8) = param_3 + *(float *)(lVar14 + 0x1c + DAT_1403eacd8);

    *(float *)(lVar14 + 0x20 + lVar10) = param_4 + *(float *)(lVar14 + 0x20 + lVar10);

LAB_140070409:

    if (uVar6 < 0x10) goto LAB_140070441;

    if (0xfff < uVar6 + 1) {

      uVar6 = (longlong)ppppuVar13 + (-8 - (longlong)ppppuVar13[-1]);

      ppppuVar13 = (undefined8 ****)ppppuVar13[-1];

joined_r0x000140070d3d:

      if (0x1f < uVar6) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

  }

  FUN_1402c7088(ppppuVar13);

LAB_140070441:

  FUN_140027900(param_1);

  return;

}




