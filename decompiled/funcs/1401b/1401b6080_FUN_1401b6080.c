// Address: 0x1401b6080
// Ghidra name: FUN_1401b6080
// ============ 0x1401b6080 FUN_1401b6080 (size=3627) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8 FUN_1401b6080(longlong param_1,uint *param_2)



{

  undefined8 *puVar1;

  undefined4 uVar2;

  code *pcVar3;

  longlong lVar4;

  int iVar5;

  ulonglong uVar6;

  uint *puVar7;

  undefined8 uVar8;

  undefined8 uVar9;

  ulonglong uVar10;

  uint uVar11;

  bool bVar12;

  undefined4 local_res8 [2];

  undefined8 auStack_370 [5];

  undefined8 local_348 [3];

  undefined4 local_330;

  undefined8 uStack_32c;

  undefined8 local_324;

  undefined8 local_31c;

  undefined8 local_314;

  undefined8 local_30c;

  undefined8 local_304;

  undefined4 local_2f8 [2];

  undefined8 *local_2f0;

  undefined4 local_2e8;

  undefined4 local_2e4;

  undefined4 *local_2e0;

  undefined4 local_2d8;

  undefined8 local_2d0;

  uint local_2c8;

  undefined8 *local_2c0;

  uint *local_2b8;

  uint local_2a8 [2];

  undefined4 *local_2a0;

  uint local_298;

  uint local_294;

  uint local_290;

  uint local_28c;

  undefined4 local_288 [2];

  undefined4 *local_280;

  uint local_278;

  uint local_274;

  uint local_270;

  undefined4 local_268 [2];

  undefined4 *local_260;

  uint local_258;

  undefined4 local_250 [2];

  undefined4 *local_248;

  uint local_240;

  undefined4 local_238 [2];

  undefined4 *local_230;

  uint local_228;

  undefined4 local_220 [4];

  uint local_210;

  uint local_20c;

  undefined4 local_208 [2];

  undefined8 local_200;

  undefined4 local_1f8;

  undefined4 local_1f4;

  undefined4 local_1f0;

  undefined4 *local_1e8;

  undefined4 local_1d8 [2];

  uint *local_1d0;

  undefined8 local_1c8;

  undefined8 uStack_1c0;

  undefined8 local_1b8;

  undefined8 uStack_1b0;

  undefined8 local_1a8;

  undefined8 uStack_1a0;

  undefined8 local_198;

  undefined8 uStack_190;

  undefined8 local_188;

  undefined8 uStack_180;

  undefined8 local_178;

  undefined8 uStack_170;

  undefined8 local_168;

  undefined8 uStack_160;

  undefined8 local_158;

  undefined8 uStack_150;

  undefined8 local_148;

  undefined8 uStack_140;

  undefined8 local_138;

  undefined8 uStack_130;

  undefined8 local_128;

  undefined8 uStack_120;

  uint local_118;

  uint uStack_114;

  uint uStack_110;

  uint uStack_10c;

  uint local_108;

  uint uStack_104;

  uint uStack_100;

  uint uStack_fc;

  undefined8 local_f8;

  uint local_f0;

  undefined1 local_e8 [36];

  int local_c4;

  int local_b4;

  

  local_1f4 = *(undefined4 *)(param_1 + 0x7c0);

  local_1e8 = local_res8;

  local_res8[0] = 0x3f800000;

  local_208[0] = 2;

  local_200 = 0;

  local_1f8 = 0;

  local_1f0 = 1;

  auStack_370[0] = 0x1401b6104;

  (**(code **)(param_1 + 0x960))(*(undefined8 *)(param_1 + 8),local_e8);

  if (local_b4 != 0) {

    param_2[0xe] = 1;

    *(undefined1 *)(param_1 + 0x592) = 1;

  }

  if (local_c4 != 0) {

    param_2[10] = 1;

    *(undefined1 *)(param_1 + 0x593) = 1;

  }

  local_2f8[0] = 3;

  if (*(char *)(param_1 + 0x58b) == '\0') {

    local_2f0 = (undefined8 *)0x0;

  }

  else {

    local_348[0]._0_4_ = 0x3b9d46b8;

    local_348[1] = 0;

    local_348[2] = 0;

    local_330 = 0;

    uStack_32c = 1;

    local_324 = 0;

    local_31c = 0;

    local_314 = 0;

    local_30c = 0;

    local_304 = 0;

    local_2f0 = local_348;

  }

  local_2e0 = local_208;

  local_2e8 = 0;

  local_2e4 = 1;

  local_2d8 = 0;

  local_2d0 = 0;

  local_2c8 = (uint)*(byte *)(param_1 + 0x589) +

              (uint)*(byte *)(param_1 + 0x58d) + (uint)*(byte *)(param_1 + 0x58c) +

              (uint)*(byte *)(param_1 + 0x58b) + (uint)*(byte *)(param_1 + 0x58a) +

              (uint)*(byte *)(param_1 + 0x588);

  uVar6 = (ulonglong)local_2c8 * 8 + 0xf;

  if (uVar6 <= (ulonglong)local_2c8 * 8) {

    uVar6 = 0xffffffffffffff0;

  }

  auStack_370[0] = 0x1401b61f6;

  lVar4 = -(uVar6 & 0xfffffffffffffff0);

  puVar1 = (undefined8 *)((longlong)local_348 + lVar4);

  bVar12 = *(byte *)(param_1 + 0x588) != 0;

  if (bVar12) {

    *puVar1 = "VK_KHR_swapchain";

  }

  uVar6 = (ulonglong)bVar12;

  if (*(char *)(param_1 + 0x589) != '\0') {

    uVar6 = (ulonglong)(byte)(bVar12 + 1);

    puVar1[bVar12] = "VK_KHR_maintenance1";

  }

  uVar10 = uVar6;

  if (*(char *)(param_1 + 0x58a) != '\0') {

    uVar10 = (ulonglong)(byte)((char)uVar6 + 1);

    puVar1[uVar6] = "VK_KHR_driver_properties";

  }

  uVar6 = uVar10;

  if (*(char *)(param_1 + 0x58b) != '\0') {

    uVar6 = (ulonglong)(byte)((char)uVar10 + 1);

    puVar1[uVar10] = "VK_KHR_portability_subset";

  }

  uVar10 = uVar6;

  if (*(char *)(param_1 + 0x58c) != '\0') {

    uVar10 = (ulonglong)(byte)((char)uVar6 + 1);

    puVar1[uVar6] = "VK_MSFT_layered_driver";

  }

  if (*(char *)(param_1 + 0x58d) != '\0') {

    puVar1[uVar10] = "VK_EXT_texture_compression_astc_hdr";

  }

  local_2c0 = puVar1;

  if (((char)param_2[0x90] == '\0') || (uVar11 = *param_2 & 0x3ff000, uVar11 == 0)) {

    local_2b8 = param_2 + 1;

  }

  else {

    local_1d8[0] = 0x3b9bb078;

    local_f8 = *(undefined8 *)(param_2 + 0x35);

    local_1c8 = *(undefined8 *)(param_2 + 1);

    uStack_1c0 = *(undefined8 *)(param_2 + 3);

    local_1b8 = *(undefined8 *)(param_2 + 5);

    uStack_1b0 = *(undefined8 *)(param_2 + 7);

    local_1a8 = *(undefined8 *)(param_2 + 9);

    uStack_1a0 = *(undefined8 *)(param_2 + 0xb);

    local_198 = *(undefined8 *)(param_2 + 0xd);

    uStack_190 = *(undefined8 *)(param_2 + 0xf);

    local_188 = *(undefined8 *)(param_2 + 0x11);

    uStack_180 = *(undefined8 *)(param_2 + 0x13);

    local_178 = *(undefined8 *)(param_2 + 0x15);

    uStack_170 = *(undefined8 *)(param_2 + 0x17);

    local_168 = *(undefined8 *)(param_2 + 0x19);

    uStack_160 = *(undefined8 *)(param_2 + 0x1b);

    local_148 = *(undefined8 *)(param_2 + 0x21);

    uStack_140 = *(undefined8 *)(param_2 + 0x23);

    local_158 = *(undefined8 *)(param_2 + 0x1d);

    uStack_150 = *(undefined8 *)(param_2 + 0x1f);

    local_138 = *(undefined8 *)(param_2 + 0x25);

    uStack_130 = *(undefined8 *)(param_2 + 0x27);

    local_128 = *(undefined8 *)(param_2 + 0x29);

    uStack_120 = *(undefined8 *)(param_2 + 0x2b);

    local_118 = param_2[0x2d];

    uStack_114 = param_2[0x2e];

    uStack_110 = param_2[0x2f];

    uStack_10c = param_2[0x30];

    local_108 = param_2[0x31];

    uStack_104 = param_2[0x32];

    uStack_100 = param_2[0x33];

    uStack_fc = param_2[0x34];

    local_f0 = param_2[0x37];

    if (uVar11 < 0x1001) {

      *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b63b3;

      FUN_1402f94c0(local_2a8,0,0xa0);

      local_298 = param_2[0x3c];

      local_28c = param_2[0x3f];

      local_290 = param_2[0x3e];

      local_294 = param_2[0x3d];

      local_278 = param_2[0x40];

      local_274 = param_2[0x41];

      local_270 = param_2[0x42];

      local_258 = param_2[0x45];

      local_240 = param_2[0x46];

      local_228 = param_2[0x47];

      local_20c = param_2[0x44];

      local_210 = param_2[0x43];

      local_1d0 = local_2a8;

      local_2a0 = local_288;

      local_280 = local_268;

      local_260 = local_250;

      local_248 = local_238;

      local_230 = local_220;

      local_2f0 = (undefined8 *)local_1d8;

      local_2a8[0] = 0x3b9c0e38;

      local_288[0] = 0x3b9b9909;

      local_268[0] = 0x3b9d0069;

      local_250[0] = 0x3b9d2b64;

      local_238[0] = 0x3b9bc018;

      local_220[0] = 0x3b9c9ec0;

      local_2b8 = (uint *)0x0;

    }

    else {

      local_1d0 = param_2 + 0x38;

      param_2[0x7e] = 0;

      param_2[0x7f] = 0;

      local_2b8 = (uint *)0x0;

      *(uint **)(param_2 + 0x3a) = param_2 + 0x48;

      puVar7 = param_2 + 0x7c;

      if (uVar11 < 0x2001) {

        puVar7 = (uint *)0x0;

      }

      *(uint **)(param_2 + 0x4a) = puVar7;

      local_2f0 = (undefined8 *)local_1d8;

    }

  }

  pcVar3 = *(code **)(param_1 + 0x940);

  puVar1 = (undefined8 *)(param_1 + 0x570);

  uVar8 = *(undefined8 *)(param_1 + 8);

  *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6510;

  iVar5 = (*pcVar3)(uVar8,local_2f8,0,puVar1);

  if (iVar5 == 0) {

    pcVar3 = *(code **)(param_1 + 0x938);

    uVar8 = *puVar1;

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6578;

    uVar9 = (*pcVar3)(uVar8,"vkAllocateCommandBuffers");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0x9e8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6592;

    uVar9 = (*pcVar3)(uVar8,"vkAllocateDescriptorSets");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0x9f0) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b65ac;

    uVar9 = (*pcVar3)(uVar8,"vkAllocateMemory");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0x9f8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b65c6;

    uVar9 = (*pcVar3)(uVar8,"vkBeginCommandBuffer");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa00) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b65e0;

    uVar9 = (*pcVar3)(uVar8,"vkBindBufferMemory");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa08) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b65fa;

    uVar9 = (*pcVar3)(uVar8,"vkBindImageMemory");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa10) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6614;

    uVar9 = (*pcVar3)(uVar8,"vkCmdBeginRenderPass");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa18) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b662e;

    uVar9 = (*pcVar3)(uVar8,"vkCmdBindDescriptorSets");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa20) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6648;

    uVar9 = (*pcVar3)(uVar8,"vkCmdBindIndexBuffer");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa28) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6662;

    uVar9 = (*pcVar3)(uVar8,"vkCmdBindPipeline");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa30) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b667c;

    uVar9 = (*pcVar3)(uVar8,"vkCmdBindVertexBuffers");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa38) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6696;

    uVar9 = (*pcVar3)(uVar8,"vkCmdBlitImage");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa40) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b66b0;

    uVar9 = (*pcVar3)(uVar8,"vkCmdClearAttachments");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa48) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b66ca;

    uVar9 = (*pcVar3)(uVar8,"vkCmdClearColorImage");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa50) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b66e4;

    uVar9 = (*pcVar3)(uVar8,"vkCmdClearDepthStencilImage");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa58) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b66fe;

    uVar8 = (*pcVar3)(uVar8,"vkCmdCopyBuffer");

    *(undefined8 *)(param_1 + 0xa60) = uVar8;

    pcVar3 = *(code **)(param_1 + 0x938);

    uVar8 = *puVar1;

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6718;

    uVar9 = (*pcVar3)(uVar8,"vkCmdCopyImage");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa68) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6732;

    uVar9 = (*pcVar3)(uVar8,"vkCmdCopyBufferToImage");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa70) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b674c;

    uVar9 = (*pcVar3)(uVar8,"vkCmdCopyImageToBuffer");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa78) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6766;

    uVar9 = (*pcVar3)(uVar8,"vkCmdDispatch");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa80) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6780;

    uVar9 = (*pcVar3)(uVar8,"vkCmdDispatchIndirect");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa88) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b679a;

    uVar9 = (*pcVar3)(uVar8,"vkCmdDraw");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa90) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b67b4;

    uVar9 = (*pcVar3)(uVar8,"vkCmdDrawIndexed");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xa98) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b67ce;

    uVar9 = (*pcVar3)(uVar8,"vkCmdDrawIndexedIndirect");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xaa0) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b67e8;

    uVar9 = (*pcVar3)(uVar8,"vkCmdDrawIndirect");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xaa8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6802;

    uVar9 = (*pcVar3)(uVar8,"vkCmdEndRenderPass");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xab0) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b681c;

    uVar9 = (*pcVar3)(uVar8,"vkCmdPipelineBarrier");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xab8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6836;

    uVar9 = (*pcVar3)(uVar8,"vkCmdResolveImage");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xac0) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6850;

    uVar9 = (*pcVar3)(uVar8,"vkCmdSetBlendConstants");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xac8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b686a;

    uVar9 = (*pcVar3)(uVar8,"vkCmdSetDepthBias");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xad0) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6884;

    uVar9 = (*pcVar3)(uVar8,"vkCmdSetScissor");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xad8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b689e;

    uVar8 = (*pcVar3)(uVar8,"vkCmdSetStencilReference");

    *(undefined8 *)(param_1 + 0xae0) = uVar8;

    pcVar3 = *(code **)(param_1 + 0x938);

    uVar8 = *puVar1;

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b68b8;

    uVar9 = (*pcVar3)(uVar8,"vkCmdSetViewport");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xae8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b68d2;

    uVar9 = (*pcVar3)(uVar8,"vkCreateBuffer");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xaf0) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b68ec;

    uVar9 = (*pcVar3)(uVar8,"vkCreateCommandPool");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xaf8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6906;

    uVar9 = (*pcVar3)(uVar8,"vkCreateDescriptorPool");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb00) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6920;

    uVar9 = (*pcVar3)(uVar8,"vkCreateDescriptorSetLayout");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb08) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b693a;

    uVar9 = (*pcVar3)(uVar8,"vkCreateFence");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb10) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6954;

    uVar9 = (*pcVar3)(uVar8,"vkCreateFramebuffer");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb18) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b696e;

    uVar9 = (*pcVar3)(uVar8,"vkCreateComputePipelines");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb20) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6988;

    uVar9 = (*pcVar3)(uVar8,"vkCreateGraphicsPipelines");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb28) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b69a2;

    uVar9 = (*pcVar3)(uVar8,"vkCreateImage");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb30) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b69bc;

    uVar9 = (*pcVar3)(uVar8,"vkCreateImageView");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb38) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b69d6;

    uVar9 = (*pcVar3)(uVar8,"vkCreatePipelineCache");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb40) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b69f0;

    uVar9 = (*pcVar3)(uVar8,"vkCreatePipelineLayout");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb48) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6a0a;

    uVar9 = (*pcVar3)(uVar8,"vkCreateRenderPass");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb50) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6a24;

    uVar9 = (*pcVar3)(uVar8,"vkCreateSampler");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb58) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6a3e;

    uVar9 = (*pcVar3)(uVar8,"vkCreateSemaphore");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb60) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6a58;

    uVar9 = (*pcVar3)(uVar8,"vkCreateShaderModule");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb68) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6a72;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyBuffer");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb70) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6a8c;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyCommandPool");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb78) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6aa6;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyDescriptorPool");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb80) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6ac0;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyDescriptorSetLayout");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb88) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6ada;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyDevice");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb90) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6af4;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyFence");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xb98) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6b0e;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyFramebuffer");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xba0) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6b28;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyImage");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xba8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6b42;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyImageView");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xbb0) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6b5c;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyPipeline");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 3000) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6b76;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyPipelineCache");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xbc0) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6b90;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyPipelineLayout");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xbc8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6baa;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyRenderPass");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xbd0) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6bc4;

    uVar9 = (*pcVar3)(uVar8,"vkDestroySampler");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xbd8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6bde;

    uVar9 = (*pcVar3)(uVar8,"vkDestroySemaphore");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xbe0) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6bf8;

    uVar9 = (*pcVar3)(uVar8,"vkDestroyShaderModule");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xbe8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6c12;

    uVar9 = (*pcVar3)(uVar8,"vkDeviceWaitIdle");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xbf0) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6c2c;

    uVar9 = (*pcVar3)(uVar8,"vkEndCommandBuffer");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xbf8) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6c46;

    uVar9 = (*pcVar3)(uVar8,"vkFreeCommandBuffers");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc00) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6c60;

    uVar9 = (*pcVar3)(uVar8,"vkFreeMemory");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc08) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6c7a;

    uVar9 = (*pcVar3)(uVar8,"vkGetDeviceQueue");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc10) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6c94;

    uVar9 = (*pcVar3)(uVar8,"vkGetPipelineCacheData");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc18) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6cae;

    uVar9 = (*pcVar3)(uVar8,"vkGetFenceStatus");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc20) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6cc8;

    uVar9 = (*pcVar3)(uVar8,"vkGetBufferMemoryRequirements");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc28) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6ce2;

    uVar9 = (*pcVar3)(uVar8,"vkGetImageMemoryRequirements");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc30) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6cfc;

    uVar9 = (*pcVar3)(uVar8,"vkMapMemory");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc38) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6d16;

    uVar9 = (*pcVar3)(uVar8,"vkQueueSubmit");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc40) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6d30;

    uVar9 = (*pcVar3)(uVar8,"vkQueueWaitIdle");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc48) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6d4a;

    uVar9 = (*pcVar3)(uVar8,"vkResetCommandBuffer");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc50) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6d64;

    uVar9 = (*pcVar3)(uVar8,"vkResetCommandPool");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc58) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6d7e;

    uVar9 = (*pcVar3)(uVar8,"vkResetDescriptorPool");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc60) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6d98;

    uVar8 = (*pcVar3)(uVar8,"vkResetFences");

    *(undefined8 *)(param_1 + 0xc68) = uVar8;

    pcVar3 = *(code **)(param_1 + 0x938);

    uVar8 = *puVar1;

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6db2;

    uVar9 = (*pcVar3)(uVar8,"vkUnmapMemory");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc70) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6dcc;

    uVar9 = (*pcVar3)(uVar8,"vkUpdateDescriptorSets");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc78) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6de6;

    uVar9 = (*pcVar3)(uVar8,"vkWaitForFences");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc80) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6e00;

    uVar9 = (*pcVar3)(uVar8,"vkAcquireNextImageKHR");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc88) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6e1a;

    uVar9 = (*pcVar3)(uVar8,"vkCreateSwapchainKHR");

    uVar8 = *puVar1;

    *(undefined8 *)(param_1 + 0xc90) = uVar9;

    pcVar3 = *(code **)(param_1 + 0x938);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6e34;

    uVar8 = (*pcVar3)(uVar8,"vkDestroySwapchainKHR");

    *(undefined8 *)(param_1 + 0xc98) = uVar8;

    pcVar3 = *(code **)(param_1 + 0x938);

    uVar8 = *puVar1;

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6e4e;

    uVar8 = (*pcVar3)(uVar8,"vkQueuePresentKHR");

    *(undefined8 *)(param_1 + 0xca0) = uVar8;

    pcVar3 = *(code **)(param_1 + 0x938);

    uVar8 = *puVar1;

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6e68;

    uVar8 = (*pcVar3)(uVar8,"vkGetSwapchainImagesKHR");

    *(undefined8 *)(param_1 + 0xca8) = uVar8;

    pcVar3 = *(code **)(param_1 + 0xc10);

    uVar2 = *(undefined4 *)(param_1 + 0x7c0);

    uVar8 = *puVar1;

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6e8b;

    (*pcVar3)(uVar8,uVar2,0,param_1 + 0x7c8);

    uVar8 = 1;

  }

  else {

    if (*(char *)(param_1 + 0x57c) != '\0') {

      *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6526;

      uVar8 = FUN_1401c0ba0(iVar5);

                    /* WARNING: Subroutine does not return */

      *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6541;

      FUN_14012e0b0(9,"%s %s","vkCreateDevice",uVar8);

    }

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b6548;

    uVar8 = FUN_1401c0ba0(iVar5);

    *(undefined8 *)((longlong)auStack_370 + lVar4) = 0x1401b655e;

    FUN_14012e850("%s %s","vkCreateDevice",uVar8);

    uVar8 = 0;

  }

  return uVar8;

}




