// Address: 0x14015cb20
// Ghidra name: FUN_14015cb20
// ============ 0x14015cb20 FUN_14015cb20 (size=295) ============


longlong FUN_14015cb20(undefined4 param_1,undefined8 *param_2)



{

  char cVar1;

  longlong lVar2;

  undefined8 *puVar3;

  undefined8 *puVar4;

  undefined8 *puVar5;

  longlong local_res18 [2];

  

  lVar2 = FUN_14015e610();

  if (lVar2 == 0) {

    FUN_14012e850("Audio subsystem is not initialized");

    *param_2 = 0;

    return 0;

  }

  puVar4 = (undefined8 *)0x0;

  local_res18[0] = 0;

  cVar1 = FUN_14015ec00(param_1);

  if (cVar1 != '\0') {

    FUN_14017caa0(DAT_1403fc128);

    FUN_1401aaff0(DAT_1403fc138,param_1,local_res18);

    if (local_res18[0] != 0) {

      puVar4 = *(undefined8 **)(local_res18[0] + 8);

      FUN_14015d3d0(puVar4);

    }

    FUN_14017cae0(DAT_1403fc128);

    if (local_res18[0] != 0) {

      FUN_140179b40(*puVar4);

      puVar3 = (undefined8 *)FUN_140138ff0(local_res18[0] + 8);

      puVar5 = puVar4;

      if (puVar4 != puVar3) {

        do {

          puVar4 = puVar3;

          FUN_14015d3d0(puVar4);

          FUN_140179b60(*puVar5);

          FUN_14015fe40(puVar5);

          FUN_140179b40(*puVar4);

          puVar3 = (undefined8 *)FUN_140138ff0(local_res18[0] + 8);

          puVar5 = puVar4;

        } while (puVar4 != puVar3);

      }

      if (local_res18[0] != 0) goto LAB_14015cc34;

    }

  }

  FUN_14012e850("Invalid audio device instance ID");

LAB_14015cc34:

  *param_2 = puVar4;

  return local_res18[0];

}




