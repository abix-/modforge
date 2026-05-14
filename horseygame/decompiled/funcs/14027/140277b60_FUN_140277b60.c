// Address: 0x140277b60
// Ghidra name: FUN_140277b60
// ============ 0x140277b60 FUN_140277b60 (size=145) ============


undefined8 FUN_140277b60(undefined8 param_1)



{

  undefined3 uVar1;

  undefined8 uVar2;

  int iVar3;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined1 local_18;

  

  uStack_50 = 0;

  local_58 = 0x8100;

  local_48 = 0;

  uStack_40 = 0;

  local_18 = 0;

  local_38 = 0;

  uStack_30 = 0;

  local_28 = 0;

  uStack_20 = 0;

  iVar3 = FUN_140193880(0,&local_58,0x41);

  uVar2 = local_58;

  if (iVar3 == 0x41) {

    local_58._0_3_ = CONCAT21(0x387,(undefined1)local_58);

    uVar1 = (undefined3)local_58;

    local_58 = CONCAT26(SUB82(uVar2,6),0x700000000);

    local_58._0_4_ = CONCAT13(8,uVar1);

    iVar3 = FUN_140193880(param_1,&local_58,0x41);

    if (iVar3 == 0x41) {

      FUN_140193250(param_1,&local_58,0x41);

      return 1;

    }

  }

  return 0;

}




