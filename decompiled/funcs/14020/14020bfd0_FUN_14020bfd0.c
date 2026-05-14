// Address: 0x14020bfd0
// Ghidra name: FUN_14020bfd0
// ============ 0x14020bfd0 FUN_14020bfd0 (size=684) ============


void FUN_14020bfd0(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  ushort uVar4;

  uint uVar6;

  longlong lVar7;

  byte bVar8;

  int *piVar9;

  ulonglong uVar10;

  int iVar11;

  ulonglong uVar5;

  

  uVar3 = FUN_140149300();

  _guard_check_icall();

  if ((param_1 != 0) && (lVar1 = *(longlong *)(param_1 + 0x148), lVar1 != 0)) {

    if (*(code **)(lVar1 + 0x70) != (code *)0x0) {

      (**(code **)(lVar1 + 0x70))(*(undefined8 *)(lVar1 + 0x68));

    }

    if (((*(byte *)(lVar1 + 0xb0) & 1) != 0) && (uVar5 = 0, *(short *)(lVar1 + 0x34) != 0)) {

      do {

        FUN_14015aab0(uVar3,param_1,uVar5,*(undefined2 *)(*(longlong *)(lVar1 + 0xb8) + uVar5 * 2));

        bVar8 = (char)uVar5 + 1;

        uVar5 = (ulonglong)bVar8;

      } while ((ushort)bVar8 < *(ushort *)(lVar1 + 0x34));

    }

    if (((*(byte *)(lVar1 + 0xb0) & 2) != 0) && (bVar8 = 0, *(short *)(lVar1 + 0x38) != 0)) {

      do {

        lVar2 = *(longlong *)(lVar1 + 0xd0);

        uVar5 = (ulonglong)bVar8;

        iVar11 = *(int *)(lVar2 + uVar5 * 8);

        lVar7 = lVar2 + uVar5 * 8;

        if ((iVar11 != 0) || (*(int *)(lVar7 + 4) != 0)) {

          FUN_14015ac40(uVar3,param_1,bVar8,iVar11,*(undefined2 *)(lVar7 + 4));

          *(undefined4 *)(lVar2 + uVar5 * 8) = 0;

          *(undefined4 *)(lVar7 + 4) = 0;

        }

        bVar8 = bVar8 + 1;

      } while ((ushort)bVar8 < *(ushort *)(lVar1 + 0x38));

    }

    if (((*(byte *)(lVar1 + 0xb0) & 4) != 0) && (uVar5 = 0, *(short *)(lVar1 + 0x36) != 0)) {

      do {

        FUN_14015ad00(uVar3,param_1,uVar5,*(undefined1 *)(uVar5 + *(longlong *)(lVar1 + 0xc0)));

        bVar8 = (char)uVar5 + 1;

        uVar5 = (ulonglong)bVar8;

      } while ((ushort)bVar8 < *(ushort *)(lVar1 + 0x36));

    }

    if (((*(byte *)(lVar1 + 0xb0) & 8) != 0) && (bVar8 = 0, *(short *)(lVar1 + 0x3a) != 0)) {

      do {

        FUN_14015ae90(uVar3,param_1,bVar8,

                      *(undefined1 *)((ulonglong)bVar8 + *(longlong *)(lVar1 + 200)));

        bVar8 = bVar8 + 1;

      } while ((ushort)bVar8 < *(ushort *)(lVar1 + 0x3a));

    }

    if (((*(byte *)(lVar1 + 0xb0) & 0x10) != 0) && (uVar5 = 0, *(short *)(lVar1 + 0x3c) != 0)) {

      do {

        iVar11 = 0;

        piVar9 = (int *)(uVar5 * 0x10 + *(longlong *)(lVar1 + 0xd8));

        if (0 < *piVar9) {

          lVar7 = 0;

          do {

            lVar2 = *(longlong *)(piVar9 + 2);

            FUN_14015b110(uVar3,param_1,uVar5,iVar11,*(undefined1 *)(lVar7 + lVar2),

                          *(undefined4 *)(lVar7 + 4 + lVar2),*(undefined4 *)(lVar7 + 8 + lVar2),

                          *(undefined4 *)(lVar7 + 0xc + lVar2));

            iVar11 = iVar11 + 1;

            lVar7 = lVar7 + 0x10;

          } while (iVar11 < *piVar9);

        }

        uVar4 = (short)uVar5 + 1;

        uVar5 = (ulonglong)uVar4;

      } while (uVar4 < *(ushort *)(lVar1 + 0x3c));

    }

    uVar5 = 0;

    if (0 < *(int *)(lVar1 + 0xec)) {

      uVar10 = uVar5;

      if (*(char *)(lVar1 + 0xe8) != '\0') {

        do {

          lVar7 = *(longlong *)(lVar1 + 0xf8);

          FUN_14015afd0(uVar3,param_1,*(undefined4 *)(lVar7 + uVar10),

                        *(undefined8 *)(lVar7 + 8 + uVar10),lVar7 + 0x10 + uVar10,

                        *(undefined4 *)(lVar7 + 0x1c + uVar10));

          uVar6 = (int)uVar5 + 1;

          uVar5 = (ulonglong)uVar6;

          uVar10 = uVar10 + 0x20;

        } while ((int)uVar6 < *(int *)(lVar1 + 0xec));

      }

      *(undefined4 *)(lVar1 + 0xec) = 0;

    }

    *(undefined4 *)(lVar1 + 0xb0) = 0;

  }

  return;

}




