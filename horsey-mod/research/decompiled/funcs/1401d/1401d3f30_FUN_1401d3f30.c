// Address: 0x1401d3f30
// Ghidra name: FUN_1401d3f30
// ============ 0x1401d3f30 FUN_1401d3f30 (size=316) ============


void FUN_1401d3f30(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,

                  undefined4 param_5)



{

  undefined4 *puVar1;

  uint uVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 *puVar5;

  ulonglong uVar6;

  undefined4 *puVar7;

  int iVar8;

  int local_res8 [2];

  int local_res10 [2];

  int local_48;

  int local_44 [3];

  

  uVar2 = *(uint *)(param_2 + 8);

  uVar6 = (ulonglong)uVar2;

  iVar3 = *(int *)(param_2 + 0x10);

  puVar5 = *(undefined4 **)(param_2 + 0x18);

  puVar7 = *(undefined4 **)(param_1 + 0x18);

  FUN_1401d3710(param_1,4,param_3,param_4,param_5,local_44,&local_48,local_res8,local_res10);

  if (local_res8[0] < 0) {

    puVar7 = puVar7 + (*(int *)(param_1 + 8) + -1);

  }

  if (local_res10[0] < 0) {

    puVar7 = (undefined4 *)

             ((longlong)puVar7 +

             (longlong)((*(int *)(param_1 + 0xc) + -1) * *(int *)(param_1 + 0x10)));

  }

  iVar8 = 0;

  if (0 < *(int *)(param_2 + 0xc)) {

    do {

      if (local_44[0] == 4) {

        FUN_1402f8e20(puVar5,puVar7,(longlong)(int)uVar6 * 4);

        uVar6 = (ulonglong)*(int *)(param_2 + 8);

        puVar7 = puVar7 + uVar6;

        puVar5 = puVar5 + uVar6;

      }

      else {

        puVar1 = puVar5 + (int)uVar6;

        if (puVar5 != puVar1) {

          do {

            uVar4 = *puVar7;

            puVar7 = (undefined4 *)((longlong)puVar7 + (longlong)local_44[0]);

            *puVar5 = uVar4;

            puVar5 = puVar5 + 1;

          } while (puVar5 != puVar1);

          uVar6 = (ulonglong)*(uint *)(param_2 + 8);

        }

      }

      puVar7 = (undefined4 *)((longlong)puVar7 + (longlong)local_48);

      puVar5 = (undefined4 *)((longlong)puVar5 + (longlong)(int)(iVar3 + uVar2 * -4));

      iVar8 = iVar8 + 1;

    } while (iVar8 < *(int *)(param_2 + 0xc));

  }

  return;

}




