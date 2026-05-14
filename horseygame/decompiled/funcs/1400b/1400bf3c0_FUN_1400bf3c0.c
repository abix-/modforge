// Address: 0x1400bf3c0
// Ghidra name: FUN_1400bf3c0
// ============ 0x1400bf3c0 FUN_1400bf3c0 (size=623) ============


ulonglong FUN_1400bf3c0(longlong *param_1,longlong *param_2,ulonglong param_3)



{

  code *pcVar1;

  longlong lVar2;

  longlong lVar3;

  uint uVar4;

  ulonglong uVar5;

  longlong lVar6;

  longlong lVar7;

  ulonglong uVar8;

  uint *puVar9;

  uint *puVar10;

  uint *puVar11;

  uint *puVar12;

  ulonglong uVar13;

  byte local_18 [16];

  

  lVar2 = *param_1;

  uVar13 = (*param_2 - lVar2 >> 2) * 0x20 + param_2[1];

  if (param_3 != 0) {

    if (0x7fffffffffffffffU - param_1[3] < param_3) {

      FUN_1400bf7d0();

      pcVar1 = (code *)swi(3);

      uVar13 = (*pcVar1)();

      return uVar13;

    }

    lVar7 = param_1[1];

    uVar5 = param_3 + 0x1f + param_1[3] >> 5;

    uVar4 = 0;

    local_18[0] = 0;

    local_18[1] = 0;

    local_18[2] = 0;

    local_18[3] = 0;

    uVar8 = lVar7 - lVar2 >> 2;

    if (uVar5 < uVar8) {

      param_1[1] = lVar2 + uVar5 * 4;

    }

    else if (uVar8 < uVar5) {

      if ((ulonglong)(param_1[2] - lVar2 >> 2) < uVar5) {

        FUN_1400be8f0(param_1,uVar5,local_18);

      }

      else {

        lVar6 = uVar5 - uVar8;

        local_18[4] = 0;

        local_18[5] = 0;

        local_18[6] = 0;

        local_18[7] = 0;

        lVar2 = 0;

        do {

          lVar3 = lVar2 + 1;

          if (local_18[lVar2] != local_18[lVar2 + 4]) {

            uVar4 = -(uint)(local_18[lVar2] < local_18[lVar2 + 4]) | 1;

            break;

          }

          lVar2 = lVar3;

        } while (lVar3 != 4);

        if ((uVar4 == 0) || (lVar6 != 0)) {

          FUN_1402f94c0(lVar7,0,lVar6 * 4);

          lVar7 = lVar7 + lVar6 * 4;

        }

        param_1[1] = lVar7;

      }

    }

    uVar5 = param_1[3];

    if (uVar5 == 0) {

      param_1[3] = param_3;

    }

    else {

      lVar2 = *param_1;

      if (((longlong)uVar5 < 0) && (uVar5 != 0)) {

        lVar7 = -((~uVar5 >> 5) * 4 + 4);

      }

      else {

        lVar7 = (uVar5 >> 5) * 4;

      }

      uVar8 = (ulonglong)((uint)uVar5 & 0x1f);

      uVar5 = uVar5 + param_3;

      param_1[3] = uVar5;

      if (((longlong)uVar5 < 0) && (uVar5 != 0)) {

        lVar6 = -((~uVar5 >> 5) * 4 + 4);

      }

      else {

        lVar6 = (uVar5 >> 5) * 4;

      }

      uVar5 = (ulonglong)((uint)uVar5 & 0x1f);

      if (((longlong)uVar13 < 0) && (uVar13 != 0)) {

        lVar3 = -((~uVar13 >> 5) * 4 + 4);

      }

      else {

        lVar3 = (uVar13 >> 5) * 4;

      }

      puVar9 = (uint *)(lVar2 + lVar7);

      puVar11 = (uint *)(lVar2 + lVar6);

      while (((uint *)(lVar2 + lVar3) != puVar9 || ((uVar13 & 0x1f) != uVar8))) {

        puVar10 = puVar9 + -1;

        if (uVar8 == 0) {

          uVar8 = 0x1f;

        }

        else {

          uVar8 = uVar8 - 1;

          puVar10 = puVar9;

        }

        puVar12 = puVar11 + -1;

        if (uVar5 == 0) {

          uVar5 = 0x1f;

        }

        else {

          uVar5 = uVar5 - 1;

          puVar12 = puVar11;

        }

        puVar9 = puVar10;

        puVar11 = puVar12;

        if ((*puVar10 & 1 << ((byte)uVar8 & 0x1f)) == 0) {

          *puVar12 = *puVar12 & ~(1 << ((uint)uVar5 & 0x1f));

        }

        else {

          *puVar12 = *puVar12 | 1 << ((uint)uVar5 & 0x1f);

        }

      }

    }

  }

  return uVar13;

}




