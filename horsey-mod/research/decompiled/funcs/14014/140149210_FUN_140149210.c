// Address: 0x140149210
// Ghidra name: FUN_140149210
// ============ 0x140149210 FUN_140149210 (size=222) ============


void FUN_140149210(longlong param_1)



{

  ulonglong uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  

  uVar2 = FUN_140149300();

  uVar6 = param_1 + uVar2;

  uVar3 = uVar2 + 1000000;

  uVar1 = 1000000;

  while (uVar3 < uVar6) {

    FUN_140184480(1000000);

    uVar4 = FUN_140149300();

    uVar5 = uVar4 - uVar2;

    if (uVar4 - uVar2 <= uVar1) {

      uVar5 = uVar1;

    }

    uVar1 = uVar5;

    uVar2 = uVar4;

    uVar3 = uVar4 + uVar5;

  }

  if ((uVar2 < uVar6) && (uVar1 - 1000000 < uVar6 - uVar2)) {

    FUN_140184480(((uVar6 - uVar1) - uVar2) + 1000000);

    uVar2 = FUN_140149300();

  }

  while (uVar2 + 1000000 < uVar6) {

    FUN_140184480(1000000);

    uVar2 = FUN_140149300();

  }

  while (uVar2 < uVar6) {

    uVar2 = FUN_140149300();

  }

  return;

}




