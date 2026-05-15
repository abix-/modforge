// Address: 0x140083c30
// Ghidra name: FUN_140083c30
// ============ 0x140083c30 FUN_140083c30 (size=262) ============


void FUN_140083c30(longlong param_1,longlong param_2,undefined8 param_3,float param_4,float param_5,

                  undefined1 param_6)



{

  undefined8 local_88 [2];

  undefined4 local_78 [2];

  undefined8 local_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined1 local_58;

  undefined8 local_50;

  undefined8 local_48;

  undefined4 local_40;

  undefined1 local_3c;

  undefined8 local_38;

  undefined1 local_30;

  undefined8 local_2c;

  

  local_70 = 0;

  local_58 = 0;

  local_78[0] = 1;

  local_50 = 0;

  local_68 = 0;

  uStack_60 = 0;

  local_48 = 0;

  local_40 = 0;

  local_38 = 0;

  local_2c = 0;

  local_3c = 0;

  local_30 = 0;

  local_88[0] = param_3;

  FUN_140009f80(local_78,param_1,param_2,local_88);

  local_3c = param_4 != param_5;

  local_58 = param_6;

  local_38 = CONCAT44((param_5 * DAT_14039ca50) / DAT_140304c34,

                      (param_4 * DAT_14039ca50) / DAT_140304c34);

  local_2c = CONCAT44(*(float *)(param_2 + 0x90) * DAT_140303fe4,(undefined4)local_2c);

  FUN_1400060e0(*(undefined8 *)(param_1 + 0x58),local_78);

  return;

}




