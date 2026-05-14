// Address: 0x140148140
// Ghidra name: FUN_140148140
// ============ 0x140148140 FUN_140148140 (size=648) ============


longlong FUN_140148140(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  uint uVar5;

  char cVar6;

  undefined1 uVar7;

  uint uVar8;

  longlong lVar9;

  longlong lVar10;

  undefined4 local_res20;

  

  cVar6 = FUN_1401489c0();

  if (cVar6 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return 0;

  }

  uVar5 = *(uint *)(param_1 + 4);

  if (uVar5 == 0) {

LAB_140148220:

    uVar8 = uVar5 & 0xf000000;

    if (((uVar8 != 0xc000000) && (uVar8 != 0x2000000)) &&

       (local_res20 = param_4, uVar8 != 0x3000000)) goto LAB_14014823c;

  }

  else {

    if ((uVar5 & 0xf0000000) != 0x10000000) {

      lVar9 = FUN_140145bb0(param_1,0x16362004);

      if (lVar9 == 0) {

        return 0;

      }

      lVar10 = FUN_140148140(lVar9,param_2,param_3,param_4);

      FUN_140146010(lVar9);

      if (lVar10 == 0) {

        return 0;

      }

      lVar9 = FUN_140145220(lVar10,*(undefined4 *)(param_1 + 4),0,*(undefined4 *)(param_1 + 0x40),

                            *(undefined4 *)(param_1 + 0x34));

      FUN_140146010(lVar10);

      return lVar9;

    }

    if ((uVar5 & 0xf000000) != 0x1000000) goto LAB_140148220;

  }

  local_res20 = 0;

LAB_14014823c:

  if ((*(longlong *)(param_1 + 0x18) == 0) && ((*param_1 & 2) == 0)) {

    lVar9 = FUN_140145bc0(param_2,param_3,uVar5,0,0);

  }

  else {

    lVar9 = FUN_140145e60(param_2,param_3);

  }

  if (lVar9 == 0) {

    return 0;

  }

  FUN_1401487f0(lVar9,*(undefined8 *)(param_1 + 0x48));

  FUN_1401487a0(lVar9,*(undefined4 *)(param_1 + 0x40));

  uVar7 = FUN_140148990(param_1);

  FUN_1401488a0(lVar9,uVar7);

  if ((*(longlong *)(param_1 + 0x18) != 0) || ((*param_1 & 2) != 0)) {

    bVar1 = param_1[0x112];

    bVar2 = param_1[0x113];

    uVar5 = *(uint *)(param_1 + 0x108);

    bVar3 = param_1[0x111];

    bVar4 = param_1[0x110];

    *(uint *)(param_1 + 0x108) = uVar5 & 0x6000;

    param_1[0x110] = 0xff;

    param_1[0x111] = 0xff;

    param_1[0x112] = 0xff;

    param_1[0x113] = 0xff;

    FUN_14017ba60(param_1 + 0x78);

    cVar6 = FUN_140143490(param_1,0,lVar9,0,local_res20);

    *(byte *)(lVar9 + 0x110) = bVar4;

    *(byte *)(lVar9 + 0x111) = bVar3;

    *(byte *)(lVar9 + 0x112) = bVar1;

    *(byte *)(lVar9 + 0x113) = bVar2;

    *(uint *)(lVar9 + 0x108) = uVar5 & 0xffff9fff;

    param_1[0x110] = bVar4;

    param_1[0x111] = bVar3;

    param_1[0x112] = bVar1;

    param_1[0x113] = bVar2;

    *(uint *)(param_1 + 0x108) = uVar5;

    FUN_14017ba60(param_1 + 0x78);

    if (cVar6 == '\0') {

      FUN_140146010(lVar9);

      return 0;

    }

  }

  return lVar9;

}




