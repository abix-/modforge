// Address: 0x140182bb0
// Ghidra name: FUN_140182bb0
// ============ 0x140182bb0 FUN_140182bb0 (size=126) ============


uint FUN_140182bb0(char *param_1)



{

  int iVar1;

  uint uVar2;

  longlong *plVar3;

  

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {

    uVar2 = 0;

    plVar3 = &DAT_1403e2940;

    do {

      if (*plVar3 != 0) {

        iVar1 = FUN_14012ef60(param_1);

        if (iVar1 == 0) {

          return uVar2;

        }

      }

      uVar2 = uVar2 + 1;

      plVar3 = plVar3 + 1;

    } while (uVar2 < 0x200);

  }

  FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140304430);

  return 0;

}




