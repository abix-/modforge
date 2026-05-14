// Address: 0x140209f90
// Ghidra name: FUN_140209f90
// ============ 0x140209f90 FUN_140209f90 (size=419) ============


void FUN_140209f90(ushort *param_1,ulonglong param_2)



{

  ushort uVar1;

  uint uVar2;

  ushort uVar3;

  ushort uVar4;

  ushort uVar5;

  ushort uVar6;

  ushort uVar7;

  

  uVar1 = (ushort)(param_2 >> 0xc) & 0xf000;

  param_1[2] = uVar1;

  uVar6 = (ushort)(param_2 >> 8) & 0xf000;

  uVar4 = (ushort)(param_2 >> 4) & 0xf000;

  param_1[1] = uVar6;

  uVar7 = (ushort)(param_2 >> 0x10) & 0xf000;

  *param_1 = uVar4;

  param_1[3] = uVar7;

  uVar3 = (ushort)(param_2 >> 0x14) & 0xf000;

  uVar5 = (ushort)(param_2 >> 0x18) & 0xf000;

  param_1[4] = uVar3;

  param_1[5] = uVar5;

  *(bool *)(param_1 + 10) =

       uVar5 != 0x8000 ||

       (uVar3 != 0x8000 ||

       ((0x2000 < (int)(short)uVar1 + 0x1000U ||

        (0x2000 < (int)(short)uVar6 + 0x1000U || 0x2000 < (int)(short)uVar4 + 0x1000U)) ||

       0x2000 < (int)(short)uVar7 + 0x1000U));

  uVar1 = (ushort)(param_2 >> 1) & 0x3c0 | (ushort)(param_2 >> 0xb) & 0xf |

          (ushort)(param_2 >> 2) & 0x10 | (ushort)(param_2 << 0xc) | (ushort)(param_2 * 2) & 0x20;

  param_1[6] = uVar1;

  if (uVar1 != 0) {

    *(undefined1 *)(param_1 + 10) = 1;

  }

  uVar2 = (uint)(param_2 << 5) & 0x3000 | (uint)(param_2 >> 5) & 0x3c0 | (int)param_2 * 4 & 0x3cU |

          (uint)(param_2 >> 6) & 1 | (uint)(param_2 >> 3) & 2 | (uint)(param_2 * 2) & 0xc00;

  *(uint *)(param_1 + 8) = uVar2;

  if (uVar2 != 0) {

    *(undefined1 *)(param_1 + 10) = 1;

  }

  return;

}




