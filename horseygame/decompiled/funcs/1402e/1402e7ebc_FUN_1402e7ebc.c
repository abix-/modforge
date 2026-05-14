// Address: 0x1402e7ebc
// Ghidra name: FUN_1402e7ebc
// ============ 0x1402e7ebc FUN_1402e7ebc (size=48) ============


undefined8 FUN_1402e7ebc(undefined4 *param_1)



{

  undefined4 *puVar1;

  undefined8 uVar2;

  

  if (param_1 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 0x16;

    FUN_1402cd454();

    uVar2 = 0x16;

  }

  else {

    *param_1 = DAT_1403ff7a8;

    uVar2 = 0;

  }

  return uVar2;

}




