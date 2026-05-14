// Address: 0x1401b0aa0
// Ghidra name: FUN_1401b0aa0
// ============ 0x1401b0aa0 FUN_1401b0aa0 (size=497) ============


undefined8 * FUN_1401b0aa0(longlong param_1,undefined8 *param_2)



{

  char cVar1;

  int iVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  undefined *puVar5;

  undefined4 local_58 [2];

  undefined8 local_50;

  undefined4 local_48;

  undefined8 local_40;

  undefined8 local_38;

  undefined4 local_30 [2];

  undefined8 local_28;

  undefined4 local_20;

  undefined8 local_18;

  undefined8 local_10;

  

  cVar1 = FUN_1401bb550(param_2[1],*param_2);

  if (cVar1 != '\0') {

    puVar3 = (undefined8 *)FUN_1401841f0(0x28);

    local_40 = *param_2;

    local_38 = param_2[1];

    local_58[0] = 0x10;

    local_50 = 0;

    local_48 = 0;

    iVar2 = (**(code **)(param_1 + 0xb68))(*(undefined8 *)(param_1 + 0x570),local_58,0,puVar3);

    if (iVar2 == 0) {

      puVar5 = &DAT_1403424a4;

      if ((undefined *)param_2[2] != (undefined *)0x0) {

        puVar5 = (undefined *)param_2[2];

      }

      uVar4 = FUN_14012f0d0(puVar5);

      puVar3[1] = uVar4;

      *(undefined4 *)(puVar3 + 2) = *(undefined4 *)((longlong)param_2 + 0x1c);

      *(undefined4 *)((longlong)puVar3 + 0x14) = *(undefined4 *)(param_2 + 4);

      *(undefined4 *)(puVar3 + 3) = *(undefined4 *)((longlong)param_2 + 0x24);

      *(undefined4 *)((longlong)puVar3 + 0x1c) = *(undefined4 *)(param_2 + 5);

      *(undefined4 *)(puVar3 + 4) = *(undefined4 *)((longlong)param_2 + 0x2c);

      FUN_140139010((longlong)puVar3 + 0x24,0);

      if ((*(char *)(param_1 + 0x57c) != '\0') &&

         (cVar1 = FUN_140174fc0(*(undefined4 *)(param_2 + 6),"SDL.gpu.shader.create.name"),

         cVar1 != '\0')) {

        local_30[0] = 0x3b9cbe00;

        local_28 = 0;

        local_10 = FUN_140174e70(*(undefined4 *)(param_2 + 6),"SDL.gpu.shader.create.name",0);

        local_18 = *puVar3;

        local_20 = 0xf;

        (**(code **)(param_1 + 0x9d0))(*(undefined8 *)(param_1 + 0x570),local_30);

      }

    }

    else {

      FUN_1401841e0(puVar3);

      if (*(char *)(param_1 + 0x57c) != '\0') {

        uVar4 = FUN_1401c0ba0(iVar2);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(9,"%s %s","vkCreateShaderModule",uVar4);

      }

      uVar4 = FUN_1401c0ba0(iVar2);

      FUN_14012e850("%s %s","vkCreateShaderModule",uVar4);

      puVar3 = (undefined8 *)0x0;

    }

    return puVar3;

  }

  if (*(char *)(param_1 + 0x57c) == '\0') {

    FUN_14012e850(&DAT_14039bf30,"The provided shader code is not valid SPIR-V!");

    return (undefined8 *)0x0;

  }

                    /* WARNING: Subroutine does not return */

  FUN_14012e0b0(9,&DAT_14039bf30,"The provided shader code is not valid SPIR-V!");

}




