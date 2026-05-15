// Address: 0x140191a40
// Ghidra name: FUN_140191a40
// ============ 0x140191a40 FUN_140191a40 (size=399) ============


ulonglong FUN_140191a40(undefined8 *param_1,longlong param_2,ulonglong param_3,DWORD param_4)



{

  undefined8 *puVar1;

  HANDLE hEvent;

  int iVar2;

  DWORD DVar3;

  char *pcVar4;

  ulonglong uVar5;

  DWORD local_res10 [2];

  

  uVar5 = 0;

  local_res10[0] = 0;

  if ((param_2 == 0) || (param_3 == 0)) {

    FUN_140196b60(param_1,L"Zero buffer/length");

    return 0xffffffff;

  }

  FUN_140196b60(param_1,0);

  hEvent = (HANDLE)param_1[0xc];

  puVar1 = param_1 + 8;

  if (*(int *)(param_1 + 7) == 0) {

    *(undefined4 *)(param_1 + 7) = 1;

    FUN_1402f94c0(*puVar1,0,param_1[3]);

    ResetEvent(hEvent);

    iVar2 = ReadFile((HANDLE)*param_1,(LPVOID)*puVar1,*(DWORD *)(param_1 + 3),local_res10,

                     (LPOVERLAPPED)(param_1 + 9));

    if (iVar2 != 0) goto LAB_140191b32;

    DVar3 = GetLastError();

    if (DVar3 != 0x3e5) {

      FUN_140196c00(param_1,L"ReadFile");

      CancelIo((HANDLE)*param_1);

      *(undefined4 *)(param_1 + 7) = 0;

      return 0xffffffff;

    }

  }

  DVar3 = 0xffffffff;

  if (-1 < (int)param_4) {

    DVar3 = param_4;

  }

  DVar3 = WaitForSingleObject(hEvent,DVar3);

  if (DVar3 != 0) {

    return 0;

  }

  iVar2 = GetOverlappedResult((HANDLE)*param_1,(LPOVERLAPPED)(param_1 + 9),local_res10,0);

LAB_140191b32:

  *(undefined4 *)(param_1 + 7) = 0;

  if (iVar2 != 0) {

    if (local_res10[0] != 0) {

      pcVar4 = (char *)*puVar1;

      if (*pcVar4 == '\0') {

        local_res10[0] = local_res10[0] - 1;

        if (local_res10[0] < param_3) {

          param_3 = (ulonglong)local_res10[0];

        }

        pcVar4 = pcVar4 + 1;

        uVar5 = param_3;

      }

      else {

        uVar5 = param_3;

        if (local_res10[0] < param_3) {

          uVar5 = (ulonglong)local_res10[0];

        }

      }

      FUN_1402f8e20(param_2,pcVar4,uVar5);

    }

    return uVar5 & 0xffffffff;

  }

  DVar3 = GetLastError();

  if (DVar3 == 0x3e3) {

    return 0;

  }

  FUN_140196c00(param_1,L"hid_read_timeout/GetOverlappedResult");

  return 0xffffffff;

}




