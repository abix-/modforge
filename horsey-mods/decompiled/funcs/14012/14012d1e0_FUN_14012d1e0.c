// Address: 0x14012d1e0
// Ghidra name: FUN_14012d1e0
// ============ 0x14012d1e0 FUN_14012d1e0 (size=62) ============


undefined1 FUN_14012d1e0(undefined8 *param_1)



{

  if ((HANDLE)*param_1 != (HANDLE)0xffffffffffffffff) {

    if (*(char *)((longlong)param_1 + 0x21) != '\0') {

      CloseHandle((HANDLE)*param_1);

    }

    *param_1 = 0xffffffffffffffff;

  }

  FUN_1401841e0(param_1[1]);

  FUN_1401841e0(param_1);

  return 1;

}




