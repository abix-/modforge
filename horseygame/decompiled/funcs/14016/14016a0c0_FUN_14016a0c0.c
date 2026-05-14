// Address: 0x14016a0c0
// Ghidra name: FUN_14016a0c0
// ============ 0x14016a0c0 FUN_14016a0c0 (size=480) ============


undefined4 FUN_14016a0c0(undefined8 *param_1,char param_2)



{

  int *piVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined8 *puVar6;

  longlong lVar7;

  undefined8 uVar8;

  int iVar9;

  undefined1 *puVar10;

  longlong lVar11;

  float fVar12;

  undefined1 local_28 [32];

  

  puVar6 = (undefined8 *)FUN_1401841f0(0x88);

  if (puVar6 != (undefined8 *)0x0) {

    lVar7 = FUN_140184230(*(undefined8 *)(DAT_1403fc410 + 0x330),

                          (longlong)*(int *)(DAT_1403fc410 + 0x328) * 8 + 8);

    lVar11 = DAT_1403fc410;

    if (lVar7 != 0) {

      piVar1 = (int *)(DAT_1403fc410 + 0x328);

      *(longlong *)(DAT_1403fc410 + 0x330) = lVar7;

      *(undefined8 **)(lVar7 + (longlong)*piVar1 * 8) = puVar6;

      *(int *)(lVar11 + 0x328) = *(int *)(lVar11 + 0x328) + 1;

      uVar4 = FUN_1401aa810();

      uVar8 = param_1[1];

      *puVar6 = *param_1;

      puVar6[1] = uVar8;

      uVar8 = param_1[3];

      puVar6[2] = param_1[2];

      puVar6[3] = uVar8;

      uVar8 = param_1[5];

      puVar6[4] = param_1[4];

      puVar6[5] = uVar8;

      uVar8 = param_1[7];

      puVar6[6] = param_1[6];

      puVar6[7] = uVar8;

      uVar8 = param_1[9];

      puVar6[8] = param_1[8];

      puVar6[9] = uVar8;

      uVar8 = param_1[0xb];

      puVar6[10] = param_1[10];

      puVar6[0xb] = uVar8;

      uVar8 = param_1[0xd];

      puVar6[0xc] = param_1[0xc];

      puVar6[0xd] = uVar8;

      uVar5 = *(undefined4 *)((longlong)param_1 + 0x74);

      uVar2 = *(undefined4 *)(param_1 + 0xf);

      uVar3 = *(undefined4 *)((longlong)param_1 + 0x7c);

      *(undefined4 *)(puVar6 + 0xe) = *(undefined4 *)(param_1 + 0xe);

      *(undefined4 *)((longlong)puVar6 + 0x74) = uVar5;

      *(undefined4 *)(puVar6 + 0xf) = uVar2;

      *(undefined4 *)((longlong)puVar6 + 0x7c) = uVar3;

      puVar6[0x10] = param_1[0x10];

      *(undefined4 *)puVar6 = uVar4;

      puVar6[0xe] = DAT_1403fc410;

      puVar10 = (undefined1 *)param_1[1];

      if (puVar10 == (undefined1 *)0x0) {

        thunk_FUN_14012eed0(uVar4,local_28,10);

        puVar10 = local_28;

      }

      uVar8 = FUN_14012f0d0(puVar10);

      puVar6[1] = uVar8;

      if (*(float *)(puVar6 + 0xb) == 0.0) {

        *(undefined4 *)(puVar6 + 0xb) = 0x3f800000;

      }

      *(undefined4 *)(puVar6 + 4) = uVar4;

      puVar6[9] = puVar6 + 4;

      FUN_14016bc10();

      iVar9 = 0;

      if (0 < *(int *)((longlong)puVar6 + 0x14)) {

        lVar11 = 0;

        do {

          iVar9 = iVar9 + 1;

          *(undefined4 *)(lVar11 + puVar6[3]) = uVar4;

          lVar11 = lVar11 + 0x28;

        } while (iVar9 < *(int *)((longlong)puVar6 + 0x14));

      }

      fVar12 = *(float *)(param_1 + 0xc);

      if (*(float *)(param_1 + 0xc) <= DAT_14039ca44) {

        fVar12 = DAT_14039ca44;

      }

      *(float *)(puVar6 + 0xc) = fVar12;

      fVar12 = *(float *)((longlong)param_1 + 0x5c);

      if (*(float *)((longlong)param_1 + 0x5c) <= DAT_14039ca44) {

        fVar12 = DAT_14039ca44;

      }

      *(float *)((longlong)puVar6 + 0x5c) = fVar12;

      uVar5 = FUN_14016d690(uVar4);

      FUN_140175280(uVar5,"SDL.display.HDR_enabled",DAT_14039ca44 < *(float *)(puVar6 + 0xc));

      FUN_1401730d0();

      if (param_2 != '\0') {

        FUN_14021a690(puVar6,0x152,0,0);

      }

      return uVar4;

    }

    FUN_1401841e0(puVar6);

  }

  return 0;

}




