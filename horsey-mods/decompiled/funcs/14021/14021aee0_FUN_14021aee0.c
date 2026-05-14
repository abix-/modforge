// Address: 0x14021aee0
// Ghidra name: FUN_14021aee0
// ============ 0x14021aee0 FUN_14021aee0 (size=81) ============


bool FUN_14021aee0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  

  lVar1 = *(longlong *)(param_2 + 0x10);

  uVar2 = *(undefined8 *)(param_2 + 0x490);

  if (param_1 != 0) {

    *(undefined8 *)(param_1 + 0x490) = *(undefined8 *)(param_2 + 0x490);

    uVar2 = DAT_1403fdb58;

  }

  DAT_1403fdb58 = uVar2;

  if (param_2 == DAT_1403fdb60) {

    DAT_1403fdb60 = param_1;

  }

  DAT_1403fdb68 = DAT_1403fdb68 + -1;

  FUN_1401841e0(param_2);

  return lVar1 != 0;

}




