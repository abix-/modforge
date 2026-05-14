// Address: 0x14002b180
// Ghidra name: FUN_14002b180
// ============ 0x14002b180 FUN_14002b180 (size=838) ============


byte * FUN_14002b180(longlong param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4)



{

  byte bVar1;

  ulonglong uVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  byte *pbVar6;

  longlong lVar7;

  longlong lVar8;

  undefined *puVar9;

  

  pcVar4 = (char *)FUN_140028820(param_2,param_4);

  if (pcVar4 == (char *)0x0) {

    return (byte *)0x0;

  }

  if (*pcVar4 == '\0') {

    return (byte *)0x0;

  }

  if (param_3 != (undefined8 *)0x0) {

    FUN_140028650(param_3,pcVar4,param_4);

    *(undefined8 *)(param_1 + 8) = *param_3;

  }

  pcVar5 = (char *)FUN_140028900(pcVar4,param_1 + 0x20);

  puVar9 = PTR_s_Error_reading_Attributes__14039a3e0;

  if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {

    lVar7 = *(longlong *)(param_1 + 0x18);

    if (lVar7 == 0) {

      return (byte *)0x0;

    }

    if (*(char *)(lVar7 + 0x68) != '\0') {

      return (byte *)0x0;

    }

    lVar8 = -1;

    *(undefined1 *)(lVar7 + 0x68) = 1;

    *(undefined4 *)(lVar7 + 0x6c) = 6;

    do {

      lVar8 = lVar8 + 1;

    } while (puVar9[lVar8] != '\0');

    FUN_140027f50(lVar7 + 0x70);

    *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

  }

  else {

    pcVar4 = (char *)FUN_140028820(pcVar5,param_4);

    puVar9 = PTR_s_Error_reading_Attributes__14039a3e0;

    if (((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) && (*pcVar4 == '=')) {

      pbVar6 = (byte *)FUN_140028820(pcVar4 + 1,param_4);

      puVar9 = PTR_s_Error_reading_Attributes__14039a3e0;

      if ((pbVar6 != (byte *)0x0) && (bVar1 = *pbVar6, bVar1 != 0)) {

        if (bVar1 == 0x27) {

          puVar9 = &DAT_14039bf00;

        }

        else {

          if (bVar1 != 0x22) {

            FUN_140027f50(param_1 + 0x40,&DAT_14039bcb9,0);

            while( true ) {

              bVar1 = *pbVar6;

              if (bVar1 == 0) {

                return pbVar6;

              }

              iVar3 = isspace((uint)bVar1);

              puVar9 = PTR_s_Error_reading_Attributes__14039a3e0;

              if (iVar3 != 0) {

                return pbVar6;

              }

              if (bVar1 == 10) {

                return pbVar6;

              }

              if (bVar1 == 0xd) {

                return pbVar6;

              }

              bVar1 = *pbVar6;

              if (bVar1 == 0x2f) {

                return pbVar6;

              }

              if (bVar1 == 0x3e) {

                return pbVar6;

              }

              if ((bVar1 == 0x27) || (bVar1 == 0x22)) break;

              uVar2 = *(ulonglong *)(param_1 + 0x50);

              if (uVar2 < *(ulonglong *)(param_1 + 0x58)) {

                *(ulonglong *)(param_1 + 0x50) = uVar2 + 1;

                lVar7 = param_1 + 0x40;

                if (0xf < *(ulonglong *)(param_1 + 0x58)) {

                  lVar7 = *(longlong *)(param_1 + 0x40);

                }

                *(byte *)(lVar7 + uVar2) = bVar1;

                *(undefined1 *)(lVar7 + 1 + uVar2) = 0;

              }

              else {

                FUN_1400280d0(param_1 + 0x40);

              }

              pbVar6 = pbVar6 + 1;

              if (pbVar6 == (byte *)0x0) {

                return (byte *)0x0;

              }

            }

            lVar7 = *(longlong *)(param_1 + 0x18);

            if (lVar7 == 0) {

              return (byte *)0x0;

            }

            if (*(char *)(lVar7 + 0x68) != '\0') {

              return (byte *)0x0;

            }

            lVar8 = -1;

            *(undefined1 *)(lVar7 + 0x68) = 1;

            *(undefined4 *)(lVar7 + 0x6c) = 6;

            do {

              lVar8 = lVar8 + 1;

            } while (puVar9[lVar8] != '\0');

            FUN_140027f50(lVar7 + 0x70);

            *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

            goto LAB_14002b3c7;

          }

          puVar9 = &DAT_14039bef0;

        }

        pbVar6 = (byte *)FUN_140028cc0(pbVar6 + 1,param_1 + 0x40,0,puVar9);

        return pbVar6;

      }

      lVar7 = *(longlong *)(param_1 + 0x18);

      if (lVar7 == 0) {

        return (byte *)0x0;

      }

      if (*(char *)(lVar7 + 0x68) != '\0') {

        return (byte *)0x0;

      }

      lVar8 = -1;

      *(undefined1 *)(lVar7 + 0x68) = 1;

      *(undefined4 *)(lVar7 + 0x6c) = 6;

      do {

        lVar8 = lVar8 + 1;

      } while (puVar9[lVar8] != '\0');

      FUN_140027f50(lVar7 + 0x70);

      *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

      if (pbVar6 == (byte *)0x0) {

        return (byte *)0x0;

      }

LAB_14002b3c7:

      if (param_3 == (undefined8 *)0x0) {

        return (byte *)0x0;

      }

      FUN_140028650(param_3,pbVar6,param_4);

      *(undefined8 *)(lVar7 + 0x94) = *param_3;

      return (byte *)0x0;

    }

    lVar7 = *(longlong *)(param_1 + 0x18);

    if (lVar7 == 0) {

      return (byte *)0x0;

    }

    if (*(char *)(lVar7 + 0x68) != '\0') {

      return (byte *)0x0;

    }

    lVar8 = -1;

    *(undefined1 *)(lVar7 + 0x68) = 1;

    *(undefined4 *)(lVar7 + 0x6c) = 6;

    do {

      lVar8 = lVar8 + 1;

    } while (puVar9[lVar8] != '\0');

    FUN_140027f50(lVar7 + 0x70);

    *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

    if (pcVar4 == (char *)0x0) {

      return (byte *)0x0;

    }

  }

  if (param_3 != (undefined8 *)0x0) {

    FUN_140028650(param_3,pcVar4,param_4);

    *(undefined8 *)(lVar7 + 0x94) = *param_3;

  }

  return (byte *)0x0;

}




