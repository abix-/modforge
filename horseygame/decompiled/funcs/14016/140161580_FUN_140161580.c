// Address: 0x140161580
// Ghidra name: FUN_140161580
// ============ 0x140161580 FUN_140161580 (size=58) ============


void FUN_140161580(longlong param_1,undefined8 param_2,undefined8 param_3,char *param_4)



{

  undefined4 uVar1;

  UINT UVar2;

  

  if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {

    uVar1 = thunk_FUN_1402d89dc(param_4);

    *(undefined4 *)(param_1 + 0xe4) = uVar1;

    return;

  }

  UVar2 = GetDoubleClickTime();

  *(UINT *)(param_1 + 0xe4) = UVar2;

  return;

}




