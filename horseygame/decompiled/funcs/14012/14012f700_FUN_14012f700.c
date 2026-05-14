// Address: 0x14012f700
// Ghidra name: FUN_14012f700
// ============ 0x14012f700 FUN_14012f700 (size=60) ============


longlong FUN_14012f700(undefined8 param_1)



{

  int iVar1;

  longlong lVar2;

  undefined8 local_res8 [4];

  

  lVar2 = 0;

  local_res8[0] = param_1;

  iVar1 = FUN_14012ed20(local_res8,0);

  while (iVar1 != 0) {

    lVar2 = lVar2 + 1;

    iVar1 = FUN_14012ed20(local_res8,0);

  }

  return lVar2;

}




