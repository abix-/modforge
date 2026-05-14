// Address: 0x14013ec00
// Ghidra name: FUN_14013ec00
// ============ 0x14013ec00 FUN_14013ec00 (size=57) ============


undefined8 FUN_14013ec00(undefined8 param_1,undefined4 *param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  

  lVar1 = FUN_14013e670();

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0xffffffff;

  }

  if (lVar1 == 0) {

    return 0xffffffff;

  }

  uVar2 = FUN_1401589d0(lVar1,param_2);

  return uVar2;

}




