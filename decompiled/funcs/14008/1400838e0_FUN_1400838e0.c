// Address: 0x1400838e0
// Ghidra name: FUN_1400838e0
// ============ 0x1400838e0 FUN_1400838e0 (size=416) ============


void FUN_1400838e0(undefined8 param_1,longlong param_2,int param_3,undefined4 param_4,

                  undefined4 param_5,undefined4 param_6)



{

  undefined4 uVar1;

  undefined1 auVar2 [16];

  undefined8 uVar3;

  longlong lVar4;

  undefined4 *puVar5;

  longlong lVar6;

  ulonglong uVar7;

  longlong lVar8;

  undefined ***local_e0;

  undefined8 local_d8;

  undefined4 local_d0;

  undefined4 local_cc;

  undefined4 local_c8;

  undefined1 local_c4;

  undefined4 local_c2;

  undefined2 local_be;

  undefined **local_b8;

  undefined4 local_b0;

  undefined8 local_ac;

  undefined4 local_a4;

  undefined4 local_20;

  

  uVar7 = (ulonglong)param_3;

  local_b8 = b2PolygonShape::vftable;

  local_b0 = 2;

  local_ac = 0x3c23d70a;

  lVar6 = 0;

  local_20 = 0;

  local_a4 = 0;

  auVar2._8_8_ = 0;

  auVar2._0_8_ = uVar7;

  uVar3 = SUB168(ZEXT816(8) * auVar2,0);

  if (SUB168(ZEXT816(8) * auVar2,8) != 0) {

    uVar3 = 0xffffffffffffffff;

  }

  lVar4 = thunk_FUN_1402c704c(uVar3);

  param_2 = param_2 - lVar4;

  if (3 < (longlong)uVar7) {

    puVar5 = (undefined4 *)(lVar4 + 0x14);

    lVar8 = (uVar7 - 4 >> 2) + 1;

    lVar6 = lVar8 * 4;

    do {

      uVar1 = *(undefined4 *)((longlong)puVar5 + param_2 + -0x10);

      puVar5[-5] = *(undefined4 *)((longlong)puVar5 + param_2 + -0x14);

      puVar5[-4] = uVar1;

      uVar1 = *(undefined4 *)((longlong)puVar5 + param_2 + -8);

      puVar5[-3] = *(undefined4 *)((longlong)puVar5 + param_2 + -0xc);

      puVar5[-2] = uVar1;

      uVar1 = *(undefined4 *)((longlong)puVar5 + param_2);

      puVar5[-1] = *(undefined4 *)((longlong)puVar5 + param_2 + -4);

      *puVar5 = uVar1;

      uVar1 = *(undefined4 *)((longlong)puVar5 + param_2 + 8);

      puVar5[1] = *(undefined4 *)((longlong)puVar5 + param_2 + 4);

      puVar5[2] = uVar1;

      puVar5 = puVar5 + 8;

      lVar8 = lVar8 + -1;

    } while (lVar8 != 0);

  }

  if (lVar6 < (longlong)uVar7) {

    puVar5 = (undefined4 *)(lVar4 + 4 + lVar6 * 8);

    do {

      uVar1 = *(undefined4 *)(param_2 + (longlong)puVar5);

      puVar5[-1] = *(undefined4 *)(param_2 + -4 + (longlong)puVar5);

      *puVar5 = uVar1;

      lVar6 = lVar6 + 1;

      puVar5 = puVar5 + 2;

    } while (lVar6 < (longlong)uVar7);

  }

  FUN_14000dec0(&local_b8,lVar4,param_3,lVar4,lVar4);

  local_d8 = 0;

  local_c2 = 0xffff0001;

  local_be = 0;

  local_c4 = 0;

  local_e0 = &local_b8;

  local_d0 = param_5;

  local_cc = param_6;

  local_c8 = param_4;

  FUN_14000fbc0(param_1,&local_e0);

  return;

}




