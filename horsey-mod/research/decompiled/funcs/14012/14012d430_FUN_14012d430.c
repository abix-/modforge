// Address: 0x14012d430
// Ghidra name: FUN_14012d430
// ============ 0x14012d430 FUN_14012d430 (size=321) ============


ulonglong FUN_14012d430(undefined8 *param_1,LPVOID param_2,ulonglong param_3,undefined4 *param_4)



{

  ulonglong uVar1;

  BOOL BVar2;

  DWORD DVar3;

  ulonglong uVar4;

  uint local_res8 [2];

  

  uVar1 = param_1[3];

  uVar4 = 0;

  if (uVar1 != 0) {

    uVar4 = uVar1;

    if (param_3 < uVar1) {

      uVar4 = param_3;

    }

    FUN_1402f8e20(param_2,(param_1[2] - uVar1) + param_1[1],uVar4);

    param_1[3] = param_1[3] - uVar4;

    if (uVar4 == param_3) {

      return param_3;

    }

    param_2 = (LPVOID)((longlong)param_2 + uVar4);

    param_3 = param_3 - uVar4;

  }

  if (param_3 < 0x400) {

    BVar2 = ReadFile((HANDLE)*param_1,(LPVOID)param_1[1],0x400,local_res8,(LPOVERLAPPED)0x0);

    if (BVar2 == 0) {

LAB_14012d509:

      DVar3 = GetLastError();

      if (DVar3 == 0x6d) {

        *param_4 = 2;

        return 0;

      }

      if (DVar3 != 0xe8) {

        *param_4 = 1;

        FUN_1401a9ed0("Error reading from datastream");

        return 0;

      }

      *param_4 = 3;

      return 0;

    }

    if (local_res8[0] == 0) {

      *param_4 = 2;

    }

    if (local_res8[0] <= param_3) {

      param_3 = (ulonglong)local_res8[0];

    }

    FUN_1402f8e20(param_2,param_1[1],param_3);

    param_1[2] = (ulonglong)local_res8[0];

    param_1[3] = local_res8[0] - param_3;

  }

  else {

    BVar2 = ReadFile((HANDLE)*param_1,param_2,(DWORD)param_3,local_res8,(LPOVERLAPPED)0x0);

    if (BVar2 == 0) goto LAB_14012d509;

    param_3 = (ulonglong)local_res8[0];

    if (local_res8[0] == 0) {

      *param_4 = 2;

    }

  }

  return param_3 + uVar4;

}




