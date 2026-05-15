// Address: 0x140175280
// Ghidra name: FUN_140175280
// ============ 0x140175280 FUN_140175280 (size=103) ============


void FUN_140175280(undefined4 param_1,undefined8 param_2,char param_3)



{

  undefined4 *puVar1;

  

  puVar1 = (undefined4 *)FUN_1401841a0(1,0x28);

  if (puVar1 == (undefined4 *)0x0) {

    return;

  }

  *puVar1 = 5;

  *(bool *)(puVar1 + 2) = param_3 != '\0';

  FUN_1401750b0(param_1,param_2);

  return;

}




