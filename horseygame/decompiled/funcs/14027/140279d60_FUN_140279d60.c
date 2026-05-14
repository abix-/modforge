// Address: 0x140279d60
// Ghidra name: FUN_140279d60
// ============ 0x140279d60 FUN_140279d60 (size=109) ============


bool FUN_140279d60(undefined8 param_1,undefined1 param_2)



{

  char cVar1;

  undefined1 local_res18 [16];

  

  local_res18[0] = 0x55;

  cVar1 = FUN_14027a030(param_1,0xa400f0,local_res18,1,param_2);

  local_res18[0] = 0;

  FUN_14027a030(param_1,0xa400fb,local_res18,1,param_2);

  return cVar1 != '\0';

}




