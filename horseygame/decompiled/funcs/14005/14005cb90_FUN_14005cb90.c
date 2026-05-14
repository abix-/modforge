// Address: 0x14005cb90
// Ghidra name: FUN_14005cb90
// ============ 0x14005cb90 FUN_14005cb90 (size=352) ============


void FUN_14005cb90(longlong param_1)



{

  undefined4 uVar1;

  int iVar2;

  undefined8 local_28;

  undefined8 local_20;

  undefined8 local_18;

  undefined8 local_10;

  

  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) <

      DAT_1403ea934) {

    FUN_1402c7138(&DAT_1403ea934);

    if (DAT_1403ea934 == -1) {

      local_20 = 0;

      local_18 = 7;

      local_10 = 0xf;

      local_28 = (ulonglong)

                 CONCAT16(DAT_140306938._6_1_,

                          CONCAT24(DAT_140306938._4_2_,(undefined4)DAT_140306938));

      DAT_1403ea930 = FUN_14006fe60(&local_28);

      _Init_thread_footer(&DAT_1403ea934);

    }

  }

  *(int *)(param_1 + 0x3c) = DAT_1403ea930 + *(int *)(param_1 + 0xc);

  if (*(int *)(param_1 + 0xc) == 5) {

    local_18 = 0xe;

    local_10 = 0xf;

    local_28._0_1_ = s_ItemPlutonium2_140306940[0];

    local_28._1_1_ = s_ItemPlutonium2_140306940[1];

    local_28._2_1_ = s_ItemPlutonium2_140306940[2];

    local_28._3_1_ = s_ItemPlutonium2_140306940[3];

    local_28._4_1_ = s_ItemPlutonium2_140306940[4];

    local_28._5_1_ = s_ItemPlutonium2_140306940[5];

    local_28._6_1_ = s_ItemPlutonium2_140306940[6];

    local_28._7_1_ = s_ItemPlutonium2_140306940[7];

    local_20 = (ulonglong)

               CONCAT24(s_ItemPlutonium2_140306940._12_2_,s_ItemPlutonium2_140306940._8_4_);

    uVar1 = FUN_14006fe60(&local_28);

    *(undefined4 *)(param_1 + 0x40) = uVar1;

  }

  iVar2 = FUN_140072ca0(*(undefined4 *)(param_1 + 0x3c));

  *(float *)(param_1 + 0x30) = (float)(iVar2 + 2) * DAT_140303354;

  iVar2 = FUN_140072cc0(*(undefined4 *)(param_1 + 0x3c));

  *(float *)(param_1 + 0x34) = (float)(iVar2 + 2) * DAT_140303354;

  if (*(int *)(param_1 + 0xc) == 0x12) {

    *(undefined4 *)(param_1 + 0x30) = 0x40180000;

    *(undefined4 *)(param_1 + 0x34) = 0x3fc00000;

  }

  return;

}




