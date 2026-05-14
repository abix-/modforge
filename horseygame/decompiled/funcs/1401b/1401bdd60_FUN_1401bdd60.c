// Address: 0x1401bdd60
// Ghidra name: FUN_1401bdd60
// ============ 0x1401bdd60 FUN_1401bdd60 (size=253) ============


undefined1 FUN_1401bdd60(longlong param_1,longlong param_2,int *param_3)



{

  int iVar1;

  undefined1 uVar2;

  

  iVar1 = *param_3;

  uVar2 = 0;

  if (iVar1 < 0x3b9c0e39) {

    if (iVar1 == 0x3b9c0e38) {

      *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | param_3[4];

      *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | param_3[5];

      *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | param_3[6];

      *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | param_3[7];

      return 1;

    }

    if (iVar1 == 0x3b9b9909) {

      *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | param_3[4];

      *(uint *)(param_2 + 0x24) = *(uint *)(param_2 + 0x24) | param_3[5];

      *(uint *)(param_2 + 0x28) = *(uint *)(param_2 + 0x28) | param_3[6];

      return 1;

    }

    if (iVar1 == 0x3b9bb078) {

      FUN_1401b29f0(param_1,param_1 + 0xd8,param_3 + 4);

      return 1;

    }

    if (iVar1 == 0x3b9bc018) {

      *(uint *)(param_2 + 0x3c) = *(uint *)(param_2 + 0x3c) | param_3[4];

      return 1;

    }

  }

  else if (iVar1 == 0x3b9c9ec0) {

    uVar2 = 1;

    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) | param_3[5];

    *(uint *)(param_2 + 0x2c) = *(uint *)(param_2 + 0x2c) | param_3[4];

  }

  else {

    if (iVar1 == 0x3b9d0069) {

      *(uint *)(param_2 + 0x34) = *(uint *)(param_2 + 0x34) | param_3[4];

      return 1;

    }

    if (iVar1 == 0x3b9d2b64) {

      *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | param_3[4];

      return 1;

    }

  }

  return uVar2;

}




