// Address: 0x140279f50
// Ghidra name: FUN_140279f50
// ============ 0x140279f50 FUN_140279f50 (size=104) ============


void FUN_140279f50(longlong param_1)



{

  uint uVar1;

  undefined1 local_res8;

  byte local_res9;

  

  local_res9 = *(byte *)(param_1 + 0x28);

  if (*(char *)(param_1 + 0x20) != '\0') {

    uVar1 = *(uint *)(param_1 + 0x24);

    if ((uVar1 == 0) || (3 < (int)uVar1)) {

      local_res9 = local_res9 | 0x10;

    }

    if ((uVar1 == 1) || (uVar1 == 4)) {

      local_res9 = local_res9 | 0x20;

    }

    if ((uVar1 == 2) || (uVar1 == 5)) {

      local_res9 = local_res9 | 0x40;

    }

    if ((uVar1 == 3) || (uVar1 == 6)) {

      local_res9 = local_res9 | 0x80;

    }

    if (6 < uVar1) {

      local_res9 = local_res9 | 0xf0;

    }

  }

  local_res8 = 0x11;

  FUN_140279fc0(param_1,&local_res8,2,0);

  return;

}




