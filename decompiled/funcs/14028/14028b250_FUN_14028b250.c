// Address: 0x14028b250
// Ghidra name: FUN_14028b250
// ============ 0x14028b250 FUN_14028b250 (size=190) ============


int FUN_14028b250(longlong param_1)



{

  ushort uVar1;

  ushort uVar2;

  int iVar3;

  ulonglong uVar4;

  int iVar5;

  int iVar6;

  

  uVar1 = *(ushort *)(param_1 + 0x22);

  uVar4 = *(ulonglong *)(param_1 + 0x68);

  iVar5 = (int)uVar4;

  if (uVar4 < uVar1) {

    iVar6 = (((int)*(short *)(param_1 + 0x1e) >> 0x1f & 0xfffffffeU) + 1) *

            (uint)*(ushort *)(param_1 + 0x24);

    iVar6 = iVar6 + (int)((*(short *)(param_1 + 0x1e) - iVar6) * ((uint)uVar1 - iVar5)) /

                    (int)(uint)uVar1;

  }

  else {

    iVar3 = *(int *)(param_1 + 0x14);

    if (iVar3 != 0) {

      uVar2 = *(ushort *)(param_1 + 0x26);

      if ((iVar3 - (uint)uVar2 <= uVar4) && (uVar2 != 0)) {

        iVar6 = (int)*(short *)(param_1 + 0x20);

        iVar6 = iVar6 - (int)((((iVar6 >> 0x1f & 0xfffffffeU) + 1) *

                               (uint)*(ushort *)(param_1 + 0x28) - iVar6) *

                             ((iVar5 - iVar3) + (uint)uVar2)) / (int)(uint)uVar2;

        goto LAB_14028b2f7;

      }

    }

    iVar6 = ((int)((iVar5 - (uint)uVar1) * *(int *)(param_1 + 0x90)) >> 0x10) +

            (int)*(short *)(param_1 + 0x1e);

  }

LAB_14028b2f7:

  return (int)((double)iVar6 * *(double *)(param_1 + 0x88));

}




