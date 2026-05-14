// Address: 0x140277a30
// Ghidra name: FUN_140277a30
// ============ 0x140277a30 FUN_140277a30 (size=100) ============


bool FUN_140277a30(longlong param_1,undefined8 param_2,undefined2 param_3,undefined2 param_4)



{

  int iVar1;

  undefined6 local_58;

  undefined2 uStack_52;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined1 local_18;

  

  local_48 = 0;

  uStack_40 = 0;

  local_18 = 0;

  local_38 = 0;

  uStack_30 = 0;

  local_28 = 0;

  uStack_20 = 0;

  _local_58 = CONCAT26(param_3,0xeb00);

  uStack_50 = (ulonglong)CONCAT22(2,param_4);

  iVar1 = FUN_140193880(*(undefined8 *)(param_1 + 0x80),&local_58,0x41);

  return iVar1 == 0x41;

}




