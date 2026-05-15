// Address: 0x14006aa10
// Ghidra name: FUN_14006aa10
// ============ 0x14006aa10 FUN_14006aa10 (size=58) ============


undefined8 FUN_14006aa10(longlong param_1)



{

  char cVar1;

  

  if (((*(int *)(param_1 + 0x2b8) == 0) && (*(char *)(param_1 + 700) == '\0')) &&

     (*(longlong **)(param_1 + 0x2b0) != (longlong *)0x0)) {

    cVar1 = (**(code **)(**(longlong **)(param_1 + 0x2b0) + 0x28))();

    if (cVar1 != '\0') {

      return 1;

    }

  }

  return 0;

}




