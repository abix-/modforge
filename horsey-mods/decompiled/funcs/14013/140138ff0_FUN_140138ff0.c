// Address: 0x140138ff0
// Ghidra name: FUN_140138ff0
// ============ 0x140138ff0 FUN_140138ff0 (size=10) ============


longlong FUN_140138ff0(longlong *param_1)



{

  longlong lVar1;

  

  LOCK();

  lVar1 = *param_1;

  if (lVar1 == 0) {

    *param_1 = 0;

    lVar1 = 0;

  }

  UNLOCK();

  return lVar1;

}




