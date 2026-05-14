// Address: 0x140266490
// Ghidra name: FUN_140266490
// ============ 0x140266490 FUN_140266490 (size=499) ============


void FUN_140266490(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,

                  int param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  if (0x12 < param_5) {

    if (*(byte *)(param_1 + 0xf7) != *(byte *)(param_4 + 2)) {

      FUN_14015ad00(param_3,param_2,7,*(byte *)(param_4 + 2) & 1);

      FUN_14015ad00(param_3,param_2,8,*(byte *)(param_4 + 2) >> 1 & 1);

    }

    iVar3 = *(int *)(param_1 + 0x158);

    iVar4 = 0;

    iVar2 = 0;

    if (0 < iVar3) {

      do {

        iVar1 = iVar2;

        if (iVar2 < 0) {

          iVar1 = iVar2 + 7;

        }

        if (*(char *)((longlong)(iVar1 >> 3) + 0xf8 + param_1) ==

            *(char *)((longlong)(iVar1 >> 3) + 3 + param_4)) {

          iVar2 = iVar2 + 8;

        }

        else {

          if (iVar3 <= iVar2) break;

          do {

            iVar3 = iVar2;

            if (iVar2 < 0) {

              iVar3 = iVar2 + 7;

            }

            FUN_14015ad00(param_3,param_2,(byte)iVar2 + *(char *)(param_1 + 0x156),

                          ((byte)(1 << ((byte)iVar2 & 0x1f)) &

                          *(byte *)((longlong)(iVar3 >> 3) + 3 + param_4)) != 0);

            iVar3 = *(int *)(param_1 + 0x158);

            iVar2 = iVar2 + 1;

          } while (iVar2 < iVar3);

        }

      } while (iVar2 < iVar3);

    }

    FUN_14015aab0(param_3,param_2,0,*(undefined2 *)(param_4 + 0xb));

    FUN_14015aab0(param_3,param_2,1,*(undefined2 *)(param_4 + 0xd));

    FUN_14015aab0(param_3,param_2,2,*(undefined2 *)(param_4 + 0xf));

    iVar3 = (short)(*(byte *)(param_4 + 0x12) - 0x80) * 0x100;

    FUN_14015aab0(param_3,param_2,4,

                  CONCAT22((short)((uint)iVar3 >> 0x10),

                           (ushort)iVar3 | (ushort)*(byte *)(param_4 + 0x11)));

    if (0 < *(int *)(param_1 + 0x15c)) {

      iVar3 = 0x14;

      do {

        if (param_5 <= iVar3) {

          return;

        }

        iVar2 = (short)(*(byte *)(iVar3 + param_4) - 0x80) * 0x100;

        FUN_14015aab0(param_3,param_2,iVar4 + 5,

                      CONCAT22((short)((uint)iVar2 >> 0x10),

                               (ushort)iVar2 | (ushort)*(byte *)((longlong)iVar3 + -1 + param_4)));

        iVar4 = iVar4 + 1;

        iVar3 = iVar3 + 2;

      } while (iVar4 < *(int *)(param_1 + 0x15c));

    }

  }

  return;

}




