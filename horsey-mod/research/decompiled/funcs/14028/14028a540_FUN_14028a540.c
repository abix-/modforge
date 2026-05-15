// Address: 0x14028a540
// Ghidra name: FUN_14028a540
// ============ 0x14028a540 FUN_14028a540 (size=86) ============


void FUN_14028a540(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  if (lVar1 != 0) {

    FUN_140218f20(param_1,*(undefined8 *)(lVar1 + 8));

    FUN_1401841e0(lVar1);

    *(undefined8 *)(param_2 + 0x188) = 0;

    return;

  }

  *(undefined8 *)(param_2 + 0x188) = 0;

  return;

}




