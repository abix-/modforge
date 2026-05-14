// Address: 0x14012f740
// Ghidra name: FUN_14012f740
// ============ 0x14012f740 FUN_14012f740 (size=79) ============


longlong FUN_14012f740(undefined8 param_1,undefined8 param_2)



{

  int iVar1;

  longlong lVar2;

  undefined8 local_res8;

  undefined8 local_res10 [3];

  

  lVar2 = 0;

  local_res8 = param_1;

  local_res10[0] = param_2;

  iVar1 = FUN_14012ed20(&local_res8,local_res10);

  while (iVar1 != 0) {

    lVar2 = lVar2 + 1;

    iVar1 = FUN_14012ed20(&local_res8,local_res10);

  }

  return lVar2;

}




