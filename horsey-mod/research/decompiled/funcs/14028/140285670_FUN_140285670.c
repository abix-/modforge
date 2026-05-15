// Address: 0x140285670
// Ghidra name: FUN_140285670
// ============ 0x140285670 FUN_140285670 (size=94) ============


undefined8 FUN_140285670(longlong param_1,undefined2 param_2,undefined2 param_3)



{

  int iVar1;

  undefined8 uVar2;

  undefined2 local_res20;

  undefined2 local_res22;

  

  if (DAT_1403fddf0 == (code *)0x0) {

    uVar2 = FUN_14012e850("That operation is not supported");

    return uVar2;

  }

  local_res20 = param_2;

  local_res22 = param_3;

  iVar1 = (*DAT_1403fddf0)(*(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0xc6a),&local_res20);

  if (iVar1 != 0) {

    uVar2 = FUN_14012e850("XInputSetState() failed");

    return uVar2;

  }

  return 1;

}




