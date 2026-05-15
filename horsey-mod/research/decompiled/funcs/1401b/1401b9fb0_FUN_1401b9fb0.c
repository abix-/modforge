// Address: 0x1401b9fb0
// Ghidra name: FUN_1401b9fb0
// ============ 0x1401b9fb0 FUN_1401b9fb0 (size=899) ============


undefined4 *

FUN_1401b9fb0(longlong param_1,undefined4 param_2,uint param_3,int param_4,int param_5,uint param_6,

             int param_7,uint param_8)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  undefined4 *puVar5;

  uint uVar6;

  uint uVar7;

  ulonglong uVar8;

  uint uVar9;

  undefined4 *local_res8;

  undefined4 local_4f8;

  uint uStack_4f4;

  int iStack_4f0;

  int iStack_4ec;

  int local_4e8;

  uint uStack_4e4;

  uint local_4e0;

  undefined8 local_4d8;

  undefined4 local_4d0 [2];

  undefined8 local_4c8;

  undefined4 local_4c0;

  int local_4bc;

  undefined1 *local_4b8;

  undefined1 local_4a8 [8];

  undefined4 local_4a0 [286];

  

  iStack_4f0 = param_5;

  local_res8 = (undefined4 *)0x0;

  uStack_4e4 = param_6;

  local_4e8 = param_7;

  local_4e0 = param_8;

  local_4f8 = param_2;

  uStack_4f4 = param_3;

  iStack_4ec = param_4;

  FUN_140179b40(*(undefined8 *)(param_1 + 0x908));

  cVar1 = FUN_1401aaff0(*(undefined8 *)(param_1 + 0x820),&local_4f8,&local_res8);

  if (cVar1 == '\0') {

    uVar7 = 0;

    local_4d0[0] = 0x20;

    local_4c8 = 0;

    local_4c0 = 0;

    if (param_3 != 0) {

      puVar5 = local_4a0;

      uVar6 = uVar7;

      do {

        puVar5[-2] = uVar6;

        uVar6 = uVar6 + 1;

        *puVar5 = 1;

        puVar5[-1] = 1;

        puVar5[1] = param_2;

        *(undefined8 *)(puVar5 + 2) = 0;

        puVar5 = puVar5 + 6;

      } while (uVar6 < param_3);

    }

    uVar6 = param_3 + param_4;

    uVar8 = (ulonglong)uVar6;

    if (param_3 < uVar6) {

      puVar5 = local_4a0 + (ulonglong)param_3 * 6;

      uVar9 = param_3;

      do {

        puVar5[-2] = uVar9;

        uVar9 = uVar9 + 1;

        *puVar5 = 1;

        puVar5[-1] = 2;

        puVar5[1] = param_2;

        *(undefined8 *)(puVar5 + 2) = 0;

        puVar5 = puVar5 + 6;

      } while (uVar9 < uVar6);

    }

    uVar9 = param_5 + uVar6;

    if (uVar6 < uVar9) {

      puVar5 = local_4a0 + uVar8 * 6;

      do {

        puVar5[-2] = (int)uVar8;

        uVar6 = (int)uVar8 + 1;

        uVar8 = (ulonglong)uVar6;

        *puVar5 = 1;

        puVar5[-1] = 7;

        puVar5[1] = param_2;

        *(undefined8 *)(puVar5 + 2) = 0;

        puVar5 = puVar5 + 6;

      } while (uVar6 < uVar9);

    }

    if (param_6 != 0) {

      puVar5 = local_4a0;

      uVar6 = uVar7;

      do {

        puVar5[-2] = uVar6;

        uVar6 = uVar6 + 1;

        *puVar5 = 1;

        puVar5[-1] = 3;

        puVar5[1] = param_2;

        *(undefined8 *)(puVar5 + 2) = 0;

        puVar5 = puVar5 + 6;

      } while (uVar6 < param_6);

    }

    if (param_6 < param_6 + param_7) {

      puVar5 = local_4a0 + (ulonglong)param_6 * 6;

      uVar6 = param_6;

      do {

        puVar5[-2] = uVar6;

        uVar6 = uVar6 + 1;

        *puVar5 = 1;

        puVar5[-1] = 7;

        puVar5[1] = param_2;

        *(undefined8 *)(puVar5 + 2) = 0;

        puVar5 = puVar5 + 6;

      } while (uVar6 < param_6 + param_7);

    }

    if (param_8 != 0) {

      puVar5 = local_4a0;

      do {

        puVar5[-2] = uVar7;

        uVar7 = uVar7 + 1;

        *puVar5 = 1;

        puVar5[-1] = 8;

        puVar5[1] = param_2;

        *(undefined8 *)(puVar5 + 2) = 0;

        puVar5 = puVar5 + 6;

      } while (uVar7 < param_8);

    }

    local_4b8 = local_4a8;

    local_4bc = uVar9 + param_6 + param_7 + param_8;

    iVar2 = (**(code **)(param_1 + 0xb08))(*(undefined8 *)(param_1 + 0x570),local_4d0,0,&local_4d8);

    if (iVar2 != 0) {

      FUN_140179b60(*(undefined8 *)(param_1 + 0x908));

      if (*(char *)(param_1 + 0x57c) == '\0') {

        uVar4 = FUN_1401c0ba0(iVar2);

        FUN_14012e850("%s %s","vkCreateDescriptorSetLayout",uVar4);

        return (undefined4 *)0x0;

      }

      uVar4 = FUN_1401c0ba0(iVar2);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkCreateDescriptorSetLayout",uVar4);

    }

    local_res8 = (undefined4 *)FUN_1401841f0(0x28);

    *(undefined8 *)(local_res8 + 2) = local_4d8;

    local_res8[4] = param_3;

    local_res8[5] = param_5;

    local_res8[6] = param_4;

    local_res8[7] = param_7;

    local_res8[8] = param_6;

    local_res8[9] = param_8;

    uVar3 = FUN_140138fb0(param_1 + 0x848,1);

    *local_res8 = uVar3;

    puVar5 = (undefined4 *)FUN_1401841f0(0x1c);

    *puVar5 = local_4f8;

    puVar5[1] = uStack_4f4;

    puVar5[2] = iStack_4f0;

    puVar5[3] = iStack_4ec;

    *(ulonglong *)(puVar5 + 4) = CONCAT44(uStack_4e4,local_4e8);

    puVar5[6] = local_4e0;

    FUN_1401ab100(*(undefined8 *)(param_1 + 0x820),puVar5,local_res8,1);

  }

  FUN_140179b60(*(undefined8 *)(param_1 + 0x908));

  return local_res8;

}




