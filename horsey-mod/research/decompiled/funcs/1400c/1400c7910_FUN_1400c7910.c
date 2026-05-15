// Address: 0x1400c7910
// Ghidra name: FUN_1400c7910
// ============ 0x1400c7910 FUN_1400c7910 (size=566) ============


void FUN_1400c7910(int param_1,longlong *param_2)



{

  ulonglong uVar1;

  undefined4 uVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  longlong lVar5;

  longlong lVar6;

  undefined8 uVar7;

  undefined8 uVar8;

  ulonglong uVar9;

  longlong lVar10;

  longlong *plVar11;

  undefined8 *puVar12;

  longlong *plVar13;

  undefined8 *puVar14;

  longlong *plVar15;

  ulonglong uVar16;

  longlong lVar17;

  longlong local_38 [3];

  ulonglong local_20;

  

  if (param_1 == -1) {

    FUN_1400c4320("No Record!");

    return;

  }

  lVar17 = (longlong)param_1 * 0x88;

  plVar11 = (longlong *)(DAT_1403f34e0 + lVar17);

  if (plVar11 != param_2) {

    plVar13 = param_2;

    if (0xf < (ulonglong)param_2[3]) {

      plVar13 = (longlong *)*param_2;

    }

    uVar3 = param_2[2];

    uVar4 = plVar11[3];

    if (uVar4 < uVar3) {

      if (0x7fffffffffffffff < uVar3) {

                    /* WARNING: Subroutine does not return */

        FUN_140024130();

      }

      uVar9 = uVar3 | 0xf;

      uVar16 = 0x7fffffffffffffff;

      if (((uVar9 < 0x8000000000000000) && (uVar4 <= 0x7fffffffffffffff - (uVar4 >> 1))) &&

         (uVar1 = uVar4 + (uVar4 >> 1), uVar16 = uVar9, uVar9 < uVar1)) {

        uVar16 = uVar1;

      }

      lVar6 = FUN_1400285e0(uVar16 + 1);

      plVar11[2] = uVar3;

      plVar11[3] = uVar16;

      FUN_1402f8e20(lVar6,plVar13);

      *(undefined1 *)(lVar6 + uVar3) = 0;

      if (0xf < uVar4) {

        lVar5 = *plVar11;

        lVar10 = lVar5;

        if ((0xfff < uVar4 + 1) &&

           (lVar10 = *(longlong *)(lVar5 + -8), 0x1f < (lVar5 - lVar10) - 8U)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088(lVar10);

      }

      *plVar11 = lVar6;

    }

    else {

      plVar15 = plVar11;

      if (0xf < uVar4) {

        plVar15 = (longlong *)*plVar11;

      }

      plVar11[2] = uVar3;

      FUN_1402f8e20(plVar15,plVar13,uVar3);

      *(undefined1 *)((longlong)plVar15 + uVar3) = 0;

    }

  }

  puVar12 = (undefined8 *)(DAT_1403f34e0 + lVar17);

  puVar14 = puVar12;

  if (0xf < (ulonglong)puVar12[3]) {

    puVar14 = (undefined8 *)*puVar12;

  }

  uVar2 = *(undefined4 *)((longlong)puVar12 + 0x44);

  uVar7 = FUN_140086330();

  uVar8 = FUN_140086310(uVar2);

  uVar7 = FUN_14008d760(local_38,"%s%s%s",uVar8,puVar14,uVar7);

  FUN_1400c5580(DAT_1403f34e0 + 0x20 + lVar17,uVar7);

  if (0xf < local_20) {

    if ((0xfff < local_20 + 1) && (0x1f < (local_38[0] - *(longlong *)(local_38[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return;

}




