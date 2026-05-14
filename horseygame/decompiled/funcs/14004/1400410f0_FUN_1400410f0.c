// Address: 0x1400410f0
// Ghidra name: FUN_1400410f0
// ============ 0x1400410f0 FUN_1400410f0 (size=63) ============


int FUN_1400410f0(longlong param_1)



{

  int iVar1;

  int iVar2;

  

  if (*(char *)(param_1 + 0x5c) != '\0') {

    return 0;

  }

  if (*(longlong *)(param_1 + 0x40) != 0) {

    return (int)*(longlong *)(param_1 + 0x40) - *(int *)(param_1 + 0x48);

  }

  iVar1 = *(int *)(param_1 + 0x38);

  iVar2 = FUN_1402cf00c(*(undefined8 *)(param_1 + 0x30));

  return iVar2 - iVar1;

}




