// Address: 0x1401bc750
// Ghidra name: FUN_1401bc750
// ============ 0x1401bc750 FUN_1401bc750 (size=163) ============


undefined8 FUN_1401bc750(undefined8 param_1,longlong param_2)



{

  char cVar1;

  undefined8 uVar2;

  

  cVar1 = FUN_1401c0880();

  if (cVar1 == '\0') {

    return 0;

  }

  if (*(longlong *)(param_2 + 0x90) != 0) {

    FUN_1401bf630(param_1);

    *(undefined8 *)(param_2 + 0x90) = 0;

  }

  if (*(longlong *)(param_2 + 0x98) != 0) {

    FUN_1401bf630(param_1);

    *(undefined8 *)(param_2 + 0x98) = 0;

  }

  if (*(longlong *)(param_2 + 0xa0) != 0) {

    FUN_1401bf630(param_1);

    *(undefined8 *)(param_2 + 0xa0) = 0;

  }

  FUN_1401b9390(param_1,param_2);

  uVar2 = FUN_1401b7430(param_1,param_2);

  return uVar2;

}




