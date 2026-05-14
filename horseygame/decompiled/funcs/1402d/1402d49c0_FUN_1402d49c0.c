// Address: 0x1402d49c0
// Ghidra name: FUN_1402d49c0
// ============ 0x1402d49c0 FUN_1402d49c0 (size=701) ============


undefined4 FUN_1402d49c0(longlong param_1)



{

  ushort uVar1;

  int *piVar2;

  char cVar3;

  short sVar4;

  int iVar5;

  byte bVar6;

  ushort *puVar7;

  longlong lVar8;

  

  lVar8 = *(longlong *)(param_1 + 8);

  if (*(longlong *)(param_1 + 0x460) == 0) {

    *(undefined1 *)(lVar8 + 0x30) = 1;

    *(undefined4 *)(lVar8 + 0x2c) = 0x16;

  }

  else {

    puVar7 = *(ushort **)(param_1 + 0x10);

    if (puVar7 != (ushort *)0x0) {

      iVar5 = *(int *)(param_1 + 0x468) + 1;

      *(int *)(param_1 + 0x468) = iVar5;

      do {

        if (iVar5 == 2) {

          return *(undefined4 *)(param_1 + 0x20);

        }

        *(undefined4 *)(param_1 + 0x48) = 0;

        *(undefined1 *)(param_1 + 0x24) = 0;

        uVar1 = *puVar7;

        while( true ) {

          puVar7 = puVar7 + 1;

          *(ushort **)(param_1 + 0x10) = puVar7;

          *(ushort *)(param_1 + 0x3a) = uVar1;

          if ((uVar1 == 0) || (*(int *)(param_1 + 0x20) < 0)) break;

          bVar6 = 0;

          if ((ushort)(uVar1 - 0x20) < 0x5b) {

            bVar6 = (&DAT_140389051)[(ulonglong)(uVar1 - 0x20 & 0x7f) * 2];

          }

          bVar6 = (&DAT_140389050)

                  [(ulonglong)((uint)*(byte *)(param_1 + 0x24) + (uint)bVar6 * 8 & 0x7f) * 2];

          *(byte *)(param_1 + 0x24) = bVar6;

          if (7 < bVar6) {

            lVar8 = *(longlong *)(param_1 + 8);

            *(undefined1 *)(lVar8 + 0x30) = 1;

            *(undefined4 *)(lVar8 + 0x2c) = 0x16;

            lVar8 = *(longlong *)(param_1 + 8);

            goto LAB_1402d4a1b;

          }

          if (bVar6 == 0) {

            *(undefined1 *)(param_1 + 0x4c) = 1;

            if ((((*(uint *)(*(longlong *)(param_1 + 0x460) + 0x14) >> 0xc & 1) == 0) ||

                (*(longlong *)(*(longlong *)(param_1 + 0x460) + 8) != 0)) &&

               (sVar4 = FUN_1402f0614(uVar1,*(undefined8 *)(param_1 + 0x460)), sVar4 == -1)) {

              *(undefined4 *)(param_1 + 0x20) = 0xffffffff;

            }

            else {

              *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;

            }

          }

          else if (bVar6 == 1) {

            *(undefined8 *)(param_1 + 0x28) = 0;

            *(undefined1 *)(param_1 + 0x38) = 0;

            *(undefined4 *)(param_1 + 0x30) = 0xffffffff;

            *(undefined4 *)(param_1 + 0x34) = 0;

            *(undefined1 *)(param_1 + 0x4c) = 0;

          }

          else if (bVar6 == 2) {

            if (uVar1 == 0x20) {

              *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 2;

            }

            else if (uVar1 == 0x23) {

              *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x20;

            }

            else if (uVar1 == 0x2b) {

              *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 1;

            }

            else if (uVar1 == 0x2d) {

              *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 4;

            }

            else if (uVar1 == 0x30) {

              *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 8;

            }

          }

          else {

            if (bVar6 == 3) {

              if (uVar1 == 0x2a) {

                piVar2 = *(int **)(param_1 + 0x18);

                *(int **)(param_1 + 0x18) = piVar2 + 2;

                iVar5 = *piVar2;

                *(int *)(param_1 + 0x2c) = iVar5;

                if (iVar5 < 0) {

                  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 4;

                  *(int *)(param_1 + 0x2c) = -iVar5;

                }

LAB_1402d4b64:

                cVar3 = '\x01';

              }

              else {

                lVar8 = param_1 + 0x2c;

LAB_1402d4b0d:

                cVar3 = FUN_1402d3ed4(param_1,lVar8);

              }

            }

            else {

              if (bVar6 == 4) {

                *(undefined4 *)(param_1 + 0x30) = 0;

                goto LAB_1402d4c10;

              }

              if (bVar6 == 5) {

                if (uVar1 == 0x2a) {

                  piVar2 = *(int **)(param_1 + 0x18);

                  *(int **)(param_1 + 0x18) = piVar2 + 2;

                  iVar5 = *piVar2;

                  *(int *)(param_1 + 0x30) = iVar5;

                  if (iVar5 < 0) {

                    *(undefined4 *)(param_1 + 0x30) = 0xffffffff;

                  }

                  goto LAB_1402d4b64;

                }

                lVar8 = param_1 + 0x30;

                goto LAB_1402d4b0d;

              }

              if (bVar6 == 6) {

                cVar3 = FUN_1402d5254(param_1);

              }

              else {

                if (bVar6 != 7) {

                  return 0xffffffff;

                }

                cVar3 = FUN_1402d5f5c(param_1);

              }

            }

            if (cVar3 == '\0') {

              return 0xffffffff;

            }

          }

LAB_1402d4c10:

          puVar7 = *(ushort **)(param_1 + 0x10);

          uVar1 = *puVar7;

        }

        *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;

        iVar5 = *(int *)(param_1 + 0x468);

      } while( true );

    }

    *(undefined1 *)(lVar8 + 0x30) = 1;

    *(undefined4 *)(lVar8 + 0x2c) = 0x16;

    lVar8 = *(longlong *)(param_1 + 8);

  }

LAB_1402d4a1b:

  FUN_1402cd39c(0,0,0,0,0,lVar8);

  return 0xffffffff;

}




