// Address: 0x14012de00
// Ghidra name: FUN_14012de00
// ============ 0x14012de00 FUN_14012de00 (size=191) ============


undefined4 FUN_14012de00(char *param_1,undefined8 param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  undefined **ppuVar3;

  

  iVar1 = FUN_140190340((int)*param_1);

  if (iVar1 == 0) {

    iVar1 = FUN_14012f260(param_1,"quiet",param_2);

    if (iVar1 != 0) {

      iVar1 = 1;

      ppuVar3 = &PTR_s_TRACE_1403141d8;

      do {

        iVar2 = FUN_14012f260(param_1,*ppuVar3,param_2);

        if (iVar2 == 0) {

          *param_3 = iVar1;

          return 1;

        }

        iVar1 = iVar1 + 1;

        ppuVar3 = ppuVar3 + 1;

      } while ((longlong)ppuVar3 < 0x140314210);

      return 0;

    }

  }

  else {

    iVar1 = thunk_FUN_1402d89dc();

    if (iVar1 != 0) {

      if (iVar1 - 1U < 7) {

        *param_3 = iVar1;

        return 1;

      }

      return 0;

    }

  }

  *param_3 = 8;

  return 1;

}




