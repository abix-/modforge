// Address: 0x14005c9b0
// Ghidra name: FUN_14005c9b0
// ============ 0x14005c9b0 FUN_14005c9b0 (size=472) ============


undefined8 *

FUN_14005c9b0(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  undefined4 uVar1;

  int iVar2;

  undefined8 local_50;

  undefined8 local_48;

  undefined8 local_40;

  undefined8 local_38;

  

  FUN_1400a8610(param_1,3);

  *(undefined4 *)(param_1 + 0xe) = 0;

  param_1[0xf] = 0;

  *param_1 = &PTR_FUN_1403068e0;

  *(undefined4 *)((longlong)param_1 + 0xc) = param_2;

  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) <

      DAT_1403ea934) {

    FUN_1402c7138(&DAT_1403ea934);

    if (DAT_1403ea934 == -1) {

      local_48 = 0;

      local_40 = 7;

      local_38 = 0xf;

      local_50 = (ulonglong)

                 CONCAT16(DAT_140306938._6_1_,

                          CONCAT24(DAT_140306938._4_2_,(undefined4)DAT_140306938));

      DAT_1403ea930 = FUN_14006fe60(&local_50);

      _Init_thread_footer(&DAT_1403ea934);

    }

  }

  *(int *)((longlong)param_1 + 0x3c) = DAT_1403ea930 + *(int *)((longlong)param_1 + 0xc);

  if (*(int *)((longlong)param_1 + 0xc) == 5) {

    local_40 = 0xe;

    local_38 = 0xf;

    local_50._0_1_ = s_ItemPlutonium2_140306940[0];

    local_50._1_1_ = s_ItemPlutonium2_140306940[1];

    local_50._2_1_ = s_ItemPlutonium2_140306940[2];

    local_50._3_1_ = s_ItemPlutonium2_140306940[3];

    local_50._4_1_ = s_ItemPlutonium2_140306940[4];

    local_50._5_1_ = s_ItemPlutonium2_140306940[5];

    local_50._6_1_ = s_ItemPlutonium2_140306940[6];

    local_50._7_1_ = s_ItemPlutonium2_140306940[7];

    local_48 = (ulonglong)

               CONCAT24(s_ItemPlutonium2_140306940._12_2_,s_ItemPlutonium2_140306940._8_4_);

    uVar1 = FUN_14006fe60(&local_50);

    *(undefined4 *)(param_1 + 8) = uVar1;

  }

  iVar2 = FUN_140072ca0(*(undefined4 *)((longlong)param_1 + 0x3c));

  *(float *)(param_1 + 6) = (float)(iVar2 + 2) * DAT_140303354;

  iVar2 = FUN_140072cc0(*(undefined4 *)((longlong)param_1 + 0x3c));

  *(float *)((longlong)param_1 + 0x34) = (float)(iVar2 + 2) * DAT_140303354;

  if (*(int *)((longlong)param_1 + 0xc) == 0x12) {

    *(undefined4 *)(param_1 + 6) = 0x40180000;

    *(undefined4 *)((longlong)param_1 + 0x34) = 0x3fc00000;

  }

  *(undefined4 *)(param_1 + 5) = param_3;

  *(undefined4 *)((longlong)param_1 + 0x2c) = param_4;

  *(undefined4 *)((longlong)param_1 + 0x44) =

       *(undefined4 *)(&DAT_1403d4e90 + (longlong)*(int *)((longlong)param_1 + 0xc) * 0x58);

  return param_1;

}




