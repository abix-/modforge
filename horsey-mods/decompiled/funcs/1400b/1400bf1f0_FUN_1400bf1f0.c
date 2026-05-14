// Address: 0x1400bf1f0
// Ghidra name: FUN_1400bf1f0
// ============ 0x1400bf1f0 FUN_1400bf1f0 (size=195) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 * FUN_1400bf1f0(undefined8 *param_1,ulonglong param_2)



{

  longlong lVar1;

  undefined8 *puVar2;

  

  *param_1 = &PTR_FUN_14030d660;

  _DAT_1403f311c = _DAT_1403f311c + -1;

  lVar1 = param_1[0x3e];

  if (lVar1 != 0) {

    FUN_1400c8d80(lVar1);

    FUN_1402c7088(lVar1,0x1f48);

  }

  puVar2 = (undefined8 *)param_1[0x48];

  if (puVar2 != (undefined8 *)0x0) {

    (**(code **)*puVar2)(puVar2,1);

  }

  FUN_140027900(param_1 + 0x51);

  FUN_140027900(param_1 + 0x31);

  FUN_140027900(param_1 + 0x2d);

  FUN_1400308d0(param_1 + 0x15);

  FUN_1400bf630(param_1 + 8);

  thunk_FUN_14002f010(param_1 + 5);

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,0x498);

  }

  return param_1;

}




