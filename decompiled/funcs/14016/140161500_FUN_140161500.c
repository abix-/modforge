// Address: 0x140161500
// Ghidra name: FUN_140161500
// ============ 0x140161500 FUN_140161500 (size=51) ============


void FUN_140161500(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  

  cVar1 = FUN_1401429e0(param_4,1);

  if (cVar1 != *(char *)(param_1 + 0xf3)) {

    *(char *)(param_1 + 0xf3) = cVar1;

    FUN_140162f40(0);

    return;

  }

  return;

}




