// Address: 0x1401b3e30
// Ghidra name: FUN_1401b3e30
// ============ 0x1401b3e30 FUN_1401b3e30 (size=2203) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void FUN_1401b3e30(longlong param_1,longlong param_2)



{

  int iVar1;

  undefined8 *puVar2;

  undefined8 uVar3;

  longlong *plVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  uint uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  ulonglong uVar13;

  undefined4 uVar14;

  undefined8 local_1868;

  undefined8 local_1860;

  undefined8 local_1858;

  undefined8 local_1850;

  undefined4 local_1848 [8];

  undefined8 local_1828 [48];

  undefined4 local_16a8 [2];

  undefined8 auStack_16a0 [2];

  int aiStack_1690 [4];

  longlong alStack_1680 [571];

  undefined8 local_4a8 [2];

  undefined4 auStack_498 [282];

  undefined8 uStack_30;

  

  uStack_30 = 0x1401b3e55;

  uVar9 = 0;

  uVar13 = 0;

  uVar7 = 0;

  uVar12 = 0;

  if (*(char *)(param_2 + 0x394) == '\0') {

    if ((((*(char *)(param_2 + 0x248) == '\0') && (*(char *)(param_2 + 0x249) == '\0')) &&

        (*(char *)(param_2 + 0x24a) == '\0')) &&

       (((*(char *)(param_2 + 0x24b) == '\0' && (*(char *)(param_2 + 0x24c) == '\0')) &&

        (*(char *)(param_2 + 0x24d) == '\0')))) {

      return;

    }

  }

  else if (*(int *)(param_2 + 0x390) != 0) {

    (**(code **)(param_1 + 0xa38))

              (*(undefined8 *)(param_2 + 0x118),0,*(int *)(param_2 + 0x390),param_2 + 0x290,

               param_2 + 0x310);

    *(undefined1 *)(param_2 + 0x394) = 0;

  }

  puVar2 = *(undefined8 **)(*(longlong *)(param_2 + 0x160) + 0x30);

  if (*(char *)(param_2 + 0x248) != '\0') {

    uVar5 = FUN_1401b9ed0(param_1,param_2,puVar2[1]);

    *(undefined8 *)(param_2 + 600) = uVar5;

    uVar7 = uVar9;

    if (*(int *)(puVar2 + 5) != 0) {

      do {

        auStack_16a0[uVar7 * 8] = 0;

        aiStack_1690[uVar7 * 0x10 + 1] = 0;

        alStack_1680[uVar7 * 8 + 2] = 0;

        alStack_1680[uVar7 * 8 + 1] = 0;

        aiStack_1690[uVar7 * 0x10] = (int)uVar7;

        uVar3 = *(undefined8 *)(param_2 + 0x418 + uVar7 * 8);

        local_16a8[uVar7 * 0x10] = 0x23;

        aiStack_1690[uVar7 * 0x10 + 2] = 1;

        aiStack_1690[uVar7 * 0x10 + 3] = 1;

        local_4a8[uVar7 * 3] = uVar3;

        uVar8 = (int)uVar7 + 1;

        uVar9 = (ulonglong)uVar8;

        local_4a8[uVar7 * 3 + 1] = *(undefined8 *)(param_2 + 0x398 + uVar7 * 8);

        auStack_16a0[uVar7 * 8 + 1] = uVar5;

        auStack_498[uVar7 * 6] = 5;

        alStack_1680[uVar7 * 8] = (longlong)(local_4a8 + uVar7 * 3);

        uVar7 = uVar9;

      } while (uVar8 < *(uint *)(puVar2 + 5));

    }

    uVar10 = uVar9;

    uVar6 = 0;

    uVar11 = uVar9;

    uVar7 = uVar9;

    if (*(int *)((longlong)puVar2 + 0x2c) != 0) {

      do {

        uVar7 = (ulonglong)((int)uVar11 + 1);

        uVar9 = (ulonglong)((int)uVar10 + 1);

        auStack_16a0[uVar10 * 8] = 0;

        aiStack_1690[uVar10 * 0x10 + 1] = 0;

        local_16a8[uVar10 * 0x10] = 0x23;

        aiStack_1690[uVar10 * 0x10 + 2] = 1;

        aiStack_1690[uVar10 * 0x10 + 3] = 2;

        iVar1 = *(int *)(puVar2 + 5);

        alStack_1680[uVar10 * 8 + 2] = 0;

        aiStack_1690[uVar10 * 0x10] = iVar1 + (int)uVar6;

        alStack_1680[uVar10 * 8 + 1] = 0;

        auStack_498[uVar11 * 6] = 1;

        uVar8 = (int)uVar6 + 1;

        auStack_16a0[uVar10 * 8 + 1] = uVar5;

        alStack_1680[uVar10 * 8] = (longlong)(local_4a8 + uVar11 * 3);

        local_4a8[uVar11 * 3 + 1] = *(undefined8 *)(param_2 + 0x498 + uVar6 * 8);

        local_4a8[uVar11 * 3] = 0;

        uVar10 = uVar9;

        uVar6 = (ulonglong)uVar8;

        uVar11 = uVar7;

      } while (uVar8 < *(uint *)((longlong)puVar2 + 0x2c));

    }

    uVar10 = uVar9;

    uVar6 = uVar13;

    if (*(int *)(puVar2 + 6) != 0) {

      do {

        uVar9 = (ulonglong)((int)uVar10 + 1);

        auStack_16a0[uVar10 * 8] = 0;

        aiStack_1690[uVar10 * 0x10 + 1] = 0;

        local_16a8[uVar10 * 0x10] = 0x23;

        aiStack_1690[uVar10 * 0x10 + 2] = 1;

        aiStack_1690[uVar10 * 0x10 + 3] = 7;

        aiStack_1690[uVar10 * 0x10] =

             *(int *)(puVar2 + 5) + (int)uVar6 + *(int *)((longlong)puVar2 + 0x2c);

        alStack_1680[uVar10 * 8 + 2] = 0;

        alStack_1680[uVar10 * 8] = 0;

        uVar3 = *(undefined8 *)(param_2 + 0x4d8 + uVar6 * 8);

        uVar8 = (int)uVar6 + 1;

        uVar13 = (ulonglong)uVar8;

        auStack_16a0[uVar10 * 8 + 1] = uVar5;

        local_1828[uVar6 * 3 + 1] = 0;

        local_1828[uVar6 * 3 + 2] = 0xffffffffffffffff;

        local_1828[uVar6 * 3] = uVar3;

        alStack_1680[uVar10 * 8 + 1] = (longlong)(local_1828 + uVar6 * 3);

        uVar10 = uVar9;

        uVar6 = uVar13;

      } while (uVar8 < *(uint *)(puVar2 + 6));

    }

    *(undefined1 *)(param_2 + 0x248) = 0;

  }

  if (*(char *)(param_2 + 0x249) != '\0') {

    uVar5 = FUN_1401b9ed0(param_1,param_2,puVar2[2]);

    *(undefined8 *)(param_2 + 0x260) = uVar5;

    uVar10 = uVar9;

    uVar6 = 0;

    uVar11 = uVar13;

    if (*(int *)((longlong)puVar2 + 0x34) != 0) {

      do {

        uVar9 = (ulonglong)((int)uVar10 + 1);

        uVar13 = (ulonglong)((int)uVar11 + 1);

        auStack_16a0[uVar10 * 8] = 0;

        aiStack_1690[uVar10 * 0x10 + 1] = 0;

        alStack_1680[uVar10 * 8 + 2] = 0;

        alStack_1680[uVar10 * 8] = 0;

        aiStack_1690[uVar10 * 0x10] = (int)uVar6;

        uVar8 = (int)uVar6 + 1;

        local_16a8[uVar10 * 0x10] = 0x23;

        aiStack_1690[uVar10 * 0x10 + 2] = 1;

        aiStack_1690[uVar10 * 0x10 + 3] = 8;

        plVar4 = *(longlong **)(param_2 + 0x9a0 + uVar6 * 8);

        auStack_16a0[uVar10 * 8 + 1] = uVar5;

        uVar3 = *(undefined8 *)(*plVar4 + 0x10);

        local_1828[uVar11 * 3 + 1] = 0;

        local_1828[uVar11 * 3] = uVar3;

        local_1828[uVar11 * 3 + 2] = 0x1000;

        alStack_1680[uVar10 * 8 + 1] = (longlong)(local_1828 + uVar11 * 3);

        uVar10 = uVar9;

        uVar6 = (ulonglong)uVar8;

        uVar11 = uVar13;

      } while (uVar8 < *(uint *)((longlong)puVar2 + 0x34));

    }

    *(undefined1 *)(param_2 + 0x249) = 0;

  }

  if (*(int *)((longlong)puVar2 + 0x34) != 0) {

    do {

      local_1848[uVar12] = *(undefined4 *)(*(longlong *)(param_2 + 0x9a0 + uVar12 * 8) + 8);

      uVar8 = (int)uVar12 + 1;

      uVar12 = (ulonglong)uVar8;

    } while (uVar8 < *(uint *)((longlong)puVar2 + 0x34));

  }

  if (*(char *)(param_2 + 0x24b) != '\0') {

    uVar5 = FUN_1401b9ed0(param_1,param_2,puVar2[3]);

    *(undefined8 *)(param_2 + 0x268) = uVar5;

    uVar10 = uVar9;

    uVar6 = 0;

    uVar11 = uVar7;

    if (*(int *)(puVar2 + 7) != 0) {

      do {

        uVar7 = (ulonglong)((int)uVar11 + 1);

        uVar9 = (ulonglong)((int)uVar10 + 1);

        uVar3 = *(undefined8 *)(param_2 + 0x598 + uVar6 * 8);

        auStack_498[uVar11 * 6] = 5;

        auStack_16a0[uVar10 * 8] = 0;

        aiStack_1690[uVar10 * 0x10 + 1] = 0;

        alStack_1680[uVar10 * 8 + 2] = 0;

        alStack_1680[uVar10 * 8 + 1] = 0;

        aiStack_1690[uVar10 * 0x10] = (int)uVar6;

        local_4a8[uVar11 * 3] = uVar3;

        uVar8 = (int)uVar6 + 1;

        uVar3 = *(undefined8 *)(param_2 + 0x518 + uVar6 * 8);

        alStack_1680[uVar10 * 8] = (longlong)(local_4a8 + uVar11 * 3);

        local_4a8[uVar11 * 3 + 1] = uVar3;

        local_16a8[uVar10 * 0x10] = 0x23;

        aiStack_1690[uVar10 * 0x10 + 2] = 1;

        aiStack_1690[uVar10 * 0x10 + 3] = 1;

        auStack_16a0[uVar10 * 8 + 1] = uVar5;

        uVar10 = uVar9;

        uVar6 = (ulonglong)uVar8;

        uVar11 = uVar7;

      } while (uVar8 < *(uint *)(puVar2 + 7));

    }

    uVar6 = 0;

    uVar10 = uVar9;

    if (*(int *)((longlong)puVar2 + 0x3c) != 0) {

      do {

        uVar9 = (ulonglong)((int)uVar10 + 1);

        auStack_16a0[uVar10 * 8] = 0;

        aiStack_1690[uVar10 * 0x10 + 1] = 0;

        local_16a8[uVar10 * 0x10] = 0x23;

        aiStack_1690[uVar10 * 0x10 + 2] = 1;

        aiStack_1690[uVar10 * 0x10 + 3] = 2;

        iVar1 = *(int *)(puVar2 + 7);

        alStack_1680[uVar10 * 8 + 2] = 0;

        aiStack_1690[uVar10 * 0x10] = iVar1 + (int)uVar6;

        alStack_1680[uVar10 * 8 + 1] = 0;

        auStack_498[uVar7 * 6] = 1;

        uVar8 = (int)uVar6 + 1;

        auStack_16a0[uVar10 * 8 + 1] = uVar5;

        alStack_1680[uVar10 * 8] = (longlong)(local_4a8 + uVar7 * 3);

        local_4a8[uVar7 * 3 + 1] = *(undefined8 *)(param_2 + 0x618 + uVar6 * 8);

        local_4a8[uVar7 * 3] = 0;

        uVar10 = uVar9;

        uVar6 = (ulonglong)uVar8;

        uVar7 = (ulonglong)((int)uVar7 + 1);

      } while (uVar8 < *(uint *)((longlong)puVar2 + 0x3c));

    }

    uVar7 = uVar9;

    uVar10 = 0;

    uVar6 = uVar13;

    if (*(int *)(puVar2 + 8) != 0) {

      do {

        uVar9 = (ulonglong)((int)uVar7 + 1);

        auStack_16a0[uVar7 * 8] = 0;

        aiStack_1690[uVar7 * 0x10 + 1] = 0;

        local_16a8[uVar7 * 0x10] = 0x23;

        aiStack_1690[uVar7 * 0x10 + 2] = 1;

        aiStack_1690[uVar7 * 0x10 + 3] = 7;

        uVar8 = (int)uVar10 + 1;

        aiStack_1690[uVar7 * 0x10] =

             *(int *)((longlong)puVar2 + 0x3c) + (int)uVar10 + *(int *)(puVar2 + 7);

        alStack_1680[uVar7 * 8 + 2] = 0;

        uVar13 = (ulonglong)((int)uVar6 + 1);

        alStack_1680[uVar7 * 8] = 0;

        uVar3 = *(undefined8 *)(param_2 + 0x658 + uVar10 * 8);

        auStack_16a0[uVar7 * 8 + 1] = uVar5;

        local_1828[uVar6 * 3 + 1] = 0;

        local_1828[uVar6 * 3 + 2] = 0xffffffffffffffff;

        local_1828[uVar6 * 3] = uVar3;

        alStack_1680[uVar7 * 8 + 1] = (longlong)(local_1828 + uVar6 * 3);

        uVar7 = uVar9;

        uVar10 = (ulonglong)uVar8;

        uVar6 = uVar13;

      } while (uVar8 < *(uint *)(puVar2 + 8));

    }

    *(undefined1 *)(param_2 + 0x24b) = 0;

  }

  if (*(char *)(param_2 + 0x24c) != '\0') {

    uVar5 = FUN_1401b9ed0(param_1,param_2,puVar2[4]);

    uVar10 = 0;

    *(undefined8 *)(param_2 + 0x270) = uVar5;

    uVar7 = uVar9;

    if (*(int *)((longlong)puVar2 + 0x44) != 0) {

      do {

        plVar4 = *(longlong **)(param_2 + 0x9c0 + uVar10 * 8);

        uVar9 = (ulonglong)((int)uVar7 + 1);

        aiStack_1690[uVar7 * 0x10] = (int)uVar10;

        uVar8 = (int)uVar10 + 1;

        uVar10 = (ulonglong)uVar8;

        local_16a8[uVar7 * 0x10] = 0x23;

        auStack_16a0[uVar7 * 8] = 0;

        aiStack_1690[uVar7 * 0x10 + 2] = 1;

        aiStack_1690[uVar7 * 0x10 + 3] = 8;

        aiStack_1690[uVar7 * 0x10 + 1] = 0;

        auStack_16a0[uVar7 * 8 + 1] = uVar5;

        alStack_1680[uVar7 * 8 + 2] = 0;

        alStack_1680[uVar7 * 8] = 0;

        local_1828[uVar13 * 3] = *(undefined8 *)(*plVar4 + 0x10);

        local_1828[uVar13 * 3 + 1] = 0;

        local_1828[uVar13 * 3 + 2] = 0x1000;

        alStack_1680[uVar7 * 8 + 1] = (longlong)(local_1828 + uVar13 * 3);

        uVar7 = uVar9;

        uVar13 = (ulonglong)((int)uVar13 + 1);

      } while (uVar8 < *(uint *)((longlong)puVar2 + 0x44));

    }

    *(undefined1 *)(param_2 + 0x24c) = 0;

  }

  uVar7 = 0;

  if (*(int *)((longlong)puVar2 + 0x44) != 0) {

    do {

      uVar8 = (int)uVar7 + 1;

      local_1848[uVar12] = *(undefined4 *)(*(longlong *)(param_2 + 0x9c0 + uVar7 * 8) + 8);

      uVar12 = (ulonglong)((int)uVar12 + 1);

      uVar7 = (ulonglong)uVar8;

    } while (uVar8 < *(uint *)((longlong)puVar2 + 0x44));

  }

  uVar14 = 0;

  (**(code **)(param_1 + 0xc78))(*(undefined8 *)(param_1 + 0x570),uVar9,local_16a8,0,0);

  local_1868 = *(undefined8 *)(param_2 + 600);

  local_1860 = *(undefined8 *)(param_2 + 0x260);

  local_1858 = *(undefined8 *)(param_2 + 0x268);

  local_1850 = *(undefined8 *)(param_2 + 0x270);

  (**(code **)(param_1 + 0xa20))

            (*(undefined8 *)(param_2 + 0x118),0,*puVar2,0,CONCAT44(uVar14,4),&local_1868,(int)uVar12

             ,local_1848);

  *(undefined1 *)(param_2 + 0x24a) = 0;

  *(undefined1 *)(param_2 + 0x24d) = 0;

  return;

}




