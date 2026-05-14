// Address: 0x1400831e0
// Ghidra name: FUN_1400831e0
// ============ 0x1400831e0 FUN_1400831e0 (size=339) ============


void FUN_1400831e0(longlong param_1)



{

  float fVar1;

  float fVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  int iVar5;

  longlong lVar6;

  undefined8 uVar7;

  undefined1 uVar8;

  

  if (*(char *)(param_1 + 0x11) == '\0') {

    if ((*(int *)(param_1 + 0x38) == -1) && (*(int *)(*(longlong *)(param_1 + 0x80) + 0x234) < 0)) {

      uVar8 = 1;

    }

    else {

      uVar8 = 0;

    }

    *(undefined1 *)(*(longlong *)(param_1 + 0x80) + 0x1a) = uVar8;

    FUN_1400be110(*(undefined8 *)(param_1 + 0x80),*(undefined8 *)(param_1 + 0x28),DAT_140303750,

                  *(int *)(param_1 + 0x70) == 0xb,*(undefined4 *)(param_1 + 0x88));

    if ((*(int *)(*(longlong *)(param_1 + 0x80) + 0x1f8) != -1) &&

       (DAT_14030335c < *(float *)(DAT_1403fb0d8 + 0x114))) {

      lVar6 = FUN_1400c7520();

      if (*(longlong *)(lVar6 + 0x10) != 0) {

        uVar4 = *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x1f8);

        lVar6 = FUN_1400c7520(uVar4);

        iVar5 = *(int *)(lVar6 + 0x44);

        fVar1 = *(float *)(param_1 + 0x2c);

        fVar2 = *(float *)(param_1 + 0x34);

        uVar3 = *(undefined4 *)(param_1 + 0x28);

        uVar7 = FUN_1400c7720(uVar4);

        FUN_140086570(DAT_1403ede48,uVar3,fVar1 - fVar2,2,DAT_14039ca34,

                      *(undefined4 *)(&DAT_1403eaee0 + (longlong)iVar5 * 4),uVar7);

      }

    }

  }

  return;

}




