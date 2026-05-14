// Address: 0x1400678b0
// Ghidra name: FUN_1400678b0
// ============ 0x1400678b0 FUN_1400678b0 (size=181) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400678b0(undefined8 param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  double dVar4;

  uint uVar5;

  

  dVar4 = _DAT_140308130;

  fVar3 = DAT_140303fd4;

  fVar2 = DAT_140303754;

  fVar1 = DAT_140303374;

  uVar5 = 0;

  do {

    FUN_1400cc9d0(param_1,uVar5,((float)((uVar5 & 0xf) + 1) * fVar2) / fVar3,

                  (float)((double)((float)(uVar5 >> 4) * fVar1) + dVar4));

    uVar5 = uVar5 + 1;

  } while ((int)uVar5 < 0x32);

  return;

}




