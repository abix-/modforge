// Address: 0x1402f8060
// Ghidra name: FUN_1402f8060
// ============ 0x1402f8060 FUN_1402f8060 (size=92) ============


int FUN_1402f8060(uint *param_1)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  

  iVar2 = 1;

  uVar5 = *param_1 & 0x80000000;

  uVar3 = *param_1 & 0x7fffff;

  uVar4 = 0;

  if (uVar3 != 0) {

    iVar1 = 0x1f;

    if (uVar3 != 0) {

      for (; uVar3 >> iVar1 == 0; iVar1 = iVar1 + -1) {

      }

    }

    if (uVar3 == 0) {

      *param_1 = uVar5;

      return -0x16;

    }

    iVar2 = iVar1 + -0x16;

    uVar4 = uVar3 << (0x17U - (char)iVar1 & 0x1f) & 0x7fffff;

  }

  *param_1 = uVar5 | uVar4;

  return iVar2;

}




