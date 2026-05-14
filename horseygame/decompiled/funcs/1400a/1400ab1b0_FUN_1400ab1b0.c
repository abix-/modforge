// Address: 0x1400ab1b0
// Ghidra name: FUN_1400ab1b0
// ============ 0x1400ab1b0 FUN_1400ab1b0 (size=535) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_1400ab1b0(undefined8 param_1,undefined4 *param_2,float param_3,float param_4,

                      undefined4 param_5)



{

  float fVar1;

  float fVar2;

  undefined8 *puVar3;

  longlong lVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  

  FUN_1400c5f10();

  fVar5 = (float)FUN_1402cdc50();

  fVar6 = (float)FUN_1402cfda0();

  fVar1 = (float)param_2[0x11];

  fVar2 = (float)param_2[0x10];

  fVar7 = fVar6 * DAT_1403f3174 - fVar5 * DAT_1403f3170;

  fVar8 = fVar6 * DAT_1403f3170 + fVar5 * DAT_1403f3174;

  lVar4 = FUN_1400ab0a0(param_1,param_2[2],*param_2,0,param_2[0x22],

                        (fVar6 * DAT_1403f3168 - fVar5 * DAT_1403f316c) + fVar2 +

                        (fVar7 * param_3 - fVar8 * param_4),

                        fVar5 * DAT_1403f3168 + fVar6 * DAT_1403f316c + fVar1 +

                        fVar7 * param_4 + fVar8 * param_3,param_5,param_2[0x20]);

  *(float *)(lVar4 + 0x5c) = (fVar6 * param_3 - fVar5 * param_4) + fVar2;

  *(float *)(lVar4 + 0x60) = fVar5 * param_3 + fVar6 * param_4 + fVar1;

  puVar3 = DAT_1403f3180;

  if (DAT_1403f3180 == DAT_1403f3188) {

    FUN_140064060(&DAT_1403f3178,DAT_1403f3180,&DAT_1403f3168);

  }

  else {

    *DAT_1403f3180 = _DAT_1403f3168;

    puVar3[1] = _DAT_1403f3170;

    DAT_1403f3180 = DAT_1403f3180 + 2;

  }

  _DAT_1403f3168 = _DAT_14030a330;

  _DAT_1403f3170 = _UNK_14030a338;

  return lVar4;

}




