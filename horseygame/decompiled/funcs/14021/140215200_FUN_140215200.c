// Address: 0x140215200
// Ghidra name: FUN_140215200
// ============ 0x140215200 FUN_140215200 (size=54) ============


undefined1 FUN_140215200(undefined8 param_1)



{

  char cVar1;

  char local_res10 [24];

  

  local_res10[0] = '\x01';

  cVar1 = FUN_140215240(FUN_140215880,param_1,local_res10);

  if ((cVar1 != '\0') && (local_res10[0] != '\0')) {

    return 1;

  }

  return 0;

}




