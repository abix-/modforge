// Address: 0x1400f17a0
// Ghidra name: FUN_1400f17a0
// ============ 0x1400f17a0 FUN_1400f17a0 (size=273) ============


void FUN_1400f17a0(longlong param_1,int param_2,int *param_3,int *param_4)



{

  byte bVar1;

  byte bVar2;

  longlong lVar3;

  int iVar4;

  ulonglong uVar5;

  

  lVar3 = *(longlong *)(param_1 + 8);

  iVar4 = (uint)*(byte *)((longlong)*(int *)(param_1 + 0x24) + 0x23 + lVar3) +

          (uint)*(byte *)((longlong)*(int *)(param_1 + 0x24) + 0x22 + lVar3) * 0x100;

  if (param_2 < iVar4) {

    if (param_3 != (int *)0x0) {

      lVar3 = param_2 * 4 + lVar3;

      *param_3 = (int)(short)((ushort)*(byte *)(*(int *)(param_1 + 0x28) + lVar3) * 0x100 +

                             (ushort)*(byte *)((longlong)*(int *)(param_1 + 0x28) + 1 + lVar3));

    }

    if (param_4 == (int *)0x0) {

      return;

    }

    lVar3 = (longlong)(param_2 * 4) + (longlong)*(int *)(param_1 + 0x28);

    bVar1 = *(byte *)(lVar3 + 2 + *(longlong *)(param_1 + 8));

    bVar2 = *(byte *)(lVar3 + 3 + *(longlong *)(param_1 + 8));

  }

  else {

    uVar5 = (ulonglong)(uint)(iVar4 * 4);

    if (param_3 != (int *)0x0) {

      lVar3 = *(int *)(param_1 + 0x28) + lVar3;

      *param_3 = (int)(short)((ushort)*(byte *)((uVar5 - 3) + lVar3) +

                             (ushort)*(byte *)((uVar5 - 4) + lVar3) * 0x100);

    }

    if (param_4 == (int *)0x0) {

      return;

    }

    lVar3 = (longlong)((param_2 - iVar4) * 2) + (longlong)*(int *)(param_1 + 0x28) + uVar5;

    bVar1 = *(byte *)(lVar3 + *(longlong *)(param_1 + 8));

    bVar2 = *(byte *)(lVar3 + 1 + *(longlong *)(param_1 + 8));

  }

  *param_4 = (int)(short)((ushort)bVar2 + (ushort)bVar1 * 0x100);

  return;

}




