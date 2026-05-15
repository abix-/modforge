// Address: 0x1401a15b0
// Ghidra name: FUN_1401a15b0
// ============ 0x1401a15b0 FUN_1401a15b0 (size=176) ============


undefined8

FUN_1401a15b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

             undefined4 param_5,undefined8 param_6)



{

  undefined8 *puVar1;

  undefined8 uVar2;

  

  puVar1 = (undefined8 *)thunk_FUN_1401841f0(0x4888);

  if (puVar1 == (undefined8 *)0x0) {

    FUN_14019f050("Out of memory");

    uVar2 = 0;

  }

  else {

    FUN_1402f94c0(puVar1 + 1,0,0x4880);

    *puVar1 = param_1;

    FUN_1401a4a60(puVar1);

    uVar2 = FUN_14019ba80(puVar1,param_2,param_3,param_4,param_5,param_6);

    FUN_1401841e0(puVar1);

  }

  return uVar2;

}




