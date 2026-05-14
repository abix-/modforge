// Address: 0x1401d5fd0
// Ghidra name: FUN_1401d5fd0
// ============ 0x1401d5fd0 FUN_1401d5fd0 (size=256) ============


undefined8

FUN_1401d5fd0(int param_1,int param_2,longlong param_3,int param_4,longlong param_5,int param_6)



{

  undefined1 auVar1 [16];

  undefined1 *puVar2;

  ushort uVar3;

  uint uVar4;

  uint uVar5;

  undefined1 (*pauVar7) [16];

  uint uVar8;

  ulonglong uVar9;

  undefined1 (*pauVar10) [16];

  undefined1 auVar11 [16];

  undefined1 auVar12 [16];

  ulonglong uVar6;

  

  uVar4 = (param_1 + 1) / 2;

  pauVar10 = (undefined1 (*) [16])(param_2 * param_4 + param_3);

  pauVar7 = (undefined1 (*) [16])(param_2 * param_6 + param_5);

  uVar5 = (param_2 + 1) / 2;

  uVar6 = (ulonglong)uVar5;

  if (uVar5 != 0) {

    do {

      uVar5 = uVar5 - 1;

      uVar8 = uVar4;

      if (7 < (int)uVar4) {

        uVar8 = uVar4 >> 3;

        uVar9 = (ulonglong)uVar8;

        uVar6 = (ulonglong)(uVar8 * 8);

        uVar8 = uVar4 + uVar8 * -8;

        do {

          auVar1 = *pauVar10;

          pauVar10 = pauVar10 + 1;

          auVar11 = psllw(auVar1,8);

          auVar12._0_2_ = auVar1._0_2_ >> 8;

          auVar12._2_2_ = auVar1._2_2_ >> 8;

          auVar12._4_2_ = auVar1._4_2_ >> 8;

          auVar12._6_2_ = auVar1._6_2_ >> 8;

          auVar12._8_2_ = auVar1._8_2_ >> 8;

          auVar12._10_2_ = auVar1._10_2_ >> 8;

          auVar12._12_2_ = auVar1._12_2_ >> 8;

          auVar12._14_2_ = auVar1._14_2_ >> 8;

          *pauVar7 = auVar12 | auVar11;

          pauVar7 = pauVar7 + 1;

          uVar9 = uVar9 - 1;

        } while (uVar9 != 0);

      }

      for (; uVar8 != 0; uVar8 = uVar8 - 1) {

        puVar2 = *pauVar10;

        pauVar10 = (undefined1 (*) [16])(*pauVar10 + 2);

        uVar3 = *(ushort *)puVar2 >> 8 | *(ushort *)puVar2 << 8;

        uVar6 = (ulonglong)uVar3;

        *(ushort *)*pauVar7 = uVar3;

        pauVar7 = (undefined1 (*) [16])(*pauVar7 + 2);

      }

      pauVar10 = (undefined1 (*) [16])

                 (*pauVar10 +

                 (longlong)(int)((ulonglong)(longlong)(int)(((param_4 + 1) / 2 - uVar4) * 2) >> 1) *

                 2);

      pauVar7 = (undefined1 (*) [16])

                (*pauVar7 +

                (longlong)(int)((ulonglong)(longlong)(int)(((param_6 + 1) / 2 - uVar4) * 2) >> 1) *

                2);

    } while (uVar5 != 0);

  }

  return CONCAT71((int7)(uVar6 >> 8),1);

}




