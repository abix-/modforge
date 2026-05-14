// Address: 0x1402ba3b0
// Ghidra name: FUN_1402ba3b0
// ============ 0x1402ba3b0 FUN_1402ba3b0 (size=616) ============


void FUN_1402ba3b0(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  ushort uVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  ulonglong uVar11;

  uint uVar12;

  uint uVar13;

  uint *puVar14;

  uint uVar15;

  ulonglong uVar16;

  

  uVar11 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar16 = (ulonglong)*(int *)(param_1 + 0x38);

  uVar1 = *(uint *)(param_1 + 0x78);

  uVar4 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar11;

  uVar5 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar16;

  uVar6 = uVar4 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar14 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar11 + -1;

      if ((int)uVar16 != 0) {

        uVar8 = uVar1 & 0x3f0;

        uVar11 = uVar5 >> 1;

        do {

          uVar15 = (int)uVar16 - 1;

          uVar16 = (ulonglong)uVar15;

          uVar2 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar6 >> 0x10) +

                            (uVar11 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          uVar10 = *puVar14;

          uVar12 = uVar10 & 0xff;

          uVar13 = uVar10 >> 0x10 & 0xff;

          uVar3 = uVar10 >> 0x18;

          uVar9 = uVar2 & 0xff;

          uVar10 = uVar10 >> 8 & 0xff;

          if (uVar8 < 0x81) {

            if (uVar8 == 0x80) {

LAB_1402ba4c4:

              uVar12 = uVar12 + uVar9;

              if (0xff < uVar12) {

                uVar12 = 0xff;

              }

              uVar10 = uVar10 + (uVar2 >> 8 & 0xff);

              if (0xff < uVar10) {

                uVar10 = 0xff;

              }

              uVar13 = uVar13 + (uVar2 >> 0x10 & 0xff);

              if (0xff < uVar13) {

                uVar13 = 0xff;

              }

            }

            else if ((uVar8 == 0x10) || (uVar8 == 0x20)) {

              uVar10 = uVar2 >> 8 & 0xff;

              uVar13 = uVar2 >> 0x10 & 0xff;

              uVar3 = 0xff;

              uVar12 = uVar9;

            }

            else if (uVar8 == 0x40) goto LAB_1402ba4c4;

          }

          else {

            if (uVar8 == 0x100) {

              uVar7 = (short)uVar9 * (short)uVar12 + 1;

              uVar7 = (uVar7 >> 8) + uVar7;

            }

            else {

              if (uVar8 != 0x200) goto LAB_1402ba590;

              uVar7 = (short)uVar12 * (short)uVar9 + 1;

              uVar7 = (uVar7 >> 8) + uVar7;

            }

            uVar12 = (uint)(uVar7 >> 8);

            uVar7 = ((ushort)(uVar2 >> 8) & 0xff) * (short)uVar10 + 1;

            uVar10 = (uint)((ushort)((uVar7 >> 8) + uVar7) >> 8);

            uVar7 = ((ushort)(uVar2 >> 0x10) & 0xff) * (short)uVar13 + 1;

            uVar13 = (uint)((ushort)((uVar7 >> 8) + uVar7) >> 8);

          }

LAB_1402ba590:

          uVar11 = uVar11 + uVar5;

          *puVar14 = ((uVar3 << 8 | uVar13) << 8 | uVar10) << 8 | uVar12;

          puVar14 = puVar14 + 1;

        } while (uVar15 != 0);

        uVar16 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar6 = uVar6 + uVar4;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar11 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




