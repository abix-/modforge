// Address: 0x14027a220
// Ghidra name: FUN_14027a220
// ============ 0x14027a220 FUN_14027a220 (size=151) ============


void FUN_14027a220(longlong param_1)



{

  char cVar1;

  int iVar2;

  longlong *plVar3;

  int local_res10 [6];

  

  plVar3 = (longlong *)FUN_1401841a0(1,0x58);

  if (plVar3 == (longlong *)0x0) {

    return;

  }

  *plVar3 = param_1;

  *(longlong **)(param_1 + 0x70) = plVar3;

  *(undefined4 *)(param_1 + 0x5c) = 2;

  cVar1 = FUN_1401596b0(*(undefined2 *)(param_1 + 0x20),*(undefined2 *)(param_1 + 0x22),

                        *(undefined2 *)(param_1 + 0x24));

  if ((cVar1 != '\0') && (*(char **)(param_1 + 0x10) != (char *)0x0)) {

    iVar2 = strncmp(*(char **)(param_1 + 0x10),"GamePad-",8);

    if (iVar2 == 0) {

      local_res10[0] = iVar2;

      FUN_14012ef30(*(undefined8 *)(param_1 + 0x10),"GamePad-%d",local_res10);

      *(int *)(param_1 + 0x60) = local_res10[0] + -1;

    }

  }

  FUN_140208110(param_1,0);

  return;

}




