// Address: 0x140084670
// Ghidra name: FUN_140084670
// ============ 0x140084670 FUN_140084670 (size=1259) ============


void FUN_140084670(longlong param_1,undefined4 param_2)



{

  float *pfVar1;

  float *pfVar2;

  longlong lVar3;

  longlong lVar4;

  float *pfVar5;

  int iVar6;

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

  

  lVar3 = *(longlong *)(param_1 + 0x18);

  lVar4 = *(longlong *)(param_1 + 0x10);

  iVar6 = *(int *)(lVar3 + 8);

  if (iVar6 == 2) {

    fVar7 = *(float *)(lVar4 + 0x14);

    fVar11 = *(float *)(lVar4 + 0x18);

    fVar13 = (fVar11 * *(float *)(lVar3 + 0x18) - fVar7 * *(float *)(lVar3 + 0x1c)) +

             *(float *)(lVar4 + 0xc);

    fVar12 = *(float *)(lVar3 + 0x18) * fVar7 + fVar11 * *(float *)(lVar3 + 0x1c) +

             *(float *)(lVar4 + 0x10);

    if (*(int *)(lVar3 + 0x98) != 2) {

      iVar6 = 1;

      if (*(int *)(lVar3 + 0x98) + -1 < 2) {

        return;

      }

      pfVar5 = (float *)(lVar3 + 0x20);

      do {

        fVar7 = *pfVar5;

        pfVar1 = pfVar5 + 3;

        fVar11 = *(float *)(lVar4 + 0x14);

        fVar14 = *(float *)(lVar4 + 0x18);

        pfVar2 = pfVar5 + 1;

        pfVar5 = pfVar5 + 2;

        FUN_140071810(fVar13,fVar12,(fVar7 * fVar14 - *pfVar2 * fVar11) + *(float *)(lVar4 + 0xc),

                      *pfVar2 * fVar14 + fVar7 * fVar11 + *(float *)(lVar4 + 0x10),

                      (*pfVar5 * fVar14 - *pfVar1 * fVar11) + *(float *)(lVar4 + 0xc),

                      *pfVar1 * fVar14 + *pfVar5 * fVar11 + *(float *)(lVar4 + 0x10),param_2);

        iVar6 = iVar6 + 1;

      } while (iVar6 < *(int *)(lVar3 + 0x98) + -1);

      return;

    }

    fVar16 = (fVar11 * *(float *)(lVar3 + 0x20) - fVar7 * *(float *)(lVar3 + 0x24)) +

             *(float *)(lVar4 + 0xc);

    fVar15 = fVar7 * *(float *)(lVar3 + 0x20) + fVar11 * *(float *)(lVar3 + 0x24) +

             *(float *)(lVar4 + 0x10);

    fVar14 = fVar13 - fVar16;

    fVar11 = fVar15 - fVar12;

    fVar7 = fVar14 * fVar14 + fVar11 * fVar11;

    if (fVar7 < 0.0) {

      fVar7 = (float)FUN_1402cdfa0(fVar7);

    }

    else {

      fVar7 = SQRT(fVar7);

    }

    if (DAT_14039c9f0 <= fVar7) {

      fVar14 = (DAT_14039ca44 / fVar7) * fVar14;

      fVar11 = (DAT_14039ca44 / fVar7) * fVar11;

    }

    fVar8 = fVar14 + fVar12;

    fVar7 = fVar11 + fVar13;

    fVar10 = fVar15 - fVar14;

    fVar9 = fVar16 - fVar11;

    FUN_140071810(fVar7,fVar8,fVar11 + fVar16,fVar14 + fVar15,fVar9,fVar10,param_2);

    fVar12 = fVar12 - fVar14;

    fVar13 = fVar13 - fVar11;

  }

  else {

    if (iVar6 != 1) {

      if (iVar6 != 0) {

        return;

      }

      FUN_140071150((*(float *)(lVar4 + 0x18) * *(float *)(lVar3 + 0x10) -

                    *(float *)(lVar4 + 0x14) * *(float *)(lVar3 + 0x14)) + *(float *)(lVar4 + 0xc),

                    *(float *)(lVar3 + 0x10) * *(float *)(lVar4 + 0x14) +

                    *(float *)(lVar4 + 0x18) * *(float *)(lVar3 + 0x14) + *(float *)(lVar4 + 0x10),

                    *(undefined4 *)(lVar3 + 0xc),param_2,0x10);

      return;

    }

    fVar7 = *(float *)(lVar4 + 0x14);

    fVar11 = *(float *)(lVar4 + 0x18);

    fVar13 = (fVar11 * *(float *)(lVar3 + 0x10) - fVar7 * *(float *)(lVar3 + 0x14)) +

             *(float *)(lVar4 + 0xc);

    fVar12 = *(float *)(lVar3 + 0x10) * fVar7 + fVar11 * *(float *)(lVar3 + 0x14) +

             *(float *)(lVar4 + 0x10);

    fVar16 = (*(float *)(lVar3 + 0x18) * fVar11 - *(float *)(lVar3 + 0x1c) * fVar7) +

             *(float *)(lVar4 + 0xc);

    fVar15 = *(float *)(lVar3 + 0x1c) * fVar11 + *(float *)(lVar3 + 0x18) * fVar7 +

             *(float *)(lVar4 + 0x10);

    fVar14 = fVar13 - fVar16;

    fVar11 = fVar15 - fVar12;

    fVar7 = fVar14 * fVar14 + fVar11 * fVar11;

    if (fVar7 < 0.0) {

      fVar7 = (float)FUN_1402cdfa0(fVar7);

    }

    else {

      fVar7 = SQRT(fVar7);

    }

    if (DAT_14039c9f0 <= fVar7) {

      fVar11 = fVar11 * (DAT_14039ca44 / fVar7);

      fVar14 = fVar14 * (DAT_14039ca44 / fVar7);

    }

    fVar11 = fVar11 * DAT_14030335c;

    fVar14 = fVar14 * DAT_14030335c;

    fVar7 = fVar13 + fVar11;

    fVar10 = fVar15 - fVar14;

    fVar8 = fVar12 + fVar14;

    fVar9 = fVar16 - fVar11;

    FUN_140071810(fVar7,fVar8,fVar16 + fVar11,fVar15 + fVar14,fVar9,fVar10,param_2);

    fVar12 = fVar12 - fVar14;

    fVar13 = fVar13 - fVar11;

  }

  FUN_140071810(fVar7,fVar8,fVar9,fVar10,fVar13,fVar12,param_2);

  return;

}




