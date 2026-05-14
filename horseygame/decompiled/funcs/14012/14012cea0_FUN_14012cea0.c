// Address: 0x14012cea0
// Ghidra name: FUN_14012cea0
// ============ 0x14012cea0 FUN_14012cea0 (size=193) ============


void FUN_14012cea0(undefined8 *param_1,longlong param_2)



{

  longlong lVar1;

  undefined4 uVar2;

  ulonglong uVar3;

  longlong lVar4;

  longlong lVar5;

  

  uVar2 = FUN_14012be20(*param_1);

  uVar3 = FUN_140174c40(uVar2,"SDL.iostream.dynamic.chunksize",0);

  if (uVar3 == 0) {

    uVar3 = 0x400;

  }

  lVar5 = ((ulonglong)((param_1[5] - param_1[1]) + param_2) / uVar3 + 1) * uVar3;

  lVar4 = FUN_140184230(param_1[1],lVar5);

  if (lVar4 == 0) {

    return;

  }

  lVar1 = param_1[1];

  param_1[1] = lVar4;

  param_1[2] = param_1[2] + (lVar4 - lVar1);

  param_1[3] = param_1[3] + (lVar4 - lVar1);

  param_1[5] = lVar4 + lVar5;

  uVar2 = FUN_14012be20(*param_1);

  FUN_140175480(uVar2,"SDL.iostream.dynamic.memory",lVar4);

  return;

}




