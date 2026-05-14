// Address: 0x1402852d0
// Ghidra name: FUN_1402852d0
// ============ 0x1402852d0 FUN_1402852d0 (size=151) ============


undefined * FUN_1402852d0(byte param_1,undefined1 param_2)



{

  char *pcVar1;

  

  switch(param_2) {

  case 1:

    pcVar1 = "XInput Controller #%d";

    break;

  case 2:

    pcVar1 = "XInput Wheel #%d";

    break;

  case 3:

    pcVar1 = "XInput ArcadeStick #%d";

    break;

  case 4:

    pcVar1 = "XInput FlightStick #%d";

    break;

  case 5:

    pcVar1 = "XInput DancePad #%d";

    break;

  case 6:

  case 7:

  case 0xb:

    pcVar1 = "XInput Guitar #%d";

    break;

  case 8:

    pcVar1 = "XInput DrumKit #%d";

    break;

  default:

    pcVar1 = "XInput Device #%d";

    break;

  case 0x13:

    pcVar1 = "XInput ArcadePad #%d";

  }

  FUN_14012ef10(&DAT_1403fde28,0x20,pcVar1,param_1 + 1);

  return &DAT_1403fde28;

}




