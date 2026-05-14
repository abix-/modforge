// Address: 0x140167f30
// Ghidra name: FUN_140167f30
// ============ 0x140167f30 FUN_140167f30 (size=321) ============


char FUN_140167f30(longlong param_1,longlong param_2,int param_3)



{

  char cVar1;

  longlong lVar2;

  

  if (param_1 == 0) {

    cVar1 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return cVar1;

  }

  if (param_2 == 0) {

    cVar1 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140334410);

    return cVar1;

  }

  if (param_3 < 0) {

    cVar1 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140334414);

    return cVar1;

  }

  if (param_3 != 0) {

    if (param_3 < 0x10000) {

      cVar1 = FUN_140164ea0(param_1,param_2,param_3,0,0);

      return cVar1;

    }

    lVar2 = FUN_1401841f0((longlong)param_3);

    cVar1 = '\0';

    if (lVar2 != 0) {

      FUN_1402f8e20(lVar2,param_2,(longlong)param_3);

      cVar1 = FUN_140164ea0(param_1,lVar2,param_3,&LAB_1401644d0,0);

      if (cVar1 == '\0') {

        FUN_1401841e0(lVar2);

      }

    }

    return cVar1;

  }

  return '\x01';

}




