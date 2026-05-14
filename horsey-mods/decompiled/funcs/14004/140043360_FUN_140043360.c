// Address: 0x140043360
// Ghidra name: FUN_140043360
// ============ 0x140043360 FUN_140043360 (size=449) ============


int FUN_140043360(longlong param_1,int param_2,longlong *param_3,int param_4)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  longlong *plVar4;

  longlong lVar5;

  longlong lVar6;

  int local_res8;

  undefined1 local_58 [24];

  

  local_res8 = 0;

  iVar1 = *(int *)(param_1 + 4);

  if (param_2 < *(int *)(param_1 + 4)) {

    iVar1 = param_2;

  }

  lVar5 = (longlong)iVar1;

  if (0 < param_4) {

    do {

      iVar2 = *(int *)(param_1 + 0x768) - *(int *)(param_1 + 0x764);

      iVar1 = param_4 - local_res8;

      if (iVar2 + local_res8 < param_4) {

        iVar1 = iVar2;

      }

      if (iVar1 != 0) {

        lVar3 = 0;

        if (0 < lVar5) {

          plVar4 = param_3;

          lVar6 = lVar5;

          do {

            FUN_1402f8e20(*plVar4 + (longlong)local_res8 * 4,

                          *(longlong *)((longlong)plVar4 + (param_1 - (longlong)param_3) + 0x378) +

                          (longlong)*(int *)(param_1 + 0x764) * 4,(longlong)iVar1 * 4);

            plVar4 = plVar4 + 1;

            lVar6 = lVar6 + -1;

            lVar3 = lVar5;

          } while (lVar6 != 0);

        }

        if (lVar3 < param_2) {

          do {

            FUN_1402f94c0(param_3[lVar3] + (longlong)local_res8 * 4,0,(longlong)iVar1 * 4);

            lVar3 = lVar3 + 1;

          } while (lVar3 < param_2);

        }

      }

      *(int *)(param_1 + 0x764) = *(int *)(param_1 + 0x764) + iVar1;

      local_res8 = local_res8 + iVar1;

    } while (((local_res8 != param_4) && (iVar1 = FUN_140042b70(param_1,0,local_58), iVar1 != 0)) &&

            (local_res8 < param_4));

    return local_res8;

  }

  return 0;

}




