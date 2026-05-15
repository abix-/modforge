// Address: 0x14026e410
// Ghidra name: FUN_14026e410
// ============ 0x14026e410 FUN_14026e410 (size=134) ============


undefined4 FUN_14026e410(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined4 uVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  *(longlong *)(lVar1 + 8) = param_2;

  *(undefined1 *)(lVar1 + 0x13) = 0;

  *(undefined2 *)(lVar1 + 0x18) = 0;

  *(undefined8 *)(lVar1 + 0x1a) = 0;

  *(undefined8 *)(lVar1 + 0x22) = 0;

  *(undefined8 *)(lVar1 + 0x2a) = 0;

  *(undefined8 *)(lVar1 + 0x32) = 0;

  *(undefined8 *)(lVar1 + 0x3a) = 0;

  *(undefined8 *)(lVar1 + 0x42) = 0;

  *(undefined8 *)(lVar1 + 0x4a) = 0;

  *(undefined8 *)(lVar1 + 0x52) = 0;

  uVar2 = FUN_140158960(param_2);

  *(undefined4 *)(lVar1 + 0x14) = uVar2;

  *(undefined4 *)(param_2 + 0x70) = 0xb;

  *(undefined4 *)(param_2 + 0x44) = 6;

  if (*(char *)(lVar1 + 0x11) != '\0') {

    *(undefined4 *)(param_2 + 0x44) = 0x10;

  }

  uVar2 = DAT_14039ca5c;

  *(undefined4 *)(param_2 + 0x60) = 1;

  FUN_14015a190(param_2,1,uVar2);

  return 1;

}




