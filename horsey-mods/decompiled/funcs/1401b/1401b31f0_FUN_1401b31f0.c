// Address: 0x1401b31f0
// Ghidra name: FUN_1401b31f0
// ============ 0x1401b31f0 FUN_1401b31f0 (size=625) ============


undefined8 FUN_1401b31f0(longlong param_1,longlong param_2,uint *param_3)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  char cVar4;

  int iVar5;

  undefined4 *puVar6;

  undefined8 uVar7;

  longlong lVar8;

  uint uVar9;

  uint uVar10;

  ulonglong uVar11;

  undefined8 local_res8;

  undefined4 local_1d8 [2];

  undefined8 local_1d0;

  undefined4 local_1c8;

  undefined4 local_1c4;

  int local_1c0;

  undefined4 *local_1b8;

  undefined4 local_1a8 [104];

  

  uVar1 = *(uint *)(param_2 + 0x10);

  if (uVar1 != 0) {

    puVar6 = local_1a8 + 1;

    uVar11 = (ulonglong)uVar1;

    do {

      puVar6[-1] = 1;

      *puVar6 = 0x80;

      puVar6 = puVar6 + 2;

      uVar11 = uVar11 - 1;

    } while (uVar11 != 0);

  }

  uVar2 = *(uint *)(param_2 + 0x18);

  uVar11 = (ulonglong)uVar2;

  uVar9 = uVar2 + uVar1;

  if (uVar1 < uVar9) {

    puVar6 = local_1a8 + (ulonglong)uVar1 * 2 + 1;

    do {

      puVar6[-1] = 2;

      *puVar6 = 0x80;

      puVar6 = puVar6 + 2;

      uVar11 = uVar11 - 1;

    } while (uVar11 != 0);

  }

  iVar5 = *(int *)(param_2 + 0x14);

  uVar10 = iVar5 + uVar2 + uVar1;

  if (uVar9 < uVar10) {

    puVar6 = local_1a8 + (ulonglong)uVar9 * 2 + 1;

    uVar11 = (ulonglong)(uVar10 - uVar9);

    do {

      puVar6[-1] = 7;

      *puVar6 = 0x80;

      puVar6 = puVar6 + 2;

      uVar11 = uVar11 - 1;

    } while (uVar11 != 0);

  }

  uVar9 = *(uint *)(param_2 + 0x20);

  if (uVar9 != 0) {

    puVar6 = local_1a8 + 1;

    uVar11 = (ulonglong)uVar9;

    do {

      puVar6[-1] = 3;

      *puVar6 = 0x80;

      puVar6 = puVar6 + 2;

      uVar11 = uVar11 - 1;

    } while (uVar11 != 0);

  }

  uVar10 = *(uint *)(param_2 + 0x1c);

  uVar11 = (ulonglong)uVar10;

  if (uVar9 < uVar10 + uVar9) {

    puVar6 = local_1a8 + (ulonglong)uVar9 * 2 + 1;

    do {

      puVar6[-1] = 7;

      *puVar6 = 0x80;

      puVar6 = puVar6 + 2;

      uVar11 = uVar11 - 1;

    } while (uVar11 != 0);

  }

  uVar3 = *(uint *)(param_2 + 0x24);

  if (uVar3 != 0) {

    puVar6 = local_1a8 + 1;

    uVar11 = (ulonglong)uVar3;

    do {

      puVar6[-1] = 8;

      *puVar6 = 0x80;

      puVar6 = puVar6 + 2;

      uVar11 = uVar11 - 1;

    } while (uVar11 != 0);

  }

  local_1d0 = 0;

  local_1c8 = 0;

  local_1d8[0] = 0x21;

  local_1c4 = 0x80;

  local_1c0 = uVar3 + uVar10 + iVar5 + uVar1 + uVar9 + uVar2;

  local_1b8 = local_1a8;

  iVar5 = (**(code **)(param_1 + 0xb00))(*(undefined8 *)(param_1 + 0x570),local_1d8,0,&local_res8);

  if (iVar5 == 0) {

    *param_3 = *param_3 + 1;

    lVar8 = FUN_140184230(*(undefined8 *)(param_3 + 2),(ulonglong)*param_3 << 3);

    *(longlong *)(param_3 + 2) = lVar8;

    *(undefined8 *)(lVar8 + (ulonglong)(*param_3 - 1) * 8) = local_res8;

    lVar8 = FUN_140184230(*(undefined8 *)(param_3 + 4),(ulonglong)*param_3 << 10);

    *(longlong *)(param_3 + 4) = lVar8;

    cVar4 = FUN_1401b2fa0(param_1,local_res8,*(undefined8 *)(param_2 + 8),0x80,

                          lVar8 + (ulonglong)param_3[6] * 8);

    if (cVar4 != '\0') {

      param_3[6] = param_3[6] + 0x80;

      return 1;

    }

  }

  else {

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar7 = FUN_1401c0ba0(iVar5);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkCreateDescriptorPool",uVar7);

    }

    uVar7 = FUN_1401c0ba0(iVar5);

    FUN_14012e850("%s %s","vkCreateDescriptorPool",uVar7);

  }

  return 0;

}




