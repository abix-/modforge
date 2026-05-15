// Address: 0x140111c50
// Ghidra name: FUN_140111c50
// ============ 0x140111c50 FUN_140111c50 (size=706) ============


void FUN_140111c50(undefined8 *param_1,undefined8 *param_2,longlong param_3,code *param_4)



{

  undefined8 uVar1;

  longlong lVar2;

  undefined8 *puVar3;

  char cVar4;

  ulonglong uVar5;

  longlong lVar6;

  undefined8 *puVar7;

  undefined8 *puVar8;

  longlong lVar9;

  longlong lVar10;

  undefined8 *local_res10;

  undefined8 *local_48;

  undefined8 *local_40;

  

  uVar5 = (longlong)param_2 - (longlong)param_1;

  puVar7 = param_2;

  while( true ) {

    local_res10 = param_2;

    if ((longlong)(uVar5 & 0xfffffffffffffff8) < 0x101) {

      if (param_1 != puVar7) {

        for (puVar8 = param_1 + 1; puVar8 != puVar7; puVar8 = puVar8 + 1) {

          uVar1 = *puVar8;

          cVar4 = (*param_4)(uVar1,*param_1);

          if (cVar4 == '\0') {

            cVar4 = (*param_4)(uVar1,puVar8[-1]);

            puVar3 = puVar8;

            while (cVar4 != '\0') {

              *puVar3 = puVar3[-1];

              cVar4 = (*param_4)(uVar1,puVar3[-2]);

              puVar3 = puVar3 + -1;

            }

            *puVar3 = uVar1;

          }

          else {

            FUN_1402f8e20(param_1 + 1,param_1,(longlong)puVar8 - (longlong)param_1);

            *param_1 = uVar1;

          }

        }

      }

      return;

    }

    if (param_3 < 1) break;

    FUN_1401110b0(&local_48,param_1,puVar7,param_4);

    puVar3 = local_40;

    puVar8 = local_48;

    param_3 = (param_3 >> 1) + (param_3 >> 2);

    if ((longlong)((longlong)local_48 - (longlong)param_1 & 0xfffffffffffffff8U) <

        (longlong)((longlong)puVar7 - (longlong)local_40 & 0xfffffffffffffff8U)) {

      FUN_140111c50(param_1,local_48,param_3,param_4);

      param_1 = puVar3;

      puVar8 = puVar7;

    }

    else {

      FUN_140111c50(local_40,puVar7,param_3,param_4);

      local_res10 = puVar8;

    }

    uVar5 = (longlong)puVar8 - (longlong)param_1;

    puVar7 = puVar8;

    param_2 = local_res10;

  }

  uVar5 = (longlong)puVar7 - (longlong)param_1 >> 3;

  lVar9 = (longlong)puVar7 - (longlong)param_1 >> 4;

  local_res10 = puVar7;

  if (0 < lVar9) {

    lVar10 = (longlong)(uVar5 - 1) >> 1;

    local_res10 = param_2;

    do {

      uVar1 = param_1[lVar9 + -1];

      lVar9 = lVar9 + -1;

      lVar2 = lVar9;

      while (lVar2 < lVar10) {

        cVar4 = (*param_4)(param_1[lVar2 * 2 + 2],param_1[lVar2 * 2 + 1]);

        lVar6 = (2 - (ulonglong)(cVar4 != '\0')) + lVar2 * 2;

        param_1[lVar2] = param_1[lVar6];

        lVar2 = lVar6;

      }

      if ((lVar2 == lVar10) && ((uVar5 & 1) == 0)) {

        param_1[lVar2] = param_1[uVar5 - 1];

        lVar2 = uVar5 - 1;

      }

      while (lVar9 < lVar2) {

        lVar6 = lVar2 + -1 >> 1;

        cVar4 = (*param_4)(param_1[lVar6],uVar1);

        if (cVar4 == '\0') break;

        param_1[lVar2] = param_1[lVar6];

        lVar2 = lVar6;

      }

      param_1[lVar2] = uVar1;

    } while (0 < lVar9);

  }

  if ((longlong)uVar5 < 2) {

    return;

  }

  puVar7 = local_res10 + -1;

  do {

    local_res10 = (undefined8 *)*puVar7;

    *puVar7 = *param_1;

    FUN_140111950(param_1,0,(longlong)puVar7 - (longlong)param_1 >> 3,&local_res10,param_4);

    puVar7 = puVar7 + -1;

  } while (0xf < (longlong)((8 - (longlong)param_1) + (longlong)puVar7 & 0xfffffffffffffff8U));

  return;

}




