// Address: 0x1401ca4f0
// Ghidra name: FUN_1401ca4f0
// ============ 0x1401ca4f0 FUN_1401ca4f0 (size=283) ============


void FUN_1401ca4f0(undefined4 param_1,int param_2,undefined4 param_3,undefined8 param_4)



{

  char *pcVar1;

  char *pcVar2;

  

  pcVar2 = "UNKNOWN";

  switch(param_1) {

  case 0:

    pcVar1 = "APPLICATION_DEFINED";

    break;

  case 1:

    pcVar1 = "MISCELLANEOUS";

    break;

  case 2:

    pcVar1 = "INITIALIZATION";

    break;

  case 3:

    pcVar1 = "CLEANUP";

    break;

  case 4:

    pcVar1 = "COMPILATION";

    break;

  case 5:

    pcVar1 = "STATE_CREATION";

    break;

  case 6:

    pcVar1 = "STATE_SETTING";

    break;

  case 7:

    pcVar1 = "STATE_GETTING";

    break;

  case 8:

    pcVar1 = "RESOURCE_MANIPULATION";

    break;

  case 9:

    pcVar1 = "EXECUTION";

    break;

  case 10:

    pcVar1 = "SHADER";

    break;

  default:

    pcVar1 = "UNKNOWN";

  }

  if (param_2 == 0) {

    pcVar2 = "CORRUPTION";

  }

  else {

    if (param_2 != 1) {

      if (param_2 == 2) {

        pcVar2 = "WARNING";

      }

      else if (param_2 == 3) {

        pcVar2 = "INFO";

      }

      else if (param_2 == 4) {

        pcVar2 = "MESSAGE";

      }

      else if (param_2 < 2) goto LAB_1401ca5ed;

      FUN_14012e2e0(9,"D3D12 WARNING: %s [%s %s #%d]",param_4,pcVar1,pcVar2,param_3);

      return;

    }

    pcVar2 = "ERROR";

  }

LAB_1401ca5ed:

                    /* WARNING: Subroutine does not return */

  FUN_14012e0b0(9,"D3D12 ERROR: %s [%s %s #%d]",param_4,pcVar1,pcVar2,param_3);

}




