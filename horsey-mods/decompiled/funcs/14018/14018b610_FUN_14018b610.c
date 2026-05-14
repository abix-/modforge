// Address: 0x14018b610
// Ghidra name: FUN_14018b610
// ============ 0x14018b610 FUN_14018b610 (size=151) ============


undefined8

FUN_14018b610(undefined8 *param_1,undefined4 *param_2,undefined8 *param_3,undefined8 *param_4)



{

  char cVar1;

  undefined8 local_38;

  undefined4 local_30;

  undefined4 local_2c;

  undefined8 local_28;

  undefined8 local_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  local_38 = *param_1;

  local_30 = *param_2;

  local_28 = *param_3;

  local_20 = *param_4;

  local_2c = 0;

  local_18 = 0;

  uStack_10 = 0;

  cVar1 = (*DAT_1403fcba8)(DAT_1403fcbb0,&local_38);

  if (cVar1 != '\0') {

    *param_2 = local_30;

    *param_3 = local_28;

    *param_4 = local_20;

    return 1;

  }

  return 0;

}




