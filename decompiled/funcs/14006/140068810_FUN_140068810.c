// Address: 0x140068810
// Ghidra name: FUN_140068810
// ============ 0x140068810 FUN_140068810 (size=268) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140068810(longlong param_1,longlong param_2)



{

  undefined8 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar5;

  char *local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  if ((*(char *)(param_1 + 0x280) == '\0') && (*(int *)(param_2 + 0xc) == 5)) {

    local_28 = (char *)0x0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    local_28 = (char *)FUN_1400285e0(0x30);

    uVar1 = s_Don_t_worry_I_buried_all_the_plu_140309aa0._8_8_;

    local_18 = _DAT_140304180;

    uStack_10 = _UNK_140304188;

    *(undefined8 *)local_28 = s_Don_t_worry_I_buried_all_the_plu_140309aa0._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar1;

    uVar4 = s_Don_t_worry_I_buried_all_the_plu_140309aa0._28_4_;

    uVar3 = s_Don_t_worry_I_buried_all_the_plu_140309aa0._24_4_;

    uVar2 = s_Don_t_worry_I_buried_all_the_plu_140309aa0._20_4_;

    *(undefined4 *)(local_28 + 0x10) = s_Don_t_worry_I_buried_all_the_plu_140309aa0._16_4_;

    *(undefined4 *)(local_28 + 0x14) = uVar2;

    *(undefined4 *)(local_28 + 0x18) = uVar3;

    *(undefined4 *)(local_28 + 0x1c) = uVar4;

    *(undefined4 *)(local_28 + 0x20) = s_Don_t_worry_I_buried_all_the_plu_140309aa0._32_4_;

    *(undefined2 *)(local_28 + 0x24) = s_Don_t_worry_I_buried_all_the_plu_140309aa0._36_2_;

    local_28[0x26] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,CONCAT44(uVar5,DAT_140303758)

                 );

    if (0xf < uStack_10) {

      if (0xfff < uStack_10 + 1) {

        if ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    *(undefined1 *)(param_1 + 0x280) = 1;

    *(undefined4 *)(param_1 + 0x27c) = 0;

  }

  return;

}




