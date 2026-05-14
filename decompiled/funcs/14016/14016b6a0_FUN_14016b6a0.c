// Address: 0x14016b6a0
// Ghidra name: FUN_14016b6a0
// ============ 0x14016b6a0 FUN_14016b6a0 (size=128) ============


void FUN_14016b6a0(undefined8 param_1,undefined8 param_2)



{

  char cVar1;

  undefined4 uVar2;

  longlong *plVar3;

  

  uVar2 = FUN_14016ea50(param_2);

  cVar1 = FUN_140174fc0(uVar2,"SDL.internal.window.texturedata");

  if (cVar1 != '\0') {

    plVar3 = (longlong *)FUN_140174d30(uVar2,"SDL.internal.window.texturedata",0);

    if (plVar3[1] != 0) {

      FUN_14014dd50();

    }

    if (*plVar3 != 0) {

      FUN_14014db70();

    }

    FUN_1401841e0(plVar3[2]);

    FUN_1401841e0(plVar3);

    FUN_1401745e0(uVar2,"SDL.internal.window.texturedata");

  }

  return;

}




