// Address: 0x1401611b0
// Ghidra name: FUN_1401611b0
// ============ 0x1401611b0 FUN_1401611b0 (size=118) ============


uint FUN_1401611b0(longlong param_1,int param_2,char param_3)



{

  longlong lVar1;

  uint uVar2;

  int iVar3;

  

  uVar2 = 0;

  iVar3 = 0;

  if (*(int *)(param_1 + 0x100) < 1) {

    return 0;

  }

  lVar1 = 0;

  do {

    if (param_2 - 1U < 0xfffffffe) {

      if (param_2 == *(int *)(lVar1 + *(longlong *)(param_1 + 0x108))) {

        return uVar2 | *(uint *)(*(longlong *)(param_1 + 0x108) + 4 + (longlong)iVar3 * 0x18);

      }

    }

    else if ((param_3 != '\0') || (*(int *)(lVar1 + *(longlong *)(param_1 + 0x108)) != -1)) {

      uVar2 = uVar2 | *(uint *)(lVar1 + 4 + *(longlong *)(param_1 + 0x108));

    }

    iVar3 = iVar3 + 1;

    lVar1 = lVar1 + 0x18;

  } while (iVar3 < *(int *)(param_1 + 0x100));

  return uVar2;

}




