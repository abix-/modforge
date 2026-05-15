// Address: 0x1401556c0
// Ghidra name: FUN_1401556c0
// ============ 0x1401556c0 FUN_1401556c0 (size=191) ============


void FUN_1401556c0(longlong param_1)



{

  char cVar1;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,3);

      if (cVar1 == '\0') goto LAB_140155761;

    }

    if (*(int *)(param_1 + 0x24) == 1) {

      if (*(longlong *)(param_1 + 0x100) == 0) {

        if (*(longlong *)(param_1 + 0xf0) == 0) {

          if (*(longlong *)(param_1 + 0xf8) == 0) {

            (**(code **)(*(longlong *)(param_1 + 0x10) + 0xb0))

                      (*(longlong *)(param_1 + 0x10),param_1);

          }

          else {

            FUN_140155510(param_1);

          }

        }

        else {

          FUN_140155610(param_1);

        }

      }

      else {

        FUN_140155620(param_1);

      }

      if (*(longlong *)(param_1 + 0x128) != 0) {

        FUN_140146010();

        *(undefined8 *)(param_1 + 0x128) = 0;

        return;

      }

    }

    return;

  }

LAB_140155761:

  FUN_14012e850("Parameter \'%s\' is invalid","texture");

  return;

}




