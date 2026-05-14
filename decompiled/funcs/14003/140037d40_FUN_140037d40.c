// Address: 0x140037d40
// Ghidra name: FUN_140037d40
// ============ 0x140037d40 FUN_140037d40 (size=95) ============


void FUN_140037d40(undefined8 *param_1)



{

  undefined8 *puVar1;

  

  *param_1 = &PTR_FUN_140304578;

  FUN_140039010();

  puVar1 = (undefined8 *)param_1[0x4d];

  if (puVar1 != (undefined8 *)0x0) {

    (**(code **)*puVar1)(puVar1,1);

  }

  FUN_1400c8d80(param_1 + 0x5e);

  FUN_140030810(param_1 + 0x56);

  FUN_1400371c0(param_1 + 0x50);

  FUN_1400c97f0(param_1);

  return;

}




