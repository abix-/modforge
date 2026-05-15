// Address: 0x14008faf0
// Ghidra name: FUN_14008faf0
// ============ 0x14008faf0 FUN_14008faf0 (size=476) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14008faf0(longlong param_1)



{

  undefined8 uVar1;

  ulonglong uVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  undefined4 uVar5;

  longlong lVar6;

  longlong lVar7;

  longlong *plVar8;

  undefined8 in_stack_ffffffffffffffa8;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  ulonglong uStack_30;

  

  uVar4 = _UNK_140304088;

  uVar3 = _DAT_140304080;

  uVar2 = _UNK_1403033d8;

  uVar1 = _DAT_1403033d0;

  lVar7 = 0;

  plVar8 = (longlong *)(param_1 + 0x390);

  do {

    uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);

    lVar6 = FUN_1402c704c();

    if (lVar6 == 0) {

      lVar6 = 0;

    }

    else {

      lVar6 = FUN_1400aac60(lVar6);

    }

    *plVar8 = lVar6;

    uStack_40 = 0;

    local_38 = uVar3;

    uStack_30 = uVar4;

    local_48 = (ulonglong)CONCAT14(s_human_140303b0c[4],s_human_140303b0c._0_4_);

    FUN_1400b2ee0(0,&local_48);

    if (0xf < uStack_30) {

      if (0xfff < uStack_30 + 1) {

        if (0x1f < (local_48 - *(longlong *)(local_48 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    lVar6 = *plVar8;

    in_stack_ffffffffffffffa8 = CONCAT44(uVar5,0xffffffff);

    uVar5 = FUN_1400c7600(0,0,0xffffffff,0xffffffff,in_stack_ffffffffffffffa8);

    *(undefined4 *)(lVar6 + 0x1f8) = uVar5;

    uStack_40 = 0;

    local_38 = uVar1;

    uStack_30 = uVar2;

    local_48 = (ulonglong)CONCAT24(s_Bookie_14030bbfc._4_2_,s_Bookie_14030bbfc._0_4_);

    FUN_1400cf950(param_1,*plVar8);

    if (0xf < uStack_30) {

      if (0xfff < uStack_30 + 1) {

        if (0x1f < (local_48 - *(longlong *)(local_48 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    lVar7 = lVar7 + 1;

    plVar8 = plVar8 + 1;

  } while (lVar7 < 3);

  return;

}




