// Address: 0x1402d4c80
// Ghidra name: FUN_1402d4c80
// ============ 0x1402d4c80 FUN_1402d4c80 (size=708) ============


undefined4 FUN_1402d4c80(longlong param_1)



{

  ushort uVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  byte bVar5;

  ushort *puVar6;

  longlong lVar7;

  

  lVar7 = *(longlong *)(param_1 + 8);

  if (*(longlong *)(param_1 + 0x460) == 0) {

    *(undefined1 *)(lVar7 + 0x30) = 1;

    *(undefined4 *)(lVar7 + 0x2c) = 0x16;

  }

  else {

    puVar6 = *(ushort **)(param_1 + 0x10);

    if (puVar6 != (ushort *)0x0) {

      iVar4 = *(int *)(param_1 + 0x468) + 1;

      *(int *)(param_1 + 0x468) = iVar4;

      do {

        if (iVar4 == 2) {

          return *(undefined4 *)(param_1 + 0x20);

        }

        *(undefined4 *)(param_1 + 0x48) = 0;

        *(undefined1 *)(param_1 + 0x24) = 0;

        uVar1 = *puVar6;

        while( true ) {

          puVar6 = puVar6 + 1;

          *(ushort **)(param_1 + 0x10) = puVar6;

          *(ushort *)(param_1 + 0x3a) = uVar1;

          if ((uVar1 == 0) || (iVar4 = *(int *)(param_1 + 0x20), iVar4 < 0)) break;

          bVar5 = 0;

          if ((ushort)(uVar1 - 0x20) < 0x5b) {

            bVar5 = (&DAT_140389051)[(ulonglong)(uVar1 - 0x20 & 0x7f) * 2];

          }

          bVar5 = (&DAT_140389050)

                  [(ulonglong)((uint)*(byte *)(param_1 + 0x24) + (uint)bVar5 * 8 & 0x7f) * 2];

          *(byte *)(param_1 + 0x24) = bVar5;

          if (7 < bVar5) {

            lVar7 = *(longlong *)(param_1 + 8);

            *(undefined1 *)(lVar7 + 0x30) = 1;

            *(undefined4 *)(lVar7 + 0x2c) = 0x16;

            lVar7 = *(longlong *)(param_1 + 8);

            goto LAB_1402d4cdb;

          }

          if (bVar5 == 0) {

            *(undefined1 *)(param_1 + 0x4c) = 1;

            lVar7 = *(longlong *)(param_1 + 0x460);

            if (*(longlong *)(lVar7 + 0x10) == *(longlong *)(lVar7 + 8)) {

              if (*(char *)(lVar7 + 0x18) == '\0') {

                *(undefined4 *)(param_1 + 0x20) = 0xffffffff;

              }

              else {

                *(int *)(param_1 + 0x20) = iVar4 + 1;

              }

            }

            else {

              *(int *)(param_1 + 0x20) = iVar4 + 1;

              *(longlong *)(lVar7 + 0x10) = *(longlong *)(lVar7 + 0x10) + 1;

              *(ushort *)**(undefined8 **)(param_1 + 0x460) = uVar1;

              **(longlong **)(param_1 + 0x460) = **(longlong **)(param_1 + 0x460) + 2;

            }

          }

          else if (bVar5 == 1) {

            *(undefined8 *)(param_1 + 0x28) = 0;

            *(undefined1 *)(param_1 + 0x38) = 0;

            *(undefined4 *)(param_1 + 0x30) = 0xffffffff;

            *(undefined4 *)(param_1 + 0x34) = 0;

            *(undefined1 *)(param_1 + 0x4c) = 0;

          }

          else if (bVar5 == 2) {

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

            if (bVar5 == 3) {

              if (uVar1 == 0x2a) {

                piVar2 = *(int **)(param_1 + 0x18);

                *(int **)(param_1 + 0x18) = piVar2 + 2;

                iVar4 = *piVar2;

                *(int *)(param_1 + 0x2c) = iVar4;

                if (iVar4 < 0) {

                  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 4;

                  *(int *)(param_1 + 0x2c) = -iVar4;

                }

LAB_1402d4e28:

                cVar3 = '\x01';

              }

              else {

                lVar7 = param_1 + 0x2c;

LAB_1402d4dd1:

                cVar3 = FUN_1402d3ed4(param_1,lVar7);

              }

            }

            else {

              if (bVar5 == 4) {

                *(undefined4 *)(param_1 + 0x30) = 0;

                goto LAB_1402d4ed7;

              }

              if (bVar5 == 5) {

                if (uVar1 == 0x2a) {

                  piVar2 = *(int **)(param_1 + 0x18);

                  *(int **)(param_1 + 0x18) = piVar2 + 2;

                  iVar4 = *piVar2;

                  *(int *)(param_1 + 0x30) = iVar4;

                  if (iVar4 < 0) {

                    *(undefined4 *)(param_1 + 0x30) = 0xffffffff;

                  }

                  goto LAB_1402d4e28;

                }

                lVar7 = param_1 + 0x30;

                goto LAB_1402d4dd1;

              }

              if (bVar5 == 6) {

                cVar3 = FUN_1402d5404(param_1);

              }

              else {

                if (bVar5 != 7) {

                  return 0xffffffff;

                }

                cVar3 = FUN_1402d6558(param_1);

              }

            }

            if (cVar3 == '\0') {

              return 0xffffffff;

            }

          }

LAB_1402d4ed7:

          puVar6 = *(ushort **)(param_1 + 0x10);

          uVar1 = *puVar6;

        }

        *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;

        iVar4 = *(int *)(param_1 + 0x468);

      } while( true );

    }

    *(undefined1 *)(lVar7 + 0x30) = 1;

    *(undefined4 *)(lVar7 + 0x2c) = 0x16;

    lVar7 = *(longlong *)(param_1 + 8);

  }

LAB_1402d4cdb:

  FUN_1402cd39c(0,0,0,0,0,lVar7);

  return 0xffffffff;

}




