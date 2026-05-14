// Address: 0x14027a7f0
// Ghidra name: FUN_14027a7f0
// ============ 0x14027a7f0 FUN_14027a7f0 (size=56) ============


bool FUN_14027a7f0(undefined8 param_1,char param_2,char param_3)



{

  int iVar1;

  undefined2 local_res18;

  char local_res1a;

  

  local_res1a = param_2 + '\x06';

  local_res18 = 0x301;

  if (param_3 == '\0') {

    local_res1a = '\0';

  }

  iVar1 = FUN_140195730(param_1,&local_res18,3);

  return iVar1 == 3;

}




