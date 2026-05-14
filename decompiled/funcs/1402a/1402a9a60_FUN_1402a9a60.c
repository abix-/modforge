// Address: 0x1402a9a60
// Ghidra name: FUN_1402a9a60
// ============ 0x1402a9a60 FUN_1402a9a60 (size=593) ============


void FUN_1402a9a60(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  ushort uVar7;

  uint uVar8;

  ulonglong uVar9;

  uint uVar10;

  uint uVar11;

  ulonglong uVar12;

  uint uVar13;

  uint uVar14;

  uint *puVar15;

  

  uVar12 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar9 = (ulonglong)*(int *)(param_1 + 0x38);

  uVar1 = *(uint *)(param_1 + 0x78);

  uVar4 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar12;

  uVar5 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar9;

  uVar6 = uVar4 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar15 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar12 + -1;

      if ((int)uVar9 != 0) {

        uVar14 = uVar1 & 0x3f0;

        uVar12 = uVar5 >> 1;

        do {

          uVar11 = *puVar15;

          uVar8 = (int)uVar9 - 1;

          uVar9 = (ulonglong)uVar8;

          uVar13 = uVar11 & 0xff;

          uVar2 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar6 >> 0x10) +

                            (uVar12 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          uVar10 = uVar2 >> 0x10 & 0xff;

          uVar3 = uVar11 >> 0x10 & 0xff;

          uVar11 = uVar11 >> 8 & 0xff;

          if (uVar14 < 0x81) {

            if (uVar14 == 0x80) {

LAB_1402a9b73:

              uVar3 = uVar3 + uVar10;

              if (0xff < uVar3) {

                uVar3 = 0xff;

              }

              uVar11 = uVar11 + (uVar2 >> 8 & 0xff);

              if (0xff < uVar11) {

                uVar11 = 0xff;

              }

              uVar13 = uVar13 + (uVar2 & 0xff);

              if (0xff < uVar13) {

                uVar13 = 0xff;

              }

            }

            else if ((uVar14 == 0x10) || (uVar14 == 0x20)) {

              uVar11 = uVar2 >> 8 & 0xff;

              uVar13 = uVar2 & 0xff;

              uVar3 = uVar10;

            }

            else if (uVar14 == 0x40) goto LAB_1402a9b73;

          }

          else {

            if (uVar14 == 0x100) {

              uVar7 = (short)uVar10 * (short)uVar3 + 1;

              uVar7 = (uVar7 >> 8) + uVar7;

            }

            else {

              if (uVar14 != 0x200) goto LAB_1402a9c36;

              uVar7 = (short)uVar10 * (short)uVar3 + 1;

              uVar7 = (uVar7 >> 8) + uVar7;

            }

            uVar3 = (uint)(uVar7 >> 8);

            uVar7 = ((ushort)(uVar2 >> 8) & 0xff) * (short)uVar11 + 1;

            uVar11 = (uint)((ushort)((uVar7 >> 8) + uVar7) >> 8);

            uVar7 = ((ushort)uVar2 & 0xff) * (short)uVar13 + 1;

            uVar13 = (uint)((ushort)((uVar7 >> 8) + uVar7) >> 8);

          }

LAB_1402a9c36:

          uVar12 = uVar12 + uVar5;

          *puVar15 = (uVar3 << 8 | uVar11) << 8 | uVar13;

          puVar15 = puVar15 + 1;

        } while (uVar8 != 0);

        uVar9 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar6 = uVar6 + uVar4;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar12 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




