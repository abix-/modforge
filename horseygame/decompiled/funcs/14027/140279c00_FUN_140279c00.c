// Address: 0x140279c00
// Ghidra name: FUN_140279c00
// ============ 0x140279c00 FUN_140279c00 (size=151) ============


bool FUN_140279c00(longlong param_1,undefined4 param_2,undefined4 param_3,char param_4)



{

  char cVar1;

  undefined1 local_res8;

  byte local_res9;

  undefined1 local_resa;

  undefined1 local_resb;

  undefined1 local_resc;

  undefined1 local_resd;

  undefined1 local_rese;

  

  local_res9 = *(byte *)(param_1 + 0x28) | 4;

  local_resc = (undefined1)param_2;

  local_resa = (undefined1)((uint)param_2 >> 0x10);

  local_rese = (undefined1)param_3;

  local_resb = (undefined1)((uint)param_2 >> 8);

  local_resd = (undefined1)((uint)param_3 >> 8);

  local_res8 = 0x17;

  cVar1 = FUN_140279fc0(param_1,&local_res8,7);

  if (cVar1 == '\0') {

    return false;

  }

  if (param_4 != '\0') {

    cVar1 = FUN_140279b60(param_1,0x21,0);

    return cVar1 != '\0';

  }

  return true;

}




