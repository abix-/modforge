// Address: 0x14018b6b0
// Ghidra name: FUN_14018b6b0
// ============ 0x14018b6b0 FUN_14018b6b0 (size=766) ============


undefined8

FUN_14018b6b0(HANDLE param_1,HDEVINFO param_2,undefined8 param_3,short param_4,short param_5,

             undefined8 param_6,uint param_7)



{

  UINT UVar1;

  BOOL BVar2;

  DWORD DVar3;

  int iVar4;

  HANDLE hObject;

  longlong lVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  undefined8 uVar8;

  DWORD MemberIndex;

  longlong local_5a8;

  _SP_DEVINFO_DATA local_5a0;

  CHAR local_578 [64];

  short local_538 [256];

  CHAR local_338 [272];

  short local_228 [256];

  

  uVar7 = 0;

  local_5a8 = 0;

  local_228[0] = 0;

  local_538[0] = 0;

  uVar6 = uVar7;

  if ((char)param_7 == '\0') {

LAB_14018b7f1:

    local_5a0.ClassGuid.Data2 = 0;

    local_5a0.ClassGuid.Data3 = 0;

    local_5a0.ClassGuid.Data4[0] = '\0';

    local_5a0.ClassGuid.Data4[1] = '\0';

    local_5a0.ClassGuid.Data4[2] = '\0';

    local_5a0.ClassGuid.Data4[3] = '\0';

    local_5a0.cbSize = 0x20;

    local_5a0.ClassGuid.Data1 = 0;

    local_5a0.ClassGuid.Data4[4] = '\0';

    local_5a0.ClassGuid.Data4[5] = '\0';

    local_5a0.ClassGuid.Data4[6] = '\0';

    local_5a0.ClassGuid.Data4[7] = '\0';

    local_5a0.DevInst = 0;

    local_5a0.Reserved = 0;

    do {

      while( true ) {

        MemberIndex = (DWORD)uVar7;

        BVar2 = SetupDiEnumDeviceInfo(param_2,MemberIndex,&local_5a0);

        if (BVar2 != 0) break;

        DVar3 = GetLastError();

        if (DVar3 == 0x103) goto LAB_14018b928;

        uVar7 = (ulonglong)(MemberIndex + 1);

      }

      BVar2 = SetupDiGetDeviceInstanceIdA(param_2,&local_5a0,local_578,0x40,(PDWORD)0x0);

      if (BVar2 != 0) {

        iVar4 = FUN_14012ef60(param_3,local_578);

        if (iVar4 == 0) goto LAB_14018b870;

      }

      uVar7 = (ulonglong)(MemberIndex + 1);

    } while( true );

  }

  local_338[0] = '\0';

  param_7 = 0x104;

  UVar1 = GetRawInputDeviceInfoA(param_1,0x20000007,local_338,&param_7);

  if (UVar1 != 0xffffffff) {

    local_338[UVar1] = '\0';

    hObject = CreateFileA(local_338,0,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);

    if (hObject != (HANDLE)0xffffffffffffffff) {

      (*DAT_1403ffc38)(hObject,local_228,0x200);

      (*DAT_1403ffc30)(hObject,local_538,0x200);

      CloseHandle(hObject);

    }

  }

  if (local_228[0] != 0) {

    lVar5 = FUN_14012fd40(local_228);

    uVar6 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_228,lVar5 * 2 + 2);

  }

  if (local_538[0] == 0) goto LAB_14018b7f1;

  goto LAB_14018b8dd;

LAB_14018b870:

  param_7 = 0;

  BVar2 = SetupDiGetDeviceRegistryPropertyW

                    (param_2,&local_5a0,0,(PDWORD)0x0,(PBYTE)local_538,0x200,&param_7);

  if (BVar2 == 0) goto LAB_14018b928;

  param_7 = param_7 >> 1;

  uVar7 = (ulonglong)param_7;

  if (0xff < param_7) {

    uVar7 = 0xff;

    param_7 = 0xff;

  }

  local_538[uVar7] = 0;

  if ((param_4 != 0) || (param_5 != 0)) {

    FUN_14012ee40(&local_5a8,"%S (0x%.4x/0x%.4x)",local_538,param_4,param_5);

    goto LAB_14018b928;

  }

LAB_14018b8dd:

  lVar5 = FUN_14012fd40(local_538);

  local_5a8 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_538,lVar5 * 2 + 2);

LAB_14018b928:

  if ((local_5a8 == 0) && ((param_4 != 0 || (param_5 != 0)))) {

    FUN_14012ee40(&local_5a8,"%s (0x%.4x/0x%.4x)",param_6,param_4,param_5);

  }

  uVar8 = FUN_1401aa480(param_4,param_5,uVar6,local_5a8,param_6);

  FUN_1401841e0(uVar6);

  FUN_1401841e0(local_5a8);

  return uVar8;

}




