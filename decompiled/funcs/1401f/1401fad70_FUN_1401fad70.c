// Address: 0x1401fad70
// Ghidra name: FUN_1401fad70
// ============ 0x1401fad70 FUN_1401fad70 (size=7141) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined1 FUN_1401fad70(longlong param_1)



{

  char cVar1;

  

  DAT_1403fce98 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkAcquireNextImageKHR");

  if (DAT_1403fce98 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkAcquireNextImageKHR\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkAcquireNextImageKHR\") failed");

    return 0;

  }

  DAT_1403fcea0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkAllocateCommandBuffers");

  if (DAT_1403fcea0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkAllocateCommandBuffers\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkAllocateCommandBuffers\") failed")

    ;

    return 0;

  }

  DAT_1403fcea8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkAllocateDescriptorSets");

  if (DAT_1403fcea8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkAllocateDescriptorSets\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkAllocateDescriptorSets\") failed")

    ;

    return 0;

  }

  DAT_1403fceb0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkAllocateMemory");

  if (DAT_1403fceb0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkAllocateMemory\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkAllocateMemory\") failed");

    return 0;

  }

  DAT_1403fceb8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkBeginCommandBuffer");

  if (DAT_1403fceb8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkBeginCommandBuffer\") failed")

      ;

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkBeginCommandBuffer\") failed");

    return 0;

  }

  DAT_1403fcec0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkBindBufferMemory");

  if (DAT_1403fcec0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkBindBufferMemory\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkBindBufferMemory\") failed");

    return 0;

  }

  DAT_1403fcec8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkBindImageMemory");

  if (DAT_1403fcec8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkBindImageMemory\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkBindImageMemory\") failed");

    return 0;

  }

  DAT_1403fced0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdBeginRenderPass");

  if (DAT_1403fced0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdBeginRenderPass\") failed")

      ;

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdBeginRenderPass\") failed");

    return 0;

  }

  DAT_1403fced8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdBindDescriptorSets");

  if (DAT_1403fced8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkCmdBindDescriptorSets\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdBindDescriptorSets\") failed");

    return 0;

  }

  DAT_1403fcee0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdBindPipeline");

  if (DAT_1403fcee0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdBindPipeline\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdBindPipeline\") failed");

    return 0;

  }

  DAT_1403fcee8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdBindVertexBuffers");

  if (DAT_1403fcee8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkCmdBindVertexBuffers\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdBindVertexBuffers\") failed");

    return 0;

  }

  _DAT_1403fcef0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdClearColorImage");

  if (_DAT_1403fcef0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdClearColorImage\") failed")

      ;

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdClearColorImage\") failed");

    return 0;

  }

  DAT_1403fcef8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdCopyBufferToImage");

  if (DAT_1403fcef8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkCmdCopyBufferToImage\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdCopyBufferToImage\") failed");

    return 0;

  }

  DAT_1403fcf00 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdCopyImageToBuffer");

  if (DAT_1403fcf00 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkCmdCopyImageToBuffer\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdCopyImageToBuffer\") failed");

    return 0;

  }

  DAT_1403fcf08 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdDraw");

  if (DAT_1403fcf08 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdDraw\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdDraw\") failed");

    return 0;

  }

  DAT_1403fcf10 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdEndRenderPass");

  if (DAT_1403fcf10 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdEndRenderPass\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdEndRenderPass\") failed");

    return 0;

  }

  DAT_1403fcf18 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdPipelineBarrier");

  if (DAT_1403fcf18 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdPipelineBarrier\") failed")

      ;

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdPipelineBarrier\") failed");

    return 0;

  }

  DAT_1403fcf20 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdPushConstants");

  if (DAT_1403fcf20 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdPushConstants\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdPushConstants\") failed");

    return 0;

  }

  DAT_1403fcf28 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdSetScissor");

  if (DAT_1403fcf28 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdSetScissor\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdSetScissor\") failed");

    return 0;

  }

  DAT_1403fcf30 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCmdSetViewport");

  if (DAT_1403fcf30 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdSetViewport\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCmdSetViewport\") failed");

    return 0;

  }

  DAT_1403fcf38 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateBuffer");

  if (DAT_1403fcf38 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateBuffer\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateBuffer\") failed");

    return 0;

  }

  DAT_1403fcf40 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateCommandPool");

  if (DAT_1403fcf40 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateCommandPool\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateCommandPool\") failed");

    return 0;

  }

  DAT_1403fcf48 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateDescriptorPool");

  if (DAT_1403fcf48 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkCreateDescriptorPool\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateDescriptorPool\") failed");

    return 0;

  }

  DAT_1403fcf50 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateDescriptorSetLayout");

  if (DAT_1403fcf50 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkCreateDescriptorSetLayout\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetDeviceProcAddr(device, \"vkCreateDescriptorSetLayout\") failed");

    return 0;

  }

  DAT_1403fcf58 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateFence");

  if (DAT_1403fcf58 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateFence\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateFence\") failed");

    return 0;

  }

  DAT_1403fcf60 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateFramebuffer");

  if (DAT_1403fcf60 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateFramebuffer\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateFramebuffer\") failed");

    return 0;

  }

  DAT_1403fcf68 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateGraphicsPipelines");

  if (DAT_1403fcf68 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkCreateGraphicsPipelines\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateGraphicsPipelines\") failed"

                 );

    return 0;

  }

  DAT_1403fcf70 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateImage");

  if (DAT_1403fcf70 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateImage\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateImage\") failed");

    return 0;

  }

  DAT_1403fcf78 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateImageView");

  if (DAT_1403fcf78 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateImageView\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateImageView\") failed");

    return 0;

  }

  DAT_1403fcf80 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreatePipelineLayout");

  if (DAT_1403fcf80 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkCreatePipelineLayout\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreatePipelineLayout\") failed");

    return 0;

  }

  DAT_1403fcf88 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateRenderPass");

  if (DAT_1403fcf88 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateRenderPass\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateRenderPass\") failed");

    return 0;

  }

  DAT_1403fcf90 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateSampler");

  if (DAT_1403fcf90 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateSampler\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateSampler\") failed");

    return 0;

  }

  DAT_1403fcf98 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateSemaphore");

  if (DAT_1403fcf98 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateSemaphore\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateSemaphore\") failed");

    return 0;

  }

  DAT_1403fcfa0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateShaderModule");

  if (DAT_1403fcfa0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateShaderModule\") failed")

      ;

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateShaderModule\") failed");

    return 0;

  }

  DAT_1403fcfa8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateSwapchainKHR");

  if (DAT_1403fcfa8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateSwapchainKHR\") failed")

      ;

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkCreateSwapchainKHR\") failed");

    return 0;

  }

  DAT_1403fcfb0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyBuffer");

  if (DAT_1403fcfb0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyBuffer\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyBuffer\") failed");

    return 0;

  }

  DAT_1403fcfb8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyCommandPool");

  if (DAT_1403fcfb8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyCommandPool\") failed")

      ;

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyCommandPool\") failed");

    return 0;

  }

  DAT_1403fcfc0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyDevice");

  if (DAT_1403fcfc0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyDevice\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyDevice\") failed");

    return 0;

  }

  DAT_1403fcfc8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyDescriptorPool");

  if (DAT_1403fcfc8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkDestroyDescriptorPool\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyDescriptorPool\") failed");

    return 0;

  }

  DAT_1403fcfd0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyDescriptorSetLayout");

  if (DAT_1403fcfd0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkDestroyDescriptorSetLayout\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetDeviceProcAddr(device, \"vkDestroyDescriptorSetLayout\") failed");

    return 0;

  }

  DAT_1403fcfd8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyFence");

  if (DAT_1403fcfd8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyFence\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyFence\") failed");

    return 0;

  }

  DAT_1403fcfe0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyFramebuffer");

  if (DAT_1403fcfe0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyFramebuffer\") failed")

      ;

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyFramebuffer\") failed");

    return 0;

  }

  DAT_1403fcfe8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyImage");

  if (DAT_1403fcfe8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyImage\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyImage\") failed");

    return 0;

  }

  DAT_1403fcff0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyImageView");

  if (DAT_1403fcff0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyImageView\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyImageView\") failed");

    return 0;

  }

  DAT_1403fcff8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyPipeline");

  if (DAT_1403fcff8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyPipeline\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyPipeline\") failed");

    return 0;

  }

  DAT_1403fd000 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyPipelineLayout");

  if (DAT_1403fd000 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkDestroyPipelineLayout\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyPipelineLayout\") failed");

    return 0;

  }

  DAT_1403fd008 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyRenderPass");

  if (DAT_1403fd008 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyRenderPass\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyRenderPass\") failed");

    return 0;

  }

  DAT_1403fd010 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroySampler");

  if (DAT_1403fd010 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroySampler\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroySampler\") failed");

    return 0;

  }

  DAT_1403fd018 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroySemaphore");

  if (DAT_1403fd018 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroySemaphore\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroySemaphore\") failed");

    return 0;

  }

  DAT_1403fd020 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroyShaderModule");

  if (DAT_1403fd020 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyShaderModule\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroyShaderModule\") failed");

    return 0;

  }

  DAT_1403fd028 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroySwapchainKHR");

  if (DAT_1403fd028 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroySwapchainKHR\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDestroySwapchainKHR\") failed");

    return 0;

  }

  DAT_1403fd030 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDeviceWaitIdle");

  if (DAT_1403fd030 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDeviceWaitIdle\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkDeviceWaitIdle\") failed");

    return 0;

  }

  DAT_1403fd038 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkEndCommandBuffer");

  if (DAT_1403fd038 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkEndCommandBuffer\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkEndCommandBuffer\") failed");

    return 0;

  }

  DAT_1403fd040 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkFreeCommandBuffers");

  if (DAT_1403fd040 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkFreeCommandBuffers\") failed")

      ;

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkFreeCommandBuffers\") failed");

    return 0;

  }

  DAT_1403fd048 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkFreeMemory");

  if (DAT_1403fd048 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkFreeMemory\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkFreeMemory\") failed");

    return 0;

  }

  DAT_1403fd050 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkGetBufferMemoryRequirements")

  ;

  if (DAT_1403fd050 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkGetBufferMemoryRequirements\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetDeviceProcAddr(device, \"vkGetBufferMemoryRequirements\") failed");

    return 0;

  }

  DAT_1403fd058 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkGetImageMemoryRequirements");

  if (DAT_1403fd058 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkGetImageMemoryRequirements\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetDeviceProcAddr(device, \"vkGetImageMemoryRequirements\") failed");

    return 0;

  }

  DAT_1403fd060 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkGetDeviceQueue");

  if (DAT_1403fd060 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkGetDeviceQueue\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkGetDeviceQueue\") failed");

    return 0;

  }

  _DAT_1403fd068 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkGetFenceStatus");

  if (_DAT_1403fd068 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkGetFenceStatus\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkGetFenceStatus\") failed");

    return 0;

  }

  DAT_1403fd070 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkGetSwapchainImagesKHR");

  if (DAT_1403fd070 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkGetSwapchainImagesKHR\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkGetSwapchainImagesKHR\") failed");

    return 0;

  }

  DAT_1403fd078 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkMapMemory");

  if (DAT_1403fd078 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkMapMemory\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkMapMemory\") failed");

    return 0;

  }

  DAT_1403fd080 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkQueuePresentKHR");

  if (DAT_1403fd080 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkQueuePresentKHR\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkQueuePresentKHR\") failed");

    return 0;

  }

  DAT_1403fd088 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkQueueSubmit");

  if (DAT_1403fd088 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkQueueSubmit\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkQueueSubmit\") failed");

    return 0;

  }

  DAT_1403fd090 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkResetCommandBuffer");

  if (DAT_1403fd090 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkResetCommandBuffer\") failed")

      ;

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkResetCommandBuffer\") failed");

    return 0;

  }

  DAT_1403fd098 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkResetCommandPool");

  if (DAT_1403fd098 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkResetCommandPool\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkResetCommandPool\") failed");

    return 0;

  }

  DAT_1403fd0a0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkResetDescriptorPool");

  if (DAT_1403fd0a0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkResetDescriptorPool\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkResetDescriptorPool\") failed");

    return 0;

  }

  DAT_1403fd0a8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkResetFences");

  if (DAT_1403fd0a8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkResetFences\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkResetFences\") failed");

    return 0;

  }

  _DAT_1403fd0b0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkUnmapMemory");

  if (_DAT_1403fd0b0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkUnmapMemory\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkUnmapMemory\") failed");

    return 0;

  }

  DAT_1403fd0b8 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkUpdateDescriptorSets");

  if (DAT_1403fd0b8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetDeviceProcAddr(device, \"vkUpdateDescriptorSets\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkUpdateDescriptorSets\") failed");

    return 0;

  }

  DAT_1403fd0c0 = (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkWaitForFences");

  if (DAT_1403fd0c0 != 0) {

    DAT_1403fd180 =

         (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkCreateSamplerYcbcrConversionKHR");

    DAT_1403fd188 =

         (*DAT_1403fd108)(*(undefined8 *)(param_1 + 0x660),"vkDestroySamplerYcbcrConversionKHR");

    return 1;

  }

  cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

  if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(6,&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkWaitForFences\") failed");

  }

  FUN_14012e850(&DAT_14039bf30,"vkGetDeviceProcAddr(device, \"vkWaitForFences\") failed");

  return 0;

}




