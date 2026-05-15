// Address: 0x140161330
// Ghidra name: FUN_140161330
// ============ 0x140161330 FUN_140161330 (size=79) ============


void FUN_140161330(undefined4 *param_1,undefined4 *param_2)



{

  longlong lVar1;

  

  lVar1 = FUN_1401611a0();

  if (param_1 != (undefined4 *)0x0) {

    *param_1 = *(undefined4 *)(lVar1 + 0x98);

  }

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = *(undefined4 *)(lVar1 + 0x9c);

  }

  *(undefined8 *)(lVar1 + 0x98) = 0;

  FUN_1401611b0(lVar1,0,1);

  return;

}




