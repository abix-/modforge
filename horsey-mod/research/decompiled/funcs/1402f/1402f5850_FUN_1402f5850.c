// Address: 0x1402f5850
// Ghidra name: FUN_1402f5850
// ============ 0x1402f5850 FUN_1402f5850 (size=346) ============


int FUN_1402f5850(byte *param_1,byte *param_2,ulonglong param_3,undefined8 *param_4)



{

  byte bVar1;

  int iVar2;

  undefined4 *puVar3;

  longlong local_28;

  undefined *local_20;

  undefined8 uStack_18;

  char local_10;

  

  if (((param_1 == (byte *)0x0) || (param_2 == (byte *)0x0)) || (0x7fffffff < param_3)) {

    puVar3 = (undefined4 *)FUN_1402e68b0();

    *puVar3 = 0x16;

    FUN_1402cd454();

    return 0x7fffffff;

  }

  if (param_3 == 0) {

    return 0;

  }

  local_10 = '\0';

  if (param_4 == (undefined8 *)0x0) {

    if (DAT_1403ff13c == 0) {

      local_20 = PTR_PTR_1403e8e88;

      local_10 = '\0';

    }

    else {

      local_28 = FUN_1402e8664();

      local_20 = *(undefined **)(local_28 + 0x90);

      uStack_18 = *(undefined8 *)(local_28 + 0x88);

      __acrt_update_locale_info(local_28,&local_20);

      FUN_1402eef30(local_28,&uStack_18);

      if ((*(uint *)(local_28 + 0x3a8) & 2) == 0) {

        local_10 = '\x01';

        *(uint *)(local_28 + 0x3a8) = *(uint *)(local_28 + 0x3a8) | 2;

      }

    }

  }

  else {

    local_20 = (undefined *)*param_4;

    local_10 = '\0';

  }

  do {

    bVar1 = *param_1;

    param_1 = param_1 + 1;

    bVar1 = *(byte *)((ulonglong)bVar1 + *(longlong *)(local_20 + 0x110));

    iVar2 = (uint)bVar1 - (uint)*(byte *)((ulonglong)*param_2 + *(longlong *)(local_20 + 0x110));

    if ((iVar2 != 0) || (bVar1 == 0)) break;

    param_3 = param_3 - 1;

    param_2 = param_2 + 1;

  } while (param_3 != 0);

  if (local_10 != '\0') {

    *(uint *)(local_28 + 0x3a8) = *(uint *)(local_28 + 0x3a8) & 0xfffffffd;

  }

  return iVar2;

}




