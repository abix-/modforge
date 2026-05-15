// Address: 0x1400c6e80
// Ghidra name: FUN_1400c6e80
// ============ 0x1400c6e80 FUN_1400c6e80 (size=125) ============


int FUN_1400c6e80(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  ulonglong uVar5;

  int iVar6;

  

  iVar4 = -param_1;

  if (-param_1 < 0) {

    iVar4 = param_1;

  }

  iVar1 = (param_1 >> 0x1f & 0xfffffffeU) + 1;

  if (iVar4 < 100) {

    return iVar1 * iVar4;

  }

  iVar6 = 10;

  iVar3 = 10;

  if (1 < param_2) {

    uVar5 = (ulonglong)(param_2 - 1);

    do {

      iVar2 = iVar3;

      iVar3 = iVar2 * 10;

      uVar5 = uVar5 - 1;

    } while (uVar5 != 0);

    if (iVar4 < iVar2 * 100) goto LAB_1400c6ee2;

  }

  do {

    iVar6 = iVar6 * 10;

  } while (iVar3 * iVar6 <= iVar4);

LAB_1400c6ee2:

  iVar4 = iVar6 / 2 + iVar4;

  return (iVar4 - iVar4 % iVar6) * iVar1;

}




