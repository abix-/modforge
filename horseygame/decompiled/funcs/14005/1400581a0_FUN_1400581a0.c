// Address: 0x1400581a0
// Ghidra name: FUN_1400581a0
// ============ 0x1400581a0 FUN_1400581a0 (size=715) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400581a0(longlong param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  ulonglong uVar5;

  undefined4 uVar6;

  char cVar7;

  char *pcVar8;

  int iVar9;

  int iVar10;

  char acStackY_2c8 [568];

  undefined *puStackY_90;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  ulonglong uStack_40;

  

  lVar1 = *(longlong *)(DAT_1403fb0d8 + 0x288);

  if (*(longlong *)(DAT_1403fb0d8 + 0x280) == lVar1) {

    return;

  }

  iVar10 = *(int *)(lVar1 + -0x20) + *(int *)(lVar1 + -0x1c) + *(int *)(lVar1 + -0x18);

  iVar9 = *(int *)(lVar1 + -0x14) / 10;

  if (*(char *)(param_1 + 0x2da) != '\0') {

    iVar10 = *(int *)(&DAT_1403d4b10 + (longlong)*(int *)(param_1 + 0x2cc) * 0xc) + 10;

    iVar9 = *(int *)(&DAT_1403d4b14 + (longlong)*(int *)(param_1 + 0x2cc) * 0xc) + 10;

  }

  pcVar8 = (char *)(param_1 + 0x2d8);

  cVar7 = *(int *)(&DAT_1403d4b10 + (longlong)*(int *)(param_1 + 0x2cc) * 0xc) <= iVar10;

  *pcVar8 = cVar7;

  *(bool *)(param_1 + 0x2d9) =

       *(int *)(&DAT_1403d4b14 + (longlong)*(int *)(param_1 + 0x2cc) * 0xc) <= iVar9;

  uVar6 = DAT_14039ca44;

  uVar5 = _UNK_140304088;

  uVar4 = _DAT_140304080;

  uVar3 = _UNK_1403033e8;

  uVar2 = _DAT_1403033e0;

  do {

    if (pcVar8[(longlong)(acStackY_2c8 + -param_1)] == '\0') {

      if (cVar7 != '\0') {

        uStack_50 = 0;

        local_48 = uVar4;

        uStack_40 = uVar5;

        local_58 = (ulonglong)CONCAT14(s_Check_140305778[4],s_Check_140305778._0_4_);

        puStackY_90 = (undefined *)0x14005839d;

        FUN_140040ca0(&local_58,100,0,uVar6);

        if (0xf < uStack_40) {

          if ((0xfff < uStack_40 + 1) && (0x1f < (local_58 - *(longlong *)(local_58 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

            puStackY_90 = &UNK_140058453;

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          goto LAB_1400583d2;

        }

      }

    }

    else if (cVar7 == '\0') {

      uStack_50 = 0;

      local_48 = uVar2;

      uStack_40 = uVar3;

      local_58 = (ulonglong)

                 CONCAT16(s_Uncheck_140305770[6],

                          CONCAT24(s_Uncheck_140305770._4_2_,s_Uncheck_140305770._0_4_));

      puStackY_90 = (undefined *)0x140058314;

      FUN_140040ca0(&local_58,100,0,uVar6);

      if (0xf < uStack_40) {

        if ((0xfff < uStack_40 + 1) && (0x1f < (local_58 - *(longlong *)(local_58 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          puStackY_90 = &UNK_14005846c;

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

LAB_1400583d2:

        puStackY_90 = (undefined *)0x1400583d7;

        FUN_1402c7088();

      }

    }

    pcVar8 = pcVar8 + 1;

    if (1 < (longlong)(pcVar8 + (-0x2d8 - param_1))) {

      if (*(char *)(param_1 + 0x2d8) == '\0') {

        return;

      }

      if (*(char *)(param_1 + 0x2d9) == '\0') {

        return;

      }

      *(undefined4 *)(param_1 + 0x254) = 1;

      *(undefined4 *)(param_1 + 0x250) = 0;

      return;

    }

    cVar7 = *pcVar8;

  } while( true );

}




