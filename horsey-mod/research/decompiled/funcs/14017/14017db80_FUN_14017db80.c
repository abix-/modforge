// Address: 0x14017db80
// Ghidra name: FUN_14017db80
// ============ 0x14017db80 FUN_14017db80 (size=268) ============


void FUN_14017db80(undefined8 *param_1,int param_2,undefined4 param_3,int param_4,int param_5)



{

  uint uVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  uint uVar5;

  int iVar6;

  ulonglong uVar7;

  undefined8 *puVar8;

  uint uVar9;

  int iVar10;

  

  iVar6 = param_4 * 4;

  if (iVar6 == param_2) {

    param_4 = param_4 * param_5;

  }

  iVar10 = 1;

  if (iVar6 != param_2) {

    iVar10 = param_5;

  }

  if (iVar10 != 0) {

    uVar3 = CONCAT44(param_3,param_3);

    uVar4 = CONCAT44(param_3,param_3);

    uVar1 = param_4 * 4;

    do {

      iVar10 = iVar10 + -1;

      puVar8 = param_1;

      uVar9 = uVar1;

      if (0x3f < (int)uVar1) {

        iVar6 = 0x10 - ((uint)param_1 & 0xf);

        if (iVar6 < 0x10) {

          uVar9 = uVar1 - iVar6;

          uVar5 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;

          uVar7 = (ulonglong)uVar5;

          if (uVar5 != 0) {

            lVar2 = uVar7 * 4;

            for (; uVar7 != 0; uVar7 = uVar7 - 1) {

              *(undefined4 *)puVar8 = param_3;

              puVar8 = (undefined8 *)((longlong)puVar8 + 4);

            }

            puVar8 = (undefined8 *)(lVar2 + (longlong)param_1);

          }

        }

        for (iVar6 = (int)(uVar9 + ((int)uVar9 >> 0x1f & 0x3fU)) >> 6; iVar6 != 0;

            iVar6 = iVar6 + -1) {

          *puVar8 = uVar3;

          puVar8[1] = uVar4;

          puVar8[2] = uVar3;

          puVar8[3] = uVar4;

          puVar8[4] = uVar3;

          puVar8[5] = uVar4;

          puVar8[6] = uVar3;

          puVar8[7] = uVar4;

          puVar8 = puVar8 + 8;

        }

      }

      if (((uVar9 & 0x3f) != 0) && (uVar9 = (int)uVar9 >> 2 & 0xf, uVar9 != 0)) {

        for (uVar7 = (ulonglong)uVar9; uVar7 != 0; uVar7 = uVar7 - 1) {

          *(undefined4 *)puVar8 = param_3;

          puVar8 = (undefined8 *)((longlong)puVar8 + 4);

        }

      }

      param_1 = (undefined8 *)((longlong)param_1 + (longlong)param_2);

    } while (iVar10 != 0);

  }

  return;

}




