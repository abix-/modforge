// Address: 0x14007b260
// Ghidra name: FUN_14007b260
// ============ 0x14007b260 FUN_14007b260 (size=108) ============


undefined1 FUN_14007b260(longlong param_1)



{

  longlong lVar1;

  

  if (8 < *(int *)(param_1 + 0x274)) {

    *(undefined1 *)(param_1 + 0x2a8) = 1;

    lVar1 = thunk_FUN_1402c62d0(*(undefined8 *)(param_1 + 0x130),*(undefined8 *)(param_1 + 0x138),

                                *(undefined8 *)(param_1 + 0x268));

    FUN_1402f8e20(lVar1,lVar1 + 8,*(longlong *)(param_1 + 0x138) - (lVar1 + 8));

    *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + -8;

    *(undefined8 *)(param_1 + 0x268) = 0;

    return 1;

  }

  return 0;

}




