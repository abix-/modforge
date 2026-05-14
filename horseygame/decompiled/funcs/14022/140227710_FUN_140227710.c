// Address: 0x140227710
// Ghidra name: FUN_140227710
// ============ 0x140227710 FUN_140227710 (size=432) ============


void FUN_140227710(int param_1,undefined8 *param_2,undefined8 *param_3)



{

  int iVar1;

  LSTATUS LVar2;

  longlong lVar3;

  bool bVar4;

  DWORD local_res10 [2];

  DWORD local_res18 [2];

  HKEY local_res20;

  BYTE local_78 [8];

  ulonglong local_70;

  ulonglong local_68;

  ulonglong local_60;

  ulonglong local_58;

  BYTE local_50 [8];

  uint local_48;

  undefined4 local_44;

  uint local_40;

  undefined4 local_3c;

  uint local_38;

  undefined4 local_34;

  uint local_30;

  undefined4 local_2c;

  

  lVar3 = (longlong)param_1;

  iVar1 = FUN_1401a9950();

  local_70 = 0x6e15;

  local_68 = 0x14000;

  bVar4 = iVar1 != 0;

  local_78[0] = '\0';

  local_78[1] = '\0';

  local_78[2] = '\0';

  local_78[3] = '\0';

  local_78[4] = '\0';

  local_78[5] = '\0';

  local_78[6] = '\0';

  local_78[7] = '\0';

  local_60 = 0x3dc29;

  local_58 = 0x280000;

  local_48 = 0x15eb8;

  if (bVar4) {

    local_48 = 0x111fd;

  }

  local_50[0] = '\0';

  local_50[1] = '\0';

  local_50[2] = '\0';

  local_50[3] = '\0';

  local_50[4] = '\0';

  local_50[5] = '\0';

  local_50[6] = '\0';

  local_50[7] = '\0';

  local_44 = 0;

  local_3c = 0;

  local_40 = 0x54ccd;

  if (bVar4) {

    local_40 = 0x42400;

  }

  local_34 = 0;

  local_2c = 0;

  local_38 = 0x184ccd;

  if (bVar4) {

    local_38 = 0x12fc00;

  }

  local_res10[0] = 0x28;

  local_res18[0] = 0x28;

  local_30 = 0x2380000;

  if (bVar4) {

    local_30 = 0x1bbc000;

  }

  LVar2 = RegOpenKeyExW((HKEY)0xffffffff80000001,L"Control Panel\\Mouse",0,0x20019,&local_res20);

  if (LVar2 == 0) {

    RegQueryValueExW(local_res20,L"SmoothMouseXCurve",(LPDWORD)0x0,(LPDWORD)0x0,local_78,local_res10

                    );

    RegQueryValueExW(local_res20,L"SmoothMouseYCurve",(LPDWORD)0x0,(LPDWORD)0x0,local_50,local_res18

                    );

    RegCloseKey(local_res20);

  }

  *param_2 = 0;

  *param_3 = 0;

  param_2[1] = (local_70 & 0xffffffff) * 7;

  param_3[1] = (ulonglong)local_48 * lVar3 * 0x20000;

  param_2[2] = (local_68 & 0xffffffff) * 7;

  param_3[2] = (ulonglong)local_40 * lVar3 * 0x20000;

  param_2[3] = (local_60 & 0xffffffff) * 7;

  param_3[3] = (ulonglong)local_38 * lVar3 * 0x20000;

  param_2[4] = (local_58 & 0xffffffff) * 7;

  param_3[4] = (ulonglong)local_30 * lVar3 * 0x20000;

  return;

}




