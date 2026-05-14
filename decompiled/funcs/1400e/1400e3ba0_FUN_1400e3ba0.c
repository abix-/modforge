// Address: 0x1400e3ba0
// Ghidra name: FUN_1400e3ba0
// ============ 0x1400e3ba0 FUN_1400e3ba0 (size=88) ============


undefined8 * FUN_1400e3ba0(undefined8 *param_1,uint param_2)



{

  undefined8 *puVar1;

  

  *param_1 = &PTR_FUN_14030f060;

  puVar1 = (undefined8 *)param_1[0x8b];

  if (puVar1 != (undefined8 *)0x0) {

    (**(code **)*puVar1)(puVar1,1);

  }

  FUN_1400c97f0(param_1);

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,0x478);

  }

  return param_1;

}




