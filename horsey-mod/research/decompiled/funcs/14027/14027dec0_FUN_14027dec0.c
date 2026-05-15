// Address: 0x14027dec0
// Ghidra name: FUN_14027dec0
// ============ 0x14027dec0 FUN_14027dec0 (size=85) ============


undefined1 FUN_14027dec0(undefined8 param_1,longlong param_2)



{

  undefined4 uVar1;

  

  _guard_check_icall();

  uVar1 = DAT_14037fd90;

  *(undefined4 *)(param_2 + 0x70) = 0x10;

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  FUN_14015a190(param_2,2,uVar1);

  FUN_14015a190(param_2,1,DAT_14037fd90);

  return 1;

}




