// Address: 0x1402d7d00
// Ghidra name: FUN_1402d7d00
// ============ 0x1402d7d00 FUN_1402d7d00 (size=593) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



ulonglong FUN_1402d7d00(ulonglong param_1,undefined1 *param_2,ulonglong param_3,longlong param_4,

                       undefined4 *param_5,undefined8 param_6)



{

  int iVar1;

  longlong lVar2;

  ulonglong uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  undefined1 auStack_548 [32];

  undefined8 local_528;

  longlong *local_520;

  undefined1 *local_518;

  ulonglong local_510;

  ulonglong local_508;

  undefined1 local_500;

  undefined4 local_4ff;

  undefined2 local_4fb;

  undefined1 local_4f9;

  longlong local_4f8 [2];

  undefined1 local_4e8;

  undefined4 local_4e0;

  undefined4 uStack_4dc;

  undefined4 uStack_4d8;

  undefined4 uStack_4d4;

  char local_4d0;

  undefined4 local_4cc;

  char local_4c8;

  undefined4 local_4c4;

  char local_4c0;

  ulonglong local_4b8;

  longlong *local_4b0;

  longlong local_4a8;

  undefined8 local_4a0;

  undefined4 local_498;

  undefined1 local_494;

  undefined8 local_490;

  undefined4 local_488;

  undefined2 local_480;

  undefined4 local_470;

  undefined1 local_46c;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined1 **local_58;

  undefined4 local_50;

  ulonglong local_48;

  

  local_48 = DAT_1403e8b00 ^ (ulonglong)auStack_548;

  local_4f8[0] = 0;

  local_4e8 = 0;

  local_4d0 = '\0';

  local_4c8 = '\0';

  local_4c0 = '\0';

  if (param_5 == (undefined4 *)0x0) {

    uVar4 = PTR_PTR_1403e8e88._0_4_;

    uVar5 = PTR_PTR_1403e8e88._4_4_;

    uVar6 = PTR_DAT_1403e8e90._0_4_;

    uVar7 = PTR_DAT_1403e8e90._4_4_;

    if (DAT_1403ff13c == 0) goto LAB_1402d7d6f;

  }

  else {

    uVar4 = *param_5;

    uVar5 = param_5[1];

    uVar6 = param_5[2];

    uVar7 = param_5[3];

LAB_1402d7d6f:

    local_4d0 = '\x01';

    local_4e0 = uVar4;

    uStack_4dc = uVar5;

    uStack_4d8 = uVar6;

    uStack_4d4 = uVar7;

  }

  if ((param_4 == 0) || ((param_3 != 0 && (param_2 == (undefined1 *)0x0)))) {

    local_520 = local_4f8;

    local_4c8 = '\x01';

    local_528 = 0;

    local_4cc = 0x16;

    FUN_1402cd39c(0,0,0,0);

  }

  else {

    local_4ff = 0;

    local_4fb = 0;

    local_4f9 = 0;

    local_508 = 0;

    if (((param_1 & 2) != 0) || (local_500 = 0, param_2 == (undefined1 *)0x0)) {

      local_500 = 1;

    }

    local_4b0 = local_4f8;

    local_498 = 0;

    local_58 = &local_518;

    local_494 = 0;

    local_4a0 = param_6;

    local_490 = 0;

    local_488 = 0;

    local_480 = 0;

    local_470 = 0;

    local_46c = 0;

    local_68 = 0;

    uStack_60 = 0;

    local_50 = 0;

    local_518 = param_2;

    local_510 = param_3;

    local_4b8 = param_1;

    local_4a8 = param_4;

    iVar1 = FUN_1402d4650(&local_4b8);

    uVar3 = (ulonglong)iVar1;

    if (param_2 == (undefined1 *)0x0) {

LAB_1402d7ee2:

      FUN_1402e9a80(uStack_60);

      goto LAB_1402d7eee;

    }

    if ((param_1 & 1) == 0) {

      if ((param_1 & 2) != 0) {

        if (param_3 != 0) {

          if (iVar1 < 0) {

            *param_2 = 0;

          }

          else {

            if (local_508 != param_3) goto LAB_1402d7ede;

            param_2[param_3 - 1] = 0;

          }

        }

        goto LAB_1402d7ee2;

      }

      if (param_3 != 0) {

        if (local_508 == param_3) {

          param_2[param_3 - 1] = 0;

          FUN_1402e9a80(uStack_60);

          uVar3 = 0xfffffffe;

          goto LAB_1402d7eee;

        }

        goto LAB_1402d7ede;

      }

    }

    else if ((param_3 != 0) || (iVar1 == 0)) {

      if (local_508 != param_3) {

LAB_1402d7ede:

        param_2[local_508] = 0;

        goto LAB_1402d7ee2;

      }

      if ((iVar1 < 0) || (uVar3 <= param_3)) goto LAB_1402d7ee2;

    }

    FUN_1402e9a80(uStack_60);

  }

  uVar3 = 0xffffffff;

LAB_1402d7eee:

  uVar4 = local_4cc;

  if (local_4d0 == '\x02') {

    *(uint *)(local_4f8[0] + 0x3a8) = *(uint *)(local_4f8[0] + 0x3a8) & 0xfffffffd;

  }

  if (local_4c8 != '\0') {

    lVar2 = FUN_1402cd068(local_4f8);

    *(undefined4 *)(lVar2 + 0x20) = uVar4;

  }

  if (local_4c0 != '\0') {

    lVar2 = FUN_1402cd068(local_4f8);

    *(undefined4 *)(lVar2 + 0x24) = local_4c4;

  }

  return uVar3 & 0xffffffff;

}




