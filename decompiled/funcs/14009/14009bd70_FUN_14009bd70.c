// Address: 0x14009bd70
// Ghidra name: FUN_14009bd70
// ============ 0x14009bd70 FUN_14009bd70 (size=238) ============


undefined8 * FUN_14009bd70(undefined8 *param_1,uint param_2)



{

  undefined8 *puVar1;

  longlong lVar2;

  

  *param_1 = &PTR_FUN_14030bb30;

  if (param_1[0x26] != param_1[0x27]) {

    param_1[0x27] = param_1[0x26];

  }

  puVar1 = (undefined8 *)param_1[0x75];

  if (puVar1 != (undefined8 *)0x0) {

    (**(code **)*puVar1)(puVar1,1);

  }

  lVar2 = param_1[0x65];

  if (lVar2 != 0) {

    FUN_1400c8d80(lVar2);

    FUN_1402c7088(lVar2,0x1f48);

  }

  FUN_140027900(param_1 + 0x76);

  FUN_140030810(param_1 + 0x6f);

  FUN_140030810(param_1 + 0x6c);

  FUN_140030810(param_1 + 0x69);

  FUN_140030810(param_1 + 0x66);

  FUN_140027900(param_1 + 0x60);

  FUN_14009bbf0(param_1 + 0x50);

  FUN_1400c97f0(param_1);

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,1000);

  }

  return param_1;

}




