// Address: 0x1401575b0
// Ghidra name: FUN_1401575b0
// ============ 0x1401575b0 FUN_1401575b0 (size=464) ============


void FUN_1401575b0(ulonglong param_1)



{

  ulonglong uVar1;

  char cVar2;

  ulonglong uVar3;

  uint uVar4;

  ulonglong uVar5;

  

  FUN_140159d30();

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,4), cVar2 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  }

  else {

    *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + -1;

    if (*(int *)(param_1 + 0x154) < 1) {

      FUN_1401747e0(*(undefined4 *)(param_1 + 0x150));

      if (*(longlong *)(param_1 + 0xa8) != 0) {

        FUN_14015a960(param_1,0,0,0);

      }

      if (*(longlong *)(param_1 + 0xc0) != 0) {

        FUN_14015a810(param_1,0,0,0);

      }

      FUN_140157380(param_1);

      (**(code **)(*(longlong *)(param_1 + 0x140) + 0x90))(param_1);

      uVar3 = 0;

      *(undefined8 *)(param_1 + 0x148) = 0;

      FUN_1401aa9d0(param_1,4,0);

      uVar5 = uVar3;

      uVar1 = DAT_1403fc070;

      do {

        if (uVar1 == 0) {

LAB_1401576b9:

          FUN_1401841e0(*(undefined8 *)(param_1 + 8));

          FUN_1401841e0(*(undefined8 *)(param_1 + 0x10));

          FUN_1401841e0(*(undefined8 *)(param_1 + 0x18));

          FUN_1401841e0(*(undefined8 *)(param_1 + 0x48));

          FUN_1401841e0(*(undefined8 *)(param_1 + 0x58));

          FUN_1401841e0(*(undefined8 *)(param_1 + 0x68));

          FUN_1401841e0(*(undefined8 *)(param_1 + 0x78));

          uVar5 = uVar3;

          if (0 < *(int *)(param_1 + 0x80)) {

            do {

              FUN_1401841e0(*(undefined8 *)(uVar3 + 8 + *(longlong *)(param_1 + 0x88)));

              uVar4 = (int)uVar5 + 1;

              uVar3 = uVar3 + 0x10;

              uVar5 = (ulonglong)uVar4;

            } while ((int)uVar4 < *(int *)(param_1 + 0x80));

          }

          FUN_1401841e0(*(undefined8 *)(param_1 + 0x88));

          FUN_1401841e0(*(undefined8 *)(param_1 + 0x98));

          FUN_1401841e0(param_1);

          FUN_14015bb10();

          return;

        }

        if (param_1 == uVar1) {

          if (uVar5 == 0) {

            DAT_1403fc070 = *(ulonglong *)(param_1 + 0x158);

          }

          else {

            *(undefined8 *)(uVar5 + 0x158) = *(undefined8 *)(uVar1 + 0x158);

          }

          goto LAB_1401576b9;

        }

        uVar5 = uVar1;

        uVar1 = *(ulonglong *)(uVar1 + 0x158);

      } while( true );

    }

  }

  FUN_14015bb10();

  return;

}




