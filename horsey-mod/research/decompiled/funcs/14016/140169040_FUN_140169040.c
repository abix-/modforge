// Address: 0x140169040
// Ghidra name: FUN_140169040
// ============ 0x140169040 FUN_140169040 (size=64) ============


char * FUN_140169040(char *param_1,undefined8 param_2,size_t *param_3)



{

  size_t sVar1;

  

  if (param_1 != (char *)0x0) {

    sVar1 = strlen(param_1);

    *param_3 = sVar1;

    return param_1;

  }

  *param_3 = 0;

  return (char *)0x0;

}




