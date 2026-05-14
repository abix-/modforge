// Address: 0x14013c5c0
// Ghidra name: FUN_14013c5c0
// ============ 0x14013c5c0 FUN_14013c5c0 (size=82) ============


ulonglong FUN_14013c5c0(longlong param_1,longlong param_2)



{

  int iVar1;

  longlong *plVar2;

  longlong lVar3;

  

  _guard_check_icall();

  iVar1 = *(int *)(param_1 + 0x18);

  plVar2 = (longlong *)(longlong)iVar1;

  if (0 < iVar1) {

    lVar3 = 0;

    plVar2 = *(longlong **)(param_1 + 0x20);

    do {

      if (*plVar2 == param_2) {

        return CONCAT71((int7)((ulonglong)plVar2 >> 8),1);

      }

      lVar3 = lVar3 + 1;

      plVar2 = plVar2 + 1;

    } while (lVar3 < iVar1);

  }

  return (ulonglong)plVar2 & 0xffffffffffffff00;

}




