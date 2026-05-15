// Address: 0x140279cf0
// Ghidra name: FUN_140279cf0
// ============ 0x140279cf0 FUN_140279cf0 (size=46) ============


void FUN_140279cf0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  

  cVar1 = FUN_1401429e0(param_4,1);

  if (cVar1 != *(char *)(param_1 + 0x20)) {

    *(char *)(param_1 + 0x20) = cVar1;

    FUN_140279f50(param_1);

    return;

  }

  return;

}




