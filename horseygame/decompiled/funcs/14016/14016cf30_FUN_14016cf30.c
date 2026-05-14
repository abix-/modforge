// Address: 0x14016cf30
// Ghidra name: FUN_14016cf30
// ============ 0x14016cf30 FUN_14016cf30 (size=592) ============


undefined8

FUN_14016cf30(undefined8 param_1,int param_2,int param_3,float param_4,char param_5,

             undefined8 *param_6)



{

  int iVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  undefined8 uVar5;

  longlong lVar6;

  undefined8 *puVar7;

  undefined8 *puVar8;

  uint uVar9;

  undefined8 *puVar10;

  undefined8 *puVar11;

  float fVar12;

  float extraout_XMM0_Da;

  float extraout_XMM0_Da_00;

  

  if (param_6 == (undefined8 *)0x0) {

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid","closest");

    return uVar5;

  }

  puVar8 = (undefined8 *)0x0;

  lVar6 = FUN_14016dd00();

  uVar5 = 0;

  *param_6 = 0;

  param_6[1] = 0;

  param_6[2] = 0;

  param_6[3] = 0;

  param_6[4] = 0;

  fVar4 = DAT_14039ca44;

  if (lVar6 != 0) {

    fVar3 = DAT_14039ca44;

    if (0 < param_3) {

      fVar3 = (float)param_2 / (float)param_3;

    }

    if (param_4 == 0.0) {

      param_4 = *(float *)(lVar6 + 0x34);

    }

    FUN_140173170(lVar6);

    puVar10 = puVar8;

    puVar11 = puVar8;

    if (0 < *(int *)(lVar6 + 0x14)) {

      do {

        puVar7 = (undefined8 *)(*(longlong *)(lVar6 + 0x18) + (longlong)puVar8);

        iVar1 = *(int *)(puVar7 + 1);

        if (iVar1 < param_2) break;

        iVar2 = *(int *)((longlong)puVar7 + 0xc);

        if ((param_3 <= iVar2) && ((*(float *)(puVar7 + 2) <= fVar4 || (param_5 != '\0')))) {

          if (puVar11 != (undefined8 *)0x0) {

            fVar12 = (float)FUN_140190250(fVar3 - (float)*(int *)(puVar11 + 1) /

                                                  (float)*(int *)((longlong)puVar11 + 0xc));

            FUN_140190250(fVar3 - (float)iVar1 / (float)iVar2);

            if (fVar12 < extraout_XMM0_Da) goto LAB_14016d0f0;

            if ((*(int *)(puVar7 + 1) == *(int *)(puVar11 + 1)) &&

               (*(int *)((longlong)puVar7 + 0xc) == *(int *)((longlong)puVar11 + 0xc))) {

              fVar12 = (float)FUN_140190250(*(float *)((longlong)puVar11 + 0x14) - param_4);

              FUN_140190250(*(float *)((longlong)puVar7 + 0x14) - param_4);

              if (fVar12 < extraout_XMM0_Da_00) goto LAB_14016d0f0;

            }

          }

          puVar11 = puVar7;

        }

LAB_14016d0f0:

        uVar9 = (int)puVar10 + 1;

        puVar8 = puVar8 + 5;

        puVar10 = (undefined8 *)(ulonglong)uVar9;

      } while ((int)uVar9 < *(int *)(lVar6 + 0x14));

      if (puVar11 != (undefined8 *)0x0) {

        uVar5 = puVar11[1];

        *param_6 = *puVar11;

        param_6[1] = uVar5;

        uVar5 = puVar11[3];

        param_6[2] = puVar11[2];

        param_6[3] = uVar5;

        param_6[4] = puVar11[4];

        return 1;

      }

    }

    uVar5 = FUN_14012e850("Couldn\'t find any matching video modes");

  }

  return uVar5;

}




