// Address: 0x14017ea70
// Ghidra name: FUN_14017ea70
// ============ 0x14017ea70 FUN_14017ea70 (size=82) ============


void FUN_14017ea70(undefined8 param_1,undefined8 param_2)



{

  char cVar1;

  undefined4 uVar2;

  

  cVar1 = FUN_14017ebb0();

  if (cVar1 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140304430);

    return;

  }

  uVar2 = FUN_140174be0();

  FUN_140175500(uVar2,param_1,param_2);

  return;

}




