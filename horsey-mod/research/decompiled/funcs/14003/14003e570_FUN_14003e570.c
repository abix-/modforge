// Address: 0x14003e570
// Ghidra name: FUN_14003e570
// ============ 0x14003e570 FUN_14003e570 (size=130) ============


undefined8 * FUN_14003e570(undefined8 *param_1,ulonglong param_2)



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

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,0x2268);

  }

  return param_1;

}




