// Address: 0x1400b2cd0
// Ghidra name: FUN_1400b2cd0
// ============ 0x1400b2cd0 FUN_1400b2cd0 (size=288) ============


void FUN_1400b2cd0(undefined8 param_1,float param_2,float param_3,undefined4 param_4)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  undefined4 uVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  uVar3 = FUN_1400c5f10(param_4);

  fVar4 = (float)FUN_1402cdc50();

  fVar5 = (float)FUN_1402cfda0(uVar3);

  puVar2 = DAT_1403f3180;

  if (DAT_1403f3180 == DAT_1403f3188) {

    FUN_140064060(&DAT_1403f3178,DAT_1403f3180,&DAT_1403f3168);

  }

  else {

    uVar1 = CONCAT44(DAT_1403f3174,DAT_1403f3170);

    *DAT_1403f3180 = CONCAT44(DAT_1403f316c,DAT_1403f3168);

    puVar2[1] = uVar1;

    DAT_1403f3180 = DAT_1403f3180 + 2;

  }

  DAT_1403f3168 = DAT_1403f3168 + (DAT_1403f3174 * param_2 - DAT_1403f3170 * param_3);

  fVar6 = DAT_1403f3170 * fVar4;

  DAT_1403f316c = DAT_1403f316c + DAT_1403f3170 * param_2 + DAT_1403f3174 * param_3;

  DAT_1403f3170 = DAT_1403f3170 * fVar5 + DAT_1403f3174 * fVar4;

  DAT_1403f3174 = DAT_1403f3174 * fVar5 - fVar6;

  return;

}




