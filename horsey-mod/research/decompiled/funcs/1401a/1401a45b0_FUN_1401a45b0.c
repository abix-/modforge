// Address: 0x1401a45b0
// Ghidra name: FUN_1401a45b0
// ============ 0x1401a45b0 FUN_1401a45b0 (size=192) ============


undefined1 * FUN_1401a45b0(undefined1 *param_1,byte *param_2,byte *param_3,int param_4)



{

  undefined1 *puVar1;

  undefined1 uVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  

  iVar3 = (uint)*param_2 + (uint)*param_2 * 2 + (uint)*param_3;

  if (param_4 == 1) {

    uVar2 = (undefined1)(iVar3 + 2U >> 2);

    param_1[1] = uVar2;

    *param_1 = uVar2;

    return param_1;

  }

  *param_1 = (char)(iVar3 + 2U >> 2);

  if (1 < (longlong)param_4) {

    lVar5 = (longlong)param_2 - (longlong)param_3;

    lVar6 = (longlong)param_4 + -1;

    iVar4 = iVar3;

    puVar1 = param_1;

    do {

      param_3 = param_3 + 1;

      iVar3 = (uint)param_3[lVar5] + (uint)param_3[lVar5] * 2 + (uint)*param_3;

      puVar1[1] = (char)((uint)(iVar3 + (iVar4 + 4) * 2 + iVar4) >> 4);

      puVar1[2] = (char)((uint)(iVar4 + (iVar3 + 4) * 2 + iVar3) >> 4);

      lVar6 = lVar6 + -1;

      iVar4 = iVar3;

      puVar1 = puVar1 + 2;

    } while (lVar6 != 0);

  }

  param_1[(longlong)(param_4 * 2) + -1] = (char)(iVar3 + 2U >> 2);

  return param_1;

}




