// Address: 0x14008d7f0
// Ghidra name: FUN_14008d7f0
// ============ 0x14008d7f0 FUN_14008d7f0 (size=1064) ============


float FUN_14008d7f0(undefined8 *param_1,undefined8 *param_2)



{

  ulonglong uVar1;

  size_t _Size;

  int iVar2;

  longlong *plVar3;

  ulonglong uVar4;

  longlong lVar5;

  undefined8 *puVar6;

  longlong lVar7;

  ulonglong uVar8;

  undefined8 *puVar9;

  size_t sVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  longlong lVar13;

  double dVar14;

  longlong local_res10;

  longlong *local_b8;

  longlong *plStack_b0;

  longlong *local_a8;

  longlong local_a0;

  longlong lStack_98;

  longlong local_90;

  longlong local_88;

  ulonglong local_80;

  longlong *local_78;

  longlong *local_70;

  longlong **local_68;

  longlong **local_60;

  

  puVar9 = param_2;

  if (0xf < (ulonglong)param_2[3]) {

    puVar9 = (undefined8 *)*param_2;

  }

  puVar6 = param_1;

  if (0xf < (ulonglong)param_1[3]) {

    puVar6 = (undefined8 *)*param_1;

  }

  uVar1 = param_2[2];

  _Size = param_1[2];

  if (_Size == uVar1) {

    if (_Size == 0) {

      return DAT_14039ca44;

    }

    iVar2 = memcmp(puVar6,puVar9,_Size);

    if (iVar2 == 0) {

      return DAT_14039ca44;

    }

  }

  else if (_Size == 0) {

    return 0.0;

  }

  if (uVar1 == 0) {

    return 0.0;

  }

  uVar11 = uVar1 + 1;

  local_a0 = 0;

  lStack_98 = 0;

  uVar12 = 0;

  local_88 = 0;

  local_90 = 0;

  if (uVar11 == 0) {

    local_res10 = 0;

  }

  else {

    if (0x1fffffffffffffff < uVar11) {

                    /* WARNING: Subroutine does not return */

      FUN_14002f0d0();

    }

    local_res10 = FUN_1400285e0(uVar11 * 8);

    lVar13 = local_res10 + uVar11 * 8;

    local_a0 = local_res10;

    local_90 = lVar13;

    local_88 = lVar13;

    FUN_1402f94c0(local_res10,0);

    lStack_98 = lVar13;

  }

  lVar13 = lStack_98;

  uVar11 = _Size + 1;

  local_b8 = (longlong *)0x0;

  plStack_b0 = (longlong *)0x0;

  local_a8 = (longlong *)0x0;

  plVar3 = plStack_b0;

  if (uVar11 != 0) {

    if (0xaaaaaaaaaaaaaaa < uVar11) {

                    /* WARNING: Subroutine does not return */

      FUN_14002f0d0();

    }

    plVar3 = (longlong *)FUN_1400285e0(uVar11 * 0x18);

    local_a8 = plVar3 + uVar11 * 3;

    local_60 = &local_b8;

    local_68 = &local_b8;

    local_b8 = plVar3;

    local_78 = plVar3;

    local_70 = plVar3;

    if (uVar11 != 0) {

      uVar4 = lVar13 - local_res10 >> 3;

      plStack_b0 = plVar3;

      local_80 = uVar4;

      do {

        *plVar3 = 0;

        plVar3[1] = 0;

        plVar3[2] = 0;

        if (uVar4 != 0) {

          local_70 = plVar3;

          if (0x1fffffffffffffff < uVar4) {

                    /* WARNING: Subroutine does not return */

            FUN_14002f0d0();

          }

          lVar13 = uVar4 * 8;

          lVar5 = FUN_1400285e0(lVar13);

          *plVar3 = lVar5;

          plVar3[1] = lVar5;

          plVar3[2] = lVar5 + lVar13;

          FUN_1402f8e20(lVar5,local_res10);

          plVar3[1] = lVar5 + lVar13;

          uVar4 = local_80;

        }

        plVar3 = plVar3 + 3;

        uVar11 = uVar11 - 1;

        local_70 = plVar3;

      } while (uVar11 != 0);

    }

  }

  plStack_b0 = plVar3;

  uVar11 = uVar12;

  uVar4 = uVar12;

  if (local_res10 != 0) {

    uVar8 = local_88 - local_res10 & 0xfffffffffffffff8;

    lVar13 = local_res10;

    if (0xfff < uVar8) {

      uVar8 = uVar8 + 0x27;

      lVar13 = *(longlong *)(local_res10 + -8);

      if (0x1f < (local_res10 - lVar13) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088(lVar13,uVar8);

  }

  do {

    **(ulonglong **)(uVar4 + (longlong)local_b8) = uVar11;

    uVar11 = uVar11 + 1;

    uVar4 = uVar4 + 0x18;

  } while (uVar11 <= _Size);

  do {

    *(ulonglong *)(*local_b8 + uVar12 * 8) = uVar12;

    uVar12 = uVar12 + 1;

  } while (uVar12 <= uVar1);

  uVar11 = 1;

  if (_Size != 0) {

    lVar13 = 0x18;

    do {

      uVar12 = 1;

      if (uVar1 != 0) {

        do {

          puVar9 = param_1;

          if (0xf < (ulonglong)param_1[3]) {

            puVar9 = (undefined8 *)*param_1;

          }

          puVar6 = param_2;

          if (0xf < (ulonglong)param_2[3]) {

            puVar6 = (undefined8 *)*param_2;

          }

          if (*(char *)((longlong)puVar9 + (uVar11 - 1)) ==

              *(char *)((longlong)puVar6 + (uVar12 - 1))) {

            *(undefined8 *)(*(longlong *)(lVar13 + (longlong)local_b8) + uVar12 * 8) =

                 *(undefined8 *)

                  (*(longlong *)(lVar13 + -0x18 + (longlong)local_b8) + -8 + uVar12 * 8);

          }

          else {

            local_a0 = *(longlong *)

                        (*(longlong *)(lVar13 + -0x18 + (longlong)local_b8) + uVar12 * 8);

            lStack_98 = *(longlong *)(*(longlong *)(lVar13 + (longlong)local_b8) + -8 + uVar12 * 8);

            local_90 = *(longlong *)

                        (*(longlong *)(lVar13 + -0x18 + (longlong)local_b8) + -8 + uVar12 * 8);

            lVar5 = *(longlong *)(lVar13 + (longlong)local_b8);

            lVar7 = thunk_FUN_1402c63c0(&local_a0,&local_88);

            *(longlong *)(lVar5 + uVar12 * 8) = lVar7 + 1;

          }

          uVar12 = uVar12 + 1;

        } while (uVar12 <= uVar1);

      }

      uVar11 = uVar11 + 1;

      lVar13 = lVar13 + 0x18;

    } while (uVar11 <= _Size);

  }

  sVar10 = _Size;

  if (_Size < uVar1) {

    sVar10 = uVar1;

  }

  dVar14 = DAT_140304b90 -

           (double)((float)*(ulonglong *)(local_b8[_Size * 3] + uVar1 * 8) / (float)sVar10);

  FUN_14008dd80(&local_b8);

  return (float)dVar14;

}




