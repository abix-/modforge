// Address: 0x1402f7fe0
// Ghidra name: FUN_1402f7fe0
// ============ 0x1402f7fe0 FUN_1402f7fe0 (size=114) ============


short FUN_1402f7fe0(ulonglong *param_1)



{

  longlong lVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  short sVar5;

  

  uVar4 = *param_1 & 0x8000000000000000;

  sVar5 = 1;

  uVar2 = *param_1 & 0xfffffffffffff;

  uVar3 = 0;

  if (uVar2 != 0) {

    lVar1 = 0x3f;

    if (uVar2 != 0) {

      for (; uVar2 >> lVar1 == 0; lVar1 = lVar1 + -1) {

      }

    }

    if (uVar2 == 0) {

      *param_1 = uVar4;

      return -0x33;

    }

    sVar5 = (short)lVar1 + -0x33;

    uVar3 = uVar2 << (0x34U - (char)lVar1 & 0x3f) & 0xfffffffffffff;

  }

  *param_1 = uVar4 | uVar3;

  return sVar5;

}




