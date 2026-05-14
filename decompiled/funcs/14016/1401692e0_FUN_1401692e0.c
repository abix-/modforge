// Address: 0x1401692e0
// Ghidra name: FUN_1401692e0
// ============ 0x1401692e0 FUN_1401692e0 (size=89) ============


undefined8 FUN_1401692e0(undefined8 *param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  

  lVar1 = FUN_14016dcf0();

  if (param_1 != (undefined8 *)0x0) {

    *param_1 = 0;

  }

  if (lVar1 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != (undefined8 *)0x0) {

    *param_1 = *(undefined8 *)(lVar1 + 0x380);

  }

  uVar2 = FUN_140169080(*(undefined8 *)(lVar1 + 0x378),*(undefined8 *)(lVar1 + 0x380),0);

  return uVar2;

}




