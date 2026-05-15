// Address: 0x1400fbae0
// Ghidra name: FUN_1400fbae0
// ============ 0x1400fbae0 FUN_1400fbae0 (size=2609) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400fbae0(longlong param_1)



{

  char cVar1;

  undefined1 auVar2 [12];

  char cVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  longlong lVar9;

  char *_Str;

  int iVar10;

  int iVar11;

  int iVar12;

  undefined4 uVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  undefined1 auVar18 [12];

  float fVar19;

  float fVar20;

  float fVar21;

  undefined4 local_res8;

  float local_resc;

  float local_res18;

  float local_res1c;

  ulonglong in_stack_ffffffffffffff28;

  uint7 uVar22;

  longlong local_a8;

  ulonglong uStack_a0;

  undefined1 local_98 [16];

  

  iVar8 = 0;

  iVar11 = 0;

  if ((DAT_1403ed69f != '\0') || (iVar12 = iVar11, DAT_1403ed657 != '\0')) {

    iVar12 = 1;

  }

  iVar10 = 0;

  if ((DAT_1403ed6a0 != '\0') || (iVar4 = iVar10, DAT_1403ed654 != '\0')) {

    iVar4 = 1;

  }

  if ((DAT_1403ed6a1 != '\0') || (DAT_1403ed666 != '\0')) {

    iVar10 = 1;

  }

  if ((DAT_1403ed6a2 != '\0') || (iVar6 = iVar11, DAT_1403ed66a != '\0')) {

    iVar6 = 1;

  }

  iVar10 = iVar10 - iVar6;

  fVar19 = *(float *)(param_1 + 0x2c);

  *(undefined4 *)(param_1 + 0x48) = 0x1b;

  iVar6 = 0xb4;

  if (*(int *)(param_1 + 0xa8) != 0) {

    iVar6 = 10;

  }

  if (*(int *)(param_1 + 0x88) < iVar6) {

    *(undefined4 *)(param_1 + 0x48) = 0x1f;

  }

  if (*(char *)(param_1 + 0xad) == '\0') {

    if (((*(char *)(param_1 + 0xac) == '\0') && (*(int *)(param_1 + 0xa0) != 0)) ||

       ((uVar7 = 1, DAT_1403d959b != '\0' && ((DAT_1403ed731 != '\0' || (DAT_1403ed735 != '\0'))))))

    {

      uVar7 = 2;

    }

  }

  else {

    *(undefined4 *)(param_1 + 0x48) = 0;

    uVar5 = ~(int)(DAT_14039ca80 / *(float *)(DAT_1403fb0d8 + 0x114));

    uVar7 = 1;

    if (1 < (int)uVar5) {

      uVar7 = uVar5;

    }

  }

  cVar3 = '\0';

  if ((0 < *(int *)(param_1 + 0x8c)) &&

     (iVar6 = *(int *)(param_1 + 0x8c) + -1, *(int *)(param_1 + 0x8c) = iVar6, iVar6 == 0)) {

    *(undefined4 *)(param_1 + 0x78) = 0;

  }

  fVar21 = DAT_1403033ac;

  if (*(int *)(param_1 + 0x98) < 1) {

    if ((iVar12 == iVar4) && (iVar10 == 0)) {

      if (0 < (int)uVar7) {

        do {

          if (cVar3 != '\0') break;

          cVar3 = FUN_1400a8a70(param_1,0);

          iVar8 = iVar8 + 1;

        } while (iVar8 < (int)uVar7);

      }

      *(bool *)(param_1 + 0x70) = 0 < *(int *)(param_1 + 0x24);

    }

    else {

      FUN_1400a89f0(param_1);

      fVar16 = (float)iVar10 + *(float *)(param_1 + 0x2c);

      if ((fVar16 < fVar21) || ((float)(*(int *)(DAT_1403fb0d8 + 0x27c) * 0x20 + -0x20) < fVar16)) {

        iVar10 = iVar11;

      }

      if (0 < (int)uVar7) {

        do {

          if (cVar3 != '\0') break;

          cVar3 = FUN_1400a8ba0(param_1);

          iVar8 = iVar8 + 1;

        } while (iVar8 < (int)uVar7);

      }

      *(undefined1 *)(param_1 + 0x70) = 1;

    }

  }

  else {

    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + -1;

  }

  uVar13 = FUN_1400c5f70();

  *(undefined4 *)(param_1 + 0x28) = uVar13;

  uVar13 = FUN_1400c5f70();

  *(undefined4 *)(param_1 + 0x2c) = uVar13;

  if (cVar3 == '\0') {

    *(undefined4 *)(param_1 + 0x88) = 0;

  }

  else {

    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;

  }

  if ((((*(char *)(param_1 + 0x70) != '\0') && (cVar3 == '\0')) &&

      (*(char *)(param_1 + 0xad) == '\0')) &&

     (*(int *)(param_1 + 0x74) == (*(int *)(param_1 + 0x74) / 0x1e) * 0x1e)) {

    in_stack_ffffffffffffff28 = CONCAT44((int)(in_stack_ffffffffffffff28 >> 0x20),iVar10);

    FUN_140102860(DAT_1403fb0d8);

  }

  fVar21 = DAT_14039ca44;

  cVar1 = *(char *)(param_1 + 0x70);

  uVar22 = (uint7)(in_stack_ffffffffffffff28 >> 8);

  if (*(char *)(param_1 + 0xac) == '\0') {

    if (*(char *)(param_1 + 0xad) == '\0') {

      iVar8 = *(int *)(param_1 + 0x90);

      if (cVar1 == '\0') {

        if (iVar8 != -1) {

          FUN_140040ea0(iVar8);

          *(undefined4 *)(param_1 + 0x90) = 0xffffffff;

        }

        *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 1;

        *(undefined4 *)(param_1 + 0x74) = 0;

      }

      else {

        if (iVar8 == -1) {

          local_98._8_8_ = _UNK_1403033f8;

          local_98._0_8_ = _DAT_1403033f0;

          local_a8._0_1_ = s_TruckMotor_1403131a8[0];

          local_a8._1_1_ = s_TruckMotor_1403131a8[1];

          local_a8._2_1_ = s_TruckMotor_1403131a8[2];

          local_a8._3_1_ = s_TruckMotor_1403131a8[3];

          local_a8._4_1_ = s_TruckMotor_1403131a8[4];

          local_a8._5_1_ = s_TruckMotor_1403131a8[5];

          local_a8._6_1_ = s_TruckMotor_1403131a8[6];

          local_a8._7_1_ = s_TruckMotor_1403131a8[7];

          uStack_a0 = (ulonglong)(ushort)s_TruckMotor_1403131a8._8_2_;

          in_stack_ffffffffffffff28 = CONCAT71(uVar22,1);

          iVar8 = FUN_140040ca0(&local_a8,100,0,DAT_14039ca44,in_stack_ffffffffffffff28);

          *(int *)(param_1 + 0x90) = iVar8;

          if (0xf < (ulonglong)local_98._8_8_) {

            if ((0xfff < local_98._8_8_ + 1) &&

               (0x1f < (local_a8 - *(longlong *)(local_a8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

            iVar8 = *(int *)(param_1 + 0x90);

          }

        }

        if (iVar8 != -1) {

          fVar16 = fVar21;

          if (1 < (int)uVar7) {

            fVar16 = DAT_140303380;

          }

          if (cVar3 == '\0') {

            auVar18 = ZEXT812(0);

          }

          else {

            auVar18._4_8_ = 0;

            auVar18._0_4_ = DAT_14030335c;

          }

          auVar2._4_8_ = auVar18._4_8_;

          auVar2._0_4_ = auVar18._0_4_ + fVar16;

          FUN_140040f80(iVar8,auVar2._0_8_);

        }

        uVar7 = *(uint *)(param_1 + 0x74) & 0x80000003;

        if ((int)uVar7 < 0) {

          uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;

        }

        if (uVar7 == 0) {

          fVar16 = *(float *)(param_1 + 0x2c);

          local_res18 = *(float *)(param_1 + 0x28) - (float)(*(int *)(param_1 + 0x38) * 0xf);

          local_res1c = fVar16 + DAT_14030339c;

          fVar14 = (float)FUN_1400c6940();

          fVar19 = (fVar16 - fVar19) * DAT_140304014;

          local_res8 = FUN_1400c6940();

          in_stack_ffffffffffffff28 = in_stack_ffffffffffffff28 & 0xffffffff00000000;

          local_resc = fVar14 + fVar19;

          FUN_1400c8dc0(*(undefined8 *)(DAT_1403fb0d8 + 0x248),0xffffffff,&local_res18,&local_res8,

                        in_stack_ffffffffffffff28,0,&DAT_1403dc17c,0x1e,fVar21);

        }

        *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + 1;

        *(undefined4 *)(param_1 + 0x78) = 0;

      }

      if (*(char *)(param_1 + 0x70) == '\0') {

        return;

      }

      iVar8 = *(int *)(param_1 + 0x94);

      *(undefined4 *)(param_1 + 0x94) = 0;

      fVar19 = DAT_140303fb4;

      fVar14 = *(float *)(param_1 + 0x2c) + DAT_14030339c;

      fVar20 = (float)(*(int *)(param_1 + 0x38) * 0xf) + *(float *)(param_1 + 0x28);

      lVar9 = FUN_1401010d0(DAT_1403fb0d8,(int)(fVar20 * DAT_140303fb4),

                            (int)(fVar14 * DAT_140303fb4));

      fVar16 = DAT_14030562c;

      for (lVar9 = *(longlong *)(lVar9 + 0x10); lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x58)) {

        if (*(int *)(lVar9 + 8) == 4) {

          fVar15 = *(float *)(lVar9 + 0x28) - fVar20;

          fVar17 = *(float *)(lVar9 + 0x2c) - fVar14;

          fVar15 = fVar17 * fVar17 + fVar15 * fVar15;

          if (fVar15 < 0.0) {

            fVar15 = (float)FUN_1402cdfa0();

          }

          else {

            fVar15 = SQRT(fVar15);

          }

          if (fVar15 < fVar16) {

            *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;

          }

        }

      }

      fVar14 = *(float *)(param_1 + 0x2c) + DAT_14030339c;

      fVar20 = *(float *)(param_1 + 0x28) - (float)(*(int *)(param_1 + 0x38) * 0xf);

      lVar9 = FUN_1401010d0(DAT_1403fb0d8,(int)(fVar20 * fVar19),(int)(fVar14 * fVar19));

      for (lVar9 = *(longlong *)(lVar9 + 0x10); lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x58)) {

        if (*(int *)(lVar9 + 8) == 4) {

          fVar19 = *(float *)(lVar9 + 0x2c) - fVar14;

          fVar15 = *(float *)(lVar9 + 0x28) - fVar20;

          fVar19 = fVar15 * fVar15 + fVar19 * fVar19;

          if (fVar19 < 0.0) {

            fVar19 = (float)FUN_1402cdfa0();

          }

          else {

            fVar19 = SQRT(fVar19);

          }

          if (fVar19 < fVar16) {

            *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;

          }

        }

      }

      iVar11 = *(int *)(param_1 + 0x94);

      if (iVar8 == iVar11) {

        s_Cas9Motor_140313188[0] = (char)s_Cas9Motor_140313188._0_8_;

        s_Cas9Motor_140313188[1] = SUB81(s_Cas9Motor_140313188._0_8_,1);

        s_Cas9Motor_140313188[2] = SUB81(s_Cas9Motor_140313188._0_8_,2);

        s_Cas9Motor_140313188[3] = SUB81(s_Cas9Motor_140313188._0_8_,3);

        s_Cas9Motor_140313188[4] = SUB81(s_Cas9Motor_140313188._0_8_,4);

        s_Cas9Motor_140313188[5] = SUB81(s_Cas9Motor_140313188._0_8_,5);

        s_Cas9Motor_140313188[6] = SUB81(s_Cas9Motor_140313188._0_8_,6);

        s_Cas9Motor_140313188[7] = SUB81(s_Cas9Motor_140313188._0_8_,7);

        s_BalloonFly_140313198[0] = (char)s_BalloonFly_140313198._0_8_;

        s_BalloonFly_140313198[1] = SUB81(s_BalloonFly_140313198._0_8_,1);

        s_BalloonFly_140313198[2] = SUB81(s_BalloonFly_140313198._0_8_,2);

        s_BalloonFly_140313198[3] = SUB81(s_BalloonFly_140313198._0_8_,3);

        s_BalloonFly_140313198[4] = SUB81(s_BalloonFly_140313198._0_8_,4);

        s_BalloonFly_140313198[5] = SUB81(s_BalloonFly_140313198._0_8_,5);

        s_BalloonFly_140313198[6] = SUB81(s_BalloonFly_140313198._0_8_,6);

        s_BalloonFly_140313198[7] = SUB81(s_BalloonFly_140313198._0_8_,7);

        s_BalloonFly_140313198[8] = (char)s_BalloonFly_140313198._8_2_;

        s_BalloonFly_140313198[9] = SUB21(s_BalloonFly_140313198._8_2_,1);

        s_TruckMotor_1403131a8[0] = (char)s_TruckMotor_1403131a8._0_8_;

        s_TruckMotor_1403131a8[1] = SUB81(s_TruckMotor_1403131a8._0_8_,1);

        s_TruckMotor_1403131a8[2] = SUB81(s_TruckMotor_1403131a8._0_8_,2);

        s_TruckMotor_1403131a8[3] = SUB81(s_TruckMotor_1403131a8._0_8_,3);

        s_TruckMotor_1403131a8[4] = SUB81(s_TruckMotor_1403131a8._0_8_,4);

        s_TruckMotor_1403131a8[5] = SUB81(s_TruckMotor_1403131a8._0_8_,5);

        s_TruckMotor_1403131a8[6] = SUB81(s_TruckMotor_1403131a8._0_8_,6);

        s_TruckMotor_1403131a8[7] = SUB81(s_TruckMotor_1403131a8._0_8_,7);

        s_TruckMotor_1403131a8[8] = (char)s_TruckMotor_1403131a8._8_2_;

        s_TruckMotor_1403131a8[9] = SUB21(s_TruckMotor_1403131a8._8_2_,1);

        return;

      }

      if (iVar8 == 0) {

        *(undefined4 *)(param_1 + 0x98) = 3;

      }

      if (iVar11 != 1) {

        fVar21 = DAT_14030c264;

      }

      _Str = "TruckPotholeIn";

      if (iVar11 == 0) {

        _Str = "TruckPotholeOut";

      }

      local_a8 = 0;

      uStack_a0 = 0;

      local_98._0_8_ = 0;

      local_98._8_8_ = 0;

      strlen(_Str);

      FUN_140027e30(&local_a8,_Str);

      FUN_140040ca0(&local_a8,100,0,fVar21,in_stack_ffffffffffffff28 & 0xffffffffffffff00);

      if ((ulonglong)local_98._8_8_ < 0x10) {

        return;

      }

      if ((0xfff < local_98._8_8_ + 1) && (0x1f < (local_a8 - *(longlong *)(local_a8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    else {

      if (cVar1 == '\0') goto LAB_1400fbfc2;

      iVar8 = *(int *)(param_1 + 0x74) + 1;

      *(int *)(param_1 + 0x74) = iVar8;

      if (iVar8 != 1) {

        return;

      }

      local_98._0_8_ = _DAT_1403033f0;

      local_98._8_8_ = _UNK_1403033f8;

      local_a8._0_1_ = s_BalloonFly_140313198[0];

      local_a8._1_1_ = s_BalloonFly_140313198[1];

      local_a8._2_1_ = s_BalloonFly_140313198[2];

      local_a8._3_1_ = s_BalloonFly_140313198[3];

      local_a8._4_1_ = s_BalloonFly_140313198[4];

      local_a8._5_1_ = s_BalloonFly_140313198[5];

      local_a8._6_1_ = s_BalloonFly_140313198[6];

      local_a8._7_1_ = s_BalloonFly_140313198[7];

      uStack_a0 = (ulonglong)(ushort)s_BalloonFly_140313198._8_2_;

      FUN_140040ca0(&local_a8,100,0,DAT_14039ca44,(ulonglong)uVar22 << 8);

      if ((ulonglong)local_98._8_8_ < 0x10) {

        return;

      }

      if ((0xfff < local_98._8_8_ + 1) && (0x1f < (local_a8 - *(longlong *)(local_a8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  else {

    if (cVar1 != '\0') {

      if (*(int *)(param_1 + 0x90) == -1) {

        local_98._8_8_ = _UNK_1403040a8;

        local_98._0_8_ = _DAT_1403040a0;

        local_a8._0_1_ = s_Cas9Motor_140313188[0];

        local_a8._1_1_ = s_Cas9Motor_140313188[1];

        local_a8._2_1_ = s_Cas9Motor_140313188[2];

        local_a8._3_1_ = s_Cas9Motor_140313188[3];

        local_a8._4_1_ = s_Cas9Motor_140313188[4];

        local_a8._5_1_ = s_Cas9Motor_140313188[5];

        local_a8._6_1_ = s_Cas9Motor_140313188[6];

        local_a8._7_1_ = s_Cas9Motor_140313188[7];

        uStack_a0 = (ulonglong)(byte)s_Cas9Motor_140313188[8];

        in_stack_ffffffffffffff28 = CONCAT71(uVar22,1);

        uVar13 = FUN_140040ca0(&local_a8,100,0,DAT_14039ca44,in_stack_ffffffffffffff28);

        *(undefined4 *)(param_1 + 0x90) = uVar13;

        if (0xf < (ulonglong)local_98._8_8_) {

          if ((0xfff < local_98._8_8_ + 1) &&

             (0x1f < (local_a8 - *(longlong *)(local_a8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

      uVar7 = *(uint *)(param_1 + 0x74) & 0x80000003;

      if ((int)uVar7 < 0) {

        uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;

      }

      if (uVar7 == 0) {

        local_res18 = *(float *)(param_1 + 0x28) - (float)(*(int *)(param_1 + 0x38) * 7);

        fVar16 = *(float *)(param_1 + 0x2c);

        local_res1c = fVar16 + DAT_140304c00;

        fVar14 = (float)FUN_1400c6940();

        fVar19 = (fVar16 - fVar19) * DAT_140304014;

        local_res8 = FUN_1400c6940();

        local_resc = fVar14 + fVar19;

        FUN_1400c8dc0(*(undefined8 *)(DAT_1403fb0d8 + 0x248),0xffffffff,&local_res18,&local_res8,

                      in_stack_ffffffffffffff28 & 0xffffffff00000000,0,&DAT_1403dc1c0,0x1e,fVar21);

      }

      *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + 1;

      *(undefined4 *)(param_1 + 0x78) = 0;

      return;

    }

    if (*(int *)(param_1 + 0x90) != -1) {

      FUN_140040ea0();

      *(undefined4 *)(param_1 + 0x90) = 0xffffffff;

    }

    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 1;

LAB_1400fbfc2:

    *(undefined4 *)(param_1 + 0x74) = 0;

  }

  return;

}




