// Address: 0x140071810
// Ghidra name: FUN_140071810
// ============ 0x140071810 FUN_140071810 (size=378) ============


void FUN_140071810(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5,undefined4 param_6,uint param_7)



{

  undefined8 uVar1;

  undefined4 *puVar2;

  longlong lVar3;

  undefined4 local_88;

  undefined4 local_84;

  undefined8 local_80;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  undefined4 local_68;

  undefined4 local_64;

  undefined8 local_60;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined8 local_40;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  

  puVar2 = &local_88;

  lVar3 = 3;

  local_80 = 0;

  local_60 = 0;

  local_40 = 0;

  local_78 = (float)(param_7 & 0xff) / DAT_14030a2d0;

  local_70 = (float)(param_7 >> 0x10 & 0xff) / DAT_14030a2d0;

  local_6c = (float)(param_7 >> 0x18) / DAT_14030a2d0;

  local_74 = (float)(param_7 >> 8 & 0xff) / DAT_14030a2d0;

  local_48 = param_5;

  local_44 = param_6;

  local_88 = param_1;

  local_84 = param_2;

  local_68 = param_3;

  local_64 = param_4;

  local_58 = local_78;

  local_54 = local_74;

  local_50 = local_70;

  local_4c = local_6c;

  local_38 = local_78;

  local_34 = local_74;

  local_30 = local_70;

  local_2c = local_6c;

  do {

    FUN_1400745d0(puVar2);

    puVar2 = puVar2 + 8;

    lVar3 = lVar3 + -1;

  } while (lVar3 != 0);

  uVar1 = FUN_1400c43c0();

  SDL_RenderGeometryRaw(uVar1,0,&local_88,0x20,&local_78,0x20,&local_80,0x20,3,0,0,0);

  return;

}




