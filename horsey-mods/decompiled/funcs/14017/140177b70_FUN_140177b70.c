// Address: 0x140177b70
// Ghidra name: FUN_140177b70
// ============ 0x140177b70 FUN_140177b70 (size=215) ============


void FUN_140177b70(longlong param_1,longlong param_2,undefined8 *param_3)



{

  char cVar1;

  undefined8 *puVar2;

  undefined8 local_38 [6];

  

  puVar2 = local_38;

  if (param_3 != (undefined8 *)0x0) {

    puVar2 = param_3;

  }

  *puVar2 = 0;

  puVar2[1] = 0;

  puVar2[2] = 0;

  puVar2[3] = 0;

  puVar2[4] = 0;

  if (param_1 == 0) {

    FUN_14012e850("Invalid storage container");

    return;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140335b8c);

    return;

  }

  cVar1 = FUN_1401784e0(param_2);

  if (cVar1 == '\0') {

    return;

  }

  if (*(code **)(param_1 + 0x20) == (code *)0x0) {

    FUN_14012e850("That operation is not supported");

    return;

  }

  (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x60),param_2,puVar2);

  return;

}




