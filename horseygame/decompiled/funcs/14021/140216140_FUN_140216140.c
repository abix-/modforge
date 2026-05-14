// Address: 0x140216140
// Ghidra name: FUN_140216140
// ============ 0x140216140 FUN_140216140 (size=176) ============


void FUN_140216140(undefined8 param_1,undefined8 param_2)



{

  int iVar1;

  undefined1 local_38 [16];

  undefined1 local_28 [8];

  undefined8 local_20;

  undefined1 *local_18;

  

  if (DAT_1403fdaf0 != '\0') {

    FUN_140289af0(param_1,param_2,0,0);

    return;

  }

  local_28[0] = 1;

  local_20 = param_2;

  iVar1 = (*DAT_1403fdb20)(&DAT_140353d28,local_38);

  local_18 = local_38;

  if (iVar1 != 0) {

    local_18 = (undefined1 *)0x0;

  }

  (*DAT_1403fdb18)(FUN_140216b50,local_28);

  local_28[0] = 0;

  local_20 = param_1;

  iVar1 = (*DAT_1403fdb20)(&DAT_140353d18,local_38);

  local_18 = local_38;

  if (iVar1 != 0) {

    local_18 = (undefined1 *)0x0;

  }

  (*DAT_1403fdb08)(FUN_140216b50,local_28);

  return;

}




