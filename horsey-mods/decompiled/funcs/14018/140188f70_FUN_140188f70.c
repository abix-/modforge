// Address: 0x140188f70
// Ghidra name: FUN_140188f70
// ============ 0x140188f70 FUN_140188f70 (size=568) ============


ulonglong FUN_140188f70(longlong param_1,longlong *param_2,undefined4 *param_3)



{

  byte bVar1;

  ulonglong uVar2;

  byte bVar3;

  ushort uVar4;

  int iVar5;

  ulonglong uVar6;

  longlong lVar7;

  ushort uVar8;

  char *pcVar9;

  byte bVar10;

  byte bVar11;

  ulonglong uVar12;

  short sVar13;

  short sVar14;

  ulonglong local_res8;

  

  if ((ulonglong)*(uint *)(param_1 + 4) != *(ulonglong *)(param_1 + 0x18)) {

    uVar6 = FUN_14018a0e0(param_1,*(ulonglong *)(param_1 + 0x18) /

                                  (ulonglong)*(ushort *)(param_1 + 0x30));

    *(ulonglong *)(param_1 + 0x58) = uVar6;

    if ((longlong)uVar6 < 0) goto LAB_14018903f;

  }

  local_res8 = *(ulonglong *)(param_1 + 0x58);

  if (local_res8 == 0) {

    *param_2 = 0;

    *param_3 = 0;

    return 1;

  }

  iVar5 = FUN_14018a0b0(&local_res8,*(undefined2 *)(param_1 + 0x24));

  uVar12 = local_res8;

  if (((iVar5 == 0) && (iVar5 = FUN_14018a0b0(&local_res8,2), uVar2 = local_res8, iVar5 == 0)) &&

     (local_res8 < 0x100000000)) {

    uVar6 = 1;

    if (local_res8 != 0) {

      uVar6 = local_res8;

    }

    lVar7 = FUN_140184230(*(undefined8 *)(param_1 + 0x10),uVar6);

    uVar6 = 0;

    if (lVar7 == 0) {

LAB_14018903f:

      return uVar6 & 0xffffffffffffff00;

    }

    uVar6 = 0;

    *(undefined8 *)(param_1 + 0x10) = 0;

    *(undefined8 *)(param_1 + 0x18) = 0;

    if (*(short *)(param_1 + 0x22) == 6) {

      while (uVar12 != 0) {

        bVar1 = *(byte *)(lVar7 + -1 + uVar12);

        uVar12 = uVar12 - 1;

        bVar3 = bVar1 ^ 0xd5;

        bVar10 = bVar3 & 0x7f;

        bVar11 = bVar10 >> 4;

        uVar8 = (ushort)(bVar3 & 0xf);

        uVar4 = uVar8 | 0x10;

        if (bVar10 >> 4 == 0) {

          uVar4 = uVar8;

        }

        uVar4 = uVar4 << 4 | 8;

        if (1 < bVar11) {

          uVar4 = uVar4 << (bVar11 - 1 & 0x1f);

        }

        uVar6 = (ulonglong)(ushort)-uVar4;

        if (-1 < (char)bVar1) {

          uVar4 = -uVar4;

        }

        *(ushort *)(lVar7 + uVar12 * 2) = uVar4;

      }

    }

    else {

      if (*(short *)(param_1 + 0x22) != 7) {

        FUN_1401841e0(lVar7);

        pcVar9 = "Unknown companded encoding";

        goto LAB_14018918a;

      }

      if (uVar12 != 0) {

        do {

          bVar1 = *(byte *)(lVar7 + -1 + uVar12);

          uVar12 = uVar12 - 1;

          bVar3 = ~bVar1;

          bVar10 = bVar3 >> 4 & 7;

          sVar13 = 4 << bVar10 + 1;

          sVar14 = (ushort)(bVar3 & 0xf) * sVar13 + sVar13 / 2 + (0x80 << bVar10);

          sVar13 = 0x84 - sVar14;

          if ((char)bVar1 < '\0') {

            sVar13 = sVar14 + -0x84;

          }

          *(short *)(lVar7 + uVar12 * 2) = sVar13;

        } while (uVar12 != 0);

        *param_2 = lVar7;

        *param_3 = (int)uVar2;

        return CONCAT71((uint7)(byte)((ushort)sVar13 >> 8),1);

      }

    }

    *param_2 = lVar7;

    *param_3 = (int)uVar2;

    return CONCAT71((int7)(uVar6 >> 8),1);

  }

  pcVar9 = "WAVE file too big";

LAB_14018918a:

  uVar6 = FUN_14012e850(pcVar9);

  return uVar6;

}




