// Address: 0x14013aa50
// Ghidra name: FUN_14013aa50
// ============ 0x14013aa50 FUN_14013aa50 (size=102) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool FUN_14013aa50(longlong *param_1,undefined8 *param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  

  FUN_140179b40(DAT_1403fb660);

  uVar2 = _DAT_1403fb670;

  lVar1 = _DAT_1403fb668;

  FUN_140179b60(DAT_1403fb660);

  if (param_1 != (longlong *)0x0) {

    *param_1 = lVar1;

  }

  if (param_2 != (undefined8 *)0x0) {

    *param_2 = uVar2;

  }

  return lVar1 != 0;

}




