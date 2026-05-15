// Address: 0x140156960
// Ghidra name: FUN_140156960
// ============ 0x140156960 FUN_140156960 (size=936) ============


void FUN_140156960(longlong param_1)



{

  int *piVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  int local_res8 [2];

  int local_res10 [2];

  

  piVar1 = *(int **)(param_1 + 0x138);

  fVar11 = (float)piVar1[0x16];

  fVar10 = (float)piVar1[0x17];

  if (piVar1 == (int *)(param_1 + 0x140)) {

    FUN_14014e850(param_1,local_res8,local_res10);

  }

  else {

    local_res8[0] = *(int *)(*(longlong *)(param_1 + 0x1f0) + 4);

    local_res10[0] = *(int *)(*(longlong *)(param_1 + 0x1f0) + 8);

  }

  iVar4 = piVar1[0x15];

  piVar1[0x1a] = (int)fVar11;

  piVar1[0x1b] = (int)fVar10;

  piVar1[0x18] = 0;

  fVar9 = DAT_14039ca44;

  piVar1[0x19] = 0;

  if (iVar4 == 0) {

    piVar1[0x1c] = 0;

    piVar1[0x1d] = 0;

    iVar4 = 0;

    fVar5 = 0.0;

    piVar1[0x1e] = (int)(float)local_res8[0];

    fVar11 = (float)piVar1[0x13];

    piVar1[0x20] = 0x3f800000;

    piVar1[0x1f] = (int)(float)local_res10[0];

    fVar10 = (float)piVar1[0x14];

    goto LAB_140156c5b;

  }

  fVar9 = 0.0;

  fVar8 = (float)local_res8[0];

  fVar7 = (float)local_res10[0];

  fVar6 = fVar8 / fVar7;

  fVar5 = fVar11 / fVar10;

  if ((fVar11 <= 0.0) || (fVar10 <= 0.0)) {

LAB_140156bdf:

    piVar1[0x1e] = (int)fVar8;

    piVar1[0x1f] = (int)fVar7;

    piVar1[0x1d] = 0;

    fVar5 = 0.0;

    piVar1[0x1c] = 0;

  }

  else if (iVar4 == 4) {

    fVar3 = fVar7;

    fVar2 = fVar10;

    if (fVar6 < fVar5) {

      fVar3 = fVar8;

      fVar2 = fVar11;

    }

    fVar6 = (float)((int)fVar3 / (int)fVar2);

    fVar5 = DAT_14039ca44;

    if (DAT_14039ca44 <= fVar6) {

      fVar5 = fVar6;

    }

    fVar5 = (float)thunk_FUN_1402d0350(fVar5 * fVar11,(int)fVar3 % (int)fVar2);

    piVar1[0x1e] = (int)fVar5;

    piVar1[0x1c] = (int)((fVar8 - fVar5) * DAT_14039ca34);

    fVar5 = (float)thunk_FUN_1402d0350();

LAB_140156b27:

    piVar1[0x1f] = (int)fVar5;

    fVar5 = (fVar7 - fVar5) * DAT_14039ca34;

    piVar1[0x1d] = (int)fVar5;

  }

  else {

    if ((iVar4 == 1) || (fVar3 = (float)FUN_140190250(fVar5 - fVar6), fVar3 < DAT_14039c9f8))

    goto LAB_140156bdf;

    if (fVar5 <= fVar6) {

      if (piVar1[0x15] != 2) goto LAB_140156b82;

    }

    else if (piVar1[0x15] == 2) {

LAB_140156b82:

      piVar1[0x1e] = (int)fVar8;

      piVar1[0x1c] = 0;

      fVar5 = (float)thunk_FUN_1402d0350();

      goto LAB_140156b27;

    }

    piVar1[0x1f] = (int)fVar7;

    piVar1[0x1d] = 0;

    fVar6 = (float)thunk_FUN_1402d0350();

    fVar5 = (float)piVar1[0x1d];

    piVar1[0x1e] = (int)fVar6;

    piVar1[0x1c] = (int)((fVar8 - fVar6) * DAT_14039ca34);

  }

  if (fVar11 <= 0.0) {

    fVar11 = 0.0;

  }

  else {

    fVar11 = (float)piVar1[0x1e] / fVar11;

  }

  piVar1[0x20] = (int)fVar11;

  if (0.0 < fVar10) {

    fVar9 = (float)piVar1[0x1f] / fVar10;

  }

  iVar4 = piVar1[0x1c];

  fVar10 = fVar9 * (float)piVar1[0x14];

  fVar11 = fVar11 * (float)piVar1[0x13];

LAB_140156c5b:

  piVar1[0x21] = (int)fVar9;

  piVar1[0x24] = (int)fVar11;

  piVar1[0x25] = (int)fVar10;

  piVar1[0x23] = (int)fVar5;

  piVar1[0x22] = iVar4;

  if (piVar1 == (int *)(param_1 + 0x140)) {

    FUN_140156d10(param_1,0x84,piVar1,piVar1);

  }

  *piVar1 = (int)(float)piVar1[0x1e];

  piVar1[1] = (int)(float)piVar1[0x1f];

  FUN_140156e80(param_1,piVar1);

  FUN_140156de0(param_1,piVar1);

  FUN_14014af50(param_1);

  FUN_14014adb0(param_1);

  return;

}




