// Address: 0x14015c960
// Ghidra name: FUN_14015c960
// ============ 0x14015c960 FUN_14015c960 (size=40) ============


undefined1 FUN_14015c960(char *param_1,undefined8 param_2,uint param_3,undefined8 param_4)



{

  char cVar1;

  

  cVar1 = FUN_14015ec30(param_3);

  if ((cVar1 == *param_1) && (param_3 < *(uint *)(param_1 + 4))) {

    *(uint *)(param_1 + 4) = param_3;

    *(undefined8 *)(param_1 + 8) = param_4;

  }

  return 1;

}




