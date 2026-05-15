// Address: 0x140042f50
// Ghidra name: FUN_140042f50
// ============ 0x140042f50 FUN_140042f50 (size=1020) ============


int FUN_140042f50(longlong param_1,int param_2,undefined4 *param_3,int param_4)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  longlong *plVar4;

  int iVar5;

  ulonglong uVar6;

  int iVar7;

  longlong lVar8;

  ulonglong uVar9;

  longlong lVar10;

  int local_res8;

  int local_res20 [2];

  int local_48;

  uint local_44;

  

  local_res8 = 0;

  local_44 = (uint)((longlong)param_4 / (longlong)param_2);

  uVar6 = (longlong)param_4 / (longlong)param_2 & 0xffffffff;

  iVar1 = *(int *)(param_1 + 4);

  if (param_2 < *(int *)(param_1 + 4)) {

    iVar1 = param_2;

  }

  lVar10 = (longlong)iVar1;

  if ((int)local_44 < 1) {

    return 0;

  }

  do {

    iVar7 = 0;

    iVar5 = (int)uVar6;

    iVar3 = *(int *)(param_1 + 0x768) - *(int *)(param_1 + 0x764);

    iVar1 = iVar5 - local_res8;

    if (iVar3 + local_res8 < iVar5) {

      iVar1 = iVar3;

    }

    if (0 < iVar1) {

      do {

        uVar6 = 0;

        uVar9 = uVar6;

        if (3 < lVar10) {

          lVar8 = (lVar10 - 4U >> 2) + 1;

          uVar9 = (ulonglong)(uint)((int)lVar8 * 4);

          uVar6 = lVar8 * 4;

          plVar4 = (longlong *)(param_1 + 0x380);

          do {

            *param_3 = *(undefined4 *)

                        (plVar4[-1] + (longlong)(*(int *)(param_1 + 0x764) + iVar7) * 4);

            param_3[1] = *(undefined4 *)

                          (*plVar4 + (longlong)(*(int *)(param_1 + 0x764) + iVar7) * 4);

            param_3[2] = *(undefined4 *)

                          (plVar4[1] + (longlong)(*(int *)(param_1 + 0x764) + iVar7) * 4);

            param_3[3] = *(undefined4 *)

                          (plVar4[2] + (longlong)(*(int *)(param_1 + 0x764) + iVar7) * 4);

            param_3 = param_3 + 4;

            lVar8 = lVar8 + -1;

            plVar4 = plVar4 + 4;

          } while (lVar8 != 0);

        }

        iVar3 = (int)uVar9;

        if ((longlong)uVar6 < lVar10) {

          lVar8 = lVar10 - uVar6;

          iVar3 = iVar3 + (int)lVar8;

          plVar4 = (longlong *)(param_1 + 0x378 + uVar6 * 8);

          do {

            *param_3 = *(undefined4 *)(*plVar4 + (longlong)(*(int *)(param_1 + 0x764) + iVar7) * 4);

            param_3 = param_3 + 1;

            lVar8 = lVar8 + -1;

            plVar4 = plVar4 + 1;

          } while (lVar8 != 0);

        }

        if (iVar3 < param_2) {

          FUN_1402f94c0(param_3,0,(longlong)(param_2 - iVar3) * 4);

          param_3 = param_3 + (param_2 - iVar3);

        }

        iVar7 = iVar7 + 1;

      } while (iVar7 < iVar1);

    }

    *(int *)(param_1 + 0x764) = *(int *)(param_1 + 0x764) + iVar1;

    local_res8 = local_res8 + iVar1;

    if (local_res8 == iVar5) {

      return local_res8;

    }

    if (*(char *)(param_1 + 0x5c) != '\0') {

      *(undefined4 *)(param_1 + 0x9c) = 2;

      return local_res8;

    }

    iVar1 = *(int *)(param_1 + 0x98);

    *(undefined8 *)(param_1 + 0x764) = 0;

    while( true ) {

      if ((iVar1 != 0) || (iVar1 = FUN_14004edb0(param_1), iVar1 == 0)) goto LAB_140043307;

      iVar1 = FUN_14004cb40(param_1,1);

      iVar3 = 0;

      if (iVar1 == 0) break;

      if (*(char *)(param_1 + 0x5c) != '\0') {

        *(undefined4 *)(param_1 + 0x9c) = 0x23;

        goto LAB_140043307;

      }

      do {

        iVar1 = FUN_14004cab0(param_1);

        *(undefined4 *)(param_1 + 0x6f8) = 0;

      } while (iVar1 != -1);

      iVar1 = *(int *)(param_1 + 0x98);

    }

    uVar2 = FUN_14004cee0(*(int *)(param_1 + 0x1f0) + -1);

    iVar1 = FUN_14004cb40(param_1,uVar2);

    if ((iVar1 == -1) || (*(int *)(param_1 + 0x1f0) <= iVar1)) goto LAB_140043307;

    lVar8 = param_1 + (longlong)iVar1 * 6;

    if (*(char *)(lVar8 + 500) == '\0') {

      iVar1 = *(int *)(param_1 + 0xa8);

      iVar7 = iVar3;

    }

    else {

      iVar1 = *(int *)(param_1 + 0xac);

      iVar3 = FUN_14004cb40(param_1,1);

      iVar7 = FUN_14004cb40(param_1,1);

    }

    iVar5 = iVar1 >> 1;

    if ((*(char *)(lVar8 + 500) == '\0') || (iVar3 != 0)) {

      local_res20[0] = 0;

      iVar3 = iVar5;

      if (*(char *)(lVar8 + 500) != '\0') goto LAB_14004323d;

    }

    else {

      local_res20[0] = iVar1 - *(int *)(param_1 + 0xa8) >> 2;

      iVar3 = *(int *)(param_1 + 0xa8) + iVar1 >> 2;

LAB_14004323d:

      if (iVar7 == 0) {

        iVar5 = iVar1 * 3 - *(int *)(param_1 + 0xa8) >> 2;

        iVar1 = iVar1 * 3 + *(int *)(param_1 + 0xa8) >> 2;

      }

    }

    iVar3 = FUN_140053a40(param_1,&local_48,lVar8 + 500,local_res20[0],iVar3,iVar5,iVar1,local_res20

                         );

    iVar1 = local_res20[0];

    if (iVar3 == 0) {

LAB_140043307:

      *(undefined8 *)(param_1 + 0x764) = 0;

      return local_res8;

    }

    lVar8 = (longlong)local_res20[0];

    local_48 = FUN_140055060(param_1,local_48,local_res20[0]);

    iVar3 = 0;

    if (0 < *(int *)(param_1 + 4)) {

      plVar4 = (longlong *)(param_1 + 0x3f8);

      do {

        iVar3 = iVar3 + 1;

        *plVar4 = plVar4[-0x10] + lVar8 * 4;

        plVar4 = plVar4 + 1;

      } while (iVar3 < *(int *)(param_1 + 4));

    }

    *(int *)(param_1 + 0x764) = iVar1;

    *(int *)(param_1 + 0x768) = local_48 + iVar1;

    if (local_48 == 0) {

      return local_res8;

    }

    uVar6 = (ulonglong)local_44;

    if ((int)local_44 <= local_res8) {

      return local_res8;

    }

  } while( true );

}




