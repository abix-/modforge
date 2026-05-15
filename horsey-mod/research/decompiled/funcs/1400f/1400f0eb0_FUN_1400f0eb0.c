// Address: 0x1400f0eb0
// Ghidra name: FUN_1400f0eb0
// ============ 0x1400f0eb0 FUN_1400f0eb0 (size=859) ============


uint FUN_1400f0eb0(longlong param_1,uint param_2)



{

  longlong lVar1;

  uint uVar2;

  longlong lVar3;

  uint uVar4;

  uint uVar5;

  longlong lVar6;

  int iVar7;

  ulonglong uVar8;

  short sVar9;

  ushort uVar10;

  int iVar11;

  int iVar12;

  ushort uVar13;

  

  lVar1 = *(longlong *)(param_1 + 8);

  uVar8 = (ulonglong)*(uint *)(param_1 + 0x30);

  sVar9 = (ushort)*(byte *)(uVar8 + lVar1) * 0x100 + (ushort)*(byte *)(uVar8 + 1 + lVar1);

  if (sVar9 == 0) {

    if ((int)param_2 <

        (int)((uint)*(byte *)(uVar8 + 2 + lVar1) * 0x100 + (*(byte *)(uVar8 + 3 + lVar1) - 6))) {

      return (uint)*(byte *)(uVar8 + (longlong)(int)param_2 + 6 + lVar1);

    }

  }

  else if (sVar9 == 6) {

    uVar4 = (uint)*(byte *)(uVar8 + 7 + lVar1) + (uint)*(byte *)(uVar8 + 6 + lVar1) * 0x100;

    if ((uVar4 <= param_2) &&

       (param_2 < (uint)*(byte *)(uVar8 + 9 + lVar1) +

                  (uint)*(byte *)(uVar8 + 8 + lVar1) * 0x100 + uVar4)) {

      lVar3 = (param_2 - uVar4) * 2 + uVar8;

      return (uint)*(byte *)(lVar3 + 10 + lVar1) * 0x100 + (uint)*(byte *)(lVar3 + 0xb + lVar1);

    }

  }

  else if (sVar9 != 2) {

    if (sVar9 == 4) {

      uVar4 = *(uint *)(param_1 + 0x30) + 0xe;

      sVar9 = (ushort)*(byte *)(uVar8 + 10 + lVar1) * 0x100 + (ushort)*(byte *)(uVar8 + 0xb + lVar1)

      ;

      uVar13 = (ushort)((ushort)*(byte *)(uVar8 + 7 + lVar1) +

                       (ushort)*(byte *)(uVar8 + 6 + lVar1) * 0x100) >> 1;

      uVar10 = (ushort)((ushort)*(byte *)(uVar8 + 9 + lVar1) +

                       (ushort)*(byte *)(uVar8 + 8 + lVar1) * 0x100) >> 1;

      if ((int)param_2 < 0x10000) {

        uVar5 = (uint)*(byte *)(uVar8 + 0xd + lVar1) + (uint)*(byte *)(uVar8 + 0xc + lVar1) * 0x100

                & 0xfffffffe;

        lVar3 = (ulonglong)uVar5 + lVar1;

        uVar5 = uVar5 + uVar4;

        if ((int)param_2 <

            (int)((uint)*(byte *)((ulonglong)uVar4 + lVar3) * 0x100 +

                 (uint)*(byte *)((ulonglong)uVar4 + 1 + lVar3))) {

          uVar5 = uVar4;

        }

        uVar5 = uVar5 - 2;

        for (; sVar9 != 0; sVar9 = sVar9 + -1) {

          uVar10 = uVar10 >> 1;

          lVar3 = (ulonglong)((uint)uVar10 + (uint)uVar10) + lVar1;

          uVar2 = (uint)uVar10 + (uint)uVar10 + uVar5;

          if ((int)param_2 <=

              (int)((uint)*(byte *)((ulonglong)uVar5 + 1 + lVar3) +

                   (uint)*(byte *)((ulonglong)uVar5 + lVar3) * 0x100)) {

            uVar2 = uVar5;

          }

          uVar5 = uVar2;

        }

        lVar3 = (ulonglong)((uVar5 - uVar4) + 2 >> 1 & 0xffff) * 2;

        lVar6 = (ulonglong)((uint)uVar13 + (uint)uVar13) + lVar3 + uVar8;

        iVar7 = (uint)*(byte *)(lVar6 + 0x10 + lVar1) * 0x100 +

                (uint)*(byte *)(lVar6 + 0x11 + lVar1);

        if (iVar7 <= (int)param_2) {

          uVar4 = ((uint)uVar13 + (uint)uVar13 * 2) * 2;

          lVar6 = (ulonglong)uVar4 + lVar3 + uVar8;

          uVar10 = (ushort)*(byte *)(lVar6 + 0x11 + lVar1) +

                   (ushort)*(byte *)(lVar6 + 0x10 + lVar1) * 0x100;

          if (uVar10 == 0) {

            lVar3 = (ulonglong)((uint)uVar13 * 4) + lVar3 + uVar8;

            return (uint)(ushort)((ushort)*(byte *)(lVar3 + 0x11 + lVar1) +

                                  (ushort)*(byte *)(lVar3 + 0x10 + lVar1) * 0x100 + (short)param_2);

          }

          lVar3 = (ulonglong)uVar10 + (longlong)(int)((param_2 - iVar7) * 2) + (ulonglong)uVar4 +

                  lVar3 + uVar8;

          return (uint)*(byte *)(lVar3 + 0x11 + lVar1) +

                 (uint)*(byte *)(lVar3 + 0x10 + lVar1) * 0x100;

        }

      }

    }

    else if ((ushort)(sVar9 - 0xcU) < 2) {

      iVar7 = 0;

      iVar11 = (((uint)*(byte *)(uVar8 + 0xd + lVar1) + (uint)*(byte *)(uVar8 + 0xc + lVar1) * 0x100

                ) * 0x100 + (uint)*(byte *)(uVar8 + 0xe + lVar1)) * 0x100 +

               (uint)*(byte *)(uVar8 + 0xf + lVar1);

      if (0 < iVar11) {

        do {

          iVar12 = (iVar11 - iVar7 >> 1) + iVar7;

          lVar3 = (longlong)(iVar12 * 0xc) + uVar8;

          uVar4 = (uint)*(byte *)(lVar3 + 0x11 + lVar1) * 0x10000 +

                  (uint)*(byte *)(lVar3 + 0x12 + lVar1) * 0x100 +

                  (uint)*(byte *)(lVar3 + 0x10 + lVar1) * 0x1000000 +

                  (uint)*(byte *)(lVar3 + 0x13 + lVar1);

          if (uVar4 <= param_2) {

            if (param_2 <=

                (uint)*(byte *)(lVar3 + 0x15 + lVar1) * 0x10000 +

                (uint)*(byte *)(lVar3 + 0x16 + lVar1) * 0x100 +

                (uint)*(byte *)(lVar3 + 0x14 + lVar1) * 0x1000000 +

                (uint)*(byte *)(lVar3 + 0x17 + lVar1)) {

              uVar5 = (uint)*(byte *)(lVar3 + 0x19 + lVar1) * 0x10000 +

                      (uint)*(byte *)(lVar3 + 0x1a + lVar1) * 0x100 +

                      (uint)*(byte *)(lVar3 + 0x18 + lVar1) * 0x1000000 +

                      (uint)*(byte *)(lVar3 + 0x1b + lVar1);

              if (sVar9 != 0xc) {

                return uVar5;

              }

              return param_2 + (uVar5 - uVar4);

            }

            iVar7 = iVar12 + 1;

            iVar12 = iVar11;

          }

          iVar11 = iVar12;

        } while (iVar7 < iVar11);

      }

    }

  }

  return 0;

}




