// Address: 0x140065710
// Ghidra name: FUN_140065710
// ============ 0x140065710 FUN_140065710 (size=879) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140065710(longlong param_1,char param_2)



{

  longlong lVar1;

  bool bVar2;

  bool bVar3;

  bool bVar4;

  undefined4 uVar5;

  undefined *puVar6;

  size_t sVar7;

  int iVar8;

  undefined **ppuVar9;

  char *pcVar10;

  longlong *plVar11;

  ulonglong uVar12;

  uint uVar13;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar14;

  longlong local_38;

  ulonglong uStack_30;

  undefined8 local_28;

  ulonglong uStack_20;

  

  if (*(char *)(param_1 + 0x2f8) == '\0') {

    if ((param_2 == '\0') && (*(char *)(param_1 + 0x325) != '\0')) {

      local_28 = _DAT_1403040a0;

      uStack_20 = _UNK_1403040a8;

      local_38 = s_Any_luck__140307d90._0_8_;

      uStack_30 = (ulonglong)(byte)s_Any_luck__140307d90[8];

      FUN_1400d0c80(DAT_140303758,*(undefined8 *)(param_1 + 0x148),&local_38,0,DAT_140303758);

      if (0xf < uStack_20) {

        if ((0xfff < uStack_20 + 1) && (0x1f < (local_38 - *(longlong *)(local_38 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    else {

      *(undefined1 *)(param_1 + 0x324) = 1;

      uVar5 = DAT_140303758;

      uVar13 = 0;

      ppuVar9 = &PTR_s_These_horses_are_useless___1403d6270;

      do {

        uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

        pcVar10 = *ppuVar9;

        if (pcVar10 == (char *)0x0) {

          pcVar10 = (char *)(param_1 + 0x2d8);

          if (0xf < *(ulonglong *)(param_1 + 0x2f0)) {

            pcVar10 = *(char **)pcVar10;

          }

          local_38 = 0;

          uStack_30 = 0;

          local_28 = 0;

          uStack_20 = 0;

          sVar7 = strlen(pcVar10);

          FUN_140027e30(&local_38,pcVar10,sVar7);

          in_stack_ffffffffffffffb8 = CONCAT44(uVar14,uVar5);

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                        in_stack_ffffffffffffffb8);

          if (0xf < uStack_20) {

            if ((0xfff < uStack_20 + 1) && (0x1f < (local_38 - *(longlong *)(local_38 + -8)) - 8U))

            {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

LAB_140065a26:

            FUN_1402c7088();

          }

        }

        else {

          local_38 = 0;

          uStack_30 = 0;

          local_28 = 0;

          uStack_20 = 0;

          sVar7 = strlen(pcVar10);

          FUN_140027e30(&local_38,pcVar10,sVar7);

          in_stack_ffffffffffffffb8 = CONCAT44(uVar14,uVar5);

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                        in_stack_ffffffffffffffb8);

          if (0xf < uStack_20) {

            if ((0xfff < uStack_20 + 1) && (0x1f < (local_38 - *(longlong *)(local_38 + -8)) - 8U))

            {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            goto LAB_140065a26;

          }

        }

        uVar13 = uVar13 + 1;

        ppuVar9 = ppuVar9 + 1;

      } while (uVar13 < 10);

    }

  }

  else {

    bVar4 = false;

    bVar3 = false;

    bVar2 = false;

    iVar8 = 0;

    plVar11 = *(longlong **)(param_1 + 0x130);

    uVar12 = *(longlong *)(param_1 + 0x138) - (longlong)plVar11 >> 3;

    if (uVar12 != 0) {

      do {

        lVar1 = *plVar11;

        if ((lVar1 != *(longlong *)(param_1 + 0x148)) &&

           (bVar2 = bVar3, *(char *)(lVar1 + 0x204) == '\0')) {

          bVar3 = true;

          bVar2 = true;

        }

        if (*(int *)(param_1 + 800) == *(int *)(lVar1 + 0x1f8)) {

          bVar4 = true;

        }

        iVar8 = iVar8 + 1;

        plVar11 = plVar11 + 1;

      } while ((ulonglong)(longlong)iVar8 < uVar12);

      if ((bVar2) || (bVar4)) {

        plVar11 = (longlong *)(param_1 + 0x300);

        if (0xf < *(ulonglong *)(param_1 + 0x318)) {

          plVar11 = (longlong *)*plVar11;

        }

        puVar6 = &DAT_140307d70;

        if (bVar4) {

          puVar6 = &DAT_140307d6c;

        }

        FUN_1400d1c40(param_1,*(undefined8 *)(param_1 + 0x148),"%s sure %s fast!",plVar11,puVar6);

        return;

      }

    }

    plVar11 = (longlong *)(param_1 + 0x300);

    if (0xf < *(ulonglong *)(param_1 + 0x318)) {

      plVar11 = (longlong *)*plVar11;

    }

    FUN_1400d1c40(param_1,*(undefined8 *)(param_1 + 0x148),"I sure do miss %s",plVar11);

  }

  return;

}




