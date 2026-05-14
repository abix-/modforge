// Address: 0x1401c79e0
// Ghidra name: FUN_1401c79e0
// ============ 0x1401c79e0 FUN_1401c79e0 (size=1171) ============


undefined8 * FUN_1401c79e0(longlong param_1,longlong param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined8 *puVar4;

  undefined8 uVar5;

  undefined8 uVar6;

  uint uVar7;

  ulonglong uVar8;

  char *pcVar9;

  ulonglong uVar10;

  longlong *local_res18;

  longlong *local_res20;

  int *local_d68;

  undefined8 local_d58;

  uint local_d50 [2];

  undefined8 *local_d48;

  undefined4 local_d40;

  undefined8 local_d38;

  undefined4 local_d30;

  int local_d28 [320];

  undefined8 local_828;

  int aiStack_820 [2];

  int *local_818 [4];

  undefined8 local_7f8;

  undefined4 uStack_7f0;

  undefined4 uStack_7ec;

  

  puVar4 = (undefined8 *)FUN_1401841a0(1,0x30);

  if (puVar4 == (undefined8 *)0x0) {

    return (undefined8 *)0x0;

  }

  FUN_1402f94c0(&local_828,0,0x800);

  FUN_1402f94c0(local_d28,0,0x500);

  puVar4[1] = 0xffffffffffffffff;

  puVar4[2] = 0xffffffffffffffff;

  puVar4[3] = 0xffffffffffffffff;

  puVar4[4] = 0xffffffffffffffff;

  puVar4[5] = 0xffffffffffffffff;

  iVar3 = *(int *)(param_2 + 0x1c);

  local_d68 = (int *)0x0;

  uVar10 = 0;

  local_7f8 = (int *)CONCAT44(local_7f8._4_4_,(undefined4)local_7f8);

  if (iVar3 != 0) {

    uVar10 = 2;

    local_818[0] = local_d28;

    local_d28[0] = 3;

    local_d28[2] = 0;

    local_d28[3] = 0;

    local_818[1] = (int *)0x0;

    local_d28[4] = 0xffffffff;

    local_828 = 0;

    aiStack_820[0] = 1;

    aiStack_820[1] = 0;

    *(undefined4 *)(puVar4 + 1) = 0;

    local_d28[6] = *(undefined4 *)(param_2 + 0x1c);

    local_d68 = local_d28 + 5;

    local_d28[5] = 0;

    local_d28[7] = 0;

    local_d28[8] = 0;

    uStack_7f0 = 0;

    uStack_7ec = 0;

    local_d28[9] = 0xffffffff;

    local_818[2] = (int *)0x0;

    local_818[3] = (int *)0x1;

    *(undefined4 *)((longlong)puVar4 + 0xc) = 1;

    local_d28[1] = iVar3;

    local_7f8 = local_d68;

  }

  iVar3 = *(int *)(param_2 + 0x20);

  if (iVar3 != 0) {

    iVar1 = *(int *)(param_2 + 0x1c);

    local_d28[uVar10 * 5] = 0;

    local_d68 = local_d28 + uVar10 * 5;

    local_d28[uVar10 * 5 + 1] = iVar3;

    local_d28[uVar10 * 5 + 2] = iVar1;

    local_d28[uVar10 * 5 + 3] = 0;

    local_d28[uVar10 * 5 + 4] = -1;

    *(undefined4 *)(&local_828 + uVar10 * 4) = 0;

    *(undefined4 *)((longlong)&local_828 + uVar10 * 0x20 + 4) = 0;

    aiStack_820[uVar10 * 8] = 1;

    aiStack_820[uVar10 * 8 + 1] = 0;

    local_818[uVar10 * 4] = local_d68;

    local_818[uVar10 * 4 + 1] = (int *)0x0;

    *(int *)(puVar4 + 2) = (int)uVar10;

    uVar10 = (ulonglong)((int)uVar10 + 1);

  }

  iVar3 = *(int *)(param_2 + 0x24);

  if (iVar3 != 0) {

    iVar1 = *(int *)(param_2 + 0x1c);

    iVar2 = *(int *)(param_2 + 0x20);

    local_d28[uVar10 * 5] = 0;

    local_d68 = local_d28 + uVar10 * 5;

    local_d28[uVar10 * 5 + 1] = iVar3;

    local_d28[uVar10 * 5 + 2] = iVar1 + iVar2;

    local_d28[uVar10 * 5 + 3] = 0;

    local_d28[uVar10 * 5 + 4] = -1;

    *(undefined4 *)(&local_828 + uVar10 * 4) = 0;

    *(undefined4 *)((longlong)&local_828 + uVar10 * 0x20 + 4) = 0;

    aiStack_820[uVar10 * 8] = 1;

    aiStack_820[uVar10 * 8 + 1] = 0;

    local_818[uVar10 * 4] = local_d68;

    local_818[uVar10 * 4 + 1] = (int *)0x0;

    *(int *)((longlong)puVar4 + 0x14) = (int)uVar10;

    uVar10 = (ulonglong)((int)uVar10 + 1);

  }

  iVar3 = *(int *)(param_2 + 0x28);

  if (iVar3 != 0) {

    local_d28[uVar10 * 5] = 1;

    local_d68 = local_d28 + uVar10 * 5;

    local_d28[uVar10 * 5 + 1] = iVar3;

    local_d28[uVar10 * 5 + 2] = 0;

    local_d28[uVar10 * 5 + 3] = 1;

    local_d28[uVar10 * 5 + 4] = -1;

    *(undefined4 *)(&local_828 + uVar10 * 4) = 0;

    *(undefined4 *)((longlong)&local_828 + uVar10 * 0x20 + 4) = 0;

    aiStack_820[uVar10 * 8] = 1;

    aiStack_820[uVar10 * 8 + 1] = 0;

    local_818[uVar10 * 4] = local_d68;

    local_818[uVar10 * 4 + 1] = (int *)0x0;

    *(int *)(puVar4 + 3) = (int)uVar10;

    uVar10 = (ulonglong)((int)uVar10 + 1);

  }

  iVar3 = *(int *)(param_2 + 0x2c);

  if (iVar3 != 0) {

    iVar1 = *(int *)(param_2 + 0x28);

    local_d28[uVar10 * 5] = 1;

    local_d68 = local_d28 + uVar10 * 5;

    local_d28[uVar10 * 5 + 1] = iVar3;

    local_d28[uVar10 * 5 + 2] = iVar1;

    local_d28[uVar10 * 5 + 3] = 1;

    local_d28[uVar10 * 5 + 4] = -1;

    *(undefined4 *)(&local_828 + uVar10 * 4) = 0;

    *(undefined4 *)((longlong)&local_828 + uVar10 * 0x20 + 4) = 0;

    aiStack_820[uVar10 * 8] = 1;

    aiStack_820[uVar10 * 8 + 1] = 0;

    local_818[uVar10 * 4] = local_d68;

    local_818[uVar10 * 4 + 1] = (int *)0x0;

    *(int *)((longlong)puVar4 + 0x1c) = (int)uVar10;

    uVar10 = (ulonglong)((int)uVar10 + 1);

  }

  local_d50[0] = (uint)uVar10;

  uVar8 = 0;

  if (*(int *)(param_2 + 0x30) != 0) {

    do {

      *(undefined4 *)(&local_828 + uVar10 * 4) = 2;

      *(undefined4 *)((longlong)&local_828 + uVar10 * 0x20 + 4) = 0;

      aiStack_820[uVar10 * 8] = (int)uVar8;

      aiStack_820[uVar10 * 8 + 1] = 2;

      local_818[uVar10 * 4] = local_d68;

      local_818[uVar10 * 4 + 1] = (int *)0x0;

      uVar7 = (int)uVar8 + 1;

      *(int *)((longlong)puVar4 + uVar8 * 4 + 0x20) = (int)uVar10;

      local_d50[0] = (int)uVar10 + 1;

      uVar10 = (ulonglong)local_d50[0];

      uVar8 = (ulonglong)uVar7;

    } while (uVar7 < *(uint *)(param_2 + 0x30));

  }

  local_d48 = &local_828;

  local_d40 = 0;

  local_d38 = 0;

  local_d30 = 0;

  iVar3 = (**(code **)(param_1 + 0x78))(local_d50,1,&local_res20,&local_res18);

  if (iVar3 < 0) {

    if (local_res18 == (longlong *)0x0) goto LAB_1401c7e53;

    if (*(char *)(param_1 + 0x98) != '\0') {

      uVar5 = (**(code **)(*local_res18 + 0x18))();

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"Failed to serialize RootSignature: %s",uVar5);

    }

    uVar5 = (**(code **)(*local_res18 + 0x18))();

    pcVar9 = "Failed to serialize RootSignature: %s";

  }

  else {

    uVar5 = (**(code **)(*local_res20 + 0x20))();

    uVar6 = (**(code **)(*local_res20 + 0x18))();

    iVar3 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x80))

                      (*(longlong **)(param_1 + 0x70),0,uVar6,uVar5,&DAT_140349348,&local_d58);

    if (-1 < iVar3) {

      *puVar4 = local_d58;

      return puVar4;

    }

    if (local_res18 == (longlong *)0x0) goto LAB_1401c7e53;

    if (*(char *)(param_1 + 0x98) != '\0') {

      uVar5 = (**(code **)(*local_res18 + 0x18))();

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"Failed to create RootSignature: %s",uVar5);

    }

    uVar5 = (**(code **)(*local_res18 + 0x18))();

    pcVar9 = "Failed to create RootSignature: %s";

  }

  FUN_14012e850(pcVar9,uVar5);

  (**(code **)(*local_res18 + 0x10))();

LAB_1401c7e53:

  FUN_1401c9730(puVar4);

  return (undefined8 *)0x0;

}




