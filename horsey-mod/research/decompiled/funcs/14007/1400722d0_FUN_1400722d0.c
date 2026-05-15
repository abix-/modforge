// Address: 0x1400722d0
// Ghidra name: FUN_1400722d0
// ============ 0x1400722d0 FUN_1400722d0 (size=570) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400722d0(int param_1,float param_2,float param_3,float param_4,float param_5,float param_6

                  ,float param_7,float param_8)



{

  undefined8 uVar1;

  undefined8 uVar2;

  longlong lVar3;

  float *pfVar4;

  longlong lVar5;

  float fVar6;

  float fVar7;

  float local_118;

  float local_114;

  float local_110;

  float local_10c;

  undefined8 local_108;

  undefined8 uStack_100;

  float local_f8;

  float fStack_f4;

  float fStack_f0;

  float fStack_ec;

  undefined8 local_e8;

  undefined8 uStack_e0;

  float local_d8;

  float fStack_d4;

  float fStack_d0;

  float fStack_cc;

  undefined8 local_c8;

  undefined8 uStack_c0;

  float local_b8;

  float fStack_b4;

  float fStack_b0;

  float fStack_ac;

  undefined8 local_a8;

  undefined8 uStack_a0;

  float local_98;

  float fStack_94;

  float fStack_90;

  float fStack_8c;

  undefined8 local_88;

  undefined8 uStack_80;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  undefined8 local_68;

  undefined8 uStack_60;

  

  pfVar4 = &local_118;

  lVar5 = 6;

  lVar3 = (longlong)param_1 * 0x38;

  local_f8 = param_6 * param_8 + param_2;

  fStack_f0 = *(float *)(lVar3 + 0x24 + DAT_1403eacd8);

  local_10c = *(float *)(lVar3 + 0x2c + DAT_1403eacd8);

  fVar7 = *(float *)(lVar3 + 0x28 + DAT_1403eacd8) - fStack_f0;

  fVar6 = *(float *)(lVar3 + 0x30 + DAT_1403eacd8) - local_10c;

  local_110 = (param_4 / *(float *)(lVar3 + 0xc + DAT_1403eacd8)) * fVar7 + fStack_f0;

  fStack_f0 = ((param_4 + param_6) / *(float *)(lVar3 + 0xc + DAT_1403eacd8)) * fVar7 + fStack_f0;

  fStack_d4 = param_7 * param_8 + param_3;

  fStack_cc = ((param_5 + param_7) / *(float *)(lVar3 + 0x10 + DAT_1403eacd8)) * fVar6 + local_10c;

  local_10c = (param_5 / *(float *)(lVar3 + 0x10 + DAT_1403eacd8)) * fVar6 + local_10c;

  local_108 = _DAT_1403d94c0;

  uStack_100 = _DAT_1403d94c8;

  local_e8 = _DAT_1403d94c0;

  uStack_e0 = _DAT_1403d94c8;

  local_c8 = _DAT_1403d94c0;

  uStack_c0 = _DAT_1403d94c8;

  local_a8 = _DAT_1403d94c0;

  uStack_a0 = _DAT_1403d94c8;

  local_88 = _DAT_1403d94c0;

  uStack_80 = _DAT_1403d94c8;

  local_68 = _DAT_1403d94c0;

  uStack_60 = _DAT_1403d94c8;

  uVar1 = *(undefined8 *)(lVar3 + DAT_1403eacd8);

  local_118 = param_2;

  local_114 = param_3;

  fStack_f4 = param_3;

  fStack_ec = local_10c;

  local_d8 = param_2;

  fStack_d0 = local_110;

  local_b8 = local_f8;

  fStack_b4 = param_3;

  fStack_b0 = fStack_f0;

  fStack_ac = local_10c;

  local_98 = param_2;

  fStack_94 = fStack_d4;

  fStack_90 = local_110;

  fStack_8c = fStack_cc;

  local_78 = local_f8;

  local_74 = fStack_d4;

  local_70 = fStack_f0;

  local_6c = fStack_cc;

  do {

    FUN_1400745d0(pfVar4);

    pfVar4 = pfVar4 + 8;

    lVar5 = lVar5 + -1;

  } while (lVar5 != 0);

  uVar2 = FUN_1400c43c0();

  SDL_RenderGeometryRaw(uVar2,uVar1,&local_118,0x20,&local_108,0x20,&local_110,0x20,6,0,0,0);

  return;

}




