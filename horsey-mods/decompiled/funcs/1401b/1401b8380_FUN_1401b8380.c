// Address: 0x1401b8380
// Ghidra name: FUN_1401b8380
// ============ 0x1401b8380 FUN_1401b8380 (size=583) ============


undefined8 FUN_1401b8380(longlong param_1,undefined8 *param_2,undefined4 param_3)



{

  int iVar1;

  int iVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  int *piVar5;

  uint uVar6;

  ulonglong uVar7;

  int local_res8 [2];

  undefined8 local_res10;

  undefined4 local_238 [2];

  undefined8 local_230;

  undefined4 local_228;

  int iStack_224;

  undefined4 *puStack_220;

  undefined4 local_218;

  undefined8 *local_210;

  undefined4 local_208;

  undefined8 local_200;

  undefined8 local_1f8;

  undefined4 local_1f0;

  undefined8 local_1e8;

  uint local_1e0;

  int *local_1d8;

  undefined8 local_1d0;

  int *local_1c8;

  undefined4 local_1c0;

  undefined8 local_1b8;

  undefined4 local_1a8 [84];

  int local_58 [16];

  

  local_1e0 = *(uint *)(param_2 + 1);

  uVar4 = 0;

  if (local_1e0 != 0) {

    piVar5 = (int *)*param_2;

    uVar7 = uVar4;

    do {

      iVar2 = *piVar5;

      piVar5 = piVar5 + 9;

      local_58[uVar7 * 2] = (int)uVar7;

      uVar6 = (int)uVar7 + 1;

      uVar4 = (ulonglong)uVar6;

      local_1a8[uVar7 * 9] = 0;

      local_1a8[uVar7 * 9 + 2] = param_3;

      local_1a8[uVar7 * 9 + 3] = 2;

      local_1a8[uVar7 * 9 + 4] = 1;

      local_1a8[uVar7 * 9 + 5] = 2;

      local_1a8[uVar7 * 9 + 1] = *(undefined4 *)(&DAT_1403e3ec0 + (longlong)iVar2 * 4);

      local_1a8[uVar7 * 9 + 6] = 1;

      local_1a8[uVar7 * 9 + 7] = 2;

      local_1a8[uVar7 * 9 + 8] = 2;

      local_58[uVar7 * 2 + 1] = 2;

      uVar7 = uVar4;

    } while (uVar6 < local_1e0);

  }

  iVar2 = (int)uVar4;

  local_1d8 = local_58;

  local_1f8 = 0;

  local_1f0 = 0;

  local_1e8 = 0;

  local_1c0 = 0;

  local_1b8 = 0;

  if (*(char *)(param_2 + 2) == '\0') {

    local_1c8 = (int *)0x0;

    iStack_224 = iVar2;

  }

  else {

    local_res8[1] = 3;

    iVar1 = *(int *)((longlong)param_2 + 0xc);

    local_1a8[uVar4 * 9] = 0;

    local_1a8[uVar4 * 9 + 2] = param_3;

    local_1a8[uVar4 * 9 + 3] = 2;

    local_1a8[uVar4 * 9 + 1] = *(undefined4 *)(&DAT_1403e3ec0 + (longlong)iVar1 * 4);

    local_1c8 = local_res8;

    local_1a8[uVar4 * 9 + 4] = 1;

    local_1a8[uVar4 * 9 + 5] = 2;

    local_1a8[uVar4 * 9 + 6] = 1;

    local_1a8[uVar4 * 9 + 7] = 3;

    local_1a8[uVar4 * 9 + 8] = 3;

    iStack_224 = iVar2 + 1;

    local_res8[0] = iVar2;

  }

  puStack_220 = local_1a8;

  local_210 = &local_1f8;

  local_1d0 = 0;

  local_238[0] = 0x26;

  local_230 = 0;

  local_228 = 0;

  local_218 = 1;

  local_208 = 0;

  local_200 = 0;

  iVar2 = (**(code **)(param_1 + 0xb50))(*(undefined8 *)(param_1 + 0x570),local_238,0,&local_res10);

  if (iVar2 != 0) {

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar3 = FUN_1401c0ba0(iVar2);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkCreateRenderPass",uVar3);

    }

    uVar3 = FUN_1401c0ba0(iVar2);

    FUN_14012e850("%s %s","vkCreateRenderPass",uVar3);

    local_res10 = 0;

  }

  return local_res10;

}




