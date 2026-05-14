// Address: 0x1402cc3e0
// Ghidra name: FUN_1402cc3e0
// ============ 0x1402cc3e0 FUN_1402cc3e0 (size=752) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_1402cc3e0(longlong *param_1,longlong param_2,longlong param_3,undefined4 param_4)



{

  int *piVar1;

  undefined1 auVar2 [16];

  UWMap4 *pUVar3;

  byte *pbVar4;

  int iVar5;

  longlong lVar6;

  uint uVar7;

  longlong *plVar8;

  longlong lVar9;

  undefined1 auStack_138 [32];

  UWMap4 **local_118;

  UWMap4 *local_108;

  byte *pbStack_100;

  int local_f8;

  int local_f4;

  undefined4 local_f0;

  UWMap4 *local_e8;

  byte *local_e0;

  longlong *local_d8;

  undefined8 local_d0;

  int *local_c8;

  longlong *local_c0;

  longlong *local_b8;

  uint *local_b0;

  byte *local_a8;

  UWMap4 *local_98;

  byte *pbStack_90;

  undefined1 local_88 [16];

  uint local_78 [2];

  byte *local_70;

  undefined8 local_68;

  undefined8 uStack_60;

  ulonglong local_58;

  

  local_58 = DAT_1403e8b00 ^ (ulonglong)auStack_138;

  local_f0 = param_4;

  local_d8 = param_1;

  local_c0 = param_1;

  local_d0 = FUN_1402c8e50();

  iVar5 = FUN_1402c9a44(param_3);

  piVar1 = (int *)(param_2 + 0x48);

  local_c8 = piVar1;

  if (*piVar1 == 0) {

    lVar6 = FUN_1402c97f8();

    if (*(int *)(lVar6 + 0x78) != -2) {

      lVar6 = FUN_1402c97f8();

      iVar5 = *(int *)(lVar6 + 0x78);

      lVar6 = FUN_1402c97f8();

      *(undefined4 *)(lVar6 + 0x78) = 0xfffffffe;

    }

  }

  else {

    lVar6 = FUN_1402c97f8();

    if (*(int *)(lVar6 + 0x78) != -2) {

                    /* WARNING: Subroutine does not return */

      FUN_1402e1bf8();

    }

    iVar5 = *piVar1 + -2;

  }

  lVar6 = FUN_1402c97f8();

  *(int *)(lVar6 + 0x30) = *(int *)(lVar6 + 0x30) + 1;

  plVar8 = (longlong *)(param_2 + 8);

  local_70 = (byte *)0x0;

  local_68 = 0;

  uStack_60 = 0;

  if (*(int *)(param_3 + 8) == 0) {

    local_78[0] = 0;

  }

  else {

    local_70 = (byte *)((longlong)*(int *)(param_3 + 8) + *plVar8);

    uVar7 = *local_70 & 0xf;

    local_70 = local_70 + -(longlong)(char)(&DAT_1403872c0)[uVar7];

    local_78[0] = *(uint *)(local_70 + -4) >> ((&DAT_1403872d0)[uVar7] & 0x1f);

  }

  local_108 = (UWMap4 *)local_78;

  local_e8 = (UWMap4 *)local_78;

  local_118 = &local_e8;

  pbStack_100 = local_70;

  local_e0 = local_70;

  local_b8 = plVar8;

  FUN_1402cc9b0(local_78,iVar5,param_4,&local_108);

  while( true ) {

    pbVar4 = pbStack_100;

    local_b0 = local_78;

    local_a8 = local_70;

    if ((pbStack_100 < local_70) || (pbStack_100 <= local_e0)) break;

    FH4::UWMap4::ReadEntry(local_108,&pbStack_100);

    pUVar3 = local_108;

    auVar2 = *(undefined1 (*) [16])(local_108 + 0x10);

    local_98 = local_108;

    pbStack_90 = pbVar4;

    pbStack_100 = pbVar4;

    local_88 = auVar2;

    FH4::UWMap4::ReadEntry(local_108,&pbStack_100);

    pbStack_100 = pbVar4 + -(ulonglong)*(uint *)(pUVar3 + 0x10);

    local_118 = &local_108;

    local_f4 = FUN_1402cca80(&local_e8,param_4,&local_98);

    iVar5 = auVar2._4_4_;

    local_f8 = 0;

    if (iVar5 != 0) {

      local_f8 = auVar2._8_4_;

    }

    if (local_f8 != 0) {

      *piVar1 = local_f4 + 2;

      if (iVar5 - 1U < 2) {

        lVar6 = *local_d8;

        if (iVar5 == 2) {

          lVar9 = *(longlong *)((ulonglong)auVar2._12_4_ + lVar6);

        }

        else {

          lVar9 = (ulonglong)auVar2._12_4_ + lVar6;

        }

        _CallSettingFrameEncoded((longlong)local_f8 + *plVar8,lVar6,lVar9,0x103);

      }

      else {

        _CallSettingFrame((longlong)local_f8 + *plVar8,param_1,0x103);

      }

      FUN_1402c8e78(local_d0);

    }

  }

  lVar6 = FUN_1402c97f8();

  if (0 < *(int *)(lVar6 + 0x30)) {

    lVar6 = FUN_1402c97f8();

    *(int *)(lVar6 + 0x30) = *(int *)(lVar6 + 0x30) + -1;

  }

  return;

}




