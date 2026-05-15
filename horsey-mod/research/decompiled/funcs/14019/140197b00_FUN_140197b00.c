// Address: 0x140197b00
// Ghidra name: FUN_140197b00
// ============ 0x140197b00 FUN_140197b00 (size=236) ============


uint FUN_140197b00(int *param_1,ulonglong param_2,uint param_3)



{

  int iVar1;

  longlong lVar2;

  uint uVar3;

  ulonglong uVar4;

  

  uVar4 = param_2 >> 2;

  if (((ulonglong)param_1 & 3) == 0) {

    for (; uVar4 != 0; uVar4 = uVar4 - 1) {

      iVar1 = *param_1;

      param_1 = param_1 + 1;

      param_3 = param_3 ^ ((uint)(iVar1 * -0x3361d2af) >> 0x11 | iVar1 * 0x16a88000) * 0x1b873593;

      param_3 = ((param_3 >> 0x13 | param_3 << 0xd) + 0xfaddaf14) * 5;

    }

  }

  else {

    for (; uVar4 != 0; uVar4 = uVar4 - 1) {

      iVar1 = *param_1;

      param_1 = param_1 + 1;

      param_3 = param_3 ^ ((uint)(iVar1 * -0x3361d2af) >> 0x11 | iVar1 * 0x16a88000) * 0x1b873593;

      param_3 = ((param_3 >> 0x13 | param_3 << 0xd) + 0xfaddaf14) * 5;

    }

  }

  uVar4 = (ulonglong)((uint)param_2 & 3);

  if ((param_2 & 3) != 0) {

    uVar3 = 0;

    do {

      lVar2 = uVar4 - 1;

      uVar4 = uVar4 - 1;

      uVar3 = uVar3 << 8 | (uint)*(byte *)((longlong)param_1 + lVar2);

    } while (uVar4 != 0);

    param_3 = param_3 ^ (uVar3 * -0x3361d2af >> 0x11 | uVar3 * 0x16a88000) * 0x1b873593;

  }

  param_3 = (uint)param_2 ^ param_3;

  uVar3 = (param_3 >> 0x10 ^ param_3) * -0x7a143595;

  uVar3 = (uVar3 >> 0xd ^ uVar3) * -0x3d4d51cb;

  return uVar3 >> 0x10 ^ uVar3;

}




