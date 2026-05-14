// Address: 0x1402eb620
// Ghidra name: FUN_1402eb620
// ============ 0x1402eb620 FUN_1402eb620 (size=195) ============


void FUN_1402eb620(uint param_1)



{

  uint uVar1;

  uint uVar2;

  undefined4 *puVar3;

  uint uVar4;

  uint local_res8 [2];

  uint local_res10 [2];

  

  local_res10[0] = 0;

  FUN_1402f6600(local_res10,0x1f);

  local_res8[0] = local_res10[0];

  uVar1 = param_1 | 0x20;

  if ((param_1 & 0x18) == 0) {

    uVar1 = param_1;

  }

  uVar4 = uVar1 >> 5 & 1;

  uVar2 = uVar4 | 2;

  if ((uVar1 & 0x10) == 0) {

    uVar2 = uVar4;

  }

  uVar4 = uVar2 | 4;

  if ((uVar1 & 8) == 0) {

    uVar4 = uVar2;

  }

  uVar2 = uVar4 | 8;

  if ((uVar1 & 4) == 0) {

    uVar2 = uVar4;

  }

  uVar4 = uVar2 | 0x10;

  if ((uVar1 & 1) == 0) {

    uVar4 = uVar2;

  }

  uVar2 = FUN_1402f67c0(uVar4);

  local_res8[0] = local_res8[0] | uVar2;

  FUN_1402f6650(local_res8,0x1f);

  if ((uVar1 & 1) != 0) {

    puVar3 = (undefined4 *)FUN_1402e68b0();

    *puVar3 = 0x21;

    return;

  }

  if ((uVar1 & 0x1c) != 0) {

    puVar3 = (undefined4 *)FUN_1402e68b0();

    *puVar3 = 0x22;

  }

  return;

}




