// Address: 0x140212f80
// Ghidra name: FUN_140212f80
// ============ 0x140212f80 FUN_140212f80 (size=116) ============


void FUN_140212f80(float param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  fVar1 = 0.0;

  fVar3 = DAT_14039ca44;

  fVar4 = DAT_14039ca44;

  do {

    fVar1 = fVar1 + fVar4;

    fVar2 = fVar3 * fVar3;

    fVar3 = fVar3 + DAT_14039ca44;

    fVar4 = fVar4 * ((param_1 * param_1 * DAT_14030335c) / fVar2);

  } while (fVar1 * DAT_14039c9f0 <= fVar4);

  return;

}




