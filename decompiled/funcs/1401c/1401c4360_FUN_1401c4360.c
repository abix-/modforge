// Address: 0x1401c4360
// Ghidra name: FUN_1401c4360
// ============ 0x1401c4360 FUN_1401c4360 (size=283) ============


undefined4 * FUN_1401c4360(undefined8 param_1,undefined4 *param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  char cVar3;

  undefined4 uVar4;

  undefined4 *puVar5;

  longlong lVar6;

  undefined8 uVar7;

  undefined8 *puVar8;

  

  puVar5 = (undefined4 *)FUN_1401841a0(1,0x50);

  if (puVar5 != (undefined4 *)0x0) {

    uVar4 = param_2[1];

    uVar1 = param_2[2];

    uVar2 = param_2[3];

    *puVar5 = *param_2;

    puVar5[1] = uVar4;

    puVar5[2] = uVar1;

    puVar5[3] = uVar2;

    uVar4 = param_2[5];

    uVar1 = param_2[6];

    uVar2 = param_2[7];

    puVar5[4] = param_2[4];

    puVar5[5] = uVar4;

    puVar5[6] = uVar1;

    puVar5[7] = uVar2;

    puVar5[8] = param_2[8];

    uVar4 = FUN_1401746e0();

    puVar5[8] = uVar4;

    if (param_2[8] != 0) {

      FUN_1401745f0(param_2[8],uVar4);

    }

    puVar5[0xe] = 1;

    puVar5[0xf] = 1;

    lVar6 = FUN_1401841a0(1,8);

    *(longlong *)(puVar5 + 0xc) = lVar6;

    if (lVar6 != 0) {

      *(undefined8 *)(puVar5 + 0x12) = 0;

      cVar3 = FUN_140174fc0(param_2[8],"SDL.gpu.texture.create.name");

      if (cVar3 != '\0') {

        uVar7 = FUN_140174e70(param_2[8],"SDL.gpu.texture.create.name",0);

        uVar7 = FUN_14012f0d0(uVar7);

        *(undefined8 *)(puVar5 + 0x12) = uVar7;

      }

      *(undefined1 *)(puVar5 + 0x10) = 1;

      puVar8 = (undefined8 *)FUN_1401c8b30(param_1,param_2,0,*(undefined8 *)(puVar5 + 0x12));

      if (puVar8 != (undefined8 *)0x0) {

        **(undefined8 **)(puVar5 + 0xc) = puVar8;

        *(undefined8 **)(puVar5 + 10) = puVar8;

        *puVar8 = puVar5;

        *(undefined4 *)(puVar8 + 1) = 0;

        return puVar5;

      }

      FUN_1401841e0();

    }

    FUN_1401841e0(puVar5);

  }

  return (undefined4 *)0x0;

}




