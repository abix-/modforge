// Address: 0x140268af0
// Ghidra name: FUN_140268af0
// ============ 0x140268af0 FUN_140268af0 (size=113) ============


void FUN_140268af0(longlong param_1,undefined8 param_2,byte param_3,byte param_4,byte param_5)



{

  longlong lVar1;

  byte bVar2;

  bool bVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (*(int *)(lVar1 + 0x20) == 3) {

    bVar3 = *(char *)(lVar1 + 0x10) == '\0';

  }

  else {

    bVar3 = *(int *)(lVar1 + 0x20) == 2;

  }

  if (!bVar3) {

    FUN_14012e850("That operation is not supported");

    return;

  }

  bVar2 = param_4;

  if (param_4 <= param_5) {

    bVar2 = param_5;

  }

  if ((param_3 <= bVar2) && (param_3 = param_5, param_5 < param_4)) {

    param_3 = param_4;

  }

  FUN_14026ce50(lVar1,(int)(((float)param_3 / DAT_14030a2d0) * DAT_14039ca5c));

  return;

}




