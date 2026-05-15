// Address: 0x140188360
// Ghidra name: FUN_140188360
// ============ 0x140188360 FUN_140188360 (size=496) ============


ulonglong FUN_140188360(longlong param_1,undefined8 param_2,int param_3)



{

  undefined1 *puVar1;

  uint uVar2;

  char cVar3;

  byte bVar4;

  ulonglong uVar5;

  longlong lVar6;

  undefined1 *puVar7;

  int iVar8;

  undefined1 *puVar9;

  longlong lVar10;

  uint uVar11;

  byte local_res8 [8];

  undefined1 local_res20;

  undefined1 local_48 [4];

  int local_44;

  longlong local_40;

  

  puVar1 = *(undefined1 **)(param_1 + 0x18);

  local_44 = *(int *)(param_1 + 0x10);

  lVar6 = (longlong)local_44;

  iVar8 = 0;

  puVar9 = puVar1 + local_44 * *(int *)(param_1 + 0xc);

  lVar10 = (longlong)puVar9 - lVar6;

  uVar11 = 2 - (param_3 != 0);

  local_40 = lVar6;

  uVar5 = FUN_14012c840(param_2,local_res8);

  cVar3 = (char)uVar5;

  while (cVar3 != '\0') {

    if (local_res8[0] == 0) {

      uVar5 = FUN_14012c840(param_2,local_res8);

      if ((char)uVar5 == '\0') break;

      if (local_res8[0] == 0) {

        iVar8 = 0;

        lVar10 = lVar10 - lVar6;

      }

      else {

        if (local_res8[0] == 1) {

          return 1;

        }

        if (local_res8[0] == 2) {

          uVar5 = FUN_14012c840(param_2);

          if ((char)uVar5 == '\0') break;

          iVar8 = iVar8 + local_res8[0] / uVar11;

          uVar5 = FUN_14012c840(param_2,local_res8);

          if ((char)uVar5 == '\0') break;

          lVar10 = lVar10 - (int)((uint)(local_res8[0] >> (param_3 == 0)) * local_44);

        }

        else {

          uVar2 = (uint)local_res8[0];

          local_res8[0] = (byte)(uVar2 / uVar11);

          puVar7 = (undefined1 *)(iVar8 + lVar10);

          do {

            uVar5 = FUN_14012c840(param_2,local_48);

            if ((char)uVar5 == '\0') goto LAB_1401884e1;

            iVar8 = iVar8 + 1;

            if ((puVar1 <= puVar7) && (puVar7 < puVar9)) {

              *puVar7 = local_48[0];

            }

            local_res8[0] = local_res8[0] - 1;

            puVar7 = puVar7 + 1;

          } while (local_res8[0] != 0);

          lVar6 = local_40;

          if (((uVar2 / uVar11 & 1) != 0) &&

             (uVar5 = FUN_14012c840(param_2,local_res8), lVar6 = local_40, (char)uVar5 == '\0'))

          break;

        }

      }

    }

    else {

      uVar5 = FUN_14012c840(param_2);

      if ((char)uVar5 == '\0') break;

      uVar5 = (ulonglong)local_res8[0] / (ulonglong)uVar11;

      local_res8[0] = (byte)uVar5;

      puVar7 = (undefined1 *)(iVar8 + lVar10);

      do {

        iVar8 = iVar8 + 1;

        bVar4 = (byte)uVar5;

        if ((puVar1 <= puVar7) && (puVar7 < puVar9)) {

          *puVar7 = local_res20;

          bVar4 = local_res8[0];

        }

        local_res8[0] = bVar4 - 1;

        uVar5 = (ulonglong)local_res8[0];

        puVar7 = puVar7 + 1;

      } while (local_res8[0] != 0);

      local_res8[0] = 0;

    }

    uVar5 = FUN_14012c840(param_2,local_res8);

    cVar3 = (char)uVar5;

  }

LAB_1401884e1:

  return uVar5 & 0xffffffffffffff00;

}




