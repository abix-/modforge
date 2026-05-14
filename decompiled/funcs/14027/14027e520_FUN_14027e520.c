// Address: 0x14027e520
// Ghidra name: FUN_14027e520
// ============ 0x14027e520 FUN_14027e520 (size=68) ============


bool FUN_14027e520(longlong param_1,char param_2)



{

  char cVar1;

  undefined1 local_res10 [24];

  

  if (**(char **)(param_1 + 0x70) != param_2) {

    **(char **)(param_1 + 0x70) = param_2;

    if (param_2 != '\0') {

      cVar1 = FUN_140208110(param_1,local_res10);

      return cVar1 != '\0';

    }

    if (0 < *(int *)(param_1 + 0x8c)) {

      FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

    }

  }

  return true;

}




