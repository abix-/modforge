// Address: 0x1402753d0
// Ghidra name: FUN_1402753d0
// ============ 0x1402753d0 FUN_1402753d0 (size=75) ============


undefined1 FUN_1402753d0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  *(undefined8 *)(lVar1 + 1) = 0;

  *(undefined8 *)(lVar1 + 9) = 0;

  *(undefined8 *)(lVar1 + 0x11) = 0;

  *(undefined8 *)(lVar1 + 0x19) = 0;

  *(undefined8 *)(lVar1 + 0x21) = 0;

  *(undefined8 *)(lVar1 + 0x29) = 0;

  *(undefined8 *)(lVar1 + 0x31) = 0;

  *(undefined8 *)(lVar1 + 0x39) = 0;

  *(undefined4 *)(param_2 + 0x70) = 0xd;

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  return 1;

}




