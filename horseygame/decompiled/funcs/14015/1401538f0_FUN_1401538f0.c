// Address: 0x1401538f0
// Ghidra name: FUN_1401538f0
// ============ 0x1401538f0 FUN_1401538f0 (size=2705) ============


char FUN_1401538f0(longlong param_1,longlong param_2,longlong param_3,int param_4,

                  undefined4 *param_5,int param_6,longlong param_7,int param_8,int param_9,

                  longlong param_10,float param_11,float param_12)



{

  void *_Buf1;

  undefined4 uVar1;

  undefined4 uVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  byte bVar9;

  char cVar10;

  int iVar11;

  uint uVar12;

  float fVar13;

  undefined4 *puVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  undefined8 uVar24;

  undefined4 uVar26;

  undefined4 *puVar25;

  char local_138;

  float local_134;

  undefined8 local_130;

  float local_128;

  float local_120;

  undefined8 local_118;

  float local_110;

  float local_10c;

  uint local_108;

  undefined4 local_104;

  undefined4 local_100;

  undefined4 local_fc;

  undefined4 local_f8;

  undefined4 local_f4;

  longlong local_f0;

  float local_e8;

  float local_e0;

  float local_dc;

  float local_d8;

  float local_d4;

  longlong local_d0;

  

  iVar11 = param_9;

  if (param_10 != 0) {

    iVar11 = (int)param_11;

  }

  param_11 = 0.0;

  local_134 = 0.0;

  local_138 = '\x01';

  uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x138) + 0x90);

  uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 0x138) + 0x94);

  local_104 = 0;

  local_f4 = 0;

  local_f8 = 0;

  local_fc = 0;

  local_100 = 0;

  FUN_14014e2b0(param_1,&local_104);

  puVar25 = &local_100;

  FUN_14014e350(param_1,&local_f4,&local_f8,&local_fc,puVar25);

  fVar22 = 0.0;

  fVar23 = 0.0;

  if (param_2 != 0) {

    FUN_14014f600(param_2,&param_11,&local_134);

    fVar22 = param_11;

    fVar23 = local_134;

  }

  fVar8 = DAT_14039ca80;

  fVar7 = DAT_14039ca44;

  uVar26 = (undefined4)((ulonglong)puVar25 >> 0x20);

  local_130 = 0xffffffffffffffff;

  fVar15 = -NAN;

  fVar21 = -NAN;

  local_128 = -NAN;

  local_e8 = 0.0;

  if (param_10 != 0) {

    local_e8 = param_12;

  }

  param_11 = 0.0;

  cVar10 = '\x01';

  if (iVar11 < 1) goto LAB_14015431a;

  local_d0 = (longlong)iVar11;

  local_f0 = 0;

LAB_140153a90:

  fVar18 = -NAN;

  fVar19 = -NAN;

  param_12 = -NAN;

  fVar20 = -NAN;

  fVar17 = -NAN;

  if (local_e8 == 5.60519e-45) {

    fVar13 = *(float *)(param_10 + 4 + local_f0 * 4);

    fVar16 = *(float *)(param_10 + local_f0 * 4);

    local_134 = *(float *)(param_10 + 8 + local_f0 * 4);

    local_120 = fVar13;

  }

  else if (local_e8 == 2.8026e-45) {

    fVar13 = (float)(uint)*(ushort *)(param_10 + 2 + local_f0 * 2);

    fVar16 = (float)(uint)*(ushort *)(param_10 + local_f0 * 2);

    local_134 = (float)(uint)*(ushort *)(param_10 + 4 + local_f0 * 2);

    local_120 = fVar13;

  }

  else if (local_e8 == 1.4013e-45) {

    fVar13 = (float)(uint)*(byte *)(param_10 + 1 + local_f0);

    fVar16 = (float)(uint)*(byte *)(param_10 + local_f0);

    local_134 = (float)(uint)*(byte *)(param_10 + 2 + local_f0);

    local_120 = fVar13;

  }

  else {

    uVar24 = CONCAT44((int)((ulonglong)puVar25 >> 0x20),param_4);

    fVar16 = (float)FUN_140157080(&local_130,param_11,param_2,param_3,uVar24,param_5,param_6,param_7

                                  ,param_8);

    uVar24 = CONCAT44((int)((ulonglong)uVar24 >> 0x20),param_4);

    fVar13 = (float)FUN_140157080(&local_130,(int)param_11 + 1,param_2,param_3,uVar24,param_5,

                                  param_6,param_7,param_8);

    puVar25 = (undefined4 *)CONCAT44((int)((ulonglong)uVar24 >> 0x20),param_4);

    local_120 = fVar13;

    local_134 = (float)FUN_140157080(&local_130,(int)param_11 + 2,param_2,param_3,puVar25,param_5,

                                     param_6,param_7,param_8);

    fVar21 = local_130._4_4_;

    fVar15 = (float)local_130;

  }

  if (fVar15 != -NAN) {

    iVar11 = 0;

    if (((local_128 == fVar16) || (local_128 == fVar13)) || (local_128 == local_134)) {

      iVar11 = 1;

    }

    if (((fVar21 == fVar16) || (fVar21 == fVar13)) || (fVar21 == local_134)) {

      iVar11 = iVar11 + 1;

    }

    if (((fVar15 == fVar16) || (fVar15 == fVar13)) || (fVar15 == local_134)) {

      iVar11 = iVar11 + 1;

    }

    local_108 = (uint)(iVar11 == 2);

    uVar12 = local_108;

    if (iVar11 != 2) {

LAB_140153e13:

      if (uVar12 == 0) goto LAB_140154160;

      _Buf1 = (void *)((longlong)((int)fVar18 * param_6) + (longlong)param_5);

      iVar11 = memcmp(_Buf1,(void *)((longlong)param_5 + (longlong)((int)fVar17 * param_6)),0x10);

      if (iVar11 != 0) {

LAB_14015415c:

        fVar15 = (float)local_130;

        goto LAB_140154160;

      }

      iVar11 = memcmp(_Buf1,(void *)((longlong)param_5 + (longlong)((int)fVar19 * param_6)),0x10);

      if (iVar11 != 0) goto LAB_14015415c;

      iVar11 = memcmp(_Buf1,(void *)((longlong)param_5 + (longlong)((int)fVar20 * param_6)),0x10);

      uVar26 = (undefined4)((ulonglong)puVar25 >> 0x20);

      if ((iVar11 != 0) ||

         ((param_7 != 0 &&

          (((((fVar21 = *(float *)((int)fVar18 * param_6 + param_7), fVar21 < 0.0 ||

              (fVar7 < fVar21)) ||

             (fVar21 = *(float *)((int)fVar17 * param_6 + param_7), fVar21 < 0.0)) ||

            ((fVar7 < fVar21 || (fVar21 = *(float *)((int)fVar19 * param_6 + param_7), fVar21 < 0.0)

             ))) || ((fVar7 < fVar21 ||

                     ((fVar21 = *(float *)((int)fVar20 * param_6 + param_7), fVar21 < 0.0 ||

                      (fVar7 < fVar21)))))))))) goto LAB_14015415c;

      puVar14 = (undefined4 *)((longlong)((int)fVar16 * param_6) + (longlong)param_5);

      if (param_2 == 0) {

        local_10c = 0.0;

        local_110 = 0.0;

        local_118 = 0;

      }

      else {

        fVar21 = fVar22 * *(float *)((int)param_12 * param_8 + param_7);

        local_10c = fVar23 * *(float *)((longlong)((int)param_12 * param_8) + 4 + param_7);

        local_110 = fVar22 * *(float *)((int)fVar17 * param_8 + param_7) - fVar21;

        local_118 = CONCAT44(local_10c,fVar21);

        local_10c = fVar23 * *(float *)((longlong)((int)fVar17 * param_8) + 4 + param_7) - local_10c

        ;

      }

      local_e0 = *(float *)((int)param_12 * param_4 + param_3);

      local_dc = *(float *)((longlong)((int)param_12 * param_4) + 4 + param_3);

      local_d8 = *(float *)((int)fVar17 * param_4 + param_3) - local_e0;

      local_d4 = *(float *)((longlong)((int)fVar17 * param_4) + 4 + param_3) - local_dc;

      if (((param_2 == 0) || (local_110 == 0.0)) || (local_10c == 0.0)) {

        if ((local_d8 != 0.0) && (local_d4 != 0.0)) {

          FUN_140154710(param_1,1);

          puVar25 = (undefined4 *)CONCAT44(uVar26,puVar14[3]);

          FUN_1401547e0(param_1,*puVar14,puVar14[1],puVar14[2],puVar25);

          FUN_140150100(param_1,&local_e0);

        }

      }

      else {

        FUN_140154f00(param_2,puVar14[3]);

        FUN_140155060(param_2,*puVar14,puVar14[1],puVar14[2]);

        if ((local_110 <= 0.0) || (local_10c <= 0.0)) {

          bVar9 = local_110 < 0.0;

          if ((bool)bVar9) {

            local_110 = local_110 * fVar8;

            local_118 = CONCAT44(local_118._4_4_,(float)local_118 - local_110);

          }

          if (local_10c < 0.0) {

            bVar9 = bVar9 | 2;

            local_10c = local_10c * fVar8;

            local_118 = CONCAT44(local_118._4_4_ - local_10c,(float)local_118);

          }

          puVar25 = (undefined4 *)0x0;

          FUN_1401529c0(param_1,param_2,&local_118,&local_e0,0,0,bVar9);

        }

        else {

          FUN_140153570(param_1,param_2,&local_118,&local_e0);

        }

      }

      fVar15 = -NAN;

      local_130 = CONCAT44(local_130._4_4_,0xffffffff);

      fVar21 = local_130._4_4_;

      goto LAB_140154233;

    }

    fVar19 = *(float *)((int)fVar16 * param_4 + param_3);

    fVar20 = *(float *)((int)fVar13 * param_4 + param_3);

    fVar3 = *(float *)((longlong)((int)fVar16 * param_4) + 4 + param_3);

    fVar4 = *(float *)((longlong)((int)fVar13 * param_4) + 4 + param_3);

    fVar5 = *(float *)((int)local_134 * param_4 + param_3);

    fVar6 = *(float *)((longlong)((int)local_134 * param_4) + 4 + param_3);

    if ((fVar20 < fVar19) || (fVar4 < fVar3)) {

      fVar18 = fVar13;

      fVar17 = fVar4;

      if (fVar20 <= fVar5) goto joined_r0x000140153cea;

LAB_140153cec:

      fVar18 = local_134;

    }

    else {

      fVar18 = fVar16;

      fVar17 = fVar3;

      if (fVar5 < fVar19) goto LAB_140153cec;

joined_r0x000140153cea:

      if (fVar6 < fVar17) goto LAB_140153cec;

    }

    if ((fVar19 < fVar20) || (fVar3 < fVar4)) {

      fVar17 = fVar13;

      fVar3 = fVar4;

      if (fVar5 <= fVar20) goto joined_r0x000140153d1a;

LAB_140153d1c:

      fVar17 = local_134;

    }

    else {

      fVar17 = fVar16;

      if (fVar19 < fVar5) goto LAB_140153d1c;

joined_r0x000140153d1a:

      if (fVar3 < fVar6) goto LAB_140153d1c;

    }

    if (((fVar16 == fVar18) || (fVar19 = fVar16, fVar16 == fVar17)) &&

       ((fVar13 == fVar18 || (fVar19 = fVar13, fVar13 == fVar17)))) {

      fVar19 = local_134;

    }

    if (((fVar15 == fVar18) || (fVar20 = fVar15, fVar15 == fVar17)) &&

       ((fVar21 == fVar18 || (fVar20 = fVar21, fVar21 == fVar17)))) {

      fVar20 = local_128;

    }

    fVar21 = *(float *)((int)fVar18 * param_4 + param_3);

    fVar13 = *(float *)((longlong)((int)fVar18 * param_4) + 4 + param_3);

    fVar4 = *(float *)((int)fVar17 * param_4 + param_3);

    fVar5 = *(float *)((longlong)((int)fVar17 * param_4) + 4 + param_3);

    fVar6 = *(float *)((int)fVar19 * param_4 + param_3);

    fVar3 = *(float *)((longlong)((int)fVar19 * param_4) + 4 + param_3);

    if (((fVar21 != fVar6) || (fVar5 != fVar3)) && ((fVar13 != fVar3 || (fVar4 != fVar6)))) {

      uVar12 = 0;

    }

    fVar6 = *(float *)((int)fVar20 * param_4 + param_3);

    fVar3 = *(float *)((longlong)((int)fVar20 * param_4) + 4 + param_3);

    param_12 = fVar18;

    if (((fVar21 == fVar6) && (fVar5 == fVar3)) || ((fVar13 == fVar3 && (fVar4 == fVar6))))

    goto LAB_140153e13;

LAB_140154160:

    fVar13 = local_120;

    if (fVar15 == -NAN) goto LAB_140154225;

    puVar25 = param_5;

    cVar10 = FUN_14014ac90(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,

                           &local_130,3,4,uVar1,uVar2,1,1);

    uVar26 = (undefined4)((ulonglong)puVar25 >> 0x20);

    fVar13 = local_120;

    local_138 = cVar10;

    if (cVar10 == '\0') goto LAB_14015431a;

  }

LAB_140154225:

  local_130 = CONCAT44(fVar13,fVar16);

  fVar21 = fVar13;

  fVar15 = fVar16;

  local_128 = local_134;

LAB_140154233:

  uVar26 = (undefined4)((ulonglong)puVar25 >> 0x20);

  param_11 = (float)((int)param_11 + 3);

  local_f0 = local_f0 + 3;

  if (local_d0 <= local_f0) goto code_r0x000140154258;

  goto LAB_140153a90;

code_r0x000140154258:

  cVar10 = local_138;

  if (fVar15 != -NAN) {

    cVar10 = FUN_14014ac90(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,

                           &local_130,3,4,uVar1,uVar2,1,1);

    uVar26 = (undefined4)((ulonglong)param_5 >> 0x20);

  }

LAB_14015431a:

  FUN_140154710(param_1,local_104);

  FUN_1401547e0(param_1,local_f4,local_f8,local_fc,CONCAT44(uVar26,local_100));

  return cVar10;

}




