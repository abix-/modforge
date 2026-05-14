// Address: 0x14026ca70
// Ghidra name: FUN_14026ca70
// ============ 0x14026ca70 FUN_14026ca70 (size=98) ============


void FUN_14026ca70(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)



{

  char cVar1;

  int iVar2;

  

  if (param_4 != 0) {

    iVar2 = FUN_14012ef60(param_4,&DAT_1403350d4);

    if (iVar2 == 0) {

      FUN_14026cdf0(param_1,2);

      return;

    }

  }

  cVar1 = FUN_1401429e0(param_4,1);

  FUN_14026cdf0(param_1,cVar1 != '\0');

  return;

}




