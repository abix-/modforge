// Address: 0x14020fcb0
// Ghidra name: FUN_14020fcb0
// ============ 0x14020fcb0 FUN_14020fcb0 (size=78) ============


void FUN_14020fcb0(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x148);

  lVar2 = *(longlong *)(lVar1 + 0x20);

  if (lVar2 != 0) {

    (**(code **)(*DAT_1403fd3b0 + 0x68))(DAT_1403fd3b0,lVar2,10000);

  }

  FUN_1401841e0(lVar1);

  *(undefined8 *)(param_1 + 0x148) = 0;

  return;

}




