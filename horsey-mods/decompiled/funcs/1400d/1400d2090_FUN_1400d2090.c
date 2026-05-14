// Address: 0x1400d2090
// Ghidra name: FUN_1400d2090
// ============ 0x1400d2090 FUN_1400d2090 (size=821) ============


void FUN_1400d2090(longlong param_1)



{

  float fVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  undefined8 *puVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  

  iVar4 = *(int *)(param_1 + 0x1f8);

  if ((int)(uint)(*(longlong *)(param_1 + 0x210) != *(longlong *)(param_1 + 0x218)) < iVar4) {

    iVar4 = iVar4 + -1;

    *(int *)(param_1 + 0x1f8) = iVar4;

  }

  iVar3 = *(int *)(param_1 + 0x1fc);

  if (0 < iVar3) {

    iVar3 = iVar3 + -1;

    *(int *)(param_1 + 0x1fc) = iVar3;

  }

  fVar1 = DAT_140303390;

  if (iVar4 < 1) {

    if (iVar4 == 0) {

      if (1 < (ulonglong)((*(longlong *)(param_1 + 0x68) - *(longlong *)(param_1 + 0x60)) / 0x68)) {

        *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0xc5) = 0;

      }

      *(undefined1 *)(param_1 + 0x204) = 0;

    }

    return;

  }

  if (iVar3 != 0) {

    return;

  }

  fVar7 = *(float *)(param_1 + 0x1d4);

  fVar8 = *(float *)(param_1 + 0x1d0);

  if (*(longlong *)(param_1 + 0x210) != *(longlong *)(param_1 + 0x218)) {

    puVar5 = (undefined8 *)(*(longlong *)(param_1 + 0x1e8) + -0x20);

    if (0xf < *(ulonglong *)(*(longlong *)(param_1 + 0x1e8) + -8)) {

      puVar5 = (undefined8 *)*puVar5;

    }

    iVar4 = FUN_140086450(DAT_1403ede50,puVar5);

    if (fVar8 - DAT_140303fc0 < (float)iVar4) {

      fVar7 = fVar7 + fVar1;

    }

  }

  FUN_140072fe0(*(undefined8 *)(param_1 + 0x1c8));

  FUN_140071000();

  uVar2 = DAT_140304c68;

  fVar6 = DAT_14030eb98;

  if (*(int *)(param_1 + 0x200) != 1) {

    if (*(int *)(param_1 + 0x200) != -1) goto LAB_1400d2254;

    fVar6 = fVar8 + DAT_140303fbc;

  }

  FUN_140071810(fVar6);

LAB_1400d2254:

  FUN_140071000(uVar2);

  if (*(longlong *)(param_1 + 0x210) != *(longlong *)(param_1 + 0x218)) {

    fVar8 = fVar8 - DAT_140303fc0;

    fVar7 = fVar7 - DAT_14039ca44;

    DAT_1403f39f0 = DAT_1403f39f0 + 1;

    if (*(int *)(param_1 + 0x1f8) == 299) {

      DAT_1403f39f0 = 0;

    }

    else if (0x1d < DAT_1403f39f0 % 0x3c) {

      fVar7 = fVar7 + DAT_14039ca34;

    }

    FUN_140071810(fVar8 + fVar1,fVar7 - DAT_14030374c,fVar8 + DAT_1403033a4,fVar7 - DAT_14030374c,

                  fVar8 + DAT_140303750,fVar7 + DAT_14030374c,DAT_1403da83c);

  }

  FUN_1400874e0(DAT_1403ede50,param_1 + 0x1c8);

  FUN_1400730f0();

  return;

}




