// Address: 0x1400924b0
// Ghidra name: FUN_1400924b0
// ============ 0x1400924b0 FUN_1400924b0 (size=356) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400924b0(longlong param_1)



{

  float fVar1;

  longlong lVar2;

  float fVar3;

  uint uVar4;

  undefined8 uVar5;

  int *piVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  int iVar9;

  ulonglong uVar10;

  uint uVar11;

  float fVar12;

  

  uVar4 = _DAT_14039cab0;

  fVar3 = DAT_14030c274;

  iVar9 = *(int *)(param_1 + 0x298);

  uVar7 = 0;

  uVar10 = 0xffffffff;

  if (0 < iVar9) {

    piVar6 = (int *)(*(longlong *)(param_1 + 0x280) + 0x14);

    uVar8 = uVar7;

    fVar12 = DAT_140303390;

    do {

      fVar1 = (float)piVar6[4];

      if ((((fVar12 < fVar1) && (*piVar6 < 0x78)) && ((char)piVar6[5] == '\0')) &&

         (lVar2 = *(longlong *)

                   (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x130) + uVar7) + 0x40) +

                   0x30),

         uVar11 = FUN_1402cd4c0(*(undefined4 *)(lVar2 + 0x14),*(undefined4 *)(lVar2 + 0x18)),

         (float)(uVar11 & uVar4) < fVar3)) {

        uVar10 = uVar8;

        fVar12 = fVar1;

      }

      uVar11 = (int)uVar8 + 1;

      uVar8 = (ulonglong)uVar11;

      piVar6 = piVar6 + 0x1c;

      uVar7 = uVar7 + 8;

    } while ((int)uVar11 < iVar9);

    iVar9 = (int)uVar10;

    if (iVar9 != -1) {

      if (DAT_1403d9528 != '\0') {

        uVar5 = FUN_1400c78c0(*(undefined4 *)

                               (*(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)iVar9 * 8)

                               + 0x1f8));

        FUN_1400c4320("Extrapolated Winner: %s",uVar5);

      }

      if ((*(int *)(param_1 + 0x2a0) == 5) || (*(int *)(param_1 + 0x2a0) == 6)) {

        uVar5 = 1;

      }

      else {

        uVar5 = 0;

      }

      FUN_140105980(DAT_1403fb0d8,

                    *(undefined8 *)(*(longlong *)(param_1 + 0x130) + (longlong)iVar9 * 8),uVar5);

    }

  }

  return;

}




