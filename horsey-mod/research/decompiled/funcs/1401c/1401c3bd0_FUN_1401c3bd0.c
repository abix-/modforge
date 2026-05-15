// Address: 0x1401c3bd0
// Ghidra name: FUN_1401c3bd0
// ============ 0x1401c3bd0 FUN_1401c3bd0 (size=467) ============


undefined4 * FUN_1401c3bd0(longlong param_1,undefined8 *param_2)



{

  undefined8 uVar1;

  char cVar2;

  int iVar3;

  undefined8 *puVar4;

  undefined4 *puVar5;

  undefined8 uVar6;

  longlong *local_res8;

  undefined8 local_48;

  undefined8 local_40;

  undefined8 local_38;

  undefined4 local_30;

  undefined8 local_28;

  undefined8 local_20;

  undefined4 local_18;

  

  cVar2 = FUN_1401c85b0(param_1,param_2[1],*param_2,*(undefined4 *)(param_2 + 3),0,0);

  if (cVar2 == '\0') {

    return (undefined4 *)0x0;

  }

  puVar4 = (undefined8 *)FUN_1401c79e0(param_1,param_2);

  if (puVar4 == (undefined8 *)0x0) {

    if (*(char *)(param_1 + 0x98) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Could not create root signature!");

    }

    FUN_14012e850(&DAT_14039bf30,"Could not create root signature!");

    puVar5 = (undefined4 *)0x0;

  }

  else {

    local_40 = param_2[1];

    local_38 = *param_2;

    local_48 = *puVar4;

    local_20 = 0;

    local_28 = 0;

    local_18 = 0;

    local_30 = 0;

    iVar3 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x58))

                      (*(longlong **)(param_1 + 0x70),&local_48,&DAT_140349368,&local_res8);

    if (iVar3 < 0) {

      FUN_1401cb240(param_1,"Could not create compute pipeline state",iVar3);

      puVar5 = (undefined4 *)0x0;

    }

    else {

      puVar5 = (undefined4 *)FUN_1401841a0(1,0x30);

      if (puVar5 == (undefined4 *)0x0) {

        (**(code **)(*local_res8 + 0x10))();

        puVar5 = (undefined4 *)0x0;

      }

      else {

        *(longlong **)(puVar5 + 6) = local_res8;

        *(undefined8 **)(puVar5 + 8) = puVar4;

        *puVar5 = *(undefined4 *)((longlong)param_2 + 0x1c);

        puVar5[1] = *(undefined4 *)(param_2 + 4);

        puVar5[2] = *(undefined4 *)((longlong)param_2 + 0x24);

        puVar5[3] = *(undefined4 *)(param_2 + 5);

        puVar5[4] = *(undefined4 *)((longlong)param_2 + 0x2c);

        puVar5[5] = *(undefined4 *)(param_2 + 6);

        FUN_140139010(puVar5 + 10,0);

        if ((*(char *)(param_1 + 0x98) != '\0') &&

           (cVar2 = FUN_140174fc0(*(undefined4 *)(param_2 + 8),"SDL.gpu.computepipeline.create.name"

                                 ), cVar2 != '\0')) {

          uVar1 = *(undefined8 *)(puVar5 + 6);

          uVar6 = FUN_140174e70(*(undefined4 *)(param_2 + 8),"SDL.gpu.computepipeline.create.name",0

                               );

          FUN_1401cb3d0(param_1,uVar1,uVar6);

        }

      }

    }

  }

  return puVar5;

}




