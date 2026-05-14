// Address: 0x1400735d0
// Ghidra name: FUN_1400735d0
// ============ 0x1400735d0 FUN_1400735d0 (size=422) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400735d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5)



{

  undefined8 uVar1;

  undefined8 uVar2;

  longlong lVar3;

  undefined4 *puVar4;

  longlong lVar5;

  undefined4 local_d8;

  undefined4 local_d4;

  float local_d0;

  float local_cc;

  undefined8 local_c8;

  undefined8 uStack_c0;

  undefined4 local_b8;

  undefined4 uStack_b4;

  undefined4 uStack_b0;

  float fStack_ac;

  undefined8 local_a8;

  undefined8 uStack_a0;

  undefined4 local_98;

  undefined4 uStack_94;

  float fStack_90;

  undefined4 uStack_8c;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined4 local_58;

  undefined4 uStack_54;

  float fStack_50;

  undefined4 uStack_4c;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  undefined8 local_28;

  undefined8 uStack_20;

  

  puVar4 = &local_d8;

  lVar5 = 6;

  lVar3 = (longlong)param_1 * 0x38;

  local_d0 = *(float *)(lVar3 + 0x24 + DAT_1403eacd8) + DAT_14039c9f8;

  local_cc = *(float *)(lVar3 + 0x2c + DAT_1403eacd8) + DAT_14039c9f8;

  local_c8 = _DAT_1403d94c0;

  uStack_c0 = _DAT_1403d94c8;

  uStack_b0 = *(undefined4 *)(lVar3 + 0x28 + DAT_1403eacd8);

  fStack_ac = *(float *)(lVar3 + 0x2c + DAT_1403eacd8) + DAT_14039c9f8;

  local_a8 = _DAT_1403d94c0;

  uStack_a0 = _DAT_1403d94c8;

  fStack_90 = *(float *)(lVar3 + 0x24 + DAT_1403eacd8) + DAT_14039c9f8;

  uStack_8c = *(undefined4 *)(lVar3 + 0x30 + DAT_1403eacd8);

  local_78 = CONCAT44(param_3,param_4);

  uStack_70 = CONCAT44(fStack_ac,uStack_b0);

  uStack_94 = param_5;

  uStack_54 = param_5;

  local_34 = param_5;

  local_88 = _DAT_1403d94c0;

  uStack_80 = _DAT_1403d94c8;

  local_68 = _DAT_1403d94c0;

  uStack_60 = _DAT_1403d94c8;

  local_48 = _DAT_1403d94c0;

  uStack_40 = _DAT_1403d94c8;

  local_30 = *(undefined4 *)(lVar3 + 0x28 + DAT_1403eacd8);

  local_2c = *(undefined4 *)(lVar3 + 0x30 + DAT_1403eacd8);

  local_28 = _DAT_1403d94c0;

  uStack_20 = _DAT_1403d94c8;

  uVar1 = *(undefined8 *)(lVar3 + DAT_1403eacd8);

  local_d8 = param_2;

  local_d4 = param_3;

  local_b8 = param_4;

  uStack_b4 = param_3;

  local_98 = param_2;

  local_58 = param_2;

  fStack_50 = fStack_90;

  uStack_4c = uStack_8c;

  local_38 = param_4;

  do {

    FUN_1400745d0(puVar4);

    puVar4 = puVar4 + 8;

    lVar5 = lVar5 + -1;

  } while (lVar5 != 0);

  uVar2 = FUN_1400c43c0();

  SDL_RenderGeometryRaw(uVar2,uVar1,&local_d8,0x20,&local_c8,0x20,&local_d0,0x20,6,0,0,0);

  return;

}




