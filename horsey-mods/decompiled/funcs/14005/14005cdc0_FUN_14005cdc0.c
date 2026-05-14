// Address: 0x14005cdc0
// Ghidra name: FUN_14005cdc0
// ============ 0x14005cdc0 FUN_14005cdc0 (size=392) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14005cdc0(longlong param_1,char param_2)



{

  undefined4 uVar1;

  ulonglong *puVar2;

  longlong lVar3;

  undefined8 *puVar4;

  ulonglong in_stack_ffffffffffffffa8;

  ulonglong local_48;

  ulonglong uStack_40;

  ulonglong local_38;

  ulonglong uStack_30;

  longlong local_28 [3];

  ulonglong uStack_10;

  

  if (param_2 == '\0') {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_140040fe0();

  }

  local_28[1] = 0;

  local_28[2] = _DAT_140305680;

  uStack_10 = _UNK_140305688;

  local_28[0] = 0x62617247;

  lVar3 = (longlong)*(int *)(param_1 + 0xc) * 0x58;

  puVar4 = (undefined8 *)(&DAT_1403d4e48 + lVar3);

  if (0xf < *(ulonglong *)(&DAT_1403d4e60 + lVar3)) {

    puVar4 = (undefined8 *)*puVar4;

  }

  puVar2 = (ulonglong *)FUN_140027810(local_28,puVar4,*(undefined8 *)(&DAT_1403d4e58 + lVar3));

  local_48 = *puVar2;

  uStack_40 = puVar2[1];

  local_38 = puVar2[2];

  uStack_30 = puVar2[3];

  puVar2[2] = 0;

  puVar2[3] = 0xf;

  *(undefined1 *)puVar2 = 0;

  FUN_140040ca0(&local_48,100,uVar1,DAT_14039ca44,in_stack_ffffffffffffffa8 & 0xffffffffffffff00);

  if (0xf < uStack_30) {

    if (0xfff < uStack_30 + 1) {

      if (0x1f < (local_48 - *(longlong *)(local_48 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  local_38 = _DAT_14039caa0;

  uStack_30 = _UNK_14039caa8;

  local_48 = local_48 & 0xffffffffffffff00;

  if (0xf < uStack_10) {

    if (0xfff < uStack_10 + 1) {

      if (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  return;

}




