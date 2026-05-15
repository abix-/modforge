// Address: 0x14028b000
// Ghidra name: FUN_14028b000
// ============ 0x14028b000 FUN_14028b000 (size=158) ============


int FUN_14028b000(longlong param_1)



{

  ushort uVar1;

  ulonglong uVar2;

  int iVar3;

  int iVar4;

  

  iVar4 = (int)*(short *)(param_1 + 0x1e);

  uVar2 = *(ulonglong *)(param_1 + 0x68);

  if (uVar2 < *(ushort *)(param_1 + 0x20)) {

    iVar3 = ((iVar4 >> 0x1f & 0xfffffffeU) + 1) * (uint)*(ushort *)(param_1 + 0x22);

    iVar4 = iVar3 + (int)(((longlong)(iVar4 - iVar3) * uVar2) /

                         (ulonglong)*(ushort *)(param_1 + 0x20));

  }

  else if ((*(int *)(param_1 + 0x14) != 0) && (uVar1 = *(ushort *)(param_1 + 0x24), uVar1 != 0)) {

    iVar3 = ((uint)uVar1 - *(int *)(param_1 + 0x14)) + (int)uVar2;

    if (0 < iVar3) {

      iVar4 = iVar4 - (int)((iVar4 - ((iVar4 >> 0x1f & 0xfffffffeU) + 1) *

                                     (uint)*(ushort *)(param_1 + 0x26)) * iVar3) / (int)(uint)uVar1;

    }

  }

  return (int)((double)iVar4 * *(double *)(param_1 + 0x88));

}




