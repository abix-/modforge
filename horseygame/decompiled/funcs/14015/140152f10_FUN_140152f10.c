// Address: 0x140152f10
// Ghidra name: FUN_140152f10
// ============ 0x140152f10 FUN_140152f10 (size=666) ============


bool FUN_140152f10(undefined8 param_1,undefined8 param_2,undefined4 *param_3,float param_4,

                  float *param_5)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  char cVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float local_f8 [2];

  float local_f0;

  float local_ec;

  float local_e8;

  float local_e4;

  undefined4 local_e0;

  undefined4 uStack_dc;

  float fStack_d8;

  float fStack_d4;

  

  pfVar3 = param_5;

  fVar13 = param_4 * (float)param_3[2];

  param_4 = param_4 * (float)param_3[3];

  fVar10 = (float)FUN_140190500(param_5[2] / fVar13,local_f8);

  fVar11 = (float)FUN_140190500(pfVar3[3] / param_4,&param_5);

  iVar5 = (int)param_5._0_4_;

  iVar9 = 0;

  iVar8 = 0;

  fVar14 = pfVar3[1];

  fVar1 = (float)param_3[3];

  fVar2 = (float)param_3[2];

  fVar15 = fVar10 * fVar13;

  fVar16 = fVar11 * param_4;

  local_e0 = *param_3;

  uStack_dc = param_3[1];

  fStack_d8 = (float)param_3[2];

  fStack_d4 = (float)param_3[3];

  iVar7 = (int)local_f8[0];

  local_ec = fVar14;

  local_e8 = fVar13;

  local_e4 = param_4;

  if (0 < iVar5) {

    do {

      fVar12 = *pfVar3;

      iVar6 = 0;

      local_f0 = fVar12;

      local_ec = fVar14;

      if (0 < iVar7) {

        do {

          local_f0 = fVar12;

          cVar4 = FUN_1401527c0(param_1,param_2,&local_e0,&local_f0);

          if (cVar4 == '\0') {

            return false;

          }

          fVar12 = fVar12 + fVar13;

          iVar6 = iVar6 + 1;

          local_f0 = fVar12;

        } while (iVar6 < iVar7);

      }

      if (0.0 < fVar15) {

        local_e8 = fVar15;

        fStack_d8 = fVar10 * fVar2;

        cVar4 = FUN_1401527c0(param_1,param_2,&local_e0,&local_f0);

        if (cVar4 == '\0') {

          return false;

        }

        fStack_d8 = (float)param_3[2];

        local_e8 = fVar13;

      }

      fVar14 = fVar14 + param_4;

      iVar8 = iVar8 + 1;

      local_ec = fVar14;

    } while (iVar8 < iVar5);

  }

  if (0.0 < fVar16) {

    fVar14 = *pfVar3;

    local_f0 = fVar14;

    local_e4 = fVar16;

    fStack_d4 = fVar11 * fVar1;

    if (0 < iVar7) {

      do {

        local_f0 = fVar14;

        cVar4 = FUN_1401527c0(param_1,param_2,&local_e0,&local_f0);

        if (cVar4 == '\0') {

          return false;

        }

        fVar14 = fVar14 + fVar13;

        iVar9 = iVar9 + 1;

        local_f0 = fVar14;

      } while (iVar9 < iVar7);

    }

    if (0.0 < fVar15) {

      local_e8 = fVar15;

      fStack_d8 = fVar10 * fVar2;

      cVar4 = FUN_1401527c0(param_1,param_2,&local_e0,&local_f0);

      return cVar4 != '\0';

    }

  }

  return true;

}




