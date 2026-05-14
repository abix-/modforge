// Address: 0x14017d8a0
// Ghidra name: FUN_14017d8a0
// ============ 0x14017d8a0 FUN_14017d8a0 (size=241) ============


void FUN_14017d8a0(undefined2 *param_1,int param_2,undefined4 param_3,uint param_4,int param_5)



{

  longlong lVar1;

  uint uVar2;

  undefined2 *puVar3;

  undefined2 uVar4;

  longlong local_38;

  

  lVar1 = (longlong)(int)param_4;

  if (param_5 != 0) {

    uVar4 = (undefined2)param_3;

    if (1 < (int)param_4) {

      do {

        puVar3 = param_1;

        uVar2 = param_4;

        local_38 = lVar1;

        if (((ulonglong)param_1 & 2) != 0) {

          local_38 = lVar1 + -1;

          *param_1 = uVar4;

          puVar3 = param_1 + 1;

          uVar2 = param_4 - 1;

        }

        FUN_140197aa0(puVar3,param_3,(longlong)((int)uVar2 >> 1));

        if ((uVar2 & 1) != 0) {

          puVar3[local_38 + -1] = uVar4;

        }

        param_1 = (undefined2 *)((longlong)param_1 + (longlong)param_2);

        param_5 = param_5 + -1;

      } while (param_5 != 0);

      return;

    }

    do {

      if ((param_4 & 1) != 0) {

        param_1[lVar1 + -1] = uVar4;

      }

      param_1 = (undefined2 *)((longlong)param_1 + (longlong)param_2);

      param_5 = param_5 + -1;

    } while (param_5 != 0);

  }

  return;

}




