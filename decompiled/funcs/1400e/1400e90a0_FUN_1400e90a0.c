// Address: 0x1400e90a0
// Ghidra name: FUN_1400e90a0
// ============ 0x1400e90a0 FUN_1400e90a0 (size=301) ============


void FUN_1400e90a0(float *param_1,byte *param_2,int param_3)



{

  double dVar1;

  float fVar2;

  

  if (param_2[3] == 0) {

    if (param_3 != 1) {

      if (param_3 != 2) {

        if (param_3 != 3) {

          if (param_3 != 4) {

            return;

          }

          param_1[3] = 1.0;

        }

        param_1[1] = 0.0;

        param_1[2] = 0.0;

        *param_1 = 0.0;

        return;

      }

      param_1[1] = 1.0;

    }

    *param_1 = 0.0;

  }

  else {

    dVar1 = (double)FUN_1402cf1e0(DAT_140304b90,param_2[3] - 0x88);

    fVar2 = (float)dVar1;

    if (param_3 < 3) {

      *param_1 = ((float)((uint)param_2[2] + (uint)param_2[1] + (uint)*param_2) * fVar2) /

                 DAT_14030338c;

      if (param_3 == 2) {

        param_1[1] = 1.0;

        return;

      }

    }

    else {

      *param_1 = (float)*param_2 * fVar2;

      param_1[1] = (float)param_2[1] * fVar2;

      param_1[2] = (float)param_2[2] * fVar2;

      if (param_3 == 4) {

        param_1[3] = 1.0;

        return;

      }

    }

  }

  return;

}




