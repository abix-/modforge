// Address: 0x140279b60
// Ghidra name: FUN_140279b60
// ============ 0x140279b60 FUN_140279b60 (size=152) ============


undefined8 FUN_140279b60(longlong param_1,uint param_2,code *param_3)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  ulonglong uVar4;

  

  lVar3 = FUN_140149350();

  iVar2 = FUN_140279b10(param_1);

  while (iVar2 != -1) {

    if (iVar2 < 1) {

      uVar4 = FUN_140149350();

      if (lVar3 + 0xfaU <= uVar4) break;

      FUN_1401492f0(1);

    }

    else if ((*(byte *)(param_1 + 0x2c) == param_2) &&

            ((param_3 == (code *)0x0 || (cVar1 = (*param_3)(param_1 + 0x2c), cVar1 != '\0')))) {

      return 1;

    }

    iVar2 = FUN_140279b10(param_1);

  }

  FUN_14012e850("Read timed out");

  return 0;

}




