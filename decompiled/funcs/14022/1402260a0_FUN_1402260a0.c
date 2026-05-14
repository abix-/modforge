// Address: 0x1402260a0
// Ghidra name: FUN_1402260a0
// ============ 0x1402260a0 FUN_1402260a0 (size=138) ============


undefined8 FUN_1402260a0(HMONITOR param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)



{

  BOOL BVar1;

  undefined1 local_78 [44];

  undefined8 uStack_4c;

  undefined8 local_44;

  undefined8 uStack_3c;

  undefined8 local_34;

  undefined8 uStack_2c;

  undefined8 local_24;

  undefined8 uStack_1c;

  undefined4 local_14;

  

  local_78._0_4_ = 0x68;

  local_78._4_4_ = 0;

  local_78._8_4_ = 0;

  local_78._12_4_ = 0;

  local_78._16_4_ = 0;

  local_14 = 0;

  local_78._20_4_ = 0;

  local_78._24_4_ = 0;

  local_78._28_4_ = 0;

  local_78._32_4_ = 0;

  local_78._36_8_ = 0;

  uStack_4c = 0;

  local_44 = 0;

  uStack_3c = 0;

  local_34 = 0;

  uStack_2c = 0;

  local_24 = 0;

  uStack_1c = 0;

  BVar1 = GetMonitorInfoW(param_1,(LPMONITORINFO)local_78);

  if ((BVar1 != 0) && ((local_78[0x24] & 1) == *(byte *)((longlong)param_4 + 0xc))) {

    FUN_140225c60(*param_4,param_1,local_78,param_4 + 1);

  }

  return 1;

}




