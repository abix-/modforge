// Address: 0x14014d8a0
// Ghidra name: FUN_14014d8a0
// ============ 0x14014d8a0 FUN_14014d8a0 (size=213) ============


undefined1 FUN_14014d8a0(void)



{

  undefined1 uVar1;

  longlong lVar2;

  ulonglong in_R9;

  longlong *in_stack_00000028;

  longlong *in_stack_00000030;

  

  if (in_stack_00000028 == (longlong *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","window");

    return uVar1;

  }

  if (in_stack_00000030 == (longlong *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    return uVar1;

  }

  lVar2 = FUN_14016b430();

  *in_stack_00000028 = lVar2;

  if (lVar2 == 0) {

    *in_stack_00000030 = 0;

    return 0;

  }

  lVar2 = FUN_14014c6b0(lVar2,0);

  *in_stack_00000030 = lVar2;

  if (lVar2 == 0) {

    FUN_14016b720(*in_stack_00000028);

    *in_stack_00000028 = 0;

    return 0;

  }

  if ((in_R9 & 8) == 0) {

    FUN_140172c00(*in_stack_00000028);

  }

  return 1;

}




