// Address: 0x1400e99f0
// Ghidra name: FUN_1400e99f0
// ============ 0x1400e99f0 FUN_1400e99f0 (size=108) ============


int FUN_1400e99f0(uint param_1)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  

  if (param_1 != 0) {

    uVar2 = param_1 >> 0x10;

    if (param_1 < 0x10000) {

      uVar2 = param_1;

    }

    iVar3 = 0x10;

    if (param_1 < 0x10000) {

      iVar3 = 0;

    }

    if (0xff < uVar2) {

      iVar3 = iVar3 + 8;

      uVar2 = uVar2 >> 8;

    }

    uVar4 = uVar2 >> 4;

    iVar1 = iVar3 + 4;

    if (uVar2 < 0x10) {

      uVar4 = uVar2;

      iVar1 = iVar3;

    }

    iVar3 = iVar1 + 2;

    if (uVar4 < 4) {

      iVar3 = iVar1;

    }

    uVar2 = uVar4 >> 2;

    if (uVar4 < 4) {

      uVar2 = uVar4;

    }

    iVar1 = iVar3 + 1;

    if (uVar2 < 2) {

      iVar1 = iVar3;

    }

    return iVar1;

  }

  return -1;

}




