// Address: 0x1401b0ca0
// Ghidra name: FUN_1401b0ca0
// ============ 0x1401b0ca0 FUN_1401b0ca0 (size=310) ============


undefined4 * FUN_1401b0ca0(undefined8 param_1,undefined4 *param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  char cVar3;

  undefined4 uVar4;

  undefined8 *puVar5;

  undefined4 *puVar6;

  undefined8 *puVar7;

  undefined8 uVar8;

  

  puVar5 = (undefined8 *)FUN_1401b7d00();

  if (puVar5 != (undefined8 *)0x0) {

    puVar6 = (undefined4 *)FUN_1401841f0(0x50);

    uVar4 = param_2[1];

    uVar1 = param_2[2];

    uVar2 = param_2[3];

    *puVar6 = *param_2;

    puVar6[1] = uVar4;

    puVar6[2] = uVar1;

    puVar6[3] = uVar2;

    uVar4 = param_2[5];

    uVar1 = param_2[6];

    uVar2 = param_2[7];

    puVar6[4] = param_2[4];

    puVar6[5] = uVar4;

    puVar6[6] = uVar1;

    puVar6[7] = uVar2;

    puVar6[8] = param_2[8];

    uVar4 = FUN_1401746e0();

    puVar6[8] = uVar4;

    if (param_2[8] != 0) {

      FUN_1401745f0(param_2[8],uVar4);

    }

    *(undefined1 *)(puVar6 + 0x12) = 1;

    *(undefined8 **)(puVar6 + 10) = puVar5;

    puVar6[0xc] = 1;

    puVar6[0xd] = 1;

    puVar7 = (undefined8 *)FUN_1401841f0(8);

    *(undefined8 **)(puVar6 + 0xe) = puVar7;

    *puVar7 = *(undefined8 *)(puVar6 + 10);

    *(undefined8 *)(puVar6 + 0x10) = 0;

    cVar3 = FUN_140174fc0(param_2[8],"SDL.gpu.texture.create.name");

    if (cVar3 != '\0') {

      uVar8 = FUN_140174e70(param_2[8],"SDL.gpu.texture.create.name",0);

      uVar8 = FUN_14012f0d0(uVar8);

      *(undefined8 *)(puVar6 + 0x10) = uVar8;

    }

    *puVar5 = puVar6;

    *(undefined4 *)(puVar5 + 1) = 0;

    uVar8 = FUN_1401add10(param_1);

    FUN_1401bd6c0(param_1,uVar8,0,puVar5);

    FUN_1401bdb50(uVar8,puVar5);

    cVar3 = FUN_1401bfd60(uVar8);

    if (cVar3 == '\0') {

      FUN_1401bf820(param_1,puVar6);

      puVar6 = (undefined4 *)0x0;

    }

    return puVar6;

  }

  return (undefined4 *)0x0;

}




