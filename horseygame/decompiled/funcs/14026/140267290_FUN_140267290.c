// Address: 0x140267290
// Ghidra name: FUN_140267290
// ============ 0x140267290 FUN_140267290 (size=751) ============


undefined8 FUN_140267290(ushort *param_1,longlong param_2,int param_3,int *param_4)



{

  int iVar1;

  ushort *puVar2;

  byte bVar3;

  byte bVar4;

  undefined1 uVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  uint uVar8;

  int iVar9;

  uint uVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  

  param_3 = param_3 - *param_4;

  puVar2 = (ushort *)(param_2 + *param_4);

  if ((0xf < param_3) && (uVar10 = (uint)*puVar2, (int)uVar10 <= param_3)) {

    uVar8 = (uint)puVar2[2];

    if (uVar8 < uVar10) {

      if (uVar8 != 0) {

        bVar3 = *(byte *)((ulonglong)uVar8 + (longlong)puVar2);

        *(byte *)(param_1 + 4) = bVar3;

        if (uVar10 < uVar8 + 1 + (uint)bVar3) {

          return 0;

        }

        uVar6 = FUN_1401841f0((uint)bVar3);

        *(undefined8 *)(param_1 + 0x28) = uVar6;

        FUN_1402f8e20(uVar6,(ulonglong)(uVar8 + 1) + (longlong)puVar2,(char)param_1[4]);

      }

      uVar8 = (uint)puVar2[3];

      if (uVar8 < uVar10) {

        uVar12 = 0;

        if (uVar8 != 0) {

          bVar3 = *(byte *)((ulonglong)uVar8 + (longlong)puVar2);

          if (uVar10 < uVar8 + 1 + (uint)bVar3) {

            return 0;

          }

          uVar7 = uVar12;

          if (bVar3 != 0) {

            do {

              uVar11 = uVar7 + 1;

              bVar4 = *(byte *)(uVar8 + uVar7 + 1 + (longlong)puVar2);

              uVar7 = (ulonglong)(bVar4 >> 5);

              *(uint *)(param_1 + uVar7 * 2 + 6) =

                   *(uint *)(param_1 + uVar7 * 2 + 6) | 1 << (bVar4 & 0x1f);

              uVar7 = uVar11;

            } while ((longlong)uVar11 < (longlong)(ulonglong)(uint)bVar3);

          }

        }

        uVar8 = (uint)puVar2[4];

        if (uVar8 < uVar10) {

          if (uVar8 != 0) {

            bVar3 = *(byte *)((ulonglong)uVar8 + (longlong)puVar2);

            if (uVar10 < uVar8 + 1 + (uint)bVar3) {

              return 0;

            }

            uVar7 = uVar12;

            if (bVar3 != 0) {

              do {

                bVar4 = *(byte *)((longlong)puVar2 + uVar7 + (ulonglong)uVar8 + 1);

                uVar7 = uVar7 + 1;

                uVar11 = (ulonglong)(bVar4 >> 5);

                *(uint *)(param_1 + uVar11 * 2 + 0x16) =

                     *(uint *)(param_1 + uVar11 * 2 + 0x16) | 1 << (bVar4 & 0x1f);

              } while ((longlong)uVar7 < (longlong)(ulonglong)(uint)bVar3);

            }

          }

          uVar8 = (uint)puVar2[5];

          if (uVar8 < uVar10) {

            if (uVar8 != 0) {

              uVar5 = *(undefined1 *)((ulonglong)uVar8 + (longlong)puVar2);

              *(undefined1 *)((longlong)param_1 + 9) = uVar5;

              uVar6 = FUN_1401841a0(uVar5,8);

              iVar9 = uVar8 + 1;

              *(undefined8 *)(param_1 + 0x2c) = uVar6;

              uVar7 = uVar12;

              if (*(char *)((longlong)param_1 + 9) != '\0') {

                do {

                  iVar1 = iVar9 + 2;

                  if ((int)uVar10 <= iVar1) {

                    return 0;

                  }

                  bVar3 = *(byte *)((longlong)iVar9 + (longlong)puVar2);

                  iVar9 = (uint)bVar3 + iVar1;

                  if ((int)uVar10 < iVar9) {

                    return 0;

                  }

                  uVar6 = FUN_1401841a0(bVar3 + 1,1);

                  *(undefined8 *)(uVar12 + *(longlong *)(param_1 + 0x2c)) = uVar6;

                  FUN_1402f8e20(*(undefined8 *)(*(longlong *)(param_1 + 0x2c) + uVar12),

                                (longlong)iVar1 + (longlong)puVar2,bVar3);

                  uVar8 = (int)uVar7 + 1;

                  uVar12 = uVar12 + 8;

                  uVar7 = (ulonglong)uVar8;

                } while ((int)uVar8 < (int)(uint)*(byte *)((longlong)param_1 + 9));

              }

            }

            uVar8 = (uint)puVar2[6];

            if (uVar8 < uVar10) {

              if (uVar8 != 0) {

                bVar3 = *(byte *)((ulonglong)uVar8 + (longlong)puVar2);

                *(byte *)(param_1 + 5) = bVar3;

                if (uVar10 < (uint)bVar3 * 0x10 + 1 + uVar8) {

                  return 0;

                }

                uVar6 = FUN_1401841a0(bVar3,0x10);

                *(undefined8 *)(param_1 + 0x30) = uVar6;

                FUN_1402f8e20(uVar6,(ulonglong)(uVar8 + 1) + (longlong)puVar2,

                              (ulonglong)(byte)param_1[5] << 4);

              }

              if ((1 < *param_1) || (param_1[1] != 0)) {

                uVar8 = (uint)puVar2[7];

                if (uVar10 <= uVar8) {

                  return 0;

                }

                if (uVar8 != 0) {

                  bVar3 = *(byte *)((ulonglong)uVar8 + (longlong)puVar2);

                  *(byte *)((longlong)param_1 + 0xb) = bVar3;

                  if (uVar10 < uVar8 + 1 + (uint)bVar3) {

                    return 0;

                  }

                  uVar6 = FUN_1401841f0((uint)bVar3);

                  *(undefined8 *)(param_1 + 0x34) = uVar6;

                  FUN_1402f8e20(uVar6,(ulonglong)(uVar8 + 1) + (longlong)puVar2,

                                *(undefined1 *)((longlong)param_1 + 0xb));

                }

              }

              *param_4 = *param_4 + uVar10;

              return 1;

            }

          }

        }

      }

    }

  }

  return 0;

}




