// Address: 0x140167ea0
// Ghidra name: FUN_140167ea0
// ============ 0x140167ea0 FUN_140167ea0 (size=138) ============


undefined8

FUN_140167ea0(longlong param_1,longlong param_2,int param_3,code *param_4,undefined8 param_5)



{

  undefined8 uVar1;

  

  if (param_1 == 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar1;

  }

  if (param_2 == 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140334410);

    return uVar1;

  }

  if (param_3 < 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140334414);

    return uVar1;

  }

  if (param_3 == 0) {

    if (param_4 != (code *)0x0) {

      (*param_4)(param_5,param_2,0);

    }

    return 1;

  }

  uVar1 = FUN_140164ea0();

  return uVar1;

}




