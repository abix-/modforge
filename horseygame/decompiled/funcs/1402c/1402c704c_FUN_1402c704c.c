// Address: 0x1402c704c
// Ghidra name: FUN_1402c704c
// ============ 0x1402c704c FUN_1402c704c (size=59) ============


void FUN_1402c704c(longlong param_1)



{

  code *pcVar1;

  longlong lVar2;

  int iVar3;

  

  do {

    lVar2 = _malloc_base(param_1);

    if (lVar2 != 0) {

      return;

    }

    iVar3 = FUN_1402e6f60(param_1);

  } while (iVar3 != 0);

  if (param_1 == -1) {

                    /* WARNING: Subroutine does not return */

    FUN_140024090();

  }

  FUN_1402c7c00();

  pcVar1 = (code *)swi(3);

  (*pcVar1)();

  return;

}




