// Address: 0x14017d9a0
// Ghidra name: FUN_14017d9a0
// ============ 0x14017d9a0 FUN_14017d9a0 (size=252) ============


void FUN_14017d9a0(undefined8 *param_1,int param_2,undefined4 param_3,int param_4,int param_5)



{

  uint uVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  int iVar5;

  ulonglong uVar6;

  undefined8 *puVar7;

  uint uVar8;

  int iVar9;

  

  iVar5 = param_4 * 2;

  if (iVar5 == param_2) {

    param_4 = param_4 * param_5;

  }

  iVar9 = 1;

  if (iVar5 != param_2) {

    iVar9 = param_5;

  }

  if (iVar9 != 0) {

    uVar3 = CONCAT44(param_3,param_3);

    uVar4 = CONCAT44(param_3,param_3);

    uVar1 = param_4 * 2;

    do {

      iVar9 = iVar9 + -1;

      puVar7 = param_1;

      uVar8 = uVar1;

      if (0x3f < (int)uVar1) {

        iVar5 = 0x10 - ((uint)param_1 & 0xf);

        if (iVar5 < 0x10) {

          uVar8 = uVar1 - iVar5;

          uVar6 = (ulonglong)(uint)(iVar5 / 2);

          if (iVar5 / 2 != 0) {

            lVar2 = uVar6 * 2;

            for (; uVar6 != 0; uVar6 = uVar6 - 1) {

              *(short *)puVar7 = (short)param_3;

              puVar7 = (undefined8 *)((longlong)puVar7 + 2);

            }

            puVar7 = (undefined8 *)(lVar2 + (longlong)param_1);

          }

        }

        for (iVar5 = (int)(uVar8 + ((int)uVar8 >> 0x1f & 0x3fU)) >> 6; iVar5 != 0;

            iVar5 = iVar5 + -1) {

          *puVar7 = uVar3;

          puVar7[1] = uVar4;

          puVar7[2] = uVar3;

          puVar7[3] = uVar4;

          puVar7[4] = uVar3;

          puVar7[5] = uVar4;

          puVar7[6] = uVar3;

          puVar7[7] = uVar4;

          puVar7 = puVar7 + 8;

        }

      }

      if (((uVar8 & 0x3f) != 0) && (uVar8 = (int)uVar8 >> 1 & 0x1f, uVar8 != 0)) {

        for (uVar6 = (ulonglong)uVar8; uVar6 != 0; uVar6 = uVar6 - 1) {

          *(short *)puVar7 = (short)param_3;

          puVar7 = (undefined8 *)((longlong)puVar7 + 2);

        }

      }

      param_1 = (undefined8 *)((longlong)param_1 + (longlong)param_2);

    } while (iVar9 != 0);

  }

  return;

}




