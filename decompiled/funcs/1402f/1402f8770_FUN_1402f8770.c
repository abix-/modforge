// Address: 0x1402f8770
// Ghidra name: FUN_1402f8770
// ============ 0x1402f8770 FUN_1402f8770 (size=81) ============


undefined8 FUN_1402f8770(ulonglong *param_1)



{

  ulonglong uVar1;

  int iVar2;

  ulonglong local_res10 [3];

  

  local_res10[0] = 0;

  iVar2 = FUN_1402f86e0(local_res10);

  uVar1 = local_res10[0];

  if (iVar2 == 0) {

    local_res10[0] = local_res10[0] | 0x1f;

    *param_1 = uVar1;

    iVar2 = FUN_1402f8700(local_res10);

    if (iVar2 == 0) {

      FUN_1402f87d0();

      return 0;

    }

  }

  return 1;

}




