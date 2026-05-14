// Address: 0x1401be910
// Ghidra name: FUN_1401be910
// ============ 0x1401be910 FUN_1401be910 (size=419) ============


undefined1 FUN_1401be910(longlong param_1,longlong param_2)



{

  undefined1 uVar1;

  

  if ((param_1 != 0) && (param_2 != 0)) {

    uVar1 = 1;

    if ((*(int *)(param_1 + 0x10) != 0) && (*(int *)(param_2 + 0x10) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'storageBuffer16BitAccess\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_2 + 0x14) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'uniformAndStorageBuffer16BitAccess\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x18) != 0) && (*(int *)(param_2 + 0x18) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'storagePushConstant16\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(param_2 + 0x1c) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'storageInputOutput16\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x20) != 0) && (*(int *)(param_2 + 0x20) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'multiview\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x24) != 0) && (*(int *)(param_2 + 0x24) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'multiviewGeometryShader\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x28) != 0) && (*(int *)(param_2 + 0x28) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'multiviewTessellationShader\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_2 + 0x2c) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'variablePointersStorageBuffer\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x30) != 0) && (*(int *)(param_2 + 0x30) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'variablePointers\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x34) != 0) && (*(int *)(param_2 + 0x34) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'protectedMemory\'"

                   );

      uVar1 = 0;

    }

    if ((*(int *)(param_1 + 0x38) != 0) && (*(int *)(param_2 + 0x38) == 0)) {

      FUN_14012e2b0(9,

                    "SDL GPU Vulkan: Application requested unsupported physical device feature \'samplerYcbcrConversion\'"

                   );

      uVar1 = 0;

    }

    if (*(int *)(param_1 + 0x3c) == 0) {

      return uVar1;

    }

    if (*(int *)(param_2 + 0x3c) != 0) {

      return uVar1;

    }

    FUN_14012e2b0(9,

                  "SDL GPU Vulkan: Application requested unsupported physical device feature \'shaderDrawParameters\'"

                 );

  }

  return 0;

}




