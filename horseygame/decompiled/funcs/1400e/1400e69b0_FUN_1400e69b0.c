// Address: 0x1400e69b0
// Ghidra name: FUN_1400e69b0
// ============ 0x1400e69b0 FUN_1400e69b0 (size=118) ============


void FUN_1400e69b0(longlong *param_1)



{

  longlong *plVar1;

  int iVar2;

  

  iVar2 = 0;

  if (0 < *(int *)(*param_1 + 8)) {

    plVar1 = param_1 + 0x6ba;

    do {

      if (*plVar1 != 0) {

        thunk_FUN_1402e9a80(plVar1[1]);

        *plVar1 = 0;

      }

      if (plVar1[2] != 0) {

        thunk_FUN_1402e9a80();

        plVar1[2] = 0;

      }

      iVar2 = iVar2 + 1;

      plVar1 = plVar1 + 9;

    } while (iVar2 < *(int *)(*param_1 + 8));

  }

  return;

}




