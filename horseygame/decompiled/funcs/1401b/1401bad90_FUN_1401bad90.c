// Address: 0x1401bad90
// Ghidra name: FUN_1401bad90
// ============ 0x1401bad90 FUN_1401bad90 (size=424) ============


longlong FUN_1401bad90(longlong param_1,uint param_2,uint param_3,uint param_4,uint param_5,

                      undefined4 *param_6)



{

  char cVar1;

  longlong lVar2;

  uint uVar3;

  undefined4 uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  uint uVar9;

  ulonglong uVar10;

  ulonglong uVar4;

  

  uVar8 = 0;

  lVar2 = FUN_1401841f0((ulonglong)*(uint *)(param_1 + 0x5a0) << 2);

  uVar10 = (ulonglong)param_5;

  uVar3 = 0;

  uVar4 = uVar8;

  uVar6 = uVar8;

  uVar7 = uVar8;

  if (*(int *)(param_1 + 0x5a0) != 0) {

    do {

      uVar6 = uVar4;

      if ((((param_2 >> ((uint)uVar7 & 0x1f) & 1) != 0) &&

          (uVar3 = *(uint *)(param_1 + 0x5a4 + uVar7 * 8),

          ((param_3 | param_4) & uVar3) == (param_3 | param_4))) && (((uint)uVar10 & uVar3) == 0)) {

        cVar1 = FUN_1401b54c0(uVar7,lVar2,uVar4);

        if (cVar1 != '\0') {

          uVar6 = (ulonglong)((int)uVar4 + 1);

          *(int *)(lVar2 + uVar4 * 4) = (int)uVar7;

        }

      }

      uVar3 = *(uint *)(param_1 + 0x5a0);

      uVar9 = (int)uVar7 + 1;

      uVar7 = (ulonglong)uVar9;

      uVar4 = uVar6;

    } while (uVar9 < uVar3);

  }

  uVar9 = 0;

  uVar4 = uVar8;

  uVar7 = uVar6;

  if (uVar3 != 0) {

    do {

      uVar6 = uVar7;

      if ((((param_2 >> ((uint)uVar4 & 0x1f) & 1) != 0) &&

          (uVar3 = *(uint *)(param_1 + 0x5a4 + uVar4 * 8), (uVar3 & param_3) == param_3)) &&

         ((uVar3 & (param_4 | (uint)uVar10)) == 0)) {

        cVar1 = FUN_1401b54c0(uVar4,lVar2,uVar7);

        if (cVar1 != '\0') {

          uVar6 = (ulonglong)((int)uVar7 + 1);

          *(int *)(lVar2 + uVar7 * 4) = (int)uVar4;

        }

      }

      uVar9 = *(uint *)(param_1 + 0x5a0);

      uVar3 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar3;

      uVar7 = uVar6;

    } while (uVar3 < uVar9);

  }

  uVar5 = (undefined4)uVar6;

  uVar4 = uVar8;

  if (uVar9 != 0) {

    do {

      uVar7 = uVar6;

      if (((param_2 >> ((uint)uVar4 & 0x1f) & 1) != 0) &&

         (uVar3 = param_3 | param_4 | (uint)uVar10,

         (*(uint *)(param_1 + 0x5a4 + uVar4 * 8) & uVar3) == uVar3)) {

        cVar1 = FUN_1401b54c0(uVar4,lVar2,uVar6);

        if (cVar1 != '\0') {

          uVar7 = (ulonglong)((int)uVar6 + 1);

          *(int *)(lVar2 + uVar6 * 4) = (int)uVar4;

        }

      }

      uVar5 = (undefined4)uVar7;

      uVar3 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar3;

      uVar6 = uVar7;

    } while (uVar3 < *(uint *)(param_1 + 0x5a0));

    if (*(uint *)(param_1 + 0x5a0) != 0) {

      do {

        uVar3 = (uint)uVar8;

        uVar6 = uVar7;

        if (((((param_2 >> (uVar3 & 0x1f) & 1) != 0) &&

             (uVar9 = *(uint *)(param_1 + 0x5a4 + uVar8 * 8), (uVar9 & param_3) == param_3)) &&

            ((param_4 & uVar9) == 0)) && ((uVar9 & (uint)uVar10) == (uint)uVar10)) {

          cVar1 = FUN_1401b54c0(uVar8,lVar2,uVar7);

          if (cVar1 != '\0') {

            uVar6 = (ulonglong)((int)uVar7 + 1);

            *(uint *)(lVar2 + uVar7 * 4) = uVar3;

          }

        }

        uVar5 = (undefined4)uVar6;

        uVar8 = (ulonglong)(uVar3 + 1);

        uVar7 = uVar6;

      } while (uVar3 + 1 < *(uint *)(param_1 + 0x5a0));

    }

  }

  *param_6 = uVar5;

  return lVar2;

}




