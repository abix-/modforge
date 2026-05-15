// Address: 0x14020d2c0
// Ghidra name: FUN_14020d2c0
// ============ 0x14020d2c0 FUN_14020d2c0 (size=56) ============


void FUN_14020d2c0(int param_1)



{

  longlong lVar1;

  

  _guard_check_icall();

  lVar1 = DAT_1403fd260;

  for (; (lVar1 != 0 && (param_1 != 0)); param_1 = param_1 + -1) {

    lVar1 = *(longlong *)(lVar1 + 0x108);

  }

  return;

}




