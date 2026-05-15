// Address: 0x140159940
// Ghidra name: FUN_140159940
// ============ 0x140159940 FUN_140159940 (size=102) ============


bool FUN_140159940(undefined4 *param_1)



{

  char cVar1;

  short local_res8 [4];

  short local_res10 [12];

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  local_18 = *param_1;

  uStack_14 = param_1[1];

  uStack_10 = param_1[2];

  uStack_c = param_1[3];

  cVar1 = FUN_1401594f0(&local_18);

  if (cVar1 == '\0') {

    local_18 = *param_1;

    uStack_14 = param_1[1];

    uStack_10 = param_1[2];

    uStack_c = param_1[3];

    FUN_1401582b0(&local_18,local_res8,local_res10,0,0);

    if (local_res8[0] != 0) {

      return local_res10[0] != 0;

    }

  }

  return false;

}




