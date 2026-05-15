// Address: 0x140193020
// Ghidra name: FUN_140193020
// ============ 0x140193020 FUN_140193020 (size=202) ============


undefined8 FUN_140193020(undefined2 param_1,undefined2 param_2)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  undefined8 local_res18;

  undefined8 local_res20;

  

  local_res18 = 0;

  local_res20 = 0;

  if ((DAT_1403fcd08 == 0) && (iVar2 = FUN_140193620(), iVar2 < 0)) {

    return 0;

  }

  lVar3 = FUN_1401926f0(param_1,param_2);

  lVar1 = lVar3;

  if (DAT_1403e3a5c == '\0') {

    for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x38)) {

      FUN_140192080(&DAT_14033ad3c,lVar1,&local_res18,&local_res20);

    }

  }

  else {

    for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x38)) {

      FUN_140192080("platform",lVar1,&local_res18,&local_res20);

    }

  }

  FUN_1401929b0(lVar3);

  return local_res18;

}




