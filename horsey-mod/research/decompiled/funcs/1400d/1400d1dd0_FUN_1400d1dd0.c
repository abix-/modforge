// Address: 0x1400d1dd0
// Ghidra name: FUN_1400d1dd0
// ============ 0x1400d1dd0 FUN_1400d1dd0 (size=57) ============


int FUN_1400d1dd0(longlong param_1,longlong param_2)



{

  int iVar1;

  longlong *plVar2;

  ulonglong uVar3;

  

  plVar2 = *(longlong **)(param_1 + 0x130);

  iVar1 = 0;

  uVar3 = *(longlong *)(param_1 + 0x138) - (longlong)plVar2 >> 3;

  if (uVar3 != 0) {

    do {

      if (*plVar2 == param_2) {

        return iVar1;

      }

      iVar1 = iVar1 + 1;

      plVar2 = plVar2 + 1;

    } while ((ulonglong)(longlong)iVar1 < uVar3);

  }

  return -1;

}




