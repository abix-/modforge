// Address: 0x1401615c0
// Ghidra name: FUN_1401615c0
// ============ 0x1401615c0 FUN_1401615c0 (size=47) ============


void FUN_1401615c0(longlong param_1,undefined8 param_2,undefined8 param_3,char *param_4)



{

  undefined1 uVar1;

  

  if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {

    uVar1 = thunk_FUN_1402d89dc(param_4);

    *(undefined1 *)(param_1 + 0x78) = uVar1;

    return;

  }

  *(undefined1 *)(param_1 + 0x78) = 0;

  return;

}




