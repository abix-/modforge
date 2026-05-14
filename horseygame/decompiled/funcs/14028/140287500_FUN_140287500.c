// Address: 0x140287500
// Ghidra name: FUN_140287500
// ============ 0x140287500 FUN_140287500 (size=73) ============


bool FUN_140287500(longlong param_1,longlong param_2)



{

  int iVar1;

  

  if (*(uint *)(param_1 + 0x1c) == *(uint *)(param_2 + 0x1c)) {

    if (*(void **)(param_2 + 0x28) == (void *)0x0) {

      return false;

    }

    if (*(void **)(param_1 + 0x28) != (void *)0x0) {

      iVar1 = memcmp(*(void **)(param_1 + 0x28),*(void **)(param_2 + 0x28),

                     (ulonglong)*(uint *)(param_1 + 0x1c) << 2);

      return iVar1 != 0;

    }

  }

  return true;

}




