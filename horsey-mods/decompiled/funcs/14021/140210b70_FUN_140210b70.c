// Address: 0x140210b70
// Ghidra name: FUN_140210b70
// ============ 0x140210b70 FUN_140210b70 (size=51) ============


undefined8 FUN_140210b70(int param_1)



{

  _guard_check_icall();

  if ((-1 < param_1) && (param_1 < DAT_1403fd3e8)) {

    return *(undefined8 *)(DAT_1403fd3e0 + (longlong)param_1 * 8);

  }

  return 0;

}




