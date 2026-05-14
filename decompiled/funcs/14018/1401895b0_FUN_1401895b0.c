// Address: 0x1401895b0
// Ghidra name: FUN_1401895b0
// ============ 0x1401895b0 FUN_1401895b0 (size=290) ============


undefined8 FUN_1401895b0(uint *param_1)



{

  uint uVar1;

  longlong lVar2;

  ulonglong uVar3;

  undefined2 uVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  ushort uVar7;

  longlong lVar8;

  ulonglong uVar9;

  longlong lVar10;

  uint uVar11;

  

  lVar2 = *(longlong *)(param_1 + 0x10);

  uVar1 = *param_1;

  uVar9 = *(ulonglong *)(param_1 + 0x1c);

  uVar7 = 0;

  uVar3 = *(ulonglong *)(param_1 + 0x1a);

  lVar10 = *(longlong *)(param_1 + 0xc);

  if (*(longlong *)(param_1 + 6) + -2 <= *(longlong *)(param_1 + 0xc)) {

    lVar10 = *(longlong *)(param_1 + 6) + -2;

  }

  lVar8 = *(longlong *)(param_1 + 0x22);

  do {

    if (lVar10 < 1) {

      uVar5 = 1;

LAB_1401896a4:

      *(longlong *)(param_1 + 0x22) = lVar8;

      return uVar5;

    }

    uVar6 = 0;

    if (uVar1 != 0) {

      do {

        if ((uVar7 & 0x4000) == 0) {

          if (uVar3 <= uVar9) {

            lVar8 = lVar8 - uVar6;

            uVar5 = 0;

            goto LAB_1401896a4;

          }

          uVar7 = *(byte *)(*(longlong *)(param_1 + 0x18) + uVar9) | 0x4000;

          uVar9 = uVar9 + 1;

        }

        else {

          uVar7 = uVar7 << 4;

        }

        uVar4 = FUN_140189a90(lVar2 + uVar6 * 6,

                              (int)*(short *)(*(longlong *)(param_1 + 0x1e) +

                                             (lVar8 - (ulonglong)uVar1) * 2),

                              (int)*(short *)(*(longlong *)(param_1 + 0x1e) +

                                             (lVar8 - (ulonglong)(uVar1 * 2)) * 2),(byte)uVar7 >> 4)

        ;

        uVar11 = (int)uVar6 + 1;

        uVar6 = (ulonglong)uVar11;

        *(undefined2 *)(*(longlong *)(param_1 + 0x1e) + lVar8 * 2) = uVar4;

        lVar8 = lVar8 + 1;

      } while (uVar11 < uVar1);

    }

    *(longlong *)(param_1 + 0xc) = *(longlong *)(param_1 + 0xc) + -1;

    lVar10 = lVar10 + -1;

  } while( true );

}




