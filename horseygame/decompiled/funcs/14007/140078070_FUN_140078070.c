// Address: 0x140078070
// Ghidra name: FUN_140078070
// ============ 0x140078070 FUN_140078070 (size=66) ============


void FUN_140078070(undefined8 *param_1,char param_2,undefined1 param_3)



{

  char local_res10 [8];

  undefined1 local_res18 [16];

  

  local_res10[0] = param_2 + -0x80;

  local_res18[0] = param_3;

  (*(code *)*param_1)(param_1[1],local_res10,1);

  (*(code *)*param_1)(param_1[1],local_res18,1);

  return;

}




