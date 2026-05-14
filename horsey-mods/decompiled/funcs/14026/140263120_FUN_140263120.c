// Address: 0x140263120
// Ghidra name: FUN_140263120
// ============ 0x140263120 FUN_140263120 (size=50) ============


bool FUN_140263120(int *param_1,int *param_2,int param_3)



{

  int iVar1;

  int iVar2;

  bool bVar3;

  bool bVar4;

  

  iVar1 = param_2[1];

  iVar2 = param_1[1];

  if (param_3 == 0) {

    if (iVar2 != iVar1) {

      return iVar2 < iVar1;

    }

    bVar4 = SBORROW4(*param_2,*param_1);

    bVar3 = *param_2 - *param_1 < 0;

  }

  else {

    bVar4 = SBORROW4(iVar1,iVar2);

    bVar3 = iVar1 - iVar2 < 0;

    if (iVar1 == iVar2) {

      if (*param_1 < *param_2) {

        return true;

      }

      bVar4 = SBORROW4(iVar1,iVar2);

      bVar3 = iVar1 - iVar2 < 0;

    }

  }

  if (bVar4 != bVar3) {

    return true;

  }

  return false;

}




