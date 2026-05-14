// Address: 0x1400a8ba0
// Ghidra name: FUN_1400a8ba0
// ============ 0x1400a8ba0 FUN_1400a8ba0 (size=601) ============


undefined8 FUN_1400a8ba0(longlong param_1,float param_2,float param_3)



{

  float fVar1;

  char cVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  int iVar6;

  int iVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  

  fVar11 = DAT_14039ca34;

  fVar1 = DAT_140303fb4;

  uVar5 = 1;

  if (param_2 != 0.0) {

    fVar10 = *(float *)(param_1 + 0x28);

    fVar12 = fVar10 + param_2;

    fVar9 = *(float *)(param_1 + 0x30) * DAT_14039ca34;

    if (param_2 <= 0.0) {

      fVar10 = fVar10 - fVar9;

    }

    else {

      fVar10 = fVar9 + fVar10;

    }

    fVar10 = fVar10 * DAT_140303fb4;

    if (param_2 <= 0.0) {

      fVar9 = fVar12 - fVar9;

    }

    else {

      fVar9 = fVar9 + fVar12;

    }

    fVar8 = *(float *)(param_1 + 0x34) * DAT_14039ca34;

    fVar9 = fVar9 * DAT_140303fb4;

    iVar7 = (int)((*(float *)(param_1 + 0x2c) - fVar8) * DAT_140303fb4);

    iVar6 = (int)((fVar8 + *(float *)(param_1 + 0x2c)) * DAT_140303fb4);

    cVar2 = FUN_1401015f0(DAT_1403fb0d8,(int)fVar10,iVar7,(int)fVar9,iVar7,

                          *(undefined4 *)(param_1 + 0x48));

    if ((cVar2 == '\0') &&

       (cVar2 = FUN_1401015f0(DAT_1403fb0d8,(int)fVar10,iVar6,(int)fVar9,iVar6,

                              *(undefined4 *)(param_1 + 0x48)), cVar2 == '\0')) {

      *(float *)(param_1 + 0x28) = fVar12;

      uVar3 = 0xffffffff;

      if (0.0 < param_2) {

        uVar3 = 1;

      }

      uVar5 = 0;

      *(undefined4 *)(param_1 + 0x38) = uVar3;

    }

  }

  if (param_3 != 0.0) {

    fVar10 = *(float *)(param_1 + 0x2c);

    fVar12 = fVar10 + param_3;

    fVar9 = *(float *)(param_1 + 0x34) * fVar11;

    if (param_3 <= 0.0) {

      fVar10 = fVar10 - fVar9;

    }

    else {

      fVar10 = fVar10 + fVar9;

    }

    fVar11 = *(float *)(param_1 + 0x30) * fVar11;

    iVar6 = (int)((*(float *)(param_1 + 0x28) - fVar11) * fVar1);

    if (param_3 <= 0.0) {

      fVar9 = fVar12 - fVar9;

    }

    else {

      fVar9 = fVar9 + fVar12;

    }

    iVar7 = (int)((fVar11 + *(float *)(param_1 + 0x28)) * fVar1);

    cVar2 = FUN_1401015f0(DAT_1403fb0d8,iVar6,(int)(fVar10 * fVar1),iVar6,(int)(fVar9 * fVar1),

                          *(undefined4 *)(param_1 + 0x48));

    if ((cVar2 == '\0') &&

       (uVar4 = FUN_1401015f0(DAT_1403fb0d8,iVar7,(int)(fVar10 * fVar1),iVar7,(int)(fVar9 * fVar1),

                              *(undefined4 *)(param_1 + 0x48)), (char)uVar4 == '\0')) {

      *(float *)(param_1 + 0x2c) = fVar12;

      uVar5 = uVar4;

    }

  }

  return uVar5;

}




