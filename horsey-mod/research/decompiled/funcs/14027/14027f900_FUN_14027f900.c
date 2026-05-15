// Address: 0x14027f900
// Ghidra name: FUN_14027f900
// ============ 0x14027f900 FUN_14027f900 (size=167) ============


bool FUN_14027f900(longlong param_1,ushort param_2)



{

  int iVar1;

  undefined4 local_res18;

  undefined2 local_res1c;

  undefined1 local_res1e;

  

  switch(param_2 - 0xc24f) {

  case 0:

    local_res18 = 0x10509f8;

    local_res1c = 1;

    goto LAB_14027f979;

  default:

    return true;

  case 0x45:

    local_res18 = 0x10009f8;

    break;

  case 0x49:

    local_res18 = 0x1f8;

    break;

  case 0x4a:

    local_res18 = 0x10f8;

    break;

  case 0x4b:

    local_res18 = 0x10309f8;

    break;

  case 0x4c:

    local_res18 = 0x10409f8;

  }

  local_res1c = 0;

LAB_14027f979:

  local_res1e = 0;

  iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res18,7);

  return iVar1 != -1;

}




