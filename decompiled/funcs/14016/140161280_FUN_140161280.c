// Address: 0x140161280
// Ghidra name: FUN_140161280
// ============ 0x140161280 FUN_140161280 (size=85) ============


longlong FUN_140161280(undefined4 param_1)



{

  char cVar1;

  longlong local_res10 [3];

  

  local_res10[0] = 0;

  cVar1 = FUN_1401aaff0(DAT_1403fc338,param_1,local_res10);

  if (cVar1 == '\0') {

    FUN_14012e850("Mouse %u not found",param_1);

    return 0;

  }

  if (local_res10[0] == 0) {

    FUN_14012e770();

    local_res10[0] = 0;

  }

  return local_res10[0];

}




