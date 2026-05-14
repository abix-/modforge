// Address: 0x1401acec0
// Ghidra name: FUN_1401acec0
// ============ 0x1401acec0 FUN_1401acec0 (size=3099) ============


undefined8 * FUN_1401acec0(undefined1 param_1,undefined1 param_2,undefined4 param_3)



{

  longlong lVar1;

  longlong lVar2;

  char cVar3;

  char cVar4;

  undefined4 uVar5;

  longlong lVar6;

  undefined8 *puVar7;

  undefined8 uVar8;

  char *pcVar9;

  uint uVar10;

  ulonglong uVar12;

  ulonglong uVar13;

  undefined1 *puVar14;

  undefined8 in_stack_fffffffffffffce8;

  undefined4 uVar15;

  undefined8 in_stack_fffffffffffffcf0;

  undefined4 uVar16;

  undefined1 local_2f8 [64];

  undefined1 local_2b8 [64];

  undefined1 local_278 [608];

  ulonglong uVar11;

  

  uVar16 = (undefined4)((ulonglong)in_stack_fffffffffffffcf0 >> 0x20);

  uVar15 = (undefined4)((ulonglong)in_stack_fffffffffffffce8 >> 0x20);

  cVar3 = FUN_1401749e0(param_3,"SDL.gpu.device.create.verbose",1);

  cVar4 = FUN_140174130(0);

  if (cVar4 == '\0') {

    return (undefined8 *)0x0;

  }

  lVar6 = FUN_1401841a0(1,0xcb0);

  if (lVar6 == 0) goto LAB_1401ad1e3;

  *(undefined1 *)(lVar6 + 0x57c) = param_1;

  *(undefined1 *)(lVar6 + 0x57d) = param_2;

  *(undefined4 *)(lVar6 + 0x584) = 2;

  cVar4 = FUN_1401bbf50(lVar6,local_278,param_3);

  if (cVar4 == '\0') {

    if (*(char *)(lVar6 + 0x57c) == '\0') {

      FUN_14012e850(&DAT_14039bf30,"Failed to initialize Vulkan!");

      FUN_1401841e0(lVar6);

      FUN_1401741d0();

      return (undefined8 *)0x0;

    }

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,&DAT_14039bf30,"Failed to initialize Vulkan!");

  }

  uVar5 = FUN_1401746e0();

  *(undefined4 *)(lVar6 + 0x580) = uVar5;

  if (cVar3 == '\0') {

    FUN_140175500(uVar5,"SDL.gpu.device.name",lVar6 + 0x34);

  }

  else {

    FUN_14012e0e0(9,"SDL_GPU Driver: Vulkan");

    FUN_140175500(*(undefined4 *)(lVar6 + 0x580),"SDL.gpu.device.name",lVar6 + 0x34);

    FUN_14012e0e0(9,"Vulkan Device: %s",lVar6 + 0x34);

  }

  uVar10 = *(uint *)(lVar6 + 0x24);

  if (*(int *)(lVar6 + 0x28) == 0x10de) {

    uVar12 = CONCAT44(uVar16,uVar10 >> 6) & 0xffffffff000000ff;

    uVar11 = CONCAT44(uVar15,uVar10 >> 0xe) & 0xffffffff000000ff;

    FUN_14012ef10(local_2f8,0x40,"%d.%d.%d.%d",uVar10 >> 0x16,uVar11,uVar12,uVar10 & 0x3f);

    uVar15 = (undefined4)(uVar11 >> 0x20);

    uVar16 = (undefined4)(uVar12 >> 0x20);

  }

  else if (*(int *)(lVar6 + 0x28) == 0x8086) {

    uVar11 = CONCAT44(uVar15,uVar10) & 0xffffffff00003fff;

    FUN_14012ef10(local_2f8,0x40,"%d.%d",uVar10 >> 0xe,uVar11);

    uVar15 = (undefined4)(uVar11 >> 0x20);

  }

  else {

    uVar12 = CONCAT44(uVar16,uVar10) & 0xffffffff00000fff;

    uVar11 = CONCAT44(uVar15,uVar10 >> 0xc) & 0xffffffff000003ff;

    FUN_14012ef10(local_2f8,0x40,"%d.%d.%d",uVar10 >> 0x16,uVar11,uVar12);

    uVar15 = (undefined4)(uVar11 >> 0x20);

    uVar16 = (undefined4)(uVar12 >> 0x20);

  }

  FUN_140175500(*(undefined4 *)(lVar6 + 0x580),"SDL.gpu.device.driver_version",local_2f8);

  if (*(char *)(lVar6 + 0x58a) == '\0') {

    if (cVar3 != '\0') {

      puVar14 = local_2f8;

      pcVar9 = "Vulkan Driver: %s";

      goto LAB_1401ad18a;

    }

  }

  else {

    FUN_140175500(*(undefined4 *)(lVar6 + 0x580),"SDL.gpu.device.driver_name",lVar6 + 0x36c);

    FUN_140175500(*(undefined4 *)(lVar6 + 0x580),"SDL.gpu.device.driver_info",lVar6 + 0x46c);

    if (cVar3 != '\0') {

      FUN_14012e0e0(9,"Vulkan Driver: %s %s",lVar6 + 0x36c,lVar6 + 0x46c);

      FUN_14012ef10(local_2b8,0x40,"%u.%u.%u.%u",*(undefined1 *)(lVar6 + 0x56c),

                    CONCAT44(uVar15,(uint)*(byte *)(lVar6 + 0x56d)),

                    CONCAT44(uVar16,(uint)*(byte *)(lVar6 + 0x56e)),*(undefined1 *)(lVar6 + 0x56f));

      puVar14 = local_2b8;

      pcVar9 = "Vulkan Conformance: %s";

LAB_1401ad18a:

      FUN_14012e0e0(9,pcVar9,puVar14);

    }

  }

  cVar3 = FUN_1401b6080(lVar6,local_278);

  if (cVar3 != '\0') {

    puVar7 = (undefined8 *)FUN_1401841a0(1,0x2b0);

    *puVar7 = FUN_1401b0e10;

    puVar7[1] = &LAB_1401b2260;

    puVar7[2] = FUN_1401afb80;

    puVar7[3] = FUN_1401afef0;

    puVar7[4] = FUN_1401b08a0;

    puVar7[5] = FUN_1401b0aa0;

    puVar7[6] = FUN_1401b0ca0;

    puVar7[7] = FUN_1401afb50;

    puVar7[8] = FUN_1401b0de0;

    puVar7[9] = FUN_1401bfac0;

    puVar7[10] = FUN_1401bfcc0;

    puVar7[0xb] = FUN_1401bf370;

    puVar7[0xc] = FUN_1401bf470;

    puVar7[0xd] = &LAB_1401bf420;

    puVar7[0xe] = FUN_1401bf820;

    puVar7[0xf] = FUN_1401bf700;

    puVar7[0x10] = &LAB_1401bf590;

    puVar7[0x11] = &LAB_1401bf590;

    puVar7[0x12] = FUN_1401bf790;

    puVar7[0x13] = FUN_1401bf5a0;

    puVar7[0x14] = FUN_1401bf670;

    puVar7[0x15] = FUN_1401ae360;

    puVar7[0x16] = FUN_1401aee20;

    puVar7[0x17] = &LAB_1401bfd50;

    puVar7[0x18] = &LAB_1401bfb50;

    puVar7[0x19] = FUN_1401bfaa0;

    puVar7[0x1a] = &LAB_1401bfb60;

    puVar7[0x1b] = FUN_1401aefa0;

    puVar7[0x1c] = FUN_1401aef20;

    puVar7[0x1d] = FUN_1401af080;

    puVar7[0x1e] = FUN_1401af200;

    puVar7[0x1f] = FUN_1401af160;

    puVar7[0x20] = FUN_1401aebf0;

    puVar7[0x21] = FUN_1401aed70;

    puVar7[0x22] = FUN_1401aecd0;

    puVar7[0x23] = FUN_1401bf4f0;

    puVar7[0x24] = FUN_1401bf4d0;

    puVar7[0x25] = FUN_1401b1520;

    puVar7[0x26] = FUN_1401b1660;

    puVar7[0x27] = FUN_1401b16d0;

    puVar7[0x28] = FUN_1401b1590;

    puVar7[0x29] = FUN_1401b1cc0;

    puVar7[0x2a] = FUN_1401ae250;

    puVar7[0x2b] = FUN_1401ae8a0;

    puVar7[0x2c] = FUN_1401ae950;

    puVar7[0x2d] = FUN_1401aeb10;

    puVar7[0x2e] = FUN_1401aea30;

    puVar7[0x2f] = FUN_1401bf450;

    puVar7[0x30] = FUN_1401b11f0;

    puVar7[0x31] = FUN_1401b1260;

    puVar7[0x32] = FUN_1401b17a0;

    puVar7[0x33] = FUN_1401bf3d0;

    puVar7[0x34] = _guard_check_icall;

    puVar7[0x35] = _guard_check_icall;

    puVar7[0x36] = FUN_1401c0710;

    puVar7[0x37] = FUN_1401c0600;

    puVar7[0x3b] = FUN_1401b13c0;

    puVar7[0x3c] = FUN_1401b12d0;

    puVar7[0x38] = FUN_1401af970;

    puVar7[0x39] = FUN_1401af830;

    puVar7[0x3a] = FUN_1401b1fd0;

    puVar7[0x3d] = _guard_check_icall;

    puVar7[0x3e] = FUN_1401af2b0;

    puVar7[0x3f] = FUN_1401c0410;

    puVar7[0x40] = FUN_1401c02c0;

    puVar7[0x41] = FUN_1401af5f0;

    puVar7[0x42] = FUN_1401bf8b0;

    puVar7[0x43] = FUN_1401bfb70;

    puVar7[0x44] = FUN_1401bfa20;

    puVar7[0x45] = FUN_1401b2270;

    puVar7[0x46] = FUN_1401add10;

    puVar7[0x47] = FUN_1401ae220;

    puVar7[0x48] = FUN_1401c0b10;

    puVar7[0x49] = FUN_1401c0960;

    puVar7[0x4a] = FUN_1401bfd60;

    puVar7[0x4b] = FUN_1401c0290;

    puVar7[0x4c] = FUN_1401af520;

    puVar7[0x4d] = FUN_1401c0880;

    puVar7[0x4e] = FUN_1401c0990;

    uVar13 = 0;

    puVar7[0x53] = lVar6;

    puVar7[0x4f] = FUN_1401bf510;

    *(undefined4 *)(puVar7 + 0x55) = 2;

    puVar7[0x50] = FUN_1401bf630;

    puVar7[0x51] = FUN_1401c0540;

    puVar7[0x52] = &LAB_1401c03d0;

    *(undefined4 *)(lVar6 + 0x7bc) = 1;

    *(undefined4 *)(lVar6 + 0x7b8) = 0;

    uVar8 = FUN_1401841f0(8);

    *(undefined8 *)(lVar6 + 0x7b0) = uVar8;

    uVar8 = FUN_140179a30();

    *(undefined8 *)(lVar6 + 0x8c0) = uVar8;

    uVar8 = FUN_140179a30();

    *(undefined8 *)(lVar6 + 0x8c8) = uVar8;

    uVar8 = FUN_140179a30();

    *(undefined8 *)(lVar6 + 0x8d0) = uVar8;

    uVar8 = FUN_140179a30();

    *(undefined8 *)(lVar6 + 0x8d8) = uVar8;

    uVar8 = FUN_140179a30();

    *(undefined8 *)(lVar6 + 0x8e0) = uVar8;

    uVar8 = FUN_140179a30();

    *(undefined8 *)(lVar6 + 0x8e8) = uVar8;

    uVar8 = FUN_140179a30();

    *(undefined8 *)(lVar6 + 0x8f0) = uVar8;

    uVar8 = FUN_140179a30();

    *(undefined8 *)(lVar6 + 0x8f8) = uVar8;

    uVar8 = FUN_140179a30();

    *(undefined8 *)(lVar6 + 0x900) = uVar8;

    uVar8 = FUN_140179a30();

    *(undefined8 *)(lVar6 + 0x908) = uVar8;

    uVar8 = FUN_140179a30();

    *(undefined8 *)(lVar6 + 0x910) = uVar8;

    *(undefined4 *)(lVar6 + 0x7dc) = 0x10;

    *(undefined4 *)(lVar6 + 0x7d8) = 0;

    uVar8 = FUN_1401841f0(0x80);

    *(undefined8 *)(lVar6 + 2000) = uVar8;

    uVar8 = FUN_1401841f0(0x500);

    *(undefined8 *)(lVar6 + 0x598) = uVar8;

    uVar11 = uVar13;

    uVar12 = uVar13;

    do {

      *(int *)(uVar12 + *(longlong *)(lVar6 + 0x598)) = (int)uVar11;

      *(undefined8 *)(uVar12 + 8 + *(longlong *)(lVar6 + 0x598)) = 0;

      *(undefined4 *)(uVar12 + 0x10 + *(longlong *)(lVar6 + 0x598)) = 0;

      lVar1 = *(longlong *)(lVar6 + 0x598);

      uVar8 = FUN_1401841f0(0x20);

      *(undefined8 *)(lVar1 + 0x18 + uVar12) = uVar8;

      uVar10 = (int)uVar11 + 1;

      uVar11 = (ulonglong)uVar10;

      *(undefined4 *)(uVar12 + 0x20 + *(longlong *)(lVar6 + 0x598)) = 0;

      *(undefined4 *)(uVar12 + 0x24 + *(longlong *)(lVar6 + 0x598)) = 4;

      uVar12 = uVar12 + 0x28;

    } while (uVar10 < 0x20);

    *(undefined4 *)(lVar6 + 0x830) = 0x20;

    *(undefined4 *)(lVar6 + 0x834) = 0x20;

    uVar8 = FUN_1401841f0(0x100);

    *(undefined8 *)(lVar6 + 0x828) = uVar8;

    if (*(int *)(lVar6 + 0x830) != 0) {

      do {

        lVar2 = *(longlong *)(lVar6 + 0x828);

        lVar1 = uVar13 * 8;

        uVar8 = FUN_1401b85d0(lVar6,0x8000);

        uVar10 = (int)uVar13 + 1;

        uVar13 = (ulonglong)uVar10;

        *(undefined8 *)(lVar2 + lVar1) = uVar8;

      } while (uVar10 < *(uint *)(lVar6 + 0x830));

    }

    *(undefined4 *)(lVar6 + 0x844) = 8;

    *(undefined4 *)(lVar6 + 0x840) = 0;

    uVar8 = FUN_1401841a0(8);

    *(undefined8 *)(lVar6 + 0x838) = uVar8;

    FUN_140139010(lVar6 + 0x848,0);

    *(undefined4 *)(lVar6 + 0x84c) = *(undefined4 *)(lVar6 + 0x288);

    uVar8 = FUN_1401aaee0(0,0,&LAB_1401b5990,&LAB_1401b59a0,FUN_1401b5970,lVar6);

    *(undefined8 *)(lVar6 + 0x7f8) = uVar8;

    uVar8 = FUN_1401aaee0(0,0,&LAB_1401bcd60,FUN_1401bce00,FUN_1401bcd20,lVar6);

    *(undefined8 *)(lVar6 + 0x800) = uVar8;

    uVar8 = FUN_1401aaee0(0,0,&LAB_1401baf60,FUN_1401bafe0,FUN_1401baf40,lVar6);

    *(undefined8 *)(lVar6 + 0x808) = uVar8;

    uVar8 = FUN_1401aaee0(0,0,&LAB_1401bb2f0,FUN_1401bb330,FUN_1401b59b0,lVar6);

    *(undefined8 *)(lVar6 + 0x810) = uVar8;

    uVar8 = FUN_1401aaee0(0,0,&LAB_1401b59d0,FUN_1401b5a00,FUN_1401b59b0,lVar6);

    *(undefined8 *)(lVar6 + 0x818) = uVar8;

    uVar8 = FUN_1401aaee0(0,0,&LAB_1401b8ef0,FUN_1401b8f20,FUN_1401b8ed0,lVar6);

    *(undefined8 *)(lVar6 + 0x820) = uVar8;

    uVar8 = FUN_140179a30();

    *(undefined8 *)(lVar6 + 0x7e0) = uVar8;

    *(undefined4 *)(lVar6 + 0x7f4) = 4;

    *(undefined4 *)(lVar6 + 0x7f0) = 0;

    uVar8 = FUN_1401841f0(0x20);

    *(undefined8 *)(lVar6 + 0x7e8) = uVar8;

    *(undefined4 *)(lVar6 + 0x85c) = 0x10;

    *(undefined4 *)(lVar6 + 0x858) = 0;

    uVar8 = FUN_1401841f0(0x80);

    *(undefined8 *)(lVar6 + 0x850) = uVar8;

    *(undefined4 *)(lVar6 + 0x86c) = 0x10;

    *(undefined4 *)(lVar6 + 0x868) = 0;

    uVar8 = FUN_1401841f0(0x80);

    *(undefined8 *)(lVar6 + 0x860) = uVar8;

    *(undefined4 *)(lVar6 + 0x87c) = 0x10;

    *(undefined4 *)(lVar6 + 0x878) = 0;

    uVar8 = FUN_1401841f0(0x80);

    *(undefined8 *)(lVar6 + 0x870) = uVar8;

    *(undefined4 *)(lVar6 + 0x88c) = 0x10;

    *(undefined4 *)(lVar6 + 0x888) = 0;

    uVar8 = FUN_1401841f0(0x80);

    *(undefined8 *)(lVar6 + 0x880) = uVar8;

    *(undefined4 *)(lVar6 + 0x89c) = 0x10;

    *(undefined4 *)(lVar6 + 0x898) = 0;

    uVar8 = FUN_1401841f0(0x80);

    *(undefined8 *)(lVar6 + 0x890) = uVar8;

    *(undefined4 *)(lVar6 + 0x8ac) = 0x10;

    *(undefined4 *)(lVar6 + 0x8a8) = 0;

    uVar8 = FUN_1401841f0(0x80);

    *(undefined8 *)(lVar6 + 0x8a0) = uVar8;

    *(undefined4 *)(lVar6 + 0x8bc) = 0x10;

    *(undefined4 *)(lVar6 + 0x8b8) = 0;

    uVar8 = FUN_1401841f0(0x80);

    *(undefined8 *)(lVar6 + 0x8b0) = uVar8;

    *(undefined1 *)(lVar6 + 0x920) = 0;

    *(undefined4 *)(lVar6 + 0x930) = 0;

    *(undefined4 *)(lVar6 + 0x934) = 4;

    uVar8 = FUN_1401841f0(0x20);

    *(undefined8 *)(lVar6 + 0x928) = uVar8;

    return puVar7;

  }

  if (*(char *)(lVar6 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,&DAT_14039bf30,"Failed to create logical device!");

  }

  FUN_14012e850(&DAT_14039bf30,"Failed to create logical device!");

  FUN_1401841e0(lVar6);

LAB_1401ad1e3:

  FUN_1401741d0();

  return (undefined8 *)0x0;

}




