// Address: 0x1400f1430
// Ghidra name: FUN_1400f1430
// ============ 0x1400f1430 FUN_1400f1430 (size=280) ============


void FUN_1400f1430(longlong param_1,undefined8 param_2,int *param_3,int *param_4)



{

  byte bVar1;

  byte bVar2;

  int iVar3;

  longlong lVar4;

  int iVar5;

  ulonglong uVar6;

  

  iVar3 = FUN_1400f0eb0();

  lVar4 = *(longlong *)(param_1 + 8);

  iVar5 = (uint)*(byte *)((longlong)*(int *)(param_1 + 0x24) + 0x23 + lVar4) +

          (uint)*(byte *)((longlong)*(int *)(param_1 + 0x24) + 0x22 + lVar4) * 0x100;

  if (iVar3 < iVar5) {

    iVar3 = iVar3 * 4;

    if (param_3 != (int *)0x0) {

      lVar4 = *(int *)(param_1 + 0x28) + lVar4;

      *param_3 = (int)(short)((ushort)*(byte *)(iVar3 + lVar4) * 0x100 +

                             (ushort)*(byte *)((longlong)iVar3 + 1 + lVar4));

    }

    if (param_4 == (int *)0x0) {

      return;

    }

    lVar4 = (longlong)*(int *)(param_1 + 0x28) + (longlong)iVar3;

    bVar1 = *(byte *)(lVar4 + 2 + *(longlong *)(param_1 + 8));

    bVar2 = *(byte *)(lVar4 + 3 + *(longlong *)(param_1 + 8));

  }

  else {

    uVar6 = (ulonglong)(uint)(iVar5 * 4);

    if (param_3 != (int *)0x0) {

      lVar4 = *(int *)(param_1 + 0x28) + lVar4;

      *param_3 = (int)(short)((ushort)*(byte *)((uVar6 - 3) + lVar4) +

                             (ushort)*(byte *)((uVar6 - 4) + lVar4) * 0x100);

    }

    if (param_4 == (int *)0x0) {

      return;

    }

    lVar4 = (longlong)((iVar3 - iVar5) * 2) + (longlong)*(int *)(param_1 + 0x28) + uVar6;

    bVar1 = *(byte *)(lVar4 + *(longlong *)(param_1 + 8));

    bVar2 = *(byte *)(lVar4 + 1 + *(longlong *)(param_1 + 8));

  }

  *param_4 = (int)(short)((ushort)bVar2 + (ushort)bVar1 * 0x100);

  return;

}




