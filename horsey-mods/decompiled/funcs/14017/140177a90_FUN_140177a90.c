// Address: 0x140177a90
// Ghidra name: FUN_140177a90
// ============ 0x140177a90 FUN_140177a90 (size=146) ============


void FUN_140177a90(longlong param_1,undefined1 *param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  undefined1 *puVar2;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid storage container");

    return;

  }

  puVar2 = &DAT_14039bcb9;

  if (param_2 != (undefined1 *)0x0) {

    puVar2 = param_2;

  }

  cVar1 = FUN_1401784e0(puVar2);

  if (cVar1 != '\0') {

    if (*(code **)(param_1 + 0x18) == (code *)0x0) {

      FUN_14012e850("That operation is not supported");

    }

    else {

      (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x60),puVar2,param_3,param_4);

    }

  }

  return;

}




