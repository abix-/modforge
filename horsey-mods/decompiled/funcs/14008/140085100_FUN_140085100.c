// Address: 0x140085100
// Ghidra name: FUN_140085100
// ============ 0x140085100 FUN_140085100 (size=1583) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140085100(undefined4 *param_1,undefined8 *param_2,undefined4 param_3,int param_4)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  ulonglong *puVar5;

  undefined8 uVar6;

  longlong lVar7;

  longlong lVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  undefined8 *puVar11;

  longlong lVar12;

  longlong lVar13;

  byte *pbVar14;

  int iVar15;

  uint uVar16;

  ulonglong uVar17;

  ulonglong uVar18;

  byte local_res18 [8];

  int local_res20;

  byte local_c8;

  undefined1 local_c7;

  undefined1 local_c6 [6];

  longlong local_c0;

  undefined8 local_b8;

  longlong lStack_b0;

  longlong local_a8;

  ulonglong uStack_a0;

  ulonglong local_98;

  ulonglong uStack_90;

  ulonglong local_88;

  ulonglong uStack_80;

  longlong local_78;

  

  local_res20 = param_4;

  FUN_140087710();

  FUN_1402f94c0(param_1 + 4,0,0x11800);

  *param_1 = param_3;

  iVar2 = FUN_140072ca0(param_3);

  iVar3 = FUN_140072cc0(*param_1);

  if (DAT_1403f3357 != '\0') {

    lStack_b0 = 0;

    local_a8 = _DAT_140304080;

    uStack_a0 = _UNK_140304088;

    local_b8 = (ulonglong)CONCAT14(DAT_14030af28,DAT_14030af24);

    puVar11 = param_2;

    if (0xf < (ulonglong)param_2[3]) {

      puVar11 = (undefined8 *)*param_2;

    }

    puVar5 = (ulonglong *)FUN_140027810(&local_b8,puVar11);

    local_98 = *puVar5;

    uStack_90 = puVar5[1];

    local_88 = puVar5[2];

    uStack_80 = puVar5[3];

    puVar5[2] = 0;

    puVar5[3] = 0xf;

    *(undefined1 *)puVar5 = 0;

    puVar5 = DAT_1403f3370;

    if (DAT_1403f3370 == DAT_1403f3378) {

      FUN_140087c70(&DAT_1403f3368,DAT_1403f3370);

      uVar18 = uStack_80;

    }

    else {

      *DAT_1403f3370 = local_98;

      puVar5[1] = uStack_90;

      puVar5[2] = local_88;

      puVar5[3] = uStack_80;

      local_98 = local_98 & 0xffffffffffffff00;

      DAT_1403f3370 = DAT_1403f3370 + 4;

      uVar18 = 0xf;

    }

    if (0xf < uVar18) {

      if ((0xfff < uVar18 + 1) && (0x1f < (local_98 - *(longlong *)(local_98 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    if (0xf < uStack_a0) {

      if ((0xfff < uStack_a0 + 1) && (0x1f < (local_b8 - *(longlong *)(local_b8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  uVar6 = FUN_1400c4e00();

  uVar6 = FUN_1400748b0(&local_b8,uVar6);

  FUN_1400753f0(0,uVar6);

  if (0xf < uStack_a0) {

    if ((0xfff < uStack_a0 + 1) && (0x1f < (local_b8 - *(longlong *)(local_b8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  FUN_140075e30(&local_c7);

  FUN_140075e30(local_c6);

  FUN_140075e30(local_res18);

  FUN_140075e30(&local_c8);

  param_1[3] = (uint)local_res18[0];

  iVar4 = FUN_140075da0();

  uVar18 = (ulonglong)iVar4;

  local_98 = 0;

  uStack_90 = 0;

  local_88 = 0;

  if (iVar4 == 0) {

    lVar7 = 0;

  }

  else {

    if (0x1fffffffffffffff < uVar18) {

                    /* WARNING: Subroutine does not return */

      FUN_14002f0d0();

    }

    lVar7 = FUN_1400285e0(uVar18 * 8);

    lVar8 = uVar18 * 8 + lVar7;

    local_98 = lVar7;

    local_88 = lVar8;

    FUN_1402f94c0(lVar7,0,uVar18 * 8);

    uStack_90 = lVar8;

  }

  uVar18 = uStack_90;

  iVar4 = FUN_140075da0();

  local_b8 = 0;

  lStack_b0 = 0;

  local_78 = 0;

  local_a8 = 0;

  if (iVar4 == 0) {

    lVar8 = 0;

  }

  else {

    if (0x5555555555555555 < (ulonglong)(longlong)iVar4) {

                    /* WARNING: Subroutine does not return */

      FUN_14002f0d0();

    }

    lVar12 = (longlong)iVar4 * 3;

    lVar8 = FUN_1400285e0(lVar12);

    lVar1 = lVar12 + lVar8;

    local_b8 = lVar8;

    local_a8 = lVar1;

    local_78 = lVar1;

    FUN_1402f94c0(lVar8,0,lVar12);

    lStack_b0 = lVar1;

  }

  uVar9 = 0;

  uVar17 = (longlong)(uVar18 - lVar7) >> 3;

  uVar10 = uVar9;

  local_c0 = lStack_b0;

  if (uVar17 != 0) {

    do {

      lVar1 = lVar7 + uVar9 * 8;

      FUN_140075e30(lVar1);

      FUN_140075e30(lVar1 + 1);

      FUN_140075e30(lVar1 + 2);

      FUN_140075e30(lVar1 + 3);

      FUN_140075e30(lVar1 + 4);

      FUN_140075de0(lVar1 + 5);

      FUN_140075de0(lVar1 + 6);

      FUN_140075e30(lVar1 + 7);

      uVar16 = (int)uVar10 + 1;

      uVar9 = (ulonglong)(int)uVar16;

      uVar10 = (ulonglong)uVar16;

    } while (uVar9 < uVar17);

  }

  uVar9 = 0;

  lVar1 = local_c0 - lVar8 >> 0x3f;

  lVar12 = (local_c0 - lVar8) / 3 + lVar1;

  uVar10 = uVar9;

  if (lVar12 != lVar1) {

    do {

      lVar13 = lVar8 + uVar9 * 3;

      FUN_140075e30(lVar13);

      FUN_140075e30(lVar13 + 1);

      FUN_140075de0(lVar13 + 2);

      uVar16 = (int)uVar10 + 1;

      uVar9 = (ulonglong)(int)uVar16;

      uVar10 = (ulonglong)uVar16;

    } while (uVar9 < (ulonglong)(lVar12 - lVar1));

  }

  iVar4 = 0;

  FUN_1402f94c0(param_1 + 4);

  if (uVar17 != 0) {

    pbVar14 = (byte *)(lVar7 + 2);

    iVar15 = iVar4;

    do {

      uVar10 = (ulonglong)pbVar14[-2];

      lVar13 = uVar10 * 0x118;

      param_1[uVar10 * 0x46 + 4] = (float)pbVar14[-1] / (float)iVar2;

      param_1[uVar10 * 0x46 + 6] = (float)*pbVar14 / (float)iVar3;

      param_1[uVar10 * 0x46 + 5] = (float)((uint)pbVar14[-1] + (uint)pbVar14[1]) / (float)iVar2;

      param_1[uVar10 * 0x46 + 7] = (float)((uint)*pbVar14 + (uint)pbVar14[2]) / (float)iVar3;

      *(byte *)(param_1 + uVar10 * 0x46 + 9) = pbVar14[1];

      *(byte *)(lVar13 + 0x25 + (longlong)param_1) = pbVar14[2];

      *(byte *)(lVar13 + 0x26 + (longlong)param_1) = pbVar14[3];

      *(byte *)(lVar13 + 0x27 + (longlong)param_1) = pbVar14[4];

      param_1[uVar10 * 0x46 + 8] = (uint)pbVar14[5] + local_res20;

      iVar15 = iVar15 + 1;

      pbVar14 = pbVar14 + 8;

    } while ((ulonglong)(longlong)iVar15 < uVar17);

  }

  if (lVar12 != lVar1) {

    pbVar14 = (byte *)(lVar8 + 1);

    do {

      *(byte *)((longlong)param_1 + (ulonglong)*pbVar14 + 0x28 + (ulonglong)pbVar14[-1] * 0x118) =

           pbVar14[1];

      iVar4 = iVar4 + 1;

      pbVar14 = pbVar14 + 3;

    } while ((ulonglong)(longlong)iVar4 < (ulonglong)(lVar12 - lVar1));

  }

  param_1[0x8c8] = (uint)local_c8 + local_res20;

  param_1[1] = (int)*(char *)((longlong)param_1 + 0x4855);

  if (lVar8 != 0) {

    if ((0xfff < (ulonglong)(((local_78 - lVar8) / 3) * 3)) &&

       (0x1f < (lVar8 - *(longlong *)(lVar8 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  if (lVar7 != 0) {

    uVar18 = uVar18 - lVar7 & 0xfffffffffffffff8;

    lVar8 = lVar7;

    if (0xfff < uVar18) {

      uVar18 = uVar18 + 0x27;

      lVar8 = *(longlong *)(lVar7 + -8);

      if (0x1f < (lVar7 - lVar8) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088(lVar8,uVar18);

  }

  FUN_140027900(param_2);

  return;

}




