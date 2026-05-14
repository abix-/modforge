// Address: 0x140283540
// Ghidra name: FUN_140283540
// ============ 0x140283540 FUN_140283540 (size=253) ============


uint FUN_140283540(longlong param_1)



{

  short sVar1;

  uint uVar2;

  longlong lVar3;

  char *pcVar4;

  byte bVar5;

  undefined1 local_88 [16];

  char local_78;

  

  lVar3 = FUN_1401841a0(1,0xe8);

  uVar2 = (uint)lVar3;

  if (lVar3 != 0) {

    *(longlong *)(param_1 + 0x70) = lVar3;

    bVar5 = 0;

    *(undefined1 *)(lVar3 + 0x40) = 0;

    do {

      uVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_88,0x80,10);

      if (0 < (int)uVar2) {

        sVar1 = *(short *)(param_1 + 0x22);

        if (sVar1 == 6) {

          pcVar4 = "ZUIKI MASCON PRO";

        }

        else {

          if (sVar1 != 0x17) {

            if (sVar1 == 0x1c) {

              *(undefined1 *)(lVar3 + 0x40) = 1;

              *(undefined4 *)(lVar3 + 0x50) = 0x42c80000;

              uVar2 = FUN_140208110(param_1,0);

              return uVar2;

            }

            if (sVar1 == 0x1d) {

              *(undefined1 *)(lVar3 + 0x40) = 1;

              *(undefined4 *)(lVar3 + 0x50) = 0x43480000;

              uVar2 = FUN_140208110(param_1,0);

              return uVar2;

            }

            goto LAB_14028362e;

          }

          if (local_78 != '\0') {

            *(undefined1 *)(lVar3 + 0x40) = 1;

            *(undefined4 *)(lVar3 + 0x50) = 0x42480000;

          }

          pcVar4 = "ZUIKI EVOTOP";

        }

        FUN_1402083c0(param_1,pcVar4);

LAB_14028362e:

        uVar2 = FUN_140208110(param_1,0);

        return uVar2;

      }

      bVar5 = bVar5 + 1;

    } while (bVar5 < 10);

  }

  return uVar2 & 0xffffff00;

}




