// Address: 0x14012f930
// Ghidra name: FUN_14012f930
// ============ 0x14012f930 FUN_14012f930 (size=443) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



uint FUN_14012f930(undefined2 *param_1,undefined8 param_2,longlong param_3,undefined8 param_4)



{

  byte bVar1;

  uint uVar2;

  int iVar3;

  longlong lVar4;

  undefined1 *puVar5;

  ulonglong uVar6;

  undefined1 *puVar7;

  undefined1 *puVar8;

  undefined1 *puVar9;

  ulonglong uVar10;

  undefined1 *puVar11;

  bool bVar12;

  undefined1 auStack_98 [32];

  undefined1 local_78 [64];

  

  puVar8 = auStack_98;

  puVar11 = local_78;

  puVar7 = (undefined1 *)0x0;

  if (param_1 != (undefined2 *)0x0) {

    *param_1 = 0;

  }

  puVar5 = puVar7;

  if (param_3 != 0) {

    lVar4 = FUN_14012fd40(param_3);

    puVar5 = (undefined1 *)FUN_140197820(&DAT_14039c6f0,"WCHAR_T",param_3,lVar4 * 2 + 2);

    if (puVar5 == (undefined1 *)0x0) {

      return 0xffffffff;

    }

  }

  uVar2 = FUN_14012f860(puVar11,0x40,puVar5,param_4);

  puVar9 = auStack_98;

  if ((int)uVar2 < 0) {

LAB_14012fac7:

    *(undefined8 *)(puVar9 + -8) = 0x14012facf;

    FUN_1401841e0(puVar5);

    return 0xffffffff;

  }

  bVar12 = false;

  uVar10 = (ulonglong)(int)(uVar2 + 1);

  if (0x3f < uVar2) {

    bVar12 = uVar10 < 0x80;

    if (bVar12) {

      uVar6 = uVar10 + 0xf;

      if (uVar6 <= uVar10) {

        uVar6 = 0xffffffffffffff0;

      }

      puVar7 = local_78 + -(uVar6 & 0xfffffffffffffff0);

      puVar8 = auStack_98 + -(uVar6 & 0xfffffffffffffff0);

    }

    else {

      puVar7 = (undefined1 *)FUN_1401841f0(uVar10);

      puVar8 = auStack_98;

    }

    puVar9 = puVar8;

    if (puVar7 == (undefined1 *)0x0) goto LAB_14012fac7;

    *(undefined8 *)(puVar8 + -8) = 0x14012fa8a;

    iVar3 = FUN_14012f860(puVar7,uVar10,puVar5,param_4);

    puVar11 = puVar7;

    if ((int)uVar2 < iVar3) {

      *(undefined8 *)(puVar8 + -8) = 0x14012fa9b;

      FUN_1401841e0(puVar5);

      *(undefined8 *)(puVar8 + -8) = 0x14012faa7;

      bVar1 = FUN_14012e850("Formatted output changed between two runs");

      return (uint)bVar1;

    }

  }

  *(undefined8 *)(puVar8 + -8) = 0x14012f9db;

  FUN_1401841e0(puVar5);

  *(undefined8 *)(puVar8 + -8) = 0x14012f9f4;

  lVar4 = FUN_140197820("WCHAR_T",&DAT_14039c6f0,puVar11,uVar10);

  if (lVar4 == 0) {

    uVar2 = 0xffffffff;

  }

  else {

    if (param_1 != (undefined2 *)0x0) {

      *(undefined8 *)(puVar8 + -8) = 0x14012fa17;

      FUN_14012fcd0(param_1,lVar4,param_2);

    }

    *(undefined8 *)(puVar8 + -8) = 0x14012fa1f;

    uVar2 = FUN_14012fd40(lVar4);

    *(undefined8 *)(puVar8 + -8) = 0x14012fa2a;

    FUN_1401841e0(lVar4);

  }

  if (puVar7 != (undefined1 *)0x0) {

    if (!bVar12) {

      *(undefined8 *)(puVar8 + -8) = 0x14012fac3;

      FUN_1401841e0(puVar7);

      return uVar2;

    }

    return uVar2;

  }

  return uVar2;

}




