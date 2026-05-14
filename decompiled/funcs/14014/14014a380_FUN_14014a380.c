// Address: 0x14014a380
// Ghidra name: FUN_14014a380
// ============ 0x14014a380 FUN_14014a380 (size=70) ============


undefined8 FUN_14014a380(longlong param_1,undefined4 param_2)



{

  char cVar1;

  

  switch(param_2) {

  case 0:

  case 1:

  case 2:

  case 4:

  case 8:

  case 0x10:

  case 0x20:

    break;

  default:

    if ((*(code **)(param_1 + 0x10) == (code *)0x0) ||

       (cVar1 = (**(code **)(param_1 + 0x10))(), cVar1 == '\0')) {

      return 0;

    }

  }

  return 1;

}




