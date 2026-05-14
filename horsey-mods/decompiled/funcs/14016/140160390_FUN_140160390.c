// Address: 0x140160390
// Ghidra name: FUN_140160390
// ============ 0x140160390 FUN_140160390 (size=320) ============


void FUN_140160390(longlong param_1,longlong param_2,float *param_3,float *param_4)



{

  int iVar1;

  int iVar2;

  char cVar3;

  longlong lVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float fVar9;

  undefined8 local_48;

  int local_40;

  int local_3c;

  int local_38;

  int local_34;

  int local_30;

  int local_2c;

  

  if ((param_2 != 0) && ((*(uint *)(param_2 + 0x48) >> 0xe & 1) == 0)) {

    iVar1 = *(int *)(param_2 + 0x24);

    iVar2 = *(int *)(param_2 + 0x20);

    iVar6 = iVar1 + -1;

    iVar7 = 0;

    iVar8 = iVar2 + -1;

    lVar4 = FUN_14016e570(param_2);

    iVar5 = iVar7;

    if (lVar4 != 0) {

      local_48 = 0;

      local_40 = iVar2;

      local_3c = iVar1;

      cVar3 = FUN_140185790(lVar4,&local_48,&local_38);

      if (cVar3 != '\0') {

        iVar8 = local_38 + -1 + local_30;

        iVar6 = local_34 + -1 + local_2c;

        iVar7 = local_34;

        iVar5 = local_38;

      }

    }

    fVar9 = *param_3;

    if ((float)(iVar8 + 1) <= fVar9) {

      fVar9 = (float)iVar8;

      if ((float)iVar8 <= *(float *)(param_1 + 0xa0)) {

        fVar9 = *(float *)(param_1 + 0xa0);

      }

      *param_3 = fVar9;

    }

    if (fVar9 < (float)iVar5) {

      *param_3 = (float)iVar5;

    }

    fVar9 = *param_4;

    if ((float)(iVar6 + 1) <= fVar9) {

      fVar9 = (float)iVar6;

      if ((float)iVar6 <= *(float *)(param_1 + 0xa4)) {

        fVar9 = *(float *)(param_1 + 0xa4);

      }

      *param_4 = fVar9;

    }

    if (fVar9 < (float)iVar7) {

      *param_4 = (float)iVar7;

    }

  }

  return;

}




