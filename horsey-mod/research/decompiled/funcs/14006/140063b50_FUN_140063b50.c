// Address: 0x140063b50
// Ghidra name: FUN_140063b50
// ============ 0x140063b50 FUN_140063b50 (size=697) ============


void FUN_140063b50(undefined8 param_1,float param_2,float param_3,undefined8 param_4,char param_5)



{

  longlong lVar1;

  undefined4 uVar2;

  undefined8 *puVar3;

  undefined8 in_stack_ffffffffffffff88;

  undefined4 uVar4;

  longlong local_50;

  ulonglong uStack_48;

  undefined8 local_40;

  ulonglong local_38;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);

  lVar1 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);

  if (*(int *)(lVar1 + 4) < DAT_1403eaa30) {

    FUN_1402c7138(&DAT_1403eaa30);

    if (DAT_1403eaa30 == -1) {

      local_40 = 8;

      local_38 = 0xf;

      local_50 = 0x786f42657a697250;

      uStack_48 = 0;

      DAT_1403eaa2c = FUN_14006fe60(&local_50);

      _Init_thread_footer(&DAT_1403eaa30);

    }

  }

  if (*(int *)(lVar1 + 4) < DAT_1403eaa38) {

    FUN_1402c7138(&DAT_1403eaa38);

    if (DAT_1403eaa38 == -1) {

      local_40 = 10;

      local_38 = 0xf;

      local_50._0_1_ = s_ItemTrophy_1403055b0[0];

      local_50._1_1_ = s_ItemTrophy_1403055b0[1];

      local_50._2_1_ = s_ItemTrophy_1403055b0[2];

      local_50._3_1_ = s_ItemTrophy_1403055b0[3];

      local_50._4_1_ = s_ItemTrophy_1403055b0[4];

      local_50._5_1_ = s_ItemTrophy_1403055b0[5];

      local_50._6_1_ = s_ItemTrophy_1403055b0[6];

      local_50._7_1_ = s_ItemTrophy_1403055b0[7];

      uStack_48 = (ulonglong)(ushort)s_ItemTrophy_1403055b0._8_2_;

      DAT_1403eaa34 = FUN_14006fe60(&local_50);

      _Init_thread_footer(&DAT_1403eaa38);

    }

  }

  if (*(int *)(lVar1 + 4) < DAT_1403eaa40) {

    FUN_1402c7138(&DAT_1403eaa40);

    if (DAT_1403eaa40 == -1) {

      local_40 = 0xc;

      local_38 = 0xf;

      local_50._0_1_ = s_PrizePresent_140307a00[0];

      local_50._1_1_ = s_PrizePresent_140307a00[1];

      local_50._2_1_ = s_PrizePresent_140307a00[2];

      local_50._3_1_ = s_PrizePresent_140307a00[3];

      local_50._4_1_ = s_PrizePresent_140307a00[4];

      local_50._5_1_ = s_PrizePresent_140307a00[5];

      local_50._6_1_ = s_PrizePresent_140307a00[6];

      local_50._7_1_ = s_PrizePresent_140307a00[7];

      uStack_48 = (ulonglong)(uint)s_PrizePresent_140307a00._8_4_;

      DAT_1403eaa3c = FUN_14006fe60(&local_50);

      _Init_thread_footer(&DAT_1403eaa40);

    }

  }

  FUN_140071d20(DAT_1403eaa2c,param_2,param_3);

  uVar2 = DAT_1403eaa34;

  if (param_5 != '\0') {

    uVar2 = DAT_1403eaa3c;

  }

  FUN_140071d20(uVar2,param_2 + DAT_140303fd0,param_3 + DAT_140304c00);

  puVar3 = (undefined8 *)FUN_14008d760(&local_50,&DAT_140307a38);

  if (0xf < (ulonglong)puVar3[3]) {

    puVar3 = (undefined8 *)*puVar3;

  }

  FUN_140086570(DAT_1403ede28,param_2 - DAT_140303fe4,param_3 + DAT_140305630,0,

                CONCAT44(uVar4,DAT_14039ca44),DAT_1403d61cc,puVar3);

  if (0xf < local_38) {

    if (0xfff < local_38 + 1) {

      if (0x1f < (local_50 - *(longlong *)(local_50 + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  return;

}




