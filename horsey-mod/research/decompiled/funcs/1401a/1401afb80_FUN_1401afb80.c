// Address: 0x1401afb80
// Ghidra name: FUN_1401afb80
// ============ 0x1401afb80 FUN_1401afb80 (size=874) ============


undefined4 * FUN_1401afb80(longlong param_1,undefined8 *param_2)



{

  char cVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined8 uVar4;

  longlong lVar5;

  undefined4 local_d8;

  undefined4 uStack_d4;

  undefined8 uStack_d0;

  undefined4 local_c8;

  undefined4 uStack_c4;

  undefined8 uStack_c0;

  undefined8 local_b8;

  undefined8 uStack_b0;

  undefined4 local_a8 [2];

  undefined8 local_a0;

  undefined4 local_98;

  undefined8 local_90;

  undefined8 local_88;

  undefined4 local_78 [2];

  undefined8 local_70;

  undefined4 local_68;

  undefined8 local_60;

  undefined8 uStack_58;

  undefined4 local_50;

  undefined4 uStack_4c;

  undefined4 uStack_48;

  undefined4 uStack_44;

  undefined4 local_40;

  undefined4 uStack_3c;

  undefined4 uStack_38;

  undefined4 uStack_34;

  undefined8 local_30;

  undefined8 local_28;

  undefined4 local_20;

  

  if (*(int *)(param_2 + 3) != 2) {

    if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Incompatible shader format for Vulkan!");

    }

    FUN_14012e850(&DAT_14039bf30,"Incompatible shader format for Vulkan!");

    return (undefined4 *)0x0;

  }

  cVar1 = FUN_1401bb550(param_2[1],*param_2);

  if (cVar1 != '\0') {

    puVar3 = (undefined4 *)FUN_1401841f0(0x38);

    local_90 = *param_2;

    local_88 = param_2[1];

    local_a8[0] = 0x10;

    local_a0 = 0;

    local_98 = 0;

    iVar2 = (**(code **)(param_1 + 0xb68))(*(undefined8 *)(param_1 + 0x570),local_a8,0,puVar3 + 6);

    if (iVar2 == 0) {

      uStack_c0 = *(undefined8 *)(puVar3 + 6);

      local_b8 = param_2[2];

      local_d8 = 0x12;

      uStack_d0 = 0;

      local_c8 = 0;

      uStack_c4 = 0x20;

      uStack_b0 = 0;

      lVar5 = FUN_1401b9c30(param_1,param_2);

      *(longlong *)(puVar3 + 10) = lVar5;

      if (lVar5 == 0) {

        (**(code **)(param_1 + 0xbe8))

                  (*(undefined8 *)(param_1 + 0x570),*(undefined8 *)(puVar3 + 6),0);

        FUN_1401841e0(puVar3);

        puVar3 = (undefined4 *)0x0;

      }

      else {

        local_60 = CONCAT44(uStack_d4,local_d8);

        local_78[0] = 0x1d;

        local_70 = 0;

        uStack_58 = uStack_d0;

        local_68 = 0;

        local_50 = local_c8;

        uStack_4c = uStack_c4;

        uStack_48 = (undefined4)uStack_c0;

        uStack_44 = uStack_c0._4_4_;

        local_40 = (undefined4)local_b8;

        uStack_3c = local_b8._4_4_;

        uStack_38 = (undefined4)uStack_b0;

        uStack_34 = uStack_b0._4_4_;

        local_30 = **(undefined8 **)(puVar3 + 10);

        local_28 = 0;

        local_20 = 0;

        iVar2 = (**(code **)(param_1 + 0xb20))

                          (*(undefined8 *)(param_1 + 0x570),0,1,local_78,0,puVar3 + 8);

        if (iVar2 == 0) {

          FUN_140139010(puVar3 + 0xc,0);

          if ((*(char *)(param_1 + 0x57c) != '\0') && (*(char *)(param_1 + 0x58e) != '\0')) {

            cVar1 = FUN_140174fc0(*(undefined4 *)(param_2 + 8),"SDL.gpu.computepipeline.create.name"

                                 );

            if (cVar1 != '\0') {

              local_d8 = 0x3b9cbe00;

              uStack_d0 = 0;

              local_b8 = FUN_140174e70(*(undefined4 *)(param_2 + 8),

                                       "SDL.gpu.computepipeline.create.name",0);

              uStack_c0 = *(undefined8 *)(puVar3 + 8);

              local_c8 = 0x13;

              (**(code **)(param_1 + 0x9d0))(*(undefined8 *)(param_1 + 0x570),&local_d8);

            }

          }

          lVar5 = *(longlong *)(puVar3 + 10);

          *puVar3 = *(undefined4 *)(lVar5 + 0x20);

          puVar3[1] = *(undefined4 *)(lVar5 + 0x24);

          puVar3[2] = *(undefined4 *)(lVar5 + 0x28);

          puVar3[3] = *(undefined4 *)(lVar5 + 0x2c);

          puVar3[4] = *(undefined4 *)(lVar5 + 0x30);

          puVar3[5] = *(undefined4 *)(lVar5 + 0x34);

        }

        else {

          FUN_1401b90a0(param_1,puVar3);

          if (*(char *)(param_1 + 0x57c) != '\0') {

            uVar4 = FUN_1401c0ba0(iVar2);

                    /* WARNING: Subroutine does not return */

            FUN_14012e0b0(9,"%s %s","vkCreateComputePipeline",uVar4);

          }

          uVar4 = FUN_1401c0ba0(iVar2);

          FUN_14012e850("%s %s","vkCreateComputePipeline",uVar4);

          puVar3 = (undefined4 *)0x0;

        }

      }

    }

    else {

      FUN_1401841e0(puVar3);

      if (*(char *)(param_1 + 0x57c) != '\0') {

        uVar4 = FUN_1401c0ba0(iVar2);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(9,"%s %s","vkCreateShaderModule",uVar4);

      }

      uVar4 = FUN_1401c0ba0(iVar2);

      FUN_14012e850("%s %s","vkCreateShaderModule",uVar4);

      puVar3 = (undefined4 *)0x0;

    }

    return puVar3;

  }

  if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,&DAT_14039bf30,"The provided shader code is not valid SPIR-V!");

  }

  FUN_14012e850(&DAT_14039bf30,"The provided shader code is not valid SPIR-V!");

  return (undefined4 *)0x0;

}




