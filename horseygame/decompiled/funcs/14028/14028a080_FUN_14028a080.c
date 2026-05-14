// Address: 0x14028a080
// Ghidra name: FUN_14028a080
// ============ 0x14028a080 FUN_14028a080 (size=71) ============


bool FUN_14028a080(longlong param_1)



{

  char cVar1;

  

  cVar1 = FUN_140219df0();

  if (cVar1 != '\0') {

    *(int *)(param_1 + 0x410) = *(int *)(param_1 + 0x410) + 1;

    cVar1 = FUN_1402192f0(param_1,0);

    *(int *)(param_1 + 0x410) = *(int *)(param_1 + 0x410) + -1;

    if (cVar1 != '\0') {

      cVar1 = FUN_1402187e0(param_1);

      return cVar1 != '\0';

    }

  }

  return false;

}




