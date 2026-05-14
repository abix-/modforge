// Address: 0x1401832d0
// Ghidra name: FUN_1401832d0
// ============ 0x1401832d0 FUN_1401832d0 (size=85) ============


longlong FUN_1401832d0(undefined4 param_1)



{

  char cVar1;

  longlong local_res10 [3];

  

  local_res10[0] = 0;

  cVar1 = FUN_1401aaff0(DAT_1403fcb18,param_1,local_res10);

  if (cVar1 == '\0') {

    FUN_14012e850("Keyboard %u not found",param_1);

    return 0;

  }

  if (local_res10[0] == 0) {

    FUN_14012e770();

    local_res10[0] = 0;

  }

  return local_res10[0];

}




