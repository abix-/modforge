// Address: 0x140271f10
// Ghidra name: FUN_140271f10
// ============ 0x140271f10 FUN_140271f10 (size=130) ============


void FUN_140271f10(longlong *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)



{

  char cVar1;

  int iVar2;

  

  if (*(char *)(*param_1 + 0x54) == '\0') {

    FUN_140271cc0(param_1,1);

    return;

  }

  if (param_4 != 0) {

    iVar2 = FUN_14012ef60(param_4,&DAT_1403350d4);

    if (iVar2 == 0) {

      FUN_140271cc0(param_1,2);

      return;

    }

  }

  cVar1 = FUN_1401429e0(param_4,1);

  FUN_140271cc0(param_1,cVar1 != '\0');

  return;

}




