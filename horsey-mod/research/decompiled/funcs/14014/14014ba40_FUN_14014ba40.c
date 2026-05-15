// Address: 0x14014ba40
// Ghidra name: FUN_14014ba40
// ============ 0x14014ba40 FUN_14014ba40 (size=94) ============


void FUN_14014ba40(longlong param_1,longlong param_2)



{

  int iVar1;

  longlong lVar2;

  ulonglong uVar3;

  uint uVar4;

  

  if (param_2 != 0) {

    iVar1 = FUN_14016d540(param_2);

    if (iVar1 != 0) goto LAB_14014ba5f;

  }

  iVar1 = FUN_14016dba0();

LAB_14014ba5f:

  lVar2 = FUN_14016d260(iVar1);

  if (((lVar2 == 0) ||

      (uVar3 = (ulonglong)*(uint *)(lVar2 + 0x18), (int)*(uint *)(lVar2 + 0x18) < 1)) ||

     (uVar4 = *(uint *)(lVar2 + 0x1c), (int)uVar4 < 1)) {

    uVar3 = 0x3c;

    uVar4 = 1;

  }

  *(ulonglong *)(param_1 + 0x128) = ((ulonglong)uVar4 * 1000000000) / uVar3;

  return;

}




