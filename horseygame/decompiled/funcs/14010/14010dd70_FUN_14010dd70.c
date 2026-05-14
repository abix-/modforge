// Address: 0x14010dd70
// Ghidra name: FUN_14010dd70
// ============ 0x14010dd70 FUN_14010dd70 (size=92) ============


ulonglong FUN_14010dd70(longlong param_1)



{

  ushort *puVar1;

  int *piVar2;

  int iVar3;

  

  piVar2 = *(int **)(param_1 + 0x438);

  if ((*(longlong *)(piVar2 + 0x36) != 0) &&

     (*(char *)(*(longlong *)(piVar2 + 0x36) + 0x270) == '\0')) {

    piVar2 = (int *)&DAT_1403d9530;

    if (0xf < DAT_1403d9548) {

      piVar2 = DAT_1403d9530;

    }

    if (DAT_1403d9540 == 6) {

      iVar3 = *piVar2 + -0x73697243;

      if (iVar3 == 0) {

        puVar1 = (ushort *)(piVar2 + 1);

        piVar2 = (int *)0x7270;

        iVar3 = *puVar1 - 0x7270;

      }

      if (iVar3 == 0) goto LAB_14010ddc9;

    }

    return (ulonglong)piVar2 & 0xffffffffffffff00;

  }

LAB_14010ddc9:

  return CONCAT71((int7)((ulonglong)piVar2 >> 8),1);

}




