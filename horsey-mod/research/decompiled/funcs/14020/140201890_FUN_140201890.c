// Address: 0x140201890
// Ghidra name: FUN_140201890
// ============ 0x140201890 FUN_140201890 (size=2581) ============


undefined1 FUN_140201890(undefined8 param_1,int *param_2,longlong param_3)



{

  int iVar1;

  int iVar2;

  undefined8 uVar3;

  undefined1 uVar4;

  float fVar5;

  float fVar6;

  undefined1 uVar7;

  undefined1 uVar8;

  undefined1 uVar9;

  char cVar10;

  undefined4 uVar11;

  uint uVar12;

  uint uVar13;

  longlong lVar14;

  longlong lVar15;

  int *piVar16;

  longlong lVar17;

  ulonglong uVar18;

  int *piVar19;

  longlong lVar20;

  float fVar21;

  undefined1 auVar22 [16];

  undefined1 auVar23 [16];

  undefined1 auVar24 [16];

  undefined1 auVar25 [16];

  undefined1 auVar26 [16];

  undefined1 auVar27 [16];

  undefined1 auVar28 [16];

  undefined1 auVar29 [16];

  float fVar30;

  float fVar31;

  float fVar32;

  longlong in_stack_fffffffffffffef8;

  undefined7 uVar33;

  undefined4 uVar34;

  int *in_stack_ffffffffffffff10;

  undefined1 local_b6;

  undefined1 local_b5;

  undefined1 local_b4;

  undefined1 local_b3 [3];

  int *local_b0;

  int *piStack_a8;

  undefined4 local_a0;

  undefined1 local_9c;

  int local_98;

  int local_94;

  int local_90;

  int local_8c;

  undefined4 local_88 [2];

  undefined8 local_80;

  undefined4 local_78;

  undefined4 local_74;

  

  lVar14 = FUN_1402002c0();

  cVar10 = FUN_1401489c0(lVar14);

  fVar6 = DAT_14039ca44;

  fVar5 = DAT_14030a2d0;

  if (cVar10 == '\0') {

    return 0;

  }

  local_a0 = 1;

  local_9c = 0;

  local_b0 = (int *)0x0;

  piStack_a8 = (int *)0x0;

  uVar11 = local_a0;

  uVar4 = local_9c;

  do {

    uVar34 = (undefined4)((ulonglong)in_stack_ffffffffffffff10 >> 0x20);

    if (param_2 == (int *)0x0) {

      return 1;

    }

    local_a0._1_1_ = (undefined1)((uint)uVar11 >> 8);

    uVar7 = local_a0._1_1_;

    local_a0._2_1_ = (undefined1)((uint)uVar11 >> 0x10);

    uVar8 = local_a0._2_1_;

    local_a0._3_1_ = (undefined1)((uint)uVar11 >> 0x18);

    uVar9 = local_a0._3_1_;

    local_a0._1_3_ = (undefined3)((uint)uVar11 >> 8);

    local_9c = uVar4;

    local_a0 = uVar11;

    switch(*param_2 + -1) {

    case 0:

      local_b0 = param_2 + 4;

      local_a0 = CONCAT31(local_a0._1_3_,1);

      uVar11 = local_a0;

      break;

    case 1:

      if ((char)param_2[2] == '\0') {

        piStack_a8 = (int *)0x0;

        local_a0 = CONCAT31(local_a0._1_3_,1);

        uVar11 = local_a0;

      }

      else {

        piStack_a8 = param_2 + 3;

        local_a0 = CONCAT31(local_a0._1_3_,1);

        uVar11 = local_a0;

      }

      break;

    case 2:

      fVar30 = (float)param_2[5] * (float)param_2[4];

      if (0.0 <= fVar30) {

        auVar22 = ZEXT416((uint)fVar6);

        if (fVar30 <= fVar6) {

          auVar22 = ZEXT416((uint)fVar30);

        }

      }

      else {

        auVar22 = ZEXT816(0);

      }

      auVar23._4_12_ = auVar22._4_12_;

      auVar23._0_4_ = auVar22._0_4_ * fVar5;

      fVar30 = (float)thunk_FUN_1402e1d00(auVar23._0_8_);

      fVar31 = (float)param_2[6] * (float)param_2[4];

      local_a0._0_2_ = CONCAT11((char)(int)fVar30,(undefined1)local_a0);

      if (0.0 <= fVar31) {

        auVar22 = ZEXT416((uint)fVar6);

        if (fVar31 <= fVar6) {

          auVar22 = ZEXT416((uint)fVar31);

        }

      }

      else {

        auVar22 = ZEXT816(0);

      }

      auVar24._4_12_ = auVar22._4_12_;

      auVar24._0_4_ = auVar22._0_4_ * fVar5;

      fVar30 = (float)thunk_FUN_1402e1d00(auVar24._0_8_);

      fVar31 = (float)param_2[7] * (float)param_2[4];

      local_a0._0_3_ = CONCAT12((char)(int)fVar30,(undefined2)local_a0);

      if (0.0 <= fVar31) {

        auVar22 = ZEXT416((uint)fVar6);

        if (fVar31 <= fVar6) {

          auVar22 = ZEXT416((uint)fVar31);

        }

      }

      else {

        auVar22 = ZEXT816(0);

      }

      auVar25._4_12_ = auVar22._4_12_;

      auVar25._0_4_ = auVar22._0_4_ * fVar5;

      fVar31 = (float)thunk_FUN_1402e1d00(auVar25._0_8_);

      fVar30 = (float)param_2[8];

      local_a0 = CONCAT13((char)(int)fVar31,(undefined3)local_a0);

      if (0.0 <= fVar30) {

        auVar22 = ZEXT416((uint)fVar6);

        if (fVar30 <= fVar6) {

          auVar22 = ZEXT416((uint)fVar30);

        }

      }

      else {

        auVar22 = ZEXT816(0);

      }

      auVar26._4_12_ = auVar22._4_12_;

      auVar26._0_4_ = auVar22._0_4_ * fVar5;

      fVar30 = (float)thunk_FUN_1402e1d00(auVar26._0_8_);

      local_9c = (undefined1)(int)fVar30;

      uVar11 = local_a0;

      break;

    case 3:

      fVar30 = (float)param_2[5] * (float)param_2[4];

      if (0.0 <= fVar30) {

        auVar22 = ZEXT416((uint)fVar6);

        if (fVar30 <= fVar6) {

          auVar22 = ZEXT416((uint)fVar30);

        }

      }

      else {

        auVar22 = ZEXT816(0);

      }

      auVar22._0_4_ = auVar22._0_4_ * fVar5;

      fVar30 = (float)thunk_FUN_1402e1d00(auVar22._0_8_);

      fVar31 = (float)param_2[6] * (float)param_2[4];

      if (0.0 <= fVar31) {

        auVar22 = ZEXT416((uint)fVar6);

        if (fVar31 <= fVar6) {

          auVar22 = ZEXT416((uint)fVar31);

        }

      }

      else {

        auVar22 = ZEXT816(0);

      }

      auVar27._4_12_ = auVar22._4_12_;

      auVar27._0_4_ = auVar22._0_4_ * fVar5;

      fVar31 = (float)thunk_FUN_1402e1d00(auVar27._0_8_);

      fVar32 = (float)param_2[7] * (float)param_2[4];

      if (0.0 <= fVar32) {

        auVar22 = ZEXT416((uint)fVar6);

        if (fVar32 <= fVar6) {

          auVar22 = ZEXT416((uint)fVar32);

        }

      }

      else {

        auVar22 = ZEXT816(0);

      }

      auVar28._4_12_ = auVar22._4_12_;

      auVar28._0_4_ = auVar22._0_4_ * fVar5;

      fVar21 = (float)thunk_FUN_1402e1d00(auVar28._0_8_);

      fVar32 = (float)param_2[8];

      if (0.0 <= fVar32) {

        auVar22 = ZEXT416((uint)fVar6);

        if (fVar32 <= fVar6) {

          auVar22 = ZEXT416((uint)fVar32);

        }

      }

      else {

        auVar22 = ZEXT816(0);

      }

      auVar29._4_12_ = auVar22._4_12_;

      auVar29._0_4_ = auVar22._0_4_ * fVar5;

      fVar32 = (float)thunk_FUN_1402e1d00(auVar29._0_8_);

      FUN_1401485c0(lVar14,0);

      in_stack_fffffffffffffef8 =

           CONCAT71((int7)((ulonglong)in_stack_fffffffffffffef8 >> 8),(char)(int)fVar32);

      uVar11 = FUN_140146f80(lVar14,(int)fVar30 & 0xff,(int)fVar31 & 0xff,(int)fVar21 & 0xff,

                             in_stack_fffffffffffffef8);

      FUN_14017dc90(lVar14,0,uVar11);

      local_a0 = CONCAT31(local_a0._1_3_,1);

      uVar11 = local_a0;

      break;

    case 4:

      lVar17 = *(longlong *)(param_2 + 2) + param_3;

      iVar1 = param_2[4];

      iVar2 = param_2[0xb];

      FUN_140202650(lVar14,&local_b0);

      if ((local_b0 != (int *)0x0) &&

         (((*local_b0 != 0 || (local_b0[1] != 0)) && (lVar20 = 0, 0 < iVar1)))) {

        do {

          piVar19 = (int *)(lVar17 + lVar20 * 8);

          *piVar19 = *piVar19 + *local_b0;

          piVar19 = (int *)(lVar17 + 4 + lVar20 * 8);

          *piVar19 = *piVar19 + local_b0[1];

          lVar20 = lVar20 + 1;

        } while (lVar20 < iVar1);

      }

      uVar33 = (undefined7)((ulonglong)in_stack_fffffffffffffef8 >> 8);

      if (iVar2 == 0) {

        in_stack_fffffffffffffef8 = CONCAT71(uVar33,uVar4);

        uVar11 = FUN_140146f80(lVar14,uVar7,uVar8,uVar9,in_stack_fffffffffffffef8);

        FUN_14025fd90(lVar14,lVar17,iVar1,uVar11);

        uVar11 = local_a0;

      }

      else {

        in_stack_ffffffffffffff10 =

             (int *)CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff10 >> 8),uVar4);

        in_stack_fffffffffffffef8 = CONCAT71(uVar33,uVar7);

        FUN_14025ea00(lVar14,lVar17,iVar1,iVar2,in_stack_fffffffffffffef8,uVar8,uVar9,

                      in_stack_ffffffffffffff10);

        uVar11 = local_a0;

      }

      break;

    case 5:

      lVar17 = *(longlong *)(param_2 + 2) + param_3;

      iVar1 = param_2[4];

      iVar2 = param_2[0xb];

      FUN_140202650(lVar14,&local_b0);

      if (((local_b0 != (int *)0x0) && ((*local_b0 != 0 || (local_b0[1] != 0)))) &&

         (lVar20 = 0, 0 < iVar1)) {

        do {

          piVar19 = (int *)(lVar17 + lVar20 * 8);

          *piVar19 = *piVar19 + *local_b0;

          piVar19 = (int *)(lVar17 + 4 + lVar20 * 8);

          *piVar19 = *piVar19 + local_b0[1];

          lVar20 = lVar20 + 1;

        } while (lVar20 < iVar1);

      }

      uVar33 = (undefined7)((ulonglong)in_stack_fffffffffffffef8 >> 8);

      if (iVar2 == 0) {

        in_stack_fffffffffffffef8 = CONCAT71(uVar33,uVar4);

        uVar11 = FUN_140146f80(lVar14,uVar7,uVar8,uVar9,in_stack_fffffffffffffef8);

        FUN_14025faf0(lVar14,lVar17,iVar1,uVar11);

        uVar11 = local_a0;

      }

      else {

        in_stack_ffffffffffffff10 =

             (int *)CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff10 >> 8),uVar4);

        in_stack_fffffffffffffef8 = CONCAT71(uVar33,uVar7);

        FUN_14025bce0(lVar14,lVar17,iVar1,iVar2,in_stack_fffffffffffffef8,uVar8,uVar9,

                      in_stack_ffffffffffffff10);

        uVar11 = local_a0;

      }

      break;

    case 6:

      piVar19 = (int *)(*(longlong *)(param_2 + 2) + param_3);

      iVar1 = param_2[4];

      lVar17 = (longlong)iVar1;

      iVar2 = param_2[0xb];

      FUN_140202650(lVar14,&local_b0);

      if (((local_b0 != (int *)0x0) && ((*local_b0 != 0 || (local_b0[1] != 0)))) &&

         (piVar16 = piVar19, 0 < iVar1)) {

        do {

          *piVar16 = *piVar16 + *local_b0;

          piVar16[1] = piVar16[1] + local_b0[1];

          lVar17 = lVar17 + -1;

          piVar16 = piVar16 + 4;

        } while (lVar17 != 0);

      }

      uVar33 = (undefined7)((ulonglong)in_stack_fffffffffffffef8 >> 8);

      if (iVar2 == 0) {

        in_stack_fffffffffffffef8 = CONCAT71(uVar33,uVar4);

        uVar11 = FUN_140146f80(lVar14,uVar7,uVar8,uVar9,in_stack_fffffffffffffef8);

        FUN_14017dd30(lVar14,piVar19,iVar1,uVar11);

        uVar11 = local_a0;

      }

      else {

        in_stack_ffffffffffffff10 =

             (int *)CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff10 >> 8),uVar4);

        in_stack_fffffffffffffef8 = CONCAT71(uVar33,uVar7);

        FUN_14024af20(lVar14,piVar19,iVar1,iVar2,in_stack_fffffffffffffef8,uVar8,uVar9,

                      in_stack_ffffffffffffff10);

        uVar11 = local_a0;

      }

      break;

    case 7:

      lVar20 = *(longlong *)(param_2 + 2) + param_3;

      lVar17 = *(longlong *)(*(longlong *)(param_2 + 0xc) + 0x138);

      FUN_140202650(lVar14,&local_b0);

      FUN_140200260(param_2,&local_b0);

      if ((local_b0 != (int *)0x0) && ((*local_b0 != 0 || (local_b0[1] != 0)))) {

        *(int *)(lVar20 + 0x10) = *(int *)(lVar20 + 0x10) + *local_b0;

        *(int *)(lVar20 + 0x14) = *(int *)(lVar20 + 0x14) + local_b0[1];

      }

      if ((*(int *)(lVar20 + 8) == *(int *)(lVar20 + 0x18)) &&

         (*(int *)(lVar20 + 0xc) == *(int *)(lVar20 + 0x1c))) {

        FUN_140144390(lVar17,lVar20,lVar14,lVar20 + 0x10);

        uVar11 = local_a0;

      }

      else if ((*(int *)(lVar20 + 0x10) < 0) ||

              (((*(int *)(lVar20 + 0x14) < 0 ||

                (*(int *)(lVar14 + 8) < *(int *)(lVar20 + 0x10) + *(int *)(lVar20 + 0x18))) ||

               (*(int *)(lVar14 + 0xc) < *(int *)(lVar20 + 0x14) + *(int *)(lVar20 + 0x1c))))) {

        uVar13 = *(uint *)(lVar17 + 4);

        if ((uVar13 == 0) || ((uVar13 & 0xf0000000) == 0x10000000)) {

          if ((((uVar13 & 0xf000000) != 0x4000000) &&

              (((uVar13 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0)) ||

             (((uVar12 = uVar13 & 0xf00000, uVar12 != 0x300000 && (uVar12 != 0x400000)) &&

              ((uVar12 != 0x700000 && (uVar12 != 0x800000)))))) {

            if (uVar13 != 0) goto LAB_140201e89;

            goto LAB_140201e97;

          }

LAB_140201ee1:

          uVar11 = 0x16362004;

        }

        else {

LAB_140201e89:

          if ((uVar13 & 0xf0000000) == 0x10000000) {

LAB_140201e97:

            uVar13 = *(uint *)(lVar17 + 4) & 0xf000000;

            if (((uVar13 == 0x7000000) || ((uVar13 + 0xf8000000 & 0xfcffffff) == 0)) &&

               ((uVar13 = *(uint *)(lVar17 + 4) & 0xf00000, uVar13 == 0x300000 ||

                (((uVar13 == 0x200000 || (uVar13 == 0x600000)) || (uVar13 == 0x500000))))))

            goto LAB_140201ee1;

          }

          uVar11 = *(undefined4 *)(lVar14 + 4);

        }

        lVar15 = FUN_140145e60(*(undefined4 *)(lVar20 + 0x18),*(undefined4 *)(lVar20 + 0x1c),uVar11)

        ;

        uVar34 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);

        uVar11 = local_a0;

        if (lVar15 != 0) {

          FUN_1401465d0(lVar17,local_88);

          FUN_140146570(lVar17,local_b3);

          FUN_1401467d0(lVar17,&local_b4,&local_b5,&local_b6);

          local_78 = *(undefined4 *)(lVar20 + 0x18);

          local_74 = *(undefined4 *)(lVar20 + 0x1c);

          local_80 = 0;

          FUN_140148450(lVar17,0);

          FUN_1401486f0(lVar17,0xff,0xff);

          FUN_1401483d0(lVar17,0xff);

          in_stack_fffffffffffffef8 = CONCAT44(uVar34,param_2[0xe]);

          FUN_140143490(lVar17,lVar20,lVar15,&local_80,in_stack_fffffffffffffef8);

          FUN_1401486f0(lVar15,local_b4,local_b5,local_b6);

          FUN_1401483d0(lVar15,local_b3[0]);

          FUN_140148450(lVar15,local_88[0]);

          FUN_140144390(lVar15,0,lVar14,lVar20 + 0x10);

          FUN_140146010(lVar15);

          uVar11 = local_a0;

        }

      }

      else {

        in_stack_fffffffffffffef8 =

             CONCAT44((int)((ulonglong)in_stack_fffffffffffffef8 >> 0x20),param_2[0xe]);

        FUN_140143490(lVar17,lVar20,lVar14,lVar20 + 0x10,in_stack_fffffffffffffef8);

        uVar11 = local_a0;

      }

      break;

    case 8:

      lVar17 = *(longlong *)(param_2 + 2) + param_3;

      FUN_140202650(lVar14,&local_b0);

      FUN_140200260(param_2,&local_b0);

      if (((local_b0 != (int *)0x0) &&

          (((*local_b0 != 0 || (local_b0[1] != 0)) && (0.0 < *(float *)(lVar17 + 0x34))))) &&

         (0.0 < *(float *)(lVar17 + 0x38))) {

        *(int *)(lVar17 + 0x10) =

             *(int *)(lVar17 + 0x10) + (int)((float)*local_b0 / *(float *)(lVar17 + 0x34));

        *(int *)(lVar17 + 0x14) =

             *(int *)(lVar17 + 0x14) + (int)((float)local_b0[1] / *(float *)(lVar17 + 0x38));

      }

      in_stack_fffffffffffffef8 = lVar17 + 0x10;

      in_stack_ffffffffffffff10 = (int *)CONCAT44(uVar34,*(undefined4 *)(lVar17 + 0x30));

      FUN_140201160(param_1,lVar14,*(undefined8 *)(param_2 + 0xc),lVar17,in_stack_fffffffffffffef8,

                    *(undefined8 *)(lVar17 + 0x20),lVar17 + 0x28,in_stack_ffffffffffffff10,

                    *(undefined4 *)(lVar17 + 0x34),*(undefined4 *)(lVar17 + 0x38),param_2[0xe]);

      uVar11 = local_a0;

      break;

    case 9:

      iVar1 = param_2[4];

      lVar20 = (longlong)iVar1;

      piVar19 = (int *)(*(longlong *)(param_2 + 2) + param_3);

      iVar2 = param_2[0xb];

      lVar17 = *(longlong *)(param_2 + 0xc);

      FUN_140202650(lVar14,&local_b0);

      if (lVar17 == 0) {

        if ((local_b0 != (int *)0x0) && ((*local_b0 != 0 || (local_b0[1] != 0)))) {

          local_8c = local_b0[1];

          local_90 = *local_b0;

          FUN_140263160(&local_90);

          piVar16 = piVar19;

          uVar11 = local_a0;

          if (iVar1 < 1) break;

          do {

            *piVar16 = *piVar16 + local_90;

            piVar16[1] = piVar16[1] + local_8c;

            lVar20 = lVar20 + -1;

            piVar16 = piVar16 + 3;

          } while (lVar20 != 0);

        }

        uVar11 = local_a0;

        if (0 < iVar1) {

          piVar19 = piVar19 + 5;

          uVar18 = (ulonglong)((iVar1 - 1U) / 3 + 1);

          do {

            in_stack_ffffffffffffff10 =

                 (int *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff10 >> 0x20),piVar19[3]);

            in_stack_fffffffffffffef8 =

                 CONCAT44((int)((ulonglong)in_stack_fffffffffffffef8 >> 0x20),iVar2);

            FUN_140261db0(lVar14,piVar19 + -5,piVar19 + -2,piVar19 + 1,in_stack_fffffffffffffef8,

                          piVar19[-3],*piVar19,in_stack_ffffffffffffff10);

            piVar19 = piVar19 + 9;

            uVar18 = uVar18 - 1;

            uVar11 = local_a0;

          } while (uVar18 != 0);

        }

      }

      else {

        uVar3 = *(undefined8 *)(lVar17 + 0x138);

        FUN_140200260(param_2,&local_b0);

        if ((local_b0 != (int *)0x0) && ((*local_b0 != 0 || (local_b0[1] != 0)))) {

          local_94 = local_b0[1];

          local_98 = *local_b0;

          FUN_140263160(&local_98);

          uVar11 = local_a0;

          if (iVar1 < 1) break;

          piVar16 = piVar19 + 3;

          do {

            piVar16[-1] = piVar16[-1] + local_98;

            *piVar16 = *piVar16 + local_94;

            piVar16 = piVar16 + 5;

            lVar20 = lVar20 + -1;

          } while (lVar20 != 0);

        }

        uVar11 = local_a0;

        if (0 < iVar1) {

          piVar19 = piVar19 + 9;

          uVar18 = (ulonglong)((iVar1 - 1U) / 3 + 1);

          do {

            in_stack_ffffffffffffff10 = piVar19 + 3;

            in_stack_fffffffffffffef8 = lVar14;

            FUN_140260da0(uVar3,piVar19 + -9,piVar19 + -4,piVar19 + 1,lVar14,piVar19 + -7,

                          piVar19 + -2,in_stack_ffffffffffffff10,piVar19[-5],*piVar19,piVar19[5],

                          param_2[0xf],param_2[0x10]);

            piVar19 = piVar19 + 0xf;

            uVar18 = uVar18 - 1;

            uVar11 = local_a0;

          } while (uVar18 != 0);

        }

      }

    }

    local_a0 = uVar11;

    param_2 = *(int **)(param_2 + 0x14);

    uVar11 = local_a0;

    uVar4 = local_9c;

  } while( true );

}




