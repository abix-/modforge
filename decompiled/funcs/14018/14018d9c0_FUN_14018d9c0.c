// Address: 0x14018d9c0
// Ghidra name: FUN_14018d9c0
// ============ 0x14018d9c0 FUN_14018d9c0 (size=90) ============


ulonglong FUN_14018d9c0(undefined8 param_1,ulonglong param_2)



{

  DWORD DVar1;

  

  if (DAT_1403e2908 != '\0') {

    if ((longlong)param_2 < 0) {

      DVar1 = 0xffffffff;

    }

    else {

      DVar1 = (DWORD)(param_2 / 1000000);

    }

    DVar1 = MsgWaitForMultipleObjects(0,(HANDLE *)0x0,0,DVar1,0x1cff);

    return (ulonglong)(DVar1 == 0);

  }

  return 0xffffffff;

}




