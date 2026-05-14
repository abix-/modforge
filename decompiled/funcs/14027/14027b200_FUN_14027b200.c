// Address: 0x14027b200
// Ghidra name: FUN_14027b200
// ============ 0x14027b200 FUN_14027b200 (size=636) ============


void FUN_14027b200(longlong param_1)



{

  char cVar1;

  undefined1 uVar2;

  int iVar3;

  longlong *plVar4;

  int *piVar5;

  longlong lVar6;

  undefined8 uVar7;

  longlong lVar8;

  int iVar9;

  undefined4 uVar10;

  longlong lVar11;

  int iVar12;

  int iVar13;

  int iVar14;

  longlong lVar15;

  undefined1 local_408 [1024];

  

  plVar4 = (longlong *)FUN_1401841a0(1,0xb0);

  if (plVar4 == (longlong *)0x0) {

    return;

  }

  *plVar4 = param_1;

  *(longlong **)(param_1 + 0x70) = plVar4;

  iVar3 = FUN_140193520(*(undefined8 *)(param_1 + 0x80),local_408,0x400);

  if (iVar3 < 1) {

    FUN_14012e080(7,"Xbox report descriptor not available");

    goto LAB_14027b3e6;

  }

  FUN_1402079c0("Xbox One report descriptor: size = %d",local_408,iVar3);

  piVar5 = (int *)FUN_1402c5930(local_408,iVar3);

  plVar4[10] = (longlong)piVar5;

  if (piVar5 == (int *)0x0) {

    uVar7 = FUN_14012e730();

    FUN_14012e2e0(7,"Couldn\'t parse Xbox report descriptor: %s",uVar7);

    goto LAB_14027b3e6;

  }

  iVar12 = 0;

  lVar8 = *(longlong *)(piVar5 + 2);

  iVar14 = 0;

  iVar3 = *piVar5;

  lVar15 = (longlong)iVar3;

  if (0 < iVar3) {

    lVar6 = 0;

    iVar9 = 0x90001;

    lVar11 = lVar8;

    do {

      if (*(int *)(lVar11 + 4) == 0x90001) {

        lVar6 = (longlong)iVar14;

        if (lVar15 <= lVar6) goto LAB_14027b311;

        iVar13 = *(int *)(lVar11 + 8);

        piVar5 = (int *)(lVar6 * 0x10 + 8 + lVar8);

        goto LAB_14027b2f4;

      }

      iVar14 = iVar14 + 1;

      lVar6 = lVar6 + 1;

      lVar11 = lVar11 + 0x10;

    } while (lVar6 < lVar15);

  }

  goto LAB_14027b34c;

  while( true ) {

    iVar12 = iVar12 + 1;

    iVar9 = iVar9 + 1;

    iVar13 = iVar13 + 1;

    lVar6 = lVar6 + 1;

    piVar5 = piVar5 + 4;

    if (lVar15 <= lVar6) break;

LAB_14027b2f4:

    if ((piVar5[-1] != iVar9) || (*piVar5 != iVar13)) break;

  }

LAB_14027b311:

  *(int *)(lVar11 + 0xc) = iVar12;

  FUN_1402f8e20((longlong)(iVar14 + 1) * 0x10 + lVar8,(longlong)(iVar14 + iVar12) * 0x10 + lVar8,

                (longlong)(iVar3 - (iVar14 + iVar12)) << 4);

  *(int *)plVar4[10] = *(int *)plVar4[10] + (1 - iVar12);

LAB_14027b34c:

  cVar1 = FUN_1402c58c0(plVar4[10],1,0x30);

  if (((cVar1 == '\0') || (cVar1 = FUN_1402c58c0(plVar4[10],1,0x31), cVar1 == '\0')) ||

     ((iVar12 != 0xc && (iVar12 != 0xf)))) {

    FUN_14012e2e0(7,"Xbox report descriptor missing expected usages, ignoring");

    FUN_1402c5900(plVar4[10]);

    plVar4[10] = 0;

  }

LAB_14027b3e6:

  *(undefined2 *)(plVar4 + 1) = *(undefined2 *)(param_1 + 0x20);

  *(undefined2 *)((longlong)plVar4 + 10) = *(undefined2 *)(param_1 + 0x22);

  lVar8 = FUN_140149350();

  plVar4[2] = lVar8;

  *(undefined1 *)(plVar4 + 3) = 0;

  uVar2 = FUN_14027b840((short)plVar4[1],*(undefined2 *)((longlong)plVar4 + 10));

  *(undefined1 *)((longlong)plVar4 + 0x29) = uVar2;

  uVar2 = thunk_FUN_1401597c0();

  *(undefined1 *)((longlong)plVar4 + 0x2a) = uVar2;

  uVar2 = FUN_14027b880((short)plVar4[1],*(undefined2 *)((longlong)plVar4 + 10));

  *(undefined1 *)((longlong)plVar4 + 0x2c) = uVar2;

  uVar2 = thunk_FUN_140159800();

  *(undefined1 *)((longlong)plVar4 + 0x2d) = uVar2;

  cVar1 = FUN_14027b890(*(undefined2 *)(param_1 + 0x20),*(undefined2 *)(param_1 + 0x22));

  uVar10 = 2;

  if (cVar1 != '\0') {

    uVar10 = 4;

  }

  *(undefined4 *)((longlong)plVar4 + 0xc) = uVar10;

  *(undefined4 *)(param_1 + 0x5c) = 3;

  FUN_140208110(param_1,0);

  return;

}




