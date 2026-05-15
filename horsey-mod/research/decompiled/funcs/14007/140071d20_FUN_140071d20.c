// Address: 0x140071d20
// Ghidra name: FUN_140071d20
// ============ 0x140071d20 FUN_140071d20 (size=417) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140071d20(int param_1,float param_2,float param_3)



{

  undefined8 uVar1;

  undefined8 uVar2;

  longlong lVar3;

  float *pfVar4;

  longlong lVar5;

  float local_c8;

  float local_c4;

  undefined4 local_c0;

  undefined4 local_bc;

  undefined8 local_b8;

  undefined8 uStack_b0;

  float local_a8;

  float fStack_a4;

  undefined4 uStack_a0;

  undefined4 uStack_9c;

  undefined8 local_98;

  undefined8 uStack_90;

  float local_88;

  float fStack_84;

  undefined4 uStack_80;

  undefined4 uStack_7c;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  float local_48;

  float fStack_44;

  undefined4 uStack_40;

  undefined4 uStack_3c;

  undefined8 local_38;

  undefined8 uStack_30;

  float local_28;

  float local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined8 local_18;

  undefined8 uStack_10;

  

  lVar3 = (longlong)param_1 * 0x38;

  pfVar4 = &local_c8;

  lVar5 = 6;

  local_c8 = param_2 - *(float *)(lVar3 + 0x1c + DAT_1403eacd8);

  local_c4 = param_3 - *(float *)(lVar3 + 0x20 + DAT_1403eacd8);

  local_c0 = *(undefined4 *)(lVar3 + 0x24 + DAT_1403eacd8);

  local_bc = *(undefined4 *)(lVar3 + 0x2c + DAT_1403eacd8);

  local_b8 = _DAT_1403d94c0;

  uStack_b0 = _DAT_1403d94c8;

  local_a8 = local_c8 + *(float *)(lVar3 + 0xc + DAT_1403eacd8);

  uStack_a0 = *(undefined4 *)(lVar3 + 0x28 + DAT_1403eacd8);

  uStack_9c = *(undefined4 *)(lVar3 + 0x2c + DAT_1403eacd8);

  local_98 = _DAT_1403d94c0;

  uStack_90 = _DAT_1403d94c8;

  fStack_84 = local_c4 + *(float *)(lVar3 + 0x10 + DAT_1403eacd8);

  uStack_80 = *(undefined4 *)(lVar3 + 0x24 + DAT_1403eacd8);

  uStack_7c = *(undefined4 *)(lVar3 + 0x30 + DAT_1403eacd8);

  local_78 = _DAT_1403d94c0;

  uStack_70 = _DAT_1403d94c8;

  local_24 = local_c4 + *(float *)(lVar3 + 0x10 + DAT_1403eacd8);

  local_28 = local_c8 + *(float *)(lVar3 + 0xc + DAT_1403eacd8);

  local_20 = *(undefined4 *)(lVar3 + 0x28 + DAT_1403eacd8);

  local_1c = *(undefined4 *)(lVar3 + 0x30 + DAT_1403eacd8);

  local_68 = CONCAT44(local_c4,local_a8);

  uStack_60 = CONCAT44(uStack_9c,uStack_a0);

  local_18 = _DAT_1403d94c0;

  uStack_10 = _DAT_1403d94c8;

  local_58 = _DAT_1403d94c0;

  uStack_50 = _DAT_1403d94c8;

  local_38 = _DAT_1403d94c0;

  uStack_30 = _DAT_1403d94c8;

  uVar1 = *(undefined8 *)(lVar3 + DAT_1403eacd8);

  fStack_a4 = local_c4;

  local_88 = local_c8;

  local_48 = local_c8;

  fStack_44 = fStack_84;

  uStack_40 = uStack_80;

  uStack_3c = uStack_7c;

  do {

    FUN_1400745d0(pfVar4);

    pfVar4 = pfVar4 + 8;

    lVar5 = lVar5 + -1;

  } while (lVar5 != 0);

  uVar2 = FUN_1400c43c0();

  SDL_RenderGeometryRaw(uVar2,uVar1,&local_c8,0x20,&local_b8,0x20,&local_c0,0x20,6,0,0,0);

  return;

}




