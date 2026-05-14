// Address: 0x1401309c0
// Ghidra name: FUN_1401309c0
// ============ 0x1401309c0 FUN_1401309c0 (size=62) ============


undefined8

FUN_1401309c0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  

  cVar1 = (*(code *)*param_1)(param_4,param_1[1]);

  if (cVar1 != '\0') {

    param_1[2] = param_4;

    return 0;

  }

  return 1;

}




