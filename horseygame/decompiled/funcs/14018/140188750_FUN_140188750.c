// Address: 0x140188750
// Ghidra name: FUN_140188750
// ============ 0x140188750 FUN_140188750 (size=670) ============


undefined8 FUN_140188750(longlong param_1,longlong *param_2,undefined4 *param_3)



{

  ushort uVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  undefined8 uVar6;

  char *pcVar7;

  longlong lVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  ulonglong uVar15;

  ulonglong local_res20;

  ulonglong local_e8;

  ulonglong uStack_e0;

  ulonglong local_d8;

  ulonglong uStack_d0;

  longlong local_c8;

  ulonglong uStack_c0;

  ulonglong local_b8;

  undefined8 uStack_b0;

  longlong local_a8;

  longlong lStack_a0;

  ulonglong local_98;

  longlong lStack_90;

  longlong local_88;

  ulonglong uStack_80;

  undefined8 local_78;

  longlong lStack_70;

  ulonglong local_68;

  ulonglong uStack_60;

  longlong local_58;

  

  if ((*(ulonglong *)(param_1 + 0x18) == (ulonglong)*(uint *)(param_1 + 4)) ||

     (cVar2 = FUN_140188680(), cVar2 != '\0')) {

    uVar10 = *(ulonglong *)(param_1 + 0x58);

    if (uVar10 == 0) {

      *param_2 = 0;

      *param_3 = 0;

      return 1;

    }

    uVar1 = *(ushort *)(param_1 + 0x24);

    uVar13 = (ulonglong)uVar1;

    uStack_d0 = (ulonglong)*(uint *)(param_1 + 0x38);

    uVar14 = (ulonglong)*(ushort *)(param_1 + 0x30);

    uVar9 = *(ulonglong *)(param_1 + 0x18);

    local_c8 = uVar13 * 2;

    lStack_a0 = *(longlong *)(param_1 + 0x10);

    uVar12 = uVar13 * 4;

    lVar8 = 0;

    lStack_90 = 0;

    uStack_b0 = 0;

    local_e8 = (ulonglong)(uint)uVar1;

    local_a8 = 0;

    local_88 = 0;

    uStack_80 = 0;

    local_78 = 0;

    lStack_70 = 0;

    local_68 = 0;

    uStack_60 = 0;

    local_res20 = uVar10;

    uStack_e0 = uVar14;

    local_d8 = uVar12;

    uStack_c0 = uVar10;

    local_b8 = uVar10;

    local_98 = uVar9;

    local_58 = lStack_a0;

    iVar3 = FUN_14018a0b0(&local_res20);

    if ((iVar3 != 0) || (0xffffffff < local_res20)) {

      pcVar7 = "WAVE file too big";

LAB_1401889d5:

      uVar6 = FUN_14012e850(pcVar7);

      return uVar6;

    }

    uStack_60 = 0;

    uVar15 = local_res20 >> 1;

    local_68 = uVar15;

    lStack_70 = FUN_1401841f0(local_res20);

    if (lStack_70 != 0) {

      lVar4 = FUN_1401841a0((uint)uVar1);

      if (lVar4 != 0) {

        lVar5 = local_58;

        uVar11 = local_res20;

        local_a8 = lVar4;

        if (0 < (longlong)uVar10) {

          while (uVar11 = local_res20, uVar12 <= uVar9) {

            local_88 = lVar5 + lVar8;

            local_78 = 0;

            uStack_80 = uVar14;

            if (uVar9 < uVar14) {

              uStack_80 = uVar9;

            }

            if (uVar15 - uStack_60 < uVar13 * uVar10) {

              FUN_1401841e0(lStack_70);

              FUN_1401841e0(lVar4);

              pcVar7 = "Unexpected overflow in IMA ADPCM decoder";

              goto LAB_1401889d5;

            }

            cVar2 = FUN_140188bf0(&local_e8);

            if ((cVar2 == '\0') || (cVar2 = FUN_1401889f0(&local_e8), cVar2 == '\0')) {

              iVar3 = *(int *)(param_1 + 0x6c);

              if ((iVar3 == 1) || (iVar3 == 2)) {

                FUN_1401841e0(lStack_70);

                FUN_1401841e0(lVar4);

                pcVar7 = "Truncated data chunk";

                goto LAB_1401889d5;

              }

              uVar10 = uStack_60;

              if (iVar3 != 3) {

                uVar10 = uStack_60 - uStack_60 % ((local_e8 & 0xffffffff) * uStack_d0);

              }

              uVar11 = uVar10 * 2;

              break;

            }

            lVar8 = lStack_90 + uStack_80;

            uVar9 = local_98 - lVar8;

            uVar11 = local_res20;

            lStack_90 = lVar8;

            if ((longlong)local_b8 < 1) break;

            uVar13 = local_e8 & 0xffffffff;

            lVar5 = lStack_a0;

            uVar10 = local_b8;

            uVar12 = local_d8;

            uVar14 = uStack_e0;

            uVar15 = local_68;

          }

        }

        *param_2 = lStack_70;

        *param_3 = (int)uVar11;

        FUN_1401841e0(lVar4);

        return 1;

      }

      FUN_1401841e0(lStack_70);

    }

  }

  return 0;

}




