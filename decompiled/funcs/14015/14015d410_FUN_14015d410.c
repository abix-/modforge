// Address: 0x14015d410
// Ghidra name: FUN_14015d410
// ============ 0x14015d410 FUN_14015d410 (size=245) ============


longlong FUN_14015d410(char param_1,undefined8 param_2,int *param_3,undefined8 param_4)



{

  longlong lVar1;

  undefined4 *puVar2;

  int local_18;

  int local_14;

  int local_10;

  

  local_14 = 2 - (uint)(param_1 != '\0');

  if (param_3 == (int *)0x0) {

    local_18 = 0x8010;

    local_10 = 0xac44;

  }

  else {

    local_18 = 0x8010;

    if (*param_3 != 0) {

      local_18 = *param_3;

    }

    if (param_3[1] != 0) {

      local_14 = param_3[1];

    }

    local_10 = 0xac44;

    if (param_3[2] != 0) {

      local_10 = param_3[2];

    }

  }

  if (param_1 == '\0') {

    lVar1 = FUN_14015c5a0(param_2,&local_18,param_4);

  }

  else {

    lVar1 = FUN_14015c5d0();

  }

  if (lVar1 != 0) {

    puVar2 = (undefined4 *)FUN_1401841f0(0x10);

    if (puVar2 != (undefined4 *)0x0) {

      *puVar2 = 0x1100;

      puVar2[1] = *(undefined4 *)(lVar1 + 0x50);

      *(undefined8 *)(puVar2 + 2) = 0;

      FUN_14017cab0(DAT_1403fc128);

      *(undefined4 **)(DAT_1403fc160 + 2) = puVar2;

      DAT_1403fc160 = puVar2;

      FUN_14017cae0(DAT_1403fc128);

    }

    return lVar1;

  }

  return 0;

}




