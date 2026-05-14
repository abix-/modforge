// Address: 0x14021f290
// Ghidra name: FUN_14021f290
// ============ 0x14021f290 FUN_14021f290 (size=93) ============


undefined1 FUN_14021f290(longlong param_1,undefined8 param_2,longlong param_3)



{

  char cVar1;

  

  cVar1 = FUN_14021f7b0(param_1,param_3);

  if (cVar1 == '\0') {

    return 0;

  }

  FUN_1402f8e20(*(longlong *)(param_1 + 8) + *(longlong *)(param_1 + 0x18),param_2,param_3);

  *(longlong *)(param_1 + 0x18) = *(longlong *)(param_1 + 0x18) + param_3;

  return 1;

}




