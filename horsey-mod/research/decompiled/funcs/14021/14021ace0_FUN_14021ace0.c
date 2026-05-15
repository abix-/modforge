// Address: 0x14021ace0
// Ghidra name: FUN_14021ace0
// ============ 0x14021ace0 FUN_14021ace0 (size=122) ============


char FUN_14021ace0(undefined8 param_1,longlong param_2,undefined8 param_3)



{

  char cVar1;

  longlong lVar2;

  

  lVar2 = FUN_1401841a0(1,0x58);

  *(longlong *)(param_2 + 0x48) = lVar2;

  if (lVar2 == 0) {

    return '\0';

  }

  cVar1 = FUN_140287e30(param_1,param_2,param_3);

  if (cVar1 == '\0') {

    FUN_1401841e0(*(undefined8 *)(param_2 + 0x48));

    *(undefined8 *)(param_2 + 0x48) = 0;

  }

  return cVar1;

}




