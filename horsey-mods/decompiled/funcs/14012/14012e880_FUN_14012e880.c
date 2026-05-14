// Address: 0x14012e880
// Ghidra name: FUN_14012e880
// ============ 0x14012e880 FUN_14012e880 (size=432) ============


undefined8 FUN_14012e880(uint param_1,uint *param_2)



{

  short *psVar1;

  uint *puVar2;

  longlong lVar3;

  longlong lVar4;

  short sVar5;

  uint uVar6;

  ulonglong uVar7;

  

  if (param_1 < 0x80) {

    if (param_1 - 0x41 < 0x1a) {

      *param_2 = param_1 + 0x20;

      return 1;

    }

  }

  else {

    uVar7 = (ulonglong)(param_1 >> 8) & 0xff ^ (ulonglong)param_1 & 0xff;

    uVar6 = (uint)uVar7;

    if (param_1 < 0x10000) {

      lVar3 = 0;

      sVar5 = (short)param_1;

      if ((&DAT_140316368)[uVar7 * 0x10] != 0) {

        psVar1 = (short *)(&PTR_DAT_140316360)[uVar7 * 2];

        lVar4 = lVar3;

        do {

          if (*psVar1 == sVar5) {

            *param_2 = (uint)(ushort)psVar1[1];

            return 1;

          }

          lVar4 = lVar4 + 1;

          psVar1 = psVar1 + 2;

        } while (lVar4 < (longlong)(ulonglong)(byte)(&DAT_140316368)[uVar7 * 0x10]);

      }

      if ((&DAT_140317468)[(ulonglong)(uVar6 & 0xf) * 0x10] != 0) {

        psVar1 = (short *)(&PTR_DAT_140317460)[(ulonglong)(uVar6 & 0xf) * 2];

        lVar4 = lVar3;

        do {

          if (*psVar1 == sVar5) {

            *param_2 = (uint)(ushort)psVar1[1];

            param_2[1] = (uint)(ushort)psVar1[2];

            return 2;

          }

          lVar4 = lVar4 + 1;

          psVar1 = psVar1 + 3;

        } while (lVar4 < (longlong)

                         (ulonglong)(byte)(&DAT_140317468)[(ulonglong)(uVar6 & 0xf) * 0x10]);

      }

      if ((&DAT_140317568)[(ulonglong)(uVar6 & 3) * 0x10] != 0) {

        psVar1 = (short *)(&PTR_DAT_140317560)[(ulonglong)(uVar6 & 3) * 2];

        do {

          if (*psVar1 == sVar5) {

            *param_2 = (uint)(ushort)psVar1[1];

            param_2[1] = (uint)(ushort)psVar1[2];

            param_2[2] = (uint)(ushort)psVar1[3];

            return 3;

          }

          lVar3 = lVar3 + 1;

          psVar1 = psVar1 + 4;

        } while (lVar3 < (longlong)(ulonglong)(byte)(&DAT_140317568)[(ulonglong)(uVar6 & 3) * 0x10])

        ;

      }

    }

    else if ((&DAT_140317368)[(ulonglong)(uVar6 & 0xf) * 0x10] != 0) {

      lVar3 = 0;

      puVar2 = (uint *)(&PTR_DAT_140317360)[(ulonglong)(uVar6 & 0xf) * 2];

      do {

        if (*puVar2 == param_1) {

          *param_2 = puVar2[1];

          return 1;

        }

        lVar3 = lVar3 + 1;

        puVar2 = puVar2 + 2;

      } while (lVar3 < (longlong)(ulonglong)(byte)(&DAT_140317368)[(ulonglong)(uVar6 & 0xf) * 0x10])

      ;

      *param_2 = param_1;

      return 1;

    }

  }

  *param_2 = param_1;

  return 1;

}




