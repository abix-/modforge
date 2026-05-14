// Address: 0x14005bc30
// Ghidra name: FUN_14005bc30
// ============ 0x14005bc30 FUN_14005bc30 (size=548) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14005bc30(longlong param_1)



{

  longlong *plVar1;

  undefined8 *puVar2;

  longlong *plVar3;

  longlong lVar4;

  longlong lVar5;

  int iVar6;

  longlong lVar7;

  longlong local_res8;

  longlong local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  *(int *)(param_1 + 0x250) = *(int *)(param_1 + 0x250) + 1;

  FUN_1400ca260();

  FUN_1400ceb60(param_1);

  plVar1 = (longlong *)(param_1 + 0x130);

  if (DAT_1403ed5f0 != '\0') {

    iVar6 = 0;

    lVar4 = *(longlong *)(param_1 + 0x138);

    lVar5 = *plVar1;

    if (lVar4 - lVar5 >> 3 != 0) {

      lVar7 = 0;

      do {

        FUN_1400b47e0(*(undefined8 *)(lVar7 + lVar5));

        puVar2 = *(undefined8 **)(lVar7 + *plVar1);

        if (puVar2 != (undefined8 *)0x0) {

          (**(code **)*puVar2)(puVar2,1);

        }

        iVar6 = iVar6 + 1;

        lVar7 = lVar7 + 8;

        lVar4 = *(longlong *)(param_1 + 0x138);

        lVar5 = *plVar1;

      } while ((ulonglong)(longlong)iVar6 < (ulonglong)(lVar4 - lVar5 >> 3));

    }

    if (lVar5 != lVar4) {

      *(longlong *)(param_1 + 0x138) = lVar5;

    }

    local_res8 = FUN_1402c704c(0x498);

    if (local_res8 == 0) {

      lVar4 = 0;

    }

    else {

      lVar4 = FUN_1400aac60(local_res8);

    }

    local_18 = _DAT_140304cc0;

    uStack_10 = _UNK_140304cc8;

    local_28._0_1_ = s_crazy_horse_140303b00[0];

    local_28._1_1_ = s_crazy_horse_140303b00[1];

    local_28._2_1_ = s_crazy_horse_140303b00[2];

    local_28._3_1_ = s_crazy_horse_140303b00[3];

    local_28._4_1_ = s_crazy_horse_140303b00[4];

    local_28._5_1_ = s_crazy_horse_140303b00[5];

    local_28._6_1_ = s_crazy_horse_140303b00[6];

    local_28._7_1_ = s_crazy_horse_140303b00[7];

    uStack_20 = (ulonglong)CONCAT12(s_crazy_horse_140303b00[10],s_crazy_horse_140303b00._8_2_);

    local_res8 = lVar4;

    FUN_1400b2ee0(lVar4,&local_28);

    if (0xf < uStack_10) {

      if (0xfff < uStack_10 + 1) {

        if (0x1f < (local_28 - *(longlong *)(local_28 + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    FUN_1400b6820(lVar4);

    plVar3 = *(longlong **)(param_1 + 0x138);

    if (plVar3 == *(longlong **)(param_1 + 0x140)) {

      FUN_140030680(plVar1,plVar3,&local_res8);

    }

    else {

      *plVar3 = lVar4;

      *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

    }

    FUN_1400cead0(param_1,lVar4);

  }

  if ((DAT_1403ed637 != '\0') && (*(longlong *)(param_1 + 0x138) - *plVar1 >> 3 != 0)) {

    FUN_1400b7fe0(*(undefined8 *)*plVar1,0);

  }

  if (*(int *)(param_1 + 0xe0) == 0) {

    FUN_1400cdae0(param_1);

  }

  if (*(int *)(param_1 + 0x124) == 3) {

    *(undefined4 *)(param_1 + 0x124) = 0xffffffff;

  }

  return;

}




