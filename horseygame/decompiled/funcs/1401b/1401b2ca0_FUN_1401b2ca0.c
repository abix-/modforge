// Address: 0x1401b2ca0
// Ghidra name: FUN_1401b2ca0
// ============ 0x1401b2ca0 FUN_1401b2ca0 (size=767) ============


ulonglong FUN_1401b2ca0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  int iVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  longlong lVar5;

  undefined8 local_res8;

  undefined4 local_28 [2];

  undefined8 local_20;

  undefined8 local_18;

  undefined4 local_10;

  undefined4 local_c;

  

  *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 1;

  uVar3 = FUN_140184230(*(undefined8 *)(param_2 + 0x10),(ulonglong)*(uint *)(param_2 + 0x18) << 3);

  *(undefined8 *)(param_2 + 0x10) = uVar3;

  local_18 = *(undefined8 *)(param_2 + 8);

  local_28[0] = 0x28;

  local_20 = 0;

  local_c = 1;

  local_10 = 0;

  iVar2 = (**(code **)(param_1 + 0x9e8))(*(undefined8 *)(param_1 + 0x570),local_28,&local_res8);

  if (iVar2 == 0) {

    lVar5 = FUN_1401841f0(0xaa0);

    *(longlong *)(lVar5 + 0x110) = param_1;

    *(longlong *)(lVar5 + 0x120) = param_2;

    *(undefined8 *)(lVar5 + 0x118) = local_res8;

    *(undefined8 *)(lVar5 + 0xa90) = 0;

    *(undefined4 *)(lVar5 + 0x134) = 1;

    *(undefined4 *)(lVar5 + 0x130) = 0;

    uVar3 = FUN_1401841f0(0x10);

    *(undefined8 *)(lVar5 + 0x128) = uVar3;

    *(undefined4 *)(lVar5 + 0x144) = 1;

    *(undefined4 *)(lVar5 + 0x140) = 0;

    uVar3 = FUN_1401841f0(8);

    *(undefined8 *)(lVar5 + 0x138) = uVar3;

    *(undefined4 *)(lVar5 + 0x154) = 1;

    *(undefined4 *)(lVar5 + 0x150) = 0;

    uVar3 = FUN_1401841f0(8);

    *(undefined8 *)(lVar5 + 0x148) = uVar3;

    *(undefined1 *)(lVar5 + 0x394) = 0;

    *(undefined4 *)(lVar5 + 0x248) = 0x1010101;

    *(undefined4 *)(lVar5 + 0x24c) = 0x1010101;

    *(undefined2 *)(lVar5 + 0x250) = 0x101;

    *(undefined8 *)(lVar5 + 600) = 0;

    *(undefined8 *)(lVar5 + 0x260) = 0;

    *(undefined8 *)(lVar5 + 0x268) = 0;

    *(undefined8 *)(lVar5 + 0x270) = 0;

    *(undefined8 *)(lVar5 + 0x278) = 0;

    *(undefined8 *)(lVar5 + 0x280) = 0;

    *(undefined8 *)(lVar5 + 0x288) = 0;

    *(undefined4 *)(lVar5 + 0xa0c) = 4;

    *(undefined4 *)(lVar5 + 0xa08) = 0;

    uVar3 = FUN_1401841f0(0x20);

    *(undefined8 *)(lVar5 + 0xa00) = uVar3;

    *(undefined4 *)(lVar5 + 0xa1c) = 4;

    *(undefined4 *)(lVar5 + 0xa18) = 0;

    uVar3 = FUN_1401841f0(0x20);

    *(undefined8 *)(lVar5 + 0xa10) = uVar3;

    *(undefined4 *)(lVar5 + 0xa2c) = 4;

    *(undefined4 *)(lVar5 + 0xa28) = 0;

    uVar3 = FUN_1401841f0(0x20);

    *(undefined8 *)(lVar5 + 0xa20) = uVar3;

    *(undefined4 *)(lVar5 + 0xa3c) = 4;

    *(undefined4 *)(lVar5 + 0xa38) = 0;

    uVar3 = FUN_1401841f0(0x20);

    *(undefined8 *)(lVar5 + 0xa30) = uVar3;

    *(undefined4 *)(lVar5 + 0xa4c) = 4;

    *(undefined4 *)(lVar5 + 0xa48) = 0;

    uVar3 = FUN_1401841f0(0x20);

    *(undefined8 *)(lVar5 + 0xa40) = uVar3;

    *(undefined4 *)(lVar5 + 0xa5c) = 4;

    *(undefined4 *)(lVar5 + 0xa58) = 0;

    uVar3 = FUN_1401841f0(0x20);

    *(undefined8 *)(lVar5 + 0xa50) = uVar3;

    *(undefined4 *)(lVar5 + 0xa6c) = 4;

    *(undefined4 *)(lVar5 + 0xa68) = 0;

    uVar3 = FUN_1401841f0(0x20);

    *(undefined8 *)(lVar5 + 0xa60) = uVar3;

    *(undefined4 *)(lVar5 + 0xa7c) = 4;

    *(undefined4 *)(lVar5 + 0xa78) = 0;

    uVar3 = FUN_1401841f0(0x20);

    *(undefined8 *)(lVar5 + 0xa70) = uVar3;

    *(undefined4 *)(lVar5 + 0xa8c) = 4;

    *(undefined4 *)(lVar5 + 0xa88) = 0;

    uVar3 = FUN_1401841f0(0x20);

    *(undefined8 *)(lVar5 + 0xa80) = uVar3;

    *(undefined1 *)(lVar5 + 0xa99) = 0;

    lVar1 = *(longlong *)(param_2 + 0x10);

    *(longlong *)(lVar1 + (ulonglong)*(uint *)(param_2 + 0x1c) * 8) = lVar5;

    uVar4 = CONCAT71((int7)((ulonglong)lVar1 >> 8),1);

    *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + 1;

  }

  else {

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar3 = FUN_1401c0ba0(iVar2);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkAllocateCommandBuffers",uVar3);

    }

    uVar3 = FUN_1401c0ba0(iVar2);

    uVar4 = FUN_14012e850("%s %s","vkAllocateCommandBuffers",uVar3);

    uVar4 = uVar4 & 0xffffffffffffff00;

  }

  return uVar4;

}




