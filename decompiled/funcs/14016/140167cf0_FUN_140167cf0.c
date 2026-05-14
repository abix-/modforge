// Address: 0x140167cf0
// Ghidra name: FUN_140167cf0
// ============ 0x140167cf0 FUN_140167cf0 (size=99) ============


undefined8 FUN_140167cf0(undefined8 *param_1,undefined4 *param_2)



{

  undefined8 uVar1;

  undefined4 uVar2;

  

  uVar1 = 0;

  uVar2 = 0;

  if (param_1 != (undefined8 *)0x0) {

    FUN_140179b40(*param_1);

    uVar2 = *(undefined4 *)(param_1 + 8);

    uVar1 = FUN_14015dd70(param_1[10],uVar2);

    FUN_140179b60(*param_1);

  }

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = uVar2;

  }

  return uVar1;

}




