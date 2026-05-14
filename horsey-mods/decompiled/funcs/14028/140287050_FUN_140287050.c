// Address: 0x140287050
// Ghidra name: FUN_140287050
// ============ 0x140287050 FUN_140287050 (size=480) ============


void FUN_140287050(longlong param_1)



{

  longlong *plVar1;

  undefined1 uVar2;

  int iVar3;

  int iVar4;

  undefined8 uVar5;

  ushort *puVar6;

  int iVar7;

  longlong lVar8;

  longlong lVar9;

  int iVar10;

  int local_res8 [2];

  undefined1 local_c28 [4];

  ushort local_c24 [1534];

  

  uVar5 = FUN_140149300();

  local_res8[0] = 0x80;

  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

  iVar3 = (**(code **)(*plVar1 + 0x50))(plVar1,0x18,local_c28,local_res8,0);

  if ((iVar3 == -0x7ff8ffe2) || (iVar3 == -0x7ff8fff4)) {

    (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 0x38))();

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

    iVar3 = (**(code **)(*plVar1 + 0x50))(plVar1,0x18,local_c28,local_res8,0);

  }

  if (-1 < iVar3) {

    iVar10 = 0;

    if (0 < local_res8[0]) {

      puVar6 = local_c24;

      iVar4 = local_res8[0];

      do {

        lVar8 = *(longlong *)(param_1 + 0x148);

        iVar7 = 0;

        if (0 < *(int *)(lVar8 + 0xc48)) {

          lVar9 = 0x48;

          do {

            if (*(int *)(puVar6 + -2) == *(int *)(lVar9 + lVar8)) {

              iVar4 = *(int *)(lVar9 + 4 + lVar8);

              if (iVar4 == 0) {

                FUN_14015ad00(uVar5,param_1,*(undefined1 *)(lVar9 + 8 + lVar8),*(int *)puVar6 != 0);

              }

              else if (iVar4 == 1) {

                FUN_14015aab0(uVar5,param_1,*(undefined1 *)(lVar9 + 8 + lVar8),*puVar6);

              }

              else if (iVar4 == 2) {

                uVar2 = FUN_140286ff0(*(int *)puVar6);

                FUN_14015ae90(uVar5,param_1,*(undefined1 *)(lVar9 + 8 + lVar8),uVar2);

              }

            }

            lVar8 = *(longlong *)(param_1 + 0x148);

            iVar7 = iVar7 + 1;

            lVar9 = lVar9 + 0xc;

            iVar4 = local_res8[0];

          } while (iVar7 < *(int *)(lVar8 + 0xc48));

        }

        iVar10 = iVar10 + 1;

        puVar6 = puVar6 + 0xc;

      } while (iVar10 < iVar4);

    }

    if (iVar3 == 1) {

      FUN_140287230(param_1);

    }

  }

  return;

}




