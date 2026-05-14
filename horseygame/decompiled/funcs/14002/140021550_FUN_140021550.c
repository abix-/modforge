// Address: 0x140021550
// Ghidra name: FUN_140021550
// ============ 0x140021550 FUN_140021550 (size=4986) ============


void FUN_140021550(longlong param_1,float *param_2,longlong param_3,float *param_4,longlong param_5,

                  float *param_6)



{

  char cVar1;

  int iVar2;

  bool bVar3;

  bool bVar4;

  int iVar5;

  float fVar6;

  char cVar7;

  float *pfVar8;

  uint *puVar9;

  int iVar10;

  int iVar11;

  longlong lVar12;

  float *pfVar13;

  uint uVar14;

  ulonglong uVar15;

  float *pfVar16;

  ulonglong uVar17;

  ulonglong uVar18;

  ulonglong uVar19;

  int iVar20;

  ulonglong uVar21;

  uint uVar22;

  undefined8 uVar23;

  float fVar24;

  uint uVar25;

  float fVar26;

  uint uVar27;

  float fVar28;

  undefined4 uVar29;

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

  undefined8 local_f8;

  undefined4 local_f0;

  float local_ec;

  float local_e8;

  undefined4 local_e4;

  undefined8 local_e0;

  undefined4 local_d8;

  float local_d4;

  float local_d0;

  undefined4 local_cc;

  

  fVar24 = param_4[2];

  fVar39 = param_4[3];

  fVar30 = *param_6;

  fVar37 = *param_4;

  fVar31 = param_6[2];

  fVar32 = param_6[1];

  fVar33 = param_4[1];

  fVar35 = param_6[3];

  *(float *)(param_1 + 0x84) = (fVar30 - fVar37) * fVar39 + (fVar32 - fVar33) * fVar24;

  *(float *)(param_1 + 0x88) = (fVar32 - fVar33) * fVar39 - (fVar30 - fVar37) * fVar24;

  fVar30 = fVar31 * fVar24 + fVar39 * fVar35;

  *(float *)(param_1 + 0x8c) = fVar39 * fVar31 - fVar24 * fVar35;

  *(float *)(param_1 + 0x90) = fVar30;

  fVar24 = *(float *)(param_5 + 0x10);

  fVar39 = *(float *)(param_5 + 0x14);

  *(float *)(param_1 + 0x98) =

       fVar24 * *(float *)(param_1 + 0x8c) + fVar30 * *(float *)(param_5 + 0x14) +

       *(float *)(param_1 + 0x88);

  *(float *)(param_1 + 0x94) =

       (fVar30 * fVar24 - *(float *)(param_1 + 0x8c) * fVar39) + *(float *)(param_1 + 0x84);

  *(undefined8 *)(param_1 + 0x9c) = *(undefined8 *)(param_3 + 0x20);

  *(undefined8 *)(param_1 + 0xa4) = *(undefined8 *)(param_3 + 0x10);

  *(undefined8 *)(param_1 + 0xac) = *(undefined8 *)(param_3 + 0x18);

  *(undefined8 *)(param_1 + 0xb4) = *(undefined8 *)(param_3 + 0x28);

  fVar39 = *(float *)(param_1 + 0xac) - *(float *)(param_1 + 0xa4);

  fVar30 = *(float *)(param_1 + 0xb0) - *(float *)(param_1 + 0xa8);

  cVar7 = *(char *)(param_3 + 0x30);

  cVar1 = *(char *)(param_3 + 0x31);

  fVar24 = fVar30 * fVar30 + fVar39 * fVar39;

  if (fVar24 < 0.0) {

    fVar24 = (float)FUN_1402cdfa0(fVar24);

  }

  else {

    fVar24 = SQRT(fVar24);

  }

  uVar14 = DAT_14039cac0;

  fVar37 = DAT_14039ca44;

  if (DAT_14039c9f0 <= fVar24) {

    fVar30 = (DAT_14039ca44 / fVar24) * fVar30;

    fVar39 = (DAT_14039ca44 / fVar24) * fVar39;

  }

  pfVar8 = (float *)(param_1 + 0xc4);

  *pfVar8 = fVar30;

  bVar3 = false;

  *(uint *)(param_1 + 200) = (uint)fVar39 ^ uVar14;

  bVar4 = false;

  fVar32 = 0.0;

  fVar31 = 0.0;

  fVar24 = (*(float *)(param_1 + 0x94) - *(float *)(param_1 + 0xa4)) * fVar30 +

           (*(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xa8)) *

           (float)((uint)fVar39 ^ uVar14);

  if (cVar7 != '\0') {

    fVar33 = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0x9c);

    fVar35 = *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0xa0);

    fVar32 = fVar35 * fVar35 + fVar33 * fVar33;

    if (fVar32 < 0.0) {

      fVar32 = (float)FUN_1402cdfa0(fVar32);

    }

    else {

      fVar32 = SQRT(fVar32);

    }

    if (DAT_14039c9f0 <= fVar32) {

      fVar32 = fVar37 / fVar32;

      fVar35 = fVar32 * fVar35;

      fVar33 = fVar32 * fVar33;

    }

    *(float *)(param_1 + 0xbc) = fVar35;

    *(uint *)(param_1 + 0xc0) = (uint)fVar33 ^ uVar14;

    bVar3 = 0.0 <= fVar33 * fVar30 - fVar35 * fVar39;

    fVar32 = (*(float *)(param_1 + 0x94) - *(float *)(param_1 + 0x9c)) * fVar35 +

             (*(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xa0)) *

             (float)((uint)fVar33 ^ uVar14);

  }

  if (cVar1 != '\0') {

    fVar33 = *(float *)(param_1 + 0xb4) - *(float *)(param_1 + 0xac);

    fVar35 = *(float *)(param_1 + 0xb8) - *(float *)(param_1 + 0xb0);

    fVar31 = fVar35 * fVar35 + fVar33 * fVar33;

    if (fVar31 < 0.0) {

      fVar31 = (float)FUN_1402cdfa0(fVar31);

    }

    else {

      fVar31 = SQRT(fVar31);

    }

    if (DAT_14039c9f0 <= fVar31) {

      fVar37 = fVar37 / fVar31;

      fVar33 = fVar33 * fVar37;

      fVar35 = fVar35 * fVar37;

    }

    *(float *)(param_1 + 0xcc) = fVar35;

    *(uint *)(param_1 + 0xd0) = (uint)fVar33 ^ uVar14;

    bVar4 = 0.0 < fVar35 * fVar39 - fVar33 * fVar30;

    fVar31 = (*(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xb0)) *

             (float)((uint)fVar33 ^ uVar14) +

             (*(float *)(param_1 + 0x94) - *(float *)(param_1 + 0xac)) * fVar35;

  }

  puVar9 = (uint *)(param_1 + 0xc4);

  if (cVar7 == '\0') {

    if (cVar1 == '\0') {

      *(bool *)(param_1 + 0xf8) = 0.0 <= fVar24;

      if (0.0 > fVar24) {

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 200) ^ uVar14;

        *(uint *)(param_1 + 0xd4) = *puVar9 ^ uVar14;

        uVar22 = *(uint *)(param_1 + 200);

        *(uint *)(param_1 + 0xe4) = *puVar9;

        *(uint *)(param_1 + 0xe8) = uVar22;

        *(uint *)(param_1 + 0xec) = *puVar9;

        goto LAB_140022030;

      }

      *(undefined8 *)(param_1 + 0xd4) = *(undefined8 *)puVar9;

      *(uint *)(param_1 + 0xe4) = *puVar9 ^ uVar14;

      *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 200) ^ uVar14;

      *(uint *)(param_1 + 0xec) = *puVar9 ^ uVar14;

      *(uint *)(param_1 + 0xf0) = *(uint *)(param_1 + 200) ^ uVar14;

    }

    else if (bVar4) {

      if ((0.0 <= fVar24) || (0.0 <= fVar31)) {

        uVar29 = *(undefined4 *)(param_1 + 0xcc);

        uVar22 = *(uint *)(param_1 + 0xd0);

        *(undefined8 *)(param_1 + 0xd4) = *(undefined8 *)(param_1 + 0xc4);

        *(undefined1 *)(param_1 + 0xf8) = 1;

        uVar27 = *(uint *)(param_1 + 200);

        uVar25 = *(uint *)(param_1 + 0xc4) ^ uVar14;

      }

      else {

        uVar29 = *(undefined4 *)(param_1 + 0xc4);

        *(undefined1 *)(param_1 + 0xf8) = 0;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 200) ^ uVar14;

        uVar25 = *(uint *)(param_1 + 0xc4) ^ uVar14;

        *(uint *)(param_1 + 0xd4) = uVar25;

        uVar22 = *(uint *)(param_1 + 200);

        uVar27 = uVar22;

      }

      *(uint *)(param_1 + 0xe4) = uVar25;

      *(uint *)(param_1 + 0xe8) = uVar27 ^ uVar14;

      *(undefined4 *)(param_1 + 0xec) = uVar29;

      *(uint *)(param_1 + 0xf0) = uVar22;

    }

    else {

      if ((fVar24 < 0.0) || (fVar31 < 0.0)) {

        cVar7 = '\0';

      }

      else {

        cVar7 = '\x01';

      }

      *(char *)(param_1 + 0xf8) = cVar7;

      uVar22 = *(uint *)(param_1 + 0xc4);

      uVar27 = *(uint *)(param_1 + 200);

      if (cVar7 == '\0') {

        *(uint *)(param_1 + 0xd4) = uVar22 ^ uVar14;

        *(uint *)(param_1 + 0xd8) = uVar27 ^ uVar14;

        *(uint *)(param_1 + 0xe4) = *(uint *)(param_1 + 0xcc) ^ uVar14;

        *(undefined8 *)(param_1 + 0xec) = *(undefined8 *)(param_1 + 0xc4);

        *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 0xd0) ^ uVar14;

      }

      else {

        *(uint *)(param_1 + 0xd4) = uVar22;

        *(uint *)(param_1 + 0xd8) = uVar27;

        *(uint *)(param_1 + 0xe4) = uVar22 ^ uVar14;

        *(uint *)(param_1 + 0xe8) = uVar27 ^ uVar14;

        *(uint *)(param_1 + 0xec) = uVar22;

        *(uint *)(param_1 + 0xf0) = uVar27;

      }

    }

  }

  else if (cVar1 == '\0') {

    if (bVar3) {

      if ((0.0 <= fVar32) || (0.0 <= fVar24)) {

        *(undefined8 *)(param_1 + 0xe4) = *(undefined8 *)(param_1 + 0xbc);

        *(undefined8 *)(param_1 + 0xd4) = *(undefined8 *)(param_1 + 0xc4);

        *(undefined1 *)(param_1 + 0xf8) = 1;

        uVar25 = *(uint *)(param_1 + 0xc4) ^ uVar14;

      }

      else {

        *(undefined1 *)(param_1 + 0xf8) = 0;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 200) ^ uVar14;

        uVar25 = *(uint *)(param_1 + 0xc4) ^ uVar14;

        *(undefined8 *)(param_1 + 0xe4) = *(undefined8 *)(param_1 + 0xc4);

        *(uint *)(param_1 + 0xd4) = uVar25;

      }

      uVar22 = *(uint *)(param_1 + 200);

    }

    else {

      if ((fVar32 < 0.0) || (fVar24 < 0.0)) {

        cVar7 = '\0';

      }

      else {

        cVar7 = '\x01';

      }

      *(char *)(param_1 + 0xf8) = cVar7;

      uVar27 = *(uint *)(param_1 + 0xc4);

      uVar22 = *(uint *)(param_1 + 200);

      uVar25 = uVar27 ^ uVar14;

      if (cVar7 == '\0') {

        *(uint *)(param_1 + 0xd4) = uVar25;

        *(uint *)(param_1 + 0xd8) = uVar22 ^ uVar14;

        *(undefined8 *)(param_1 + 0xe4) = *(undefined8 *)(param_1 + 0xc4);

        uVar22 = *(uint *)(param_1 + 0xc0);

        uVar25 = *(uint *)(param_1 + 0xbc) ^ uVar14;

      }

      else {

        *(uint *)(param_1 + 0xd4) = uVar27;

        *(uint *)(param_1 + 0xd8) = uVar22;

        *(uint *)(param_1 + 0xe4) = uVar27;

        *(uint *)(param_1 + 0xe8) = uVar22;

      }

    }

    *(uint *)(param_1 + 0xec) = uVar25;

    *(uint *)(param_1 + 0xf0) = uVar22 ^ uVar14;

  }

  else if (bVar3) {

    if (bVar4) {

      if (((0.0 <= fVar32) || (0.0 <= fVar24)) || (0.0 <= fVar31)) {

        *(undefined8 *)(param_1 + 0xd4) = *(undefined8 *)pfVar8;

        uVar22 = *(uint *)(param_1 + 0xd0);

        *(undefined1 *)(param_1 + 0xf8) = 1;

        *(undefined8 *)(param_1 + 0xe4) = *(undefined8 *)(param_1 + 0xbc);

        *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0xcc);

      }

      else {

        *(undefined1 *)(param_1 + 0xf8) = 0;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 200) ^ uVar14;

        uVar27 = (uint)*pfVar8 ^ uVar14;

        *(uint *)(param_1 + 0xd4) = uVar27;

        *(uint *)(param_1 + 0xe4) = uVar27;

        *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 200) ^ uVar14;

        uVar22 = *(uint *)(param_1 + 200) ^ uVar14;

        *(uint *)(param_1 + 0xec) = uVar27;

      }

    }

    else if ((0.0 <= fVar32) || ((0.0 <= fVar24 && (0.0 <= fVar31)))) {

      uVar22 = *(uint *)(param_1 + 200);

      *(undefined8 *)(param_1 + 0xe4) = *(undefined8 *)(param_1 + 0xbc);

      *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 0xc4);

      *(uint *)(param_1 + 0xd8) = uVar22;

      param_6._0_4_ = (undefined4)*(undefined8 *)(param_1 + 0xc4);

      *(undefined1 *)(param_1 + 0xf8) = 1;

      *(undefined4 *)(param_1 + 0xec) = param_6._0_4_;

    }

    else {

      *(undefined1 *)(param_1 + 0xf8) = 0;

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 200) ^ uVar14;

      uVar27 = *(uint *)(param_1 + 0xc4) ^ uVar14;

      *(uint *)(param_1 + 0xd4) = uVar27;

      *(uint *)(param_1 + 0xe4) = *(uint *)(param_1 + 0xcc) ^ uVar14;

      *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 0xd0) ^ uVar14;

      uVar22 = *(uint *)(param_1 + 200) ^ uVar14;

      *(uint *)(param_1 + 0xec) = uVar27;

    }

LAB_140022030:

    *(uint *)(param_1 + 0xf0) = uVar22;

  }

  else {

    if (bVar4) {

      if ((0.0 <= fVar31) || ((0.0 <= fVar32 && (0.0 <= fVar24)))) {

        *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 0xc4);

        *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_1 + 200);

        *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xc4);

        uVar22 = *(uint *)(param_1 + 0xcc);

        *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 200);

        uVar27 = *(uint *)(param_1 + 0xd0);

        *(undefined1 *)(param_1 + 0xf8) = 1;

      }

      else {

        *(undefined1 *)(param_1 + 0xf8) = 0;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 200) ^ uVar14;

        uVar22 = *(uint *)(param_1 + 0xc4) ^ uVar14;

        *(uint *)(param_1 + 0xd4) = uVar22;

        *(uint *)(param_1 + 0xe4) = uVar22;

        *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 200) ^ uVar14;

        uVar22 = *(uint *)(param_1 + 0xbc) ^ uVar14;

        uVar27 = *(uint *)(param_1 + 0xc0) ^ uVar14;

      }

    }

    else {

      if (((fVar32 < 0.0) || (fVar24 < 0.0)) || (fVar31 < 0.0)) {

        cVar7 = '\0';

      }

      else {

        cVar7 = '\x01';

      }

      *(char *)(param_1 + 0xf8) = cVar7;

      uVar22 = *(uint *)(param_1 + 0xc4);

      uVar27 = *(uint *)(param_1 + 200);

      if (cVar7 == '\0') {

        *(uint *)(param_1 + 0xd4) = uVar22 ^ uVar14;

        *(uint *)(param_1 + 0xd8) = uVar27 ^ uVar14;

        *(uint *)(param_1 + 0xe4) = *(uint *)(param_1 + 0xcc) ^ uVar14;

        *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 0xd0) ^ uVar14;

        *(uint *)(param_1 + 0xf0) = *(uint *)(param_1 + 0xc0) ^ uVar14;

        *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xbc) ^ uVar14;

        goto LAB_140022038;

      }

      *(uint *)(param_1 + 0xd4) = uVar22;

      *(uint *)(param_1 + 0xd8) = uVar27;

      *(uint *)(param_1 + 0xe4) = uVar22;

      *(uint *)(param_1 + 0xe8) = uVar27;

    }

    *(uint *)(param_1 + 0xec) = uVar22;

    *(uint *)(param_1 + 0xf0) = uVar27;

  }

LAB_140022038:

  uVar21 = 0;

  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_5 + 0x98);

  if (0 < *(int *)(param_5 + 0x98)) {

    pfVar8 = (float *)(param_5 + 0x1c);

    lVar12 = param_1 - param_5;

    uVar19 = uVar21;

    do {

      fVar24 = *(float *)(param_1 + 0x8c);

      uVar22 = (int)uVar19 + 1;

      uVar19 = (ulonglong)uVar22;

      fVar39 = *(float *)(param_1 + 0x90);

      fVar30 = pfVar8[-1];

      fVar37 = *pfVar8;

      fVar31 = *(float *)(param_1 + 0x84);

      *(float *)(lVar12 + -0x18 + (longlong)pfVar8) =

           fVar24 * pfVar8[-1] + fVar39 * *pfVar8 + *(float *)(param_1 + 0x88);

      *(float *)(lVar12 + -0x1c + (longlong)pfVar8) = (fVar39 * fVar30 - fVar24 * fVar37) + fVar31;

      fVar24 = pfVar8[0x10];

      fVar39 = pfVar8[0xf];

      fVar30 = *(float *)(param_1 + 0x8c);

      fVar37 = *(float *)(param_1 + 0x90);

      *(float *)(lVar12 + 0x24 + (longlong)pfVar8) = fVar37 * fVar39 - fVar30 * fVar24;

      *(float *)(lVar12 + 0x28 + (longlong)pfVar8) = fVar30 * fVar39 + fVar37 * fVar24;

      pfVar8 = pfVar8 + 2;

    } while ((int)uVar22 < *(int *)(param_5 + 0x98));

  }

  *(undefined4 *)(param_1 + 0xf4) = 0x3ca3d70a;

  param_2[0xf] = 0.0;

  FUN_1400228d0(param_1,&local_e0);

  iVar20 = (int)uVar21;

  if ((float)local_e0 == (float)iVar20) {

    return;

  }

  if (*(float *)(param_1 + 0xf4) < local_d8) {

    return;

  }

  uVar15 = uVar21 & 0xffffffff;

  uVar19 = uVar21 & 0xffffffff;

  local_f8 = CONCAT44(0xffffffff,iVar20);

  if (0 < *(int *)(param_1 + 0x80)) {

    puVar9 = (uint *)(param_1 + 0x44);

    fVar24 = DAT_14039ca8c;

    do {

      fVar30 = (float)(puVar9[-1] ^ uVar14);

      fVar37 = (float)(*puVar9 ^ uVar14);

      local_f0 = ((float)puVar9[-0x11] - *(float *)(param_1 + 0xa4)) * fVar30 +

                 ((float)puVar9[-0x10] - *(float *)(param_1 + 0xa8)) * fVar37;

      fVar39 = ((float)puVar9[-0x11] - *(float *)(param_1 + 0xac)) * fVar30 +

               ((float)puVar9[-0x10] - *(float *)(param_1 + 0xb0)) * fVar37;

      if (fVar39 <= local_f0) {

        local_f0 = fVar39;

      }

      iVar10 = (int)uVar19;

      if (*(float *)(param_1 + 0xf4) < local_f0) {

        local_f8 = CONCAT44(iVar10,2);

        goto LAB_1400223ab;

      }

      if (fVar30 * (float)((uint)*(float *)(param_1 + 0xd8) ^ uVar14) +

          *(float *)(param_1 + 0xd4) * fVar37 < 0.0) {

        fVar31 = *(float *)(param_1 + 0xe4);

        fVar39 = *(float *)(param_1 + 0xe8);

      }

      else {

        fVar31 = *(float *)(param_1 + 0xec);

        fVar39 = *(float *)(param_1 + 0xf0);

      }

      if ((DAT_14039ca74 <=

           (fVar30 - fVar31) * *(float *)(param_1 + 0xd4) +

           (fVar37 - fVar39) * *(float *)(param_1 + 0xd8)) && (fVar24 < local_f0)) {

        uVar15 = 2;

        local_f8 = CONCAT44(iVar10,2);

        fVar24 = local_f0;

      }

      uVar19 = (ulonglong)(iVar10 + 1U);

      puVar9 = puVar9 + 2;

    } while ((int)(iVar10 + 1U) < *(int *)(param_1 + 0x80));

    local_f0 = fVar24;

    if ((int)uVar15 != 0) {

LAB_1400223ab:

      if (*(float *)(param_1 + 0xf4) <= local_f0 && local_f0 != *(float *)(param_1 + 0xf4)) {

        return;

      }

      uVar23 = local_f8;

      if (local_d8 * DAT_14039ca3c + DAT_14039c9fc < local_f0) goto LAB_14002228c;

    }

  }

  local_f0 = local_d8;

  uVar23 = local_e0;

LAB_14002228c:

  local_f8._0_4_ = (float)uVar23;

  iVar10 = (int)(float)local_f8;

  cVar7 = (char)uVar21;

  if ((float)local_f8 == 1.4013e-45) {

    param_2[0xe] = 1.4013e-45;

    uVar19 = uVar21 & 0xffffffff;

    iVar2 = *(int *)(param_1 + 0x80);

    fVar24 = *(float *)(param_1 + 0xd8) * *(float *)(param_1 + 0x44) +

             *(float *)(param_1 + 0xd4) * *(float *)(param_1 + 0x40);

    if (1 < iVar2) {

      pfVar8 = (float *)(param_1 + 0x4c);

      uVar22 = 1;

      do {

        fVar39 = *(float *)(param_1 + 0xd4) * pfVar8[-1] + *(float *)(param_1 + 0xd8) * *pfVar8;

        uVar27 = uVar22;

        if (fVar24 <= fVar39) {

          uVar27 = (uint)uVar19;

          fVar39 = fVar24;

        }

        fVar24 = fVar39;

        uVar22 = uVar22 + 1;

        pfVar8 = pfVar8 + 2;

        uVar19 = (ulonglong)uVar27;

      } while ((int)uVar22 < iVar2);

    }

    fVar31 = *(float *)(param_1 + 0xc4);

    iVar5 = (int)uVar19;

    fVar32 = *(float *)(param_1 + 200);

    iVar11 = iVar5 + 1;

    if (iVar2 <= iVar5 + 1) {

      iVar11 = iVar20;

    }

    fVar24 = *(float *)(param_1 + (longlong)iVar5 * 8);

    fVar39 = *(float *)(param_1 + 4 + (longlong)iVar5 * 8);

    pfVar8 = (float *)(param_1 + 0xb0);

    local_d8 = (float)CONCAT22(1,CONCAT11((char)uVar19,cVar7));

    local_cc = (float)CONCAT22(1,(short)CONCAT31((int3)iVar11,cVar7));

    fVar30 = *(float *)(param_1 + (longlong)iVar11 * 8);

    fVar37 = *(float *)(param_1 + 4 + (longlong)iVar11 * 8);

    pfVar16 = (float *)(param_1 + 0xa4);

    if (*(char *)(param_1 + 0xf8) == cVar7) {

      pfVar8 = (float *)(param_1 + 0xa8);

      iVar20 = 1;

      uVar15 = uVar21 & 0xffffffff;

      fVar31 = (float)((uint)fVar31 ^ uVar14);

      fVar32 = (float)((uint)fVar32 ^ uVar14);

      pfVar13 = (float *)(param_1 + 0xac);

    }

    else {

      uVar15 = 1;

      pfVar13 = pfVar16;

      pfVar16 = (float *)(param_1 + 0xac);

    }

    fVar33 = *pfVar8;

    fVar35 = *pfVar16;

    fVar36 = pfVar13[1];

    fVar38 = *pfVar13;

  }

  else {

    local_f8._4_4_ = (float)((ulonglong)uVar23 >> 0x20);

    iVar20 = (int)local_f8._4_4_;

    lVar12 = (longlong)(int)local_f8._4_4_;

    local_f8._4_1_ = (byte)((ulonglong)uVar23 >> 0x20);

    param_2[0xe] = 2.8026e-45;

    uVar19 = (ulonglong)local_f8._4_1_;

    fVar24 = *(float *)(param_1 + 0xa4);

    fVar39 = *(float *)(param_1 + 0xa8);

    fVar30 = *(float *)(param_1 + 0xac);

    fVar37 = *(float *)(param_1 + 0xb0);

    uVar15 = (ulonglong)(iVar20 + 1U);

    if (*(int *)(param_1 + 0x80) <= (int)(iVar20 + 1U)) {

      uVar15 = uVar21 & 0xffffffff;

    }

    fVar38 = *(float *)(param_1 + lVar12 * 8);

    fVar36 = *(float *)(param_1 + 4 + lVar12 * 8);

    fVar31 = *(float *)(param_1 + 0x40 + lVar12 * 8);

    fVar32 = *(float *)(param_1 + 0x44 + lVar12 * 8);

    local_d8 = (float)CONCAT22(0x100,CONCAT11(local_f8._4_1_,cVar7));

    fVar35 = *(float *)(param_1 + (longlong)(int)uVar15 * 8);

    fVar33 = *(float *)(param_1 + 4 + (longlong)(int)uVar15 * 8);

    local_cc = (float)CONCAT22(0x100,CONCAT11(local_f8._4_1_,cVar7));

  }

  fVar6 = local_cc;

  fVar28 = (float)((uint)fVar31 ^ uVar14);

  uVar17 = uVar21 & 0xffffffff;

  fVar34 = (float)((uint)fVar32 ^ uVar14);

  fVar26 = fVar28 * fVar36 + fVar32 * fVar38;

  fVar33 = fVar34 * fVar35 + fVar31 * fVar33;

  fVar35 = (fVar28 * fVar39 + fVar24 * fVar32) - fVar26;

  fVar26 = (fVar28 * fVar37 + fVar32 * fVar30) - fVar26;

  local_f8 = uVar23;

  if (fVar35 <= 0.0) {

    local_f8 = CONCAT44(fVar39,fVar24);

    uVar17 = 1;

    local_f0 = local_d8;

  }

  uVar18 = uVar17;

  if (fVar26 <= 0.0) {

    uVar18 = (ulonglong)((int)uVar17 + 1);

    *(ulonglong *)((longlong)&local_f8 + uVar17 * 0xc) = CONCAT44(fVar37,fVar30);

    (&local_f0)[uVar17 * 3] = fVar6;

  }

  uVar14 = (uint)uVar18;

  if (fVar26 * fVar35 < 0.0) {

    uVar14 = uVar14 + 1;

    *(char *)(&local_f0 + uVar18 * 3) = (char)iVar20;

    fVar35 = fVar35 / (fVar35 - fVar26);

    *(char *)((longlong)&local_f0 + uVar18 * 0xc + 1) = (char)uVar19;

    *(undefined2 *)((longlong)&local_f0 + uVar18 * 0xc + 2) = 0x100;

    *(float *)((longlong)&local_f8 + uVar18 * 0xc) = (fVar30 - fVar24) * fVar35 + fVar24;

    *(float *)((longlong)&local_f8 + uVar18 * 0xc + 4) = (fVar37 - fVar39) * fVar35 + fVar39;

  }

  if (1 < uVar14) {

    uVar19 = uVar21 & 0xffffffff;

    fVar24 = (fVar31 * local_f8._4_4_ + fVar34 * (float)local_f8) - fVar33;

    fVar33 = (fVar31 * local_e8 + fVar34 * local_ec) - fVar33;

    if (fVar24 <= 0.0) {

      uVar19 = 1;

      local_e0 = local_f8;

      local_d8 = local_f0;

    }

    uVar17 = uVar19;

    if (fVar33 <= 0.0) {

      uVar17 = (ulonglong)((int)uVar19 + 1);

      *(ulonglong *)((longlong)&local_e0 + uVar19 * 0xc) = CONCAT44(local_e8,local_ec);

      (&local_d8)[uVar19 * 3] = local_e4;

    }

    uVar14 = (uint)uVar17;

    if (fVar33 * fVar24 < 0.0) {

      uVar14 = uVar14 + 1;

      *(char *)(&local_d8 + uVar17 * 3) = (char)uVar15;

      fVar24 = fVar24 / (fVar24 - fVar33);

      *(undefined1 *)((longlong)&local_d8 + uVar17 * 0xc + 1) = local_f0._1_1_;

      *(undefined2 *)((longlong)&local_d8 + uVar17 * 0xc + 2) = 0x100;

      *(float *)((longlong)&local_e0 + uVar17 * 0xc) =

           (local_ec - (float)local_f8) * fVar24 + (float)local_f8;

      *(float *)((longlong)&local_e0 + uVar17 * 0xc + 4) =

           (local_e8 - local_f8._4_4_) * fVar24 + local_f8._4_4_;

    }

    if (1 < uVar14) {

      if (iVar10 == 1) {

        param_2[10] = fVar31;

        param_2[0xb] = fVar32;

        param_2[0xc] = fVar38;

        param_2[0xd] = fVar36;

      }

      else {

        *(undefined8 *)(param_2 + 10) = *(undefined8 *)(param_5 + 0x58 + (longlong)iVar20 * 8);

        *(undefined8 *)(param_2 + 0xc) = *(undefined8 *)(param_5 + 0x18 + (longlong)iVar20 * 8);

      }

      if ((local_e0._4_4_ - fVar36) * fVar32 + ((float)local_e0 - fVar38) * fVar31 <=

          *(float *)(param_1 + 0xf4)) {

        if (iVar10 == 1) {

          local_e0._0_4_ = (float)local_e0 - *(float *)(param_1 + 0x84);

          local_e0._4_4_ = local_e0._4_4_ - *(float *)(param_1 + 0x88);

          fVar24 = *(float *)(param_1 + 0x90);

          fVar39 = *(float *)(param_1 + 0x8c);

          param_2[4] = local_d8;

          *param_2 = fVar39 * local_e0._4_4_ + fVar24 * (float)local_e0;

          param_2[1] = fVar24 * local_e0._4_4_ - fVar39 * (float)local_e0;

        }

        else {

          *(undefined1 *)((longlong)param_2 + 0x12) = local_d8._3_1_;

          *(undefined1 *)((longlong)param_2 + 0x13) = local_d8._2_1_;

          *(undefined1 *)(param_2 + 4) = local_d8._1_1_;

          *(undefined1 *)((longlong)param_2 + 0x11) = (undefined1)local_d8;

          *param_2 = (float)local_e0;

          param_2[1] = local_e0._4_4_;

        }

        uVar21 = 1;

      }

      fVar24 = (float)uVar21;

      if ((local_d0 - fVar36) * fVar32 + (local_d4 - fVar38) * fVar31 <= *(float *)(param_1 + 0xf4))

      {

        uVar21 = uVar21 & 0xffffffff;

        if (iVar10 == 1) {

          local_d4 = local_d4 - *(float *)(param_1 + 0x84);

          local_d0 = local_d0 - *(float *)(param_1 + 0x88);

          fVar39 = *(float *)(param_1 + 0x90);

          fVar30 = *(float *)(param_1 + 0x8c);

          param_2[uVar21 * 5] = fVar30 * local_d0 + fVar39 * local_d4;

          param_2[uVar21 * 5 + 1] = fVar39 * local_d0 - fVar30 * local_d4;

          param_2[uVar21 * 5 + 4] = local_cc;

        }

        else {

          param_2[uVar21 * 5] = local_d4;

          param_2[uVar21 * 5 + 1] = local_d0;

          *(undefined1 *)((longlong)param_2 + uVar21 * 0x14 + 0x12) = local_cc._3_1_;

          *(undefined1 *)((longlong)param_2 + uVar21 * 0x14 + 0x13) = local_cc._2_1_;

          *(undefined1 *)(param_2 + uVar21 * 5 + 4) = local_cc._1_1_;

          *(undefined1 *)((longlong)param_2 + uVar21 * 0x14 + 0x11) = (undefined1)local_cc;

        }

        fVar24 = (float)((int)fVar24 + 1);

      }

      param_2[0xf] = fVar24;

    }

  }

  return;

}




