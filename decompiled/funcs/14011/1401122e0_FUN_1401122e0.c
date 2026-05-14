// Address: 0x1401122e0
// Ghidra name: FUN_1401122e0
// ============ 0x1401122e0 FUN_1401122e0 (size=259) ============


undefined8 * FUN_1401122e0(undefined8 *param_1,ulonglong param_2)



{

  undefined8 *puVar1;

  longlong lVar2;

  

  *param_1 = &PTR_FUN_140313558;

  if (param_1[0x4e] != 0) {

    FUN_1402c7088();

  }

  lVar2 = 0;

  do {

    puVar1 = *(undefined8 **)(lVar2 + param_1[0x87]);

    if (puVar1 != (undefined8 *)0x0) {

      (**(code **)*puVar1)(puVar1,1);

    }

    lVar2 = lVar2 + 8;

  } while (lVar2 < 0x180);

  FUN_1402c7088(param_1[0x87]);

  if (DAT_1403f4e00 != (undefined8 *)0x0) {

    (**(code **)*DAT_1403f4e00)(DAT_1403f4e00,1);

  }

  DAT_1403f4e00 = (undefined8 *)0x0;

  DAT_1403fb0d8 = 0;

  FUN_14003f680();

  FUN_140030810(param_1 + 0x84);

  FUN_140087ec0(param_1 + 0x7f);

  FUN_140112210(param_1 + 0x79);

  FUN_140112180(param_1 + 0x50);

  FUN_1400c97f0(param_1);

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,0x448);

  }

  return param_1;

}




