// Address: 0x140151600
// Ghidra name: FUN_140151600
// ============ 0x140151600 FUN_140151600 (size=272) ============


undefined1 FUN_140151600(longlong param_1,float *param_2)



{

  char cVar1;

  undefined1 uVar2;

  float local_48 [4];

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,2);

      if (cVar1 == '\0') goto LAB_1401516f0;

    }

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    if (param_2 == (float *)0x0) {

      FUN_14014a2f0(param_1,local_48);

      param_2 = local_48;

    }

    local_38 = *param_2;

    local_34 = param_2[1];

    local_2c = local_34;

    local_20 = local_38;

    local_30 = (local_38 + param_2[2]) - DAT_14039ca44;

    local_18 = local_38;

    local_14 = local_34;

    local_28 = local_30;

    local_24 = (local_34 + param_2[3]) - DAT_14039ca44;

    local_1c = local_24;

    uVar2 = FUN_140150b10(param_1,&local_38,5);

    return uVar2;

  }

LAB_1401516f0:

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




