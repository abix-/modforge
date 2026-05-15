// Address: 0x1400759e0
// Ghidra name: FUN_1400759e0
// ============ 0x1400759e0 FUN_1400759e0 (size=146) ============


void FUN_1400759e0(longlong *param_1)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  

  *DAT_1403ead20 = (int)(param_1[1] - *param_1 >> 2);

  FUN_1400764d0(4);

  lVar1 = *param_1;

  iVar2 = 0;

  if (param_1[1] - lVar1 >> 2 != 0) {

    lVar3 = 0;

    do {

      *DAT_1403ead20 = *(undefined4 *)(lVar3 + lVar1);

      FUN_1400764d0(4);

      lVar1 = *param_1;

      lVar3 = lVar3 + 4;

      iVar2 = iVar2 + 1;

    } while ((ulonglong)(longlong)iVar2 < (ulonglong)(param_1[1] - lVar1 >> 2));

  }

  return;

}




