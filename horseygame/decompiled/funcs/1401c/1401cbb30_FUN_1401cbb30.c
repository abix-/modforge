// Address: 0x1401cbb30
// Ghidra name: FUN_1401cbb30
// ============ 0x1401cbb30 FUN_1401cbb30 (size=188) ============


void FUN_1401cbb30(longlong param_1)



{

  int iVar1;

  undefined4 local_res8 [2];

  longlong *local_res10 [3];

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined4 *puStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  local_res10[0] = (longlong *)0x0;

  local_res8[0] = 3;

  iVar1 = (**(code **)**(undefined8 **)(param_1 + 0x70))

                    (*(undefined8 **)(param_1 + 0x70),&DAT_140349388,local_res10);

  if (-1 < iVar1) {

    puStack_20 = local_res8;

    local_28 = 1;

    local_68 = 0;

    uStack_60 = 0;

    local_58 = 0;

    uStack_50 = 0;

    local_48 = 0;

    uStack_40 = 0;

    local_38 = 0;

    uStack_30 = 0;

    local_18 = 0;

    uStack_10 = 0;

    (**(code **)(*local_res10[0] + 0x88))(local_res10[0],&local_68);

    (**(code **)(*local_res10[0] + 0xf8))(local_res10[0],0,1);

    (**(code **)(*local_res10[0] + 0x10))();

  }

  return;

}




