// Address: 0x140210ad0
// Ghidra name: FUN_140210ad0
// ============ 0x140210ad0 FUN_140210ad0 (size=146) ============


void FUN_140210ad0(void)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  

  _guard_check_icall();

  iVar3 = 0;

  if (0 < DAT_1403fd3e8) {

    lVar4 = 0;

    iVar2 = DAT_1403fd3e8;

    do {

      lVar1 = *(longlong *)(lVar4 + DAT_1403fd3e0);

      if (lVar1 != 0) {

        FUN_1401841e0(*(undefined8 *)(lVar1 + 8));

        FUN_1401841e0(lVar1);

        iVar2 = DAT_1403fd3e8;

      }

      iVar3 = iVar3 + 1;

      lVar4 = lVar4 + 8;

    } while (iVar3 < iVar2);

  }

  FUN_1401841e0(DAT_1403fd3e0);

  DAT_1403fd3e0 = 0;

  DAT_1403fd3e8 = 0;

  return;

}




