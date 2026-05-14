// Address: 0x140274520
// Ghidra name: FUN_140274520
// ============ 0x140274520 FUN_140274520 (size=54) ============


void FUN_140274520(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  

  cVar1 = FUN_1401429e0(param_4,1);

  if (cVar1 != *(char *)(param_1 + 0x6c)) {

    *(char *)(param_1 + 0x6c) = cVar1;

    FUN_140274300(param_1,0x10,0);

    return;

  }

  return;

}




