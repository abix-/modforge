// Address: 0x1401f4710
// Ghidra name: FUN_1401f4710
// ============ 0x1401f4710 FUN_1401f4710 (size=35) ============


void FUN_1401f4710(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (*(char *)(lVar1 + 8) != '\0') {

    do {

      iVar2 = (**(code **)(lVar1 + 200))();

    } while (iVar2 != 0);

  }

  return;

}




