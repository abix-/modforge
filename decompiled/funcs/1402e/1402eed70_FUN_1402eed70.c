// Address: 0x1402eed70
// Ghidra name: FUN_1402eed70
// ============ 0x1402eed70 FUN_1402eed70 (size=73) ============


bool FUN_1402eed70(FILE *param_1)



{

  int iVar1;

  FILE *pFVar2;

  bool bVar3;

  

  pFVar2 = (FILE *)FUN_1402e16a0(2);

  if (param_1 == pFVar2) {

    bVar3 = true;

  }

  else {

    pFVar2 = (FILE *)FUN_1402e16a0(1);

    if (param_1 == pFVar2) {

      iVar1 = _fileno(param_1);

      iVar1 = FUN_1402f6598(iVar1);

      bVar3 = iVar1 != 0;

    }

    else {

      bVar3 = false;

    }

  }

  return bVar3;

}




