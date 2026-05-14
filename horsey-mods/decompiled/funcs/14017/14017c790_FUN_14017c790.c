// Address: 0x14017c790
// Ghidra name: FUN_14017c790
// ============ 0x14017c790 FUN_14017c790 (size=164) ============


undefined8 FUN_14017c790(char *param_1,undefined8 param_2,undefined4 *param_3)



{

  char cVar1;

  undefined8 uVar2;

  

  if (param_1 == (char *)0x0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","process");

    return uVar2;

  }

  if (*param_1 == '\0') {

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = *(undefined4 *)(param_1 + 4);

      return 1;

    }

  }

  else {

    cVar1 = FUN_14021e530(param_1,param_2,param_1 + 4);

    if (cVar1 == '\0') {

      return 0;

    }

    *param_1 = '\0';

    if (param_3 != (undefined4 *)0x0) {

      if (param_1[1] != '\0') {

        param_1[4] = '\0';

        param_1[5] = '\0';

        param_1[6] = '\0';

        param_1[7] = '\0';

      }

      *param_3 = *(undefined4 *)(param_1 + 4);

    }

  }

  return 1;

}




