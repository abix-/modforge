// Address: 0x140101cc0
// Ghidra name: FUN_140101cc0
// ============ 0x140101cc0 FUN_140101cc0 (size=238) ============


int FUN_140101cc0(longlong param_1,int param_2,int param_3,int param_4)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  int iVar6;

  

  iVar6 = 0;

  iVar2 = FUN_1400c5c30(0,param_3 - param_4);

  iVar3 = FUN_1400c5c20(*(int *)(param_1 + 0x27c) + -1,param_3 + param_4);

  if (iVar2 <= iVar3) {

    do {

      iVar3 = FUN_1400c5c30(0,param_2 - param_4);

      iVar4 = FUN_1400c5c20(*(int *)(param_1 + 0x278) + -1,param_4 + param_2);

      if (iVar3 <= iVar4) {

        do {

          lVar5 = (longlong)(*(int *)(param_1 + 0x278) * iVar2 + iVar3);

          lVar1 = *(longlong *)(param_1 + 0x270);

          if (*(int *)(lVar1 + 0x18 + lVar5 * 0x28) == 0) {

            iVar6 = iVar6 + *(int *)(lVar1 + 4 + lVar5 * 0x28);

          }

          iVar6 = iVar6 + *(int *)(lVar1 + 0x20 + lVar5 * 0x28);

          iVar3 = iVar3 + 1;

          iVar4 = FUN_1400c5c20(*(int *)(param_1 + 0x278) + -1,param_4 + param_2);

        } while (iVar3 <= iVar4);

      }

      iVar2 = iVar2 + 1;

      iVar3 = FUN_1400c5c20(*(int *)(param_1 + 0x27c) + -1,param_3 + param_4);

    } while (iVar2 <= iVar3);

  }

  return iVar6;

}




