// Address: 0x1400bea50
// Ghidra name: FUN_1400bea50
// ============ 0x1400bea50 FUN_1400bea50 (size=869) ============


void FUN_1400bea50(longlong *param_1,ulonglong param_2)



{

  undefined1 *puVar1;

  ulonglong uVar2;

  longlong lVar3;

  undefined8 *puVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  longlong lVar7;

  undefined4 *puVar8;

  undefined8 *puVar9;

  longlong lVar10;

  

  if (0xb60b60b60b60b6 < param_2) {

                    /* WARNING: Subroutine does not return */

    FUN_14002f0d0();

  }

  lVar3 = (param_1[1] - *param_1) / 0x168;

  uVar2 = (param_1[2] - *param_1) / 0x168;

  if (0xb60b60b60b60b6 - (uVar2 >> 1) < uVar2) {

    uVar6 = 0xb60b60b60b60b6;

  }

  else {

    uVar2 = (uVar2 >> 1) + uVar2;

    uVar6 = param_2;

    if ((param_2 <= uVar2) && (uVar6 = uVar2, 0xb60b60b60b60b6 < uVar2)) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

  }

  lVar7 = FUN_1400285e0(uVar6 * 0x168);

  FUN_1400bf070(lVar3 * 0x168 + lVar7,param_2 - lVar3,param_1);

  lVar3 = param_1[1];

  lVar10 = *param_1;

  if (lVar10 != lVar3) {

    puVar8 = (undefined4 *)(lVar7 + 0xc);

    do {

      *(undefined ***)(puVar8 + -3) = b2Shape::vftable;

      puVar8[-1] = *(undefined4 *)(lVar10 + 8);

      *puVar8 = *(undefined4 *)(lVar10 + 0xc);

      *(undefined ***)(puVar8 + -3) = b2PolygonShape::vftable;

      *(undefined8 *)(puVar8 + 1) = *(undefined8 *)(lVar10 + 0x10);

      uVar5 = *(undefined8 *)(lVar10 + 0x20);

      *(undefined8 *)(puVar8 + 3) = *(undefined8 *)(lVar10 + 0x18);

      *(undefined8 *)(puVar8 + 5) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0x30);

      *(undefined8 *)(puVar8 + 7) = *(undefined8 *)(lVar10 + 0x28);

      *(undefined8 *)(puVar8 + 9) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0x40);

      *(undefined8 *)(puVar8 + 0xb) = *(undefined8 *)(lVar10 + 0x38);

      *(undefined8 *)(puVar8 + 0xd) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0x50);

      *(undefined8 *)(puVar8 + 0xf) = *(undefined8 *)(lVar10 + 0x48);

      *(undefined8 *)(puVar8 + 0x11) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0x60);

      *(undefined8 *)(puVar8 + 0x13) = *(undefined8 *)(lVar10 + 0x58);

      *(undefined8 *)(puVar8 + 0x15) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0x70);

      *(undefined8 *)(puVar8 + 0x17) = *(undefined8 *)(lVar10 + 0x68);

      *(undefined8 *)(puVar8 + 0x19) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0x80);

      *(undefined8 *)(puVar8 + 0x1b) = *(undefined8 *)(lVar10 + 0x78);

      *(undefined8 *)(puVar8 + 0x1d) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0x90);

      *(undefined8 *)(puVar8 + 0x1f) = *(undefined8 *)(lVar10 + 0x88);

      *(undefined8 *)(puVar8 + 0x21) = uVar5;

      puVar8[0x23] = *(undefined4 *)(lVar10 + 0x98);

      *(undefined ***)(puVar8 + 0x25) = b2Shape::vftable;

      puVar8[0x27] = *(undefined4 *)(lVar10 + 0xa8);

      puVar8[0x28] = *(undefined4 *)(lVar10 + 0xac);

      *(undefined ***)(puVar8 + 0x25) = b2PolygonShape::vftable;

      *(undefined8 *)(puVar8 + 0x29) = *(undefined8 *)(lVar10 + 0xb0);

      uVar5 = *(undefined8 *)(lVar10 + 0xc0);

      *(undefined8 *)(puVar8 + 0x2b) = *(undefined8 *)(lVar10 + 0xb8);

      *(undefined8 *)(puVar8 + 0x2d) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0xd0);

      *(undefined8 *)(puVar8 + 0x2f) = *(undefined8 *)(lVar10 + 200);

      *(undefined8 *)(puVar8 + 0x31) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0xe0);

      *(undefined8 *)(puVar8 + 0x33) = *(undefined8 *)(lVar10 + 0xd8);

      *(undefined8 *)(puVar8 + 0x35) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0xf0);

      *(undefined8 *)(puVar8 + 0x37) = *(undefined8 *)(lVar10 + 0xe8);

      *(undefined8 *)(puVar8 + 0x39) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0x100);

      *(undefined8 *)(puVar8 + 0x3b) = *(undefined8 *)(lVar10 + 0xf8);

      *(undefined8 *)(puVar8 + 0x3d) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0x110);

      *(undefined8 *)(puVar8 + 0x3f) = *(undefined8 *)(lVar10 + 0x108);

      *(undefined8 *)(puVar8 + 0x41) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0x120);

      *(undefined8 *)(puVar8 + 0x43) = *(undefined8 *)(lVar10 + 0x118);

      *(undefined8 *)(puVar8 + 0x45) = uVar5;

      uVar5 = *(undefined8 *)(lVar10 + 0x130);

      *(undefined8 *)(puVar8 + 0x47) = *(undefined8 *)(lVar10 + 0x128);

      *(undefined8 *)(puVar8 + 0x49) = uVar5;

      puVar8[0x4b] = *(undefined4 *)(lVar10 + 0x138);

      *(undefined8 *)(puVar8 + 0x4d) = *(undefined8 *)(lVar10 + 0x140);

      puVar8[0x4f] = *(undefined4 *)(lVar10 + 0x148);

      puVar8[0x50] = *(undefined4 *)(lVar10 + 0x14c);

      puVar8[0x51] = *(undefined4 *)(lVar10 + 0x150);

      puVar8[0x52] = *(undefined4 *)(lVar10 + 0x154);

      puVar8[0x53] = *(undefined4 *)(lVar10 + 0x158);

      puVar8[0x54] = *(undefined4 *)(lVar10 + 0x15c);

      puVar1 = (undefined1 *)(lVar10 + 0x160);

      lVar10 = lVar10 + 0x168;

      *(undefined1 *)(puVar8 + 0x55) = *puVar1;

      puVar8 = puVar8 + 0x5a;

    } while (lVar10 != lVar3);

  }

  puVar9 = (undefined8 *)*param_1;

  if (puVar9 != (undefined8 *)0x0) {

    puVar4 = (undefined8 *)param_1[1];

    for (; puVar9 != puVar4; puVar9 = puVar9 + 0x2d) {

      puVar9[0x14] = b2Shape::vftable;

      *puVar9 = b2Shape::vftable;

    }

    lVar3 = *param_1;

    lVar10 = lVar3;

    if ((0xfff < (ulonglong)(((param_1[2] - lVar3) / 0x168) * 0x168)) &&

       (lVar10 = *(longlong *)(lVar3 + -8), 0x1f < (lVar3 - lVar10) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar10);

  }

  *param_1 = lVar7;

  param_1[1] = param_2 * 0x168 + lVar7;

  param_1[2] = uVar6 * 0x168 + lVar7;

  return;

}




