// Address: 0x1400c8220
// Ghidra name: FUN_1400c8220
// ============ 0x1400c8220 FUN_1400c8220 (size=831) ============


void FUN_1400c8220(longlong *param_1,ulonglong param_2)



{

  ulonglong uVar1;

  undefined8 *puVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  ulonglong uVar9;

  longlong lVar10;

  longlong lVar11;

  undefined8 *puVar12;

  longlong lVar13;

  undefined8 *puVar14;

  undefined8 *puVar15;

  

  if (0x1e1e1e1e1e1e1e1 < param_2) {

                    /* WARNING: Subroutine does not return */

    FUN_14002f0d0();

  }

  lVar11 = (param_1[1] - *param_1) / 0x88;

  uVar1 = (param_1[2] - *param_1) / 0x88;

  if (0x1e1e1e1e1e1e1e1 - (uVar1 >> 1) < uVar1) {

    uVar9 = 0x1e1e1e1e1e1e1e1;

  }

  else {

    uVar1 = (uVar1 >> 1) + uVar1;

    uVar9 = param_2;

    if ((param_2 <= uVar1) && (uVar9 = uVar1, 0x1e1e1e1e1e1e1e1 < uVar1)) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

  }

  lVar10 = FUN_1400285e0(uVar9 * 0x88);

  FUN_1400c8570(lVar11 * 0x88 + lVar10,param_2 - lVar11,param_1);

  puVar2 = (undefined8 *)param_1[1];

  puVar15 = (undefined8 *)*param_1;

  if (puVar15 != puVar2) {

    puVar12 = puVar15 + 0xf;

    puVar14 = (undefined8 *)(lVar10 + 0x38);

    do {

      puVar14[-7] = 0;

      puVar14[-6] = 0;

      puVar14[-5] = 0;

      puVar14[-4] = 0;

      uVar3 = puVar15[1];

      puVar14[-7] = *puVar15;

      puVar14[-6] = uVar3;

      uVar3 = puVar15[3];

      puVar14[-5] = puVar15[2];

      puVar14[-4] = uVar3;

      puVar12[-0xd] = 0;

      puVar12[-0xc] = 0xf;

      *(undefined1 *)puVar15 = 0;

      puVar15 = puVar15 + 0x11;

      puVar14[-3] = 0;

      puVar14[-2] = 0;

      puVar14[-1] = 0;

      *puVar14 = 0;

      uVar6 = *(undefined4 *)((longlong)puVar12 + -0x54);

      uVar7 = *(undefined4 *)(puVar12 + -10);

      uVar8 = *(undefined4 *)((longlong)puVar12 + -0x4c);

      *(undefined4 *)(puVar14 + -3) = *(undefined4 *)(puVar12 + -0xb);

      *(undefined4 *)((longlong)puVar14 + -0x14) = uVar6;

      *(undefined4 *)(puVar14 + -2) = uVar7;

      *(undefined4 *)((longlong)puVar14 + -0xc) = uVar8;

      uVar3 = puVar12[-8];

      puVar14[-1] = puVar12[-9];

      *puVar14 = uVar3;

      puVar12[-9] = 0;

      puVar12[-8] = 0xf;

      *(undefined1 *)(puVar12 + -0xb) = 0;

      *(undefined1 *)(puVar14 + 1) = *(undefined1 *)(puVar12 + -7);

      *(undefined4 *)((longlong)puVar14 + 0xc) = *(undefined4 *)((longlong)puVar12 + -0x34);

      puVar14[2] = puVar12[-6];

      *(undefined4 *)(puVar14 + 3) = *(undefined4 *)(puVar12 + -5);

      *(undefined4 *)((longlong)puVar14 + 0x1c) = *(undefined4 *)((longlong)puVar12 + -0x24);

      *(undefined1 *)(puVar14 + 4) = *(undefined1 *)(puVar12 + -4);

      *(undefined4 *)((longlong)puVar14 + 0x24) = *(undefined4 *)((longlong)puVar12 + -0x1c);

      *(undefined4 *)(puVar14 + 5) = *(undefined4 *)(puVar12 + -3);

      *(undefined4 *)((longlong)puVar14 + 0x2c) = *(undefined4 *)((longlong)puVar12 + -0x14);

      *(undefined4 *)(puVar14 + 6) = *(undefined4 *)(puVar12 + -2);

      *(undefined1 *)((longlong)puVar14 + 0x34) = *(undefined1 *)((longlong)puVar12 + -0xc);

      uVar3 = puVar12[1];

      uVar4 = *puVar12;

      uVar5 = puVar12[-1];

      puVar12[1] = 0;

      *puVar12 = 0;

      puVar12[-1] = 0;

      puVar14[7] = uVar5;

      puVar14[8] = uVar4;

      puVar14[9] = uVar3;

      puVar12 = puVar12 + 0x11;

      puVar14 = puVar14 + 0x11;

    } while (puVar15 != puVar2);

  }

  lVar11 = *param_1;

  if (lVar11 != 0) {

    lVar13 = param_1[1];

    for (; lVar11 != lVar13; lVar11 = lVar11 + 0x88) {

      thunk_FUN_1400308d0(lVar11 + 0x70);

      FUN_140027900(lVar11 + 0x20);

      FUN_140027900(lVar11);

    }

    lVar11 = *param_1;

    lVar13 = lVar11;

    if ((0xfff < (ulonglong)(((param_1[2] - lVar11) / 0x88) * 0x88)) &&

       (lVar13 = *(longlong *)(lVar11 + -8), 0x1f < (lVar11 - lVar13) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar13);

  }

  *param_1 = lVar10;

  param_1[1] = param_2 * 0x88 + lVar10;

  param_1[2] = uVar9 * 0x88 + lVar10;

  return;

}




