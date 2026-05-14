// Address: 0x140226b40
// Ghidra name: FUN_140226b40
// ============ 0x140226b40 FUN_140226b40 (size=557) ============


ulonglong FUN_140226b40(longlong param_1,HMONITOR param_2,undefined8 *param_3)



{

  undefined8 *puVar1;

  undefined8 uVar2;

  BOOL BVar3;

  int iVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  uint uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  byte local_res8;

  uint local_res20 [2];

  uint local_118 [4];

  undefined4 local_108;

  undefined4 local_104;

  undefined8 local_100;

  undefined4 local_f8;

  undefined8 local_f4;

  undefined8 uStack_ec;

  undefined8 local_e4;

  undefined8 uStack_dc;

  undefined8 local_d4;

  undefined8 uStack_cc;

  undefined8 local_c4;

  undefined8 uStack_bc;

  undefined1 local_a8 [40];

  undefined1 auStack_80 [4];

  undefined8 uStack_7c;

  undefined8 local_74;

  undefined8 uStack_6c;

  undefined8 local_64;

  undefined8 uStack_5c;

  undefined8 local_54;

  undefined8 uStack_4c;

  undefined4 local_44;

  

  uVar7 = 0;

  local_res20[0] = 0;

  local_118[0] = 0;

  local_res8 = 0;

  if (((*(longlong *)(param_1 + 0x18) == 0) || (*(longlong *)(param_1 + 0x20) == 0)) ||

     (*(longlong *)(param_1 + 0x28) == 0)) {

    return (ulonglong)param_2 & 0xffffffffffffff00;

  }

  local_a8._0_4_ = 0x68;

  local_44 = 0;

  local_a8._4_4_ = 0;

  local_a8._8_4_ = 0;

  local_a8._12_4_ = 0;

  local_a8._16_4_ = 0;

  local_a8._20_4_ = 0;

  local_a8._24_4_ = 0;

  local_a8._28_4_ = 0;

  local_a8._32_4_ = 0;

  stack0xffffffffffffff7c = 0;

  uStack_7c = 0;

  local_74 = 0;

  uStack_6c = 0;

  local_64 = 0;

  uStack_5c = 0;

  local_54 = 0;

  uStack_4c = 0;

  BVar3 = GetMonitorInfoW(param_2,(LPMONITORINFO)local_a8);

  uVar9 = uVar7;

  uVar10 = uVar7;

  if (BVar3 != 0) {

    do {

      iVar4 = (**(code **)(param_1 + 0x18))(2,local_res20,local_118);

      if (iVar4 != 0) {

        FUN_1401841e0(uVar10);

        uVar7 = FUN_1401841e0(uVar9);

        return uVar7 & 0xffffffffffffff00;

      }

      uVar5 = FUN_140184230(uVar10,(ulonglong)local_res20[0] * 0x48);

      if ((uVar5 == 0) ||

         (uVar6 = FUN_140184230(uVar9,(ulonglong)local_118[0] << 6), uVar10 = uVar5, uVar6 == 0))

      goto LAB_140226ce6;

      iVar4 = (**(code **)(param_1 + 0x20))(2,local_res20,uVar5,local_118,uVar6,0);

      uVar9 = uVar6;

    } while (iVar4 == 0x7a);

    if ((iVar4 == 0) && (local_res20[0] != 0)) {

      do {

        local_f4 = 0;

        uStack_ec = 0;

        local_108 = 1;

        local_e4 = 0;

        uStack_dc = 0;

        local_104 = 0x54;

        local_100 = *(undefined8 *)(uVar5 + uVar7 * 0x48);

        puVar1 = (undefined8 *)(uVar5 + uVar7 * 0x48);

        local_f8 = *(undefined4 *)(puVar1 + 1);

        local_d4 = 0;

        uStack_cc = 0;

        local_c4 = 0;

        uStack_bc = 0;

        iVar4 = (**(code **)(param_1 + 0x28))(&local_108);

        if ((iVar4 == 0) && (iVar4 = FUN_14012fbc0(auStack_80,&local_f4), iVar4 == 0)) {

          uVar2 = puVar1[1];

          local_res8 = 1;

          *param_3 = *puVar1;

          param_3[1] = uVar2;

          uVar2 = puVar1[3];

          param_3[2] = puVar1[2];

          param_3[3] = uVar2;

          uVar2 = puVar1[5];

          param_3[4] = puVar1[4];

          param_3[5] = uVar2;

          uVar2 = puVar1[7];

          param_3[6] = puVar1[6];

          param_3[7] = uVar2;

          param_3[8] = puVar1[8];

          break;

        }

        uVar8 = (int)uVar7 + 1;

        uVar7 = (ulonglong)uVar8;

      } while (uVar8 < local_res20[0]);

    }

  }

LAB_140226ce6:

  FUN_1401841e0(uVar10);

  FUN_1401841e0(uVar9);

  return (ulonglong)local_res8;

}




