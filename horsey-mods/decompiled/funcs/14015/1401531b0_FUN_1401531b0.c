// Address: 0x1401531b0
// Ghidra name: FUN_1401531b0
// ============ 0x1401531b0 FUN_1401531b0 (size=606) ============


undefined1

FUN_1401531b0(longlong param_1,longlong param_2,longlong param_3,float param_4,undefined1 *param_5)



{

  char cVar1;

  undefined1 uVar2;

  undefined8 local_48;

  float local_40;

  float local_3c;

  undefined1 local_38 [48];

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,2), cVar1 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    uVar2 = 0;

  }

  else if (*(char *)(param_1 + 0x2d8) == '\0') {

    if ((param_2 == 0) ||

       ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_2,3), cVar1 == '\0')))) {

      FUN_14012e850("Parameter \'%s\' is invalid","texture");

      uVar2 = 0;

    }

    else if (param_1 == *(longlong *)(param_2 + 0x10)) {

      if (0.0 < param_4) {

        local_48 = 0;

        local_40 = (float)*(int *)(param_2 + 4);

        local_3c = (float)*(int *)(param_2 + 8);

        if ((param_3 == 0) || (cVar1 = FUN_140185680(param_3,&local_48,&local_48), cVar1 != '\0')) {

          if (param_5 == (undefined1 *)0x0) {

            FUN_14014a2f0(param_1,local_38);

            param_5 = local_38;

          }

          cVar1 = FUN_140156f30(param_2);

          uVar2 = 0;

          if (cVar1 != '\0') {

            if (*(longlong *)(param_2 + 0xf8) != 0) {

              param_2 = *(longlong *)(param_2 + 0xf8);

            }

            *(undefined4 *)(param_2 + 0x130) = *(undefined4 *)(param_1 + 600);

            if ((*(char *)(param_1 + 0x114) == '\0') &&

               (((param_3 == 0 ||

                 (((((float)local_48 == 0.0 && (local_48._4_4_ == 0.0)) &&

                   (local_40 == (float)*(int *)(param_2 + 4))) &&

                  (local_3c == (float)*(int *)(param_2 + 8))))) &&

                ((*(char *)(param_1 + 0x115) == '\0' ||

                 ((cVar1 = FUN_14014a360(*(undefined4 *)(param_2 + 4)), cVar1 == '\0' &&

                  (cVar1 = FUN_14014a360(*(undefined4 *)(param_2 + 8)), cVar1 == '\0')))))))) {

              uVar2 = FUN_140153410(param_1,param_2,&local_48,param_4,param_5);

            }

            else {

              uVar2 = FUN_140152f10(param_1,param_2,&local_48,param_4,param_5);

            }

          }

        }

        else {

          uVar2 = 1;

        }

      }

      else {

        uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","scale");

      }

    }

    else {

      uVar2 = FUN_14012e850("Texture was not created with this renderer");

    }

  }

  else {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    uVar2 = 0;

  }

  return uVar2;

}




