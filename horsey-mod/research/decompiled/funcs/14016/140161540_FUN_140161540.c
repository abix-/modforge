// Address: 0x140161540
// Ghidra name: FUN_140161540
// ============ 0x140161540 FUN_140161540 (size=56) ============


void FUN_140161540(longlong param_1,undefined8 param_2,undefined8 param_3,char *param_4)



{

  undefined4 uVar1;

  

  if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {

    uVar1 = thunk_FUN_1402d89dc(param_4);

    *(undefined4 *)(param_1 + 0xe8) = uVar1;

    return;

  }

  *(undefined4 *)(param_1 + 0xe8) = 0x20;

  return;

}




