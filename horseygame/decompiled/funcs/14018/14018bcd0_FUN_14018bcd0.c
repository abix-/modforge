// Address: 0x14018bcd0
// Ghidra name: FUN_14018bcd0
// ============ 0x14018bcd0 FUN_14018bcd0 (size=45) ============


ulonglong FUN_14018bcd0(longlong param_1)



{

  int iVar1;

  ulonglong in_RAX;

  

  iVar1 = *(int *)(param_1 + 0xb8);

  if (iVar1 == 0) {

    return in_RAX & 0xffffffffffffff00;

  }

  if ((iVar1 != 1) && (iVar1 == 2)) {

    return 1;

  }

  return CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0xc0) >> 8),

                  *(char *)(*(longlong *)(param_1 + 0xc0) + 0xf8) == '\0');

}




