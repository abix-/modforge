// Address: 0x14014db70
// Ghidra name: FUN_14014db70
// ============ 0x14014db70 FUN_14014db70 (size=175) ============


void FUN_14014db70(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  char cVar4;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar4 = FUN_1401aa7c0(param_1,2), cVar4 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    return;

  }

  if (*(char *)(param_1 + 0x2d8) == '\0') {

    FUN_14014da10();

  }

  lVar1 = 0;

  lVar2 = DAT_1403fc050;

  do {

    lVar3 = DAT_1403fc050;

    if (lVar2 == 0) {

LAB_14014dbea:

      DAT_1403fc050 = lVar3;

      FUN_1401aa9d0(param_1,2,0);

      FUN_1401841e0(param_1);

      return;

    }

    if (lVar2 == param_1) {

      lVar3 = *(longlong *)(param_1 + 0x2e8);

      if (lVar1 != 0) {

        *(longlong *)(lVar1 + 0x2e8) = *(longlong *)(param_1 + 0x2e8);

        lVar3 = DAT_1403fc050;

      }

      goto LAB_14014dbea;

    }

    lVar1 = lVar2;

    lVar2 = *(longlong *)(lVar2 + 0x2e8);

  } while( true );

}




