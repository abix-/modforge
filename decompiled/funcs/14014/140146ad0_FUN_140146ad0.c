// Address: 0x140146ad0
// Ghidra name: FUN_140146ad0
// ============ 0x140146ad0 FUN_140146ad0 (size=192) ============


longlong * FUN_140146ad0(longlong param_1,int *param_2)



{

  int iVar1;

  char cVar2;

  longlong *plVar3;

  

  if (param_2 != (int *)0x0) {

    *param_2 = 0;

  }

  cVar2 = FUN_1401489c0();

  if (cVar2 != '\0') {

    iVar1 = *(int *)(param_1 + 0x50);

    plVar3 = (longlong *)FUN_1401841f0((longlong)iVar1 * 8 + 0x10);

    if (plVar3 != (longlong *)0x0) {

      *plVar3 = param_1;

      if (0 < *(int *)(param_1 + 0x50)) {

        FUN_1402f8e20(plVar3 + 1,*(undefined8 *)(param_1 + 0x58),

                      (longlong)*(int *)(param_1 + 0x50) << 3);

      }

      plVar3[(longlong)iVar1 + 1] = 0;

      if (param_2 != (int *)0x0) {

        *param_2 = iVar1 + 1;

      }

    }

    return plVar3;

  }

  FUN_14012e850("Parameter \'%s\' is invalid","surface");

  return (longlong *)0x0;

}




