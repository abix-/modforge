// Address: 0x1401d4300
// Ghidra name: FUN_1401d4300
// ============ 0x1401d4300 FUN_1401d4300 (size=284) ============


void FUN_1401d4300(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,

                  undefined4 param_5)



{

  undefined1 *puVar1;

  undefined1 uVar2;

  uint uVar3;

  int iVar4;

  undefined1 *puVar5;

  ulonglong uVar6;

  undefined1 *puVar7;

  int iVar8;

  int local_res8 [2];

  int local_res10 [2];

  int local_48;

  int local_44 [3];

  

  uVar3 = *(uint *)(param_2 + 8);

  uVar6 = (ulonglong)uVar3;

  iVar4 = *(int *)(param_2 + 0x10);

  puVar5 = *(undefined1 **)(param_2 + 0x18);

  puVar7 = *(undefined1 **)(param_1 + 0x18);

  FUN_1401d3710(param_1,1,param_3,param_4,param_5,local_44,&local_48,local_res8,local_res10);

  if (local_res8[0] < 0) {

    puVar7 = puVar7 + (*(int *)(param_1 + 8) + -1);

  }

  if (local_res10[0] < 0) {

    puVar7 = puVar7 + (*(int *)(param_1 + 0xc) + -1) * *(int *)(param_1 + 0x10);

  }

  iVar8 = 0;

  if (0 < *(int *)(param_2 + 0xc)) {

    do {

      if (local_44[0] == 1) {

        FUN_1402f8e20(puVar5,puVar7,(longlong)(int)uVar6);

        uVar6 = (ulonglong)*(int *)(param_2 + 8);

        puVar7 = puVar7 + uVar6;

        puVar5 = puVar5 + uVar6;

      }

      else {

        puVar1 = puVar5 + (int)uVar6;

        if (puVar5 != puVar1) {

          do {

            uVar2 = *puVar7;

            puVar7 = puVar7 + local_44[0];

            *puVar5 = uVar2;

            puVar5 = puVar5 + 1;

          } while (puVar5 != puVar1);

          uVar6 = (ulonglong)*(uint *)(param_2 + 8);

        }

      }

      puVar7 = puVar7 + local_48;

      puVar5 = puVar5 + (int)(iVar4 - uVar3);

      iVar8 = iVar8 + 1;

    } while (iVar8 < *(int *)(param_2 + 0xc));

  }

  return;

}




