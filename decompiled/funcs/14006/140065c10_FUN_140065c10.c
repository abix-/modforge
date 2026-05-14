// Address: 0x140065c10
// Ghidra name: FUN_140065c10
// ============ 0x140065c10 FUN_140065c10 (size=497) ============


void FUN_140065c10(longlong param_1)



{

  int iVar1;

  float fVar2;

  undefined8 local_38;

  ulonglong uStack_30;

  undefined8 local_28;

  undefined8 local_20;

  

  FUN_140070f90(DAT_1403d6340);

  FUN_1400d6500(param_1,DAT_1403d6354);

  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

       < DAT_1403eaaa4) && (FUN_1402c7138(&DAT_1403eaaa4), DAT_1403eaaa4 == -1)) {

    local_28 = 10;

    local_20 = 0xf;

    local_38._0_1_ = s_HutchHouse_140307db0[0];

    local_38._1_1_ = s_HutchHouse_140307db0[1];

    local_38._2_1_ = s_HutchHouse_140307db0[2];

    local_38._3_1_ = s_HutchHouse_140307db0[3];

    local_38._4_1_ = s_HutchHouse_140307db0[4];

    local_38._5_1_ = s_HutchHouse_140307db0[5];

    local_38._6_1_ = s_HutchHouse_140307db0[6];

    local_38._7_1_ = s_HutchHouse_140307db0[7];

    uStack_30 = (ulonglong)(ushort)s_HutchHouse_140307db0._8_2_;

    DAT_1403eaaa0 = FUN_14006fe60(&local_38);

    _Init_thread_footer(&DAT_1403eaaa4);

  }

  FUN_140071d20(DAT_1403eaaa0);

  FUN_140071d20(DAT_1403eaaa0 + 1);

  iVar1 = 0x32;

  if (-9 - DAT_1403eda00 < 0x32) {

    do {

      FUN_140071d20(DAT_1403eaaa0 + 2);

      iVar1 = iVar1 + -9;

    } while (-9 - DAT_1403eda00 < iVar1);

  }

  fVar2 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar2 * *(float *)(param_1 + 0x110),fVar2 * *(float *)(param_1 + 0x10c)));

  FUN_1400d5d90(param_1,1);

  local_38 = *(undefined8 *)(*(longlong *)(param_1 + 0x78) + 0x30);

  uStack_30 = *(undefined8 *)(*(longlong *)(param_1 + 0x78) + 0x38);

  FUN_140071120(&local_38,DAT_1403d6308);

  FUN_1400d5ba0(param_1,3);

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  FUN_1400cacd0(param_1,1);

  return;

}




