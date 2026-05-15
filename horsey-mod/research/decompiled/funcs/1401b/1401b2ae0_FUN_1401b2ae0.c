// Address: 0x1401b2ae0
// Ghidra name: FUN_1401b2ae0
// ============ 0x1401b2ae0 FUN_1401b2ae0 (size=433) ============


void FUN_1401b2ae0(ulonglong param_1,longlong param_2,uint *param_3)



{

  uint *puVar1;

  uint *puVar2;

  char cVar3;

  uint *puVar4;

  longlong lVar5;

  

  cVar3 = FUN_140174fc0(param_1,"SDL.gpu.device.create.vulkan.options");

  if (cVar3 != '\0') {

    puVar4 = (uint *)FUN_140174d30(param_1 & 0xffffffff,"SDL.gpu.device.create.vulkan.options",0);

    if (puVar4 != (uint *)0x0) {

      *(undefined1 *)(param_3 + 0x90) = 1;

      *param_3 = *puVar4;

      puVar1 = param_3 + 0x38;

      puVar1[0] = 0;

      puVar1[1] = 0;

      param_3[0x3a] = 0;

      param_3[0x3b] = 0;

      param_3[0x3c] = 0;

      param_3[0x3d] = 0;

      param_3[0x3e] = 0;

      param_3[0x3f] = 0;

      param_3[0x40] = 0;

      param_3[0x41] = 0;

      param_3[0x42] = 0;

      param_3[0x43] = 0;

      param_3[0x44] = 0;

      param_3[0x45] = 0;

      param_3[0x46] = 0;

      param_3[0x47] = 0;

      FUN_1402f94c0(param_3 + 0x49,0,0xcc);

      puVar2 = param_3 + 0x7c;

      puVar2[0] = 0;

      puVar2[1] = 0;

      param_3[0x7e] = 0;

      param_3[0x7f] = 0;

      param_3[0x80] = 0;

      param_3[0x81] = 0;

      param_3[0x82] = 0;

      param_3[0x83] = 0;

      param_3[0x84] = 0;

      param_3[0x85] = 0;

      param_3[0x86] = 0;

      param_3[0x87] = 0;

      param_3[0x88] = 0;

      param_3[0x89] = 0;

      param_3[0x8a] = 0;

      param_3[0x8b] = 0;

      param_3[0x8c] = 0;

      param_3[0x8d] = 0;

      param_3[0x8e] = 0;

      param_3[0x8f] = 0;

      *puVar1 = 0x31;

      param_3[0x48] = 0x33;

      *puVar2 = 0x35;

      if (*(longlong *)(puVar4 + 4) != 0) {

        FUN_1401b29f0(param_3 + 1,param_3 + 0x37);

      }

      if (((*param_3 & 0x3ff000) != 0) && (lVar5 = *(longlong *)(puVar4 + 2), lVar5 != 0)) {

        if ((*param_3 & 0x3ff000) < 0x2000) {

          do {

            FUN_1401bdd60(param_3 + 1,puVar1,lVar5);

            lVar5 = *(longlong *)(lVar5 + 8);

          } while (lVar5 != 0);

        }

        else {

          do {

            FUN_1401bde60(param_3 + 1,puVar1,param_3 + 0x48,puVar2,*param_3,lVar5);

            lVar5 = *(longlong *)(lVar5 + 8);

          } while (lVar5 != 0);

        }

      }

      param_3[0x91] = puVar4[6];

      *(undefined8 *)(param_3 + 0x92) = *(undefined8 *)(puVar4 + 8);

      param_3[0x94] = puVar4[10];

      *(undefined8 *)(param_3 + 0x96) = *(undefined8 *)(puVar4 + 0xc);

      return;

    }

    if (*(char *)(param_2 + 0x57c) != '\0') {

      FUN_14012e2e0(9,

                    "VULKAN_INTERNAL_AddOptInVulkanOptions: Additional options property was set, but value was null. This may be a bug."

                   );

    }

  }

  return;

}




