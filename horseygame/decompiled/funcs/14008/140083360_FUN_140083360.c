// Address: 0x140083360
// Ghidra name: FUN_140083360
// ============ 0x140083360 FUN_140083360 (size=88) ============


undefined8 * FUN_140083360(undefined8 *param_1,uint param_2)



{

  undefined8 *puVar1;

  

  *param_1 = &PTR_FUN_14030ac90;

  puVar1 = (undefined8 *)param_1[0x10];

  if (puVar1 != (undefined8 *)0x0) {

    (**(code **)*puVar1)(puVar1,1);

  }

  FUN_1400a8730(param_1);

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,200);

  }

  return param_1;

}




