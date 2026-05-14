// Address: 0x140107190
// Ghidra name: FUN_140107190
// ============ 0x140107190 FUN_140107190 (size=871) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_140107190(longlong param_1,int param_2)



{

  ulonglong uVar1;

  longlong lVar2;

  float fVar3;

  uint uVar4;

  int *piVar5;

  ulonglong uVar6;

  int *piVar7;

  ulonglong uVar8;

  int *piVar9;

  int *piVar10;

  int iVar11;

  longlong lVar12;

  longlong lVar13;

  int *local_68;

  int *piStack_60;

  int *local_58;

  

  uVar4 = _DAT_14039cab0;

  fVar3 = DAT_140313a24;

  local_68 = (int *)0x0;

  piStack_60 = (int *)0x0;

  piVar7 = (int *)0x0;

  local_58 = (int *)0x0;

  iVar11 = 0;

  lVar12 = *(longlong *)(param_1 + 0xb8);

  piVar10 = (int *)0x0;

  piVar5 = (int *)0x0;

  if (*(longlong *)(param_1 + 0xc0) - lVar12 >> 3 != 0) {

    lVar13 = 0;

    do {

      lVar12 = *(longlong *)(lVar12 + lVar13);

      if (((((*(int *)(lVar12 + 8) == 0) && (iVar11 != *(int *)(param_1 + 0x350))) &&

           (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x438) + (longlong)param_2 * 8),

           (float)((uint)(*(float *)(lVar12 + 0x28) - *(float *)(lVar2 + 0xc)) & uVar4) < fVar3)) &&

          (((float)((uint)(*(float *)(lVar12 + 0x2c) - *(float *)(lVar2 + 0x10)) & uVar4) < fVar3 &&

           (lVar2 = *(longlong *)(lVar12 + 0x80), *(char *)(lVar12 + 0x11) == '\0')))) &&

         ((lVar2 != 0 &&

          ((*(int *)(lVar2 + 0x1fc) < *(int *)(lVar2 + 0x200) && (*(int *)(lVar12 + 0x70) != 0xd))))

         )) {

        if (piVar10 == piVar7) {

          lVar12 = (longlong)piVar10 - (longlong)piVar5 >> 2;

          if (lVar12 == 0x3fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

            FUN_14002f0d0();

          }

          uVar1 = lVar12 + 1;

          uVar8 = (longlong)piVar7 - (longlong)piVar5 >> 2;

          if (0x3fffffffffffffff - (uVar8 >> 1) < uVar8) {

            uVar6 = 0x3fffffffffffffff;

          }

          else {

            uVar8 = (uVar8 >> 1) + uVar8;

            uVar6 = uVar1;

            if (uVar1 <= uVar8) {

              uVar6 = uVar8;

            }

            if (0x3fffffffffffffff < uVar6) {

                    /* WARNING: Subroutine does not return */

              FUN_140024090();

            }

          }

          piVar5 = (int *)FUN_1400285e0(uVar6 * 4);

          piVar5[lVar12] = iVar11;

          piVar7 = piVar5;

          piVar9 = local_68;

          if (piVar10 != piStack_60) {

            FUN_1402f8e20(piVar5,local_68,(longlong)piVar10 - (longlong)local_68);

            piVar7 = piVar5 + lVar12 + 1;

            piVar9 = piVar10;

          }

          FUN_1402f8e20(piVar7,piVar9);

          if (local_68 != (int *)0x0) {

            if ((0xfff < ((longlong)local_58 - (longlong)local_68 & 0xfffffffffffffffcU)) &&

               (0x1f < (ulonglong)((longlong)local_68 + (-8 - *(longlong *)(local_68 + -2))))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          piVar10 = piVar5 + uVar1;

          piVar7 = piVar5 + uVar6;

          local_68 = piVar5;

          piStack_60 = piVar10;

          local_58 = piVar7;

        }

        else {

          *piVar10 = iVar11;

          piVar10 = piStack_60 + 1;

          piVar7 = local_58;

          piVar5 = local_68;

          piStack_60 = piVar10;

        }

      }

      iVar11 = iVar11 + 1;

      lVar13 = lVar13 + 8;

      lVar12 = *(longlong *)(param_1 + 0xb8);

    } while ((ulonglong)(longlong)iVar11 < (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar12 >> 3))

    ;

  }

  if (piVar5 == piVar10) {

    lVar12 = 0;

  }

  else {

    iVar11 = FUN_1400c6580((longlong)piVar10 - (longlong)piVar5 >> 2 & 0xffffffff);

    lVar13 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + (longlong)local_68[iVar11] * 8);

    lVar12 = *(longlong *)(lVar13 + 0x80);

    *(undefined2 *)(lVar12 + 0x205) = 0;

    FUN_1400b8f90(lVar12,0);

    *(undefined8 *)(lVar13 + 0x80) = 0;

    *(undefined1 *)(lVar13 + 0x11) = 1;

    piVar7 = local_58;

    piVar5 = local_68;

  }

  if (piVar5 != (int *)0x0) {

    piVar10 = piVar5;

    if ((0xfff < ((longlong)piVar7 - (longlong)piVar5 & 0xfffffffffffffffcU)) &&

       (piVar10 = *(int **)(piVar5 + -2),

       0x1f < (ulonglong)((longlong)piVar5 + (-8 - (longlong)piVar10)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(piVar10);

  }

  return lVar12;

}




