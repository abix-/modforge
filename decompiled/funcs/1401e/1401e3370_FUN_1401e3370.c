// Address: 0x1401e3370
// Ghidra name: FUN_1401e3370
// ============ 0x1401e3370 FUN_1401e3370 (size=70) ============


void FUN_1401e3370(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x108))(*(longlong **)(lVar1 + 0x28),0,0,0);

  if (*(longlong **)(lVar1 + 0x48) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x10))();

    *(undefined8 *)(lVar1 + 0x48) = 0;

  }

  return;

}




