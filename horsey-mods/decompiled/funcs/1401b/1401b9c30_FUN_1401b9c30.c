// Address: 0x1401b9c30
// Ghidra name: FUN_1401b9c30
// ============ 0x1401b9c30 FUN_1401b9c30 (size=664) ============


longlong FUN_1401b9c30(longlong param_1,longlong param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  undefined8 uVar5;

  undefined4 *puVar6;

  longlong local_res8;

  undefined4 local_78;

  undefined4 uStack_74;

  undefined4 uStack_70;

  undefined4 uStack_6c;

  undefined4 local_68;

  undefined4 uStack_64;

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

  

  local_78 = *(undefined4 *)(param_2 + 0x1c);

  uStack_74 = *(undefined4 *)(param_2 + 0x20);

  uStack_70 = *(undefined4 *)(param_2 + 0x24);

  uStack_6c = *(undefined4 *)(param_2 + 0x28);

  local_68 = *(undefined4 *)(param_2 + 0x2c);

  uStack_64 = *(undefined4 *)(param_2 + 0x30);

  local_res8 = 0;

  FUN_140179b40(*(undefined8 *)(param_1 + 0x900));

  cVar2 = FUN_1401aaff0(*(undefined8 *)(param_1 + 0x818),&local_78,&local_res8);

  if (cVar2 == '\0') {

    lVar4 = FUN_1401841a0(1,0x38);

    local_res8 = lVar4;

    uVar5 = FUN_1401b9fb0(param_1,0x20,*(undefined4 *)(param_2 + 0x1c),

                          *(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x24),0,0,0);

    lVar1 = local_res8;

    *(undefined8 *)(lVar4 + 8) = uVar5;

    uVar5 = FUN_1401b9fb0(param_1,0x20,0,0,0,*(undefined4 *)(param_2 + 0x28),

                          *(undefined4 *)(param_2 + 0x2c),0);

    lVar4 = local_res8;

    *(undefined8 *)(lVar1 + 0x10) = uVar5;

    uVar5 = FUN_1401b9fb0(param_1,0x20,0,0,0,0,0,*(undefined4 *)(param_2 + 0x30));

    *(undefined8 *)(lVar4 + 0x18) = uVar5;

    local_60 = *(undefined8 *)(*(longlong *)(local_res8 + 8) + 8);

    local_58 = *(undefined8 *)(*(longlong *)(local_res8 + 0x10) + 8);

    local_50 = *(undefined8 *)(*(longlong *)(local_res8 + 0x18) + 8);

    *(undefined4 *)(local_res8 + 0x20) = *(undefined4 *)(param_2 + 0x1c);

    *(undefined4 *)(local_res8 + 0x24) = *(undefined4 *)(param_2 + 0x20);

    *(undefined4 *)(local_res8 + 0x28) = *(undefined4 *)(param_2 + 0x24);

    *(undefined4 *)(local_res8 + 0x2c) = *(undefined4 *)(param_2 + 0x28);

    *(undefined4 *)(local_res8 + 0x30) = *(undefined4 *)(param_2 + 0x2c);

    *(undefined4 *)(local_res8 + 0x34) = *(undefined4 *)(param_2 + 0x30);

    local_30 = &local_60;

    local_48[0] = 0x1e;

    local_40 = 0;

    local_38 = 0;

    local_34 = 3;

    local_28 = 0;

    local_20 = 0;

    iVar3 = (**(code **)(param_1 + 0xb48))(*(undefined8 *)(param_1 + 0x570),local_48,0,local_res8);

    if (iVar3 == 0) {

      puVar6 = (undefined4 *)FUN_1401841f0(0x18);

      *puVar6 = local_78;

      puVar6[1] = uStack_74;

      puVar6[2] = uStack_70;

      puVar6[3] = uStack_6c;

      *(ulonglong *)(puVar6 + 4) = CONCAT44(uStack_64,local_68);

      FUN_1401ab100(*(undefined8 *)(param_1 + 0x818),puVar6,local_res8,1);

      FUN_140179b60(*(undefined8 *)(param_1 + 0x900));

    }

    else {

      FUN_1401b9110(param_1,local_res8);

      FUN_140179b60(*(undefined8 *)(param_1 + 0x900));

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

    FUN_140179b60(*(undefined8 *)(param_1 + 0x900));

  }

  return local_res8;

}




