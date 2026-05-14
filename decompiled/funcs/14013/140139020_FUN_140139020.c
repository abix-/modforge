// Address: 0x140139020
// Ghidra name: FUN_140139020
// ============ 0x140139020 FUN_140139020 (size=7) ============


undefined8 FUN_140139020(undefined8 *param_1,undefined8 param_2)



{

  undefined8 uVar1;

  

  LOCK();

  uVar1 = *param_1;

  *param_1 = param_2;

  UNLOCK();

  return uVar1;

}




