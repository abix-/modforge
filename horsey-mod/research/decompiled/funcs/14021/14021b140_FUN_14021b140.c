// Address: 0x14021b140
// Ghidra name: FUN_14021b140
// ============ 0x14021b140 FUN_14021b140 (size=605) ============


undefined8 FUN_14021b140(undefined4 *param_1,longlong param_2)



{

  undefined8 *puVar1;

  char cVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  undefined8 *puVar5;

  undefined8 *puVar6;

  longlong lVar7;

  undefined **ppuVar8;

  int iVar9;

  undefined1 local_38 [8];

  longlong local_30;

  undefined *local_28;

  longlong local_20;

  

  _guard_check_icall();

  if (*(undefined ***)(param_2 + 0x140) != &PTR_FUN_1403e4c90) {

    uVar4 = FUN_14012e850("Cannot open hidapi haptic from non hidapi joystick");

    return uVar4;

  }

  iVar9 = 0;

  ppuVar8 = &PTR_PTR_1403e5378;

  while (cVar2 = (**(code **)*ppuVar8)(param_2), cVar2 == '\0') {

    iVar9 = iVar9 + 1;

    ppuVar8 = ppuVar8 + 1;

    if (0x1403e537f < (longlong)ppuVar8) {

      uVar4 = FUN_14012e850("No supported HIDAPI haptic driver found for joystick");

      return uVar4;

    }

  }

  local_20 = (**(code **)((&PTR_PTR_1403e5378)[iVar9] + 8))(param_2);

  if (local_20 == 0) {

    return 0;

  }

  puVar5 = (undefined8 *)FUN_1401841f0(0x20);

  local_28 = (&PTR_PTR_1403e5378)[iVar9];

  if (puVar5 == (undefined8 *)0x0) {

    local_30 = param_2;

    (**(code **)(local_28 + 0x10))(local_38);

    uVar4 = FUN_14012e770();

    return uVar4;

  }

  puVar5[2] = local_28;

  *puVar5 = param_1;

  puVar5[1] = param_2;

  puVar5[3] = local_20;

  puVar6 = (undefined8 *)FUN_1401841f0(0x10);

  if (puVar6 == (undefined8 *)0x0) {

    (**(code **)(puVar5[2] + 0x10))();

    FUN_1401841e0(puVar5);

    uVar4 = FUN_14012e770();

    return uVar4;

  }

  *(undefined8 **)(param_1 + 10) = puVar5;

  uVar3 = (**(code **)(puVar5[2] + 0x18))(puVar5);

  param_1[6] = uVar3;

  uVar3 = (**(code **)(puVar5[2] + 0x20))(puVar5);

  param_1[7] = uVar3;

  uVar3 = (**(code **)(puVar5[2] + 0x28))(puVar5);

  param_1[8] = uVar3;

  uVar3 = (**(code **)(puVar5[2] + 0x30))(puVar5);

  param_1[9] = uVar3;

  iVar9 = (**(code **)(puVar5[2] + 0x18))(puVar5);

  param_1[6] = iVar9;

  lVar7 = FUN_1401841f0((longlong)iVar9 * 0x50);

  *(longlong *)(param_1 + 4) = lVar7;

  if (lVar7 == 0) {

    FUN_1401841e0(puVar6);

    (**(code **)(puVar5[2] + 0x10))(puVar5);

    FUN_1401841e0(puVar5);

    uVar4 = FUN_14012e770();

    return uVar4;

  }

  FUN_1402f94c0(lVar7,0,(longlong)(int)param_1[6] * 0x50);

  *param_1 = 0xff;

  *puVar6 = param_1;

  puVar6[1] = 0;

  uVar3 = FUN_140158720(param_2);

  FUN_140159d70(uVar3);

  FUN_140179b40(DAT_1403fdb78);

  if (DAT_1403fdb70 != (undefined8 *)0x0) {

    puVar5 = DAT_1403fdb70;

    if (DAT_1403fdb70[1] != 0) {

      puVar1 = (undefined8 *)DAT_1403fdb70[1];

      do {

        puVar5 = puVar1;

        puVar1 = (undefined8 *)puVar5[1];

      } while ((undefined8 *)puVar5[1] != (undefined8 *)0x0);

    }

    puVar5[1] = puVar6;

    puVar6 = DAT_1403fdb70;

  }

  DAT_1403fdb70 = puVar6;

  FUN_140179b60(DAT_1403fdb78);

  return 1;

}




