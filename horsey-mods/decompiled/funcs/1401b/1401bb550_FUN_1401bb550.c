// Address: 0x1401bb550
// Ghidra name: FUN_1401bb550
// ============ 0x1401bb550 FUN_1401bb550 (size=95) ============


undefined4 FUN_1401bb550(void *param_1,ulonglong param_2)



{

  int iVar1;

  undefined4 local_res10 [2];

  undefined4 local_res18 [4];

  

  if ((param_2 < 4) || (param_1 == (void *)0x0)) {

    return 0;

  }

  local_res10[0] = 0x7230203;

  local_res18[0] = 0x3022307;

  iVar1 = memcmp(param_1,local_res10,4);

  if ((iVar1 != 0) && (iVar1 = memcmp(param_1,local_res18,4), iVar1 != 0)) {

    return 0;

  }

  return 1;

}




