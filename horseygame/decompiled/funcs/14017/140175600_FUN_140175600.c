// Address: 0x140175600
// Ghidra name: FUN_140175600
// ============ 0x140175600 FUN_140175600 (size=306) ============


void FUN_140175600(ulonglong param_1)



{

  char cVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  uint uVar4;

  ulonglong uVar5;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,6), cVar1 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","haptic");

    return;

  }

  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;

  if (0 < *(int *)(param_1 + 0x30)) {

    return;

  }

  cVar1 = FUN_14021b070(param_1);

  uVar2 = 0;

  if (cVar1 == '\0') {

    uVar3 = uVar2;

    uVar5 = uVar2;

    if (0 < *(int *)(param_1 + 0x18)) {

      do {

        if (*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x48 + uVar3) != 0) {

          FUN_1401758c0(param_1,uVar5);

        }

        uVar4 = (int)uVar5 + 1;

        uVar3 = uVar3 + 0x50;

        uVar5 = (ulonglong)uVar4;

      } while ((int)uVar4 < *(int *)(param_1 + 0x18));

    }

    FUN_14021ab90(param_1);

  }

  else {

    FUN_14021af40(param_1);

  }

  FUN_1401aa9d0(param_1,6,0);

  uVar3 = DAT_1403fc460;

  do {

    if (uVar3 == 0) {

LAB_1401756f9:

      FUN_1401841e0(*(undefined8 *)(param_1 + 8));

      FUN_1401841e0(param_1);

      return;

    }

    if (param_1 == uVar3) {

      if (uVar2 == 0) {

        DAT_1403fc460 = *(ulonglong *)(param_1 + 0x80);

      }

      else {

        *(undefined8 *)(uVar2 + 0x80) = *(undefined8 *)(uVar3 + 0x80);

      }

      goto LAB_1401756f9;

    }

    uVar2 = uVar3;

    uVar3 = *(ulonglong *)(uVar3 + 0x80);

  } while( true );

}




