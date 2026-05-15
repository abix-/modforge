// Address: 0x1402c8dfc
// Ghidra name: FUN_1402c8dfc
// ============ 0x1402c8dfc FUN_1402c8dfc (size=82) ============


void FUN_1402c8dfc(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  bool bVar3;

  

  lVar2 = FUN_1402c97f8();

  if (param_1 == *(longlong *)(lVar2 + 0x58)) {

    lVar2 = FUN_1402c97f8();

    lVar2 = *(longlong *)(lVar2 + 0x58);

    while (lVar2 != 0) {

      lVar1 = *(longlong *)(lVar2 + 8);

      bVar3 = param_1 == lVar2;

      lVar2 = lVar1;

      if (bVar3) {

        lVar2 = FUN_1402c97f8();

        *(longlong *)(lVar2 + 0x58) = lVar1;

        return;

      }

    }

  }

                    /* WARNING: Subroutine does not return */

  FUN_1402e1bf8();

}




