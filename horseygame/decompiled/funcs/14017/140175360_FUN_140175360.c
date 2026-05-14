// Address: 0x140175360
// Ghidra name: FUN_140175360
// ============ 0x140175360 FUN_140175360 (size=97) ============


void FUN_140175360(undefined4 param_1,undefined8 param_2,undefined8 param_3)



{

  undefined4 *puVar1;

  

  puVar1 = (undefined4 *)FUN_1401841a0(1,0x28);

  if (puVar1 == (undefined4 *)0x0) {

    return;

  }

  *puVar1 = 3;

  *(undefined8 *)(puVar1 + 2) = param_3;

  FUN_1401750b0(param_1,param_2,puVar1);

  return;

}




