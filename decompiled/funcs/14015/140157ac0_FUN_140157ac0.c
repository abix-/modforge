// Address: 0x140157ac0
// Ghidra name: FUN_140157ac0
// ============ 0x140157ac0 FUN_140157ac0 (size=186) ============


ulonglong FUN_140157ac0(undefined4 *param_1,undefined8 param_2)



{

  char cVar1;

  uint uVar2;

  ulonglong uVar3;

  undefined2 local_res8 [4];

  undefined2 local_res18 [8];

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  local_18 = *param_1;

  uStack_14 = param_1[1];

  uStack_10 = param_1[2];

  uStack_c = param_1[3];

  FUN_1401582b0(&local_18,local_res18,local_res8,0,0);

  uVar2 = FUN_140157b80(local_res18[0],local_res8[0],param_2,1);

  if (uVar2 == 1) {

    local_18 = *param_1;

    uStack_14 = param_1[1];

    uStack_10 = param_1[2];

    uStack_c = param_1[3];

    cVar1 = FUN_140159790(&local_18);

    if (cVar1 != '\0') {

      return 3;

    }

    local_18 = *param_1;

    uStack_14 = param_1[1];

    uStack_10 = param_1[2];

    uStack_c = param_1[3];

    cVar1 = FUN_1401594b0(&local_18);

    if (cVar1 != '\0') {

      local_18 = *param_1;

      uStack_14 = param_1[1];

      uStack_10 = param_1[2];

      uStack_c = param_1[3];

      uVar3 = FUN_140207d60(&local_18);

      return uVar3;

    }

  }

  return (ulonglong)uVar2;

}




