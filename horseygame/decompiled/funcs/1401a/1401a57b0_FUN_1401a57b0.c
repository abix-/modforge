// Address: 0x1401a57b0
// Ghidra name: FUN_1401a57b0
// ============ 0x1401a57b0 FUN_1401a57b0 (size=760) ============


bool FUN_1401a57b0(longlong param_1)



{

  int iVar1;

  ushort uVar2;

  uint uVar3;

  longlong lVar4;

  byte bVar5;

  byte *pbVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  byte bVar11;

  

  pbVar6 = (byte *)(param_1 + 0x92aa);

  uVar8 = 1;

  if (pbVar6 < *(byte **)(param_1 + 0x30)) {

    do {

      if (uVar8 == 1) {

        uVar8 = *pbVar6 | 0x100;

        pbVar6 = pbVar6 + 1;

      }

      bVar5 = *pbVar6;

      iVar1 = *(int *)(param_1 + 0x5c);

      if ((uVar8 & 1) == 0) {

        bVar11 = *(byte *)((ulonglong)bVar5 + 0x8f4a + param_1);

        uVar9 = (uint)*(ushort *)(param_1 + 0x888a + (ulonglong)bVar5 * 2) << ((byte)iVar1 & 0x1f) |

                *(uint *)(param_1 + 0x60);

        *(uint *)(param_1 + 0x60) = uVar9;

        uVar3 = (uint)bVar11 + iVar1;

        *(uint *)(param_1 + 0x5c) = uVar3;

        while (7 < uVar3) {

          if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

            **(undefined1 **)(param_1 + 0x40) = (char)uVar9;

            *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

          }

          *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) >> 8;

          *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + -8;

          uVar9 = (uint)*(byte *)(param_1 + 0x60);

          uVar3 = *(uint *)(param_1 + 0x5c);

        }

        lVar4 = 1;

      }

      else {

        uVar10 = (uint)bVar5;

        uVar2 = *(ushort *)(pbVar6 + 1);

        uVar7 = (uint)uVar2;

        bVar5 = *(byte *)((ulonglong)*(ushort *)(&DAT_14033b660 + (ulonglong)uVar10 * 2) + 0x8f4a +

                         param_1);

        uVar9 = (uint)*(ushort *)

                       (param_1 + 0x888a +

                       (ulonglong)*(ushort *)(&DAT_14033b660 + (ulonglong)uVar10 * 2) * 2) <<

                ((byte)iVar1 & 0x1f) | *(uint *)(param_1 + 0x60);

        *(uint *)(param_1 + 0x60) = uVar9;

        uVar3 = (uint)bVar5 + iVar1;

        *(uint *)(param_1 + 0x5c) = uVar3;

        while (7 < uVar3) {

          if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

            **(undefined1 **)(param_1 + 0x40) = (char)uVar9;

            *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

          }

          uVar9 = *(uint *)(param_1 + 0x60) >> 8;

          uVar3 = *(int *)(param_1 + 0x5c) - 8;

          *(uint *)(param_1 + 0x60) = uVar9;

          *(uint *)(param_1 + 0x5c) = uVar3;

        }

        uVar9 = (*(uint *)(&DAT_14033be60 + (ulonglong)(byte)(&DAT_14033b860)[uVar10] * 4) & uVar10)

                << ((byte)uVar3 & 0x1f) | uVar9;

        uVar3 = (byte)(&DAT_14033b860)[uVar10] + uVar3;

        *(uint *)(param_1 + 0x60) = uVar9;

        *(uint *)(param_1 + 0x5c) = uVar3;

        while (7 < uVar3) {

          if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

            **(undefined1 **)(param_1 + 0x40) = (char)uVar9;

            *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

          }

          uVar9 = *(uint *)(param_1 + 0x60) >> 8;

          uVar3 = *(int *)(param_1 + 0x5c) - 8;

          *(uint *)(param_1 + 0x60) = uVar9;

          *(uint *)(param_1 + 0x5c) = uVar3;

        }

        if (uVar7 < 0x200) {

          bVar5 = (&DAT_14033b960)[uVar7];

          bVar11 = (&DAT_14033bb60)[uVar7];

        }

        else {

          uVar2 = uVar2 >> 8;

          bVar5 = (&DAT_14033bd60)[uVar2];

          bVar11 = (&DAT_14033bde0)[uVar2];

        }

        uVar10 = uVar3 + *(byte *)((ulonglong)bVar5 + 0x906a + param_1);

        uVar9 = (uint)*(ushort *)(param_1 + 0x8aca + (ulonglong)bVar5 * 2) << ((byte)uVar3 & 0x1f) |

                uVar9;

        *(uint *)(param_1 + 0x5c) = uVar10;

        *(uint *)(param_1 + 0x60) = uVar9;

        uVar3 = uVar9;

        while (7 < uVar10) {

          if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

            **(undefined1 **)(param_1 + 0x40) = (char)uVar3;

            *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

          }

          uVar9 = *(uint *)(param_1 + 0x60) >> 8;

          uVar10 = *(int *)(param_1 + 0x5c) - 8;

          *(uint *)(param_1 + 0x60) = uVar9;

          uVar3 = uVar9 & 0xff;

          *(uint *)(param_1 + 0x5c) = uVar10;

        }

        uVar3 = bVar11 + uVar10;

        uVar9 = (*(uint *)(&DAT_14033be60 + (ulonglong)bVar11 * 4) & uVar7) << ((byte)uVar10 & 0x1f)

                | uVar9;

        *(uint *)(param_1 + 0x5c) = uVar3;

        *(uint *)(param_1 + 0x60) = uVar9;

        while (7 < uVar3) {

          if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

            **(undefined1 **)(param_1 + 0x40) = (char)uVar9;

            *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

          }

          *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) >> 8;

          *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + -8;

          uVar9 = (uint)*(byte *)(param_1 + 0x60);

          uVar3 = *(uint *)(param_1 + 0x5c);

        }

        lVar4 = 3;

      }

      uVar8 = uVar8 >> 1;

      pbVar6 = pbVar6 + lVar4;

    } while (pbVar6 < *(byte **)(param_1 + 0x30));

  }

  uVar8 = *(int *)(param_1 + 0x5c) + (uint)*(byte *)(param_1 + 0x904a);

  uVar3 = (uint)*(ushort *)(param_1 + 0x8a8a) << ((byte)*(int *)(param_1 + 0x5c) & 0x1f) |

          *(uint *)(param_1 + 0x60);

  *(uint *)(param_1 + 0x60) = uVar3;

  *(uint *)(param_1 + 0x5c) = uVar8;

  while (7 < uVar8) {

    if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

      **(undefined1 **)(param_1 + 0x40) = (char)uVar3;

      *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

    }

    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) >> 8;

    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + -8;

    uVar3 = (uint)*(byte *)(param_1 + 0x60);

    uVar8 = *(uint *)(param_1 + 0x5c);

  }

  return *(ulonglong *)(param_1 + 0x40) < *(ulonglong *)(param_1 + 0x48);

}




