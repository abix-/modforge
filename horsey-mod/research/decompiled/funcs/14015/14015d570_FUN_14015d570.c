// Address: 0x14015d570
// Ghidra name: FUN_14015d570
// ============ 0x14015d570 FUN_14015d570 (size=88) ============


void FUN_14015d570(undefined8 *param_1,undefined8 *param_2)



{

  undefined8 uVar1;

  

  uVar1 = FUN_14015d410(0,"System audio playback device",0,1);

  *param_1 = uVar1;

  if (DAT_1403fc121 != '\0') {

    uVar1 = FUN_14015d410(1,"System audio recording device",0,2);

    *param_2 = uVar1;

  }

  return;

}




