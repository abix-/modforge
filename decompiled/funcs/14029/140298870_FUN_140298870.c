// Address: 0x140298870
// Ghidra name: FUN_140298870
// ============ 0x140298870 FUN_140298870 (size=623) ============


code * FUN_140298870(longlong param_1)



{

  uint uVar1;

  uint *puVar2;

  uint *puVar3;

  uint *puVar4;

  char cVar5;

  uint uVar6;

  code *pcVar7;

  uint *puVar8;

  code *pcVar9;

  uint uVar10;

  

  puVar2 = *(uint **)(param_1 + 0xe8);

  puVar3 = *(uint **)(param_1 + 0x38);

  if ((byte)puVar2[1] < 8) {

    return (code *)0x0;

  }

  uVar6 = *(uint *)(param_1 + 0x108) & 0xffff8fff;

  if (uVar6 == 0) {

    if (((*puVar3 & 0xf0000) == 0x60000) && ((*puVar2 & 0xf0000) == 0x60000)) {

      cVar5 = FUN_14017fd60();

      if (cVar5 != '\0') {

        return FUN_140295650;

      }

      cVar5 = FUN_14017fe90();

      if (cVar5 != '\0') {

        return FUN_1402958c0;

      }

    }

    pcVar7 = (code *)0x0;

    if (8 < (byte)puVar2[1]) {

      uVar6 = 0;

      uVar10 = 1;

      if (puVar2[5] != 0) {

        uVar10 = 2;

        if (puVar3[5] != 0) {

          uVar10 = 4;

        }

      }

      if ((byte)(*(byte *)((longlong)puVar3 + 5) - 1) < 4) {

        puVar4 = *(uint **)(&DAT_1403838e8 + (ulonglong)*(byte *)((longlong)puVar3 + 5) * 8);

        uVar1 = puVar4[3];

        puVar8 = puVar4;

        pcVar9 = pcVar7;

        while (uVar1 != 0) {

          uVar6 = (uint)pcVar9;

          if ((((((puVar3[2] == *puVar8) || (*puVar8 == 0)) &&

                ((puVar3[3] == puVar8[1] || (puVar8[1] == 0)))) &&

               ((puVar3[4] == puVar8[2] || (puVar8[2] == 0)))) &&

              ((puVar2[2] == puVar8[4] || (puVar8[4] == 0)))) &&

             ((((puVar2[3] == puVar8[5] || (puVar8[5] == 0)) &&

               ((puVar2[4] == puVar8[6] || (puVar8[6] == 0)))) &&

              ((((uint)*(byte *)((longlong)puVar2 + 5) == puVar8[3] &&

                ((puVar8[10] & uVar10) == uVar10)) &&

               (cVar5 = FUN_14017fe90(), (puVar8[7] & (uint)(cVar5 != '\0')) == puVar8[7]))))))

          break;

          pcVar7 = pcVar7 + 1;

          uVar6 = uVar6 + 1;

          pcVar9 = (code *)(ulonglong)uVar6;

          puVar8 = puVar4 + (longlong)pcVar7 * 0xc;

          uVar1 = puVar8[3];

        }

        pcVar7 = *(code **)(puVar4 + (longlong)(int)uVar6 * 0xc + 8);

        if (pcVar7 == FUN_140293af0) {

          cVar5 = *(char *)((longlong)puVar3 + 5);

          if (((cVar5 == *(char *)((longlong)puVar2 + 5)) && (puVar3[2] == puVar2[2])) &&

             ((puVar3[3] == puVar2[3] && (puVar3[4] == puVar2[4])))) {

            if (uVar10 == 4) {

              pcVar7 = FUN_14029fb60;

              if (puVar3[5] != puVar2[5]) {

                pcVar7 = FUN_140295af0;

              }

            }

            else if (cVar5 == '\x04') {

              pcVar7 = FUN_1402953d0;

            }

            else if (cVar5 == '\x02') {

              pcVar7 = FUN_140295120;

            }

          }

          else if (uVar10 == 4) {

            pcVar7 = FUN_140295af0;

          }

        }

      }

    }

  }

  else {

    if (uVar6 != 0x400) {

      return (code *)0x0;

    }

    if ((*(char *)((longlong)puVar3 + 5) == '\x02') && (*(int *)(param_1 + 0x78) != 0)) {

      return FUN_140294f70;

    }

    pcVar7 = FUN_140296080;

    if (puVar3[5] != 0) {

      if (puVar2[5] != 0) {

        pcVar7 = FUN_140297650;

      }

      return pcVar7;

    }

  }

  return pcVar7;

}




