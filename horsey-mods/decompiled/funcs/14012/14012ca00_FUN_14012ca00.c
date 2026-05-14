// Address: 0x14012ca00
// Ghidra name: FUN_14012ca00
// ============ 0x14012ca00 FUN_14012ca00 (size=224) ============


undefined8 FUN_14012ca00(longlong param_1,longlong param_2,ulonglong param_3,char param_4)



{

  int iVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  

  uVar3 = 0;

  uVar4 = 1;

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

  }

  else if (param_3 != 0) {

    uVar2 = uVar3;

    if (param_2 == 0) {

      FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14030ebdc);

    }

    else {

      do {

        uVar2 = FUN_14012cbb0(param_1,uVar2 + param_2,param_3 - uVar2);

        if (uVar2 == 0) {

          iVar1 = FUN_14012bf10(param_1);

          if (iVar1 != 3) {

            uVar4 = 0;

            break;

          }

          FUN_1401492f0(1);

        }

        else {

          uVar3 = uVar3 + uVar2;

        }

      } while (uVar3 < param_3);

    }

  }

  if ((param_4 != '\0') && (param_1 != 0)) {

    FUN_14012bd50(param_1);

  }

  return uVar4;

}




