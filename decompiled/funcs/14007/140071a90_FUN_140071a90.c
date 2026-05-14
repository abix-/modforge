// Address: 0x140071a90
// Ghidra name: FUN_140071a90
// ============ 0x140071a90 FUN_140071a90 (size=635) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140071a90(float *param_1,float *param_2,float param_3,undefined8 param_4)



{

  float fVar1;

  undefined8 uVar2;

  undefined8 *puVar3;

  longlong lVar4;

  float fVar5;

  float fVar6;

  undefined8 local_128;

  undefined8 uStack_120;

  undefined8 local_118;

  undefined8 uStack_110;

  undefined8 local_108;

  undefined8 uStack_100;

  undefined8 local_f8;

  undefined8 uStack_f0;

  undefined8 local_e8;

  undefined8 uStack_e0;

  undefined8 local_d8;

  undefined8 uStack_d0;

  undefined8 local_c8;

  undefined8 uStack_c0;

  undefined8 local_b8;

  undefined8 uStack_b0;

  undefined8 local_a8;

  undefined8 uStack_a0;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  

  local_128 = 0;

  uStack_120 = 0;

  local_118 = _DAT_14030a340;

  uStack_110 = _UNK_14030a348;

  local_108 = 0;

  uStack_100 = 0;

  local_f8 = _DAT_14030a340;

  uStack_f0 = _UNK_14030a348;

  local_e8 = 0;

  uStack_e0 = 0;

  local_d8 = _DAT_14030a340;

  uStack_d0 = _UNK_14030a348;

  local_c8 = 0;

  uStack_c0 = 0;

  local_b8 = _DAT_14030a340;

  uStack_b0 = _UNK_14030a348;

  local_a8 = 0;

  uStack_a0 = 0;

  local_98 = _DAT_14030a340;

  uStack_90 = _UNK_14030a348;

  local_88 = 0;

  uStack_80 = 0;

  local_78 = _DAT_14030a340;

  uStack_70 = _UNK_14030a348;

  FUN_140074020(&local_128,param_1,param_2,param_3,param_4);

  puVar3 = &local_128;

  lVar4 = 6;

  do {

    FUN_1400745d0(puVar3);

    puVar3 = puVar3 + 4;

    lVar4 = lVar4 + -1;

  } while (lVar4 != 0);

  uVar2 = FUN_1400c43c0();

  SDL_RenderGeometryRaw(uVar2,0,&local_128,0x20,&local_118,0x20,&uStack_120,0x20,6,0,0,0);

  fVar1 = *param_2;

  fVar5 = fVar1 - *param_1;

  fVar6 = param_2[1] - param_1[1];

  fVar5 = fVar5 * fVar5 + fVar6 * fVar6;

  if (fVar5 < 0.0) {

    fVar5 = (float)FUN_1402cdfa0(fVar5);

  }

  else {

    fVar5 = SQRT(fVar5);

  }

  if ((DAT_14039c9f0 <= fVar5) && (DAT_14039c9f8 <= fVar5)) {

    param_3 = (DAT_14039ca44 / fVar5) * fVar6 * param_3;

    FUN_140071810(fVar1 - (param_3 + param_3));

  }

  return;

}




