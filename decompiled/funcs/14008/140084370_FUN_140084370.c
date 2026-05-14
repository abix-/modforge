// Address: 0x140084370
// Ghidra name: FUN_140084370
// ============ 0x140084370 FUN_140084370 (size=321) ============


undefined1 FUN_140084370(longlong param_1,float param_2)



{

  float fVar1;

  float fVar2;

  

  fVar2 = param_2 / DAT_140304014;

  if (*(int *)(param_1 + 8) != 2) {

    fVar1 = (float)FUN_14000b270();

    if (fVar2 < fVar1) {

      FUN_14000b2f0(param_1,(uint)param_2 ^ DAT_14039cac0);

      return 0;

    }

    if (fVar1 < (float)((uint)fVar2 ^ DAT_14039cac0)) {

      FUN_14000b2f0(param_1,param_2);

      return 0;

    }

    FUN_14000b2f0(param_1,((float)((uint)fVar1 ^ DAT_14039cac0) / DAT_140304014) * DAT_14039ca34);

    return 1;

  }

  fVar1 = (float)FUN_140009ca0();

  if (fVar2 < fVar1) {

    FUN_140009e60(param_1,(uint)param_2 ^ DAT_14039cac0);

    return 0;

  }

  if (fVar1 < (float)((uint)fVar2 ^ DAT_14039cac0)) {

    FUN_140009e60(param_1,param_2);

    return 0;

  }

  FUN_140009e60(param_1,((float)((uint)fVar1 ^ DAT_14039cac0) / DAT_140304014) * DAT_14039ca34);

  return 1;

}




