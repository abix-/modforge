// Address: 0x140213f40
// Ghidra name: FUN_140213f40
// ============ 0x140213f40 FUN_140213f40 (size=1006) ============


void FUN_140213f40(float *param_1,float *param_2,float *param_3,float param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

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

  

  fVar11 = param_4 * param_4;

  fVar17 = fVar11 * param_4;

  fVar24 = param_4 * param_3[1] + *param_3 + fVar11 * param_3[2] + fVar17 * param_3[3];

  fVar23 = param_4 * param_3[5] + param_3[4] + fVar11 * param_3[6] + fVar17 * param_3[7];

  fVar22 = param_4 * param_3[9] + param_3[8] + fVar11 * param_3[10] + fVar17 * param_3[0xb];

  fVar21 = param_4 * param_3[0xd] + param_3[0xc] + fVar11 * param_3[0xe] + fVar17 * param_3[0xf];

  fVar20 = param_4 * param_3[0x11] + param_3[0x10] + fVar11 * param_3[0x12] + fVar17 * param_3[0x13]

  ;

  fVar19 = param_4 * param_3[0x15] + param_3[0x14] + fVar11 * param_3[0x16] + fVar17 * param_3[0x17]

  ;

  fVar18 = param_4 * param_3[0x19] + param_3[0x18] + fVar11 * param_3[0x1a] + fVar17 * param_3[0x1b]

  ;

  fVar16 = param_4 * param_3[0x1d] + param_3[0x1c] + fVar11 * param_3[0x1e] + fVar17 * param_3[0x1f]

  ;

  fVar15 = param_4 * param_3[0x21] + param_3[0x20] + fVar11 * param_3[0x22] + fVar17 * param_3[0x23]

  ;

  fVar14 = param_4 * param_3[0x25] + param_3[0x24] + fVar11 * param_3[0x26] + fVar17 * param_3[0x27]

  ;

  fVar1 = param_1[2];

  fVar12 = param_4 * param_3[0x2d] + param_3[0x2c] + fVar11 * param_3[0x2e] + fVar17 * param_3[0x2f]

  ;

  fVar13 = param_4 * param_3[0x29] + param_3[0x28] + fVar11 * param_3[0x2a] + fVar17 * param_3[0x2b]

  ;

  fVar11 = *param_1;

  fVar17 = param_1[4];

  fVar2 = param_1[6];

  fVar3 = param_1[8];

  fVar4 = param_1[10];

  fVar5 = param_1[0xc];

  fVar6 = param_1[0xe];

  fVar7 = param_1[0x10];

  fVar8 = param_1[0x12];

  fVar9 = param_1[0x14];

  fVar10 = param_1[0x16];

  param_2[1] = fVar24 * param_1[1] + 0.0 + fVar23 * param_1[3] + fVar22 * param_1[5] +

               fVar21 * param_1[7] + fVar20 * param_1[9] + fVar19 * param_1[0xb] +

               fVar18 * param_1[0xd] + fVar16 * param_1[0xf] + fVar15 * param_1[0x11] +

               fVar14 * param_1[0x13] + fVar13 * param_1[0x15] + fVar12 * param_1[0x17];

  *param_2 = fVar24 * fVar11 + 0.0 + fVar23 * fVar1 + fVar22 * fVar17 + fVar21 * fVar2 +

             fVar20 * fVar3 + fVar19 * fVar4 + fVar18 * fVar5 + fVar16 * fVar6 + fVar15 * fVar7 +

             fVar14 * fVar8 + fVar13 * fVar9 + fVar12 * fVar10;

  return;

}




