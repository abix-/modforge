// Address: 0x1401889f0
// Ghidra name: FUN_1401889f0
// ============ 0x1401889f0 FUN_1401889f0 (size=505) ============


undefined1 FUN_1401889f0(uint *param_1)



{

  uint uVar1;

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  undefined2 uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  longlong lVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  longlong lVar10;

  ulonglong uVar11;

  longlong lVar12;

  longlong lVar13;

  undefined1 local_res8;

  uint local_res10;

  ulonglong local_58;

  

  uVar1 = *param_1;

  local_res8 = 1;

  uVar8 = (ulonglong)uVar1 * 4;

  lVar10 = *(longlong *)(param_1 + 0x1c);

  lVar7 = *(longlong *)(param_1 + 0x22);

  uVar5 = *(ulonglong *)(param_1 + 0xc);

  if ((longlong)(*(longlong *)(param_1 + 6) - 1U) <= (longlong)*(ulonglong *)(param_1 + 0xc)) {

    uVar5 = *(longlong *)(param_1 + 6) - 1U;

  }

  uVar11 = *(longlong *)(param_1 + 0x1a) - lVar10;

  if (uVar11 < ((longlong)(uVar5 + 7 + (ulonglong)((uint)((longlong)(uVar5 + 7) >> 0x3f) & 7)) >> 3)

               * uVar8) {

    auVar2._8_8_ = 0;

    auVar2._0_8_ = uVar8;

    auVar3._8_8_ = 0;

    auVar3._0_8_ = uVar11;

    uVar5 = uVar11 / uVar8;

    if (uVar8 - 4 < SUB168(auVar3 % auVar2,0)) {

      uVar5 = uVar5 + (ulonglong)(SUB164(auVar3 % auVar2,0) & 3) * 2;

    }

    local_res8 = 0;

  }

  for (; 0 < (longlong)uVar5; uVar5 = uVar5 - uVar8) {

    local_58 = (ulonglong)uVar1;

    uVar8 = 8;

    if (uVar5 < 8) {

      uVar8 = uVar5;

    }

    uVar11 = 0;

    local_res10 = 0;

    if (uVar1 != 0) {

      lVar12 = lVar7 * 2;

      do {

        uVar6 = 0;

        uVar9 = 0;

        uVar4 = *(undefined2 *)((ulonglong)uVar1 * -2 + *(longlong *)(param_1 + 0x1e) + lVar12);

        lVar13 = lVar12;

        if (uVar8 != 0) {

          do {

            if ((uVar9 & 1) == 0) {

              uVar6 = (ulonglong)*(byte *)(lVar10 + *(longlong *)(param_1 + 0x18));

              lVar10 = lVar10 + 1;

            }

            else {

              uVar6 = uVar6 >> 4;

            }

            uVar4 = FUN_140188d80(*(longlong *)(param_1 + 0x10) + uVar11,uVar4,

                                  uVar6 & 0xffffffffffffff0f);

            uVar9 = uVar9 + 1;

            *(undefined2 *)(lVar13 + *(longlong *)(param_1 + 0x1e)) = uVar4;

            lVar13 = lVar13 + local_58 * 2;

          } while (uVar9 < uVar8);

          uVar11 = (ulonglong)local_res10;

        }

        local_res10 = (int)uVar11 + 1;

        uVar11 = (ulonglong)local_res10;

        lVar12 = lVar12 + 2;

      } while (local_res10 < uVar1);

    }

    *(ulonglong *)(param_1 + 0xc) = *(longlong *)(param_1 + 0xc) - uVar8;

    lVar7 = lVar7 + uVar1 * uVar8;

  }

  *(longlong *)(param_1 + 0x1c) = lVar10;

  *(longlong *)(param_1 + 0x22) = lVar7;

  return local_res8;

}




