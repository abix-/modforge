// Address: 0x140223a10
// Ghidra name: FUN_140223a10
// ============ 0x140223a10 FUN_140223a10 (size=258) ============


undefined8 FUN_140223a10(longlong param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  char *pcVar3;

  int iVar4;

  int iVar5;

  undefined8 local_res8;

  

  local_res8 = 0;

  iVar4 = -1;

  if (*(int *)(param_1 + 0xc) < 1) {

    return 0;

  }

  iVar5 = -param_3;

  do {

    iVar1 = *(int *)(param_1 + 8);

    iVar2 = 0;

    pcVar3 = (char *)((longlong)((iVar5 + param_3) * *(int *)(param_1 + 0x10)) +

                     *(longlong *)(param_1 + 0x18));

    if (0 < iVar1) {

      do {

        if (*pcVar3 == '\0') {

          if (iVar4 != -1) {

            FUN_1402239a0(&local_res8,iVar4 + param_2,param_3,iVar2 + param_2,param_3 + 1);

            iVar1 = *(int *)(param_1 + 8);

            iVar4 = -1;

          }

        }

        else if (iVar4 == -1) {

          iVar4 = iVar2;

        }

        pcVar3 = pcVar3 + 4;

        iVar2 = iVar2 + 1;

      } while (iVar2 < iVar1);

    }

    if (iVar4 != -1) {

      FUN_1402239a0(&local_res8,iVar4 + param_2,param_3,iVar2 + param_2,param_3 + 1);

      iVar4 = -1;

    }

    param_3 = param_3 + 1;

  } while (iVar5 + param_3 < *(int *)(param_1 + 0xc));

  return local_res8;

}




