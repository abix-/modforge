// Address: 0x14008edc0
// Ghidra name: FUN_14008edc0
// ============ 0x14008edc0 FUN_14008edc0 (size=573) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14008edc0(longlong param_1,longlong param_2,int param_3)



{

  int iVar1;

  undefined8 uVar2;

  char cVar3;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar4;

  char *local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  if ((((*(char *)(param_2 + 0x10) == '\0') && (*(int *)(param_2 + 8) == 3)) && (param_3 == 0)) &&

     ((iVar1 = *(int *)(param_2 + 0xc), iVar1 == 0x17 || (iVar1 - 0x18U < 2)))) {

    cVar3 = FUN_140104c00(DAT_1403fb0d8,0xfa,0);

    local_28 = (char *)0x0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    if (cVar3 != '\0') {

      local_28 = (char *)FUN_1400285e0(0x20);

      uVar2 = s_Let_s_install_that_now_14030b958._8_8_;

      local_18 = _DAT_140305fd0;

      uStack_10 = _UNK_140305fd8;

      *(undefined8 *)local_28 = s_Let_s_install_that_now_14030b958._0_8_;

      *(undefined8 *)(local_28 + 8) = uVar2;

      *(undefined4 *)(local_28 + 0x10) = s_Let_s_install_that_now_14030b958._16_4_;

      *(undefined2 *)(local_28 + 0x14) = s_Let_s_install_that_now_14030b958._20_2_;

      local_28[0x16] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,

                    CONCAT44(uVar4,DAT_140303758));

      if (0xf < uStack_10) {

        if (0xfff < uStack_10 + 1) {

          if ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

        }

        FUN_1402c7088();

      }

      *(undefined1 *)(param_2 + 0x10) = 1;

      *(undefined4 *)(param_1 + 0x250) = 1;

      *(undefined4 *)(param_1 + 0x25c) = 0;

      return;

    }

    local_28 = (char *)FUN_1400285e0(0x20);

    uVar2 = s_You_can_t_afford_that_140305900._8_8_;

    local_18 = _DAT_140304110;

    uStack_10 = _UNK_140304118;

    *(undefined8 *)local_28 = s_You_can_t_afford_that_140305900._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar2;

    *(undefined4 *)(local_28 + 0x10) = s_You_can_t_afford_that_140305900._16_4_;

    local_28[0x14] = s_You_can_t_afford_that_140305900[0x14];

    local_28[0x15] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,CONCAT44(uVar4,DAT_140303758)

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

    *(float *)(param_2 + 0x28) = (float)(iVar1 * 0x14 + -0x174) * DAT_140303354;

    *(undefined4 *)(param_2 + 0x2c) = 0x40000000;

  }

  return;

}




