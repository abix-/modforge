// Address: 0x1401bf120
// Ghidra name: FUN_1401bf120
// ============ 0x1401bf120 FUN_1401bf120 (size=512) ============


undefined1 FUN_1401bf120(longlong param_1,longlong param_2)



{

  undefined1 uVar1;

  

  if ((param_1 != 0) && (param_2 != 0)) {

    uVar1 = 1;

    if ((*(int *)(param_1 + 0x10) != 0) && (*(int *)(param_2 + 0x10) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'robustImageAccess\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_2 + 0x14) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'inlineUniformBlock\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x18) != 0) && (*(int *)(param_2 + 0x18) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'descriptorBindingInlineUniformBlockUpdateAfterBind\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(param_2 + 0x1c) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'pipelineCreationCacheControl\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x20) != 0) && (*(int *)(param_2 + 0x20) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'privateData\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x24) != 0) && (*(int *)(param_2 + 0x24) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'shaderDemoteToHelperInvocation\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x28) != 0) && (*(int *)(param_2 + 0x28) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'shaderTerminateInvocation\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_2 + 0x2c) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'subgroupSizeControl\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x30) != 0) && (*(int *)(param_2 + 0x30) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'computeFullSubgroups\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x34) != 0) && (*(int *)(param_2 + 0x34) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'synchronization2\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x38) != 0) && (*(int *)(param_2 + 0x38) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'textureCompressionASTC_HDR\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x3c) != 0) && (*(int *)(param_2 + 0x3c) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'shaderZeroInitializeWorkgroupMemory\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x40) != 0) && (*(int *)(param_2 + 0x40) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'dynamicRendering\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x44) != 0) && (*(int *)(param_2 + 0x44) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'shaderIntegerDotProduct\'"

                   );

      uVar1 = 0;

    }

    if (*(int *)(param_1 + 0x48) == 0) {

      return uVar1;

    }

    if (*(int *)(param_2 + 0x48) != 0) {

      return uVar1;

    }

    FUN_14012e2b0(9,

                  "SDL GPU Vulkan: Application requested unsupported physical device feature \'maintenance4\'"

                 );

  }

  return 0;

}




