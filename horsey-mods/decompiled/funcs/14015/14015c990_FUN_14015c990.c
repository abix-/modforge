// Address: 0x14015c990
// Ghidra name: FUN_14015c990
// ============ 0x14015c990 FUN_14015c990 (size=231) ============


longlong FUN_14015c990(int *param_1,char param_2)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  undefined *puVar4;

  int iVar5;

  undefined8 local_28;

  int local_20;

  longlong local_18;

  char local_10;

  

  lVar3 = 0;

  lVar2 = FUN_14015e610();

  if (lVar2 == 0) {

    FUN_14012e850("Audio subsystem is not initialized");

    iVar1 = 0;

  }

  else {

    FUN_14017caa0(DAT_1403fc128);

    puVar4 = &DAT_1403fc168;

    if (param_2 != '\0') {

      puVar4 = &DAT_1403fc16c;

    }

    iVar1 = FUN_140138fe0(puVar4);

    lVar3 = FUN_1401841f0((longlong)(iVar1 + 1) << 2);

    if (lVar3 != 0) {

      local_28 = 0;

      local_20 = iVar1;

      local_18 = lVar3;

      local_10 = param_2;

      FUN_1401ab210(DAT_1403fc130,FUN_14015c540,&local_28);

      *(undefined4 *)(lVar3 + (longlong)(int)local_28 * 4) = 0;

      iVar1 = (int)local_28;

    }

    FUN_14017cae0(DAT_1403fc128);

  }

  if (param_1 != (int *)0x0) {

    iVar5 = 0;

    if (lVar3 != 0) {

      iVar5 = iVar1;

    }

    *param_1 = iVar5;

  }

  return lVar3;

}




