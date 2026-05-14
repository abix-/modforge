// Address: 0x1400f6010
// Ghidra name: FUN_1400f6010
// ============ 0x1400f6010 FUN_1400f6010 (size=1003) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400f6010(longlong param_1)



{

  int iVar1;

  undefined8 *puVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar5;

  char *local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  ulonglong uStack_20;

  

  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  if (*(char *)(param_1 + 0x26c) == '\0') {

    iVar1 = *(int *)(param_1 + 0x260);

    if (iVar1 == 0) {

      local_38 = (char *)0x0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_38 = (char *)FUN_1400285e0(0x20);

      uVar3 = _UNK_140312818;

      local_28 = _DAT_140304d00;

      uStack_20 = _UNK_140304d08;

      *(undefined8 *)local_38 = _DAT_140312810;

      *(undefined8 *)(local_38 + 8) = uVar3;

      *(undefined8 *)(local_38 + 0x10) = DAT_140312820;

      *(undefined4 *)(local_38 + 0x18) = DAT_140312828;

      local_38[0x1c] = DAT_14031282c;

      local_38[0x1d] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),&local_38,0,CONCAT44(uVar5,DAT_1403033b4)

                   );

      if (0xf < uStack_20) {

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      uVar4 = _UNK_14039caa8;

      uVar3 = _DAT_14039caa0;

      uStack_30 = 0;

      local_28 = _DAT_14039caa0;

      uStack_20 = _UNK_14039caa8;

      local_38 = (char *)0x0;

      puVar2 = *(undefined8 **)(param_1 + 0x218);

      if (puVar2 == *(undefined8 **)(param_1 + 0x220)) {

        FUN_140087c70();

        uVar4 = uStack_20;

      }

      else {

        *puVar2 = 0;

        puVar2[1] = 0;

        puVar2[2] = uVar3;

        puVar2[3] = uVar4;

        local_38 = (char *)0x0;

        *(longlong *)(param_1 + 0x218) = *(longlong *)(param_1 + 0x218) + 0x20;

        uVar4 = 0xf;

      }

      if (uVar4 < 0x10) {

        return;

      }

      if ((0xfff < uVar4 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    else if (iVar1 == 1) {

      local_38 = (char *)0x0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_38 = (char *)FUN_1400285e0(0x30);

      uVar3 = s_Show_me_any_trophies_that_you_wi_140312830._8_8_;

      local_28 = _DAT_140304160;

      uStack_20 = _UNK_140304168;

      *(undefined8 *)local_38 = s_Show_me_any_trophies_that_you_wi_140312830._0_8_;

      *(undefined8 *)(local_38 + 8) = uVar3;

      uVar3 = s_Show_me_any_trophies_that_you_wi_140312830._24_8_;

      *(undefined8 *)(local_38 + 0x10) = s_Show_me_any_trophies_that_you_wi_140312830._16_8_;

      *(undefined8 *)(local_38 + 0x18) = uVar3;

      local_38[0x20] = s_Show_me_any_trophies_that_you_wi_140312830[0x20];

      local_38[0x21] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),&local_38,0,CONCAT44(uVar5,DAT_140303758)

                   );

      if (uStack_20 < 0x10) {

        return;

      }

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    else {

      if (iVar1 != 8) {

        return;

      }

      local_28 = _DAT_140304090;

      uStack_20 = _UNK_140304098;

      local_38 = (char *)0x216f72656820794d;

      uStack_30 = 0;

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),&local_38,0,CONCAT44(uVar5,DAT_140303758)

                   );

      if (uStack_20 < 0x10) {

        return;

      }

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

  }

  else {

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x20);

    uVar3 = s_Pour_it_into_my_mouth_1403127f8._8_8_;

    local_28 = _DAT_140304110;

    uStack_20 = _UNK_140304118;

    *(undefined8 *)local_38 = s_Pour_it_into_my_mouth_1403127f8._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar3;

    *(undefined4 *)(local_38 + 0x10) = s_Pour_it_into_my_mouth_1403127f8._16_4_;

    local_38[0x14] = s_Pour_it_into_my_mouth_1403127f8[0x14];

    local_38[0x15] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),&local_38,0,CONCAT44(uVar5,DAT_140303758));

    if (uStack_20 < 0x10) {

      return;

    }

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

  return;

}




