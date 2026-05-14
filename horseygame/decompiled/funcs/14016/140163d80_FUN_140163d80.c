// Address: 0x140163d80
// Ghidra name: FUN_140163d80
// ============ 0x140163d80 FUN_140163d80 (size=109) ============


void FUN_140163d80(longlong param_1,undefined4 *param_2)



{

  char cVar1;

  

  cVar1 = FUN_140163df0();

  if (cVar1 == '\0') {

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = 0xffffffff;

      return;

    }

  }

  else {

    FUN_140180210(param_1);

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = *(undefined4 *)(param_1 + 0x10);

    }

    FUN_1401aa9d0(param_1,10,0);

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x40));

    FUN_1401841e0(param_1);

  }

  return;

}




