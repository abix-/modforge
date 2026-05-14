// Address: 0x14003a940
// Ghidra name: FUN_14003a940
// ============ 0x14003a940 FUN_14003a940 (size=7894) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14003a940(longlong param_1)



{

  undefined8 uVar1;

  double dVar2;

  undefined1 uVar3;

  int iVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  longlong lVar11;

  undefined8 *puVar12;

  ulonglong uVar13;

  longlong lVar14;

  uint uVar15;

  double dVar16;

  float fVar17;

  float fVar18;

  undefined1 auVar19 [16];

  float fVar20;

  float fVar21;

  float fVar22;

  double dVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  float fVar27;

  undefined8 local_res8;

  undefined8 local_res10;

  float local_res18;

  float fStackX_1c;

  undefined8 local_res20;

  ulonglong in_stack_fffffffffffffe98;

  undefined4 uVar29;

  ulonglong uVar28;

  float local_138;

  float local_134;

  undefined8 local_130;

  undefined8 uStack_128;

  undefined8 local_120;

  undefined8 local_118;

  undefined8 local_110;

  ulonglong uStack_108;

  undefined8 local_100;

  ulonglong uStack_f8;

  

  fVar27 = DAT_14039ca44;

  fVar17 = DAT_140303fd0;

  fVar20 = DAT_140303fbc;

  uVar29 = (undefined4)(in_stack_fffffffffffffe98 >> 0x20);

  iVar4 = *(int *)(param_1 + 0x25c);

  uVar15 = 0;

  uVar13 = (ulonglong)_tls_index;

  if (iVar4 - 2U < 6) {

    if (iVar4 == 2) {

      FUN_140070f90(DAT_1403d43b8);

    }

    else if (2 < iVar4) {

      if (*(int *)(param_1 + 0x254) == 5) {

        FUN_140070f90(DAT_1403d43b8);

      }

      else {

        FUN_140070f90(DAT_1403d441c);

        FUN_140071000();

      }

      lVar14 = *(longlong *)((longlong)ThreadLocalStoragePointer + uVar13 * 8);

      if ((*(int *)(lVar14 + 4) < DAT_1403ea19c) &&

         (FUN_1402c7138(&DAT_1403ea19c), DAT_1403ea19c == -1)) {

        local_120 = 9;

        local_118 = 0xf;

        local_130._0_1_ = s_Spotlight_140304a48[0];

        local_130._1_1_ = s_Spotlight_140304a48[1];

        local_130._2_1_ = s_Spotlight_140304a48[2];

        local_130._3_1_ = s_Spotlight_140304a48[3];

        local_130._4_1_ = s_Spotlight_140304a48[4];

        local_130._5_1_ = s_Spotlight_140304a48[5];

        local_130._6_1_ = s_Spotlight_140304a48[6];

        local_130._7_1_ = s_Spotlight_140304a48[7];

        uStack_128 = (ulonglong)(byte)s_Spotlight_140304a48[8];

        DAT_1403ea198 = FUN_14006fe60(&local_130);

        _Init_thread_footer(&DAT_1403ea19c);

      }

      FUN_140071d20(DAT_1403ea198);

      FUN_140071ed0(DAT_1403ea198);

      FUN_140072750(0x40);

      FUN_140071d20(DAT_1403ea198 + 1);

      in_stack_fffffffffffffe98 = CONCAT44(uVar29,fVar27);

      FUN_140071ed0(DAT_1403ea198 + 1);

      FUN_1400727d0();

      uVar29 = (undefined4)(in_stack_fffffffffffffe98 >> 0x20);

      if (*(int *)(param_1 + 0x254) != 5) {

        if ((*(int *)(lVar14 + 4) < DAT_1403ea1a4) &&

           (FUN_1402c7138(&DAT_1403ea1a4), DAT_1403ea1a4 == -1)) {

          local_100 = 8;

          uStack_f8 = 0xf;

          local_110 = 0x65636e6569647541;

          uStack_108 = 0;

          DAT_1403ea1a0 = FUN_14006fe60(&local_110);

          _Init_thread_footer(&DAT_1403ea1a4);

        }

        iVar4 = 0;

        if (*(int *)(param_1 + 0x25c) == 6) {

          uVar9 = *(int *)(param_1 + 0x250) / 10 & 0x80000001;

          if ((int)uVar9 < 0) {

            uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;

          }

          iVar4 = uVar9 + 1;

        }

        FUN_140071d20(DAT_1403ea1a0 + iVar4);

        in_stack_fffffffffffffe98 = CONCAT44(uVar29,fVar27);

        FUN_140071ed0(DAT_1403ea1a0 + iVar4);

        if (iVar4 == 0) {

          pfVar5 = (float *)FUN_1400b4a10(*(undefined8 *)(param_1 + 0x260),&local_res8);

          dVar2 = DAT_140304ba0;

          local_res10 = (char *)CONCAT44(local_res10._4_4_,*pfVar5 * fVar17);

          local_res18 = pfVar5[1] * fVar17 - *(float *)(param_1 + 0x110) * fVar17;

          fVar17 = *pfVar5 * fVar17;

          uVar9 = uVar15;

          do {

            dVar23 = (double)(int)uVar9;

            fVar20 = (float)(dVar23 * _DAT_140304bb0 + _DAT_140304bc8);

            local_res8 = CONCAT44(local_res8._4_4_,fVar20);

            fVar20 = local_res18 - fVar20;

            uVar10 = uVar15;

            do {

              uVar29 = (undefined4)(in_stack_fffffffffffffe98 >> 0x20);

              if (uVar10 < 0x11) {

                dVar16 = (double)(int)uVar10 * dVar2 + _DAT_140304ba8 + dVar23 + dVar23;

              }

              else {

                dVar16 = ((double)(int)(uVar10 - 0x11) * dVar2 + _DAT_140304bd0) - (dVar23 + dVar23)

                ;

              }

              if ((fVar17 - (float)dVar16) * (fVar17 - (float)dVar16) + fVar20 * fVar20 < 0.0) {

                FUN_1402cdfa0();

              }

              FUN_140071000();

              in_stack_fffffffffffffe98 = CONCAT44(uVar29,DAT_1403d43e8);

              FUN_140071000();

              uVar10 = uVar10 + 1;

              fVar17 = (float)local_res10;

            } while ((int)uVar10 < 0x22);

            uVar9 = uVar9 + 1;

            fVar20 = DAT_140303fbc;

          } while ((int)uVar9 < 3);

        }

        if ((*(char *)(param_1 + 0x2250) != '\0') && (*(int *)(param_1 + 0x25c) == 7)) {

          uVar9 = (*(int *)(param_1 + 0x250) + -0xf) / 0x1e & 0x80000001;

          if ((int)uVar9 < 0) {

            uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;

          }

          FUN_140071d20(DAT_1403ea1a0 + 3 + uVar9);

          if ((*(int *)(param_1 + 0x250) + -0xf) % 0x3c == 0x1e) {

            local_100 = _DAT_140304090;

            uStack_f8 = _UNK_140304098;

            local_110 = 0x70616c43656e6f4c;

            uStack_108 = 0;

            in_stack_fffffffffffffe98 = in_stack_fffffffffffffe98 & 0xffffffffffffff00;

            FUN_140040ca0(&local_110,100,0);

            FUN_140027900(&local_110);

          }

        }

        if ((*(int *)(lVar14 + 4) < DAT_1403ea1ac) &&

           (FUN_1402c7138(&DAT_1403ea1ac), DAT_1403ea1ac == -1)) {

          local_100 = 8;

          uStack_f8 = 0xf;

          local_110 = 0x657375616c707041;

          uStack_108 = 0;

          DAT_1403ea1a8 = FUN_14006fe60(&local_110);

          _Init_thread_footer(&DAT_1403ea1ac);

        }

        uVar9 = uVar15;

        if (*(int *)(param_1 + 0x25c) == 6) {

          uVar9 = *(int *)(param_1 + 0x250) / 0x1e & 0x80000001;

          if ((int)uVar9 < 0) {

            uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;

          }

          uVar9 = uVar9 + 1;

        }

        FUN_140071d20(DAT_1403ea1a8 + uVar9);

        if ((*(int *)(param_1 + 0x254) == 2) && (*(int *)(param_1 + 0x25c) < 6)) {

          if ((*(int *)(lVar14 + 4) < DAT_1403ea1b4) &&

             (FUN_1402c7138(&DAT_1403ea1b4), DAT_1403ea1b4 == -1)) {

            local_120 = 0xb;

            local_118 = 0xf;

            local_130._0_1_ = s_BounceLight_140304a58[0];

            local_130._1_1_ = s_BounceLight_140304a58[1];

            local_130._2_1_ = s_BounceLight_140304a58[2];

            local_130._3_1_ = s_BounceLight_140304a58[3];

            local_130._4_1_ = s_BounceLight_140304a58[4];

            local_130._5_1_ = s_BounceLight_140304a58[5];

            local_130._6_1_ = s_BounceLight_140304a58[6];

            local_130._7_1_ = s_BounceLight_140304a58[7];

            uStack_128 = (ulonglong)

                         CONCAT12(s_BounceLight_140304a58[10],s_BounceLight_140304a58._8_2_);

            _DAT_1403ea1b0 = FUN_14006fe60(&local_130);

            _Init_thread_footer(&DAT_1403ea1b4);

          }

          iVar4 = *(int *)(param_1 + 0x2238);

          iVar6 = 0x85;

          do {

            FUN_140071d20((uint)((int)uVar15 < (iVar4 + 1) / 2) + _DAT_1403ea1b0);

            uVar15 = uVar15 + 1;

            iVar6 = iVar6 + 0xd;

          } while (iVar6 < 0xb9);

          uVar13 = (ulonglong)_tls_index;

        }

      }

      if (*(int *)(param_1 + 0x254) == 5) {

        if ((*(int *)(lVar14 + 4) < DAT_1403ea1bc) &&

           (FUN_1402c7138(&DAT_1403ea1bc), DAT_1403ea1bc == -1)) {

          local_120 = 9;

          local_118 = 0xf;

          local_130._0_1_ = s_FreakGlow_140304a68[0];

          local_130._1_1_ = s_FreakGlow_140304a68[1];

          local_130._2_1_ = s_FreakGlow_140304a68[2];

          local_130._3_1_ = s_FreakGlow_140304a68[3];

          local_130._4_1_ = s_FreakGlow_140304a68[4];

          local_130._5_1_ = s_FreakGlow_140304a68[5];

          local_130._6_1_ = s_FreakGlow_140304a68[6];

          local_130._7_1_ = s_FreakGlow_140304a68[7];

          uStack_128 = (ulonglong)(byte)s_FreakGlow_140304a68[8];

          DAT_1403ea1b8 = FUN_14006fe60(&local_130);

          _Init_thread_footer(&DAT_1403ea1bc);

        }

        FUN_140071d20(DAT_1403ea1b8);

      }

    }

  }

  else {

    FUN_140070f90(DAT_1403d443c);

  }

  if (((*(int *)(param_1 + 0x25c) < 2) || (7 < *(int *)(param_1 + 0x25c))) &&

     (*(int *)(param_1 + 0x225c) == -1)) {

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar13 * 8) + 4) <

         DAT_1403ea1c4) && (FUN_1402c7138(&DAT_1403ea1c4), DAT_1403ea1c4 == -1)) {

      local_120 = 10;

      local_118 = 0xf;

      local_130._0_1_ = s_CircusSign_140304a78[0];

      local_130._1_1_ = s_CircusSign_140304a78[1];

      local_130._2_1_ = s_CircusSign_140304a78[2];

      local_130._3_1_ = s_CircusSign_140304a78[3];

      local_130._4_1_ = s_CircusSign_140304a78[4];

      local_130._5_1_ = s_CircusSign_140304a78[5];

      local_130._6_1_ = s_CircusSign_140304a78[6];

      local_130._7_1_ = s_CircusSign_140304a78[7];

      uStack_128 = (ulonglong)(ushort)s_CircusSign_140304a78._8_2_;

      DAT_1403ea1c0 = FUN_14006fe60(&local_130);

      _Init_thread_footer(&DAT_1403ea1c4);

    }

    FUN_140071d20(DAT_1403ea1c0);

    iVar4 = *(int *)(param_1 + 0x250) / 5;

    iVar8 = iVar4 / 6 + (iVar4 >> 0x1f) +

            (int)(((longlong)iVar4 / 6 + ((longlong)iVar4 >> 0x3f) & 0xffffffffU) >> 0x1f);

    iVar6 = iVar4 + iVar8 * -6 + -3;

    iVar4 = -iVar6;

    if (iVar4 < 0) {

      iVar4 = iVar6;

    }

    FUN_140071d20(DAT_1403ea1c0 + 1,iVar8,(float)(iVar4 * 6) + fVar20);

    iVar4 = *(int *)(param_1 + 0x250) / 5 + 3;

    iVar6 = iVar4 / 6 + (iVar4 >> 0x1f) +

            (int)(((longlong)iVar4 / 6 + ((longlong)iVar4 >> 0x3f) & 0xffffffffU) >> 0x1f);

    iVar8 = iVar4 + iVar6 * -6 + -3;

    iVar4 = -iVar8;

    if (iVar4 < 0) {

      iVar4 = iVar8;

    }

    FUN_140071d20(DAT_1403ea1c0 + 1,iVar6,(float)(iVar4 * 6) + fVar20);

  }

  fVar20 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar20 * *(float *)(param_1 + 0x110),fVar20 * *(float *)(param_1 + 0x10c)))

  ;

  fVar20 = DAT_140303354;

  if (*(int *)(param_1 + 0x25c) - 3U < 5) {

    if ((*(longlong *)(param_1 + 0x298) != 0) && (*(int *)(param_1 + 0x254) != 5)) {

      FUN_140084670(*(undefined8 *)(param_1 + 0x2c8),DAT_1403d4418);

    }

    iVar4 = *(int *)(param_1 + 0x254);

    if (iVar4 == 0) {

      if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar13 * 8) + 4) <

           DAT_1403ea1cc) && (FUN_1402c7138(&DAT_1403ea1cc), DAT_1403ea1cc == -1)) {

        local_100 = 8;

        uStack_f8 = 0xf;

        local_110 = 0x74616c5065766944;

        uStack_108 = 0;

        DAT_1403ea1c8 = FUN_14006fe60(&local_110);

        _Init_thread_footer(&DAT_1403ea1cc);

      }

      uVar28 = in_stack_fffffffffffffe98 & 0xffffffff00000000;

      FUN_140071ed0(DAT_1403ea1c8);

      in_stack_fffffffffffffe98 = uVar28 & 0xffffffff00000000;

      FUN_140071ed0(DAT_1403ea1c8 + 1);

      if (*(longlong *)(param_1 + 0x2a0) != 0) {

        for (lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x2a0) + 0x70); lVar14 != 0;

            lVar14 = *(longlong *)(lVar14 + 8)) {

          if (lVar14 != *(longlong *)(param_1 + 0x2d8)) {

            FUN_140084670(lVar14,DAT_1403d444c);

          }

        }

      }

      lVar14 = *(longlong *)(param_1 + 0x2b8);

      for (lVar11 = *(longlong *)(param_1 + 0x2b0); lVar11 != lVar14; lVar11 = lVar11 + 8) {

        in_stack_fffffffffffffe98 = CONCAT44((int)(in_stack_fffffffffffffe98 >> 0x20),8);

        FUN_140071150();

      }

    }

    else if (iVar4 == 1) {

      FUN_140084670(*(undefined8 *)(param_1 + 0x2d0),DAT_1403d43cc);

      FUN_140084670(*(undefined8 *)(param_1 + 0x2d8),DAT_1403d43cc);

      FUN_140072640(DAT_1403d4404);

      if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar13 * 8) + 4) <

           DAT_1403ea1d4) && (FUN_1402c7138(&DAT_1403ea1d4), DAT_1403ea1d4 == -1)) {

        local_120 = 9;

        local_118 = 0xf;

        local_130._0_1_ = s_WhiteStar_140304a88[0];

        local_130._1_1_ = s_WhiteStar_140304a88[1];

        local_130._2_1_ = s_WhiteStar_140304a88[2];

        local_130._3_1_ = s_WhiteStar_140304a88[3];

        local_130._4_1_ = s_WhiteStar_140304a88[4];

        local_130._5_1_ = s_WhiteStar_140304a88[5];

        local_130._6_1_ = s_WhiteStar_140304a88[6];

        local_130._7_1_ = s_WhiteStar_140304a88[7];

        uStack_128 = (ulonglong)(byte)s_WhiteStar_140304a88[8];

        DAT_1403ea1d0 = FUN_14006fe60(&local_130);

        _Init_thread_footer(&DAT_1403ea1d4);

      }

      iVar4 = 0xe7;

      do {

        in_stack_fffffffffffffe98 = in_stack_fffffffffffffe98 & 0xffffffff00000000;

        FUN_140071ed0(DAT_1403ea1d0,(float)iVar4 * fVar20);

        iVar4 = iVar4 + 0x20;

      } while (iVar4 < 0x147);

    }

    else if (iVar4 == 2) {

      puVar12 = (undefined8 *)(param_1 + 0x2d0);

      lVar14 = 4;

      do {

        FUN_140084670(*puVar12,DAT_1403d43cc);

        puVar12 = puVar12 + 1;

        lVar14 = lVar14 + -1;

      } while (lVar14 != 0);

      if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar13 * 8) + 4) <

           DAT_1403ea1dc) && (FUN_1402c7138(&DAT_1403ea1dc), DAT_1403ea1dc == -1)) {

        uStack_128 = 0;

        local_120 = 7;

        local_118 = 0xf;

        local_130._0_6_ = CONCAT24(s_Netting_140304a98._4_2_,s_Netting_140304a98._0_4_);

        local_130._0_7_ = CONCAT16(s_Netting_140304a98[6],(undefined6)local_130);

        local_130 = (ulonglong)(uint7)local_130;

        DAT_1403ea1d8 = FUN_14006fe60(&local_130);

        _Init_thread_footer(&DAT_1403ea1dc);

      }

      in_stack_fffffffffffffe98 = in_stack_fffffffffffffe98 & 0xffffffff00000000;

      FUN_140071ed0(DAT_1403ea1d8);

    }

    else if (iVar4 == 3) {

      lVar14 = *(longlong *)((longlong)ThreadLocalStoragePointer + uVar13 * 8);

      if ((*(int *)(lVar14 + 4) < DAT_1403ea1e4) &&

         (FUN_1402c7138(&DAT_1403ea1e4), DAT_1403ea1e4 == -1)) {

        local_120 = 9;

        local_118 = 0xf;

        local_130._0_1_ = s_AcroFloor_140304aa0[0];

        local_130._1_1_ = s_AcroFloor_140304aa0[1];

        local_130._2_1_ = s_AcroFloor_140304aa0[2];

        local_130._3_1_ = s_AcroFloor_140304aa0[3];

        local_130._4_1_ = s_AcroFloor_140304aa0[4];

        local_130._5_1_ = s_AcroFloor_140304aa0[5];

        local_130._6_1_ = s_AcroFloor_140304aa0[6];

        local_130._7_1_ = s_AcroFloor_140304aa0[7];

        uStack_128 = (ulonglong)(byte)s_AcroFloor_140304aa0[8];

        DAT_1403ea1e0 = FUN_14006fe60(&local_130);

        _Init_thread_footer(&DAT_1403ea1e4);

      }

      in_stack_fffffffffffffe98 = in_stack_fffffffffffffe98 & 0xffffffff00000000;

      FUN_140071ed0(DAT_1403ea1e0);

      uVar29 = (undefined4)(in_stack_fffffffffffffe98 >> 0x20);

      if (*(longlong *)(param_1 + 0x2a0) != 0) {

        if ((*(int *)(lVar14 + 4) < DAT_1403ea1ec) &&

           (FUN_1402c7138(&DAT_1403ea1ec), DAT_1403ea1ec == -1)) {

          local_100 = 8;

          uStack_f8 = 0xf;

          local_110 = 0x706f6f486f726341;

          uStack_108 = 0;

          DAT_1403ea1e8 = FUN_14006fe60(&local_110);

          _Init_thread_footer(&DAT_1403ea1ec);

        }

        FUN_1402cd4c0();

        in_stack_fffffffffffffe98 = CONCAT44(uVar29,DAT_140304b20);

        FUN_140071f00(DAT_1403ea1e8);

      }

    }

    else if (iVar4 == 5) {

      FUN_140084670(*(undefined8 *)(param_1 + 0x2d0),DAT_1403d43d4);

    }

  }

  if (*(int *)(param_1 + 0x225c) != -1) {

    FUN_140072fe0(CONCAT44(DAT_140304c94,DAT_140304cac));

  }

  iVar4 = 1;

  if ((*(int *)(param_1 + 0x25c) < 2) || (7 < *(int *)(param_1 + 0x25c))) {

    iVar6 = -1;

    if (*(int *)(param_1 + 0x168) != -1) {

      FUN_1400b4a10(*(undefined8 *)

                     (*(longlong *)(param_1 + 0x130) + (longlong)*(int *)(param_1 + 0x168) * 8),

                    &local_res8);

      pfVar5 = *(float **)(param_1 + 0x280);

      if ((((*pfVar5 <= (float)local_res8) && ((float)local_res8 < *pfVar5 + pfVar5[2])) &&

          (pfVar5[1] <= local_res8._4_4_)) && (iVar6 = -1, local_res8._4_4_ < pfVar5[1] + pfVar5[3])

         ) {

        iVar6 = 0;

      }

      if (((pfVar5[4] <= (float)local_res8) && ((float)local_res8 < pfVar5[4] + pfVar5[6])) &&

         ((pfVar5[5] <= local_res8._4_4_ && (local_res8._4_4_ < pfVar5[5] + pfVar5[7])))) {

        iVar6 = 1;

      }

      if (((pfVar5[8] <= (float)local_res8) && ((float)local_res8 < pfVar5[8] + pfVar5[10])) &&

         ((pfVar5[9] <= local_res8._4_4_ && (local_res8._4_4_ < pfVar5[9] + pfVar5[0xb])))) {

        iVar6 = 2;

      }

      if ((((pfVar5[0xc] <= (float)local_res8) && ((float)local_res8 < pfVar5[0xc] + pfVar5[0xe]))

          && (pfVar5[0xd] <= local_res8._4_4_)) && (local_res8._4_4_ < pfVar5[0xd] + pfVar5[0xf])) {

        iVar6 = 3;

      }

      if (((pfVar5[0x14] <= (float)local_res8) && ((float)local_res8 < pfVar5[0x14] + pfVar5[0x16]))

         && ((pfVar5[0x15] <= local_res8._4_4_ && (local_res8._4_4_ < pfVar5[0x15] + pfVar5[0x17])))

         ) {

        iVar6 = 5;

      }

    }

    lVar14 = *(longlong *)((longlong)ThreadLocalStoragePointer + uVar13 * 8);

    if ((*(int *)(lVar14 + 4) < DAT_1403ea1f4) &&

       (FUN_1402c7138(&DAT_1403ea1f4), DAT_1403ea1f4 == -1)) {

      local_100 = 8;

      uStack_f8 = 0xf;

      local_110 = 0x6e65704f746e6554;

      uStack_108 = 0;

      DAT_1403ea1f0 = FUN_14006fe60(&local_110);

      _Init_thread_footer(&DAT_1403ea1f4);

    }

    iVar8 = 0;

    lVar11 = 0;

    do {

      in_stack_fffffffffffffe98 = in_stack_fffffffffffffe98 & 0xffffffff00000000;

      FUN_140071ed0(DAT_1403ea1f0 + 2 + iVar8);

      iVar8 = iVar8 + 1;

      lVar11 = lVar11 + 0x10;

    } while (lVar11 < 0x60);

    if (iVar6 != -1) {

      in_stack_fffffffffffffe98 = in_stack_fffffffffffffe98 & 0xffffffff00000000;

      FUN_140071ed0(DAT_1403ea1f0 + 1);

    }

    if (*(int *)(param_1 + 0x1b0) < 1) {

      if ((*(int *)(lVar14 + 4) < DAT_1403ea1fc) &&

         (FUN_1402c7138(&DAT_1403ea1fc), DAT_1403ea1fc == -1)) {

        local_100 = 8;

        uStack_f8 = 0xf;

        local_110 = 0x6b636f4c746e6554;

        uStack_108 = 0;

        _DAT_1403ea1f8 = FUN_14006fe60(&local_110);

        _Init_thread_footer(&DAT_1403ea1fc);

      }

      uVar15 = DAT_14030375c;

      uVar13 = _UNK_1403033f8;

      uVar1 = _DAT_1403033f0;

      fVar17 = DAT_140303394;

      fVar24 = *(float *)(*(longlong *)(param_1 + 0x280) + 0x40) + _DAT_140304b38;

      iVar8 = 0;

      local_res10 = (char *)(param_1 + 0x2258);

      iVar6 = 0xf;

      local_res8 = CONCAT44(local_res8._4_4_,0xf);

      do {

        fVar21 = *(float *)(*(longlong *)(param_1 + 0x280) + 0x44);

        auVar19 = ZEXT816(0);

        if (*local_res10 == '\0') {

LAB_14003bb16:

          auVar19 = ZEXT416(uVar15);

        }

        else if (((*(int *)(param_1 + 0x225c) == iVar8) &&

                 (iVar7 = *(int *)(param_1 + 0x250), iVar7 - 0x3cU < 0x78)) &&

                (iVar7 = iVar7 % 10, iVar7 < 5)) {

          if (iVar7 == 1) {

            local_100 = uVar1;

            uStack_f8 = uVar13;

            local_110._0_1_ = s_LockRattle_140304ab0[0];

            local_110._1_1_ = s_LockRattle_140304ab0[1];

            local_110._2_1_ = s_LockRattle_140304ab0[2];

            local_110._3_1_ = s_LockRattle_140304ab0[3];

            local_110._4_1_ = s_LockRattle_140304ab0[4];

            local_110._5_1_ = s_LockRattle_140304ab0[5];

            local_110._6_1_ = s_LockRattle_140304ab0[6];

            local_110._7_1_ = s_LockRattle_140304ab0[7];

            uStack_108 = (ulonglong)(ushort)s_LockRattle_140304ab0._8_2_;

            in_stack_fffffffffffffe98 = in_stack_fffffffffffffe98 & 0xffffffffffffff00;

            FUN_140040ca0(&local_110,100);

            if (0xf < uStack_f8) {

              if ((0xfff < uStack_f8 + 1) && (0x1f < (local_110 - *(longlong *)(local_110 - 8)) - 8)

                 ) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              FUN_1402c7088();

            }

          }

          goto LAB_14003bb16;

        }

        iVar7 = 0;

        if (*local_res10 != '\0') {

          iVar7 = iVar8 + 1;

        }

        auVar19._0_4_ = auVar19._0_4_ + fVar24;

        in_stack_fffffffffffffe98 = in_stack_fffffffffffffe98 & 0xffffffff00000000;

        FUN_140071ed0(iVar7 + _DAT_1403ea1f8,auVar19._0_8_);

        if ((*(int *)(param_1 + 0x250) == 0xb2) && (*(int *)(param_1 + 0x225c) == iVar8)) {

          local_130 = CONCAT44(DAT_1403d43fc,DAT_1403d43f4);

          uStack_128 = CONCAT44(DAT_1403d442c,DAT_1403d43f8);

          *(undefined4 *)(param_1 + 0x2234) = 0;

          fVar25 = DAT_14030338c;

          fVar22 = fVar24 * DAT_140303fd0 + DAT_14030338c;

          fVar21 = ((float)iVar6 * fVar20 + fVar21) * DAT_140303fd0;

          lVar14 = 0x14;

          do {

            FUN_1400c6d00(&local_res18);

            fVar18 = (float)FUN_1400c6940();

            local_res20 = CONCAT44(fVar18 * fStackX_1c,fVar18 * local_res18);

            local_138 = local_res18 * fVar25 + fVar22;

            local_134 = fStackX_1c * fVar25 + fVar21 + fVar17;

            in_stack_fffffffffffffe98 = in_stack_fffffffffffffe98 & 0xffffffff00000000;

            FUN_1400c8dc0(param_1 + 0x2f0,0xffffffff,&local_138,&local_res20,

                          in_stack_fffffffffffffe98,0,(longlong)&local_130 + (longlong)iVar8 * 4,

                          0x2d,fVar27);

            lVar14 = lVar14 + -1;

          } while (lVar14 != 0);

        }

        iVar8 = iVar8 + 1;

        iVar6 = (int)(float)local_res8 + 9;

        local_res8 = CONCAT44(local_res8._4_4_,iVar6);

        local_res10 = local_res10 + 1;

      } while (iVar6 < 0x33);

    }

    else {

      FUN_140071ed0(DAT_1403ea1f0);

    }

    FUN_1400d5d90(param_1,1);

    if (*(int *)(param_1 + 0x254) != -1) {

      FUN_140071ed0(DAT_1403ea1f0 + 2 + *(int *)(param_1 + 0x254));

      FUN_140071ed0(DAT_1403ea1f0);

    }

  }

  if (*(int *)(param_1 + 0x225c) != -1) {

    FUN_1400730f0();

  }

  if (((*(int *)(param_1 + 0x25c) < 1) || (2 < *(int *)(param_1 + 0x25c))) &&

     (*(int *)(param_1 + 0x225c) == -1)) {

    FUN_1400d5ff0(param_1,1);

  }

  fVar24 = DAT_14030335c;

  fVar17 = DAT_140303358;

  if ((*(int *)(param_1 + 0x254) == 1) && (*(int *)(param_1 + 0x25c) - 3U < 5)) {

    fVar21 = *(float *)(*(longlong *)(param_1 + 0x270) + 300) + DAT_140304b2c;

    lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x270) + 0x40) + 0x30);

    local_res8 = CONCAT44(*(float *)(lVar14 + 0x14) * fVar21 +

                          *(float *)(lVar14 + 0x18) * DAT_140303358 + *(float *)(lVar14 + 0x10),

                          (*(float *)(lVar14 + 0x18) * fVar21 -

                          *(float *)(lVar14 + 0x14) * DAT_140303358) + *(float *)(lVar14 + 0xc));

    fVar21 = *(float *)(*(longlong *)(param_1 + 0x260) + 300) - fVar20;

    lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x260) + 0x40) + 0x30);

    local_res10 = (char *)CONCAT44(*(float *)(lVar14 + 0x14) * fVar21 +

                                   *(float *)(lVar14 + 0x18) * fVar20 + *(float *)(lVar14 + 0x10),

                                   (*(float *)(lVar14 + 0x18) * fVar21 -

                                   *(float *)(lVar14 + 0x14) * fVar20) + *(float *)(lVar14 + 0xc));

    FUN_140071150();

    uVar13 = (ulonglong)_tls_index;

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar13 * 8) + 4) <

         DAT_1403ea204) && (FUN_1402c7138(&DAT_1403ea204), DAT_1403ea204 == -1)) {

      local_100 = 10;

      uStack_f8 = 0xf;

      local_110._0_1_ = s_StrongHook_140304ac0[0];

      local_110._1_1_ = s_StrongHook_140304ac0[1];

      local_110._2_1_ = s_StrongHook_140304ac0[2];

      local_110._3_1_ = s_StrongHook_140304ac0[3];

      local_110._4_1_ = s_StrongHook_140304ac0[4];

      local_110._5_1_ = s_StrongHook_140304ac0[5];

      local_110._6_1_ = s_StrongHook_140304ac0[6];

      local_110._7_1_ = s_StrongHook_140304ac0[7];

      uStack_108 = (ulonglong)(ushort)s_StrongHook_140304ac0._8_2_;

      DAT_1403ea200 = FUN_14006fe60(&local_110);

      _Init_thread_footer(&DAT_1403ea204);

    }

    FUN_1402cd4c0();

    FUN_1400c5f10();

    FUN_140071f00(DAT_1403ea200);

    lVar14 = local_res8;

    fVar20 = local_res10._4_4_;

    fVar25 = local_res8._4_4_;

    fVar22 = (float)local_res10;

    fVar21 = (float)local_res8;

    fVar18 = ((float)local_res10 - (float)local_res8) * ((float)local_res10 - (float)local_res8) +

             (local_res10._4_4_ - local_res8._4_4_) * (local_res10._4_4_ - local_res8._4_4_);

    if (fVar18 < 0.0) {

      fVar18 = (float)FUN_1402cdfa0();

    }

    else {

      fVar18 = SQRT(fVar18);

    }

    fVar26 = 0.0;

    if (DAT_14039c9f0 <= fVar18) {

      fVar26 = fVar18;

    }

    fVar27 = (fVar27 - fVar26 / *(float *)(param_1 + 0x224c)) *

             *(float *)(param_1 + 0x224c) * DAT_14039ca34;

    if (DAT_140304b24 <= fVar27) {

      local_res20 = lVar14;

      local_res8 = lVar14;

      while( true ) {

        local_res18 = (fVar22 - fVar21) * (float)iVar4 * fVar17 + fVar21;

        iVar6 = -(iVar4 + -4);

        if (iVar6 < 0) {

          iVar6 = iVar4 + -4;

        }

        fVar21 = (float)(4 - iVar6) * fVar24;

        if (fVar21 < 0.0) {

          fVar21 = (float)FUN_1402cdfa0();

        }

        else {

          fVar21 = SQRT(fVar21);

        }

        fStackX_1c = fVar21 * fVar27 + (fVar20 - fVar25) * (float)iVar4 * fVar17 + fVar25;

        FUN_140071990(&local_res20,&local_res18);

        local_res20 = CONCAT44(fStackX_1c,local_res18);

        iVar4 = iVar4 + 1;

        if (8 < iVar4) break;

        fVar22 = (float)local_res10;

        fVar21 = (float)local_res8;

        fVar25 = local_res8._4_4_;

        fVar20 = local_res10._4_4_;

      }

    }

    else {

      FUN_140071990(&local_res10,&local_res8);

    }

  }

  else {

    uVar13 = (ulonglong)_tls_index;

  }

  FUN_1400730f0();

  if ((*(int *)(param_1 + 0x254) == 5) && (*(int *)(param_1 + 0x25c) - 3U < 5)) {

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar13 * 8) + 4) <

         DAT_1403ea20c) && (FUN_1402c7138(), DAT_1403ea20c == -1)) {

      uStack_128 = 0;

      local_120 = 7;

      local_118 = 0xf;

      local_130._0_6_ = CONCAT24(s_Curtain_140304ad0._4_2_,s_Curtain_140304ad0._0_4_);

      local_130._0_7_ = CONCAT16(s_Curtain_140304ad0[6],(undefined6)local_130);

      local_130 = (ulonglong)(uint7)local_130;

      DAT_1403ea208 = FUN_14006fe60(&local_130);

      _Init_thread_footer(&DAT_1403ea20c);

    }

    FUN_140071ed0(DAT_1403ea208);

    FUN_140071ed0(DAT_1403ea208);

    FUN_140071d20(DAT_1403ea208 + 1);

  }

  if (*(int *)(param_1 + 0x25c) == 6) {

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar13 * 8) + 4) <

         DAT_1403ea214) && (FUN_1402c7138(&DAT_1403ea214), DAT_1403ea214 == -1)) {

      uStack_108 = 0;

      local_100 = 6;

      uStack_f8 = 0xf;

      local_110 = (ulonglong)CONCAT24(s_Cannon_140304a1c._4_2_,s_Cannon_140304a1c._0_4_);

      DAT_1403ea210 = FUN_14006fe60(&local_110);

      _Init_thread_footer(&DAT_1403ea214);

    }

    iVar6 = *(int *)(param_1 + 0x250) + -0x1c;

    iVar4 = 0;

    if (iVar6 < 0) {

      iVar4 = iVar6;

    }

    FUN_140071d20(DAT_1403ea210,(float)DAT_1403ed994 + (float)iVar4);

    FUN_140071ed0(DAT_1403ea210,(float)DAT_1403d9e68 - (float)iVar4);

  }

  FUN_1400c9290(param_1 + 0x2f0);

  if (*(int *)(param_1 + 0x25c) == 7) {

    iVar4 = *(int *)(param_1 + 0x250) * 0x10;

    uVar3 = (undefined1)iVar4;

    if (0xa0 < iVar4) {

      uVar3 = 0xa0;

    }

    local_res8 = (ulonglong)CONCAT41((int)((ulonglong)local_res8 >> 0x20),uVar3) << 0x18;

    FUN_140071000();

  }

  iVar4 = *(int *)(param_1 + 0x25c);

  if (((iVar4 < 1) || (7 < iVar4)) && (*(int *)(param_1 + 0x225c) == -1)) {

    FUN_1400cacd0(param_1,1);

  }

  else if (iVar4 == 6) {

    FUN_1400d64e0(param_1);

  }

  return;

}




