// Address: 0x14021ab50
// Ghidra name: FUN_14021ab50
// ============ 0x14021ab50 FUN_14021ab50 (size=58) ============


undefined8 FUN_14021ab50(undefined8 param_1)



{

  ulonglong uVar1;

  

  uVar1 = (ulonglong)DAT_1403fdb60 >> 8;

  if (DAT_1403fdb60 == 0) {

    DAT_1403fdb68 = DAT_1403fdb68 + 1;

    DAT_1403fdb58 = param_1;

    DAT_1403fdb60 = param_1;

    return 1;

  }

  DAT_1403fdb68 = DAT_1403fdb68 + 1;

  *(undefined8 *)(DAT_1403fdb60 + 0x490) = param_1;

  DAT_1403fdb60 = param_1;

  return CONCAT71((int7)uVar1,1);

}




