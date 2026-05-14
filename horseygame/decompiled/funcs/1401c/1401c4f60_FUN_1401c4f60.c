// Address: 0x1401c4f60
// Ghidra name: FUN_1401c4f60
// ============ 0x1401c4f60 FUN_1401c4f60 (size=797) ============


void FUN_1401c4f60(longlong param_1)



{

  longlong *plVar1;

  undefined8 uVar2;

  longlong lVar3;

  longlong *plVar4;

  longlong lVar5;

  undefined8 in_stack_ffffffffffffffd8;

  undefined4 uVar6;

  

  plVar4 = (longlong *)(param_1 + 0x188);

  lVar3 = 8;

  do {

    uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);

    lVar5 = plVar4[-8];

    if (lVar5 != 0) {

      uVar2 = 4;

      if (*plVar4 != 0) {

        FUN_1401cb440(param_1,4,0x2000,lVar5);

        plVar1 = *(longlong **)plVar4[-8];

        in_stack_ffffffffffffffd8 = CONCAT44(uVar6,*(undefined4 *)((longlong)plVar4[-8] + 0x14));

        (**(code **)(**(longlong **)(param_1 + 0x120) + 0x98))

                  (*(longlong **)(param_1 + 0x120),*(undefined8 *)(*(longlong *)*plVar4 + 0x20),

                   *(undefined4 *)(*plVar4 + 0x14),plVar1[4],in_stack_ffffffffffffffd8,

                   *(undefined4 *)(&DAT_1403e43f0 + (longlong)*(int *)(*plVar1 + 4) * 4));

        FUN_1401cb4c0(param_1,0x2000,plVar4[-8]);

        lVar5 = *plVar4;

        uVar2 = 0x1000;

      }

      FUN_1401cb4c0(param_1,uVar2,lVar5);

    }

    plVar4 = plVar4 + 1;

    lVar3 = lVar3 + -1;

  } while (lVar3 != 0);

  if (*(longlong *)(param_1 + 0x1c8) != 0) {

    FUN_1401cb4c0(param_1,0x10);

    *(undefined8 *)(param_1 + 0x1c8) = 0;

  }

  *(undefined8 *)(param_1 + 0x1d0) = 0;

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0x170))(*(longlong **)(param_1 + 0x120),0,0,0,0);

  *(undefined8 *)(param_1 + 0x148) = 0;

  *(undefined8 *)(param_1 + 0x150) = 0;

  *(undefined8 *)(param_1 + 0x158) = 0;

  *(undefined8 *)(param_1 + 0x160) = 0;

  *(undefined8 *)(param_1 + 0x168) = 0;

  *(undefined8 *)(param_1 + 0x170) = 0;

  *(undefined8 *)(param_1 + 0x178) = 0;

  *(undefined8 *)(param_1 + 0x180) = 0;

  *(undefined8 *)(param_1 + 0x188) = 0;

  *(undefined8 *)(param_1 + 400) = 0;

  *(undefined8 *)(param_1 + 0x198) = 0;

  *(undefined8 *)(param_1 + 0x1a0) = 0;

  *(undefined8 *)(param_1 + 0x1a8) = 0;

  *(undefined8 *)(param_1 + 0x1b0) = 0;

  *(undefined8 *)(param_1 + 0x1b8) = 0;

  *(undefined8 *)(param_1 + 0x1c0) = 0;

  *(undefined8 *)(param_1 + 0x1c8) = 0;

  *(undefined8 *)(param_1 + 0x228) = 0;

  *(undefined8 *)(param_1 + 0x230) = 0;

  *(undefined8 *)(param_1 + 0x238) = 0;

  *(undefined8 *)(param_1 + 0x240) = 0;

  *(undefined8 *)(param_1 + 0x248) = 0;

  *(undefined8 *)(param_1 + 0x250) = 0;

  *(undefined8 *)(param_1 + 600) = 0;

  *(undefined8 *)(param_1 + 0x260) = 0;

  *(undefined8 *)(param_1 + 0x268) = 0;

  *(undefined8 *)(param_1 + 0x270) = 0;

  *(undefined8 *)(param_1 + 0x278) = 0;

  *(undefined8 *)(param_1 + 0x280) = 0;

  *(undefined8 *)(param_1 + 0x288) = 0;

  *(undefined8 *)(param_1 + 0x290) = 0;

  *(undefined8 *)(param_1 + 0x298) = 0;

  *(undefined8 *)(param_1 + 0x2a0) = 0;

  *(undefined8 *)(param_1 + 0x2a8) = 0;

  *(undefined8 *)(param_1 + 0x2b0) = 0;

  *(undefined8 *)(param_1 + 0x2b8) = 0;

  *(undefined8 *)(param_1 + 0x2c0) = 0;

  *(undefined8 *)(param_1 + 0x2c8) = 0;

  *(undefined8 *)(param_1 + 0x2d0) = 0;

  *(undefined8 *)(param_1 + 0x2d8) = 0;

  *(undefined8 *)(param_1 + 0x2e0) = 0;

  *(undefined4 *)(param_1 + 0x2e8) = 0;

  *(undefined8 *)(param_1 + 0x2f0) = 0;

  *(undefined8 *)(param_1 + 0x2f8) = 0;

  *(undefined8 *)(param_1 + 0x300) = 0;

  *(undefined8 *)(param_1 + 0x308) = 0;

  *(undefined8 *)(param_1 + 0x310) = 0;

  *(undefined8 *)(param_1 + 0x318) = 0;

  *(undefined8 *)(param_1 + 800) = 0;

  *(undefined8 *)(param_1 + 0x328) = 0;

  *(undefined8 *)(param_1 + 0x330) = 0;

  *(undefined8 *)(param_1 + 0x338) = 0;

  *(undefined8 *)(param_1 + 0x340) = 0;

  *(undefined8 *)(param_1 + 0x348) = 0;

  *(undefined8 *)(param_1 + 0x350) = 0;

  *(undefined8 *)(param_1 + 0x358) = 0;

  *(undefined8 *)(param_1 + 0x360) = 0;

  *(undefined8 *)(param_1 + 0x368) = 0;

  *(undefined8 *)(param_1 + 0x370) = 0;

  *(undefined8 *)(param_1 + 0x378) = 0;

  *(undefined8 *)(param_1 + 0x380) = 0;

  *(undefined8 *)(param_1 + 0x388) = 0;

  *(undefined8 *)(param_1 + 0x390) = 0;

  *(undefined8 *)(param_1 + 0x398) = 0;

  *(undefined8 *)(param_1 + 0x3a0) = 0;

  *(undefined8 *)(param_1 + 0x3a8) = 0;

  *(undefined8 *)(param_1 + 0x3b0) = 0;

  *(undefined8 *)(param_1 + 0x3b8) = 0;

  *(undefined8 *)(param_1 + 0x3c0) = 0;

  *(undefined8 *)(param_1 + 0x3c8) = 0;

  *(undefined8 *)(param_1 + 0x3d0) = 0;

  *(undefined8 *)(param_1 + 0x3d8) = 0;

  *(undefined8 *)(param_1 + 0x3e0) = 0;

  *(undefined8 *)(param_1 + 1000) = 0;

  *(undefined8 *)(param_1 + 0x3f0) = 0;

  *(undefined8 *)(param_1 + 0x3f8) = 0;

  *(undefined8 *)(param_1 + 0x400) = 0;

  *(undefined8 *)(param_1 + 0x408) = 0;

  *(undefined8 *)(param_1 + 0x410) = 0;

  *(undefined8 *)(param_1 + 0x418) = 0;

  *(undefined8 *)(param_1 + 0x420) = 0;

  *(undefined8 *)(param_1 + 0x428) = 0;

  *(undefined8 *)(param_1 + 0x430) = 0;

  *(undefined8 *)(param_1 + 0x438) = 0;

  *(undefined8 *)(param_1 + 0x440) = 0;

  *(undefined8 *)(param_1 + 0x448) = 0;

  *(undefined8 *)(param_1 + 0x450) = 0;

  *(undefined8 *)(param_1 + 0x458) = 0;

  *(undefined8 *)(param_1 + 0x460) = 0;

  *(undefined8 *)(param_1 + 0x468) = 0;

  *(undefined8 *)(param_1 + 0x490) = 0;

  *(undefined8 *)(param_1 + 0x498) = 0;

  *(undefined8 *)(param_1 + 0x4a0) = 0;

  *(undefined8 *)(param_1 + 0x4a8) = 0;

  *(undefined8 *)(param_1 + 0x4b0) = 0;

  *(undefined8 *)(param_1 + 0x4b8) = 0;

  *(undefined8 *)(param_1 + 0x4c0) = 0;

  *(undefined8 *)(param_1 + 0x4c8) = 0;

  *(undefined8 *)(param_1 + 0x4d0) = 0;

  *(undefined8 *)(param_1 + 0x4d8) = 0;

  *(undefined8 *)(param_1 + 0x4e0) = 0;

  *(undefined8 *)(param_1 + 0x4e8) = 0;

  *(undefined8 *)(param_1 + 0x4f0) = 0;

  *(undefined8 *)(param_1 + 0x4f8) = 0;

  *(undefined8 *)(param_1 + 0x500) = 0;

  *(undefined8 *)(param_1 + 0x508) = 0;

  *(undefined8 *)(param_1 + 0x510) = 0;

  *(undefined8 *)(param_1 + 0x518) = 0;

  *(undefined8 *)(param_1 + 0x520) = 0;

  *(undefined8 *)(param_1 + 0x528) = 0;

  *(undefined8 *)(param_1 + 0x530) = 0;

  *(undefined8 *)(param_1 + 0x538) = 0;

  *(undefined8 *)(param_1 + 0x540) = 0;

  *(undefined8 *)(param_1 + 0x548) = 0;

  *(undefined8 *)(param_1 + 0x550) = 0;

  *(undefined8 *)(param_1 + 0x558) = 0;

  *(undefined8 *)(param_1 + 0x560) = 0;

  *(undefined8 *)(param_1 + 0x568) = 0;

  *(undefined8 *)(param_1 + 0x570) = 0;

  *(undefined8 *)(param_1 + 0x578) = 0;

  *(undefined8 *)(param_1 + 0x580) = 0;

  *(undefined8 *)(param_1 + 0x588) = 0;

  *(undefined8 *)(param_1 + 0x590) = 0;

  *(undefined8 *)(param_1 + 0x598) = 0;

  *(undefined8 *)(param_1 + 0x5a0) = 0;

  *(undefined8 *)(param_1 + 0x5a8) = 0;

  *(undefined8 *)(param_1 + 0x5b0) = 0;

  *(undefined8 *)(param_1 + 0x5b8) = 0;

  *(undefined8 *)(param_1 + 0x5c0) = 0;

  *(undefined8 *)(param_1 + 0x5c8) = 0;

  *(undefined8 *)(param_1 + 0x5d0) = 0;

  *(undefined8 *)(param_1 + 0x5d8) = 0;

  *(undefined8 *)(param_1 + 0x5e0) = 0;

  *(undefined8 *)(param_1 + 0x5e8) = 0;

  *(undefined8 *)(param_1 + 0x5f0) = 0;

  *(undefined8 *)(param_1 + 0x5f8) = 0;

  *(undefined8 *)(param_1 + 0x600) = 0;

  *(undefined8 *)(param_1 + 0x608) = 0;

  return;

}




