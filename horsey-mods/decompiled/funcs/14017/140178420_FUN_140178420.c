// Address: 0x140178420
// Ghidra name: FUN_140178420
// ============ 0x140178420 FUN_140178420 (size=179) ============


void FUN_140178420(longlong param_1,longlong param_2,longlong param_3,longlong param_4)



{

  char cVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid storage container");

  }

  else if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140335b8c);

  }

  else {

    cVar1 = FUN_1401784e0(param_2);

    if (cVar1 != '\0') {

      if ((param_4 == 0) || (param_3 != 0)) {

        if (*(code **)(param_1 + 0x30) == (code *)0x0) {

          FUN_14012e850("That operation is not supported");

        }

        else {

          (**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0x60),param_2,param_3,param_4);

        }

      }

      else {

        FUN_14012e850("Parameter \'%s\' is invalid","source");

      }

    }

  }

  return;

}




