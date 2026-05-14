// Address: 0x1401bb0a0
// Ghidra name: FUN_1401bb0a0
// ============ 0x1401bb0a0 FUN_1401bb0a0 (size=480) ============


ulonglong FUN_1401bb0a0(longlong param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)



{

  ulonglong uVar1;

  undefined4 **ppuVar2;

  bool bVar3;

  ulonglong *puVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  undefined *puVar7;

  undefined8 local_6c8;

  undefined4 *puStack_6c0;

  undefined8 local_6b8;

  undefined4 local_6a8 [2];

  undefined4 *local_6a0;

  int local_698;

  uint local_5a4;

  ulonglong local_5a0;

  undefined4 auStack_598 [65];

  char local_494;

  undefined4 local_368 [2];

  undefined4 *local_360 [3];

  int local_348;

  

  puVar7 = &DAT_140340bc8;

  if (*(char *)(param_1 + 0x57d) != '\0') {

    puVar7 = &DAT_140340bd0;

  }

  uVar6 = 0;

  if ((*(char *)(param_3 + 2) == '\0') && (*(char *)(param_3 + 4) == '\0')) {

    uVar1 = (**(code **)(param_1 + 0x988))(param_2,local_6a8);

    bVar3 = true;

  }

  else {

    FUN_1402f94c0(local_6a8,0,0x218);

    local_368[0] = 0x3b9bb079;

    local_6b8 = 0;

    local_6c8 = 0;

    puStack_6c0 = (undefined4 *)0x0;

    ppuVar2 = local_360;

    if (*(char *)(param_3 + 2) != '\0') {

      local_360[0] = local_6a8;

      local_6a8[0] = 0x3b9dc7a0;

      ppuVar2 = &local_6a0;

    }

    if (*(char *)(param_3 + 4) != '\0') {

      local_6c8 = 0x3ba2e050;

      *ppuVar2 = (undefined4 *)&local_6c8;

      ppuVar2 = &puStack_6c0;

    }

    *ppuVar2 = (undefined4 *)0x0;

    uVar1 = (**(code **)(param_1 + 0x998))(param_2,local_368);

    bVar3 = *(char *)(param_3 + 2) == '\0' || local_494 != '\0';

    local_698 = local_348;

    if ((*(char *)(param_3 + 4) != '\0') && ((int)local_6b8 != 0)) {

      local_698 = 3;

      bVar3 = true;

    }

  }

  if (((*(char *)(param_1 + 0x57e) == '\0') ||

      (uVar1 = (ulonglong)(local_698 - 1U), local_698 - 1U < 3)) && (bVar3)) {

    uVar1 = (ulonglong)(byte)puVar7[local_698] * 1000000;

    if (*param_4 < uVar1) {

      *param_4 = uVar1;

    }

    else if (uVar1 < *param_4) {

      *param_4 = 0;

      goto LAB_1401bb27c;

    }

    if (*(char *)(param_1 + 0x57d) == '\0') {

      (**(code **)(param_1 + 0x980))(param_2,local_6a8);

      uVar1 = (ulonglong)local_5a4;

      if (local_5a4 != 0) {

        puVar4 = &local_5a0;

        uVar5 = (ulonglong)local_5a4;

        do {

          uVar1 = (ulonglong)(uint)puVar4[1];

          if (((uint)puVar4[1] & 1) != 0) {

            uVar6 = uVar6 + *puVar4;

            uVar1 = *puVar4;

          }

          puVar4 = puVar4 + 2;

          uVar5 = uVar5 - 1;

        } while (uVar5 != 0);

      }

      *param_4 = *param_4 + (uVar6 >> 0x14);

    }

    uVar1 = CONCAT71((int7)(uVar1 >> 8),1);

  }

  else {

LAB_1401bb27c:

    uVar1 = uVar1 & 0xffffffffffffff00;

  }

  return uVar1;

}




