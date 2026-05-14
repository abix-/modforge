// Address: 0x140163030
// Ghidra name: FUN_140163030
// ============ 0x140163030 FUN_140163030 (size=186) ============


undefined1

FUN_140163030(longlong param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,char param_5

             )



{

  longlong lVar1;

  char cVar2;

  undefined1 uVar3;

  

  lVar1 = FUN_1401611a0();

  lVar1 = *(longlong *)(lVar1 + 0x88);

  cVar2 = FUN_140161650(param_1,param_2,param_3);

  if (cVar2 == '\0') {

    if (param_1 == lVar1) {

      if (param_5 != '\0') {

        FUN_140161f10(0,param_1,0,0,param_2,param_3);

      }

      FUN_140162ca0(0);

    }

    uVar3 = 0;

  }

  else {

    if (param_1 != lVar1) {

      FUN_140162ca0(param_1);

      if (param_5 != '\0') {

        FUN_140161f10(0,param_1,0,0,param_2,param_3);

      }

    }

    uVar3 = 1;

  }

  return uVar3;

}




