// Address: 0x140189320
// Ghidra name: FUN_140189320
// ============ 0x140189320 FUN_140189320 (size=643) ============


undefined8 FUN_140189320(longlong param_1,longlong *param_2,int *param_3)



{

  ushort uVar1;

  char cVar2;

  int iVar3;

  undefined8 uVar4;

  char *pcVar5;

  longlong lVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  ulonglong local_res20;

  longlong lVar12;

  ulonglong local_f0;

  uint local_e8 [2];

  ulonglong local_e0;

  ulonglong local_d8;

  ulonglong local_d0;

  longlong local_c8;

  ulonglong uStack_c0;

  ulonglong local_b8;

  undefined8 local_b0;

  undefined8 *local_a8;

  longlong local_a0;

  ulonglong local_98;

  longlong local_90;

  longlong lStack_88;

  ulonglong local_80;

  undefined8 uStack_78;

  longlong local_70;

  ulonglong local_68;

  ulonglong local_60;

  undefined8 local_58;

  undefined4 local_50;

  

  local_e8[1] = 0;

  local_58 = 0;

  local_50 = 0;

  local_c8 = 0;

  uStack_c0 = 0;

  local_90 = 0;

  lStack_88 = 0;

  local_80 = 0;

  uStack_78 = 0;

  if ((*(ulonglong *)(param_1 + 0x18) == (ulonglong)*(uint *)(param_1 + 4)) ||

     (cVar2 = FUN_140189250(), cVar2 != '\0')) {

    uVar7 = *(ulonglong *)(param_1 + 0x58);

    if (uVar7 == 0) {

      *param_2 = 0;

      *param_3 = 0;

      return 1;

    }

    local_f0 = (ulonglong)*(ushort *)(param_1 + 0x24);

    local_d0 = (ulonglong)*(uint *)(param_1 + 0x38);

    uVar1 = *(ushort *)(param_1 + 0x30);

    uVar8 = *(ulonglong *)(param_1 + 0x18);

    local_c8 = local_f0 * 2;

    local_b0 = *(undefined8 *)(param_1 + 0x60);

    lVar12 = *(longlong *)(param_1 + 0x10);

    lVar6 = 0;

    local_e8[0] = (uint)*(ushort *)(param_1 + 0x24);

    local_90 = 0;

    local_res20 = uVar7;

    local_e0 = (ulonglong)uVar1;

    local_d8 = local_f0 * 7;

    uStack_c0 = uVar7;

    local_b8 = uVar7;

    local_a0 = lVar12;

    local_98 = uVar8;

    iVar3 = FUN_14018a0b0(&local_res20,local_c8,param_3,param_2,lVar12);

    if ((iVar3 != 0) || (0xffffffff < local_res20)) {

      pcVar5 = "WAVE file too big";

LAB_14018958a:

      uVar4 = FUN_14012e850(pcVar5);

      return uVar4;

    }

    uVar11 = local_res20 >> 1;

    local_60 = 0;

    local_68 = uVar11;

    local_70 = FUN_1401841a0(1);

    if (local_70 != 0) {

      local_a8 = &local_58;

      uVar9 = local_f0 * 7;

      uVar10 = 0;

      local_80 = (ulonglong)uVar1;

      if (0 < (longlong)uVar7) {

        while (uVar9 <= uVar8) {

          lStack_88 = lVar12 + lVar6;

          uStack_78 = 0;

          if (uVar8 < local_80) {

            local_80 = uVar8;

          }

          if (uVar11 - uVar10 < local_f0 * uVar7) {

            FUN_1401841e0(local_70);

            pcVar5 = "Unexpected overflow in MS ADPCM decoder";

            goto LAB_14018958a;

          }

          cVar2 = FUN_1401896e0(local_e8);

          if (cVar2 == '\0') {

            FUN_1401841e0(local_70);

            return 0;

          }

          cVar2 = FUN_1401895b0(local_e8);

          if (cVar2 == '\0') {

            iVar3 = *(int *)(param_1 + 0x6c);

            if ((iVar3 == 1) || (iVar3 == 2)) {

              FUN_1401841e0(local_70);

              pcVar5 = "Truncated data chunk";

              goto LAB_14018958a;

            }

            if (iVar3 != 3) {

              local_60 = local_60 - local_60 % (local_e8[0] * local_d0);

            }

            iVar3 = (int)local_60 * 2;

            goto LAB_14018956d;

          }

          lVar6 = local_90 + local_80;

          uVar8 = local_98 - lVar6;

          if ((longlong)local_b8 < 1) break;

          local_f0 = (ulonglong)local_e8[0];

          uVar7 = local_b8;

          uVar9 = local_d8;

          uVar10 = local_60;

          local_80 = local_e0;

          uVar11 = local_68;

          lVar12 = local_a0;

          local_90 = lVar6;

        }

      }

      iVar3 = (int)local_res20;

LAB_14018956d:

      *param_2 = local_70;

      *param_3 = iVar3;

      return 1;

    }

  }

  return 0;

}




