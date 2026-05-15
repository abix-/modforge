// Address: 0x140275050
// Ghidra name: FUN_140275050
// ============ 0x140275050 FUN_140275050 (size=209) ============


void FUN_140275050(undefined8 param_1,undefined8 param_2,longlong param_3)



{

  undefined8 uVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  uVar1 = FUN_140149300();

  FUN_14015ad00(uVar1,param_1,0xc,*(byte *)(param_3 + 1) & 1);

  fVar2 = (float)(int)(*(byte *)(param_3 + 2) - 0x70) / DAT_1403033b4;

  fVar4 = 0.0;

  if (0.0 <= fVar2) {

    fVar4 = fVar2;

  }

  fVar2 = DAT_14039ca44;

  if (fVar4 <= DAT_14039ca44) {

    fVar2 = fVar4;

  }

  fVar3 = (float)(int)(*(byte *)(param_3 + 4) - 0x40) / DAT_140303fdc;

  fVar4 = 0.0;

  if (0.0 <= fVar3) {

    fVar4 = fVar3;

  }

  fVar3 = DAT_14039ca44;

  if (fVar4 <= DAT_14039ca44) {

    fVar3 = fVar4;

  }

  fVar4 = DAT_14039ca44;

  if (*(char *)(param_3 + 1) < '\0') {

    fVar4 = 0.0;

  }

  FUN_14015b110(uVar1,param_1,0,0,-1 < *(char *)(param_3 + 1),fVar2,fVar3,fVar4);

  return;

}




