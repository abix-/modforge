// Address: 0x1401677b0
// Ghidra name: FUN_1401677b0
// ============ 0x1401677b0 FUN_1401677b0 (size=142) ============


ulonglong FUN_1401677b0(undefined8 *param_1)



{

  char cVar1;

  longlong lVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return 0xffffffff;

  }

  FUN_140179b40(*param_1);

  cVar1 = FUN_140163e40(param_1);

  if (cVar1 == '\0') {

    FUN_140179b60(*param_1);

    return 0;

  }

  lVar2 = FUN_1401644e0(param_1,0);

  uVar4 = (ulonglong)((*(uint *)((longlong)param_1 + 0x3c) >> 3 & 0x1f) * *(int *)(param_1 + 8)) *

          lVar2;

  FUN_140179b60(*param_1);

  uVar3 = 0x7fffffff;

  if ((longlong)uVar4 < 0x7fffffff) {

    uVar3 = uVar4 & 0xffffffff;

  }

  return uVar3;

}




