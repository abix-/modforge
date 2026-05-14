// Address: 0x140213710
// Ghidra name: FUN_140213710
// ============ 0x140213710 FUN_140213710 (size=1393) ============


void FUN_140213710(float *param_1,float *param_2,float *param_3,float param_4,int param_5)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float *pfVar4;

  float *pfVar5;

  float *pfVar6;

  float *pfVar7;

  float *pfVar8;

  float *pfVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  float fVar27;

  float fVar28;

  float fVar29;

  float fVar30;

  float fVar31;

  float fVar32;

  float fVar33;

  float fVar34;

  float fVar35;

  float fVar36;

  float fVar37;

  float fVar38;

  float fVar39;

  float fVar40;

  float fVar41;

  float *pfVar42;

  float *pfVar43;

  float *pfVar44;

  float *pfVar45;

  longlong lVar46;

  int iVar47;

  int iVar48;

  longlong lVar49;

  ulonglong uVar50;

  float fVar51;

  float fVar52;

  float fVar53;

  float fVar54;

  float fVar55;

  float fVar56;

  float fVar57;

  float fVar58;

  float fVar59;

  float fVar60;

  float fVar61;

  float fVar62;

  float fVar63;

  float fVar64;

  float fVar65;

  float fVar66;

  

  lVar49 = (longlong)param_5;

  fVar51 = param_4 * param_4;

  fVar52 = param_4 * param_4;

  fVar53 = param_4 * param_4;

  fVar54 = param_4 * param_4;

  fVar55 = fVar51 * param_4;

  fVar56 = fVar52 * param_4;

  fVar57 = fVar53 * param_4;

  fVar58 = fVar54 * param_4;

  fVar63 = param_4 * param_3[4] + *param_3 + fVar51 * param_3[8] + fVar55 * param_3[0xc];

  fVar64 = param_4 * param_3[5] + param_3[1] + fVar52 * param_3[9] + fVar56 * param_3[0xd];

  fVar65 = param_4 * param_3[6] + param_3[2] + fVar53 * param_3[10] + fVar57 * param_3[0xe];

  fVar66 = param_4 * param_3[7] + param_3[3] + fVar54 * param_3[0xb] + fVar58 * param_3[0xf];

  fVar59 = param_4 * param_3[0x14] + param_3[0x10] + fVar51 * param_3[0x18] + fVar55 * param_3[0x1c]

  ;

  fVar60 = param_4 * param_3[0x15] + param_3[0x11] + fVar52 * param_3[0x19] + fVar56 * param_3[0x1d]

  ;

  fVar61 = param_4 * param_3[0x16] + param_3[0x12] + fVar53 * param_3[0x1a] + fVar57 * param_3[0x1e]

  ;

  fVar62 = param_4 * param_3[0x17] + param_3[0x13] + fVar54 * param_3[0x1b] + fVar58 * param_3[0x1f]

  ;

  fVar51 = param_4 * param_3[0x24] + param_3[0x20] + fVar51 * param_3[0x28] + fVar55 * param_3[0x2c]

  ;

  fVar52 = param_4 * param_3[0x25] + param_3[0x21] + fVar52 * param_3[0x29] + fVar56 * param_3[0x2d]

  ;

  fVar53 = param_4 * param_3[0x26] + param_3[0x22] + fVar53 * param_3[0x2a] + fVar57 * param_3[0x2e]

  ;

  fVar54 = param_4 * param_3[0x27] + param_3[0x23] + fVar54 * param_3[0x2b] + fVar58 * param_3[0x2f]

  ;

  if (param_5 == 2) {

    *(ulonglong *)param_2 =

         CONCAT44(fVar62 * param_1[0xf] + fVar66 * param_1[7] + fVar54 * param_1[0x17] +

                  fVar60 * param_1[0xb] + fVar64 * param_1[3] + fVar52 * param_1[0x13] +

                  fVar61 * param_1[0xd] + fVar65 * param_1[5] + fVar53 * param_1[0x15] +

                  fVar59 * param_1[9] + fVar63 * param_1[1] + fVar51 * param_1[0x11],

                  fVar62 * param_1[0xe] + fVar66 * param_1[6] + fVar54 * param_1[0x16] +

                  fVar60 * param_1[10] + fVar64 * param_1[2] + fVar52 * param_1[0x12] +

                  fVar61 * param_1[0xc] + fVar65 * param_1[4] + fVar53 * param_1[0x14] +

                  fVar59 * param_1[8] + fVar63 * *param_1 + fVar51 * param_1[0x10]);

  }

  else if (param_5 == 1) {

    *param_2 = param_1[5] * fVar60 + param_1[1] * fVar64 + param_1[9] * fVar52 +

               param_1[4] * fVar59 + *param_1 * fVar63 + param_1[8] * fVar51 +

               param_1[7] * fVar62 + param_1[3] * fVar66 + param_1[0xb] * fVar54 +

               param_1[6] * fVar61 + param_1[2] * fVar65 + param_1[10] * fVar53;

  }

  else {

    iVar47 = 0;

    if (3 < param_5) {

      pfVar45 = param_1 + lVar49 * 10;

      iVar48 = 4;

      do {

        pfVar1 = pfVar45 + lVar49 * -9;

        fVar55 = pfVar1[1];

        fVar56 = pfVar1[2];

        fVar57 = pfVar1[3];

        iVar47 = iVar47 + 4;

        pfVar2 = pfVar45 + lVar49 * -7;

        fVar58 = pfVar2[1];

        fVar10 = pfVar2[2];

        fVar11 = pfVar2[3];

        pfVar42 = pfVar45 + -lVar49;

        iVar48 = iVar48 + 4;

        pfVar3 = pfVar45 + lVar49 * -5;

        fVar12 = pfVar3[1];

        fVar13 = pfVar3[2];

        fVar14 = pfVar3[3];

        pfVar4 = pfVar45 + lVar49 * -3;

        fVar15 = pfVar4[1];

        fVar16 = pfVar4[2];

        fVar17 = pfVar4[3];

        pfVar5 = pfVar45 + lVar49;

        fVar18 = pfVar5[1];

        fVar19 = pfVar5[2];

        fVar20 = pfVar5[3];

        fVar21 = pfVar42[1];

        fVar22 = pfVar42[2];

        fVar23 = pfVar42[3];

        pfVar6 = pfVar45 + lVar49 * -10;

        fVar24 = pfVar6[1];

        fVar25 = pfVar6[2];

        fVar26 = pfVar6[3];

        pfVar7 = pfVar45 + lVar49 * -8;

        fVar27 = pfVar7[1];

        fVar28 = pfVar7[2];

        fVar29 = pfVar7[3];

        pfVar8 = pfVar45 + lVar49 * -6;

        fVar30 = pfVar8[1];

        fVar31 = pfVar8[2];

        fVar32 = pfVar8[3];

        pfVar43 = pfVar45 + lVar49 * -4;

        fVar33 = pfVar43[1];

        fVar34 = pfVar43[2];

        fVar35 = pfVar43[3];

        pfVar44 = pfVar45 + lVar49 * -2;

        fVar36 = pfVar44[1];

        fVar37 = pfVar44[2];

        fVar38 = pfVar44[3];

        fVar39 = pfVar45[1];

        fVar40 = pfVar45[2];

        fVar41 = pfVar45[3];

        pfVar9 = (float *)((longlong)pfVar45 +

                          (longlong)param_2 + (lVar49 * -0x28 - (longlong)param_1));

        *pfVar9 = *pfVar1 * fVar64 + *pfVar2 * fVar66 + *pfVar3 * fVar60 + *pfVar4 * fVar62 +

                  *pfVar42 * fVar52 + *pfVar5 * fVar54 +

                  *pfVar6 * fVar63 + *pfVar7 * fVar65 + *pfVar8 * fVar59 + *pfVar43 * fVar61 +

                  *pfVar44 * fVar51 + fVar53 * *pfVar45;

        pfVar9[1] = fVar55 * fVar64 + fVar58 * fVar66 + fVar12 * fVar60 + fVar15 * fVar62 +

                    fVar21 * fVar52 + fVar18 * fVar54 +

                    fVar24 * fVar63 + fVar27 * fVar65 + fVar30 * fVar59 + fVar33 * fVar61 +

                    fVar36 * fVar51 + fVar53 * fVar39;

        pfVar9[2] = fVar56 * fVar64 + fVar10 * fVar66 + fVar13 * fVar60 + fVar16 * fVar62 +

                    fVar22 * fVar52 + fVar19 * fVar54 +

                    fVar25 * fVar63 + fVar28 * fVar65 + fVar31 * fVar59 + fVar34 * fVar61 +

                    fVar37 * fVar51 + fVar53 * fVar40;

        pfVar9[3] = fVar57 * fVar64 + fVar11 * fVar66 + fVar14 * fVar60 + fVar17 * fVar62 +

                    fVar23 * fVar52 + fVar20 * fVar54 +

                    fVar26 * fVar63 + fVar29 * fVar65 + fVar32 * fVar59 + fVar35 * fVar61 +

                    fVar38 * fVar51 + fVar53 * fVar41;

        pfVar45 = pfVar45 + 4;

      } while (iVar48 <= param_5);

    }

    if (iVar47 < param_5) {

      lVar46 = (longlong)(param_5 * 2);

      param_2 = param_2 + iVar47;

      param_1 = param_1 + lVar46 * 4 + (longlong)iVar47 + lVar49;

      uVar50 = (ulonglong)(uint)(param_5 - iVar47);

      do {

        pfVar45 = param_1 + lVar46 * -4;

        pfVar1 = param_1 + (lVar46 * -4 - lVar49);

        pfVar43 = (float *)((longlong)param_1 - (lVar46 * 4 + lVar49 * 4));

        pfVar2 = param_1 + (lVar46 * -3 - lVar49);

        pfVar3 = param_1 + (lVar46 * -2 - lVar49);

        pfVar4 = param_1 + lVar46 * -3;

        pfVar5 = param_1 + lVar46 * -2;

        pfVar44 = param_1 + -lVar46;

        fVar55 = *param_1;

        pfVar6 = param_1 + (lVar46 - lVar49);

        pfVar7 = param_1 + -lVar49;

        pfVar8 = param_1 + lVar46;

        param_1 = param_1 + 1;

        *param_2 = *pfVar45 * fVar64 + *pfVar5 * fVar60 + fVar55 * fVar52 +

                   *pfVar1 * fVar63 + *pfVar3 * fVar59 + *pfVar7 * fVar51 +

                   *pfVar4 * fVar66 + *pfVar44 * fVar62 + *pfVar8 * fVar54 +

                   *pfVar2 * fVar65 + *pfVar43 * fVar61 + *pfVar6 * fVar53;

        param_2 = param_2 + 1;

        uVar50 = uVar50 - 1;

      } while (uVar50 != 0);

    }

  }

  return;

}




