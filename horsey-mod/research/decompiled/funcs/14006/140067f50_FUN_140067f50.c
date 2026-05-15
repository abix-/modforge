// Address: 0x140067f50
// Ghidra name: FUN_140067f50
// ============ 0x140067f50 FUN_140067f50 (size=451) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140067f50(longlong param_1)



{

  undefined8 *puVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  longlong *plVar4;

  undefined8 uVar5;

  longlong lVar6;

  int iVar7;

  float local_res10 [2];

  undefined8 local_res18;

  longlong local_res20;

  longlong local_48;

  ulonglong uStack_40;

  undefined8 local_38;

  ulonglong uStack_30;

  

  FUN_1400d01d0(param_1,"Nuclear Physicist",0,DAT_1403d9e74);

  uVar3 = _UNK_1403040a8;

  uVar2 = _DAT_1403040a0;

  plVar4 = (longlong *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    plVar4 = DAT_1403d9530;

  }

  if (DAT_1403d9540 == 10) {

    lVar6 = *plVar4 + -0x616c507265776f50;

    if (lVar6 == 0) {

      lVar6 = (ulonglong)*(ushort *)(plVar4 + 1) - 0x746e;

    }

    if (lVar6 == 0) {

      DAT_1403d90d0 = 0x41c80000;

      iVar7 = 0;

      do {

        local_res20 = FUN_1402c704c(0x498);

        if (local_res20 == 0) {

          uVar5 = 0;

        }

        else {

          uVar5 = FUN_1400aac60(local_res20);

        }

        local_38 = uVar2;

        uStack_30 = uVar3;

        local_48._0_1_ = s_alligator_140303b48[0];

        local_48._1_1_ = s_alligator_140303b48[1];

        local_48._2_1_ = s_alligator_140303b48[2];

        local_48._3_1_ = s_alligator_140303b48[3];

        local_48._4_1_ = s_alligator_140303b48[4];

        local_48._5_1_ = s_alligator_140303b48[5];

        local_48._6_1_ = s_alligator_140303b48[6];

        local_48._7_1_ = s_alligator_140303b48[7];

        uStack_40 = (ulonglong)(byte)s_alligator_140303b48[8];

        local_res18 = uVar5;

        FUN_1400b2ee0(uVar5,&local_48);

        if (0xf < uStack_30) {

          if (0xfff < uStack_30 + 1) {

            if (0x1f < (local_48 - *(longlong *)(local_48 + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

          }

          FUN_1402c7088();

        }

        local_res10[0] = (float)(iVar7 + 0xe);

        local_res10[1] = 5.0;

        FUN_1400b6610(uVar5,local_res10);

        puVar1 = *(undefined8 **)(param_1 + 0x138);

        if (puVar1 == *(undefined8 **)(param_1 + 0x140)) {

          FUN_140030680(param_1 + 0x130,puVar1,&local_res18);

        }

        else {

          *puVar1 = uVar5;

          *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

        }

        iVar7 = iVar7 + 1;

      } while (iVar7 < 2);

    }

  }

  return;

}




