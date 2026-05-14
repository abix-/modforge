// Address: 0x1401d4070
// Ghidra name: FUN_1401d4070
// ============ 0x1401d4070 FUN_1401d4070 (size=647) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1401d4070(longlong param_1,longlong param_2,int param_3,int param_4,int param_5,int param_6

                  ,int *param_7,float *param_8)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  double dVar5;

  double dVar6;

  undefined1 uVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  undefined1 *puVar11;

  int iVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  double dVar16;

  double dVar17;

  double dVar18;

  double dVar19;

  

  iVar1 = *(int *)(param_1 + 8);

  puVar11 = *(undefined1 **)(param_2 + 0x18);

  iVar2 = *(int *)(param_1 + 0xc);

  iVar3 = *(int *)(param_2 + 0x10);

  iVar15 = *(int *)(param_2 + 0xc);

  iVar4 = *(int *)(param_2 + 8);

  dVar16 = (double)*param_8 * _DAT_14034a978;

  dVar17 = (double)param_8[1] * _DAT_14034a978;

  uVar7 = FUN_1401d3810(param_1);

  FUN_1402f94c0(puVar11,uVar7,(longlong)iVar3 * (longlong)iVar15);

  dVar6 = DAT_14034a970;

  dVar5 = DAT_140304b70;

  iVar15 = 0;

  if (0 < *(int *)(param_2 + 0xc)) {

    do {

      iVar14 = 0;

      dVar19 = ((double)*param_7 + 0.0 + dVar5) - (double)*param_8;

      dVar18 = ((double)iVar15 + (double)param_7[1] + dVar5) - (double)param_8[1];

      iVar12 = (int)(((dVar19 * (double)param_4 - (double)param_3 * dVar18) + (double)(int)dVar16) -

                    dVar6);

      iVar13 = (int)((dVar19 * (double)param_3 + (double)param_4 * dVar18 + (double)(int)dVar17) -

                    dVar6);

      if (0 < *(int *)(param_2 + 8)) {

        do {

          uVar10 = iVar12 >> 0x10;

          uVar9 = iVar13 >> 0x10;

          if ((uVar10 < *(uint *)(param_1 + 8)) && (uVar9 < *(uint *)(param_1 + 0xc))) {

            uVar8 = (iVar2 + -1) - uVar9;

            if (param_6 == 0) {

              uVar8 = uVar9;

            }

            uVar9 = (iVar1 + -1) - uVar10;

            if (param_5 == 0) {

              uVar9 = uVar10;

            }

            *puVar11 = *(undefined1 *)

                        ((longlong)(int)(uVar8 * *(int *)(param_1 + 0x10)) + (longlong)(int)uVar9 +

                        *(longlong *)(param_1 + 0x18));

          }

          iVar12 = iVar12 + param_4;

          iVar13 = iVar13 + param_3;

          puVar11 = puVar11 + 1;

          iVar14 = iVar14 + 1;

        } while (iVar14 < *(int *)(param_2 + 8));

      }

      puVar11 = puVar11 + (iVar3 - iVar4);

      iVar15 = iVar15 + 1;

    } while (iVar15 < *(int *)(param_2 + 0xc));

  }

  return;

}




