// Address: 0x1401c7fa0
// Ghidra name: FUN_1401c7fa0
// ============ 0x1401c7fa0 FUN_1401c7fa0 (size=1530) ============


undefined8 * FUN_1401c7fa0(longlong param_1,longlong param_2,longlong param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  undefined8 *puVar4;

  ulonglong uVar5;

  undefined8 uVar6;

  undefined8 uVar7;

  uint uVar8;

  ulonglong uVar9;

  char *pcVar10;

  int iVar11;

  ulonglong uVar12;

  ulonglong uVar13;

  longlong *local_res20;

  undefined8 uStack_d80;

  undefined8 local_d78;

  longlong *local_d68;

  undefined8 local_d60;

  uint local_d58 [2];

  undefined8 *local_d50;

  undefined4 local_d48;

  undefined8 local_d40;

  undefined4 local_d38;

  int local_d28 [320];

  undefined8 local_828;

  int aiStack_820 [2];

  undefined8 local_818;

  undefined8 uStack_810;

  undefined8 local_808;

  undefined8 uStack_800;

  undefined8 local_7f8;

  undefined4 uStack_7f0;

  undefined4 uStack_7ec;

  

  uVar9 = 0;

  puVar4 = (undefined8 *)FUN_1401841a0(1,0x48);

  if (puVar4 == (undefined8 *)0x0) {

    return (undefined8 *)0x0;

  }

  FUN_1402f94c0(&local_828,0,0x800);

  FUN_1402f94c0(local_d28,0,0x500);

  puVar4[1] = 0xffffffffffffffff;

  puVar4[2] = 0xffffffffffffffff;

  puVar4[5] = 0xffffffffffffffff;

  puVar4[6] = 0xffffffffffffffff;

  puVar4[3] = 0xffffffffffffffff;

  puVar4[7] = 0xffffffffffffffff;

  puVar4[4] = 0xffffffffffffffff;

  puVar4[8] = 0xffffffffffffffff;

  iVar3 = *(int *)(param_2 + 0x14);

  local_d78 = (int *)0x0;

  uVar12 = uVar9;

  local_7f8 = (int *)CONCAT44(local_7f8._4_4_,(undefined4)local_7f8);

  if (iVar3 != 0) {

    uVar12 = 2;

    local_818 = local_d28;

    local_d28[0] = 3;

    local_d28[2] = 0;

    local_d28[3] = 0;

    uStack_810 = 1;

    local_d28[4] = 0xffffffff;

    local_828 = 0;

    aiStack_820[0] = 1;

    aiStack_820[1] = 0;

    *(undefined4 *)(puVar4 + 1) = 0;

    local_d28[6] = *(undefined4 *)(param_2 + 0x14);

    local_d78 = local_d28 + 5;

    local_d28[5] = 0;

    local_d28[7] = 0;

    local_d28[8] = 0;

    uStack_7f0 = 1;

    uStack_7ec = 0;

    local_d28[9] = 0xffffffff;

    local_808 = 0;

    uStack_800 = 1;

    *(undefined4 *)((longlong)puVar4 + 0xc) = 1;

    local_d28[1] = iVar3;

    local_7f8 = local_d78;

  }

  iVar3 = *(int *)(param_2 + 0x20);

  if (iVar3 != 0) {

    iVar11 = *(int *)(param_2 + 0x14);

    local_d28[uVar12 * 5] = 0;

    local_d78 = local_d28 + uVar12 * 5;

    local_d28[uVar12 * 5 + 1] = iVar3;

    local_d28[uVar12 * 5 + 2] = iVar11;

    local_d28[uVar12 * 5 + 3] = 0;

    local_d28[uVar12 * 5 + 4] = -1;

    *(undefined4 *)(&local_828 + uVar12 * 4) = 0;

    *(undefined4 *)((longlong)&local_828 + uVar12 * 0x20 + 4) = 0;

    aiStack_820[uVar12 * 8] = 1;

    aiStack_820[uVar12 * 8 + 1] = 0;

    (&local_818)[uVar12 * 4] = local_d78;

    (&uStack_810)[uVar12 * 4] = 1;

    *(int *)(puVar4 + 2) = (int)uVar12;

    uVar12 = (ulonglong)((int)uVar12 + 1);

  }

  iVar3 = *(int *)(param_2 + 0x1c);

  if (iVar3 != 0) {

    iVar11 = *(int *)(param_2 + 0x20);

    iVar2 = *(int *)(param_2 + 0x14);

    local_d28[uVar12 * 5] = 0;

    local_d78 = local_d28 + uVar12 * 5;

    local_d28[uVar12 * 5 + 1] = iVar3;

    local_d28[uVar12 * 5 + 2] = iVar11 + iVar2;

    local_d28[uVar12 * 5 + 3] = 0;

    local_d28[uVar12 * 5 + 4] = -1;

    *(undefined4 *)(&local_828 + uVar12 * 4) = 0;

    *(undefined4 *)((longlong)&local_828 + uVar12 * 0x20 + 4) = 0;

    aiStack_820[uVar12 * 8] = 1;

    aiStack_820[uVar12 * 8 + 1] = 0;

    (&local_818)[uVar12 * 4] = local_d78;

    (&uStack_810)[uVar12 * 4] = 1;

    *(int *)((longlong)puVar4 + 0x14) = (int)uVar12;

    uVar12 = (ulonglong)((int)uVar12 + 1);

  }

  uStack_d80 = 0;

  uVar5 = uVar9;

  uVar13 = uVar12;

  if (*(int *)(param_2 + 0x18) != 0) {

    do {

      iVar3 = (int)uVar5;

      uStack_d80 = CONCAT44(1,iVar3);

      *(undefined4 *)(&local_828 + uVar13 * 4) = 2;

      *(undefined4 *)((longlong)&local_828 + uVar13 * 0x20 + 4) = 0;

      aiStack_820[uVar13 * 8] = iVar3;

      aiStack_820[uVar13 * 8 + 1] = 1;

      (&local_818)[uVar13 * 4] = local_d78;

      (&uStack_810)[uVar13 * 4] = 1;

      *(int *)((longlong)puVar4 + uVar5 * 4 + 0x18) = (int)uVar13;

      uVar13 = (ulonglong)((int)uVar13 + 1);

      uVar5 = (ulonglong)(iVar3 + 1U);

    } while (iVar3 + 1U < *(uint *)(param_2 + 0x18));

  }

  iVar3 = *(int *)(param_3 + 0x14);

  if (iVar3 != 0) {

    local_d28[uVar12 * 5] = 3;

    local_d28[uVar12 * 5 + 1] = iVar3;

    local_d28[uVar12 * 5 + 2] = 0;

    local_d28[uVar12 * 5 + 3] = 2;

    local_d28[uVar12 * 5 + 4] = -1;

    uStack_d80 = CONCAT44(uStack_d80._4_4_,1);

    iVar11 = (int)uVar13;

    uVar5 = (ulonglong)((int)uVar12 + 1);

    (&local_828)[uVar13 * 4] = 0;

    *(undefined8 *)(aiStack_820 + uVar13 * 8) = uStack_d80;

    (&local_818)[uVar13 * 4] = local_d28 + uVar12 * 5;

    (&uStack_810)[uVar13 * 4] = 5;

    *(int *)(puVar4 + 5) = iVar11;

    iVar3 = *(int *)(param_3 + 0x14);

    piVar1 = local_d28 + uVar5 * 5;

    *piVar1 = 0;

    local_d28[uVar5 * 5 + 1] = iVar3;

    local_d28[uVar5 * 5 + 2] = 0;

    local_d28[uVar5 * 5 + 3] = 2;

    local_d28[uVar5 * 5 + 4] = -1;

    local_d78._0_4_ = SUB84(piVar1,0);

    local_d78._4_4_ = (undefined4)((ulonglong)piVar1 >> 0x20);

    uVar5 = (ulonglong)(iVar11 + 1U);

    uVar12 = (ulonglong)((int)uVar12 + 2);

    uVar13 = (ulonglong)(iVar11 + 2);

    (&local_828)[uVar5 * 4] = 0;

    *(undefined8 *)(aiStack_820 + uVar5 * 8) = uStack_d80;

    *(undefined4 *)(&local_818 + uVar5 * 4) = (undefined4)local_d78;

    *(undefined4 *)((longlong)&local_818 + uVar5 * 0x20 + 4) = local_d78._4_4_;

    *(undefined4 *)(&uStack_810 + uVar5 * 4) = 5;

    *(undefined4 *)((longlong)&uStack_810 + uVar5 * 0x20 + 4) = 0;

    *(uint *)((longlong)puVar4 + 0x2c) = iVar11 + 1U;

    local_d78 = piVar1;

  }

  iVar3 = *(int *)(param_3 + 0x20);

  uVar5 = uVar12;

  if (iVar3 != 0) {

    iVar11 = *(int *)(param_3 + 0x14);

    uVar5 = (ulonglong)((int)uVar12 + 1);

    local_d28[uVar12 * 5] = 0;

    local_d78 = local_d28 + uVar12 * 5;

    local_d28[uVar12 * 5 + 1] = iVar3;

    local_d28[uVar12 * 5 + 2] = iVar11;

    local_d28[uVar12 * 5 + 3] = 2;

    local_d28[uVar12 * 5 + 4] = -1;

    *(undefined4 *)(&local_828 + uVar13 * 4) = 0;

    *(undefined4 *)((longlong)&local_828 + uVar13 * 0x20 + 4) = 0;

    aiStack_820[uVar13 * 8] = 1;

    aiStack_820[uVar13 * 8 + 1] = uStack_d80._4_4_;

    (&local_818)[uVar13 * 4] = local_d78;

    (&uStack_810)[uVar13 * 4] = 5;

    *(int *)(puVar4 + 6) = (int)uVar13;

    uVar13 = (ulonglong)((int)uVar13 + 1);

  }

  iVar3 = *(int *)(param_3 + 0x1c);

  if (iVar3 != 0) {

    iVar11 = *(int *)(param_3 + 0x20);

    iVar2 = *(int *)(param_3 + 0x14);

    local_d28[uVar5 * 5] = 0;

    local_d78 = local_d28 + uVar5 * 5;

    local_d28[uVar5 * 5 + 1] = iVar3;

    local_d28[uVar5 * 5 + 2] = iVar11 + iVar2;

    local_d28[uVar5 * 5 + 3] = 2;

    local_d28[uVar5 * 5 + 4] = -1;

    *(undefined4 *)(&local_828 + uVar13 * 4) = 0;

    *(undefined4 *)((longlong)&local_828 + uVar13 * 0x20 + 4) = 0;

    aiStack_820[uVar13 * 8] = 1;

    aiStack_820[uVar13 * 8 + 1] = uStack_d80._4_4_;

    (&local_818)[uVar13 * 4] = local_d78;

    (&uStack_810)[uVar13 * 4] = 5;

    *(int *)((longlong)puVar4 + 0x34) = (int)uVar13;

    uVar13 = (ulonglong)((int)uVar13 + 1);

  }

  local_d58[0] = (uint)uVar13;

  if (*(int *)(param_3 + 0x18) != 0) {

    do {

      *(undefined4 *)(&local_828 + uVar13 * 4) = 2;

      *(undefined4 *)((longlong)&local_828 + uVar13 * 0x20 + 4) = 0;

      aiStack_820[uVar13 * 8] = (int)uVar9;

      aiStack_820[uVar13 * 8 + 1] = 3;

      (&local_818)[uVar13 * 4] = local_d78;

      (&uStack_810)[uVar13 * 4] = 5;

      uVar8 = (int)uVar9 + 1;

      *(int *)((longlong)puVar4 + uVar9 * 4 + 0x38) = (int)uVar13;

      local_d58[0] = (int)uVar13 + 1;

      uVar13 = (ulonglong)local_d58[0];

      uVar9 = (ulonglong)uVar8;

    } while (uVar8 < *(uint *)(param_3 + 0x18));

  }

  local_d50 = &local_828;

  local_d48 = 0;

  local_d40 = 0;

  local_d38 = 1;

  iVar3 = (**(code **)(param_1 + 0x78))(local_d58,1,&local_d68,&local_res20);

  if (iVar3 < 0) {

    if (local_res20 == (longlong *)0x0) goto LAB_1401c8575;

    if (*(char *)(param_1 + 0x98) != '\0') {

      uVar6 = (**(code **)(*local_res20 + 0x18))();

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"Failed to serialize RootSignature: %s",uVar6);

    }

    uVar6 = (**(code **)(*local_res20 + 0x18))();

    pcVar10 = "Failed to serialize RootSignature: %s";

  }

  else {

    uVar6 = (**(code **)(*local_d68 + 0x20))();

    uVar7 = (**(code **)(*local_d68 + 0x18))();

    iVar3 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x80))

                      (*(longlong **)(param_1 + 0x70),0,uVar7,uVar6,&DAT_140349348,&local_d60);

    if (-1 < iVar3) {

      *puVar4 = local_d60;

      return puVar4;

    }

    if (local_res20 == (longlong *)0x0) goto LAB_1401c8575;

    if (*(char *)(param_1 + 0x98) != '\0') {

      uVar6 = (**(code **)(*local_res20 + 0x18))();

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"Failed to create RootSignature: %s",uVar6);

    }

    uVar6 = (**(code **)(*local_res20 + 0x18))();

    pcVar10 = "Failed to create RootSignature: %s";

  }

  FUN_14012e850(pcVar10,uVar6);

  (**(code **)(*local_res20 + 0x10))();

LAB_1401c8575:

  FUN_1401c9730(puVar4);

  return (undefined8 *)0x0;

}




