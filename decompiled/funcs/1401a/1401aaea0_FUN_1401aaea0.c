// Address: 0x1401aaea0
// Ghidra name: FUN_1401aaea0
// ============ 0x1401aaea0 FUN_1401aaea0 (size=59) ============


uint FUN_1401aaea0(uint param_1)



{

  int iVar1;

  uint uVar2;

  byte bVar3;

  uint uVar4;

  

  if ((int)param_1 < 1) {

    return 4;

  }

  iVar1 = 0x1f;

  if (param_1 != 0) {

    for (; param_1 >> iVar1 == 0; iVar1 = iVar1 + -1) {

    }

  }

  bVar3 = 0xff;

  if (param_1 != 0) {

    bVar3 = (byte)iVar1;

  }

  uVar4 = 1 << (bVar3 & 0x1f);

  if ((param_1 & param_1 - 1) != 0) {

    uVar4 = 2 << (bVar3 & 0x1f);

  }

  uVar2 = 0x4000000;

  if (uVar4 < 0x4000000) {

    uVar2 = uVar4;

  }

  return uVar2;

}




