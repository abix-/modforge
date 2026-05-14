// Address: 0x14012ccf0
// Ghidra name: FUN_14012ccf0
// ============ 0x14012ccf0 FUN_14012ccf0 (size=41) ============


bool FUN_14012ccf0(undefined8 param_1,ushort param_2)



{

  longlong lVar1;

  ushort local_res18 [8];

  

  local_res18[0] = param_2 >> 8 | param_2 << 8;

  lVar1 = FUN_14012cbb0(param_1,local_res18,2);

  return lVar1 == 2;

}




