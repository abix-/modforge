// Address: 0x140261db0
// Ghidra name: FUN_140261db0
// ============ 0x140261db0 FUN_140261db0 (size=4615) ============


undefined1

FUN_140261db0(byte *param_1,int *param_2,int *param_3,int *param_4,int param_5,uint param_6,

             uint param_7,uint param_8)



{

  char cVar1;

  char cVar2;

  char cVar3;

  undefined1 uVar4;

  undefined2 uVar5;

  uint uVar6;

  undefined4 uVar7;

  longlong lVar8;

  longlong lVar9;

  longlong lVar10;

  byte *pbVar11;

  int iVar12;

  longlong lVar13;

  uint uVar14;

  longlong lVar15;

  int iVar16;

  ulonglong uVar17;

  int *piVar18;

  ulonglong uVar19;

  int iVar20;

  longlong lVar21;

  uint local_104;

  int local_100;

  longlong local_f8;

  undefined8 local_f0;

  int local_e8;

  longlong local_e0;

  undefined4 local_d8;

  char local_d4;

  undefined1 local_d3;

  int local_d0;

  int local_cc;

  int local_c8;

  int local_c4;

  int local_c0;

  int local_bc;

  int local_b8;

  int local_b4;

  int local_b0;

  ulonglong local_a8;

  longlong local_a0;

  longlong local_98;

  longlong local_90;

  longlong local_88;

  byte *local_80;

  longlong local_78;

  undefined4 local_70;

  undefined4 local_6c;

  int local_68;

  undefined8 local_60;

  undefined8 local_58;

  

  local_d3 = 1;

  local_68 = 0;

  local_80 = (byte *)0x0;

  cVar1 = FUN_1401489c0(param_1);

  if (cVar1 == '\0') {

    return 0;

  }

  local_f8 = FUN_140263080(param_2,param_3,*param_4,param_4[1]);

  if (((((((char)param_6 != (char)param_7) || (param_6._1_1_ != param_7._1_1_)) ||

        (param_6._2_1_ != param_7._2_1_)) ||

       ((param_6._3_1_ != param_7._3_1_ || ((char)param_7 != (char)param_8)))) ||

      (param_7._1_1_ != param_8._1_1_)) ||

     ((param_7._2_1_ != param_8._2_1_ || (local_d4 = '\x01', param_7._3_1_ != param_8._3_1_)))) {

    local_d4 = '\0';

  }

  if (local_f8 == 0) {

    return 1;

  }

  local_a0 = local_f8;

  if ((*param_1 & 2) != 0) {

    cVar1 = FUN_140146f20(param_1);

    if (cVar1 == '\0') {

      return 0;

    }

    local_68 = 1;

  }

  FUN_140262fc0(param_2,param_3,param_4,&local_d0);

  local_78 = 0;

  local_70 = *(undefined4 *)(param_1 + 8);

  local_6c = *(undefined4 *)(param_1 + 0xc);

  FUN_140185790(&local_d0,&local_78,&local_d0);

  FUN_1401466d0(param_1,&local_78);

  FUN_140185790(&local_d0,&local_78,&local_d0);

  if (param_5 == 0) {

    local_b0 = *(int *)(param_1 + 0x10);

    local_104 = (uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

    lVar21 = (longlong)(int)(local_104 * local_d0) + (longlong)(local_b0 * local_cc) +

             *(longlong *)(param_1 + 0x18);

  }

  else {

    uVar14 = *(uint *)(param_1 + 4);

    if (uVar14 == 0) {

LAB_140261f5b:

      if (((uVar14 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0) {

LAB_140261f8b:

        if (uVar14 != 0) goto LAB_140261f90;

        goto LAB_140261f9f;

      }

LAB_140261f67:

      uVar6 = uVar14 & 0xf00000;

      if ((((uVar6 != 0x300000) && (uVar6 != 0x400000)) && (uVar6 != 0x700000)) &&

         (uVar6 != 0x800000)) goto LAB_140261f8b;

    }

    else {

      if ((uVar14 & 0xf0000000) == 0x10000000) {

        if ((uVar14 & 0xf000000) != 0x4000000) goto LAB_140261f5b;

        goto LAB_140261f67;

      }

LAB_140261f90:

      if ((uVar14 & 0xf0000000) == 0x10000000) {

LAB_140261f9f:

        if ((((uVar14 & 0xf000000) == 0x7000000) ||

            (((uVar14 & 0xf000000) + 0xf8000000 & 0xfcffffff) == 0)) &&

           (((uVar6 = uVar14 & 0xf00000, uVar6 == 0x300000 ||

             ((uVar6 == 0x200000 || (uVar6 == 0x600000)))) || (uVar6 == 0x500000))))

        goto LAB_140261fe4;

      }

      uVar14 = 0x16362004;

    }

LAB_140261fe4:

    local_80 = (byte *)FUN_140145e60(local_c8,local_c4,uVar14);

    if (local_80 == (byte *)0x0) {

      local_d3 = 0;

      uVar4 = 0;

      goto LAB_140262f74;

    }

    if (param_5 == 4) {

      uVar7 = FUN_140146f80(local_80,0xff,0xff,0xff,0xff);

      FUN_14017dc90(local_80,0,uVar7);

    }

    FUN_140148450(local_80,param_5);

    lVar21 = *(longlong *)(local_80 + 0x18);

    local_104 = (uint)*(byte *)(*(longlong *)(local_80 + 0x38) + 5);

    local_b0 = *(int *)(local_80 + 0x10);

  }

  local_a8 = CONCAT44(local_a8._4_4_,(uint)(0 < local_f8));

  if (local_f8 < 0) {

    local_f8 = -local_f8;

  }

  local_c0 = (param_3[1] - param_4[1]) * 2;

  iVar12 = param_2[1] - param_3[1];

  local_e8 = (param_4[1] - param_2[1]) * 2;

  local_100 = iVar12 * 2;

  local_bc = (*param_4 - *param_3) * 2;

  iVar20 = *param_3 - *param_2;

  local_b8 = (*param_2 - *param_4) * 2;

  local_b4 = iVar20 * 2;

  local_f0._0_4_ = local_d0;

  local_f0._4_4_ = local_cc;

  FUN_140263160(&local_f0);

  uVar19 = (ulonglong)((int)local_f0 + 1);

  uVar17 = (ulonglong)(local_f0._4_4_ + 1);

  lVar8 = FUN_140263080(param_3,param_4,uVar19,uVar17);

  local_e0 = lVar8;

  lVar9 = FUN_140263080(param_4,param_2,uVar19 & 0xffffffff,uVar17 & 0xffffffff);

  piVar18 = param_3;

  local_f0 = lVar9;

  lVar10 = FUN_140263080(param_2,param_3,uVar19 & 0xffffffff,uVar17 & 0xffffffff);

  if (local_a0 < 1) {

    local_b4 = iVar20 * -2;

    local_c0 = -local_c0;

    local_e0 = -lVar8;

    lVar9 = -lVar9;

    local_e8 = -local_e8;

    local_100 = iVar12 * -2;

    local_bc = -local_bc;

    local_b8 = -local_b8;

    lVar10 = -lVar10;

    local_f0 = lVar9;

  }

  local_98 = lVar10;

  cVar1 = FUN_140263120(piVar18,param_4,local_a8 & 0xffffffff);

  cVar2 = FUN_140263120(param_4,param_2);

  cVar3 = FUN_140263120(param_2,param_3);

  if (local_d4 == '\0') {

    pbVar11 = param_1;

    if (local_80 != (byte *)0x0) {

      pbVar11 = local_80;

    }

    local_60 = *(undefined8 *)(pbVar11 + 0x48);

    local_58 = *(undefined8 *)(pbVar11 + 0x38);

    if (local_104 == 4) {

      local_a8 = local_a8 & 0xffffffff00000000;

      iVar12 = local_c8;

      if (0 < local_c4) {

        do {

          local_88 = lVar10;

          local_104 = 0;

          lVar10 = local_88;

          local_90 = local_f0;

          if (0 < iVar12) {

            local_a0 = (ulonglong)(cVar1 != '\0') - 1;

            local_d8 = 0;

            lVar9 = local_e0;

            iVar20 = local_e8;

            do {

              if (((-1 < local_a0 + lVar9) &&

                  (-1 < (longlong)(((ulonglong)(cVar2 != '\0') - 1) + local_90))) &&

                 (-1 < (longlong)(((ulonglong)(cVar3 != '\0') - 1) + local_88))) {

                uVar7 = FUN_14017bba0(local_58,local_60,

                                      (longlong)

                                      ((ulonglong)(param_6 & 0xff) * lVar9 +

                                      (ulonglong)(param_8 & 0xff) * local_88 +

                                      (ulonglong)(param_7 & 0xff) * local_90) / local_f8,

                                      (longlong)

                                      ((ulonglong)param_6._1_1_ * lVar9 +

                                      (ulonglong)param_8._1_1_ * local_88 +

                                      (ulonglong)param_7._1_1_ * local_90) / local_f8,

                                      (char)((longlong)

                                             ((ulonglong)param_6._2_1_ * lVar9 +

                                             (ulonglong)param_8._2_1_ * local_88 +

                                             (ulonglong)param_7._2_1_ * local_90) / local_f8),

                                      (char)((longlong)

                                             ((ulonglong)param_6._3_1_ * lVar9 +

                                             (ulonglong)param_8._3_1_ * local_88 +

                                             (ulonglong)param_7._3_1_ * local_90) / local_f8));

                *(undefined4 *)(local_d8 + lVar21) = uVar7;

                iVar20 = local_e8;

              }

              local_104 = local_104 + 1;

              lVar9 = lVar9 + local_c0;

              local_90 = local_90 + iVar20;

              local_d8 = local_d8 + 4;

              local_88 = local_88 + local_100;

              lVar10 = local_98;

              iVar12 = local_c8;

            } while ((int)local_104 < local_c8);

          }

          local_e0 = local_e0 + local_bc;

          local_f0 = local_f0 + local_b8;

          local_98 = lVar10 + local_b4;

          lVar21 = lVar21 + local_b0;

          iVar20 = (int)local_a8 + 1;

          local_a8 = CONCAT44(local_a8._4_4_,iVar20);

          lVar10 = local_98;

        } while (iVar20 < local_c4);

      }

    }

    else if (local_104 == 3) {

      local_d8 = 0;

      iVar12 = local_c8;

      if (0 < local_c4) {

        do {

          local_90 = lVar9;

          local_88 = lVar10;

          iVar20 = 0;

          local_a8 = local_a8 & 0xffffffff00000000;

          lVar10 = local_88;

          lVar9 = local_90;

          local_a0 = local_e0;

          if (0 < iVar12) {

            local_78 = (ulonglong)(cVar1 != '\0') - 1;

            local_104 = 0;

            iVar16 = local_e8;

            do {

              if (((-1 < local_78 + local_a0) &&

                  (-1 < (longlong)(((ulonglong)(cVar2 != '\0') - 1) + local_90))) &&

                 (-1 < (longlong)(((ulonglong)(cVar3 != '\0') - 1) + local_88))) {

                lVar10 = (longlong)(int)local_104;

                uVar7 = FUN_14017bba0(local_58,local_60,

                                      (longlong)

                                      ((ulonglong)(param_6 & 0xff) * local_a0 +

                                      (ulonglong)(param_8 & 0xff) * local_88 +

                                      (ulonglong)(param_7 & 0xff) * local_90) / local_f8,

                                      (longlong)

                                      ((ulonglong)param_6._1_1_ * local_a0 +

                                      (ulonglong)param_8._1_1_ * local_88 +

                                      (ulonglong)param_7._1_1_ * local_90) / local_f8,

                                      (char)((longlong)

                                             ((ulonglong)param_6._2_1_ * local_a0 +

                                             (ulonglong)param_8._2_1_ * local_88 +

                                             (ulonglong)param_7._2_1_ * local_90) / local_f8),

                                      (char)((longlong)

                                             ((ulonglong)param_6._3_1_ * local_a0 +

                                             (ulonglong)param_8._3_1_ * local_88 +

                                             (ulonglong)param_7._3_1_ * local_90) / local_f8));

                *(char *)(lVar10 + lVar21) = (char)uVar7;

                *(char *)(lVar10 + 2 + lVar21) = (char)((uint)uVar7 >> 0x10);

                *(char *)(lVar10 + 1 + lVar21) = (char)((uint)uVar7 >> 8);

                iVar20 = (int)local_a8;

                iVar16 = local_e8;

              }

              iVar20 = iVar20 + 1;

              local_a0 = local_a0 + local_c0;

              local_90 = local_90 + iVar16;

              local_104 = local_104 + 3;

              local_88 = local_88 + local_100;

              local_a8 = CONCAT44(local_a8._4_4_,iVar20);

              lVar10 = local_98;

              lVar9 = local_f0;

              iVar12 = local_c8;

            } while (iVar20 < local_c8);

          }

          local_e0 = local_e0 + local_bc;

          local_f0 = lVar9 + local_b8;

          local_98 = lVar10 + local_b4;

          lVar21 = lVar21 + local_b0;

          local_d8 = local_d8 + 1;

          lVar10 = local_98;

          lVar9 = local_f0;

        } while (local_d8 < local_c4);

      }

    }

    else if (local_104 == 2) {

      local_d8 = 0;

      iVar12 = local_c8;

      if (0 < local_c4) {

        do {

          local_90 = lVar10;

          iVar20 = 0;

          local_a8 = local_a8 & 0xffffffff00000000;

          lVar10 = local_90;

          local_a0 = local_f0;

          if (0 < iVar12) {

            local_78 = (ulonglong)(cVar1 != '\0') - 1;

            local_104 = 0;

            lVar9 = local_e0;

            iVar16 = local_e8;

            do {

              if (((-1 < local_78 + lVar9) &&

                  (-1 < (longlong)(((ulonglong)(cVar2 != '\0') - 1) + local_a0))) &&

                 (-1 < (longlong)(((ulonglong)(cVar3 != '\0') - 1) + local_90))) {

                uVar5 = FUN_14017bba0(local_58,local_60,

                                      (longlong)

                                      ((ulonglong)(param_6 & 0xff) * lVar9 +

                                      (ulonglong)(param_8 & 0xff) * local_90 +

                                      (ulonglong)(param_7 & 0xff) * local_a0) / local_f8,

                                      (longlong)

                                      ((ulonglong)param_6._1_1_ * lVar9 +

                                      (ulonglong)param_8._1_1_ * local_90 +

                                      (ulonglong)param_7._1_1_ * local_a0) / local_f8,

                                      (char)((longlong)

                                             ((ulonglong)param_6._2_1_ * lVar9 +

                                             (ulonglong)param_8._2_1_ * local_90 +

                                             (ulonglong)param_7._2_1_ * local_a0) / local_f8),

                                      (char)((longlong)

                                             ((ulonglong)param_6._3_1_ * lVar9 +

                                             (ulonglong)param_8._3_1_ * local_90 +

                                             (ulonglong)param_7._3_1_ * local_a0) / local_f8));

                *(undefined2 *)((int)local_104 + lVar21) = uVar5;

                iVar20 = (int)local_a8;

                iVar16 = local_e8;

              }

              iVar20 = iVar20 + 1;

              lVar9 = lVar9 + local_c0;

              local_a0 = local_a0 + iVar16;

              local_104 = local_104 + 2;

              local_90 = local_90 + local_100;

              local_a8 = CONCAT44(local_a8._4_4_,iVar20);

              lVar10 = local_98;

              iVar12 = local_c8;

            } while (iVar20 < local_c8);

          }

          local_e0 = local_e0 + local_bc;

          local_f0 = local_f0 + local_b8;

          local_98 = lVar10 + local_b4;

          lVar21 = lVar21 + local_b0;

          local_d8 = local_d8 + 1;

          lVar10 = local_98;

        } while (local_d8 < local_c4);

      }

    }

    else if ((local_104 == 1) && (local_104 = 0, iVar12 = local_c8, 0 < local_c4)) {

      do {

        local_90 = lVar10;

        iVar20 = 0;

        local_a8 = local_a8 & 0xffffffff00000000;

        lVar10 = local_90;

        local_a0 = local_f0;

        if (0 < iVar12) {

          lVar9 = (longlong)local_c0;

          local_88 = (ulonglong)(cVar1 != '\0') - 1;

          lVar8 = local_e0;

          local_78 = lVar9;

          iVar16 = local_e8;

          do {

            if (((-1 < local_88 + lVar8) &&

                (iVar16 = local_e8, -1 < (longlong)(((ulonglong)(cVar2 != '\0') - 1) + local_a0)))

               && (-1 < (longlong)(((ulonglong)(cVar3 != '\0') - 1) + local_90))) {

              uVar4 = FUN_14017bba0(local_58,local_60,

                                    (longlong)

                                    ((ulonglong)(param_6 & 0xff) * lVar8 +

                                    (ulonglong)(param_8 & 0xff) * local_90 +

                                    (ulonglong)(param_7 & 0xff) * local_a0) / local_f8,

                                    (longlong)

                                    ((ulonglong)param_6._1_1_ * lVar8 +

                                    (ulonglong)param_8._1_1_ * local_90 +

                                    (ulonglong)param_7._1_1_ * local_a0) / local_f8,

                                    (char)((longlong)

                                           ((ulonglong)param_6._2_1_ * lVar8 +

                                           (ulonglong)param_8._2_1_ * local_90 +

                                           (ulonglong)param_7._2_1_ * local_a0) / local_f8),

                                    (char)((longlong)

                                           ((ulonglong)param_6._3_1_ * lVar8 +

                                           (ulonglong)param_8._3_1_ * local_90 +

                                           (ulonglong)param_7._3_1_ * local_a0) / local_f8));

              *(undefined1 *)((int)local_a8 + lVar21) = uVar4;

              lVar9 = local_78;

              iVar12 = local_c8;

              iVar20 = (int)local_a8;

              iVar16 = local_e8;

            }

            iVar20 = iVar20 + 1;

            local_90 = local_90 + local_100;

            local_a0 = local_a0 + iVar16;

            lVar8 = lVar8 + lVar9;

            local_a8 = CONCAT44(local_a8._4_4_,iVar20);

            lVar10 = local_98;

          } while (iVar20 < iVar12);

        }

        local_e0 = local_e0 + local_bc;

        local_f0 = local_f0 + local_b8;

        local_98 = lVar10 + local_b4;

        lVar21 = lVar21 + local_b0;

        local_104 = local_104 + 1;

        lVar10 = local_98;

      } while ((int)local_104 < local_c4);

    }

  }

  else {

    pbVar11 = local_80;

    if (local_80 == (byte *)0x0) {

      pbVar11 = param_1;

    }

    iVar12 = FUN_140146f80(pbVar11,param_6 & 0xff,param_6._1_1_,param_6._2_1_,param_6._3_1_);

    local_d8 = iVar12;

    if (local_104 == 4) {

      local_104 = 0;

      lVar10 = local_98;

      if (0 < local_c4) {

        do {

          iVar20 = 0;

          if (0 < local_c8) {

            local_f0 = (longlong)local_c0;

            iVar16 = 0;

            local_a0 = (longlong)local_100;

            lVar13 = ((ulonglong)(cVar1 != '\0') - 1) + local_e0;

            lVar8 = lVar9;

            lVar15 = lVar10;

            do {

              if (((-1 < lVar13) && (-1 < (longlong)(((ulonglong)(cVar2 != '\0') - 1) + lVar8))) &&

                 (-1 < (longlong)(((ulonglong)(cVar3 != '\0') - 1) + lVar15))) {

                *(int *)(iVar16 + lVar21) = iVar12;

              }

              lVar15 = lVar15 + local_a0;

              lVar13 = lVar13 + local_f0;

              lVar8 = lVar8 + local_e8;

              iVar20 = iVar20 + 1;

              iVar16 = iVar16 + 4;

            } while (iVar20 < local_c8);

          }

          local_104 = local_104 + 1;

          local_e0 = local_e0 + local_bc;

          lVar9 = lVar9 + local_b8;

          lVar21 = lVar21 + local_b0;

          lVar10 = lVar10 + local_b4;

        } while ((int)local_104 < local_c4);

      }

    }

    else if (local_104 == 3) {

      local_104 = 0;

      if (0 < local_c4) {

        do {

          iVar20 = 0;

          lVar10 = lVar9;

          if (0 < local_c8) {

            iVar16 = 0;

            local_d8._2_1_ = (undefined1)((uint)iVar12 >> 0x10);

            local_d8._1_1_ = (undefined1)((uint)iVar12 >> 8);

            local_a8 = (ulonglong)local_e8;

            local_a0 = (longlong)local_100;

            lVar15 = ((ulonglong)(cVar1 != '\0') - 1) + local_e0;

            lVar8 = local_98;

            do {

              if (((-1 < lVar15) && (-1 < (longlong)(((ulonglong)(cVar2 != '\0') - 1) + lVar9))) &&

                 (-1 < (longlong)(((ulonglong)(cVar3 != '\0') - 1) + lVar8))) {

                lVar10 = (longlong)iVar16;

                *(char *)(lVar10 + lVar21) = (char)iVar12;

                *(undefined1 *)(lVar10 + 1 + lVar21) = local_d8._1_1_;

                *(undefined1 *)(lVar10 + 2 + lVar21) = local_d8._2_1_;

              }

              lVar8 = lVar8 + local_a0;

              lVar15 = lVar15 + local_c0;

              lVar9 = lVar9 + local_a8;

              iVar20 = iVar20 + 1;

              iVar16 = iVar16 + 3;

              lVar10 = local_f0;

            } while (iVar20 < local_c8);

          }

          local_104 = local_104 + 1;

          local_e0 = local_e0 + local_bc;

          lVar9 = lVar10 + local_b8;

          local_98 = local_98 + local_b4;

          lVar21 = lVar21 + local_b0;

          local_f0 = lVar9;

        } while ((int)local_104 < local_c4);

      }

    }

    else if (local_104 == 2) {

      local_104 = 0;

      lVar10 = local_98;

      if (0 < local_c4) {

        do {

          iVar20 = 0;

          if (0 < local_c8) {

            local_f0 = (longlong)local_c0;

            iVar16 = 0;

            local_a0 = (longlong)local_100;

            lVar13 = ((ulonglong)(cVar1 != '\0') - 1) + local_e0;

            lVar8 = lVar9;

            lVar15 = lVar10;

            do {

              if (((-1 < lVar13) && (-1 < (longlong)(((ulonglong)(cVar2 != '\0') - 1) + lVar8))) &&

                 (-1 < (longlong)(((ulonglong)(cVar3 != '\0') - 1) + lVar15))) {

                *(short *)(iVar16 + lVar21) = (short)iVar12;

              }

              lVar15 = lVar15 + local_a0;

              lVar13 = lVar13 + local_f0;

              lVar8 = lVar8 + local_e8;

              iVar20 = iVar20 + 1;

              iVar16 = iVar16 + 2;

            } while (iVar20 < local_c8);

          }

          local_104 = local_104 + 1;

          local_e0 = local_e0 + local_bc;

          lVar9 = lVar9 + local_b8;

          lVar21 = lVar21 + local_b0;

          lVar10 = lVar10 + local_b4;

        } while ((int)local_104 < local_c4);

      }

    }

    else if ((local_104 == 1) && (local_104 = 0, lVar10 = local_98, 0 < local_c4)) {

      do {

        iVar20 = 0;

        if (0 < local_c8) {

          local_f0 = (longlong)local_e8;

          lVar13 = ((ulonglong)(cVar1 != '\0') - 1) + local_e0;

          lVar8 = lVar9;

          lVar15 = lVar10;

          do {

            if (((-1 < lVar13) && (-1 < (longlong)(((ulonglong)(cVar2 != '\0') - 1) + lVar8))) &&

               (-1 < (longlong)(((ulonglong)(cVar3 != '\0') - 1) + lVar15))) {

              *(char *)(iVar20 + lVar21) = (char)iVar12;

            }

            lVar8 = lVar8 + local_f0;

            lVar15 = lVar15 + local_100;

            iVar20 = iVar20 + 1;

            lVar13 = lVar13 + local_c0;

          } while (iVar20 < local_c8);

        }

        local_104 = local_104 + 1;

        local_e0 = local_e0 + local_bc;

        lVar9 = lVar9 + local_b8;

        lVar21 = lVar21 + local_b0;

        lVar10 = lVar10 + local_b4;

      } while ((int)local_104 < local_c4);

    }

  }

  pbVar11 = local_80;

  if (local_80 != (byte *)0x0) {

    FUN_140144390(local_80,0,param_1,&local_d0);

    FUN_140146010(pbVar11);

  }

  uVar4 = 1;

LAB_140262f74:

  if (local_68 != 0) {

    FUN_1401489e0(param_1);

    uVar4 = local_d3;

  }

  return uVar4;

}




