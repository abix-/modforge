// Address: 0x1401e4740
// Ghidra name: FUN_1401e4740
// ============ 0x1401e4740 FUN_1401e4740 (size=102) ============


void FUN_1401e4740(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  int local_res8 [8];

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (*(int *)(lVar1 + 0x40) != 0) {

    *(undefined4 *)(lVar1 + 0x44) = 0;

    return;

  }

  *(undefined4 *)(lVar1 + 0x44) = 8;

  if ((*(uint *)(lVar1 + 0x3c) & 0x800) != 0) {

    local_res8[0] = 0;

    iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x30) + 0x58))

                      (*(longlong **)(lVar1 + 0x30),local_res8,0);

    if ((-1 < iVar2) && (local_res8[0] == 0)) {

      *(undefined4 *)(lVar1 + 0x44) = 0x200;

    }

  }

  return;

}




