// Address: 0x14019b9b0
// Ghidra name: FUN_14019b9b0
// ============ 0x14019b9b0 FUN_14019b9b0 (size=197) ============


void FUN_14019b9b0(longlong param_1,undefined8 param_2)



{

  char cVar1;

  longlong lVar2;

  uint uVar3;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return;

  }

  uVar3 = *(uint *)(param_1 + 4);

  if ((((uVar3 == 0) || ((uVar3 & 0xf0000000) == 0x10000000)) &&

      ((uVar3 = uVar3 & 0xf000000, uVar3 == 0x1000000 ||

       (((uVar3 == 0xc000000 || (uVar3 == 0x2000000)) || (uVar3 == 0x3000000)))))) &&

     (*(longlong *)(param_1 + 0x48) == 0)) {

    FUN_14012e850("Indexed surfaces must have a palette");

    return;

  }

  lVar2 = FUN_14012c130(param_2,&DAT_14030a390);

  if (lVar2 == 0) {

    return;

  }

  FUN_14019b6c0(param_1,lVar2,1);

  return;

}




