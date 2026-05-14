// Address: 0x140159d70
// Ghidra name: FUN_140159d70
// ============ 0x140159d70 FUN_140159d70 (size=1045) ============


int * FUN_140159d70(int param_1)



{

  int iVar1;

  char cVar2;

  undefined1 uVar3;

  int *piVar4;

  undefined8 uVar5;

  longlong lVar6;

  int *piVar7;

  undefined8 *puVar8;

  ushort uVar9;

  int iVar10;

  undefined2 uVar11;

  int iVar12;

  undefined1 local_res10 [8];

  undefined4 local_res18 [2];

  undefined **local_res20;

  int local_28;

  int iStack_24;

  int iStack_20;

  int iStack_1c;

  

  local_res10[0] = 0;

  FUN_140159d30();

  cVar2 = FUN_140157a10(param_1,&local_res20,local_res18);

  piVar4 = DAT_1403fc070;

  if (cVar2 == '\0') {

LAB_14015a177:

    FUN_14015bb10();

    return (int *)0x0;

  }

  for (; piVar4 != (int *)0x0; piVar4 = *(int **)(piVar4 + 0x56)) {

    if (param_1 == *piVar4) {

      piVar4[0x55] = piVar4[0x55] + 1;

      FUN_14015bb10();

      return piVar4;

    }

  }

  piVar4 = (int *)FUN_1401841a0(1,0x160);

  if (piVar4 == (int *)0x0) goto LAB_14015a177;

  FUN_1401aa9d0(piVar4,4,1);

  *(undefined ***)(piVar4 + 0x50) = local_res20;

  *piVar4 = param_1;

  *(undefined1 *)(piVar4 + 0x38) = 1;

  uVar5 = FUN_140149350();

  *(undefined8 *)(piVar4 + 0x36) = uVar5;

  piVar4[0x3b] = -1;

  *(bool *)((longlong)piVar4 + 0x41) = local_res20 == &PTR_FUN_1403e4f30;

  cVar2 = (*(code *)local_res20[0xb])(piVar4,local_res18[0]);

  if (cVar2 == '\0') {

    FUN_1401aa9d0(piVar4,4,0);

    FUN_1401841e0(piVar4);

LAB_140159e57:

    FUN_14015bb10();

    return (int *)0x0;

  }

  lVar6 = (*(code *)local_res20[4])(local_res18[0]);

  if (lVar6 != 0) {

    uVar5 = FUN_14012f0d0(lVar6);

    *(undefined8 *)(piVar4 + 2) = uVar5;

  }

  lVar6 = (*(code *)local_res20[5])(local_res18[0]);

  if (lVar6 != 0) {

    uVar5 = FUN_14012f0d0(lVar6);

    *(undefined8 *)(piVar4 + 4) = uVar5;

  }

  piVar7 = (int *)(*(code *)local_res20[9])(&local_28,local_res18[0]);

  iVar12 = piVar7[1];

  iVar10 = piVar7[2];

  iVar1 = piVar7[3];

  piVar4[8] = *piVar7;

  piVar4[9] = iVar12;

  piVar4[10] = iVar10;

  piVar4[0xb] = iVar1;

  if (0 < piVar4[0x11]) {

    uVar5 = FUN_1401841a0((longlong)piVar4[0x11],10);

    *(undefined8 *)(piVar4 + 0x12) = uVar5;

  }

  if (0 < piVar4[0x14]) {

    uVar5 = FUN_1401841a0((longlong)piVar4[0x14],8);

    *(undefined8 *)(piVar4 + 0x16) = uVar5;

  }

  if (0 < piVar4[0x18]) {

    uVar5 = FUN_1401841a0((longlong)piVar4[0x18],1);

    *(undefined8 *)(piVar4 + 0x1a) = uVar5;

  }

  if (0 < piVar4[0x1c]) {

    uVar5 = FUN_1401841a0((longlong)piVar4[0x1c],1);

    *(undefined8 *)(piVar4 + 0x1e) = uVar5;

  }

  if (((((0 < piVar4[0x11]) && (*(longlong *)(piVar4 + 0x12) == 0)) ||

       ((0 < piVar4[0x14] && (*(longlong *)(piVar4 + 0x16) == 0)))) ||

      ((0 < piVar4[0x18] && (*(longlong *)(piVar4 + 0x1a) == 0)))) ||

     ((0 < piVar4[0x1c] && (*(longlong *)(piVar4 + 0x1e) == 0)))) {

    FUN_1401575b0(piVar4);

    goto LAB_140159e57;

  }

  cVar2 = FUN_140159840(piVar4);

  iVar12 = 0;

  if ((cVar2 != '\0') && (0 < piVar4[0x11])) {

    lVar6 = 0;

    iVar10 = iVar12;

    do {

      lVar6 = lVar6 + 10;

      iVar10 = iVar10 + 1;

      *(undefined1 *)(*(longlong *)(piVar4 + 0x12) + -4 + lVar6) = 1;

    } while (iVar10 < piVar4[0x11]);

  }

  local_28 = piVar4[8];

  iStack_24 = piVar4[9];

  iStack_20 = piVar4[10];

  iStack_1c = piVar4[0xb];

  cVar2 = FUN_1401594b0(&local_28);

  if (cVar2 == '\0') {

    local_28 = piVar4[8];

    iStack_24 = piVar4[9];

    iStack_20 = piVar4[10];

    iStack_1c = piVar4[0xb];

    cVar2 = FUN_140159790(&local_28);

    if (cVar2 == '\0') {

      local_28 = piVar4[8];

      iStack_24 = piVar4[9];

      iStack_20 = piVar4[10];

      iStack_1c = piVar4[0xb];

      cVar2 = FUN_140159600(&local_28);

      if (cVar2 == '\0') {

        local_28 = piVar4[8];

        iStack_24 = piVar4[9];

        iStack_20 = piVar4[10];

        iStack_1c = piVar4[0xb];

        cVar2 = FUN_140159770(&local_28);

        if (cVar2 == '\0') goto LAB_14015a0fb;

      }

    }

  }

  if (5 < piVar4[0x11]) {

    local_28 = piVar4[8];

    iStack_24 = piVar4[9];

    iStack_20 = piVar4[10];

    iStack_1c = piVar4[0xb];

    cVar2 = FUN_140159790(&local_28);

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 2) = 0;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 4) = 0;

    **(undefined2 **)(piVar4 + 0x12) = 0;

    *(undefined1 *)(*(longlong *)(piVar4 + 0x12) + 6) = 1;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 0xc) = 0;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 0xe) = 0;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 10) = 0;

    *(undefined1 *)(*(longlong *)(piVar4 + 0x12) + 0x10) = 1;

    uVar9 = -(ushort)(cVar2 != '\0') & 0x8000;

    *(ushort *)(*(longlong *)(piVar4 + 0x12) + 0x16) = uVar9;

    *(ushort *)(*(longlong *)(piVar4 + 0x12) + 0x18) = uVar9;

    *(ushort *)(*(longlong *)(piVar4 + 0x12) + 0x14) = uVar9;

    *(undefined1 *)(*(longlong *)(piVar4 + 0x12) + 0x1a) = 1;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 0x20) = 0;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 0x22) = 0;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 0x1e) = 0;

    if (cVar2 == '\0') {

      iVar12 = 0x8000;

    }

    *(undefined1 *)(*(longlong *)(piVar4 + 0x12) + 0x24) = 1;

    uVar11 = (undefined2)iVar12;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 0x2a) = uVar11;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 0x2c) = uVar11;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 0x28) = uVar11;

    *(undefined1 *)(*(longlong *)(piVar4 + 0x12) + 0x2e) = 1;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 0x34) = 0x8000;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 0x36) = 0x8000;

    *(undefined2 *)(*(longlong *)(piVar4 + 0x12) + 0x32) = 0x8000;

    *(undefined1 *)(*(longlong *)(piVar4 + 0x12) + 0x38) = 1;

  }

LAB_14015a0fb:

  puVar8 = (undefined8 *)FUN_140158f10(param_1);

  if (puVar8 != (undefined8 *)0x0) {

    *(undefined8 *)(piVar4 + 0xe) = *puVar8;

    uVar3 = FUN_14015c220(puVar8);

    *(undefined1 *)(piVar4 + 0x10) = uVar3;

  }

  cVar2 = FUN_14015c0a0(piVar4,local_res10);

  if (cVar2 != '\0') {

    FUN_140157200(piVar4,local_res10[0]);

  }

  piVar4[0x55] = piVar4[0x55] + 1;

  *(int **)(piVar4 + 0x56) = DAT_1403fc070;

  DAT_1403fc070 = piVar4;

  (*(code *)local_res20[0x11])(piVar4);

  FUN_14015bb10();

  return piVar4;

}




