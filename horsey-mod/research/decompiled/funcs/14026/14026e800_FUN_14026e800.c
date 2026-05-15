// Address: 0x14026e800
// Ghidra name: FUN_14026e800
// ============ 0x14026e800 FUN_14026e800 (size=158) ============


undefined8 FUN_14026e800(longlong param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  *(longlong *)(lVar1 + 8) = param_2;

  *(undefined8 *)(lVar1 + 0x1a) = 0;

  *(undefined8 *)(lVar1 + 0x22) = 0;

  *(undefined8 *)(lVar1 + 0x2a) = 0;

  *(undefined8 *)(lVar1 + 0x32) = 0;

  *(undefined8 *)(lVar1 + 0x3a) = 0;

  *(undefined8 *)(lVar1 + 0x42) = 0;

  *(undefined8 *)(lVar1 + 0x4a) = 0;

  *(undefined8 *)(lVar1 + 0x52) = 0;

  *(undefined4 *)(param_2 + 0x70) = 0xb;

  *(undefined4 *)(param_2 + 0x44) = 6;

  if (*(char *)(lVar1 + 0x11) != '\0') {

    *(undefined4 *)(param_2 + 0x44) = 0x10;

  }

  *(undefined4 *)(param_2 + 0x60) = 1;

  if ((*(short *)(param_1 + 0x20) == 0x2563) && (*(short *)(param_1 + 0x22) == 0x575)) {

    *(undefined4 *)(param_2 + 0xe4) = 2;

  }

  FUN_14015a190(param_2,1,DAT_14039ca5c);

  return 1;

}




