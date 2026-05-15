// Address: 0x140104b20
// Ghidra name: FUN_140104b20
// ============ 0x140104b20 FUN_140104b20 (size=205) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140104b20(longlong param_1,int param_2,char param_3)



{

  longlong local_28;

  ulonglong uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  *(int *)(param_1 + 0x310) = param_2;

  *(int *)(param_1 + 0x308) = *(int *)(param_1 + 0x308) + param_2;

  *(undefined4 *)(param_1 + 0x30c) = 0x3c;

  if (param_3 == '\0') {

    local_18 = _DAT_1403040a0;

    uStack_10 = _UNK_1403040a8;

    local_28._0_1_ = s_GainMoney_1403137f0[0];

    local_28._1_1_ = s_GainMoney_1403137f0[1];

    local_28._2_1_ = s_GainMoney_1403137f0[2];

    local_28._3_1_ = s_GainMoney_1403137f0[3];

    local_28._4_1_ = s_GainMoney_1403137f0[4];

    local_28._5_1_ = s_GainMoney_1403137f0[5];

    local_28._6_1_ = s_GainMoney_1403137f0[6];

    local_28._7_1_ = s_GainMoney_1403137f0[7];

    uStack_20 = (ulonglong)(byte)s_GainMoney_1403137f0[8];

    FUN_140040ca0(&local_28,0x3c,0,DAT_14039ca44,0);

    if (0xf < uStack_10) {

      if (0xfff < uStack_10 + 1) {

        if (0x1f < (local_28 - *(longlong *)(local_28 + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

  }

  return;

}




