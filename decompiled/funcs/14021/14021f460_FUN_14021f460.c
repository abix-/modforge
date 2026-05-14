// Address: 0x14021f460
// Ghidra name: FUN_14021f460
// ============ 0x14021f460 FUN_14021f460 (size=65) ============


undefined1 FUN_14021f460(longlong param_1,ulonglong param_2)



{

  ulonglong uVar1;

  char cVar2;

  

  uVar1 = *(ulonglong *)(param_1 + 0x18);

  cVar2 = FUN_14021f7b0();

  if (cVar2 == '\0') {

    return 0;

  }

  *(longlong *)(param_1 + 0x18) = *(longlong *)(param_1 + 0x18) + uVar1 % param_2;

  return 1;

}




