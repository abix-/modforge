// Address: 0x1401912e0
// Ghidra name: FUN_1401912e0
// ============ 0x1401912e0 FUN_1401912e0 (size=925) ============


void FUN_1401912e0(undefined4 *param_1,ulonglong param_2,code *param_3,undefined8 param_4)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  ulonglong uVar4;

  undefined4 uVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  undefined4 *puVar9;

  ulonglong *puVar10;

  longlong local_458;

  undefined8 *local_450;

  undefined4 *local_448;

  undefined4 *local_440;

  undefined8 local_438;

  ulonglong local_430 [127];

  

  puVar2 = (undefined4 *)FUN_1401841f0(4);

  local_440 = param_1 + (param_2 - 1);

  if ((0x2f < (ulonglong)((longlong)local_440 - (longlong)param_1)) &&

     (puVar3 = param_1 + ((ulonglong)((longlong)local_440 - (longlong)param_1) >> 3),

     puVar3 < local_440)) {

    local_450 = &local_438;

    local_458 = 0;

    puVar10 = local_430;

    local_448 = param_1;

    do {

      if ((ulonglong)((longlong)local_440 - (longlong)local_448) < 0xa1) {

        iVar1 = (*param_3)(param_4,local_448,puVar3);

        if (iVar1 < 0) {

          iVar1 = (*param_3)();

          if (0 < iVar1) {

            uVar5 = *puVar3;

            *puVar3 = *local_440;

            *local_440 = uVar5;

            iVar1 = (*param_3)(param_4,local_448,puVar3);

            if (0 < iVar1) {

              uVar5 = *local_448;

              *local_448 = *puVar3;

              *puVar3 = uVar5;

            }

          }

        }

        else {

          iVar1 = (*param_3)(param_4,puVar3,local_440);

          uVar5 = *local_448;

          if (iVar1 < 1) {

            *local_448 = *puVar3;

            *puVar3 = uVar5;

            iVar1 = (*param_3)(param_4,puVar3,local_440);

            if (iVar1 < 1) goto LAB_140191413;

            uVar5 = *puVar3;

            *puVar3 = *local_440;

          }

          else {

            *local_448 = *local_440;

          }

          *local_440 = uVar5;

        }

LAB_140191413:

        puVar8 = local_448 + 1;

        puVar6 = local_440 + -1;

      }

      else {

        puVar3 = (undefined4 *)FUN_140190770(local_448,puVar3,local_440,4,param_3,param_4);

        puVar6 = local_440;

        puVar8 = local_448;

      }

      *puVar2 = *puVar3;

      do {

        iVar1 = (*param_3)(param_4,puVar8,puVar2);

        while (iVar1 < 0) {

          puVar8 = puVar8 + 1;

          iVar1 = (*param_3)(param_4,puVar8,puVar2);

        }

        iVar1 = (*param_3)(param_4,puVar2,puVar6);

        while (iVar1 < 0) {

          puVar6 = puVar6 + -1;

          iVar1 = (*param_3)(param_4,puVar2,puVar6);

        }

        if (puVar8 < puVar6) {

          uVar5 = *puVar8;

          *puVar8 = *puVar6;

          puVar8 = puVar8 + 1;

          *puVar6 = uVar5;

          puVar6 = puVar6 + -1;

        }

        else if (puVar8 == puVar6) {

          puVar8 = puVar8 + 1;

          puVar6 = puVar6 + -1;

          break;

        }

      } while (puVar8 <= puVar6);

      uVar4 = (longlong)local_440 - (longlong)puVar8;

      if ((ulonglong)((longlong)puVar6 - (longlong)local_448) < 0x30) {

        local_448 = puVar8;

        puVar6 = local_440;

        if (uVar4 < 0x30) {

          puVar10 = puVar10 + -2;

          local_458 = local_458 + -1;

          local_450 = local_450 + -2;

          if (local_458 < 0) break;

          local_448 = (undefined4 *)*local_450;

          puVar6 = (undefined4 *)*puVar10;

        }

      }

      else if (uVar4 < (ulonglong)((longlong)puVar6 - (longlong)local_448)) {

        if (0x2f < uVar4) {

          local_458 = local_458 + 1;

          *puVar10 = (ulonglong)puVar6;

          *local_450 = local_448;

          local_450 = local_450 + 2;

          puVar10 = puVar10 + 2;

          local_448 = puVar8;

          puVar6 = local_440;

        }

      }

      else {

        local_458 = local_458 + 1;

        *puVar10 = (ulonglong)local_440;

        *local_450 = puVar8;

        local_450 = local_450 + 2;

        puVar10 = puVar10 + 2;

      }

      local_440 = puVar6;

      puVar3 = local_448 + ((ulonglong)((longlong)local_440 - (longlong)local_448) >> 3);

    } while (puVar3 < local_440);

  }

  uVar4 = param_2;

  if (0xc < param_2) {

    uVar4 = 0xc;

  }

  puVar3 = param_1 + (uVar4 - 1);

  puVar8 = param_1;

  if (puVar3 != param_1) {

    do {

      iVar1 = (*param_3)(param_4,puVar8,puVar3);

      puVar6 = puVar3;

      if (iVar1 < 1) {

        puVar6 = puVar8;

      }

      puVar3 = puVar3 + -1;

      puVar8 = puVar6;

    } while (puVar3 != param_1);

    if (puVar6 != param_1) {

      uVar5 = *puVar6;

      *puVar6 = *param_1;

      *param_1 = uVar5;

    }

  }

  puVar8 = param_1;

  puVar3 = param_1;

  do {

    puVar3 = puVar3 + 1;

    if (puVar3 == param_1 + param_2) {

      FUN_1401841e0(puVar2);

      return;

    }

    *puVar2 = *puVar3;

    puVar6 = puVar8;

    puVar9 = puVar3;

    if (param_1 <= puVar8) {

      do {

        puVar7 = puVar6;

        iVar1 = (*param_3)(param_4,puVar7,puVar2);

        if (iVar1 < 1) break;

        *puVar9 = *puVar7;

        puVar6 = puVar7 + -1;

        puVar9 = puVar7;

      } while (param_1 <= puVar7 + -1);

      if (puVar9 != puVar3) {

        *puVar9 = *puVar2;

      }

    }

    puVar8 = puVar8 + 1;

  } while( true );

}




