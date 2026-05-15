// Address: 0x14013ba20
// Ghidra name: FUN_14013ba20
// ============ 0x14013ba20 FUN_14013ba20 (size=82) ============


void FUN_14013ba20(longlong param_1)



{

  longlong lVar1;

  

  if ((*(longlong *)(param_1 + 0x80) != 0) && (lVar1 = FUN_14013aaf0(1), lVar1 != 0)) {

    lVar1 = *(longlong *)(param_1 + 0x80);

    while (lVar1 != 0) {

      lVar1 = *(longlong *)(lVar1 + 0x10);

      FUN_14013acc0();

    }

    *(undefined8 *)(param_1 + 0x80) = 0;

  }

  return;

}




