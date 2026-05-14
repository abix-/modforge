// Address: 0x1400e6f80
// Ghidra name: FUN_1400e6f80
// ============ 0x1400e6f80 FUN_1400e6f80 (size=969) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_1400e6f80(longlong param_1,int param_2,int param_3,int param_4,int param_5)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  int iVar4;

  longlong lVar5;

  byte *pbVar6;

  byte *pbVar7;

  int iVar8;

  

  if (param_3 != param_2) {

    lVar5 = _malloc_base(param_3 * param_4 * param_5);

    if (lVar5 == 0) {

      thunk_FUN_1402e9a80(param_1);

      _DAT_1403f4c40 = "outofmem";

      lVar5 = 0;

    }

    else {

      iVar8 = 0;

      if (0 < param_5) {

        do {

          pbVar7 = (byte *)((ulonglong)(uint)(iVar8 * param_2 * param_4) + param_1);

          pbVar6 = (byte *)((ulonglong)(uint)(iVar8 * param_3 * param_4) + lVar5);

          switch(param_2 * 8 + -10 + param_3) {

          case 0:

            iVar4 = param_4;

            while (iVar4 = iVar4 + -1, -1 < iVar4) {

              *pbVar6 = *pbVar7;

              pbVar7 = pbVar7 + 1;

              pbVar6[1] = 0xff;

              pbVar6 = pbVar6 + 2;

            }

            break;

          case 1:

            iVar4 = param_4;

            while (iVar4 = iVar4 + -1, -1 < iVar4) {

              bVar1 = *pbVar7;

              pbVar6[2] = bVar1;

              pbVar7 = pbVar7 + 1;

              pbVar6[1] = bVar1;

              *pbVar6 = bVar1;

              pbVar6 = pbVar6 + 3;

            }

            break;

          case 2:

            iVar4 = param_4;

            while (iVar4 = iVar4 + -1, -1 < iVar4) {

              bVar1 = *pbVar7;

              pbVar6[2] = bVar1;

              pbVar7 = pbVar7 + 1;

              pbVar6[1] = bVar1;

              *pbVar6 = bVar1;

              pbVar6[3] = 0xff;

              pbVar6 = pbVar6 + 4;

            }

            break;

          case 7:

            iVar4 = param_4;

            while (iVar4 = iVar4 + -1, -1 < iVar4) {

              *pbVar6 = *pbVar7;

              pbVar6 = pbVar6 + 1;

              pbVar7 = pbVar7 + 2;

            }

            break;

          case 9:

            iVar4 = param_4;

            while (iVar4 = iVar4 + -1, -1 < iVar4) {

              bVar1 = *pbVar7;

              pbVar6[2] = bVar1;

              pbVar7 = pbVar7 + 2;

              pbVar6[1] = bVar1;

              *pbVar6 = bVar1;

              pbVar6 = pbVar6 + 3;

            }

            break;

          case 10:

            iVar4 = param_4;

            while (iVar4 = iVar4 + -1, -1 < iVar4) {

              bVar1 = *pbVar7;

              pbVar6[2] = bVar1;

              pbVar6[1] = bVar1;

              *pbVar6 = bVar1;

              pbVar6[3] = pbVar7[1];

              pbVar7 = pbVar7 + 2;

              pbVar6 = pbVar6 + 4;

            }

            break;

          case 0xf:

            iVar4 = param_4;

            while (iVar4 = iVar4 + -1, -1 < iVar4) {

              *pbVar6 = (byte)((uint)pbVar7[1] * 0x96 + (uint)pbVar7[2] * 0x1d +

                               (uint)*pbVar7 * 0x4d >> 8);

              pbVar7 = pbVar7 + 3;

              pbVar6 = pbVar6 + 1;

            }

            break;

          case 0x10:

            iVar4 = param_4;

            while (iVar4 = iVar4 + -1, -1 < iVar4) {

              bVar1 = pbVar7[1];

              bVar2 = pbVar7[2];

              bVar3 = *pbVar7;

              pbVar6[1] = 0xff;

              *pbVar6 = (byte)((uint)bVar1 * 0x96 + (uint)bVar2 * 0x1d + (uint)bVar3 * 0x4d >> 8);

              pbVar7 = pbVar7 + 3;

              pbVar6 = pbVar6 + 2;

            }

            break;

          case 0x12:

            iVar4 = param_4;

            while (iVar4 = iVar4 + -1, -1 < iVar4) {

              *pbVar6 = *pbVar7;

              pbVar6[1] = pbVar7[1];

              pbVar6[2] = pbVar7[2];

              pbVar6[3] = 0xff;

              pbVar7 = pbVar7 + 3;

              pbVar6 = pbVar6 + 4;

            }

            break;

          case 0x17:

            iVar4 = param_4;

            while (iVar4 = iVar4 + -1, -1 < iVar4) {

              *pbVar6 = (byte)((uint)pbVar7[1] * 0x96 + (uint)pbVar7[2] * 0x1d +

                               (uint)*pbVar7 * 0x4d >> 8);

              pbVar7 = pbVar7 + 4;

              pbVar6 = pbVar6 + 1;

            }

            break;

          case 0x18:

            iVar4 = param_4;

            while (iVar4 = iVar4 + -1, -1 < iVar4) {

              *pbVar6 = (byte)((uint)pbVar7[1] * 0x96 + (uint)pbVar7[2] * 0x1d +

                               (uint)*pbVar7 * 0x4d >> 8);

              pbVar6[1] = pbVar7[3];

              pbVar7 = pbVar7 + 4;

              pbVar6 = pbVar6 + 2;

            }

            break;

          case 0x19:

            iVar4 = param_4;

            while (iVar4 = iVar4 + -1, -1 < iVar4) {

              *pbVar6 = *pbVar7;

              pbVar6[1] = pbVar7[1];

              pbVar6[2] = pbVar7[2];

              pbVar7 = pbVar7 + 4;

              pbVar6 = pbVar6 + 3;

            }

          }

          iVar8 = iVar8 + 1;

        } while (iVar8 < param_5);

      }

      thunk_FUN_1402e9a80(param_1);

    }

    return lVar5;

  }

  return param_1;

}




