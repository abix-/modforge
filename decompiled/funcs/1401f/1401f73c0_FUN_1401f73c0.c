// Address: 0x1401f73c0
// Ghidra name: FUN_1401f73c0
// ============ 0x1401f73c0 FUN_1401f73c0 (size=1361) ============


longlong FUN_1401f73c0(longlong param_1,int param_2,undefined8 param_3,undefined8 param_4,

                      undefined4 param_5,uint param_6,undefined4 param_7)



{

  longlong lVar1;

  uint uVar2;

  char cVar3;

  undefined4 uVar4;

  int iVar5;

  undefined8 uVar6;

  longlong lVar7;

  undefined4 local_res8;

  undefined4 local_resc;

  undefined8 local_res18 [2];

  undefined8 local_348;

  undefined8 uStack_340;

  undefined8 local_338;

  undefined8 uStack_330;

  undefined4 local_328;

  undefined8 local_324;

  undefined8 local_318;

  undefined8 local_310;

  undefined4 local_308;

  undefined4 local_304;

  undefined4 local_300;

  undefined4 local_2fc;

  undefined4 local_2f8;

  undefined4 local_2f4;

  undefined4 local_2f0;

  undefined4 local_2ec;

  undefined8 local_2e8;

  undefined8 uStack_2e0;

  undefined4 local_2d8;

  undefined4 uStack_2d4;

  undefined4 uStack_2d0;

  undefined4 uStack_2cc;

  undefined4 uStack_2c8;

  undefined4 uStack_2c4;

  undefined4 uStack_2c0;

  undefined4 uStack_2bc;

  undefined4 local_2b8;

  undefined4 uStack_2b4;

  undefined8 uStack_2b0;

  undefined8 local_2a8;

  undefined8 uStack_2a0;

  longlong local_298;

  undefined8 uStack_290;

  undefined8 local_288;

  undefined8 uStack_280;

  undefined8 local_278;

  undefined4 *puStack_270;

  undefined8 local_268;

  undefined8 uStack_260;

  undefined8 local_258;

  undefined4 *puStack_250;

  undefined8 local_248;

  undefined8 *puStack_240;

  undefined8 local_238;

  undefined8 uStack_230;

  undefined8 local_228;

  undefined8 uStack_220;

  undefined *local_218;

  undefined8 uStack_210;

  undefined8 local_208;

  undefined8 uStack_200;

  undefined8 local_1f8;

  undefined8 uStack_1f0;

  undefined *local_1e8;

  undefined8 uStack_1e0;

  undefined4 local_1d8;

  undefined8 local_1d4;

  undefined8 local_1cc;

  undefined4 local_1c4;

  undefined8 *local_1c0;

  undefined8 *local_1b8;

  undefined8 *local_1b0;

  undefined8 local_1a8;

  undefined8 *local_1a0;

  undefined8 *local_198;

  undefined8 *local_190;

  undefined8 *local_188;

  undefined8 *local_180;

  undefined8 *local_178;

  undefined8 local_170;

  undefined8 local_168;

  undefined4 local_160;

  undefined8 local_15c;

  undefined8 uStack_154;

  undefined4 local_14c;

  undefined8 local_148;

  undefined8 uStack_140;

  undefined8 local_138;

  undefined8 uStack_130;

  undefined8 local_128;

  undefined8 uStack_120;

  undefined8 local_118;

  undefined8 uStack_110;

  undefined8 local_108;

  undefined8 uStack_100;

  undefined4 *local_f8;

  undefined8 uStack_f0;

  undefined8 local_e8;

  undefined8 uStack_e0;

  undefined8 local_d8;

  undefined8 uStack_d0;

  undefined8 *local_c8;

  undefined8 uStack_c0;

  undefined8 local_b8;

  undefined8 local_a8;

  undefined8 uStack_a0;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  

  uVar2 = param_6;

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  local_1d8 = 0x1c;

  local_res18[0] = 0;

  local_48 = 0;

  local_b8 = 0;

  local_1d4 = 0;

  local_1cc = 0;

  local_1a8 = 0;

  local_14c = 0;

  local_1b8 = &local_268;

  local_1b0 = &local_2a8;

  local_1a0 = &local_148;

  local_198 = &local_2e8;

  local_190 = &local_118;

  local_188 = &local_a8;

  local_180 = &local_e8;

  local_178 = &local_288;

  uStack_230 = 0;

  uStack_260 = 0;

  local_238 = 0x12;

  uStack_210 = 0;

  uStack_2a0 = 0;

  uStack_280 = 0;

  uStack_140 = 0;

  uStack_130 = 0;

  uStack_120 = 0;

  uStack_2e0 = 0;

  local_2d8 = 0;

  uStack_110 = 0;

  uStack_100 = 0;

  uStack_f0 = 0;

  uStack_a0 = 0;

  local_98 = 0;

  uStack_90 = 0;

  local_88 = 0;

  uStack_80 = 0;

  local_78 = 0;

  uStack_70 = 0;

  local_68 = 0;

  uStack_60 = 0;

  local_58 = 0;

  uStack_50 = 0;

  uStack_e0 = 0;

  local_d8 = 0;

  uStack_c0 = 0;

  local_15c = 0;

  uStack_154 = 0;

  uStack_220 = *(undefined8 *)(lVar1 + 0x718 + (longlong)param_2 * 8);

  uStack_200 = 0;

  local_208 = 0x12;

  uStack_1e0 = 0;

  local_228 = 0x100000000;

  local_218 = &DAT_1403424a4;

  uStack_1f0 = *(undefined8 *)(lVar1 + 0x730 + (longlong)param_2 * 8);

  local_1c0 = &local_238;

  local_1f8 = 0x1000000000;

  local_1e8 = &DAT_1403424a4;

  local_1c4 = 2;

  local_268 = 0x13;

  local_248 = 3;

  puStack_240 = &local_318;

  puStack_250 = &local_328;

  puStack_270 = &local_res8;

  local_f8 = &param_6;

  local_c8 = &local_348;

  uStack_340 = 0;

  local_258 = 0x100000000;

  local_318 = 0;

  local_310 = 0x67;

  local_304 = 0;

  local_300 = 0x67;

  local_308 = 1;

  local_2fc = 8;

  local_2f4 = 0;

  local_2f0 = 0x6d;

  local_2f8 = 2;

  local_2ec = 0x10;

  local_328 = 0;

  local_324 = 0x20;

  local_2a8 = 0x14;

  local_298 = (ulonglong)param_6 << 0x20;

  uStack_290 = 0;

  local_148 = 0x16;

  local_128 = 1;

  local_138 = 0x100000000;

  local_288 = 0x1b;

  local_res8 = 0;

  local_resc = 1;

  local_278 = 0x200000000;

  local_2e8 = 0x17;

  uStack_2d4 = 0;

  uStack_2d0 = 0;

  uStack_2cc = 0;

  uStack_2c8 = 0;

  uStack_2c4 = 0;

  uStack_2c0 = 0;

  uStack_2bc = 0;

  local_2b8 = 0;

  uStack_2b4 = 0;

  uStack_2b0 = 0x3f800000;

  local_118 = 0x18;

  param_6 = 0xffffffff;

  local_108 = 0x100000000;

  local_a8 = 0x19;

  local_338 = 0;

  uStack_330 = 0;

  local_e8 = 0x1a;

  uStack_d0 = 0x100000000;

  local_348 = 1;

  uVar4 = FUN_14014df00(param_5);

  uVar4 = FUN_1401f53e0(uVar4);

  local_348 = CONCAT44(uVar4,(undefined4)local_348);

  uVar4 = FUN_14014dee0(param_5);

  uVar4 = FUN_1401f53e0(uVar4);

  local_338 = CONCAT44(local_338._4_4_,uVar4);

  uVar4 = FUN_14014de80(param_5);

  uVar4 = FUN_1401f5470(uVar4);

  uStack_340._4_4_ = uVar4;

  uVar4 = FUN_14014dec0(param_5);

  uVar4 = FUN_1401f53e0(uVar4);

  uStack_340 = CONCAT44(uStack_340._4_4_,uVar4);

  uVar4 = FUN_14014dea0(param_5);

  uVar4 = FUN_1401f53e0(uVar4);

  local_338 = CONCAT44(uVar4,(undefined4)local_338);

  uVar4 = FUN_14014de60(param_5);

  uVar4 = FUN_1401f5470(uVar4);

  uStack_330 = CONCAT44(0xf,uVar4);

  local_168 = *(undefined8 *)(lVar1 + 0x710);

  local_160 = 0;

  local_170 = param_3;

  iVar5 = (*DAT_1403fcf68)(*(undefined8 *)(lVar1 + 0x660),0,1,&local_1d8,0,local_res18);

  if (iVar5 == 0) {

    lVar7 = FUN_140184230(*(undefined8 *)(lVar1 + 0x2860),

                          ((longlong)*(int *)(lVar1 + 0x2858) + 1) * 0x58);

    if (lVar7 != 0) {

      *(int *)((longlong)*(int *)(lVar1 + 0x2858) * 0x58 + lVar7) = param_2;

      *(undefined4 *)((longlong)*(int *)(lVar1 + 0x2858) * 0x58 + 0x34 + lVar7) = param_5;

      *(uint *)((longlong)*(int *)(lVar1 + 0x2858) * 0x58 + 0x38 + lVar7) = uVar2;

      *(undefined4 *)((longlong)*(int *)(lVar1 + 0x2858) * 0x58 + 0x3c + lVar7) = param_7;

      *(undefined8 *)((longlong)*(int *)(lVar1 + 0x2858) * 0x58 + 0x50 + lVar7) = local_res18[0];

      *(undefined8 *)((longlong)*(int *)(lVar1 + 0x2858) * 0x58 + 0x48 + lVar7) = param_4;

      *(undefined8 *)((longlong)*(int *)(lVar1 + 0x2858) * 0x58 + 0x40 + lVar7) = local_170;

      iVar5 = *(int *)(lVar1 + 0x2858);

      *(longlong *)(lVar1 + 0x2860) = lVar7;

      *(int *)(lVar1 + 0x2858) = iVar5 + 1;

      return (longlong)iVar5 * 0x58 + lVar7;

    }

  }

  else {

    cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar3 != '\0') {

      uVar6 = FUN_140241280(iVar5);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkCreateGraphicsPipelines()",uVar6);

    }

    uVar6 = FUN_140241280(iVar5);

    FUN_14012e850("%s: %s","vkCreateGraphicsPipelines()",uVar6);

  }

  return 0;

}




