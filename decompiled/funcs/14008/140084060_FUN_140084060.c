// Address: 0x140084060
// Ghidra name: FUN_140084060
// ============ 0x140084060 FUN_140084060 (size=653) ============


void FUN_140084060(longlong param_1,float param_2,char param_3,char param_4)



{

  char cVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  if (*(int *)(param_1 + 8) == 2) {

    fVar2 = (float)FUN_140009ca0();

    fVar4 = *(float *)(param_1 + 0xc0);

    if ((param_3 != '\0') && (param_4 != '\0')) {

      cVar1 = FUN_140009e00(param_1);

      if (cVar1 == '\0') {

        return;

      }

      FUN_140009e10(param_1,0);

      return;

    }

    cVar1 = FUN_140009e00(param_1);

    if (cVar1 == '\0') {

      FUN_140009e10(param_1,1);

    }

    if (((param_3 != '\0') && ((float)((uint)param_2 ^ DAT_14039cac0) / DAT_140304014 < fVar2)) &&

       (fVar2 < param_2 / DAT_140304014)) {

      FUN_140009e60(param_1,0);

      return;

    }

    fVar6 = (float)((uint)param_2 ^ DAT_14039cac0);

    if ((fVar4 < param_2) && (fVar6 < fVar4)) {

      if (0.0 < fVar2) {

        param_2 = fVar6;

      }

      FUN_140009e60(param_1,param_2);

      return;

    }

    if ((0.0 < fVar4) && (fVar3 = (float)FUN_140009df0(param_1), fVar3 - DAT_14039ca0c < fVar2)) {

      FUN_140009e60(param_1,fVar6);

      return;

    }

    if (0.0 <= fVar4) {

      return;

    }

    fVar4 = (float)FUN_140009de0(param_1);

    if (fVar4 + DAT_14039ca0c <= fVar2) {

      return;

    }

    FUN_140009e60(param_1,param_2);

    return;

  }

  fVar2 = (float)FUN_14000b270();

  fVar4 = *(float *)(param_1 + 0xa8);

  if ((param_3 == '\0') || (param_4 == '\0')) {

    cVar1 = FUN_14000b290(param_1);

    if ((cVar1 == '\0') && (cVar1 = FUN_14000b290(param_1), cVar1 == '\0')) {

      FUN_14000b2a0(param_1,1);

    }

    if (((param_3 == '\0') || (fVar2 <= (float)((uint)param_2 ^ DAT_14039cac0) / DAT_140304014)) ||

       (param_2 / DAT_140304014 <= fVar2)) {

      fVar6 = (float)((uint)param_2 ^ DAT_14039cac0);

      if ((param_2 <= fVar4) || (fVar4 <= fVar6)) {

        if ((fVar4 <= 0.0) ||

           (fVar5 = (float)FUN_140009df0(param_1), fVar3 = fVar6, fVar2 <= fVar5 - DAT_14039ca0c)) {

          if (0.0 <= fVar4) {

            return;

          }

          fVar4 = (float)FUN_140009de0(param_1);

          fVar3 = param_2;

          if (fVar4 + DAT_14039ca0c <= fVar2) {

            return;

          }

        }

      }

      else {

        fVar3 = param_2;

        if (0.0 < fVar2) {

          fVar3 = fVar6;

        }

      }

      goto LAB_1400842ba;

    }

  }

  else {

    cVar1 = FUN_14000b290(param_1);

    if (cVar1 == '\0') {

      return;

    }

    FUN_14000b2a0(param_1,0);

  }

  fVar3 = 0.0;

LAB_1400842ba:

  FUN_14000b2f0(param_1,fVar3);

  return;

}




