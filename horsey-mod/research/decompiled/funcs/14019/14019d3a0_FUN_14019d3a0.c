// Address: 0x14019d3a0
// Ghidra name: FUN_14019d3a0
// ============ 0x14019d3a0 FUN_14019d3a0 (size=989) ============


longlong FUN_14019d3a0(longlong param_1,int param_2,int param_3,int param_4,int param_5)



{

  undefined1 *puVar1;

  undefined1 uVar2;

  longlong lVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  undefined1 *puVar7;

  undefined1 *puVar8;

  

  if (param_1 == 0) {

    return 0;

  }

  if (param_3 != param_2) {

    lVar3 = FUN_1401a1b30(param_3,param_4,param_5,0);

    if (lVar3 == 0) {

      FUN_1401841e0(param_1);

      FUN_14019f050("Out of memory");

      lVar3 = 0;

    }

    else {

      iVar6 = 0;

      if (0 < param_5) {

        iVar5 = param_4 + -1;

        do {

          puVar8 = (undefined1 *)((ulonglong)(uint)(iVar6 * param_2 * param_4) + param_1);

          puVar7 = (undefined1 *)((ulonglong)(uint)(iVar6 * param_3 * param_4) + lVar3);

          switch(param_2 * 8 + -10 + param_3) {

          case 0:

            for (iVar4 = iVar5; -1 < iVar4; iVar4 = iVar4 + -1) {

              *puVar7 = *puVar8;

              puVar8 = puVar8 + 1;

              puVar7[1] = 0xff;

              puVar7 = puVar7 + 2;

            }

            break;

          case 1:

            for (iVar4 = iVar5; -1 < iVar4; iVar4 = iVar4 + -1) {

              uVar2 = *puVar8;

              puVar7[2] = uVar2;

              puVar8 = puVar8 + 1;

              puVar7[1] = uVar2;

              *puVar7 = uVar2;

              puVar7 = puVar7 + 3;

            }

            break;

          case 2:

            for (iVar4 = iVar5; -1 < iVar4; iVar4 = iVar4 + -1) {

              uVar2 = *puVar8;

              puVar7[2] = uVar2;

              puVar8 = puVar8 + 1;

              puVar7[1] = uVar2;

              *puVar7 = uVar2;

              puVar7[3] = 0xff;

              puVar7 = puVar7 + 4;

            }

            break;

          default:

            FUN_1401841e0(param_1);

            FUN_1401841e0(lVar3);

            FUN_14019f050("Unsupported format conversion");

            return 0;

          case 7:

            for (iVar4 = iVar5; -1 < iVar4; iVar4 = iVar4 + -1) {

              *puVar7 = *puVar8;

              puVar7 = puVar7 + 1;

              puVar8 = puVar8 + 2;

            }

            break;

          case 9:

            for (iVar4 = iVar5; -1 < iVar4; iVar4 = iVar4 + -1) {

              uVar2 = *puVar8;

              puVar7[2] = uVar2;

              puVar8 = puVar8 + 2;

              puVar7[1] = uVar2;

              *puVar7 = uVar2;

              puVar7 = puVar7 + 3;

            }

            break;

          case 10:

            for (iVar4 = iVar5; -1 < iVar4; iVar4 = iVar4 + -1) {

              uVar2 = *puVar8;

              puVar7[2] = uVar2;

              puVar7[1] = uVar2;

              *puVar7 = uVar2;

              puVar7[3] = puVar8[1];

              puVar8 = puVar8 + 2;

              puVar7 = puVar7 + 4;

            }

            break;

          case 0xf:

            for (iVar4 = iVar5; -1 < iVar4; iVar4 = iVar4 + -1) {

              uVar2 = FUN_14019d1d0(*puVar8,puVar8[1],puVar8[2]);

              *puVar7 = uVar2;

              puVar7 = puVar7 + 1;

              puVar8 = puVar8 + 3;

            }

            break;

          case 0x10:

            for (iVar4 = iVar5; -1 < iVar4; iVar4 = iVar4 + -1) {

              uVar2 = FUN_14019d1d0(*puVar8,puVar8[1],puVar8[2]);

              *puVar7 = uVar2;

              puVar7[1] = 0xff;

              puVar7 = puVar7 + 2;

              puVar8 = puVar8 + 3;

            }

            break;

          case 0x12:

            for (iVar4 = iVar5; -1 < iVar4; iVar4 = iVar4 + -1) {

              *puVar7 = *puVar8;

              puVar7[1] = puVar8[1];

              puVar7[2] = puVar8[2];

              puVar7[3] = 0xff;

              puVar8 = puVar8 + 3;

              puVar7 = puVar7 + 4;

            }

            break;

          case 0x17:

            for (iVar4 = iVar5; -1 < iVar4; iVar4 = iVar4 + -1) {

              uVar2 = FUN_14019d1d0(*puVar8,puVar8[1],puVar8[2]);

              *puVar7 = uVar2;

              puVar7 = puVar7 + 1;

              puVar8 = puVar8 + 4;

            }

            break;

          case 0x18:

            for (iVar4 = iVar5; -1 < iVar4; iVar4 = iVar4 + -1) {

              uVar2 = FUN_14019d1d0(*puVar8,puVar8[1],puVar8[2]);

              *puVar7 = uVar2;

              puVar1 = puVar8 + 3;

              puVar8 = puVar8 + 4;

              puVar7[1] = *puVar1;

              puVar7 = puVar7 + 2;

            }

            break;

          case 0x19:

            for (iVar4 = iVar5; -1 < iVar4; iVar4 = iVar4 + -1) {

              *puVar7 = *puVar8;

              puVar7[1] = puVar8[1];

              puVar7[2] = puVar8[2];

              puVar8 = puVar8 + 4;

              puVar7 = puVar7 + 3;

            }

          }

          iVar6 = iVar6 + 1;

        } while (iVar6 < param_5);

      }

      FUN_1401841e0(param_1);

    }

    return lVar3;

  }

  return param_1;

}




