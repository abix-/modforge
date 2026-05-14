// Address: 0x1401e42a0
// Ghidra name: FUN_1401e42a0
// ============ 0x1401e42a0 FUN_1401e42a0 (size=587) ============


void FUN_1401e42a0(longlong param_1,longlong param_2,int *param_3,float *param_4)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  longlong lVar6;

  undefined8 *puVar7;

  undefined8 uVar8;

  float fVar9;

  byte bVar10;

  

  param_4[0] = 0.0;

  param_4[1] = 0.0;

  param_4[2] = 0.0;

  param_4[3] = 0.0;

  param_4[4] = 0.0;

  param_4[5] = 0.0;

  param_4[6] = 0.0;

  param_4[7] = 0.0;

  param_4[8] = 0.0;

  param_4[9] = 0.0;

  param_4[10] = 0.0;

  param_4[0xb] = 0.0;

  param_4[0xc] = 0.0;

  param_4[0xd] = 0.0;

  param_4[0xe] = 0.0;

  param_4[0xf] = 0.0;

  param_4[0x10] = 0.0;

  param_4[0x11] = 0.0;

  param_4[0x12] = 0.0;

  param_4[0x13] = 0.0;

  param_4[0x14] = 0.0;

  param_4[0x15] = 0.0;

  param_4[0x16] = 0.0;

  param_4[0x17] = 0.0;

  param_4[0x18] = 0.0;

  param_4[0x19] = 0.0;

  param_4[0x1a] = 0.0;

  param_4[0x1b] = 0.0;

  bVar10 = FUN_1401538c0();

  *param_4 = (float)bVar10;

  param_4[3] = *(float *)(param_2 + 0x18);

  fVar9 = DAT_14039ca44;

  fVar3 = DAT_14030374c;

  if (param_3 == (int *)0x0) {

    return;

  }

  iVar4 = *param_3;

  lVar6 = *(longlong *)(param_3 + 0x4e);

  if (iVar4 < 0x3231564f) {

    if (iVar4 == 0x3231564e) {

      param_4[1] = 6.0;

    }

    else {

      if (iVar4 == 0x13000801) {

        iVar4 = *(int *)(param_2 + 0x38);

        pfVar1 = param_4 + 1;

        if (iVar4 == 0) {

          *pfVar1 = 3.0;

        }

        else if (iVar4 == 1) {

          *pfVar1 = 4.0;

        }

        else if (iVar4 == 2) {

          *pfVar1 = 5.0;

        }

        goto LAB_1401e4403;

      }

      if (iVar4 == 0x30313050) {

        param_4[2] = 3.0;

        param_4[1] = 6.0;

        goto LAB_1401e4403;

      }

      if (iVar4 != 0x3132564e) goto LAB_1401e43ae;

      param_4[1] = 7.0;

    }

  }

  else {

    if ((iVar4 != 0x32315659) && (iVar4 != 0x56555949)) {

LAB_1401e43ae:

      fVar2 = DAT_14039ca44;

      if (*(int *)(param_2 + 0x38) == 2) {

        fVar2 = DAT_14030374c;

      }

      param_4[1] = fVar2;

      if (param_3[6] == 0x12000500) {

        param_4[2] = 2.0;

      }

      else if (param_3[6] == 0x12002600) {

        param_4[2] = 3.0;

      }

      else {

        param_4[2] = 0.0;

      }

      goto LAB_1401e4403;

    }

    param_4[1] = 8.0;

  }

  param_4[2] = 1.0;

LAB_1401e4403:

  fVar2 = param_4[1];

  if (((fVar2 == DAT_140303390) || (fVar2 == DAT_140303394)) || (fVar2 == fVar3)) {

    iVar4 = param_3[1];

    param_4[6] = (float)iVar4;

    iVar5 = param_3[2];

    param_4[4] = fVar9 / (float)iVar4;

    param_4[7] = (float)iVar5;

    param_4[5] = fVar9 / (float)iVar5;

  }

  param_4[0xb] = (float)param_3[7];

  if (*(longlong *)(param_1 + 0x1f0) == 0) {

    fVar3 = *(float *)(param_1 + 0x210);

  }

  else {

    fVar3 = *(float *)(*(longlong *)(param_1 + 0x1f0) + 0x20);

  }

  if ((fVar3 < (float)param_3[8]) && (0.0 < fVar3)) {

    param_4[8] = 2.0;

    fVar2 = (float)param_3[8];

    param_4[10] = fVar9 / fVar3;

    param_4[9] = fVar3 / (fVar2 * fVar2);

  }

  puVar7 = *(undefined8 **)(lVar6 + 0x30);

  if (puVar7 != (undefined8 *)0x0) {

    uVar8 = puVar7[1];

    *(undefined8 *)(param_4 + 0xc) = *puVar7;

    *(undefined8 *)(param_4 + 0xe) = uVar8;

    uVar8 = puVar7[3];

    *(undefined8 *)(param_4 + 0x10) = puVar7[2];

    *(undefined8 *)(param_4 + 0x12) = uVar8;

    uVar8 = puVar7[5];

    *(undefined8 *)(param_4 + 0x14) = puVar7[4];

    *(undefined8 *)(param_4 + 0x16) = uVar8;

    uVar8 = puVar7[7];

    *(undefined8 *)(param_4 + 0x18) = puVar7[6];

    *(undefined8 *)(param_4 + 0x1a) = uVar8;

  }

  return;

}




