// Address: 0x1401752f0
// Ghidra name: FUN_1401752f0
// ============ 0x1401752f0 FUN_1401752f0 (size=98) ============


void FUN_1401752f0(undefined4 param_1,undefined8 param_2,undefined4 param_3)



{

  undefined4 *puVar1;

  

  puVar1 = (undefined4 *)FUN_1401841a0(1,0x28);

  if (puVar1 == (undefined4 *)0x0) {

    return;

  }

  puVar1[2] = param_3;

  *puVar1 = 4;

  FUN_1401750b0(param_1,param_2,puVar1);

  return;

}




