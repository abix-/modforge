// Address: 0x14027c510
// Ghidra name: FUN_14027c510
// ============ 0x14027c510 FUN_14027c510 (size=118) ============


void FUN_14027c510(undefined8 *param_1,longlong param_2)



{

  longlong lVar1;

  undefined1 *puVar2;

  undefined1 *puVar3;

  undefined1 local_28 [28];

  undefined1 local_c;

  

  puVar3 = (undefined1 *)(param_2 + 2);

  puVar2 = local_28;

  lVar1 = 0xe;

  do {

    thunk_FUN_14012f5e0(*puVar3,puVar2,0x10);

    puVar2 = puVar2 + 2;

    puVar3 = puVar3 + 1;

    lVar1 = lVar1 + -1;

  } while (lVar1 != 0);

  local_c = 0;

  FUN_140208490(*param_1,local_28);

  return;

}




