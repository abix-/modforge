// Address: 0x1400a6970
// Ghidra name: FUN_1400a6970
// ============ 0x1400a6970 FUN_1400a6970 (size=716) ============


void FUN_1400a6970(longlong *param_1,ulonglong param_2)



{

  ulonglong uVar1;

  undefined4 *puVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  longlong lVar8;

  undefined4 *puVar9;

  undefined4 *puVar10;

  longlong lVar11;

  undefined8 *puVar12;

  longlong lVar13;

  

  if (0xfe823ca508735 < param_2) {

                    /* WARNING: Subroutine does not return */

    FUN_14002f0d0();

  }

  lVar11 = (param_1[1] - *param_1) / 0x1018;

  uVar1 = (param_1[2] - *param_1) / 0x1018;

  if (0xfe823ca508735 - (uVar1 >> 1) < uVar1) {

    uVar7 = 0xfe823ca508735;

  }

  else {

    uVar1 = (uVar1 >> 1) + uVar1;

    uVar7 = param_2;

    if ((param_2 <= uVar1) && (uVar7 = uVar1, 0xfe823ca508735 < uVar1)) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

  }

  lVar8 = FUN_1400285e0(uVar7 * 0x1018);

  FUN_1400a6c40(lVar11 * 0x1018 + lVar8,param_2 - lVar11,param_1);

  puVar2 = (undefined4 *)param_1[1];

  if ((undefined4 *)*param_1 != puVar2) {

    puVar9 = (undefined4 *)*param_1;

    puVar12 = (undefined8 *)(lVar8 + 0x20);

    do {

      *(undefined4 *)(puVar12 + -4) = *puVar9;

      *(undefined4 *)((longlong)puVar12 + -0x1c) = puVar9[1];

      puVar12[-3] = 0;

      puVar12[-2] = 0;

      puVar12[-1] = 0;

      *puVar12 = 0;

      uVar3 = puVar9[3];

      uVar4 = puVar9[4];

      uVar5 = puVar9[5];

      *(undefined4 *)(puVar12 + -3) = puVar9[2];

      *(undefined4 *)((longlong)puVar12 + -0x14) = uVar3;

      *(undefined4 *)(puVar12 + -2) = uVar4;

      *(undefined4 *)((longlong)puVar12 + -0xc) = uVar5;

      uVar3 = puVar9[7];

      uVar4 = puVar9[8];

      uVar5 = puVar9[9];

      *(undefined4 *)(puVar12 + -1) = puVar9[6];

      *(undefined4 *)((longlong)puVar12 + -4) = uVar3;

      *(undefined4 *)puVar12 = uVar4;

      *(undefined4 *)((longlong)puVar12 + 4) = uVar5;

      *(undefined8 *)(puVar9 + 6) = 0;

      *(undefined8 *)(puVar9 + 8) = 0xf;

      *(undefined1 *)(puVar9 + 2) = 0;

      FUN_1402f8e20(puVar12 + 1,puVar9 + 10,0xf00);

      puVar10 = puVar9 + 0x406;

      uVar6 = *(undefined8 *)(puVar9 + 0x3cc);

      puVar12[0x1e1] = *(undefined8 *)(puVar9 + 0x3ca);

      puVar12[0x1e2] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 0x3d0);

      puVar12[0x1e3] = *(undefined8 *)(puVar9 + 0x3ce);

      puVar12[0x1e4] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 0x3d4);

      puVar12[0x1e5] = *(undefined8 *)(puVar9 + 0x3d2);

      puVar12[0x1e6] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 0x3d8);

      puVar12[0x1e7] = *(undefined8 *)(puVar9 + 0x3d6);

      puVar12[0x1e8] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 0x3dc);

      puVar12[0x1e9] = *(undefined8 *)(puVar9 + 0x3da);

      puVar12[0x1ea] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 0x3e0);

      puVar12[0x1eb] = *(undefined8 *)(puVar9 + 0x3de);

      puVar12[0x1ec] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 0x3e4);

      puVar12[0x1ed] = *(undefined8 *)(puVar9 + 0x3e2);

      puVar12[0x1ee] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 1000);

      puVar12[0x1ef] = *(undefined8 *)(puVar9 + 0x3e6);

      puVar12[0x1f0] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 0x3ec);

      puVar12[0x1f1] = *(undefined8 *)(puVar9 + 0x3ea);

      puVar12[0x1f2] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 0x3f0);

      puVar12[499] = *(undefined8 *)(puVar9 + 0x3ee);

      puVar12[500] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 0x3f4);

      puVar12[0x1f5] = *(undefined8 *)(puVar9 + 0x3f2);

      puVar12[0x1f6] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 0x3f8);

      puVar12[0x1f7] = *(undefined8 *)(puVar9 + 0x3f6);

      puVar12[0x1f8] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 0x3fc);

      puVar12[0x1f9] = *(undefined8 *)(puVar9 + 0x3fa);

      puVar12[0x1fa] = uVar6;

      uVar6 = *(undefined8 *)(puVar9 + 0x400);

      puVar12[0x1fb] = *(undefined8 *)(puVar9 + 0x3fe);

      puVar12[0x1fc] = uVar6;

      uVar3 = puVar9[0x403];

      uVar4 = puVar9[0x404];

      uVar5 = puVar9[0x405];

      *(undefined4 *)(puVar12 + 0x1fd) = puVar9[0x402];

      *(undefined4 *)((longlong)puVar12 + 0xfec) = uVar3;

      *(undefined4 *)(puVar12 + 0x1fe) = uVar4;

      *(undefined4 *)((longlong)puVar12 + 0xff4) = uVar5;

      puVar9 = puVar10;

      puVar12 = puVar12 + 0x203;

    } while (puVar10 != puVar2);

  }

  lVar11 = *param_1;

  if (lVar11 != 0) {

    lVar13 = param_1[1];

    for (; lVar11 != lVar13; lVar11 = lVar11 + 0x1018) {

      FUN_140027900(lVar11 + 8);

    }

    lVar11 = *param_1;

    lVar13 = lVar11;

    if ((0xfff < (ulonglong)(((param_1[2] - lVar11) / 0x1018) * 0x1018)) &&

       (lVar13 = *(longlong *)(lVar11 + -8), 0x1f < (lVar11 - lVar13) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar13);

  }

  *param_1 = lVar8;

  param_1[1] = param_2 * 0x1018 + lVar8;

  param_1[2] = uVar7 * 0x1018 + lVar8;

  return;

}




