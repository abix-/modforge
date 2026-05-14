// Address: 0x1400b6360
// Ghidra name: FUN_1400b6360
// ============ 0x1400b6360 FUN_1400b6360 (size=682) ============


void FUN_1400b6360(longlong param_1,undefined8 param_2)



{

  int *piVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_58;

  float fStack_54;

  

  if (*(longlong *)(param_1 + 0x40) == *(longlong *)(param_1 + 0x48)) {

    return;

  }

  piVar1 = *(int **)(*(longlong *)(param_1 + 0x40) + 0x30);

  if (piVar1 == (int *)0x0) {

    return;

  }

  fVar5 = (float)piVar1[0xb];

  fVar6 = (float)piVar1[0xc];

  local_58 = (float)param_2;

  local_58 = local_58 - fVar5;

  fStack_54 = (float)((ulonglong)param_2 >> 0x20);

  fStack_54 = fStack_54 - fVar6;

  fVar2 = fStack_54 * fStack_54 + local_58 * local_58;

  if (fVar2 < 0.0) {

    fVar2 = (float)FUN_1402cdfa0(fVar2);

  }

  else {

    fVar2 = SQRT(fVar2);

  }

  if (DAT_14039c9f0 <= fVar2) {

    fVar3 = (DAT_14039ca44 / fVar2) * fStack_54;

    fVar4 = (DAT_14039ca44 / fVar2) * local_58;

  }

  else {

    fVar2 = 0.0;

    fVar3 = fStack_54;

    fVar4 = local_58;

  }

  if (*(char *)(param_1 + 0x20) == '\0') {

    fVar2 = local_58 * DAT_14039ca60 -

            ((float)piVar1[0x10] - (fVar6 - fVar6) * (float)piVar1[0x12]) * DAT_14039ca5c;

    fVar3 = fStack_54 * DAT_14039ca60 -

            ((fVar5 - fVar5) * (float)piVar1[0x12] + (float)piVar1[0x11]) * DAT_14039ca5c;

    if (*piVar1 != 2) goto LAB_1400b653f;

    if ((*(ushort *)(piVar1 + 1) & 2) == 0) {

      piVar1[0x2b] = 0;

      *(ushort *)(piVar1 + 1) = *(ushort *)(piVar1 + 1) | 2;

    }

    fVar5 = (fVar5 - fVar5) * fVar3;

    fVar6 = (fVar6 - fVar6) * fVar2;

  }

  else {

    if (DAT_14030374c <= fVar2) {

      fVar2 = DAT_14030374c;

    }

    fVar2 = *(float *)(param_1 + 0x158) * DAT_140304c38 * fVar2;

    fVar3 = fVar2 * fVar3;

    fVar2 = fVar2 * fVar4;

    if (*piVar1 != 2) goto LAB_1400b653f;

    if ((*(ushort *)(piVar1 + 1) & 2) == 0) {

      piVar1[0x2b] = 0;

      *(ushort *)(piVar1 + 1) = *(ushort *)(piVar1 + 1) | 2;

    }

    fVar5 = (fVar5 - fVar5) * fVar3;

    fVar6 = (fVar6 - fVar6) * fVar2;

  }

  piVar1[0x14] = (int)(fVar3 + (float)piVar1[0x14]);

  piVar1[0x13] = (int)(fVar2 + (float)piVar1[0x13]);

  piVar1[0x15] = (int)((fVar5 - fVar6) + (float)piVar1[0x15]);

LAB_1400b653f:

  for (fVar5 = (float)FUN_1402cd4c0(piVar1[5],piVar1[6]); DAT_14039ca50 < fVar5;

      fVar5 = fVar5 + DAT_14039ca88) {

  }

  for (; fVar5 < DAT_14039ca84; fVar5 = fVar5 + DAT_14039ca54) {

  }

  fVar6 = (float)((uint)fVar5 ^ DAT_14039cac0) * DAT_14039ca5c;

  fVar5 = (float)piVar1[0x12] * DAT_14039ca58;

  if (*piVar1 == 2) {

    if ((*(ushort *)(piVar1 + 1) & 2) == 0) {

      piVar1[0x2b] = 0;

      *(ushort *)(piVar1 + 1) = *(ushort *)(piVar1 + 1) | 2;

    }

    piVar1[0x15] = (int)((fVar6 - fVar5) + (float)piVar1[0x15]);

  }

  *(undefined4 *)(param_1 + 0x1c0) = 0x3c;

  return;

}




