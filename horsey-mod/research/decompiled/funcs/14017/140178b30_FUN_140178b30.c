// Address: 0x140178b30
// Ghidra name: FUN_140178b30
// ============ 0x140178b30 FUN_140178b30 (size=61) ============


undefined8 FUN_140178b30(undefined1 *param_1,longlong param_2)



{

  undefined8 uVar1;

  undefined1 *puVar2;

  

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140335bb4);

    return 0;

  }

  puVar2 = &DAT_14039bcb9;

  if (param_1 != (undefined1 *)0x0) {

    puVar2 = param_1;

  }

  uVar1 = FUN_14021c7c0(puVar2);

  return uVar1;

}




