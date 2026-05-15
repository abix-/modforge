// Address: 0x140145bc0
// Ghidra name: FUN_140145bc0
// ============ 0x140145bc0 FUN_140145bc0 (size=350) ============


longlong FUN_140145bc0(int param_1,int param_2,int param_3,longlong param_4,int param_5)



{

  char cVar1;

  longlong lVar2;

  ulonglong *in_stack_ffffffffffffffa8;

  ulonglong local_28 [2];

  

  if (param_1 < 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","width");

    return 0;

  }

  if (param_2 < 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","height");

    return 0;

  }

  if (param_3 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","format");

    return 0;

  }

  if ((param_5 != 0) || (param_4 != 0)) {

    in_stack_ffffffffffffffa8 = local_28;

    cVar1 = FUN_140144680(param_3,param_1,param_2,0,in_stack_ffffffffffffffa8,1);

    if (cVar1 == '\0') {

      return 0;

    }

    if ((param_5 < 0) || ((ulonglong)(longlong)param_5 < local_28[0])) {

      FUN_14012e850("Parameter \'%s\' is invalid","pitch");

      return 0;

    }

  }

  lVar2 = FUN_1401841f0(0x128);

  if (lVar2 == 0) {

    return 0;

  }

  cVar1 = FUN_140146ca0(lVar2,param_1,param_2,param_3,

                        (ulonglong)in_stack_ffffffffffffffa8 & 0xffffffff00000000,0,param_4,param_5,

                        0);

  if (cVar1 != '\0') {

    return lVar2;

  }

  return 0;

}




