// Address: 0x140176ce0
// Ghidra name: FUN_140176ce0
// ============ 0x140176ce0 FUN_140176ce0 (size=234) ============


void FUN_140176ce0(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  char cVar3;

  

  FUN_140177410();

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar3 = FUN_1401aa7c0(param_1,7), cVar3 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","sensor");

  }

  else {

    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;

    if (*(int *)(param_1 + 0x6c) < 1) {

      FUN_1401747e0(*(undefined4 *)(param_1 + 0x68));

      (**(code **)(*(longlong *)(param_1 + 0x58) + 0x48))(param_1);

      *(undefined8 *)(param_1 + 0x60) = 0;

      FUN_1401aa9d0(param_1,7,0);

      lVar1 = 0;

      lVar2 = DAT_1403fc480;

      do {

        if (lVar2 == 0) {

LAB_140176d8d:

          FUN_1401841e0(*(undefined8 *)(param_1 + 8));

          FUN_1401841e0(param_1);

          FUN_140177750();

          return;

        }

        if (param_1 == lVar2) {

          if (lVar1 == 0) {

            DAT_1403fc480 = *(longlong *)(param_1 + 0x70);

          }

          else {

            *(undefined8 *)(lVar1 + 0x70) = *(undefined8 *)(lVar2 + 0x70);

          }

          goto LAB_140176d8d;

        }

        lVar1 = lVar2;

        lVar2 = *(longlong *)(lVar2 + 0x70);

      } while( true );

    }

  }

  FUN_140177750();

  return;

}




