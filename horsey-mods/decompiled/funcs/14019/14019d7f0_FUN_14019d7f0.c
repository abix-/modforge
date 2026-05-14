// Address: 0x14019d7f0
// Ghidra name: FUN_14019d7f0
// ============ 0x14019d7f0 FUN_14019d7f0 (size=1042) ============


longlong FUN_14019d7f0(longlong param_1,int param_2,int param_3,int param_4,int param_5)



{

  int iVar1;

  undefined2 *puVar2;

  undefined2 uVar3;

  longlong lVar4;

  int iVar5;

  int iVar6;

  undefined2 *puVar7;

  undefined2 *puVar8;

  

  if (param_3 != param_2) {

    iVar6 = 0;

    lVar4 = FUN_1401a1b80(param_3,param_4,param_5,2,0);

    if (lVar4 == 0) {

      FUN_1401841e0(param_1);

      FUN_14019f050("Out of memory");

      lVar4 = 0;

    }

    else {

      if (0 < param_5) {

        iVar1 = param_4 + -1;

        do {

          puVar8 = (undefined2 *)(param_1 + (ulonglong)(uint)(iVar6 * param_2 * param_4) * 2);

          puVar7 = (undefined2 *)(lVar4 + (ulonglong)(uint)(iVar6 * param_3 * param_4) * 2);

          switch(param_2 * 8 + -10 + param_3) {

          case 0:

            for (iVar5 = iVar1; -1 < iVar5; iVar5 = iVar5 + -1) {

              *puVar7 = *puVar8;

              puVar8 = puVar8 + 1;

              puVar7[1] = 0xffff;

              puVar7 = puVar7 + 2;

            }

            break;

          case 1:

            for (iVar5 = iVar1; -1 < iVar5; iVar5 = iVar5 + -1) {

              uVar3 = *puVar8;

              puVar7[2] = uVar3;

              puVar8 = puVar8 + 1;

              puVar7[1] = uVar3;

              *puVar7 = uVar3;

              puVar7 = puVar7 + 3;

            }

            break;

          case 2:

            for (iVar5 = iVar1; -1 < iVar5; iVar5 = iVar5 + -1) {

              uVar3 = *puVar8;

              puVar7[2] = uVar3;

              puVar8 = puVar8 + 1;

              puVar7[1] = uVar3;

              *puVar7 = uVar3;

              puVar7[3] = 0xffff;

              puVar7 = puVar7 + 4;

            }

            break;

          default:

            FUN_1401841e0(param_1);

            FUN_1401841e0(lVar4);

            FUN_14019f050("Unsupported format conversion");

            return 0;

          case 7:

            for (iVar5 = iVar1; -1 < iVar5; iVar5 = iVar5 + -1) {

              *puVar7 = *puVar8;

              puVar7 = puVar7 + 1;

              puVar8 = puVar8 + 2;

            }

            break;

          case 9:

            for (iVar5 = iVar1; -1 < iVar5; iVar5 = iVar5 + -1) {

              uVar3 = *puVar8;

              puVar7[2] = uVar3;

              puVar8 = puVar8 + 2;

              puVar7[1] = uVar3;

              *puVar7 = uVar3;

              puVar7 = puVar7 + 3;

            }

            break;

          case 10:

            for (iVar5 = iVar1; -1 < iVar5; iVar5 = iVar5 + -1) {

              uVar3 = *puVar8;

              puVar7[2] = uVar3;

              puVar7[1] = uVar3;

              *puVar7 = uVar3;

              puVar7[3] = puVar8[1];

              puVar8 = puVar8 + 2;

              puVar7 = puVar7 + 4;

            }

            break;

          case 0xf:

            for (iVar5 = iVar1; -1 < iVar5; iVar5 = iVar5 + -1) {

              uVar3 = FUN_14019d1d0(*puVar8,puVar8[1],puVar8[2]);

              *puVar7 = uVar3;

              puVar7 = puVar7 + 1;

              puVar8 = puVar8 + 3;

            }

            break;

          case 0x10:

            for (iVar5 = iVar1; -1 < iVar5; iVar5 = iVar5 + -1) {

              uVar3 = FUN_14019d1d0(*puVar8,puVar8[1],puVar8[2]);

              *puVar7 = uVar3;

              puVar8 = puVar8 + 3;

              puVar7[1] = 0xffff;

              puVar7 = puVar7 + 2;

            }

            break;

          case 0x12:

            for (iVar5 = iVar1; -1 < iVar5; iVar5 = iVar5 + -1) {

              *puVar7 = *puVar8;

              puVar7[1] = puVar8[1];

              puVar7[2] = puVar8[2];

              puVar7[3] = 0xffff;

              puVar8 = puVar8 + 3;

              puVar7 = puVar7 + 4;

            }

            break;

          case 0x17:

            for (iVar5 = iVar1; -1 < iVar5; iVar5 = iVar5 + -1) {

              uVar3 = FUN_14019d1d0(*puVar8,puVar8[1],puVar8[2]);

              *puVar7 = uVar3;

              puVar7 = puVar7 + 1;

              puVar8 = puVar8 + 4;

            }

            break;

          case 0x18:

            for (iVar5 = iVar1; -1 < iVar5; iVar5 = iVar5 + -1) {

              uVar3 = FUN_14019d1d0(*puVar8,puVar8[1],puVar8[2]);

              *puVar7 = uVar3;

              puVar2 = puVar8 + 3;

              puVar8 = puVar8 + 4;

              puVar7[1] = *puVar2;

              puVar7 = puVar7 + 2;

            }

            break;

          case 0x19:

            for (iVar5 = iVar1; -1 < iVar5; iVar5 = iVar5 + -1) {

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

    return lVar4;

  }

  return param_1;

}




