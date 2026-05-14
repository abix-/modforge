// Address: 0x14014a400
// Ghidra name: FUN_14014a400
// ============ 0x14014a400 FUN_14014a400 (size=46) ============


ulonglong FUN_14014a400(longlong param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  longlong lVar3;

  

  iVar1 = *(int *)(param_1 + 0x110);

  piVar2 = (int *)(longlong)iVar1;

  if (0 < iVar1) {

    lVar3 = 0;

    piVar2 = *(int **)(param_1 + 0x108);

    do {

      if (*piVar2 == param_2) {

        return CONCAT71((int7)((ulonglong)piVar2 >> 8),1);

      }

      lVar3 = lVar3 + 1;

      piVar2 = piVar2 + 1;

    } while (lVar3 < iVar1);

  }

  return (ulonglong)piVar2 & 0xffffffffffffff00;

}




