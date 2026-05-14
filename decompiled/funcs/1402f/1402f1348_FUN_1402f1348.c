// Address: 0x1402f1348
// Ghidra name: FUN_1402f1348
// ============ 0x1402f1348 FUN_1402f1348 (size=162) ============


ulonglong FUN_1402f1348(LPCWSTR param_1,undefined8 param_2,uint param_3)



{

  char cVar1;

  BOOL BVar2;

  int iVar3;

  ulonglong uVar4;

  undefined8 uVar5;

  

  BVar2 = IsDebuggerPresent();

  if (BVar2 != 0) {

    if (param_1 != (LPCWSTR)0x0) {

      OutputDebugStringW(param_1);

    }

    iVar3 = FUN_1402ec9ac();

    if (iVar3 != 1) {

      return 4;

    }

  }

  iVar3 = FUN_1402ec938();

  if ((iVar3 == 2) && (cVar1 = FUN_1402ec638(), cVar1 != '\0')) {

    cVar1 = FUN_1402ec784();

    if (cVar1 == '\0') {

      param_3 = param_3 | 0x200000;

      uVar5 = 0;

    }

    else {

      uVar5 = FUN_1402ec6bc();

    }

    uVar4 = FUN_1402ec524(uVar5,param_1,param_2,param_3);

    return uVar4;

  }

  return (ulonglong)((BVar2 != 0) + 3);

}




