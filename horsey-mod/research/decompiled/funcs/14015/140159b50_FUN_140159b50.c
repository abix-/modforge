// Address: 0x140159b50
// Ghidra name: FUN_140159b50
// ============ 0x140159b50 FUN_140159b50 (size=293) ============


void FUN_140159b50(char *param_1,int *param_2,int *param_3,longlong *param_4)



{

  undefined2 uVar1;

  undefined2 uVar2;

  longlong lVar3;

  char *pcVar4;

  int iVar5;

  longlong local_res8;

  

  if (param_1 != (char *)0x0) {

    pcVar4 = (char *)0x0;

    if (*param_1 == '@') {

      param_1 = (char *)FUN_14012c650(param_1 + 1,0);

      pcVar4 = param_1;

    }

    if (param_1 != (char *)0x0) {

      for (local_res8 = thunk_FUN_1402c9340(param_1,&DAT_1403333b4); local_res8 != 0;

          local_res8 = thunk_FUN_1402c9340(local_res8,&DAT_1403333b4)) {

        uVar1 = thunk_FUN_1402d8a8c(local_res8,&local_res8,0);

        local_res8 = thunk_FUN_1402c9340(local_res8,&DAT_1403333b4);

        if (local_res8 == 0) break;

        uVar2 = thunk_FUN_1402d8a8c(local_res8,&local_res8,0);

        if (*param_2 == *param_3) {

          iVar5 = *param_3 + 0x10;

          lVar3 = FUN_140184230(*param_4,(longlong)iVar5 << 2);

          if (lVar3 == 0) break;

          *param_4 = lVar3;

          *param_3 = iVar5;

        }

        *(uint *)(*param_4 + (longlong)*param_2 * 4) = CONCAT22(uVar1,uVar2);

        *param_2 = *param_2 + 1;

      }

      FUN_1401841e0(pcVar4);

    }

  }

  return;

}




