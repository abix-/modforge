// Address: 0x14015e550
// Ghidra name: FUN_14015e550
// ============ 0x14015e550 FUN_14015e550 (size=109) ============


undefined4 FUN_14015e550(undefined8 *param_1)



{

  undefined4 uVar1;

  

  uVar1 = 0;

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return 0;

  }

  FUN_140179b40(*param_1);

  if ((undefined4 *)param_1[0x18] == (undefined4 *)0x0) {

    FUN_14012e850("Audio stream not bound to an audio device");

  }

  else {

    uVar1 = *(undefined4 *)param_1[0x18];

  }

  FUN_140179b60(*param_1);

  return uVar1;

}




