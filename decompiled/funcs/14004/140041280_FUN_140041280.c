// Address: 0x140041280
// Ghidra name: FUN_140041280
// ============ 0x140041280 FUN_140041280 (size=957) ============


ulonglong FUN_140041280(longlong param_1,longlong param_2,int param_3,int *param_4,longlong *param_5

                       ,undefined4 *param_6)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  int iVar5;

  ulonglong uVar6;

  longlong *plVar7;

  int iVar8;

  longlong lVar9;

  int iVar10;

  int local_res8 [2];

  undefined4 local_38 [4];

  

  if (*(char *)(param_1 + 0x5c) == '\0') {

    *(undefined4 *)(param_1 + 0x9c) = 2;

    return 0;

  }

  iVar10 = 0;

  iVar3 = 0;

  if (-1 < *(int *)(param_1 + 0x710)) {

    *param_6 = 0;

    uVar6 = FUN_140055520();

    return uVar6;

  }

  *(longlong *)(param_1 + 0x40) = param_2;

  *(longlong *)(param_1 + 0x50) = param_3 + param_2;

  *(undefined4 *)(param_1 + 0x9c) = 0;

  iVar1 = FUN_14004ec60();

  if (iVar1 == 0) {

    *param_6 = 0;

    return 0;

  }

  *(undefined8 *)(param_1 + 0x764) = 0;

  iVar1 = (int)param_2;

  if (*(int *)(param_1 + 0x98) == 0) {

    while (iVar2 = FUN_14004edb0(param_1), iVar2 != 0) {

      iVar2 = FUN_14004cb40(param_1,1);

      if (iVar2 == 0) {

        uVar4 = FUN_14004cee0(*(int *)(param_1 + 0x1f0) + -1);

        iVar2 = FUN_14004cb40(param_1,uVar4);

        if ((iVar2 != -1) && (iVar2 < *(int *)(param_1 + 0x1f0))) {

          lVar9 = param_1 + (longlong)iVar2 * 6;

          if (*(char *)(lVar9 + 500) == '\0') {

            iVar2 = *(int *)(param_1 + 0xa8);

            iVar5 = 0;

          }

          else {

            iVar2 = *(int *)(param_1 + 0xac);

            iVar5 = FUN_14004cb40(param_1,1);

            iVar3 = FUN_14004cb40(param_1,1);

          }

          iVar8 = iVar2 >> 1;

          if ((*(char *)(lVar9 + 500) == '\0') || (iVar5 != 0)) {

            local_res8[0] = 0;

            iVar5 = iVar8;

            if (*(char *)(lVar9 + 500) != '\0') goto LAB_1400414b9;

          }

          else {

            local_res8[0] = iVar2 - *(int *)(param_1 + 0xa8) >> 2;

            iVar5 = *(int *)(param_1 + 0xa8) + iVar2 >> 2;

LAB_1400414b9:

            if (iVar3 == 0) {

              iVar8 = iVar2 * 3 - *(int *)(param_1 + 0xa8) >> 2;

              iVar2 = iVar2 * 3 + *(int *)(param_1 + 0xa8) >> 2;

            }

          }

          iVar3 = FUN_140053a40(param_1,local_38,lVar9 + 500,local_res8[0],iVar5,iVar8,iVar2,

                                local_res8);

          if (iVar3 != 0) {

            lVar9 = (longlong)local_res8[0];

            uVar4 = FUN_140055060(param_1,local_38[0],local_res8[0],iVar8);

            iVar3 = *(int *)(param_1 + 4);

            if (0 < iVar3) {

              plVar7 = (longlong *)(param_1 + 0x3f8);

              do {

                iVar10 = iVar10 + 1;

                *plVar7 = plVar7[-0x10] + lVar9 * 4;

                iVar3 = *(int *)(param_1 + 4);

                plVar7 = plVar7 + 1;

              } while (iVar10 < iVar3);

            }

            if (param_4 != (int *)0x0) {

              *param_4 = iVar3;

            }

            *param_6 = uVar4;

            *param_5 = param_1 + 0x3f8;

            return (ulonglong)(uint)(*(int *)(param_1 + 0x40) - iVar1);

          }

        }

        break;

      }

      if (*(char *)(param_1 + 0x5c) != '\0') {

        *(undefined4 *)(param_1 + 0x9c) = 0x23;

        break;

      }

      do {

        iVar2 = FUN_14004cab0(param_1);

        *(undefined4 *)(param_1 + 0x6f8) = 0;

      } while (iVar2 != -1);

      if (*(int *)(param_1 + 0x98) != 0) break;

    }

  }

  if (*(int *)(param_1 + 0x9c) == 0x23) {

    *(undefined4 *)(param_1 + 0x9c) = 0;

    iVar3 = FUN_14004cab0(param_1);

    *(undefined4 *)(param_1 + 0x6f8) = 0;

    if (iVar3 != -1) {

      while (*(int *)(param_1 + 0x98) == 0) {

        iVar3 = FUN_14004cab0(param_1);

        *(undefined4 *)(param_1 + 0x6f8) = 0;

        if (iVar3 == -1) {

          *param_6 = 0;

          return (ulonglong)(uint)(*(int *)(param_1 + 0x40) - iVar1);

        }

      }

    }

  }

  else {

    if ((*(int *)(param_1 + 0x9c) != 0x20) || (*(int *)(param_1 + 0x4f8) != 0)) {

      *(undefined4 *)(param_1 + 0x4f8) = 0;

      *(undefined8 *)(param_1 + 0x70c) = 0;

      *(undefined4 *)(param_1 + 0x708) = 0;

      *(undefined4 *)(param_1 + 0x584) = 0;

      *(undefined1 *)(param_1 + 0x6e5) = 0;

      *(undefined8 *)(param_1 + 0x764) = 0;

      *param_6 = 0;

      return 1;

    }

    *(undefined4 *)(param_1 + 0x9c) = 0;

    iVar3 = FUN_14004cab0(param_1);

    *(undefined4 *)(param_1 + 0x6f8) = 0;

    while ((iVar3 != -1 && (*(int *)(param_1 + 0x98) == 0))) {

      iVar3 = FUN_14004cab0(param_1);

      *(undefined4 *)(param_1 + 0x6f8) = 0;

    }

  }

  *param_6 = 0;

  return (ulonglong)(uint)(*(int *)(param_1 + 0x40) - iVar1);

}




