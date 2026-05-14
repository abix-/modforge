// Address: 0x140107510
// Ghidra name: FUN_140107510
// ============ 0x140107510 FUN_140107510 (size=58) ============


undefined8 FUN_140107510(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x438) + 0x90);

  if ((lVar1 != 0) &&

     (1 < (ulonglong)(*(longlong *)(lVar1 + 0x138) - *(longlong *)(lVar1 + 0x130) >> 3))) {

    return *(undefined8 *)(*(longlong *)(lVar1 + 0x138) + -8);

  }

  return 0;

}




