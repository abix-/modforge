// Address: 0x140068970
// Ghidra name: FUN_140068970
// ============ 0x140068970 FUN_140068970 (size=558) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140068970(longlong param_1,int param_2)



{

  float fVar1;

  int *piVar2;

  undefined8 uVar3;

  float fVar4;

  ulonglong in_stack_ffffffffffffffc8;

  ulonglong uVar5;

  undefined4 uVar6;

  char *local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  if ((*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8) + 0x1dc) ==

       *(int *)(param_1 + 0x120) + -1) && (*(char *)(param_1 + 0x270) != '\0')) {

    *(undefined1 *)(param_1 + 0x270) = 0;

    local_18 = _DAT_140304090;

    uStack_10 = _UNK_140304098;

    local_28 = (char *)0x66664f7265776f50;

    uStack_20 = 0;

    uVar5 = in_stack_ffffffffffffffc8 & 0xffffffffffffff00;

    FUN_140040ca0(&local_28,100,0,DAT_14039ca44,uVar5);

    uVar6 = (undefined4)(uVar5 >> 0x20);

    if (0xf < uStack_10) {

      if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    local_28 = (char *)0x0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    local_28 = (char *)FUN_1400285e0(0x20);

    uVar3 = s_Power_is_off_again_140309ac8._8_8_;

    local_18 = _DAT_140303410;

    uStack_10 = _UNK_140303418;

    *(undefined8 *)local_28 = s_Power_is_off_again_140309ac8._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar3;

    *(undefined2 *)(local_28 + 0x10) = s_Power_is_off_again_140309ac8._16_2_;

    local_28[0x12] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,CONCAT44(uVar6,DAT_140303758)

                 );

    if (0xf < uStack_10) {

      if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    fVar4 = DAT_140309c28;

    if (0.0 < *(float *)(param_1 + 0x268)) {

      fVar4 = DAT_140309c00;

    }

    *(float *)(param_1 + 0x268) = fVar4;

    piVar2 = *(int **)(param_1 + 600);

    fVar1 = (float)piVar2[0x12];

    if (fVar4 <= 0.0) {

      fVar4 = DAT_140309c18;

      if (DAT_140309c18 <= fVar1) {

        fVar4 = fVar1;

      }

    }

    else {

      fVar4 = DAT_140309bd4;

      if (fVar1 <= DAT_140309bd4) {

        fVar4 = fVar1;

      }

    }

    if (*piVar2 != 0) {

      if ((0.0 < fVar4 * fVar4) && ((*(ushort *)(piVar2 + 1) & 2) == 0)) {

        *(ushort *)(piVar2 + 1) = *(ushort *)(piVar2 + 1) | 2;

        piVar2[0x2b] = 0;

      }

      piVar2[0x12] = (int)fVar4;

    }

  }

  return;

}




