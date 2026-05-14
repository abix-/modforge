// Address: 0x140178ae0
// Ghidra name: FUN_140178ae0
// ============ 0x140178ae0 FUN_140178ae0 (size=74) ============


void FUN_140178ae0(longlong param_1,undefined8 *param_2)



{

  undefined8 *puVar1;

  undefined8 local_38 [7];

  

  puVar1 = local_38;

  if (param_2 != (undefined8 *)0x0) {

    puVar1 = param_2;

  }

  *puVar1 = 0;

  puVar1[1] = 0;

  puVar1[2] = 0;

  puVar1[3] = 0;

  puVar1[4] = 0;

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140335b8c);

    return;

  }

  FUN_14021d110(0,puVar1);

  return;

}




