// Address: 0x140138fd0
// Ghidra name: FUN_140138fd0
// ============ 0x140138fd0 FUN_140138fd0 (size=12) ============


bool FUN_140138fd0(longlong *param_1,longlong param_2,longlong param_3)



{

  longlong lVar1;

  

  LOCK();

  lVar1 = *param_1;

  if (param_2 == lVar1) {

    *param_1 = param_3;

  }

  UNLOCK();

  return param_2 == lVar1;

}




