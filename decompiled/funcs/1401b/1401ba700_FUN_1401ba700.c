// Address: 0x1401ba700
// Ghidra name: FUN_1401ba700
// ============ 0x1401ba700 FUN_1401ba700 (size=779) ============


longlong FUN_1401ba700(longlong param_1,longlong param_2,longlong param_3)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  undefined8 uVar5;

  undefined4 *puVar6;

  longlong local_res8;

  undefined4 local_88;

  undefined4 uStack_84;

  undefined4 uStack_80;

  undefined4 uStack_7c;

  undefined4 local_78;

  undefined4 uStack_74;

  undefined4 uStack_70;

  undefined4 uStack_6c;

  undefined8 local_68;

  undefined8 local_60;

  undefined8 local_58;

  undefined8 local_50;

  undefined4 local_48 [2];

  undefined8 local_40;

  undefined4 local_38;

  undefined4 local_34;

  undefined8 *local_30;

  undefined4 local_28;

  undefined8 local_20;

  

  local_88 = *(undefined4 *)(param_2 + 0x14);

  uStack_84 = *(undefined4 *)(param_2 + 0x18);

  uStack_80 = *(undefined4 *)(param_2 + 0x1c);

  uStack_7c = *(undefined4 *)(param_2 + 0x20);

  local_78 = *(undefined4 *)(param_3 + 0x14);

  uStack_74 = *(undefined4 *)(param_3 + 0x18);

  uStack_70 = *(undefined4 *)(param_3 + 0x1c);

  uStack_6c = *(undefined4 *)(param_3 + 0x20);

  local_res8 = 0;

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8f8));

  cVar2 = FUN_1401aaff0(*(undefined8 *)(param_1 + 0x810),&local_88,&local_res8);

  if (cVar2 == '\0') {

    lVar4 = FUN_1401841a0(1,0x48);

    local_res8 = lVar4;

    uVar5 = FUN_1401b9fb0(param_1,1,*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18),

                          *(undefined4 *)(param_2 + 0x1c),0,0,0);

    lVar1 = local_res8;

    *(undefined8 *)(lVar4 + 8) = uVar5;

    uVar5 = FUN_1401b9fb0(param_1,1,0,0,0,0,0,*(undefined4 *)(param_2 + 0x20));

    lVar4 = local_res8;

    *(undefined8 *)(lVar1 + 0x10) = uVar5;

    uVar5 = FUN_1401b9fb0(param_1,0x10,*(undefined4 *)(param_3 + 0x14),

                          *(undefined4 *)(param_3 + 0x18),*(undefined4 *)(param_3 + 0x1c),0,0,0);

    lVar1 = local_res8;

    *(undefined8 *)(lVar4 + 0x18) = uVar5;

    uVar5 = FUN_1401b9fb0(param_1,0x10,0,0,0,0,0,*(undefined4 *)(param_3 + 0x20));

    *(undefined8 *)(lVar1 + 0x20) = uVar5;

    local_68 = *(undefined8 *)(*(longlong *)(local_res8 + 8) + 8);

    local_60 = *(undefined8 *)(*(longlong *)(local_res8 + 0x10) + 8);

    local_58 = *(undefined8 *)(*(longlong *)(local_res8 + 0x18) + 8);

    local_50 = *(undefined8 *)(*(longlong *)(local_res8 + 0x20) + 8);

    *(undefined4 *)(local_res8 + 0x28) = *(undefined4 *)(param_2 + 0x14);

    *(undefined4 *)(local_res8 + 0x2c) = *(undefined4 *)(param_2 + 0x18);

    *(undefined4 *)(local_res8 + 0x30) = *(undefined4 *)(param_2 + 0x1c);

    *(undefined4 *)(local_res8 + 0x34) = *(undefined4 *)(param_2 + 0x20);

    *(undefined4 *)(local_res8 + 0x38) = *(undefined4 *)(param_3 + 0x14);

    *(undefined4 *)(local_res8 + 0x3c) = *(undefined4 *)(param_3 + 0x18);

    *(undefined4 *)(local_res8 + 0x40) = *(undefined4 *)(param_3 + 0x1c);

    *(undefined4 *)(local_res8 + 0x44) = *(undefined4 *)(param_3 + 0x20);

    local_30 = &local_68;

    local_48[0] = 0x1e;

    local_40 = 0;

    local_38 = 0;

    local_34 = 4;

    local_28 = 0;

    local_20 = 0;

    iVar3 = (**(code **)(param_1 + 0xb48))(*(undefined8 *)(param_1 + 0x570),local_48,0,local_res8);

    if (iVar3 == 0) {

      puVar6 = (undefined4 *)FUN_1401841f0(0x20);

      *puVar6 = local_88;

      puVar6[1] = uStack_84;

      puVar6[2] = uStack_80;

      puVar6[3] = uStack_7c;

      puVar6[4] = local_78;

      puVar6[5] = uStack_74;

      puVar6[6] = uStack_70;

      puVar6[7] = uStack_6c;

      FUN_1401ab100(*(undefined8 *)(param_1 + 0x810),puVar6,local_res8,1);

      FUN_140179b60(*(undefined8 *)(param_1 + 0x8f8));

    }

    else {

      FUN_1401b9110(param_1,local_res8);

      FUN_140179b60(*(undefined8 *)(param_1 + 0x8f8));

      if (*(char *)(param_1 + 0x57c) != '\0') {

        uVar5 = FUN_1401c0ba0(iVar3);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(9,"%s %s","vkCreatePipelineLayout",uVar5);

      }

      uVar5 = FUN_1401c0ba0(iVar3);

      FUN_14012e850("%s %s","vkCreatePipelineLayout",uVar5);

      local_res8 = 0;

    }

  }

  else {

    FUN_140179b60(*(undefined8 *)(param_1 + 0x8f8));

  }

  return local_res8;

}




