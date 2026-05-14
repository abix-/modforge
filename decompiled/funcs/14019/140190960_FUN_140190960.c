// Address: 0x140190960
// Ghidra name: FUN_140190960
// ============ 0x140190960 FUN_140190960 (size=1231) ============


void FUN_140190960(undefined4 *param_1,ulonglong param_2,ulonglong param_3,code *param_4,

                  undefined8 param_5)



{

  undefined4 uVar1;

  int iVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  ulonglong uVar7;

  undefined4 *puVar8;

  undefined4 *puVar9;

  longlong local_res18;

  undefined8 *local_468;

  ulonglong *local_460;

  undefined4 *local_458;

  undefined4 *local_450;

  undefined8 local_438;

  ulonglong local_430 [127];

  

  uVar3 = FUN_1401841f0(param_3);

  uVar7 = param_3 * 0xc;

  uVar4 = (param_2 - 1) * param_3;

  local_450 = (undefined4 *)(uVar4 + (longlong)param_1);

  if ((uVar7 <= uVar4) &&

     (puVar9 = (undefined4 *)((uVar4 / param_3 >> 1) * param_3 + (longlong)param_1),

     puVar9 < local_450)) {

    local_res18 = 0;

    local_460 = local_430;

    local_468 = &local_438;

    local_458 = param_1;

    do {

      if (param_3 * 0x28 < (ulonglong)((longlong)local_450 - (longlong)local_458)) {

        puVar9 = (undefined4 *)FUN_140190770(local_458,puVar9,local_450,param_3,param_4,param_5);

        puVar5 = local_450;

        puVar6 = local_458;

      }

      else {

        iVar2 = (*param_4)(param_5,local_458,puVar9);

        if (iVar2 < 0) {

          iVar2 = (*param_4)();

          puVar6 = puVar9;

          puVar5 = local_450;

          uVar4 = param_3;

          if (0 < iVar2) {

            do {

              uVar1 = *puVar6;

              *puVar6 = *puVar5;

              *puVar5 = uVar1;

              uVar4 = uVar4 - 4;

              puVar6 = puVar6 + 1;

              puVar5 = puVar5 + 1;

            } while (uVar4 != 0);

            iVar2 = (*param_4)(param_5,local_458,puVar9);

            puVar6 = local_458;

            puVar5 = puVar9;

            uVar4 = param_3;

            if (0 < iVar2) {

              do {

                uVar1 = *puVar6;

                *puVar6 = *puVar5;

                *puVar5 = uVar1;

                uVar4 = uVar4 - 4;

                puVar6 = puVar6 + 1;

                puVar5 = puVar5 + 1;

              } while (uVar4 != 0);

            }

          }

        }

        else {

          iVar2 = (*param_4)(param_5,puVar9,local_450);

          puVar6 = local_458;

          puVar5 = puVar9;

          puVar8 = local_450;

          uVar4 = param_3;

          if (iVar2 < 1) {

            do {

              uVar1 = *puVar6;

              *puVar6 = *puVar5;

              *puVar5 = uVar1;

              uVar4 = uVar4 - 4;

              puVar6 = puVar6 + 1;

              puVar5 = puVar5 + 1;

            } while (uVar4 != 0);

            iVar2 = (*param_4)(param_5,puVar9,local_450);

            puVar6 = puVar9;

            puVar5 = local_450;

            uVar4 = param_3;

            if (0 < iVar2) {

              do {

                uVar1 = *puVar6;

                *puVar6 = *puVar5;

                *puVar5 = uVar1;

                uVar4 = uVar4 - 4;

                puVar6 = puVar6 + 1;

                puVar5 = puVar5 + 1;

              } while (uVar4 != 0);

            }

          }

          else {

            do {

              uVar1 = *puVar6;

              *puVar6 = *puVar8;

              *puVar8 = uVar1;

              uVar4 = uVar4 - 4;

              puVar6 = puVar6 + 1;

              puVar8 = puVar8 + 1;

            } while (uVar4 != 0);

          }

        }

        puVar6 = (undefined4 *)((longlong)local_458 + param_3);

        puVar5 = (undefined4 *)((longlong)local_450 - param_3);

      }

      FUN_1402f8e20(uVar3,puVar9,param_3);

      do {

        iVar2 = (*param_4)(param_5,puVar6,uVar3);

        while (iVar2 < 0) {

          puVar6 = (undefined4 *)((longlong)puVar6 + param_3);

          iVar2 = (*param_4)(param_5,puVar6,uVar3);

        }

        iVar2 = (*param_4)(param_5,uVar3,puVar5);

        while (iVar2 < 0) {

          puVar5 = (undefined4 *)((longlong)puVar5 - param_3);

          iVar2 = (*param_4)(param_5,uVar3,puVar5);

        }

        puVar9 = puVar6;

        puVar8 = puVar5;

        uVar4 = param_3;

        if (puVar6 < puVar5) {

          do {

            uVar1 = *puVar9;

            *puVar9 = *puVar8;

            *puVar8 = uVar1;

            uVar4 = uVar4 - 4;

            puVar9 = puVar9 + 1;

            puVar8 = puVar8 + 1;

          } while (uVar4 != 0);

          puVar6 = (undefined4 *)((longlong)puVar6 + param_3);

          puVar5 = (undefined4 *)((longlong)puVar5 - param_3);

        }

        else if (puVar6 == puVar5) {

          puVar6 = (undefined4 *)((longlong)puVar6 + param_3);

          puVar5 = (undefined4 *)((longlong)puVar5 - param_3);

          break;

        }

      } while (puVar6 <= puVar5);

      uVar4 = (longlong)local_450 - (longlong)puVar6;

      if ((ulonglong)((longlong)puVar5 - (longlong)local_458) < uVar7) {

        local_458 = puVar6;

        puVar5 = local_450;

        if (uVar4 < uVar7) {

          local_res18 = local_res18 + -1;

          local_468 = local_468 + -2;

          local_460 = local_460 + -2;

          if (local_res18 < 0) break;

          local_458 = (undefined4 *)*local_468;

          puVar5 = (undefined4 *)*local_460;

        }

      }

      else if (uVar4 < (ulonglong)((longlong)puVar5 - (longlong)local_458)) {

        if (uVar7 <= uVar4) {

          local_res18 = local_res18 + 1;

          *local_468 = local_458;

          local_468 = local_468 + 2;

          *local_460 = (ulonglong)puVar5;

          local_460 = local_460 + 2;

          local_458 = puVar6;

          puVar5 = local_450;

        }

      }

      else {

        local_res18 = local_res18 + 1;

        *local_468 = puVar6;

        local_468 = local_468 + 2;

        *local_460 = (ulonglong)local_450;

        local_460 = local_460 + 2;

      }

      local_450 = puVar5;

      puVar9 = (undefined4 *)

               (((ulonglong)((longlong)local_450 - (longlong)local_458) / param_3 >> 1) * param_3 +

               (longlong)local_458);

    } while (puVar9 < local_450);

  }

  uVar4 = param_2;

  if (0xc < param_2) {

    uVar4 = 0xc;

  }

  puVar6 = (undefined4 *)((uVar4 - 1) * param_3 + (longlong)param_1);

  puVar9 = param_1;

  if (puVar6 != param_1) {

    do {

      iVar2 = (*param_4)(param_5,puVar9,puVar6);

      puVar5 = puVar6;

      if (iVar2 < 1) {

        puVar5 = puVar9;

      }

      puVar6 = (undefined4 *)((longlong)puVar6 - param_3);

      puVar9 = puVar5;

    } while (puVar6 != param_1);

    puVar9 = param_1;

    uVar4 = param_3;

    if (puVar5 != param_1) {

      do {

        uVar1 = *puVar5;

        *puVar5 = *puVar9;

        *puVar9 = uVar1;

        uVar4 = uVar4 - 4;

        puVar9 = puVar9 + 1;

        puVar5 = puVar5 + 1;

      } while (uVar4 != 0);

    }

  }

  puVar6 = param_1;

  puVar9 = param_1;

  while (puVar9 = (undefined4 *)(param_3 + (longlong)puVar9), puVar5 = puVar6,

        puVar9 != (undefined4 *)(param_2 * param_3 + (longlong)param_1)) {

    while ((param_1 <= puVar5 && (iVar2 = (*param_4)(param_5,puVar5,puVar9), 0 < iVar2))) {

      puVar5 = (undefined4 *)((longlong)puVar5 - param_3);

    }

    puVar5 = (undefined4 *)((longlong)puVar5 + param_3);

    if (puVar5 != puVar9) {

      FUN_1402f8e20(uVar3,puVar9,param_3);

      FUN_1402f8e20((longlong)puVar5 + param_3,puVar5,(longlong)puVar9 - (longlong)puVar5);

      FUN_1402f8e20(puVar5,uVar3,param_3);

    }

    puVar6 = (undefined4 *)((longlong)puVar6 + param_3);

  }

  FUN_1401841e0(uVar3);

  return;

}




