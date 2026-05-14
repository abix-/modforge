// Address: 0x140071f00
// Ghidra name: FUN_140071f00
// ============ 0x140071f00 FUN_140071f00 (size=301) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140071f00(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5,undefined4 param_6)



{

  undefined8 uVar1;

  undefined8 uVar2;

  undefined8 *puVar3;

  longlong lVar4;

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

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  local_c8 = 0;

  uStack_c0 = 0;

  local_b8 = _DAT_14030a340;

  uStack_b0 = _UNK_14030a348;

  local_a8 = 0;

  uStack_a0 = 0;

  local_88 = 0;

  uStack_80 = 0;

  local_68 = 0;

  uStack_60 = 0;

  local_48 = 0;

  uStack_40 = 0;

  local_28 = 0;

  uStack_20 = 0;

  local_98 = _DAT_14030a340;

  uStack_90 = _UNK_14030a348;

  local_78 = _DAT_14030a340;

  uStack_70 = _UNK_14030a348;

  local_58 = _DAT_14030a340;

  uStack_50 = _UNK_14030a348;

  local_38 = _DAT_14030a340;

  uStack_30 = _UNK_14030a348;

  local_18 = _DAT_14030a340;

  uStack_10 = _UNK_14030a348;

  FUN_140073780(&local_c8,param_1,param_2,param_3,param_4,param_5,param_6);

  lVar4 = 6;

  puVar3 = &local_c8;

  uVar1 = *(undefined8 *)((longlong)param_1 * 0x38 + DAT_1403eacd8);

  do {

    FUN_1400745d0(puVar3);

    puVar3 = puVar3 + 4;

    lVar4 = lVar4 + -1;

  } while (lVar4 != 0);

  uVar2 = FUN_1400c43c0();

  SDL_RenderGeometryRaw(uVar2,uVar1,&local_c8,0x20,&local_b8,0x20,&uStack_c0,0x20,6,0,0,0);

  return;

}




