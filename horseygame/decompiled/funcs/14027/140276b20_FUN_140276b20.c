// Address: 0x140276b20
// Ghidra name: FUN_140276b20
// ============ 0x140276b20 FUN_140276b20 (size=109) ============


void FUN_140276b20(undefined8 *param_1,char param_2)



{

  undefined8 uVar1;

  bool bVar2;

  

  if (param_2 == '\0') {

    bVar2 = DAT_1403fddb0 == param_1;

  }

  else {

    bVar2 = DAT_1403fddb0 == (undefined8 *)0x0;

  }

  if ((bVar2) && (*(char *)(param_1 + 1) == '\0')) {

    FUN_1402771f0(*param_1);

    if (param_2 != '\0') {

      uVar1 = FUN_140149350();

      param_1[3] = uVar1;

      DAT_1403fddb0 = param_1;

      return;

    }

    DAT_1403fddb0 = (undefined8 *)0x0;

    param_1[3] = 0;

  }

  return;

}




