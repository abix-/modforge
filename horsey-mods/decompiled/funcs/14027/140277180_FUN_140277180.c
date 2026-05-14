// Address: 0x140277180
// Ghidra name: FUN_140277180
// ============ 0x140277180 FUN_140277180 (size=97) ============


undefined8 FUN_140277180(undefined8 param_1,undefined1 param_2)



{

  int iVar1;

  undefined8 uVar2;

  ulonglong local_58 [8];

  undefined1 local_18;

  

  local_58[1] = 0;

  local_18 = 0;

  local_58[2] = 0;

  local_58[3] = 0;

  local_58[4] = 0;

  local_58[5] = 0;

  local_58[0] = (ulonglong)CONCAT14(param_2,0x2d038700);

  local_58[6] = 0;

  local_58[7] = 0;

  iVar1 = FUN_140277070(0,local_58,6);

  if (iVar1 < 0) {

    uVar2 = FUN_14012e850("Couldn\'t write feature report");

    return uVar2;

  }

  return 1;

}




