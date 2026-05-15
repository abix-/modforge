// Address: 0x140100c90
// Ghidra name: FUN_140100c90
// ============ 0x140100c90 FUN_140100c90 (size=220) ============


void FUN_140100c90(longlong param_1,longlong param_2,undefined4 param_3,undefined4 param_4)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  longlong local_res10;

  

  local_res10 = param_2;

  iVar1 = FUN_1400c5f50(param_3,1,*(int *)(param_1 + 0x278) + -2);

  iVar2 = FUN_1400c5f50(param_4,1,*(int *)(param_1 + 0x27c) + -2);

  FUN_1400a8750(param_2);

  if ((((iVar1 < 0) || (*(int *)(param_1 + 0x278) <= iVar1)) || (iVar2 < 0)) ||

     (*(int *)(param_1 + 0x27c) <= iVar2)) {

    puVar3 = &DAT_1403dc390;

  }

  else {

    puVar3 = (undefined4 *)

             (*(longlong *)(param_1 + 0x270) +

             (longlong)(*(int *)(param_1 + 0x278) * iVar2 + iVar1) * 0x28);

  }

  *(longlong *)(puVar3 + 4) = param_2;

  *(int *)(param_2 + 0x60) = iVar2 * *(int *)(param_1 + 0x278) + iVar1;

  FUN_14003e600(param_1 + 0xb8,&local_res10);

  return;

}




