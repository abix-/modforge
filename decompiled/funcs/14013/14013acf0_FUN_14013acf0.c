// Address: 0x14013acf0
// Ghidra name: FUN_14013acf0
// ============ 0x14013acf0 FUN_14013acf0 (size=81) ============


void FUN_14013acf0(longlong param_1,undefined8 param_2)



{

  longlong lVar1;

  

  lVar1 = FUN_14013aaf0(0);

  if (lVar1 != 0) {

    lVar1 = FUN_14013aac0(lVar1,param_2);

    if (lVar1 != 0) {

      FUN_14013bb10();

      *(undefined8 *)(lVar1 + 0x10) = *(undefined8 *)(param_1 + 0x80);

      *(longlong *)(param_1 + 0x80) = lVar1;

    }

  }

  return;

}




