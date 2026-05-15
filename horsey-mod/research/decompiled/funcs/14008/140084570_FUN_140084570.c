// Address: 0x140084570
// Ghidra name: FUN_140084570
// ============ 0x140084570 FUN_140084570 (size=60) ============


void FUN_140084570(longlong param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)



{

  longlong lVar1;

  undefined2 local_res8;

  undefined2 local_resa;

  undefined2 local_resc;

  

  local_res8 = param_3;

  local_resa = param_4;

  local_resc = param_2;

  for (lVar1 = *(longlong *)(param_1 + 0x70); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 8)) {

    FUN_1400082e0(lVar1,&local_res8);

  }

  return;

}




