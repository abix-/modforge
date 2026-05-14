// Address: 0x14017cd10
// Ghidra name: FUN_14017cd10
// ============ 0x14017cd10 FUN_14017cd10 (size=79) ============


undefined8 FUN_14017cd10(undefined8 *param_1,ulonglong param_2)



{

  DWORD DVar1;

  

  if (param_1 != (undefined8 *)0x0) {

    if ((longlong)param_2 < 0) {

      DVar1 = 0xffffffff;

    }

    else {

      DVar1 = (DWORD)(param_2 / 1000000);

    }

    DVar1 = WaitForSingleObjectEx((HANDLE)*param_1,DVar1,0);

    if (DVar1 != 0) {

      return 0;

    }

    LOCK();

    *(int *)(param_1 + 1) = *(int *)(param_1 + 1) + -1;

    UNLOCK();

  }

  return 1;

}




