// Address: 0x1401ba340
// Ghidra name: FUN_1401ba340
// ============ 0x1401ba340 FUN_1401ba340 (size=954) ============


longlong FUN_1401ba340(longlong param_1,undefined8 param_2,longlong param_3,uint param_4,

                      undefined8 *param_5,undefined4 param_6,undefined4 param_7)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  undefined8 *puVar4;

  undefined8 uVar5;

  uint uVar6;

  uint uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  uint *puVar11;

  undefined8 *puVar12;

  ulonglong uVar13;

  undefined4 local_1a8 [2];

  undefined8 local_1a0;

  undefined4 local_198;

  undefined8 local_190;

  undefined4 local_188;

  undefined8 *local_180;

  undefined4 local_178;

  undefined4 local_174;

  undefined4 local_170;

  undefined8 local_168 [18];

  undefined8 local_d8;

  undefined8 uStack_d0;

  undefined8 local_c8;

  undefined8 uStack_c0;

  undefined8 local_b8;

  undefined8 uStack_b0;

  undefined8 local_a8;

  undefined8 uStack_a0;

  uint local_98;

  undefined4 uStack_94;

  undefined8 auStack_90 [4];

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined4 local_58;

  undefined4 uStack_54;

  uint uStack_50;

  undefined4 uStack_4c;

  undefined8 local_48;

  undefined4 uStack_40;

  undefined4 uStack_3c;

  

  puVar4 = param_5;

  uVar10 = (ulonglong)param_4;

  param_5 = (undefined8 *)0x0;

  local_168[0x10] = 0;

  local_168[0] = 0;

  local_168[1] = 0;

  uVar8 = 0;

  local_168[2] = 0;

  local_168[3] = 0;

  local_168[4] = 0;

  local_168[5] = 0;

  local_168[6] = 0;

  local_168[7] = 0;

  local_168[8] = 0;

  local_168[9] = 0;

  local_168[10] = 0;

  local_168[0xb] = 0;

  local_168[0xc] = 0;

  local_168[0xd] = 0;

  local_168[0xe] = 0;

  local_168[0xf] = 0;

  FUN_1402f94c0(&local_d8,0,0xa0);

  local_98 = param_4;

  if (param_4 != 0) {

    puVar12 = &local_d8;

    puVar11 = (uint *)(param_3 + 0xc);

    uVar9 = (ulonglong)param_4;

    do {

      uVar7 = puVar11[-1];

      if (**(int **)(puVar11 + -3) == 2) {

        uVar13 = (ulonglong)*puVar11;

        uVar6 = 0;

      }

      else {

        uVar6 = *puVar11;

        uVar13 = 0;

      }

      lVar3 = FUN_1401bac70(*(int **)(puVar11 + -3),uVar6,uVar7);

      *puVar12 = *(undefined8 *)(*(longlong *)(lVar3 + 0x10) + uVar13 * 8);

      if (*(longlong *)(puVar11 + 7) != 0) {

        lVar3 = FUN_1401bac70(*(longlong *)(puVar11 + 7),*puVar11,uVar7);

        auStack_90[uStack_50] = **(undefined8 **)(lVar3 + 0x10);

        uStack_50 = uStack_50 + 1;

      }

      puVar12 = puVar12 + 1;

      puVar11 = puVar11 + 0x10;

      uVar9 = uVar9 - 1;

    } while (uVar9 != 0);

  }

  if (puVar4 == (undefined8 *)0x0) {

    local_48 = 0;

  }

  else {

    lVar3 = FUN_1401bac70(*puVar4,*(undefined1 *)((longlong)puVar4 + 0x1f),

                          *(undefined1 *)((longlong)puVar4 + 0x1e));

    local_48 = *(undefined8 *)(lVar3 + 0x20);

  }

  uStack_40 = param_6;

  uStack_3c = param_7;

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8f0));

  cVar1 = FUN_1401aaff0(*(undefined8 *)(param_1 + 0x808),&local_d8,&param_5);

  if (cVar1 == '\0') {

    param_5 = (undefined8 *)FUN_1401841f0(0x10);

    FUN_140139010((longlong)param_5 + 8,0);

    if (param_4 != 0) {

      puVar11 = (uint *)(param_3 + 0xc);

      do {

        if (**(int **)(puVar11 + -3) == 2) {

          uVar9 = (ulonglong)*puVar11;

          uVar7 = 0;

        }

        else {

          uVar7 = *puVar11;

          uVar9 = 0;

        }

        lVar3 = FUN_1401bac70(*(int **)(puVar11 + -3),uVar7,puVar11[-1]);

        local_168[uVar8] = *(undefined8 *)(*(longlong *)(lVar3 + 0x10) + (uVar9 & 0xffffffff) * 8);

        iVar2 = (int)uVar8;

        uVar8 = (ulonglong)(iVar2 + 1);

        if (puVar11[6] - 2 < 2) {

          lVar3 = FUN_1401bac70(*(undefined8 *)(puVar11 + 7),puVar11[10],puVar11[9]);

          local_168[uVar8] = **(undefined8 **)(lVar3 + 0x10);

          uVar8 = (ulonglong)(iVar2 + 2);

        }

        puVar11 = puVar11 + 0x10;

        uVar10 = uVar10 - 1;

      } while (uVar10 != 0);

    }

    if (puVar4 != (undefined8 *)0x0) {

      lVar3 = FUN_1401bac70(*puVar4,*(undefined1 *)((longlong)puVar4 + 0x1f),

                            *(undefined1 *)((longlong)puVar4 + 0x1e));

      local_168[uVar8] = *(undefined8 *)(lVar3 + 0x20);

      uVar8 = (ulonglong)((int)uVar8 + 1);

    }

    local_180 = local_168;

    local_178 = uStack_40;

    local_174 = uStack_3c;

    local_1a8[0] = 0x25;

    local_1a0 = 0;

    local_198 = 0;

    local_188 = (undefined4)uVar8;

    local_170 = 1;

    local_190 = param_2;

    iVar2 = (**(code **)(param_1 + 0xb18))(*(undefined8 *)(param_1 + 0x570),local_1a8,0,param_5);

    if (iVar2 != 0) {

      FUN_1401841e0(param_5);

      FUN_140179b60(*(undefined8 *)(param_1 + 0x8f0));

      if (*(char *)(param_1 + 0x57c) == '\0') {

        uVar5 = FUN_1401c0ba0(iVar2);

        FUN_14012e850("%s %s","vkCreateFramebuffer",uVar5);

        return 0;

      }

      uVar5 = FUN_1401c0ba0(iVar2);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkCreateFramebuffer",uVar5);

    }

    puVar4 = (undefined8 *)FUN_1401841f0(0xa0);

    *puVar4 = local_d8;

    puVar4[1] = uStack_d0;

    puVar4[2] = local_c8;

    puVar4[3] = uStack_c0;

    puVar4[4] = local_b8;

    puVar4[5] = uStack_b0;

    puVar4[6] = local_a8;

    puVar4[7] = uStack_a0;

    puVar4[8] = CONCAT44(uStack_94,local_98);

    puVar4[9] = auStack_90[0];

    puVar4[10] = auStack_90[1];

    puVar4[0xb] = auStack_90[2];

    puVar4[0xc] = auStack_90[3];

    puVar4[0xd] = uStack_70;

    puVar4[0xe] = local_68;

    puVar4[0xf] = uStack_60;

    *(undefined4 *)(puVar4 + 0x10) = local_58;

    *(undefined4 *)((longlong)puVar4 + 0x84) = uStack_54;

    *(uint *)(puVar4 + 0x11) = uStack_50;

    *(undefined4 *)((longlong)puVar4 + 0x8c) = uStack_4c;

    *(undefined4 *)(puVar4 + 0x12) = (undefined4)local_48;

    *(undefined4 *)((longlong)puVar4 + 0x94) = local_48._4_4_;

    *(undefined4 *)(puVar4 + 0x13) = uStack_40;

    *(undefined4 *)((longlong)puVar4 + 0x9c) = uStack_3c;

    FUN_1401ab100(*(undefined8 *)(param_1 + 0x808),puVar4,param_5,1);

  }

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8f0));

  return (longlong)param_5;

}




