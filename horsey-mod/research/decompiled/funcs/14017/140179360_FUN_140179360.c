// Address: 0x140179360
// Ghidra name: FUN_140179360
// ============ 0x140179360 FUN_140179360 (size=207) ============


longlong FUN_140179360(undefined8 *param_1)



{

  longlong lVar1;

  longlong local_38;

  longlong local_30;

  longlong local_28;

  longlong local_20;

  longlong local_18;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140335bb8);

    return 0;

  }

  FUN_140179b40(*param_1);

  local_38 = 0;

  local_30 = 0;

  FUN_1401ab210(param_1[1],FUN_140179100,&local_38);

  lVar1 = FUN_1401841f0(local_30 + 8 + local_38 * 8);

  if (lVar1 != 0) {

    local_18 = 0;

    local_20 = lVar1 + (local_38 + 1) * 8;

    local_28 = lVar1;

    FUN_1401ab210(param_1[1],FUN_140179060,&local_28);

    *(undefined8 *)(lVar1 + local_18 * 8) = 0;

  }

  FUN_140179b60(*param_1);

  return lVar1;

}




