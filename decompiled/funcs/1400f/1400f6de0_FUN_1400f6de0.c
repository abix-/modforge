// Address: 0x1400f6de0
// Ghidra name: FUN_1400f6de0
// ============ 0x1400f6de0 FUN_1400f6de0 (size=376) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400f6de0(longlong param_1,longlong param_2,int param_3)



{

  undefined8 *puVar1;

  undefined8 uVar2;

  ulonglong in_stack_ffffffffffffffc8;

  ulonglong uVar3;

  undefined4 uVar4;

  longlong local_28;

  ulonglong uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  if ((param_3 == 3) && (*(int *)(param_2 + 8) == 3)) {

    local_18 = _DAT_1403033f0;

    uStack_10 = _UNK_1403033f8;

    local_28 = s_PutOnShelf_140312878._0_8_;

    uStack_20 = (ulonglong)(ushort)s_PutOnShelf_140312878._8_2_;

    uVar3 = in_stack_ffffffffffffffc8 & 0xffffffffffffff00;

    FUN_140040ca0(&local_28,100,0xffffffce,DAT_14039ca44,uVar3);

    uVar4 = (undefined4)(uVar3 >> 0x20);

    if (0xf < uStack_10) {

      if ((0xfff < uStack_10 + 1) && (0x1f < (local_28 - *(longlong *)(local_28 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    puVar1 = (undefined8 *)FUN_14005e270(*(undefined4 *)(param_2 + 0xc));

    if (0xf < (ulonglong)puVar1[3]) {

      puVar1 = (undefined8 *)*puVar1;

    }

    uVar2 = FUN_14008d760(&local_28,"What a lovely %s!",puVar1);

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),uVar2,0,CONCAT44(uVar4,DAT_140303758));

    if (0xf < uStack_10) {

      if ((0xfff < uStack_10 + 1) && (0x1f < (local_28 - *(longlong *)(local_28 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  return;

}




