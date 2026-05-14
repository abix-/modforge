// Address: 0x140277990
// Ghidra name: FUN_140277990
// ============ 0x140277990 FUN_140277990 (size=145) ============


undefined8 FUN_140277990(longlong param_1,longlong param_2)



{

  float fVar1;

  

  fVar1 = (DAT_14039ca44 / (float)**(uint **)(param_1 + 0x70)) * DAT_14037f68c;

  _guard_check_icall();

  *(undefined4 *)(param_2 + 0x70) = 0x10;

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  FUN_14015a190(param_2,2,fVar1);

  FUN_14015a190(param_2,1,fVar1);

  FUN_14015a220(param_2,1);

  FUN_14015a220(param_2,1);

  return 1;

}




