// Address: 0x1401afef0
// Ghidra name: FUN_1401afef0
// ============ 0x1401afef0 FUN_1401afef0 (size=2476) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 * FUN_1401afef0(longlong param_1,longlong *param_2)



{

  longlong lVar1;

  longlong *plVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  undefined8 *puVar5;

  code *pcVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  longlong lVar10;

  char cVar11;

  int iVar12;

  undefined4 *puVar13;

  ulonglong uVar14;

  undefined8 uVar15;

  longlong lVar16;

  longlong lVar17;

  uint uVar18;

  uint uVar19;

  undefined4 uVar20;

  undefined4 local_res8 [2];

  undefined8 auStack_340 [5];

  longlong alStack_318 [2];

  undefined8 local_308;

  undefined8 uStack_300;

  undefined8 local_2f8;

  undefined8 uStack_2f0;

  undefined8 local_2e8;

  undefined4 local_2d8 [2];

  undefined8 local_2d0;

  undefined4 local_2c8;

  uint local_2c4;

  uint local_2c0;

  undefined4 local_2bc;

  undefined4 local_2b8;

  uint local_2b4;

  undefined4 local_2b0;

  undefined4 local_2ac;

  undefined4 local_2a8;

  undefined4 local_2a4;

  uint local_2a0;

  uint local_29c;

  undefined4 local_298;

  undefined4 local_294;

  undefined4 local_290;

  undefined4 local_28c;

  undefined4 local_288;

  uint local_284;

  uint local_280;

  undefined8 local_27c;

  undefined4 local_274;

  undefined4 local_268 [2];

  undefined8 local_260;

  undefined4 local_258;

  uint local_254;

  undefined4 local_250;

  undefined4 local_24c;

  undefined4 local_248;

  undefined4 local_244;

  uint local_240;

  undefined4 local_23c;

  undefined4 local_238;

  undefined4 local_234;

  undefined4 local_230;

  undefined4 local_228 [2];

  undefined8 local_220;

  undefined4 local_218;

  undefined4 local_214;

  undefined4 local_210;

  undefined4 local_20c;

  undefined4 *local_208;

  uint local_200;

  undefined4 local_1fc;

  undefined4 local_1f8 [2];

  undefined8 local_1f0;

  undefined4 local_1e8;

  undefined4 local_1e4;

  undefined4 local_1e0;

  undefined4 local_1d8 [2];

  undefined8 local_1d0;

  undefined4 local_1c8;

  undefined4 local_1c4;

  undefined *local_1c0;

  undefined4 local_1b8 [2];

  undefined8 local_1b0;

  undefined4 local_1a8;

  undefined4 local_1a4;

  longlong local_1a0;

  uint local_198;

  longlong local_190;

  undefined4 local_188 [2];

  undefined8 local_180;

  undefined4 local_178;

  undefined4 local_174;

  undefined8 local_170;

  undefined4 local_168;

  undefined8 local_160;

  undefined4 local_158 [2];

  undefined8 local_150;

  undefined8 local_148;

  undefined4 local_140;

  uint local_13c;

  longlong local_138;

  undefined8 local_130;

  undefined8 uStack_128;

  undefined4 local_118 [2];

  undefined8 local_110;

  undefined4 local_108;

  undefined4 local_104;

  undefined8 local_100;

  undefined8 local_f8;

  undefined8 local_f0;

  undefined4 local_e8;

  undefined8 local_e0;

  undefined4 local_d8;

  undefined4 local_d4;

  undefined8 local_d0;

  undefined8 local_c8;

  undefined8 local_c0;

  undefined4 local_b8 [2];

  undefined8 local_b0;

  undefined4 local_a8;

  undefined4 local_a4;

  undefined4 *local_a0;

  undefined4 *local_98;

  undefined4 *local_90;

  undefined8 local_88;

  undefined4 *local_80;

  undefined4 *local_78;

  undefined4 *local_70;

  undefined4 *local_68;

  undefined4 *local_60;

  undefined4 *local_58;

  undefined8 local_50;

  undefined8 local_48;

  undefined4 local_40;

  undefined8 local_38;

  undefined4 local_30;

  

  auStack_340[0] = 0x1401aff2b;

  puVar13 = (undefined4 *)FUN_1401841f0(0x50);

  uVar14 = (ulonglong)*(uint *)(param_2 + 3) * 0xc + 0xf;

  if (uVar14 <= (ulonglong)*(uint *)(param_2 + 3) * 0xc) {

    uVar14 = 0xffffffffffffff0;

  }

  auStack_340[0] = 0x1401aff58;

  lVar7 = -(uVar14 & 0xfffffffffffffff0);

  lVar16 = (longlong)&local_308 + lVar7;

  uVar14 = (ulonglong)*(uint *)(param_2 + 5) * 0x10 + 0xf;

  if (uVar14 <= (ulonglong)*(uint *)(param_2 + 5) * 0x10) {

    uVar14 = 0xffffffffffffff0;

  }

  *(undefined8 *)((longlong)auStack_340 + lVar7) = 0x1401aff7f;

  lVar8 = -(uVar14 & 0xfffffffffffffff0);

  lVar10 = (longlong)&local_308 + lVar8 + lVar7;

  uVar14 = (ulonglong)*(uint *)(param_2 + 0x12) * 0x20 + 0xf;

  if (uVar14 <= (ulonglong)*(uint *)(param_2 + 0x12) * 0x20) {

    uVar14 = 0xffffffffffffff0;

  }

  *(undefined8 *)((longlong)auStack_340 + lVar8 + lVar7) = 0x1401affa9;

  local_308 = param_2[0x11];

  uStack_300 = param_2[0x12];

  lVar9 = -(uVar14 & 0xfffffffffffffff0);

  local_2f8 = param_2[0x13];

  uVar20 = *(undefined4 *)(&DAT_1403e4250 + (longlong)(int)param_2[10] * 4);

  lVar1 = (longlong)&local_308 + lVar9 + lVar8 + lVar7;

  *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401affe8;

  uVar15 = FUN_1401b8380(param_1,&local_308,uVar20);

  lVar17 = *param_2;

  local_1d8[0] = 0x1b;

  local_1d0 = 0;

  local_1c8 = 0;

  local_1c0 = &DAT_140340bd8;

  local_1c4 = 4;

  *(longlong *)(puVar13 + 0xe) = lVar17;

  *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b0031;

  FUN_140138fb0(lVar17 + 0x24);

  local_118[0] = 0x12;

  local_110 = 0;

  local_108 = 0;

  local_104 = 1;

  local_100 = **(undefined8 **)(puVar13 + 0xe);

  local_f8 = *(undefined8 *)(*(longlong *)(puVar13 + 0xe) + 8);

  lVar17 = param_2[1];

  local_f0 = 0;

  *(longlong *)(puVar13 + 0x10) = lVar17;

  *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b008e;

  FUN_140138fb0(lVar17 + 0x24);

  local_e8 = 0x12;

  local_e0 = 0;

  local_d8 = 0;

  local_d4 = 0x10;

  local_d0 = **(undefined8 **)(puVar13 + 0x10);

  local_c8 = *(undefined8 *)(*(longlong *)(puVar13 + 0x10) + 8);

  local_c0 = 0;

  if (*(char *)(param_1 + 0x57c) != '\0') {

    if (*(int *)(*(longlong *)(puVar13 + 0xe) + 0x10) != 0) {

      do {

        *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b0110;

        iVar12 = FUN_14017f2a0(&DAT_1403e4288,"VULKAN_CreateGraphicsPipeline",

                               "C:\\dev\\SDL-3.4.4\\src\\gpu\\vulkan\\SDL_gpu_vulkan.c",0x18c5);

      } while (iVar12 == 0);

      if (iVar12 == 1) {

        pcVar6 = (code *)swi(3);

        puVar13 = (undefined4 *)(*pcVar6)();

        return puVar13;

      }

    }

    if (*(int *)(*(longlong *)(puVar13 + 0x10) + 0x10) != 1) {

      do {

        *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b0150;

        iVar12 = FUN_14017f2a0(&DAT_1403e42b8,"VULKAN_CreateGraphicsPipeline",

                               "C:\\dev\\SDL-3.4.4\\src\\gpu\\vulkan\\SDL_gpu_vulkan.c",0x18c8);

      } while (iVar12 == 0);

      if (iVar12 == 1) {

        pcVar6 = (code *)swi(3);

        puVar13 = (undefined4 *)(*pcVar6)();

        return puVar13;

      }

    }

  }

  uVar14 = 0;

  if ((int)param_2[3] != 0) {

    do {

      uVar18 = (int)uVar14 + 1;

      *(undefined4 *)(lVar16 + uVar14 * 0xc) = *(undefined4 *)(param_2[2] + uVar14 * 0x10);

      *(undefined4 *)((longlong)&uStack_300 + uVar14 * 0xc + lVar7) =

           *(undefined4 *)(&DAT_1403e4260 + (longlong)*(int *)(param_2[2] + 8 + uVar14 * 0x10) * 4);

      *(undefined4 *)((longlong)&local_308 + uVar14 * 0xc + lVar7 + 4) =

           *(undefined4 *)(param_2[2] + 4 + uVar14 * 0x10);

      uVar14 = (ulonglong)uVar18;

    } while (uVar18 < *(uint *)(param_2 + 3));

  }

  local_198 = 0;

  uVar14 = 0;

  if ((int)param_2[5] != 0) {

    do {

      uVar18 = (int)uVar14 + 1;

      *(undefined4 *)((longlong)&local_308 + uVar14 * 0x10 + lVar8 + lVar7 + 4) =

           *(undefined4 *)(param_2[4] + 4 + uVar14 * 0x10);

      *(undefined4 *)((longlong)&uStack_300 + uVar14 * 0x10 + lVar8 + lVar7) =

           *(undefined4 *)(&DAT_1403e40e0 + (longlong)*(int *)(param_2[4] + 8 + uVar14 * 0x10) * 4);

      *(undefined4 *)(lVar10 + uVar14 * 0x10) = *(undefined4 *)(param_2[4] + uVar14 * 0x10);

      *(undefined4 *)((longlong)&uStack_300 + uVar14 * 0x10 + lVar8 + lVar7 + 4) =

           *(undefined4 *)(param_2[4] + 0xc + uVar14 * 0x10);

      local_198 = *(uint *)(param_2 + 5);

      uVar14 = (ulonglong)uVar18;

    } while (uVar18 < local_198);

  }

  local_1a4 = (undefined4)param_2[3];

  uVar14 = 0;

  local_1b8[0] = 0x13;

  local_1b0 = 0;

  local_1e4 = *(undefined4 *)(&DAT_1403e4160 + (longlong)(int)param_2[6] * 4);

  uVar20 = 0;

  local_1a8 = 0;

  local_1f8[0] = 0x14;

  local_1f0 = 0;

  local_1e8 = 0;

  local_1e0 = 0;

  puVar13[10] = (int)param_2[6];

  local_188[0] = 0x16;

  local_180 = 0;

  local_254 = (uint)(*(char *)((longlong)param_2 + 0x4d) == '\0');

  local_178 = 0;

  local_174 = 1;

  local_170 = 0;

  local_168 = 1;

  local_160 = 0;

  local_268[0] = 0x17;

  local_260 = 0;

  local_258 = 0;

  local_250 = 0;

  local_1a0 = lVar16;

  local_190 = lVar10;

  if (*(int *)((longlong)param_2 + 0x34) != 0) {

    if ((*(char *)(param_1 + 0x592) == '\0') || (*(int *)((longlong)param_2 + 0x34) != 1)) {

      if (*(char *)(param_1 + 0x57b) == '\0') {

        *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b0312;

        FUN_14012e2e0(9,"Unsupported fill mode requested, using FILL!");

        *(undefined1 *)(param_1 + 0x57b) = 1;

      }

    }

    else {

      uVar20 = 1;

    }

  }

  local_23c = (undefined4)param_2[8];

  local_248 = *(undefined4 *)(&DAT_1403e4178 + (longlong)(int)param_2[7] * 4);

  local_238 = *(undefined4 *)((longlong)param_2 + 0x44);

  local_234 = (undefined4)param_2[9];

  local_244 = *(undefined4 *)(&DAT_1403e4188 + (longlong)*(int *)((longlong)param_2 + 0x3c) * 4);

  local_240 = (uint)*(byte *)((longlong)param_2 + 0x4c);

  local_230 = 0x3f800000;

  local_res8[0] = 0xffffffff;

  local_214 = *(undefined4 *)(&DAT_1403e4250 + (longlong)(int)param_2[10] * 4);

  local_208 = local_res8;

  local_200 = (uint)*(byte *)((longlong)param_2 + 0x59);

  local_2c4 = (uint)*(byte *)((longlong)param_2 + 0x82);

  local_2c0 = (uint)*(byte *)((longlong)param_2 + 0x83);

  local_228[0] = 0x18;

  local_220 = 0;

  local_218 = 0;

  local_2bc = *(undefined4 *)(&DAT_1403e41e0 + (longlong)*(int *)((longlong)param_2 + 0x5c) * 4);

  local_2b4 = (uint)*(byte *)((longlong)param_2 + 0x84);

  local_210 = 0;

  local_20c = 0x3f800000;

  local_1fc = 0;

  local_2b0 = *(undefined4 *)(&DAT_1403e4208 + (longlong)(int)param_2[0xe] * 4);

  local_2d8[0] = 0x19;

  local_2d0 = 0;

  local_2c8 = 0;

  local_2ac = *(undefined4 *)(&DAT_1403e4208 + (longlong)*(int *)((longlong)param_2 + 0x74) * 4);

  local_2b8 = 0;

  local_2a0 = (uint)*(byte *)(param_2 + 0x10);

  local_29c = (uint)*(byte *)((longlong)param_2 + 0x81);

  local_2a8 = *(undefined4 *)(&DAT_1403e4208 + (longlong)(int)param_2[0xf] * 4);

  local_298 = 0;

  local_2a4 = *(undefined4 *)(&DAT_1403e41e0 + (longlong)*(int *)((longlong)param_2 + 0x7c) * 4);

  local_27c = 0;

  local_274 = 0;

  local_294 = *(undefined4 *)(&DAT_1403e4208 + (longlong)(int)param_2[0xc] * 4);

  local_290 = *(undefined4 *)(&DAT_1403e4208 + (longlong)*(int *)((longlong)param_2 + 100) * 4);

  local_28c = *(undefined4 *)(&DAT_1403e4208 + (longlong)(int)param_2[0xd] * 4);

  local_288 = *(undefined4 *)(&DAT_1403e41e0 + (longlong)*(int *)((longlong)param_2 + 0x6c) * 4);

  local_13c = 0;

  local_284 = local_2a0;

  local_280 = local_29c;

  local_24c = uVar20;

  if ((int)param_2[0x12] != 0) {

    do {

      lVar16 = param_2[0x11];

      plVar2 = (longlong *)(lVar16 + 4 + uVar14 * 0x24);

      lVar10 = *plVar2;

      uStack_300 = plVar2[1];

      plVar2 = (longlong *)(lVar16 + 0x14 + uVar14 * 0x24);

      local_2f8 = *plVar2;

      uStack_2f0 = plVar2[1];

      uVar3 = *(undefined8 *)(lVar16 + 0x1c + uVar14 * 0x24);

      uVar18 = (uint)uVar3 & 0xff;

      if ((char)((ulonglong)uVar3 >> 0x10) == '\0') {

        uVar18 = 0xf;

      }

      lVar17 = uVar14 * 0x20;

      uVar19 = (int)uVar14 + 1;

      uVar14 = (ulonglong)uVar19;

      local_308 = lVar10;

      *(uint *)(lVar17 + lVar1) = (uint)((ulonglong)uVar3 >> 8) & 0xff;

      *(uint *)(lVar17 + 0x1c + lVar1) = uVar18;

      *(undefined4 *)(lVar17 + 4 + lVar1) =

           *(undefined4 *)(&DAT_1403e4190 + (longlong)(int)lVar10 * 4);

      lVar16 = uStack_300;

      *(undefined4 *)(lVar17 + 8 + lVar1) =

           *(undefined4 *)(&DAT_1403e4190 + (longlong)(int)((ulonglong)lVar10 >> 0x20) * 4);

      *(undefined4 *)(lVar17 + 0xc + lVar1) =

           *(undefined4 *)(&DAT_1403e41c8 + (longlong)(int)lVar16 * 4);

      lVar10 = local_2f8;

      *(undefined4 *)(lVar17 + 0x10 + lVar1) =

           *(undefined4 *)(&DAT_1403e4190 + (longlong)(int)((ulonglong)lVar16 >> 0x20) * 4);

      *(undefined4 *)(lVar17 + 0x14 + lVar1) =

           *(undefined4 *)(&DAT_1403e4190 + (longlong)(int)lVar10 * 4);

      *(undefined4 *)(lVar17 + 0x18 + lVar1) =

           *(undefined4 *)(&DAT_1403e41c8 + (longlong)(int)((ulonglong)lVar10 >> 0x20) * 4);

      local_13c = *(uint *)(param_2 + 0x12);

    } while (uVar19 < local_13c);

  }

  local_130 = _DAT_14030a340;

  uStack_128 = _UNK_14030a348;

  local_158[0] = 0x1a;

  local_150 = 0;

  local_148 = 0;

  local_140 = 0;

  uVar3 = *(undefined8 *)(puVar13 + 0x10);

  uVar4 = *(undefined8 *)(puVar13 + 0xe);

  local_138 = lVar1;

  *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b060c;

  lVar16 = FUN_1401ba700(param_1,uVar4,uVar3);

  *(longlong *)(puVar13 + 0xc) = lVar16;

  if (lVar16 == 0) {

    *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b061d;

    FUN_1401841e0(puVar13);

    if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

      *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b063e;

      FUN_14012e0b0(9,&DAT_14039bf30,"Failed to initialize pipeline resource layout!");

    }

    *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b0651;

    FUN_14012e850(&DAT_14039bf30,"Failed to initialize pipeline resource layout!");

    puVar13 = (undefined4 *)0x0;

  }

  else {

    local_b8[0] = 0x1c;

    local_a0 = local_118;

    local_b0 = 0;

    local_98 = local_1b8;

    local_a8 = 0;

    local_90 = local_1f8;

    local_a4 = 2;

    local_80 = local_188;

    local_88 = 0;

    local_78 = local_268;

    local_70 = local_228;

    local_68 = local_2d8;

    local_60 = local_158;

    local_58 = local_1d8;

    puVar5 = *(undefined8 **)(puVar13 + 0xc);

    *(undefined4 **)((longlong)alStack_318 + lVar9 + lVar8 + lVar7 + 8) = puVar13 + 8;

    *(undefined8 *)((longlong)alStack_318 + lVar9 + lVar8 + lVar7) = 0;

    local_50 = *puVar5;

    pcVar6 = *(code **)(param_1 + 0xb28);

    uVar3 = *(undefined8 *)(param_1 + 0x570);

    local_40 = 0;

    local_38 = 0;

    local_30 = 0;

    local_48 = uVar15;

    *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b0753;

    iVar12 = (*pcVar6)(uVar3,0,1,local_b8);

    pcVar6 = *(code **)(param_1 + 0xbd0);

    uVar3 = *(undefined8 *)(param_1 + 0x570);

    *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b076c;

    (*pcVar6)(uVar3,uVar15,0);

    if (iVar12 == 0) {

      *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b07d2;

      FUN_140139010(puVar13 + 0x12,0);

      if ((*(char *)(param_1 + 0x57c) != '\0') && (*(char *)(param_1 + 0x58e) != '\0')) {

        lVar16 = param_2[0x14];

        *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b07f6;

        cVar11 = FUN_140174fc0((int)lVar16,"SDL.gpu.graphicspipeline.create.name");

        if (cVar11 != '\0') {

          lVar16 = param_2[0x14];

          local_308 = CONCAT44(local_308._4_4_,0x3b9cbe00);

          uStack_300 = 0;

          *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b081a;

          local_2e8 = FUN_140174e70((int)lVar16,"SDL.gpu.graphicspipeline.create.name",0);

          uVar15 = *(undefined8 *)(param_1 + 0x570);

          uStack_2f0 = *(longlong *)(puVar13 + 8);

          pcVar6 = *(code **)(param_1 + 0x9d0);

          local_2f8 = CONCAT44(local_2f8._4_4_,0x13);

          *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b0840;

          (*pcVar6)(uVar15,&local_308);

        }

      }

      lVar16 = *(longlong *)(puVar13 + 0xc);

      *puVar13 = *(undefined4 *)(lVar16 + 0x28);

      puVar13[2] = *(undefined4 *)(lVar16 + 0x30);

      puVar13[1] = *(undefined4 *)(lVar16 + 0x2c);

      puVar13[3] = *(undefined4 *)(lVar16 + 0x34);

      puVar13[4] = *(undefined4 *)(lVar16 + 0x38);

      puVar13[6] = *(undefined4 *)(lVar16 + 0x40);

      puVar13[5] = *(undefined4 *)(lVar16 + 0x3c);

      puVar13[7] = *(undefined4 *)(lVar16 + 0x44);

    }

    else {

      *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b0778;

      FUN_1401841e0(puVar13);

      if (*(char *)(param_1 + 0x57c) != '\0') {

        *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b0788;

        uVar15 = FUN_1401c0ba0(iVar12);

                    /* WARNING: Subroutine does not return */

        *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b07a3;

        FUN_14012e0b0(9,"%s %s","vkCreateGraphicsPipelines",uVar15);

      }

      *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b07aa;

      uVar15 = FUN_1401c0ba0(iVar12);

      *(undefined8 *)((longlong)auStack_340 + lVar9 + lVar8 + lVar7) = 0x1401b07c0;

      FUN_14012e850("%s %s","vkCreateGraphicsPipelines",uVar15);

      puVar13 = (undefined4 *)0x0;

    }

  }

  return puVar13;

}




