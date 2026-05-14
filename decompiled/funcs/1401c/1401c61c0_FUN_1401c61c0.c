// Address: 0x1401c61c0
// Ghidra name: FUN_1401c61c0
// ============ 0x1401c61c0 FUN_1401c61c0 (size=1752) ============


void FUN_1401c61c0(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  uint *puVar3;

  longlong *plVar4;

  ulonglong uVar5;

  int *piVar6;

  uint *puVar7;

  longlong *plVar8;

  undefined8 local_res8;

  undefined1 local_1a8 [128];

  longlong local_128;

  int local_120 [62];

  

  puVar3 = *(uint **)(param_1 + 0x1d0);

  if (*(longlong *)(param_1 + 0x1e0) == 0) {

    FUN_1401cb360();

  }

  if (*(char *)(param_1 + 0x210) != '\0') {

    uVar1 = *(uint *)(param_1 + 0x2e8);

    if (uVar1 != 0) {

      plVar8 = (longlong *)(param_1 + 0x228);

      uVar5 = (ulonglong)uVar1;

      piVar6 = local_120;

      puVar7 = puVar3 + 0xd;

      do {

        plVar4 = (longlong *)*plVar8;

        uVar2 = *(uint *)((param_1 - (longlong)puVar3) + 0x274 + (longlong)puVar7);

        plVar8 = plVar8 + 1;

        *(ulonglong *)(piVar6 + -2) = (ulonglong)uVar2 + plVar4[0xf];

        *piVar6 = *(int *)(*plVar4 + 4) - uVar2;

        piVar6[1] = *puVar7;

        uVar5 = uVar5 - 1;

        piVar6 = piVar6 + 4;

        puVar7 = puVar7 + 1;

      } while (uVar5 != 0);

    }

    (**(code **)(**(longlong **)(param_1 + 0x120) + 0x160))

              (*(longlong **)(param_1 + 0x120),0,(ulonglong)uVar1,&local_128);

    *(undefined1 *)(param_1 + 0x210) = 0;

  }

  if (*(char *)(param_1 + 0x211) != '\0') {

    uVar1 = *puVar3;

    if (uVar1 != 0) {

      FUN_1402f8e20(local_1a8,param_1 + 0x370,(ulonglong)uVar1 << 3);

      FUN_1401cbc70(param_1,1,local_1a8,uVar1,&local_res8);

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x100))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 8),

                 local_res8);

      uVar1 = *puVar3;

      if (uVar1 != 0) {

        FUN_1402f8e20(local_1a8,param_1 + 0x2f0,(ulonglong)uVar1 << 3);

      }

      FUN_1401cbc70(param_1,0,local_1a8,uVar1,&local_res8);

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x100))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0xc),

                 local_res8);

    }

    *(undefined1 *)(param_1 + 0x211) = 0;

  }

  if (*(char *)(param_1 + 0x212) != '\0') {

    uVar1 = puVar3[1];

    if (uVar1 != 0) {

      FUN_1402f8e20(local_1a8,param_1 + 0x3f0,(ulonglong)uVar1 << 3);

      FUN_1401cbc70(param_1,0,local_1a8,uVar1,&local_res8);

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x100))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x10),

                 local_res8);

    }

    *(undefined1 *)(param_1 + 0x212) = 0;

  }

  if (*(char *)(param_1 + 0x213) != '\0') {

    uVar1 = puVar3[2];

    if (uVar1 != 0) {

      FUN_1402f8e20(local_1a8,param_1 + 0x430,(ulonglong)uVar1 << 3);

      FUN_1401cbc70(param_1,0,local_1a8,uVar1,&local_res8);

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x100))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x14),

                 local_res8);

    }

    *(undefined1 *)(param_1 + 0x213) = 0;

  }

  if (*(char *)(param_1 + 0x214) != '\0') {

    if (puVar3[3] != 0) {

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x130))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x18),

                 (ulonglong)*(uint *)((longlong)*(longlong **)(param_1 + 0x470) + 0xc) +

                 *(longlong *)(**(longlong **)(param_1 + 0x470) + 0x78));

    }

    *(undefined1 *)(param_1 + 0x214) = 0;

  }

  if (*(char *)(param_1 + 0x215) != '\0') {

    if (1 < puVar3[3]) {

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x130))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x1c),

                 (ulonglong)*(uint *)((longlong)*(longlong **)(param_1 + 0x478) + 0xc) +

                 *(longlong *)(**(longlong **)(param_1 + 0x478) + 0x78));

    }

    *(undefined1 *)(param_1 + 0x215) = 0;

  }

  if (*(char *)(param_1 + 0x216) != '\0') {

    if (2 < puVar3[3]) {

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x130))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x20),

                 (ulonglong)*(uint *)((longlong)*(longlong **)(param_1 + 0x480) + 0xc) +

                 *(longlong *)(**(longlong **)(param_1 + 0x480) + 0x78));

    }

    *(undefined1 *)(param_1 + 0x216) = 0;

  }

  if (*(char *)(param_1 + 0x217) != '\0') {

    if (3 < puVar3[3]) {

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x130))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x24),

                 (ulonglong)*(uint *)((longlong)*(longlong **)(param_1 + 0x488) + 0xc) +

                 *(longlong *)(**(longlong **)(param_1 + 0x488) + 0x78));

    }

    *(undefined1 *)(param_1 + 0x217) = 0;

  }

  if (*(char *)(param_1 + 0x218) != '\0') {

    uVar1 = puVar3[4];

    if (uVar1 != 0) {

      FUN_1402f8e20(local_1a8,param_1 + 0x510,(ulonglong)uVar1 << 3);

      FUN_1401cbc70(param_1,1,local_1a8,uVar1,&local_res8);

      plVar8 = *(longlong **)(param_1 + 0x120);

      (**(code **)(*plVar8 + 0x100))

                (plVar8,*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x28),local_res8);

      uVar1 = puVar3[4];

      if (uVar1 != 0) {

        FUN_1402f8e20(local_1a8,param_1 + 0x490,(ulonglong)uVar1 << 3);

      }

      FUN_1401cbc70(param_1,0,local_1a8,uVar1,&local_res8);

      plVar8 = *(longlong **)(param_1 + 0x120);

      (**(code **)(*plVar8 + 0x100))

                (plVar8,*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x2c),local_res8);

    }

    *(undefined1 *)(param_1 + 0x218) = 0;

  }

  if (*(char *)(param_1 + 0x219) != '\0') {

    uVar1 = puVar3[5];

    if (uVar1 != 0) {

      FUN_1402f8e20(local_1a8,param_1 + 0x590,(ulonglong)uVar1 << 3);

      FUN_1401cbc70(param_1,0,local_1a8,uVar1,&local_res8);

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x100))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x30),

                 local_res8);

    }

    *(undefined1 *)(param_1 + 0x219) = 0;

  }

  if (*(char *)(param_1 + 0x21a) != '\0') {

    uVar1 = puVar3[6];

    if (uVar1 != 0) {

      FUN_1402f8e20(local_1a8,param_1 + 0x5d0,(ulonglong)uVar1 << 3);

      FUN_1401cbc70(param_1,0,local_1a8,uVar1,&local_res8);

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x100))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x34),

                 local_res8);

    }

    *(undefined1 *)(param_1 + 0x21a) = 0;

  }

  if (*(char *)(param_1 + 0x21b) != '\0') {

    if (puVar3[7] != 0) {

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x130))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x38),

                 (ulonglong)*(uint *)((longlong)*(longlong **)(param_1 + 0x610) + 0xc) +

                 *(longlong *)(**(longlong **)(param_1 + 0x610) + 0x78));

    }

    *(undefined1 *)(param_1 + 0x21b) = 0;

  }

  if (*(char *)(param_1 + 0x21c) != '\0') {

    if (1 < puVar3[7]) {

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x130))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x3c),

                 (ulonglong)*(uint *)((longlong)*(longlong **)(param_1 + 0x618) + 0xc) +

                 *(longlong *)(**(longlong **)(param_1 + 0x618) + 0x78));

    }

    *(undefined1 *)(param_1 + 0x21c) = 0;

  }

  if (*(char *)(param_1 + 0x21d) != '\0') {

    if (2 < puVar3[7]) {

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x130))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x40),

                 (ulonglong)*(uint *)((longlong)*(longlong **)(param_1 + 0x620) + 0xc) +

                 *(longlong *)(**(longlong **)(param_1 + 0x620) + 0x78));

    }

    *(undefined1 *)(param_1 + 0x21d) = 0;

  }

  if (*(char *)(param_1 + 0x21e) != '\0') {

    if (3 < puVar3[7]) {

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x130))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar3 + 10) + 0x44),

                 (ulonglong)*(uint *)((longlong)*(longlong **)(param_1 + 0x628) + 0xc) +

                 *(longlong *)(**(longlong **)(param_1 + 0x628) + 0x78));

    }

    *(undefined1 *)(param_1 + 0x21e) = 0;

  }

  return;

}




