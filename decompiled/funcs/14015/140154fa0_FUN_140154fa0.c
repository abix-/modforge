// Address: 0x140154fa0
// Ghidra name: FUN_140154fa0
// ============ 0x140154fa0 FUN_140154fa0 (size=188) ============


ulonglong FUN_140154fa0(longlong param_1,int param_2)



{

  longlong *plVar1;

  char cVar2;

  ulonglong uVar3;

  

  while (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,3);

      if (cVar2 == '\0') break;

    }

    if (param_2 == 0x7fffffff) {

      uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","blendMode");

      return uVar3;

    }

    cVar2 = FUN_14014a380(*(undefined8 *)(param_1 + 0x10),param_2);

    if (cVar2 == '\0') {

      uVar3 = FUN_14012e850("That operation is not supported");

      return uVar3;

    }

    plVar1 = (longlong *)(param_1 + 0xf8);

    *(int *)(param_1 + 0x28) = param_2;

    param_1 = *plVar1;

    if (*plVar1 == 0) {

      return 1;

    }

  }

  uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","texture");

  return uVar3 & 0xffffffffffffff00;

}




