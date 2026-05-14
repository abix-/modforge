// Address: 0x1402875c0
// Ghidra name: FUN_1402875c0
// ============ 0x1402875c0 FUN_1402875c0 (size=69) ============


bool FUN_1402875c0(longlong param_1,longlong param_2)



{

  int iVar1;

  

  if (*(uint *)(param_1 + 0x38) == *(uint *)(param_2 + 0x38)) {

    if (*(void **)(param_2 + 0x40) == (void *)0x0) {

      return false;

    }

    if (*(void **)(param_1 + 0x40) != (void *)0x0) {

      iVar1 = memcmp(*(void **)(param_1 + 0x40),*(void **)(param_2 + 0x40),

                     (ulonglong)*(uint *)(param_1 + 0x38));

      return iVar1 != 0;

    }

  }

  return true;

}




