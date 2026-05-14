// Address: 0x14026c8f0
// Ghidra name: FUN_14026c8f0
// ============ 0x14026c8f0 FUN_14026c8f0 (size=135) ============


ulonglong FUN_14026c8f0(longlong param_1,uint param_2)



{

  int iVar1;

  longlong lVar2;

  ulonglong uVar3;

  

  lVar2 = FUN_140149350();

  uVar3 = FUN_14026c790(param_1);

  iVar1 = (int)uVar3;

  while (iVar1 != -1) {

    if ((int)uVar3 < 1) {

      FUN_1401492f0(1);

    }

    else if ((*(char *)(param_1 + 0x40) == -0x7f) && (*(byte *)(param_1 + 0x41) == param_2)) {

      return 1;

    }

    uVar3 = FUN_140149350();

    if (lVar2 + 100U <= uVar3) break;

    uVar3 = FUN_14026c790(param_1);

    iVar1 = (int)uVar3;

  }

  return uVar3 & 0xffffffffffffff00;

}




