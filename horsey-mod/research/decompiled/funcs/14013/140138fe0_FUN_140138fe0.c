// Address: 0x140138fe0
// Ghidra name: FUN_140138fe0
// ============ 0x140138fe0 FUN_140138fe0 (size=14) ============


void FUN_140138fe0(int *param_1)



{

  int iVar1;

  int iVar2;

  bool bVar3;

  

  iVar2 = *param_1;

  do {

    LOCK();

    iVar1 = *param_1;

    bVar3 = iVar2 == iVar1;

    if (bVar3) {

      *param_1 = iVar2;

      iVar1 = iVar2;

    }

    iVar2 = iVar1;

    UNLOCK();

  } while (!bVar3);

  return;

}




