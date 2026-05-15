// Address: 0x140275e10
// Ghidra name: FUN_140275e10
// ============ 0x140275e10 FUN_140275e10 (size=145) ============


undefined8 FUN_140275e10(longlong param_1,undefined8 param_2,char param_3)



{

  longlong lVar1;

  uint5 uVar2;

  int iVar3;

  undefined8 uVar4;

  undefined1 local_58 [8];

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined1 local_18;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  local_18 = 0;

  uStack_50 = 0;

  local_58._0_5_ = 0x1830008700;

  local_48 = 0;

  uStack_40 = 0;

  local_38 = 0;

  uStack_30 = 0;

  local_28 = 0;

  uStack_20 = 0;

  if (param_3 == '\0') {

    local_58._0_5_ = 0x30008700;

  }

  uVar2 = (uint5)local_58._0_5_ >> 0x18;

  local_58._0_3_ = CONCAT12(3,(undefined2)local_58._0_5_);

  local_58 = (undefined1  [8])CONCAT53(uVar2,local_58._0_3_);

  iVar3 = FUN_140277070(0,local_58,6);

  if (iVar3 < 0) {

    uVar4 = FUN_14012e850("Couldn\'t write feature report");

    return uVar4;

  }

  *(char *)(lVar1 + 9) = param_3;

  return 1;

}




