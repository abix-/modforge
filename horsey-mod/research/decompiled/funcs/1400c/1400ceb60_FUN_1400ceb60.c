// Address: 0x1400ceb60
// Ghidra name: FUN_1400ceb60
// ============ 0x1400ceb60 FUN_1400ceb60 (size=2502) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400ceb60(longlong *param_1)



{

  float fVar1;

  undefined8 *puVar2;

  float *pfVar3;

  ulonglong *puVar4;

  bool bVar5;

  bool bVar6;

  undefined8 uVar7;

  ulonglong uVar8;

  char cVar9;

  undefined4 uVar10;

  int iVar11;

  int iVar12;

  char *_Str;

  size_t sVar13;

  undefined4 *puVar14;

  ulonglong uVar15;

  undefined8 uVar16;

  longlong lVar17;

  undefined8 *puVar18;

  int *piVar19;

  ulonglong uVar20;

  uint uVar21;

  longlong lVar22;

  undefined4 uVar23;

  float local_res8;

  float local_resc;

  ulonglong local_res10;

  ulonglong in_stack_ffffffffffffff68;

  ulonglong local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  ulonglong uStack_70;

  

  bVar5 = false;

  local_res10 = local_res10 & 0xffffffff00000000;

  *(int *)((longlong)param_1 + 0x244) = *(int *)((longlong)param_1 + 0x244) + 1;

  uVar8 = _UNK_140305688;

  uVar7 = _DAT_140305680;

  uVar15 = _UNK_1403040c8;

  uVar16 = _DAT_1403040c0;

  if (*(int *)((longlong)param_1 + 0x244) == 0x3c) {

    local_res8 = 0.0;

    lVar17 = param_1[0x26];

    if (param_1[0x27] - lVar17 >> 3 != 0) {

      lVar22 = 0;

      uVar23 = (undefined4)s_High_Achiever_140305588._0_8_;

      uVar10 = SUB84(s_High_Achiever_140305588._0_8_,4);

      uVar21 = s_High_Achiever_140305588._8_4_;

      cVar9 = s_High_Achiever_140305588[0xc];

      do {

        fVar1 = local_res8;

        if (*(int *)(*(longlong *)(lVar22 + lVar17) + 0x1c) == 4) {

          if ((*(char *)(*(longlong *)(lVar22 + lVar17) + 0x206) != '\0') &&

             (cVar9 = FUN_1400b76a0(), cVar9 == '\0')) {

            piVar19 = (int *)(*(longlong *)(lVar22 + param_1[0x26]) + 0x1fc);

            *piVar19 = *piVar19 + 1;

          }

          FUN_1400b8f90(*(undefined8 *)(lVar22 + param_1[0x26]),0);

          FUN_1400d1e10(param_1,fVar1,2);

          uVar23 = (undefined4)s_High_Achiever_140305588._0_8_;

          uVar10 = SUB84(s_High_Achiever_140305588._0_8_,4);

          uVar21 = s_High_Achiever_140305588._8_4_;

          cVar9 = s_High_Achiever_140305588[0xc];

        }

        if (*(int *)(*(longlong *)(lVar22 + param_1[0x26]) + 0x1f8) == -1) {

LAB_1400ced05:

          bVar6 = false;

        }

        else {

          local_78 = uVar16;

          uStack_70 = uVar15;

          local_88 = CONCAT44(uVar10,uVar23);

          uVar20 = (ulonglong)uVar21;

          uStack_80 = (ulonglong)CONCAT14(cVar9,uVar21);

          bVar5 = true;

          local_res10 = CONCAT44(local_res10._4_4_,1);

          if (*(longlong *)(lVar22 + param_1[0x26]) == 0) {

            _Str = "Horse";

          }

          else {

            _Str = (char *)FUN_1400c7720();

            uVar23 = (undefined4)s_High_Achiever_140305588._0_8_;

            uVar10 = SUB84(s_High_Achiever_140305588._0_8_,4);

            uVar21 = s_High_Achiever_140305588._8_4_;

            cVar9 = s_High_Achiever_140305588[0xc];

          }

          sVar13 = strlen(_Str);

          if (sVar13 != 0xd) goto LAB_1400ced05;

          lVar17 = local_88 - *(longlong *)_Str;

          if ((lVar17 == 0) && (lVar17 = uVar20 - *(uint *)((longlong)_Str + 8), lVar17 == 0)) {

            lVar17 = (uStack_80 >> 0x20 & 0xff) - (ulonglong)*(byte *)((longlong)_Str + 0xc);

          }

          if (lVar17 != 0) goto LAB_1400ced05;

          bVar6 = true;

        }

        if ((bVar5) && (bVar5 = false, 0xf < uStack_70)) {

          uVar20 = local_88;

          if ((0xfff < uStack_70 + 1) &&

             (uVar20 = *(ulonglong *)(local_88 - 8), 0x1f < (local_88 - uVar20) - 8)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088(uVar20);

          uVar23 = (undefined4)s_High_Achiever_140305588._0_8_;

          uVar10 = SUB84(s_High_Achiever_140305588._0_8_,4);

          uVar21 = s_High_Achiever_140305588._8_4_;

          cVar9 = s_High_Achiever_140305588[0xc];

        }

        if (bVar6) {

          uStack_80 = 0;

          local_78 = uVar7;

          uStack_70 = uVar8;

          local_88 = 0x656d616e;

          FUN_140037710(&local_88);

          if (0xf < uStack_70) {

            if ((0xfff < uStack_70 + 1) && (0x1f < (local_88 - *(longlong *)(local_88 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          uVar23 = (undefined4)s_High_Achiever_140305588._0_8_;

          uVar10 = SUB84(s_High_Achiever_140305588._0_8_,4);

          uVar21 = s_High_Achiever_140305588._8_4_;

          cVar9 = s_High_Achiever_140305588[0xc];

        }

        local_res8 = (float)((int)local_res8 + 1);

        lVar22 = lVar22 + 8;

        lVar17 = param_1[0x26];

      } while ((ulonglong)(longlong)(int)local_res8 < (ulonglong)(param_1[0x27] - lVar17 >> 3));

    }

  }

  puVar2 = (undefined8 *)param_1[0x18];

  for (puVar18 = (undefined8 *)param_1[0x17]; puVar18 != puVar2; puVar18 = puVar18 + 1) {

    (**(code **)(*(longlong *)*puVar18 + 0x28))((longlong *)*puVar18,0);

  }

  FUN_1400d2ab0(param_1);

  uVar23 = DAT_14039ca44;

  iVar12 = *(int *)((longlong)param_1 + 0x15c);

  if ((iVar12 != -1) && (DAT_1403ed637 != '\0')) {

    if (DAT_1403d959b == '\0') {

      if (*(char *)(*(longlong *)(param_1[0x26] + (longlong)iVar12 * 8) + 0x204) == '\0')

      goto LAB_1400cf198;

      cVar9 = (**(code **)(*param_1 + 0xa0))(param_1);

      if (cVar9 == '\0') goto LAB_1400cef66;

    }

    local_78 = _DAT_1403040a0;

    uStack_70 = _UNK_1403040a8;

    local_88._0_1_ = s_WhipCrack_14030eaf8[0];

    local_88._1_1_ = s_WhipCrack_14030eaf8[1];

    local_88._2_1_ = s_WhipCrack_14030eaf8[2];

    local_88._3_1_ = s_WhipCrack_14030eaf8[3];

    local_88._4_1_ = s_WhipCrack_14030eaf8[4];

    local_88._5_1_ = s_WhipCrack_14030eaf8[5];

    local_88._6_1_ = s_WhipCrack_14030eaf8[6];

    local_88._7_1_ = s_WhipCrack_14030eaf8[7];

    uStack_80 = (ulonglong)(byte)s_WhipCrack_14030eaf8[8];

    puVar14 = (undefined4 *)

              FUN_1400b4a10(*(undefined8 *)

                             (param_1[0x26] + (longlong)*(int *)((longlong)param_1 + 0x15c) * 8),

                            &local_res8);

    uVar10 = FUN_140040fe0(*puVar14);

    in_stack_ffffffffffffff68 = in_stack_ffffffffffffff68 & 0xffffffffffffff00;

    FUN_140040ca0(&local_88,100,uVar10,uVar23,in_stack_ffffffffffffff68);

    if (0xf < uStack_70) {

      if ((0xfff < uStack_70 + 1) && (0x1f < (local_88 - *(longlong *)(local_88 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    FUN_1400b7fe0(*(undefined8 *)(param_1[0x26] + (longlong)*(int *)((longlong)param_1 + 0x15c) * 8)

                  ,0);

  }

LAB_1400cef66:

  piVar19 = (int *)((longlong)param_1 + 0x15c);

  if (DAT_1403d959b != '\0') {

    if (*piVar19 != -1) {

      if (DAT_1403ed647 != '\0') {

        FUN_1400b87e0(*(undefined8 *)(param_1[0x26] + (longlong)*piVar19 * 8));

      }

      if (DAT_1403ed633 != '\0') {

        FUN_1400b8f90(*(undefined8 *)(param_1[0x26] + (longlong)*piVar19 * 8),0);

        *(undefined1 *)(*(longlong *)(param_1[0x26] + (longlong)*piVar19 * 8) + 0x206) = 0;

        *(undefined1 *)(*(longlong *)(param_1[0x26] + (longlong)*piVar19 * 8) + 0x205) = 0;

      }

      if (DAT_1403ed63b != '\0') {

        FUN_1400a33b0(*(longlong *)

                       (param_1[0x26] + (longlong)*(int *)((longlong)param_1 + 0x15c) * 8) + 0x2b8);

      }

    }

    uVar10 = (undefined4)(in_stack_ffffffffffffff68 >> 0x20);

    if (((DAT_1403d959b != '\0') && (DAT_1403ed638 != '\0')) &&

       (param_1[0x10] - param_1[0xf] >> 4 != 0)) {

      local_res10 = FUN_1402c704c(0x498);

      if (local_res10 == 0) {

        uVar15 = 0;

      }

      else {

        uVar15 = FUN_1400aac60(local_res10);

      }

      local_78 = _DAT_140304cc0;

      uStack_70 = _UNK_140304cc8;

      local_88._0_1_ = s_crazy_horse_140303b00[0];

      local_88._1_1_ = s_crazy_horse_140303b00[1];

      local_88._2_1_ = s_crazy_horse_140303b00[2];

      local_88._3_1_ = s_crazy_horse_140303b00[3];

      local_88._4_1_ = s_crazy_horse_140303b00[4];

      local_88._5_1_ = s_crazy_horse_140303b00[5];

      local_88._6_1_ = s_crazy_horse_140303b00[6];

      local_88._7_1_ = s_crazy_horse_140303b00[7];

      uStack_80 = (ulonglong)CONCAT12(s_crazy_horse_140303b00[10],s_crazy_horse_140303b00._8_2_);

      local_res10 = uVar15;

      FUN_1400c6580(4);

      FUN_1400b2ee0(uVar15,&local_88);

      if (0xf < uStack_70) {

        if ((0xfff < uStack_70 + 1) && (0x1f < (local_88 - *(longlong *)(local_88 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      in_stack_ffffffffffffff68 = CONCAT44(uVar10,0xffffffff);

      uVar10 = FUN_1400c7600(1,0,0,0xffffffff,in_stack_ffffffffffffff68);

      *(undefined4 *)(uVar15 + 0x1f8) = uVar10;

      *(undefined1 *)(uVar15 + 0x204) = 1;

      FUN_1400c57a0(&local_res8,param_1[0xf],uVar23);

      FUN_1400b6610(uVar15,&local_res8);

      pfVar3 = (float *)param_1[0xf];

      fVar1 = pfVar3[1];

      *(float *)(uVar15 + 0x1d4) = local_res8 - *pfVar3;

      *(float *)(uVar15 + 0x1d8) = local_resc - fVar1;

      FUN_1400cead0(param_1,uVar15);

      puVar4 = (ulonglong *)param_1[0x27];

      if (puVar4 == (ulonglong *)param_1[0x28]) {

        FUN_140030680(param_1 + 0x26,puVar4,&local_res10);

      }

      else {

        *puVar4 = uVar15;

        param_1[0x27] = param_1[0x27] + 8;

      }

    }

  }

LAB_1400cf198:

  uVar23 = (undefined4)(in_stack_ffffffffffffff68 >> 0x20);

  if ((((int)param_1[0x46] != -1) && (*(int *)((longlong)param_1 + 0x22c) != -1)) &&

     (((int)param_1[0x3f] == 0 && (0x78 < *(int *)((longlong)param_1 + 0x244))))) {

    lVar17 = *(longlong *)(param_1[0x26] + (longlong)(int)param_1[0x46] * 8);

    uVar16 = FUN_140067ad0(&local_88,*(undefined4 *)(lVar17 + 0x284));

    FUN_1400d0c80(param_1,lVar17,uVar16,0,CONCAT44(uVar23,DAT_140303758));

    if (0xf < uStack_70) {

      if ((0xfff < uStack_70 + 1) && (0x1f < (local_88 - *(longlong *)(local_88 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    *(undefined4 *)((longlong)param_1 + 0x22c) = 0xffffffff;

  }

  if ((param_1[0x13] != 0) && ((char)param_1[0x16] == '\0')) {

    iVar12 = 300;

    lVar17 = param_1[0x14];

    if ((DAT_14039ca90 < *(float *)(lVar17 + 0xc)) &&

       (((*(float *)(lVar17 + 0xc) < DAT_14039ca68 && (DAT_14039ca90 < *(float *)(lVar17 + 0x10)))

        && (*(float *)(lVar17 + 0x10) < DAT_14039ca68)))) {

      if ((((DAT_14039ca90 < *(float *)(lVar17 + 0x40)) &&

           (*(float *)(lVar17 + 0x40) < DAT_14039ca68)) &&

          (DAT_14039ca90 < *(float *)(lVar17 + 0x44))) &&

         (*(float *)(lVar17 + 0x44) < DAT_14039ca68)) {

        FUN_140007610(param_1[0x13]);

        iVar11 = (int)(param_1[0x27] - param_1[0x26] >> 3) + -1;

        lVar17 = (longlong)iVar11;

        if (-1 < iVar11) {

          do {

            lVar22 = *(longlong *)(param_1[0x26] + lVar17 * 8);

            FUN_1400b9540(lVar22,0);

            if (*(char *)(lVar22 + 0x21) != '\0') break;

            iVar11 = *(int *)(lVar22 + 8) - *(int *)(lVar22 + 0x1c4);

            if (iVar11 < iVar12) {

              iVar12 = iVar11;

            }

            if (*(char *)(lVar22 + 0x1c8) != '\0') {

              FUN_1400cead0(param_1);

            }

            lVar17 = lVar17 + -1;

          } while (-1 < lVar17);

        }

        if (((*(int *)((longlong)param_1 + 0x23c) == 0) &&

            (*(int *)((longlong)param_1 + 0x244) ==

             (*(int *)((longlong)param_1 + 0x244) / 0x3c) * 0x3c)) &&

           ((iVar12 == 300 && (param_1[0x27] - param_1[0x26] >> 3 != 0)))) {

          iVar12 = FUN_1400c6580(0x14);

          if ((((ulonglong)(longlong)iVar12 < (ulonglong)(param_1[0x27] - param_1[0x26] >> 3)) &&

              (lVar17 = *(longlong *)(param_1[0x26] + (longlong)iVar12 * 8), param_1[0x41] != lVar17

              )) && ((iVar12 = *(int *)(lVar17 + 0x1c), iVar12 == 2 || (iVar12 == 1)))) {

            FUN_1400b87e0();

          }

        }

        if (DAT_1403d95c5 == '\0') {

          return;

        }

        iVar12 = (int)(param_1[0x27] - param_1[0x26] >> 3) + -1;

        lVar17 = (longlong)iVar12;

        if (iVar12 < 0) {

          return;

        }

        do {

          *(undefined1 *)(*(longlong *)(param_1[0x26] + lVar17 * 8) + 0x206) = 0;

          *(undefined1 *)(*(longlong *)(param_1[0x26] + lVar17 * 8) + 0x205) = 0;

          lVar17 = lVar17 + -1;

        } while (-1 < lVar17);

        return;

      }

    }

    *(undefined1 *)(param_1 + 0x16) = 1;

  }

  return;

}




