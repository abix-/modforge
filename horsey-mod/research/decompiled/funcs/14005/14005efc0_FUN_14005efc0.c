// Address: 0x14005efc0
// Ghidra name: FUN_14005efc0
// ============ 0x14005efc0 FUN_14005efc0 (size=526) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14005efc0(longlong param_1,int param_2,int param_3)



{

  undefined4 uVar1;

  char cVar2;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar4;

  undefined8 uVar3;

  char *local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  ulonglong uStack_20;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  if (((*(char *)(*(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8) + 0x204) ==

        '\0') && (param_3 == 0)) && (*(longlong *)(param_1 + 0x148) != 0)) {

    cVar2 = FUN_1400b7650();

    if (cVar2 != '\0') {

      if (*(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8) ==

          *(longlong *)(param_1 + 0x260)) {

        local_38 = (char *)0x0;

        uStack_30 = 0;

        local_28 = 0;

        uStack_20 = 0;

        local_38 = (char *)FUN_1400285e0(0x20);

        uVar3 = s_I_hate_that_thing_140307210._8_8_;

        local_28 = _DAT_1403040f0;

        uStack_20 = _UNK_1403040f8;

        *(undefined8 *)local_38 = s_I_hate_that_thing_140307210._0_8_;

        *(undefined8 *)(local_38 + 8) = uVar3;

        local_38[0x10] = s_I_hate_that_thing_140307210[0x10];

        local_38[0x11] = '\0';

        uVar1 = DAT_140303758;

        uVar3 = CONCAT44(uVar4,DAT_140303758);

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,uVar3);

        uVar4 = (undefined4)((ulonglong)uVar3 >> 0x20);

        if (0xf < uStack_20) {

          if (0xfff < uStack_20 + 1) {

            if ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

          }

          FUN_1402c7088();

        }

        local_38 = (char *)0x0;

        uStack_30 = 0;

        local_28 = 0;

        uStack_20 = 0;

        local_38 = (char *)FUN_1400285e0(0x20);

        uVar3 = s_But_you_can_t_have_it_140307228._8_8_;

        local_28 = _DAT_140304110;

        uStack_20 = _UNK_140304118;

        *(undefined8 *)local_38 = s_But_you_can_t_have_it_140307228._0_8_;

        *(undefined8 *)(local_38 + 8) = uVar3;

        *(undefined4 *)(local_38 + 0x10) = s_But_you_can_t_have_it_140307228._16_4_;

        local_38[0x14] = s_But_you_can_t_have_it_140307228[0x14];

        local_38[0x15] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar4,uVar1));

        if (0xf < uStack_20) {

          if (0xfff < uStack_20 + 1) {

            if ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

          }

          FUN_1402c7088();

        }

      }

      return 0;

    }

  }

  return 1;

}




