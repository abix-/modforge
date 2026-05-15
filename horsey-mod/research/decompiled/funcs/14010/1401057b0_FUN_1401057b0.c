// Address: 0x1401057b0
// Ghidra name: FUN_1401057b0
// ============ 0x1401057b0 FUN_1401057b0 (size=455) ============


void FUN_1401057b0(longlong param_1,undefined8 *param_2)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  undefined4 *puVar9;

  undefined8 *puVar10;

  undefined4 *puVar11;

  undefined4 *puVar12;

  undefined8 *puVar13;

  undefined1 local_58 [24];

  undefined1 local_40 [24];

  

  if (0xf < (ulonglong)param_2[3]) {

    param_2 = (undefined8 *)*param_2;

  }

  puVar9 = (undefined4 *)

           FUN_140086910(DAT_1403ede58,local_58,DAT_140313a20,DAT_14039ca44,DAT_1403dc2a4,param_2);

  puVar11 = *(undefined4 **)(param_1 + 0x3d0);

  if (puVar11 == *(undefined4 **)(param_1 + 0x3d8)) {

    FUN_1401107d0((longlong *)(param_1 + 0x3c8),puVar11);

  }

  else {

    uVar6 = puVar9[1];

    uVar7 = puVar9[2];

    uVar8 = puVar9[3];

    *puVar11 = *puVar9;

    puVar11[1] = uVar6;

    puVar11[2] = uVar7;

    puVar11[3] = uVar8;

    puVar11[4] = puVar9[4];

    puVar11[5] = puVar9[5];

    uVar3 = *(undefined8 *)(puVar9 + 10);

    *(undefined8 *)(puVar9 + 10) = 0;

    uVar4 = *(undefined8 *)(puVar9 + 8);

    *(undefined8 *)(puVar9 + 8) = 0;

    uVar5 = *(undefined8 *)(puVar9 + 6);

    *(undefined8 *)(puVar9 + 6) = 0;

    *(undefined8 *)(puVar11 + 6) = uVar5;

    *(undefined8 *)(puVar11 + 8) = uVar4;

    *(undefined8 *)(puVar11 + 10) = uVar3;

    *(longlong *)(param_1 + 0x3d0) = *(longlong *)(param_1 + 0x3d0) + 0x30;

  }

  FUN_140087ec0(local_40);

  puVar11 = *(undefined4 **)(param_1 + 0x3c8);

  puVar9 = *(undefined4 **)(param_1 + 0x3d0);

  if ((10 < (ulonglong)(((longlong)puVar9 - (longlong)puVar11) / 0x30)) &&

     (puVar12 = puVar11 + 0x3c, puVar11 != puVar12)) {

    if (puVar12 != puVar9) {

      puVar10 = (undefined8 *)(puVar11 + 0x46);

      puVar13 = (undefined8 *)(puVar11 + 10);

      do {

        uVar6 = puVar12[1];

        uVar7 = puVar12[2];

        uVar8 = puVar12[3];

        *puVar11 = *puVar12;

        puVar11[1] = uVar6;

        puVar11[2] = uVar7;

        puVar11[3] = uVar8;

        *(undefined4 *)(puVar13 + -3) = *(undefined4 *)(puVar10 + -3);

        *(undefined4 *)((longlong)puVar13 + -0x14) = *(undefined4 *)((longlong)puVar10 + -0x14);

        puVar1 = puVar13 + -2;

        puVar2 = puVar10 + -2;

        if (puVar1 != puVar2) {

          FUN_140087ec0(puVar1);

          *puVar1 = *puVar2;

          puVar13[-1] = puVar10[-1];

          *puVar13 = *puVar10;

          *puVar2 = 0;

          puVar10[-1] = 0;

          *puVar10 = 0;

        }

        puVar11 = puVar11 + 0xc;

        puVar13 = puVar13 + 6;

        puVar12 = puVar12 + 0xc;

        puVar10 = puVar10 + 6;

      } while (puVar12 != puVar9);

    }

    puVar9 = *(undefined4 **)(param_1 + 0x3d0);

    for (puVar12 = puVar11; puVar12 != puVar9; puVar12 = puVar12 + 0xc) {

      FUN_140087ec0(puVar12 + 6);

    }

    *(undefined4 **)(param_1 + 0x3d0) = puVar11;

  }

  return;

}




