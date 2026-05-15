// Address: 0x140073510
// Ghidra name: FUN_140073510
// ============ 0x140073510 FUN_140073510 (size=171) ============


void FUN_140073510(undefined8 param_1,longlong param_2,uint param_3)



{

  undefined8 uVar1;

  longlong lVar2;

  ulonglong uVar3;

  

  if (0 < (int)param_3) {

    uVar3 = (ulonglong)param_3;

    lVar2 = param_2;

    do {

      FUN_1400745d0(lVar2);

      lVar2 = lVar2 + 0x20;

      uVar3 = uVar3 - 1;

    } while (uVar3 != 0);

  }

  uVar1 = FUN_1400c43c0();

  SDL_RenderGeometryRaw

            (uVar1,param_1,param_2,0x20,param_2 + 0x10,0x20,param_2 + 8,0x20,param_3,0,0,0);

  return;

}




