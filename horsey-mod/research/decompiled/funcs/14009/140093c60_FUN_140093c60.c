// Address: 0x140093c60
// Ghidra name: FUN_140093c60
// ============ 0x140093c60 FUN_140093c60 (size=296) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140093c60(undefined8 param_1,float param_2,int *param_3,int *param_4)



{

  float fVar1;

  longlong lVar2;

  int iVar3;

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

  undefined4 local_18;

  undefined4 local_14;

  

  iVar3 = 0x38;

  local_f8 = _DAT_14030c3b0;

  uStack_f0 = _UNK_14030c3b8;

  local_d8 = _DAT_14030c2f0;

  uStack_d0 = _UNK_14030c2f8;

  local_b8 = _DAT_14030c310;

  uStack_b0 = _UNK_14030c318;

  local_a8 = _DAT_14030c320;

  uStack_a0 = _UNK_14030c328;

  local_98 = _DAT_14030c330;

  uStack_90 = _UNK_14030c338;

  local_88 = _DAT_14030c340;

  uStack_80 = _UNK_14030c348;

  local_e8 = _DAT_14030c2e0;

  uStack_e0 = _UNK_14030c2e8;

  local_c8 = _DAT_14030c300;

  uStack_c0 = _UNK_14030c308;

  local_78 = _DAT_14030c350;

  uStack_70 = _UNK_14030c358;

  local_68 = _DAT_14030c360;

  uStack_60 = _UNK_14030c368;

  local_58 = _DAT_14030c370;

  uStack_50 = _UNK_14030c378;

  local_48 = _DAT_14030c380;

  uStack_40 = _UNK_14030c388;

  local_38 = _DAT_14030c390;

  uStack_30 = _UNK_14030c398;

  local_28 = _DAT_14030c3a0;

  uStack_20 = _UNK_14030c3a8;

  local_18 = 0x437a0000;

  local_14 = 0x3f800000;

  lVar2 = 0x38;

  do {

    fVar1 = *(float *)((longlong)&local_f8 + lVar2 * 4 + 4);

    if (param_2 <=

        (fVar1 / ((fVar1 + *(float *)((longlong)&local_f8 + lVar2 * 4)) - DAT_14039ca44)) *

        DAT_14030c26c) break;

    iVar3 = iVar3 + -2;

    lVar2 = lVar2 + -2;

  } while (0 < lVar2);

  *param_3 = (int)*(float *)((longlong)&local_f8 + (longlong)iVar3 * 4);

  *param_4 = (int)*(float *)((longlong)&local_f8 + (longlong)iVar3 * 4 + 4);

  return;

}




