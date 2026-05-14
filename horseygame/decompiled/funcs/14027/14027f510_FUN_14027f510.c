// Address: 0x14027f510
// Ghidra name: FUN_14027f510
// ============ 0x14027f510 FUN_14027f510 (size=112) ============


bool FUN_14027f510(longlong param_1,undefined1 param_2)



{

  int iVar1;

  undefined2 local_res8;

  undefined1 local_resa;

  undefined4 local_resb;

  

  local_resa = 0;

  switch(param_2) {

  case 1:

    local_resa = 1;

    break;

  case 2:

    local_resa = 3;

    break;

  case 3:

    local_resa = 7;

    break;

  case 4:

    local_resa = 0xf;

    break;

  case 5:

    local_resa = 0x1f;

  }

  local_res8 = 0x12f8;

  local_resb = 0;

  iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,7);

  return iVar1 == 7;

}




