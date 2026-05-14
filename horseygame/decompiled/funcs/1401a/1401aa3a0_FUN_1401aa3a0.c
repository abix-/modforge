// Address: 0x1401aa3a0
// Ghidra name: FUN_1401aa3a0
// ============ 0x1401aa3a0 FUN_1401aa3a0 (size=172) ============


void FUN_1401aa3a0(float param_1,int *param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  

  iVar8 = 0;

  iVar7 = 1;

  iVar6 = 1;

  iVar3 = 0;

  while( true ) {

    if (1000 < iVar3) {

      *param_2 = iVar8;

      *param_3 = iVar7;

      return;

    }

    iVar5 = iVar6 + iVar8;

    iVar4 = iVar3 + iVar7;

    if (param_1 == (float)iVar5 / (float)iVar4) break;

    iVar1 = iVar5;

    iVar2 = iVar4;

    if (param_1 <= (float)iVar5 / (float)iVar4) {

      iVar1 = iVar8;

      iVar2 = iVar7;

      iVar6 = iVar5;

      iVar3 = iVar4;

    }

    iVar7 = iVar2;

    iVar8 = iVar1;

    if (1000 < iVar7) {

      *param_2 = iVar6;

      *param_3 = iVar3;

      return;

    }

  }

  if ((1000 < iVar4) && (iVar4 = iVar7, iVar5 = iVar8, iVar7 < iVar3)) {

    *param_2 = iVar6;

    *param_3 = iVar3;

    return;

  }

  *param_2 = iVar5;

  *param_3 = iVar4;

  return;

}




