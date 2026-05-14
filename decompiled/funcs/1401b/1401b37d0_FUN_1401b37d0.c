// Address: 0x1401b37d0
// Ghidra name: FUN_1401b37d0
// ============ 0x1401b37d0 FUN_1401b37d0 (size=1610) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void FUN_1401b37d0(longlong param_1,longlong param_2)



{

  int iVar1;

  int iVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  longlong *plVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  uint uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  uint uVar13;

  ulonglong uVar14;

  ulonglong uVar15;

  undefined4 uVar16;

  undefined8 local_1238;

  undefined8 local_1230;

  undefined8 local_1228;

  undefined4 local_1220 [6];

  undefined8 local_1208 [60];

  undefined4 local_1028 [2];

  undefined8 auStack_1020 [2];

  int aiStack_1010 [4];

  undefined8 auStack_1000 [411];

  undefined8 local_328 [2];

  undefined4 auStack_318 [186];

  undefined8 uStack_30;

  

  uStack_30 = 0x1401b37f5;

  uVar9 = 0;

  uVar15 = 0;

  uVar11 = 0;

  uVar14 = 0;

  uVar13 = 0;

  if ((((*(char *)(param_2 + 0x24e) != '\0') || (*(char *)(param_2 + 0x24f) != '\0')) ||

      (*(char *)(param_2 + 0x250) != '\0')) || (*(char *)(param_2 + 0x251) != '\0')) {

    puVar3 = *(undefined8 **)(*(longlong *)(param_2 + 0x158) + 0x28);

    if (*(char *)(param_2 + 0x24e) != '\0') {

      uVar6 = FUN_1401b9ed0(param_1,param_2,puVar3[1]);

      *(undefined8 *)(param_2 + 0x278) = uVar6;

      uVar11 = uVar9;

      if (*(int *)(puVar3 + 4) != 0) {

        do {

          auStack_1020[uVar11 * 8] = 0;

          aiStack_1010[uVar11 * 0x10 + 1] = 0;

          auStack_1000[uVar11 * 8 + 2] = 0;

          auStack_1000[uVar11 * 8 + 1] = 0;

          aiStack_1010[uVar11 * 0x10] = (int)uVar11;

          uVar4 = *(undefined8 *)(param_2 + 0x718 + uVar11 * 8);

          local_1028[uVar11 * 0x10] = 0x23;

          aiStack_1010[uVar11 * 0x10 + 2] = 1;

          aiStack_1010[uVar11 * 0x10 + 3] = 1;

          local_328[uVar11 * 3] = uVar4;

          uVar8 = (int)uVar11 + 1;

          uVar9 = (ulonglong)uVar8;

          local_328[uVar11 * 3 + 1] = *(undefined8 *)(param_2 + 0x698 + uVar11 * 8);

          auStack_1020[uVar11 * 8 + 1] = uVar6;

          auStack_318[uVar11 * 6] = 5;

          auStack_1000[uVar11 * 8] = local_328 + uVar11 * 3;

          uVar11 = uVar9;

        } while (uVar8 < *(uint *)(puVar3 + 4));

      }

      uVar10 = uVar9;

      uVar7 = 0;

      uVar12 = uVar9;

      uVar11 = uVar9;

      if (*(int *)((longlong)puVar3 + 0x24) != 0) {

        do {

          uVar11 = (ulonglong)((int)uVar12 + 1);

          uVar9 = (ulonglong)((int)uVar10 + 1);

          auStack_1020[uVar10 * 8] = 0;

          aiStack_1010[uVar10 * 0x10 + 1] = 0;

          local_1028[uVar10 * 0x10] = 0x23;

          aiStack_1010[uVar10 * 0x10 + 2] = 1;

          aiStack_1010[uVar10 * 0x10 + 3] = 2;

          iVar1 = *(int *)(puVar3 + 4);

          auStack_1000[uVar10 * 8 + 2] = 0;

          aiStack_1010[uVar10 * 0x10] = iVar1 + (int)uVar7;

          auStack_1000[uVar10 * 8 + 1] = 0;

          auStack_318[uVar12 * 6] = 1;

          uVar8 = (int)uVar7 + 1;

          auStack_1020[uVar10 * 8 + 1] = uVar6;

          auStack_1000[uVar10 * 8] = local_328 + uVar12 * 3;

          local_328[uVar12 * 3 + 1] = *(undefined8 *)(param_2 + 0x798 + uVar7 * 8);

          local_328[uVar12 * 3] = 0;

          uVar10 = uVar9;

          uVar7 = (ulonglong)uVar8;

          uVar12 = uVar11;

        } while (uVar8 < *(uint *)((longlong)puVar3 + 0x24));

      }

      uVar10 = uVar9;

      uVar7 = uVar15;

      if (*(int *)(puVar3 + 5) != 0) {

        do {

          uVar9 = (ulonglong)((int)uVar10 + 1);

          auStack_1020[uVar10 * 8] = 0;

          aiStack_1010[uVar10 * 0x10 + 1] = 0;

          local_1028[uVar10 * 0x10] = 0x23;

          aiStack_1010[uVar10 * 0x10 + 2] = 1;

          aiStack_1010[uVar10 * 0x10 + 3] = 7;

          iVar1 = *(int *)(puVar3 + 4);

          iVar2 = *(int *)((longlong)puVar3 + 0x24);

          auStack_1000[uVar10 * 8 + 2] = 0;

          aiStack_1010[uVar10 * 0x10] = iVar1 + iVar2 + (int)uVar7;

          auStack_1000[uVar10 * 8] = 0;

          uVar4 = *(undefined8 *)(param_2 + 0x7d8 + uVar7 * 8);

          uVar8 = (int)uVar7 + 1;

          uVar15 = (ulonglong)uVar8;

          auStack_1020[uVar10 * 8 + 1] = uVar6;

          local_1208[uVar7 * 3 + 1] = 0;

          local_1208[uVar7 * 3 + 2] = 0xffffffffffffffff;

          local_1208[uVar7 * 3] = uVar4;

          auStack_1000[uVar10 * 8 + 1] = local_1208 + uVar7 * 3;

          uVar10 = uVar9;

          uVar7 = uVar15;

        } while (uVar8 < *(uint *)(puVar3 + 5));

      }

      *(undefined1 *)(param_2 + 0x24e) = 0;

    }

    if (*(char *)(param_2 + 0x24f) != '\0') {

      uVar6 = FUN_1401b9ed0(param_1,param_2,puVar3[2]);

      *(undefined8 *)(param_2 + 0x280) = uVar6;

      uVar7 = 0;

      uVar10 = uVar9;

      if (*(int *)((longlong)puVar3 + 0x2c) != 0) {

        do {

          uVar9 = (ulonglong)((int)uVar10 + 1);

          auStack_1020[uVar10 * 8] = 0;

          aiStack_1010[uVar10 * 0x10 + 1] = 0;

          auStack_1000[uVar10 * 8 + 2] = 0;

          auStack_1000[uVar10 * 8 + 1] = 0;

          aiStack_1010[uVar10 * 0x10] = (int)uVar7;

          local_1028[uVar10 * 0x10] = 0x23;

          aiStack_1010[uVar10 * 0x10 + 2] = 1;

          aiStack_1010[uVar10 * 0x10 + 3] = 3;

          auStack_1020[uVar10 * 8 + 1] = uVar6;

          uVar8 = (int)uVar7 + 1;

          auStack_318[uVar11 * 6] = 1;

          auStack_1000[uVar10 * 8] = local_328 + uVar11 * 3;

          uVar4 = *(undefined8 *)(param_2 + 0x898 + uVar7 * 8);

          local_328[uVar11 * 3] = 0;

          local_328[uVar11 * 3 + 1] = uVar4;

          uVar10 = uVar9;

          uVar7 = (ulonglong)uVar8;

          uVar11 = (ulonglong)((int)uVar11 + 1);

        } while (uVar8 < *(uint *)((longlong)puVar3 + 0x2c));

      }

      uVar11 = uVar9;

      uVar10 = 0;

      uVar7 = uVar15;

      if (*(int *)(puVar3 + 6) != 0) {

        do {

          uVar9 = (ulonglong)((int)uVar11 + 1);

          local_1028[uVar11 * 0x10] = 0x23;

          auStack_1020[uVar11 * 8] = 0;

          aiStack_1010[uVar11 * 0x10 + 2] = 1;

          aiStack_1010[uVar11 * 0x10 + 3] = 7;

          aiStack_1010[uVar11 * 0x10 + 1] = 0;

          iVar1 = *(int *)((longlong)puVar3 + 0x2c);

          auStack_1020[uVar11 * 8 + 1] = uVar6;

          aiStack_1010[uVar11 * 0x10] = iVar1 + (int)uVar10;

          uVar8 = (int)uVar10 + 1;

          auStack_1000[uVar11 * 8 + 2] = 0;

          auStack_1000[uVar11 * 8] = 0;

          uVar4 = *(undefined8 *)(param_2 + 0x8d8 + uVar10 * 8);

          uVar15 = (ulonglong)((int)uVar7 + 1);

          local_1208[uVar7 * 3 + 1] = 0;

          local_1208[uVar7 * 3 + 2] = 0xffffffffffffffff;

          auStack_1000[uVar11 * 8 + 1] = local_1208 + uVar7 * 3;

          local_1208[uVar7 * 3] = uVar4;

          uVar11 = uVar9;

          uVar10 = (ulonglong)uVar8;

          uVar7 = uVar15;

        } while (uVar8 < *(uint *)(puVar3 + 6));

      }

      *(undefined1 *)(param_2 + 0x24f) = 0;

    }

    uVar11 = 0;

    if (*(char *)(param_2 + 0x250) != '\0') {

      uVar6 = FUN_1401b9ed0(param_1,param_2,puVar3[3]);

      *(undefined8 *)(param_2 + 0x288) = uVar6;

      uVar10 = uVar9;

      if (*(int *)((longlong)puVar3 + 0x34) != 0) {

        do {

          plVar5 = *(longlong **)(param_2 + 0x9e0 + uVar11 * 8);

          uVar9 = (ulonglong)((int)uVar10 + 1);

          aiStack_1010[uVar10 * 0x10] = (int)uVar11;

          uVar8 = (int)uVar11 + 1;

          uVar11 = (ulonglong)uVar8;

          local_1028[uVar10 * 0x10] = 0x23;

          auStack_1020[uVar10 * 8] = 0;

          aiStack_1010[uVar10 * 0x10 + 2] = 1;

          aiStack_1010[uVar10 * 0x10 + 3] = 8;

          aiStack_1010[uVar10 * 0x10 + 1] = 0;

          auStack_1020[uVar10 * 8 + 1] = uVar6;

          auStack_1000[uVar10 * 8 + 2] = 0;

          auStack_1000[uVar10 * 8] = 0;

          local_1208[uVar15 * 3] = *(undefined8 *)(*plVar5 + 0x10);

          local_1208[uVar15 * 3 + 1] = 0;

          local_1208[uVar15 * 3 + 2] = 0x1000;

          auStack_1000[uVar10 * 8 + 1] = local_1208 + uVar15 * 3;

          uVar10 = uVar9;

          uVar15 = (ulonglong)((int)uVar15 + 1);

        } while (uVar8 < *(uint *)((longlong)puVar3 + 0x34));

      }

      *(undefined1 *)(param_2 + 0x250) = 0;

    }

    if (*(int *)((longlong)puVar3 + 0x34) != 0) {

      do {

        local_1220[uVar14] = *(undefined4 *)(*(longlong *)(param_2 + 0x9e0 + uVar14 * 8) + 8);

        uVar13 = (int)uVar14 + 1;

        uVar14 = (ulonglong)uVar13;

      } while (uVar13 < *(uint *)((longlong)puVar3 + 0x34));

    }

    uVar16 = 0;

    (**(code **)(param_1 + 0xc78))(*(undefined8 *)(param_1 + 0x570),uVar9,local_1028,0,0);

    local_1238 = *(undefined8 *)(param_2 + 0x278);

    local_1230 = *(undefined8 *)(param_2 + 0x280);

    local_1228 = *(undefined8 *)(param_2 + 0x288);

    (**(code **)(param_1 + 0xa20))

              (*(undefined8 *)(param_2 + 0x118),1,*puVar3,0,CONCAT44(uVar16,3),&local_1238,uVar13,

               local_1220);

    *(undefined1 *)(param_2 + 0x251) = 0;

  }

  return;

}




