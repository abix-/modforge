// Address: 0x14007ae10
// Ghidra name: FUN_14007ae10
// ============ 0x14007ae10 FUN_14007ae10 (size=407) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14007ae10(longlong param_1)



{

  longlong lVar1;

  int *piVar2;

  int iVar3;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  if (*(longlong *)(param_1 + 0x138) - (longlong)*(longlong **)(param_1 + 0x130) >> 3 != 0) {

    lVar1 = **(longlong **)(param_1 + 0x130);

    *(longlong *)(param_1 + 0x268) = lVar1;

    *(undefined1 *)(lVar1 + 0x1a) = 1;

    FUN_1400b6820(*(undefined8 *)(param_1 + 0x268),

                  (float)(DAT_14030b680 + DAT_1403eda00) / *(float *)(param_1 + 0x114) +

                  DAT_140303390,DAT_14030562c);

  }

  FUN_1400cd5a0(param_1,1);

  FUN_1400ce540(param_1);

  *(undefined8 *)(param_1 + 0x260) = 0;

  *(undefined8 *)(param_1 + 0x254) = 0;

  *(undefined4 *)(param_1 + 0x250) = 0;

  *(undefined4 *)(param_1 + 0x2ac) = 1000;

  *(undefined8 *)(param_1 + 0x298) = 0;

  *(undefined8 *)(param_1 + 0x2a0) = 0;

  *(undefined4 *)(param_1 + 0x290) = 0;

  piVar2 = (int *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    piVar2 = DAT_1403d9530;

  }

  if (DAT_1403d9540 == 5) {

    iVar3 = *piVar2 + -0x7a697250;

    if (iVar3 == 0) {

      iVar3 = *(byte *)(piVar2 + 1) - 0x65;

    }

    if (iVar3 == 0) {

      *(undefined4 *)(param_1 + 0x274) = 8;

    }

  }

  if (8 < *(int *)(param_1 + 0x274)) {

    uStack_20 = 0;

    local_18 = _DAT_1403033d0;

    uStack_10 = _UNK_1403033d8;

    local_28 = (ulonglong)CONCAT24(DAT_140304258,DAT_140304254);

    FUN_140037710(&local_28);

    if (0xf < uStack_10) {

      if (0xfff < uStack_10 + 1) {

        if (0x1f < (local_28 - *(longlong *)(local_28 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

  }

  return 1;

}




