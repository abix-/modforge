// Address: 0x1400f3c70
// Ghidra name: FUN_1400f3c70
// ============ 0x1400f3c70 FUN_1400f3c70 (size=207) ============


int FUN_1400f3c70(longlong param_1,int param_2)



{

  longlong lVar1;

  longlong lVar2;

  int iVar3;

  int iVar4;

  

  if ((param_2 < *(int *)(param_1 + 0x14)) && (*(int *)(param_1 + 0x34) < 2)) {

    lVar1 = *(longlong *)(param_1 + 8);

    if (*(int *)(param_1 + 0x34) == 0) {

      lVar2 = (longlong)(param_2 * 2) + (longlong)*(int *)(param_1 + 0x18);

      iVar3 = ((uint)*(byte *)(lVar2 + lVar1) * 0x100 + (uint)*(byte *)(lVar2 + 1 + lVar1)) * 2;

      iVar4 = ((uint)*(byte *)(lVar2 + 3 + lVar1) + (uint)*(byte *)(lVar2 + 2 + lVar1) * 0x100) * 2;

    }

    else {

      lVar2 = (longlong)(param_2 * 4) + (longlong)*(int *)(param_1 + 0x18);

      iVar3 = (((uint)*(byte *)(lVar2 + 1 + lVar1) + (uint)*(byte *)(lVar2 + lVar1) * 0x100) * 0x100

              + (uint)*(byte *)(lVar2 + 2 + lVar1)) * 0x100 + (uint)*(byte *)(lVar2 + 3 + lVar1);

      iVar4 = (((uint)*(byte *)(lVar2 + 5 + lVar1) + (uint)*(byte *)(lVar2 + 4 + lVar1) * 0x100) *

               0x100 + (uint)*(byte *)(lVar2 + 6 + lVar1)) * 0x100 +

              (uint)*(byte *)(lVar2 + 7 + lVar1);

    }

    iVar3 = *(int *)(param_1 + 0x20) + iVar3;

    if (iVar3 == *(int *)(param_1 + 0x20) + iVar4) {

      iVar3 = -1;

    }

    return iVar3;

  }

  return -1;

}




