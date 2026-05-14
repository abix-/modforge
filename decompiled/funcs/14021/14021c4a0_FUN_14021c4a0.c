// Address: 0x14021c4a0
// Ghidra name: FUN_14021c4a0
// ============ 0x14021c4a0 FUN_14021c4a0 (size=64) ============


undefined8 FUN_14021c4a0(undefined1 *param_1,undefined1 *param_2)



{

  undefined1 *puVar1;

  undefined1 *puVar2;

  undefined8 local_res8 [4];

  

  local_res8[0] = 0;

  puVar2 = &DAT_14039bcb9;

  if (param_2 != (undefined1 *)0x0) {

    puVar2 = param_2;

  }

  puVar1 = &DAT_14039bcb9;

  if (param_1 != (undefined1 *)0x0) {

    puVar1 = param_1;

  }

  FUN_14012ee40(local_res8,&DAT_14031bb40,puVar1,puVar2);

  return local_res8[0];

}




