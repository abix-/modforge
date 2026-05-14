// Address: 0x1401f4bb0
// Ghidra name: FUN_1401f4bb0
// ============ 0x1401f4bb0 FUN_1401f4bb0 (size=988) ============


undefined1 FUN_1401f4bb0(longlong param_1,longlong param_2,undefined4 param_3,longlong param_4)



{

  undefined8 *_Buf2;

  int iVar1;

  longlong lVar2;

  undefined8 uVar3;

  float fVar4;

  char cVar5;

  undefined1 uVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  undefined4 uVar9;

  undefined4 uVar10;

  undefined4 uVar11;

  code *pcVar12;

  int iVar13;

  

  lVar2 = *(longlong *)(param_2 + 0x30);

  iVar1 = *(int *)(param_2 + 0x2c);

  if (*(char *)(param_1 + 0x270) != '\0') {

    if (*(longlong *)(param_1 + 0x280) == 0) {

      iVar13 = (*(int *)(param_1 + 700) - *(int *)(param_1 + 0x26c)) - *(int *)(param_1 + 0x264);

    }

    else {

      iVar13 = *(int *)(param_1 + 0x264);

    }

    (**(code **)(param_1 + 0x178))

              (*(undefined4 *)(param_1 + 0x260),iVar13,*(undefined4 *)(param_1 + 0x268),

               *(undefined4 *)(param_1 + 0x26c));

    fVar4 = DAT_14030374c;

    if ((*(int *)(param_1 + 0x268) != 0) && (*(int *)(param_1 + 0x26c) != 0)) {

      *(float *)(param_1 + 0x2d0) = DAT_14030374c / (float)*(int *)(param_1 + 0x268);

      uVar7 = DAT_14039ca80;

      if (*(longlong *)(param_1 + 0x280) == 0) {

        *(float *)(param_1 + 0x2e4) = DAT_140304c68 / (float)*(int *)(param_1 + 0x26c);

        uVar7 = DAT_14039ca44;

      }

      else {

        *(float *)(param_1 + 0x2e4) = fVar4 / (float)*(int *)(param_1 + 0x26c);

      }

      *(undefined4 *)(param_1 + 0x304) = uVar7;

    }

    *(undefined1 *)(param_1 + 0x270) = 0;

  }

  if (*(char *)(param_1 + 0x28c) != '\0') {

    if (*(char *)(param_1 + 0x28d) == '\0') {

      pcVar12 = *(code **)(param_1 + 0x80);

    }

    else {

      pcVar12 = *(code **)(param_1 + 0x98);

    }

    (*pcVar12)(0xc11);

    *(undefined1 *)(param_1 + 0x28c) = 0;

  }

  if ((*(char *)(param_1 + 0x28d) != '\0') && (*(char *)(param_1 + 0x28e) != '\0')) {

    if (*(longlong *)(param_1 + 0x280) == 0) {

      iVar13 = ((*(int *)(param_1 + 700) - *(int *)(param_1 + 0x264)) - *(int *)(param_1 + 0x29c)) -

               *(int *)(param_1 + 0x294);

    }

    else {

      iVar13 = *(int *)(param_1 + 0x264) + *(int *)(param_1 + 0x294);

    }

    (**(code **)(param_1 + 0x110))

              (*(int *)(param_1 + 0x290) + *(int *)(param_1 + 0x260),iVar13,

               *(undefined4 *)(param_1 + 0x298),*(undefined4 *)(param_1 + 0x29c));

    *(undefined1 *)(param_1 + 0x28e) = 0;

  }

  if ((*(char *)(param_1 + 0x2a1) != '\0') || ((lVar2 != 0) != (bool)*(char *)(param_1 + 0x2a0))) {

    if (lVar2 != 0) {

      (**(code **)(param_1 + 0xa0))(2);

    }

    else {

      (**(code **)(param_1 + 0x88))();

    }

    *(bool *)(param_1 + 0x2a0) = lVar2 != 0;

    *(undefined1 *)(param_1 + 0x2a1) = 0;

  }

  uVar7 = 0x18;

  if (lVar2 == 0) {

    uVar8 = 0x120005a0;

  }

  else {

    (**(code **)(param_1 + 0x170))(2,2,0x1406,0,0x20,*(longlong *)(param_2 + 8) + 0x18 + param_4);

    uVar8 = *(undefined4 *)(lVar2 + 0x18);

    uVar7 = 0x20;

  }

  cVar5 = FUN_1401f3710(param_1,lVar2,param_3,*(undefined4 *)(param_2 + 0x38),uVar8);

  uVar6 = 0;

  if (cVar5 != '\0') {

    lVar2 = *(longlong *)(param_1 + 0x2c0);

    if (*(int *)(lVar2 + 0xc) != -1) {

      _Buf2 = (undefined8 *)(param_1 + 0x2d0);

      iVar13 = memcmp((void *)(lVar2 + 0x2c),_Buf2,0x40);

      if (iVar13 != 0) {

        (**(code **)(param_1 + 0x160))(*(undefined4 *)(lVar2 + 0xc),1,0,_Buf2);

        uVar3 = *(undefined8 *)(param_1 + 0x2d8);

        *(undefined8 *)(lVar2 + 0x2c) = *_Buf2;

        *(undefined8 *)(lVar2 + 0x34) = uVar3;

        uVar3 = *(undefined8 *)(param_1 + 0x2e8);

        *(undefined8 *)(lVar2 + 0x3c) = *(undefined8 *)(param_1 + 0x2e0);

        *(undefined8 *)(lVar2 + 0x44) = uVar3;

        uVar3 = *(undefined8 *)(param_1 + 0x2f8);

        *(undefined8 *)(lVar2 + 0x4c) = *(undefined8 *)(param_1 + 0x2f0);

        *(undefined8 *)(lVar2 + 0x54) = uVar3;

        uVar3 = *(undefined8 *)(param_1 + 0x308);

        *(undefined8 *)(lVar2 + 0x5c) = *(undefined8 *)(param_1 + 0x300);

        *(undefined8 *)(lVar2 + 100) = uVar3;

      }

    }

    if (iVar1 != *(int *)(param_1 + 0x288)) {

      if (iVar1 == 0) {

        (**(code **)(param_1 + 0x80))();

      }

      else {

        (**(code **)(param_1 + 0x98))(0xbe2);

        uVar8 = FUN_14014dea0(iVar1);

        uVar8 = FUN_1401ef410(uVar8);

        uVar9 = FUN_14014dee0(iVar1);

        uVar9 = FUN_1401ef410(uVar9);

        uVar10 = FUN_14014dec0(iVar1);

        uVar10 = FUN_1401ef410(uVar10);

        uVar11 = FUN_14014df00(iVar1);

        uVar11 = FUN_1401ef410(uVar11);

        (**(code **)(param_1 + 0x38))(uVar11,uVar10,uVar9,uVar8);

        uVar8 = FUN_14014de60(iVar1);

        uVar8 = FUN_1401ef3d0(uVar8);

        uVar9 = FUN_14014de80(iVar1);

        uVar9 = FUN_1401ef3d0(uVar9);

        (**(code **)(param_1 + 0x30))(uVar9,uVar8);

      }

      *(int *)(param_1 + 0x288) = iVar1;

    }

    param_4 = *(longlong *)(param_2 + 8) + param_4;

    (**(code **)(param_1 + 0x170))(0,2,0x1406,0,uVar7,param_4);

    (**(code **)(param_1 + 0x170))(1,4,0x1406,1,uVar7,param_4 + 8);

    uVar6 = 1;

  }

  return uVar6;

}




