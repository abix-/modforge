// Address: 0x1400ce540
// Ghidra name: FUN_1400ce540
// ============ 0x1400ce540 FUN_1400ce540 (size=1125) ============


void FUN_1400ce540(longlong param_1,float param_2,char param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  undefined4 uVar4;

  longlong lVar5;

  ulonglong uVar6;

  undefined8 uVar7;

  longlong lVar8;

  uint uVar9;

  float fVar11;

  float fVar12;

  undefined4 local_res8;

  short local_resc;

  float local_res20;

  float local_res24;

  undefined **local_148;

  undefined4 local_140;

  undefined8 local_13c;

  undefined4 local_134;

  undefined4 local_b0;

  ulonglong uVar10;

  

  lVar5 = *(longlong *)(param_1 + 0x98);

  if (lVar5 != 0) {

    FUN_140005cf0(lVar5);

    FUN_1402c7088(lVar5,0x19380);

  }

  lVar5 = FUN_1402c704c(0x19380);

  uVar10 = 0;

  uVar6 = uVar10;

  if (lVar5 != 0) {

    local_res20 = 0.0;

    local_res24 = 10.0;

    uVar6 = FUN_140005a10(lVar5,&local_res20,1);

  }

  *(ulonglong *)(param_1 + 0x98) = uVar6;

  FUN_140005e00(uVar6,param_1);

  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x10c);

  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0x110);

  uVar7 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),*(undefined8 *)(param_1 + 0x10c),1);

  *(undefined8 *)(param_1 + 0xa0) = uVar7;

  *(undefined1 *)(param_1 + 0xb0) = 0;

  local_res8 = 0xfe0001;

  local_resc = 1;

  *(undefined4 *)(param_1 + 0x120) = 0xffffffff;

  fVar3 = DAT_14039ca44;

  fVar11 = DAT_14039ca34;

  fVar2 = DAT_14030374c;

  fVar1 = DAT_14030335c;

  fVar12 = 0.0;

  if (0.0 < *(float *)(param_1 + 0x11c) + DAT_14030374c) {

    param_2 = param_2 - DAT_14039ca0c;

    do {

      if (param_2 <= fVar12) {

        if (*(int *)(param_1 + 0x120) == -1) {

          *(int *)(param_1 + 0x120) = (int)local_resc;

        }

        local_148 = b2PolygonShape::vftable;

        local_140 = 2;

        local_13c = 0x3c23d70a;

        local_b0 = 0;

        local_134 = 0;

        local_res20 = *(float *)(param_1 + 0x118) * fVar11;

        local_res24 = fVar12 + fVar3;

        FUN_14000d4e0(&local_148);

        uVar7 = FUN_140083430(*(undefined8 *)(param_1 + 0xa0),&local_148,0,fVar3,0);

        FUN_1400082e0(uVar7,&local_res8);

      }

      fVar12 = fVar12 + fVar1;

      local_resc = local_resc + 1;

    } while (fVar12 < *(float *)(param_1 + 0x11c) + fVar2);

  }

  if (DAT_1403f3120 != DAT_1403f3128) {

    DAT_1403f3128 = DAT_1403f3120;

  }

  *(undefined8 *)(param_1 + 0x22c) = 0xffffffffffffffff;

  fVar2 = DAT_140304c8c;

  lVar5 = *(longlong *)(param_1 + 0x130);

  uVar6 = uVar10;

  if (*(longlong *)(param_1 + 0x138) - lVar5 >> 3 != 0) {

    do {

      if (param_3 != '\0') {

        *(undefined1 *)(*(longlong *)(uVar6 + lVar5) + 0x1a) = 0;

      }

      lVar5 = *(longlong *)(uVar6 + *(longlong *)(param_1 + 0x130));

      FUN_1400b3dc0(lVar5,*(undefined8 *)(param_1 + 0x98));

      fVar11 = (float)FUN_1400b6170(lVar5);

      uVar4 = FUN_1400c5c30(*(undefined4 *)(param_1 + 0x120),

                            1 - (int)(((fVar11 + fVar1) - *(float *)(param_1 + 0x110)) * fVar2));

      FUN_1400b6990(lVar5,uVar4,*(undefined1 *)(lVar5 + 0x1e0));

      *(undefined1 *)(lVar5 + 0x1c8) = 0;

      FUN_1400ccbd0(param_1,lVar5);

      uVar9 = (int)uVar10 + 1;

      uVar10 = (ulonglong)uVar9;

      lVar5 = *(longlong *)(param_1 + 0x130);

      uVar6 = uVar6 + 8;

    } while ((ulonglong)(longlong)(int)uVar9 <

             (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar5 >> 3));

  }

  *(undefined4 *)(param_1 + 0x244) = 0;

  *(undefined4 *)(param_1 + 0xd4) = 0xffffffff;

  *(undefined8 *)(param_1 + 0x168) = 0xffffffffffffffff;

  *(undefined4 *)(param_1 + 0x170) = 0xffffffff;

  *(undefined4 *)(param_1 + 0x1b8) = 0xffffffff;

  *(undefined4 *)(param_1 + 0x1f8) = 0;

  lVar5 = *(longlong *)(param_1 + 0x218);

  lVar8 = *(longlong *)(param_1 + 0x210);

  if (lVar8 != lVar5) {

    do {

      FUN_140027900(lVar8);

      lVar8 = lVar8 + 0x20;

    } while (lVar8 != lVar5);

    *(undefined8 *)(param_1 + 0x218) = *(undefined8 *)(param_1 + 0x210);

  }

  *(undefined4 *)(param_1 + 0x18c) = 0xffffffff;

  *(undefined8 *)(param_1 + 400) = 0;

  FUN_1400c8d90(*(undefined8 *)(param_1 + 0x248));

  if (DAT_1403f3110 != 0) {

    FUN_1400c8d90();

  }

  FUN_140040fc0(*(float *)(param_1 + 0x10c),

                (float)DAT_14030b680 / *(float *)(param_1 + 0x114) + *(float *)(param_1 + 0x10c));

  return;

}




