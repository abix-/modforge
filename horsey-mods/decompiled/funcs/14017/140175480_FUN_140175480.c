// Address: 0x140175480
// Ghidra name: FUN_140175480
// ============ 0x140175480 FUN_140175480 (size=122) ============


void FUN_140175480(undefined4 param_1,undefined8 param_2,longlong param_3)



{

  undefined4 *puVar1;

  

  if (param_3 == 0) {

    FUN_1401745e0();

    return;

  }

  puVar1 = (undefined4 *)FUN_1401841a0(1,0x28);

  if (puVar1 == (undefined4 *)0x0) {

    return;

  }

  *puVar1 = 1;

  *(longlong *)(puVar1 + 2) = param_3;

  FUN_1401750b0(param_1,param_2,puVar1);

  return;

}




