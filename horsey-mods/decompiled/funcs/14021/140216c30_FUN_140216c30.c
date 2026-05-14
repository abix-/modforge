// Address: 0x140216c30
// Ghidra name: FUN_140216c30
// ============ 0x140216c30 FUN_140216c30 (size=220) ============


void FUN_140216c30(undefined8 param_1,int param_2)



{

  char *pcVar1;

  

  if (param_2 < -0x7787ffe1) {

    if (param_2 == -0x7787ffe2) {

      pcVar1 = "Control requested is not available";

      goto LAB_140216cfa;

    }

    if (param_2 == -0x7fffbfff) {

      pcVar1 = "Function not supported";

      goto LAB_140216cfa;

    }

    if (param_2 == -0x7fffbffe) {

      pcVar1 = "Unsupported interface -- Is DirectX 8.0 or later installed?";

      goto LAB_140216cfa;

    }

    if (param_2 == -0x7ff8fff2) {

      pcVar1 = "Out of memory";

      goto LAB_140216cfa;

    }

    if (param_2 == -0x7ff8ffa9) {

      pcVar1 = "Invalid parameter";

      goto LAB_140216cfa;

    }

    if (param_2 == -0x7787fff6) {

      pcVar1 = "Audio device in use";

      goto LAB_140216cfa;

    }

  }

  else {

    if (param_2 == -0x7787ffce) {

      pcVar1 = "Invalid call for the current state";

      goto LAB_140216cfa;

    }

    if (param_2 == -0x7787ffba) {

      pcVar1 = "Caller doesn\'t have priority";

      goto LAB_140216cfa;

    }

    if (param_2 == -0x7787ff9c) {

      pcVar1 = "Unsupported audio format";

      goto LAB_140216cfa;

    }

    if (param_2 == -0x7787ff88) {

      pcVar1 = "No audio device found";

      goto LAB_140216cfa;

    }

    if (param_2 == -0x7787ff6a) {

      pcVar1 = "Mixing buffer was lost";

      goto LAB_140216cfa;

    }

  }

  pcVar1 = "Unknown DirectSound error";

LAB_140216cfa:

  FUN_14012e850("%s: %s (0x%x)",param_1,pcVar1,param_2);

  return;

}




