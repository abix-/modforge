// Address: 0x14012cd50
// Ghidra name: FUN_14012cd50
// ============ 0x14012cd50 FUN_14012cd50 (size=38) ============


bool FUN_14012cd50(undefined8 param_1,uint param_2)



{

  longlong lVar1;

  uint local_res18 [4];

  

  local_res18[0] =

       param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 | param_2 << 0x18;

  lVar1 = FUN_14012cbb0(param_1,local_res18,4);

  return lVar1 == 4;

}




