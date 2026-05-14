// Address: 0x140180400
// Ghidra name: FUN_140180400
// ============ 0x140180400 FUN_140180400 (size=366) ============


undefined8 FUN_140180400(longlong param_1,uint *param_2,char param_3)



{

  ushort uVar1;

  BOOL BVar2;

  DWORD DVar3;

  undefined8 uVar4;

  longlong lVar5;

  _SYSTEMTIME *p_Var6;

  DWORD local_res10 [2];

  DWORD local_res20 [2];

  FILETIME local_48;

  _FILETIME local_40;

  _SYSTEMTIME local_38;

  _SYSTEMTIME local_28;

  

  p_Var6 = (_SYSTEMTIME *)0x0;

  if (param_2 == (uint *)0x0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403371ac);

    return uVar4;

  }

  FUN_14017d4a0(param_1,local_res10,local_res20);

  local_48.dwLowDateTime = local_res10[0];

  local_48.dwHighDateTime = local_res20[0];

  BVar2 = FileTimeToSystemTime(&local_48,&local_28);

  if (BVar2 == 0) {

LAB_1401804eb:

    DVar3 = GetLastError();

    uVar4 = FUN_14012e850("SDL_DateTime conversion failed (%lu)",DVar3);

  }

  else {

    if (param_3 == '\0') {

      param_2[8] = 0;

      p_Var6 = &local_28;

    }

    else {

      BVar2 = SystemTimeToTzSpecificLocalTime((TIME_ZONE_INFORMATION *)0x0,&local_28,&local_38);

      if (BVar2 != 0) {

        SystemTimeToFileTime(&local_38,&local_40);

        lVar5 = FUN_14017d450(local_40.dwLowDateTime,local_40.dwHighDateTime);

        p_Var6 = &local_38;

        param_2[8] = (uint)((lVar5 - param_1) / 1000000000);

      }

      if (p_Var6 == (_SYSTEMTIME *)0x0) goto LAB_1401804eb;

    }

    *param_2 = (uint)p_Var6->wYear;

    param_2[1] = (uint)p_Var6->wMonth;

    param_2[2] = (uint)p_Var6->wDay;

    param_2[3] = (uint)p_Var6->wHour;

    param_2[4] = (uint)p_Var6->wMinute;

    param_2[5] = (uint)p_Var6->wSecond;

    uVar1 = p_Var6->wDayOfWeek;

    param_2[7] = (uint)uVar1;

    uVar4 = CONCAT71((uint7)(byte)(uVar1 >> 8),1);

    param_2[6] = (int)param_1 + (int)(param_1 / 1000000000) * -1000000000;

  }

  return uVar4;

}




