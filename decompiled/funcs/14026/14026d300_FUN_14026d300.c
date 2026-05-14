// Address: 0x14026d300
// Ghidra name: FUN_14026d300
// ============ 0x14026d300 FUN_14026d300 (size=107) ============


void FUN_14026d300(longlong param_1)



{

  uint uVar1;

  undefined1 local_res8 [8];

  undefined4 local_res10;

  undefined4 local_res14;

  

  if (*(char *)(param_1 + 0x10) == '\0') {

    local_res8[0] = 0;

    local_res10 = 0xf070301;

    local_res14 = 0x60d0509;

    if ((*(char *)(param_1 + 0x12) != '\0') && (-1 < (int)*(uint *)(param_1 + 0x14))) {

      uVar1 = *(uint *)(param_1 + 0x14) & 0x80000007;

      if ((int)uVar1 < 0) {

        uVar1 = (uVar1 - 1 | 0xfffffff8) + 1;

      }

      local_res8[0] = *(undefined1 *)((longlong)&local_res10 + (longlong)(int)uVar1);

    }

    FUN_14026d5b0(param_1,0x30,local_res8,1,0);

  }

  return;

}




