// Address: 0x1401a9b00
// Ghidra name: FUN_1401a9b00
// ============ 0x1401a9b00 FUN_1401a9b00 (size=842) ============


longlong FUN_1401a9b00(undefined8 param_1,undefined1 *param_2)



{

  int iVar1;

  LSTATUS LVar2;

  longlong lVar3;

  size_t sVar4;

  LPCWSTR lpSubKey;

  LPBYTE lpData;

  DWORD local_res18 [2];

  HKEY local_res20;

  undefined8 in_stack_fffffffffffffeb8;

  undefined4 uVar5;

  undefined8 in_stack_fffffffffffffec0;

  undefined4 uVar6;

  char local_c8 [136];

  

  uVar5 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);

  uVar6 = (undefined4)((ulonglong)in_stack_fffffffffffffec0 >> 0x20);

  local_res18[0] = 0;

  iVar1 = FUN_1401a98e0(param_2,&DAT_14033c458);

  if (iVar1 != 0) {

    lVar3 = FUN_14012fd40(param_1);

    lVar3 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",param_1,lVar3 * 2 + 2);

    return lVar3;

  }

  FUN_14012ef10(local_c8,0x80,

                "System\\CurrentControlSet\\Control\\MediaCategories\\{%02X%02X%02X%02X-%02X%02X-%02X%02X-%02X%02X-%02X%02X%02X%02X%02X%02X}"

                ,param_2[3],CONCAT44(uVar5,(uint)(byte)param_2[2]),

                CONCAT44(uVar6,(uint)(byte)param_2[1]),*param_2,param_2[5],param_2[4],param_2[7],

                param_2[6],param_2[8],param_2[9],param_2[10],param_2[0xb],param_2[0xc],param_2[0xd],

                param_2[0xe],param_2[0xf]);

  sVar4 = strlen(local_c8);

  lpSubKey = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,local_c8,sVar4 + 1);

  LVar2 = RegOpenKeyExW((HKEY)0xffffffff80000002,lpSubKey,0,1,&local_res20);

  FUN_1401841e0(lpSubKey);

  if (LVar2 == 0) {

    LVar2 = RegQueryValueExW(local_res20,L"Name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,local_res18);

    if ((LVar2 == 0) &&

       (lpData = (LPBYTE)FUN_1401841f0((ulonglong)local_res18[0] + 2), lpData != (LPBYTE)0x0)) {

      LVar2 = RegQueryValueExW(local_res20,L"Name",(LPDWORD)0x0,(LPDWORD)0x0,lpData,local_res18);

      RegCloseKey(local_res20);

      if (LVar2 == 0) {

        (lpData + (ulonglong)(local_res18[0] >> 1) * 2)[0] = '\0';

        (lpData + (ulonglong)(local_res18[0] >> 1) * 2)[1] = '\0';

        lVar3 = FUN_14012fd40(lpData);

        lVar3 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",lpData,lVar3 * 2 + 2);

        FUN_1401841e0(lpData);

        if (lVar3 != 0) {

          return lVar3;

        }

        lVar3 = FUN_14012fd40(param_1);

        lVar3 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",param_1,lVar3 * 2 + 2);

        return lVar3;

      }

      FUN_1401841e0();

    }

    else {

      RegCloseKey(local_res20);

    }

  }

  lVar3 = FUN_14012fd40(param_1);

  lVar3 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",param_1,lVar3 * 2 + 2);

  return lVar3;

}




