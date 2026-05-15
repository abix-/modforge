// Address: 0x1400aed30
// Ghidra name: FUN_1400aed30
// ============ 0x1400aed30 FUN_1400aed30 (size=2595) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400aed30(longlong param_1,longlong param_2,longlong param_3,longlong param_4,float param_5

                  )



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  char cVar5;

  longlong lVar6;

  undefined8 *puVar7;

  undefined8 uVar8;

  float fVar9;

  double dVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  uint uVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float local_e8;

  float local_e4;

  float local_e0;

  float local_dc;

  float local_d8;

  float local_d4;

  float local_d0;

  float local_cc;

  

  uVar14 = DAT_14039cac0;

  fVar15 = DAT_14039ca44;

  fVar13 = DAT_14039ca34;

  fVar18 = *(float *)(param_4 + 8);

  fVar17 = fVar18 * param_5;

  if (*(int *)(param_4 + 0x10) == 4) {

    fVar17 = (fVar17 + *(float *)(param_4 + 4)) * DAT_14030335c;

    fVar15 = fVar17 * *(float *)(param_4 + 0xc) * DAT_140303380;

    FUN_1400a9290(param_3,&DAT_1403f3168,fVar15,0,fVar17,2,DAT_14039ca44);

    fVar18 = DAT_14039ca34;

    fVar13 = fVar17 * DAT_14039ca34;

    FUN_1400a9360(param_3,&DAT_1403f3168,fVar15 - fVar13,

                  (float)((uint)fVar17 ^ DAT_14039cac0) * DAT_14039ca34,fVar17,fVar17,1,0);

    *(float *)(param_3 + 0xb0) = fVar13;

    FUN_1400b2cd0(param_1,0,fVar17,0);

    FUN_1400ae6b0(param_1,param_2,param_3,param_4 + 0x48,*(float *)(param_4 + 4) * fVar18,0);

    _DAT_1403f3168 = *(undefined8 *)((longlong)DAT_1403f3180 + -0x10);

    _DAT_1403f3170 = *(undefined8 *)((longlong)DAT_1403f3180 + -8);

    DAT_1403f3180 = (undefined8 *)((longlong)DAT_1403f3180 + -0x10);

  }

  else if ((*(float *)(param_4 + 0x40) == 0.0) && (*(float *)(param_4 + 0x44) == 0.0)) {

    fVar15 = DAT_14039ca80;

    if (param_5 == DAT_14039ca44) {

      fVar15 = DAT_14039ca44;

    }

    fVar15 = fVar15 * *(float *)(param_4 + 0xc) * fVar18 * DAT_140303374;

    if (((float)((uint)fVar15 & _DAT_14039cab0) <= DAT_14039ca0c) ||

       (fVar11 = *(float *)(param_4 + 4), fVar18 < fVar11 + fVar11)) {

      fVar18 = *(float *)(param_4 + 4);

      fVar15 = 0.0;

      FUN_1400a9560(param_3,&DAT_1403f3168,(float)((uint)fVar18 ^ DAT_14039cac0) * DAT_14039ca34,0,

                    fVar18,fVar17,*(undefined4 *)(param_4 + 0x30),*(undefined4 *)(param_4 + 0x34),

                    *(undefined4 *)(param_4 + 0x38),*(undefined4 *)(param_4 + 0x3c),DAT_14039ca44);

      fVar18 = fVar17;

    }

    else {

      uVar1 = *(undefined4 *)(param_4 + 0x38);

      fVar19 = (float)((uint)fVar11 ^ DAT_14039cac0) * DAT_14039ca34;

      fVar13 = DAT_14039ca44;

      if (fVar18 * fVar11 < DAT_14039ca0c) {

        fVar13 = DAT_14039ca0c / (fVar18 * fVar11);

      }

      fVar17 = fVar18 * DAT_14039ca34;

      FUN_1400a9360(param_3,&DAT_1403f3168,fVar19,0,fVar11,fVar17,uVar1,fVar13);

      lVar6 = FUN_1400a9180(param_3,uVar1,fVar13);

      fVar11 = fVar19 + fVar11;

      fVar12 = (fVar17 + 0.0) * DAT_1403f3174;

      fVar13 = (fVar17 + 0.0) * DAT_1403f3170;

      local_e4 = fVar19 * DAT_1403f3170 + fVar12 + DAT_1403f316c;

      local_e8 = (fVar19 * DAT_1403f3174 - fVar13) + DAT_1403f3168;

      fVar9 = (fVar18 + 0.0) * DAT_1403f3170;

      fVar16 = (fVar18 + 0.0) * DAT_1403f3174;

      local_e0 = (fVar11 * DAT_1403f3174 - fVar13) + DAT_1403f3168;

      local_dc = fVar11 * DAT_1403f3170 + fVar12 + DAT_1403f316c;

      local_d8 = ((fVar11 + fVar15) * DAT_1403f3174 - fVar9) + DAT_1403f3168;

      local_d4 = (fVar11 + fVar15) * DAT_1403f3170 + fVar16 + DAT_1403f316c;

      local_d0 = ((fVar19 + fVar15) * DAT_1403f3174 - fVar9) + DAT_1403f3168;

      local_cc = (fVar19 + fVar15) * DAT_1403f3170 + fVar16 + DAT_1403f316c;

      cVar5 = FUN_14000e0e0(lVar6,&local_e8,4);

      uVar14 = DAT_14039cac0;

      fVar13 = DAT_14039ca34;

      if (cVar5 == '\0') {

        *(undefined1 *)(lVar6 + 0x160) = 0;

        uVar14 = DAT_14039cac0;

        fVar13 = DAT_14039ca34;

      }

    }

    *(float *)(param_3 + 0xb0) = fVar17;

    fVar17 = DAT_140303358;

    if (*(char *)(param_4 + 0x4a) == '\0') {

      FUN_1400b2cd0(param_1,fVar15,fVar18,0);

      if (fVar15 == 0.0) {

        fVar15 = fVar18 - fVar17;

      }

      else {

        fVar15 = 0.0;

      }

      FUN_1400ae6b0(param_1,param_2,param_3,param_4 + 0x48,*(float *)(param_4 + 4) * fVar13,fVar15);

    }

    else {

      lVar6 = FUN_1400ab1b0(param_1,param_3,fVar15,fVar18,0);

      dVar10 = DAT_140304b50;

      if (fVar15 == 0.0) {

        dVar10 = 0.0;

      }

      FUN_1400ae6b0(param_1,param_2,lVar6,param_4 + 0x48,*(float *)(param_4 + 4) * fVar13,

                    (float)((double)*(float *)(param_2 + 0x34c) + dVar10));

      *(undefined1 *)(lVar6 + 0x84) = 1;

      *(undefined4 *)(lVar6 + 100) = 0;

      *(undefined4 *)(lVar6 + 0x68) = 0xc1f00000;

      *(undefined8 *)(lVar6 + 0x6c) = 0x41f00000;

      *(undefined8 *)(lVar6 + 0x74) = 0;

      *(undefined4 *)(lVar6 + 0x7c) = 0;

    }

    fVar15 = DAT_140303354;

    puVar7 = (undefined8 *)((longlong)DAT_1403f3180 + -0x10);

    _DAT_1403f3168 = *puVar7;

    _DAT_1403f3170 = *(undefined8 *)((longlong)DAT_1403f3180 + -8);

    DAT_1403f3180 = puVar7;

    if ((*(int *)(param_1 + 0xd0) == 0x21) && ((*DAT_1403f3190 & 2) == 0)) {

      fVar11 = fVar18 - DAT_140304b2c;

      if (fVar18 - DAT_140304b2c <= DAT_140303354) {

        fVar11 = DAT_140303354;

      }

      FUN_1400a9360(param_3,&DAT_1403f3168,(float)(*(uint *)(param_4 + 4) ^ uVar14) * fVar13,

                    fVar11 - DAT_140303354,*(uint *)(param_4 + 4),fVar17,0x10,0);

      lVar6 = FUN_1400ab1b0(param_1,param_3,0,fVar11,0);

      uVar4 = DAT_14039ca7c;

      uVar3 = DAT_14039ca2c;

      uVar2 = DAT_140304078;

      uVar1 = DAT_14030338c;

      FUN_1400a9360(lVar6,&DAT_1403f3168,DAT_14039ca7c,DAT_140304078,DAT_14039ca2c,fVar15,0x10,

                    DAT_14030338c);

      *(undefined1 *)(lVar6 + 0x84) = 1;

      *(undefined8 *)(lVar6 + 100) = 1;

      *(undefined8 *)(lVar6 + 0x6c) = 0;

      *(undefined8 *)(lVar6 + 0x74) = 0;

      *(undefined4 *)(lVar6 + 0x7c) = 0;

      lVar6 = FUN_1400ab1b0(param_1,lVar6,uVar4,0,0);

      FUN_1400a9360(lVar6,&DAT_1403f3168,uVar4,uVar2,uVar3,fVar15,0x10,uVar1);

      *(undefined1 *)(lVar6 + 0x84) = 1;

      *(undefined8 *)(lVar6 + 100) = 1;

      *(undefined8 *)(lVar6 + 0x6c) = 0;

      *(undefined8 *)(lVar6 + 0x74) = 0;

      *(undefined4 *)(lVar6 + 0x7c) = 0;

      lVar6 = FUN_1400ab1b0(param_1,lVar6,uVar4,0,0);

      FUN_1400a9360(lVar6,&DAT_1403f3168,uVar4,uVar2,uVar3,fVar15,0x10,uVar1);

      *(undefined1 *)(lVar6 + 0x84) = 1;

      *(undefined8 *)(lVar6 + 100) = 1;

      *(undefined8 *)(lVar6 + 0x6c) = 0;

      *(undefined8 *)(lVar6 + 0x74) = 0;

      *(undefined4 *)(lVar6 + 0x7c) = 0;

      lVar6 = FUN_1400ab1b0(param_1,lVar6,uVar4,0,0);

      FUN_1400a9360(lVar6,&DAT_1403f3168,uVar4,uVar2,uVar3,fVar15,0x10,uVar1);

      uVar1 = DAT_14030d9e8;

      *(undefined1 *)(lVar6 + 0x84) = 1;

      *(undefined8 *)(lVar6 + 100) = 1;

      *(undefined8 *)(lVar6 + 0x6c) = 0;

      *(undefined8 *)(lVar6 + 0x74) = 0;

      *(undefined4 *)(lVar6 + 0x7c) = 0;

      *(undefined4 *)(lVar6 + 0xc) = 0xf;

      uVar8 = FUN_1400ab1b0(param_1,lVar6,uVar1,uVar2,0);

      FUN_1400a9290(uVar8,&DAT_1403f3168,0,0,DAT_14030d954,0x10,fVar13);

      _DAT_1403f3168 = DAT_1403f3180[-2];

      _DAT_1403f3170 = DAT_1403f3180[-1];

      DAT_1403f3180 = DAT_1403f3180 + -2;

      *DAT_1403f3190 = *DAT_1403f3190 | 2;

      *(undefined1 *)(param_1 + 0x20) = 1;

    }

  }

  else {

    fVar17 = fVar17 * DAT_14039ca34;

    FUN_1400a9360(param_3,&DAT_1403f3168,

                  (float)(*(uint *)(param_4 + 4) ^ DAT_14039cac0) * DAT_14039ca34,0,

                  *(uint *)(param_4 + 4),fVar17,*(undefined4 *)(param_4 + 0x38),DAT_14039ca44);

    lVar6 = FUN_1400ab1b0(param_1,param_3,0,fVar17,*(undefined4 *)(param_3 + 0x48));

    FUN_1400a9360(lVar6,&DAT_1403f3168,(float)(*(uint *)(param_4 + 4) ^ DAT_14039cac0) * fVar13,0,

                  *(uint *)(param_4 + 4),fVar17,*(undefined4 *)(param_4 + 0x3c),fVar15);

    uVar1 = *(undefined4 *)(param_4 + 0x40);

    *(undefined4 *)(lVar6 + 0x6c) = *(undefined4 *)(param_4 + 0x44);

    *(undefined4 *)(lVar6 + 0x68) = uVar1;

    *(undefined1 *)(lVar6 + 0x84) = 1;

    *(undefined4 *)(lVar6 + 100) = 0;

    *(undefined8 *)(lVar6 + 0x70) = 0;

    *(undefined8 *)(lVar6 + 0x78) = 0;

    FUN_1400b2cd0(param_1,0,fVar17,0);

    FUN_1400ae6b0(param_1,param_2,lVar6,param_4 + 0x48,*(float *)(param_4 + 4) * fVar13,fVar17);

    _DAT_1403f3168 = *(undefined8 *)((longlong)DAT_1403f3180 + -0x20);

    _DAT_1403f3170 = *(undefined8 *)((longlong)DAT_1403f3180 + -0x18);

    DAT_1403f3180 = (undefined8 *)((longlong)DAT_1403f3180 + -0x20);

    *(float *)(param_3 + 0xb0) = fVar17;

    *(undefined1 *)(param_1 + 0x20) = 1;

  }

  return;

}




