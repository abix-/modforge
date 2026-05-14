// Address: 0x140197730
// Ghidra name: FUN_140197730
// ============ 0x140197730 FUN_140197730 (size=233) ============


int * FUN_140197730(char *param_1,char *param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  undefined1 local_98 [64];

  undefined1 local_58 [64];

  

  iVar5 = 0;

  iVar3 = 0;

  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {

    param_2 = (char *)FUN_1401979c0(local_98,0x40);

  }

  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

    param_1 = (char *)FUN_1401979c0(local_58,0x40);

  }

  uVar4 = 0;

  piVar2 = &DAT_1403e3b38;

  do {

    iVar1 = FUN_14012ef60(param_2,*(undefined8 *)(piVar2 + -2));

    if ((iVar1 == 0) && (iVar5 = *piVar2, iVar3 != 0)) break;

    iVar1 = FUN_14012ef60(param_1,*(undefined8 *)(piVar2 + -2));

    if ((iVar1 == 0) && (iVar3 = *piVar2, iVar5 != 0)) goto LAB_1401977db;

    uVar4 = uVar4 + 1;

    piVar2 = piVar2 + 4;

  } while (uVar4 < 0x1d);

  if (iVar5 != 0) {

LAB_1401977db:

    if ((iVar3 != 0) && (piVar2 = (int *)FUN_1401841f0(8), piVar2 != (int *)0x0)) {

      *piVar2 = iVar5;

      piVar2[1] = iVar3;

      return piVar2;

    }

  }

  return (int *)0xffffffffffffffff;

}




