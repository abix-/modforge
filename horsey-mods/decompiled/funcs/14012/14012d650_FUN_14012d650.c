// Address: 0x14012d650
// Ghidra name: FUN_14012d650
// ============ 0x14012d650 FUN_14012d650 (size=233) ============


DWORD FUN_14012d650(undefined8 *param_1,LPCVOID param_2,longlong param_3,undefined4 *param_4)



{

  DWORD DVar1;

  BOOL BVar2;

  DWORD local_res8 [2];

  LARGE_INTEGER local_18 [2];

  

  if (param_1[3] == 0) {

LAB_14012d6b0:

    if (*(char *)(param_1 + 4) != '\0') {

      local_18[0].QuadPart = 0;

      BVar2 = SetFilePointerEx((HANDLE)*param_1,(LARGE_INTEGER)0x0,local_18,2);

      if (BVar2 == 0) goto LAB_14012d692;

    }

    BVar2 = WriteFile((HANDLE)*param_1,param_2,(DWORD)param_3,local_res8,(LPOVERLAPPED)0x0);

    if (BVar2 == 0) {

      *param_4 = 1;

      FUN_1401a9ed0("Error writing to datastream");

      local_res8[0] = 0;

    }

    else if ((local_res8[0] == 0) && (param_3 != 0)) {

      *param_4 = 3;

    }

  }

  else {

    DVar1 = SetFilePointer((HANDLE)*param_1,-(int)param_1[3],(PLONG)0x0,1);

    if (DVar1 != 0) {

      param_1[3] = 0;

      goto LAB_14012d6b0;

    }

LAB_14012d692:

    *param_4 = 1;

    FUN_1401a9ed0("Error seeking in datastream");

    local_res8[0] = 0;

  }

  return local_res8[0];

}




