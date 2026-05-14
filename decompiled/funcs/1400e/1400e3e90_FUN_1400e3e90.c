// Address: 0x1400e3e90
// Ghidra name: FUN_1400e3e90
// ============ 0x1400e3e90 FUN_1400e3e90 (size=211) ============


void FUN_1400e3e90(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

                  undefined8 param_5,undefined4 param_6)



{

  int iVar1;

  undefined1 local_d8 [16];

  code *local_c8;

  undefined8 uStack_c0;

  undefined8 local_b8;

  undefined8 local_b0;

  undefined4 local_a8;

  undefined4 local_a4;

  undefined1 local_a0 [128];

  undefined1 *local_20;

  undefined1 *local_18;

  undefined1 *local_10;

  

  local_c8 = (code *)*param_1;

  uStack_c0 = param_1[1];

  local_b8 = param_1[2];

  local_10 = local_a0;

  local_a4 = 0x80;

  local_a8 = 1;

  local_b0 = param_2;

  iVar1 = (*local_c8)(param_2,local_a0,0x80);

  if (iVar1 == 0) {

    local_20 = local_18 + -1;

    *local_20 = 0;

    local_a8 = 0;

  }

  else {

    local_20 = local_a0;

    local_18 = local_a0 + iVar1;

  }

  FUN_1400ee9e0(local_d8,param_3,param_4,param_5,param_6);

  return;

}




