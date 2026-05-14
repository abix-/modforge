// Address: 0x140213290
// Ghidra name: FUN_140213290
// ============ 0x140213290 FUN_140213290 (size=1151) ============


void FUN_140213290(longlong param_1,longlong param_2,float *param_3,float param_4,int param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

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

  float fVar42;

  float fVar43;

  float fVar44;

  float fVar45;

  float fVar46;

  float fVar47;

  float fVar48;

  float fVar49;

  float fVar50;

  float fVar51;

  int iVar52;

  int iVar53;

  int iVar54;

  int iVar55;

  int iVar56;

  int iVar57;

  int iVar58;

  int iVar59;

  longlong lVar60;

  int iVar61;

  longlong lVar62;

  float fVar63;

  float fVar64;

  

  fVar4 = param_3[1];

  fVar5 = param_3[5];

  fVar6 = param_3[9];

  fVar7 = *param_3;

  fVar8 = param_3[4];

  fVar9 = param_3[8];

  fVar10 = param_3[0xd];

  fVar11 = param_3[0x11];

  fVar12 = param_3[0x15];

  fVar13 = param_3[0x19];

  fVar14 = param_3[0xc];

  fVar15 = param_3[0x10];

  fVar16 = param_3[0x14];

  fVar17 = param_3[0x18];

  fVar18 = param_3[0x1d];

  fVar63 = param_4 * param_4;

  fVar19 = param_3[2];

  fVar64 = fVar63 * param_4;

  fVar20 = param_3[6];

  fVar21 = param_3[3];

  fVar22 = param_3[10];

  fVar23 = param_3[7];

  fVar24 = param_3[0xe];

  fVar25 = param_3[0xb];

  fVar26 = param_3[0x12];

  fVar27 = param_3[0xf];

  fVar28 = param_3[0x16];

  fVar29 = param_3[0x13];

  fVar30 = param_3[0x1a];

  fVar31 = param_3[0x17];

  fVar32 = param_3[0x1b];

  fVar33 = param_3[0x21];

  fVar34 = param_3[0x25];

  fVar35 = param_3[0x1e];

  fVar36 = param_3[0x1f];

  fVar37 = param_3[0x29];

  fVar38 = param_3[0x2d];

  fVar39 = param_3[0x1c];

  fVar40 = param_3[0x20];

  fVar41 = param_3[0x24];

  fVar42 = param_3[0x28];

  fVar43 = param_3[0x2c];

  fVar44 = param_3[0x22];

  fVar45 = param_3[0x23];

  fVar46 = param_3[0x26];

  fVar47 = param_3[0x27];

  fVar48 = param_3[0x2a];

  fVar49 = param_3[0x2e];

  fVar50 = param_3[0x2b];

  fVar51 = param_3[0x2f];

  if (0 < param_5) {

    lVar62 = 0;

    iVar61 = param_5 * 2;

    do {

      iVar52 = iVar61 + param_5 * -2;

      iVar53 = iVar61 - param_5;

      lVar60 = (longlong)iVar61;

      iVar54 = iVar61 + param_5;

      iVar55 = param_5 * 2 + iVar61;

      iVar56 = param_5 * 3 + iVar61;

      iVar57 = iVar61 + param_5 * 4;

      iVar58 = iVar61 + param_5 * 5;

      iVar59 = iVar61 + param_5 * 6;

      iVar1 = iVar61 + param_5 * 7;

      iVar2 = iVar61 + param_5 * 8;

      iVar3 = iVar61 + param_5 * 9;

      iVar61 = iVar61 + 1;

      *(float *)(param_2 + lVar62 * 4) =

           (param_4 * fVar4 + fVar7 + fVar63 * fVar19 + fVar64 * fVar21) *

           *(float *)(param_1 + (longlong)iVar52 * 4) + 0.0 +

           (param_4 * fVar5 + fVar8 + fVar63 * fVar20 + fVar64 * fVar23) *

           *(float *)(param_1 + (longlong)iVar53 * 4) +

           (param_4 * fVar6 + fVar9 + fVar63 * fVar22 + fVar64 * fVar25) *

           *(float *)(param_1 + lVar60 * 4) +

           (param_4 * fVar10 + fVar14 + fVar63 * fVar24 + fVar64 * fVar27) *

           *(float *)(param_1 + (longlong)iVar54 * 4) +

           (param_4 * fVar11 + fVar15 + fVar63 * fVar26 + fVar64 * fVar29) *

           *(float *)(param_1 + (longlong)iVar55 * 4) +

           (param_4 * fVar12 + fVar16 + fVar63 * fVar28 + fVar64 * fVar31) *

           *(float *)(param_1 + (longlong)iVar56 * 4) +

           (param_4 * fVar13 + fVar17 + fVar63 * fVar30 + fVar64 * fVar32) *

           *(float *)(param_1 + (longlong)iVar57 * 4) +

           (param_4 * fVar18 + fVar39 + fVar63 * fVar35 + fVar64 * fVar36) *

           *(float *)(param_1 + (longlong)iVar58 * 4) +

           (param_4 * fVar33 + fVar40 + fVar63 * fVar44 + fVar64 * fVar45) *

           *(float *)(param_1 + (longlong)iVar59 * 4) +

           (param_4 * fVar34 + fVar41 + fVar63 * fVar46 + fVar64 * fVar47) *

           *(float *)(param_1 + (longlong)iVar1 * 4) +

           (param_4 * fVar37 + fVar42 + fVar63 * fVar48 + fVar64 * fVar50) *

           *(float *)(param_1 + (longlong)iVar2 * 4) +

           (param_4 * fVar38 + fVar43 + fVar63 * fVar49 + fVar64 * fVar51) *

           *(float *)(param_1 + (longlong)iVar3 * 4);

      lVar62 = lVar62 + 1;

    } while (lVar62 < param_5);

  }

  return;

}




