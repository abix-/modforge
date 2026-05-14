// Address: 0x140163930
// Ghidra name: FUN_140163930
// ============ 0x140163930 FUN_140163930 (size=50) ============


undefined8 FUN_140163930(undefined8 *param_1)



{

  char cVar1;

  undefined8 uVar2;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar2 = FUN_14017ffb0();

    return uVar2;

  }

  cVar1 = FUN_140163df0();

  if (cVar1 != '\0') {

    return *param_1;

  }

  return 0;

}




