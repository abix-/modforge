// Address: 0x140055360
// Ghidra name: FUN_140055360
// ============ 0x140055360 FUN_140055360 (size=441) ============


ulonglong FUN_140055360(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  ulonglong uVar6;

  int iVar7;

  int local_res8 [2];

  undefined4 local_res10 [2];

  

  *(undefined8 *)(param_1 + 0x764) = 0;

  iVar5 = 0;

  if (*(int *)(param_1 + 0x98) == 0) {

    while (iVar2 = FUN_14004edb0(param_1), iVar2 != 0) {

      iVar2 = FUN_14004cb40(param_1,1);

      if (iVar2 == 0) {

        uVar3 = FUN_14004cee0(*(int *)(param_1 + 0x1f0) + -1);

        iVar2 = FUN_14004cb40(param_1,uVar3);

        if (iVar2 == -1) {

          return 0;

        }

        if (*(int *)(param_1 + 0x1f0) <= iVar2) {

          return 0;

        }

        lVar1 = param_1 + (longlong)iVar2 * 6;

        if (*(char *)(lVar1 + 500) == '\0') {

          iVar2 = *(int *)(param_1 + 0xa8);

          iVar4 = 0;

        }

        else {

          iVar2 = *(int *)(param_1 + 0xac);

          iVar4 = FUN_14004cb40(param_1,1);

          iVar5 = FUN_14004cb40(param_1,1);

        }

        iVar7 = iVar2 >> 1;

        if ((*(char *)(lVar1 + 500) == '\0') || (iVar4 != 0)) {

          local_res8[0] = 0;

          iVar4 = iVar7;

          if (*(char *)(lVar1 + 500) == '\0') goto LAB_1400554b1;

        }

        else {

          local_res8[0] = iVar2 - *(int *)(param_1 + 0xa8) >> 2;

          iVar4 = *(int *)(param_1 + 0xa8) + iVar2 >> 2;

        }

        if (iVar5 == 0) {

          iVar7 = iVar2 * 3 - *(int *)(param_1 + 0xa8) >> 2;

          iVar2 = iVar2 * 3 + *(int *)(param_1 + 0xa8) >> 2;

        }

LAB_1400554b1:

        uVar6 = FUN_140053a40(param_1,local_res10,lVar1 + 500,local_res8[0],iVar4,iVar7,iVar2,

                              local_res8);

        if ((int)uVar6 != 0) {

          FUN_140055060(param_1,local_res10[0],local_res8[0],iVar7);

          uVar6 = uVar6 & 0xffffffff;

        }

        return uVar6;

      }

      if (*(char *)(param_1 + 0x5c) != '\0') {

        *(undefined4 *)(param_1 + 0x9c) = 0x23;

        return 0;

      }

      do {

        iVar2 = FUN_14004cab0(param_1);

        *(undefined4 *)(param_1 + 0x6f8) = 0;

      } while (iVar2 != -1);

      if (*(int *)(param_1 + 0x98) != 0) {

        return 0;

      }

    }

  }

  return 0;

}




