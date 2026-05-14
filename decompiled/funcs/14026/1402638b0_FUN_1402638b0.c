// Address: 0x1402638b0
// Ghidra name: FUN_1402638b0
// ============ 0x1402638b0 FUN_1402638b0 (size=68) ============


ulonglong FUN_1402638b0(void)



{

  ulonglong uVar1;

  short in_R9W;

  short in_stack_00000028;

  

  uVar1 = 0x57e;

  if (in_R9W == 0x57e) {

    uVar1 = 0x337;

    if (in_stack_00000028 == 0x337) {

LAB_1402638f1:

      return CONCAT71((int7)(uVar1 >> 8),1);

    }

  }

  else if (in_R9W == 0x79) {

    uVar1 = (ulonglong)(ushort)(in_stack_00000028 + 0xe7bdU);

    if (1 < (ushort)(in_stack_00000028 + 0xe7bdU)) {

      return CONCAT71(0x18,in_stack_00000028 == 0x1846);

    }

    goto LAB_1402638f1;

  }

  return uVar1 & 0xffffffffffffff00;

}




