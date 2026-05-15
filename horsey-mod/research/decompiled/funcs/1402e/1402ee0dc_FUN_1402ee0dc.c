// Address: 0x1402ee0dc
// Ghidra name: FUN_1402ee0dc
// ============ 0x1402ee0dc FUN_1402ee0dc (size=263) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



DWORD * FUN_1402ee0dc(DWORD *param_1,uint param_2,char *param_3,ulonglong param_4)



{

  char cVar1;

  HANDLE hFile;

  BOOL BVar2;

  DWORD DVar3;

  uint nNumberOfBytesToWrite;

  char *pcVar4;

  char *pcVar5;

  undefined1 auStackY_1468 [32];

  DWORD local_1438 [4];

  char local_1428 [5120];

  ulonglong local_28;

  undefined8 local_20;

  

  local_20 = 0x1402ee0f4;

  local_28 = DAT_1403e8b00 ^ (ulonglong)auStackY_1468;

  pcVar5 = param_3 + (param_4 & 0xffffffff);

  hFile = *(HANDLE *)

           ((&DAT_1403ff160)[(longlong)(int)param_2 >> 6] + 0x28 +

           (ulonglong)(param_2 & 0x3f) * 0x48);

  param_1[0] = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  do {

    if (pcVar5 <= param_3) {

      return param_1;

    }

    pcVar4 = local_1428;

    do {

      if (pcVar5 <= param_3) break;

      cVar1 = *param_3;

      param_3 = param_3 + 1;

      if (cVar1 == '\n') {

        param_1[2] = param_1[2] + 1;

        *pcVar4 = '\r';

        pcVar4 = pcVar4 + 1;

      }

      *pcVar4 = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (pcVar4 < local_1428 + 0x13ff);

    local_1438[0] = 0;

    nNumberOfBytesToWrite = (int)pcVar4 - (int)local_1428;

    BVar2 = WriteFile(hFile,local_1428,nNumberOfBytesToWrite,local_1438,(LPOVERLAPPED)0x0);

    if (BVar2 == 0) {

      DVar3 = GetLastError();

      *param_1 = DVar3;

      return param_1;

    }

    param_1[1] = param_1[1] + local_1438[0];

    if (local_1438[0] < nNumberOfBytesToWrite) {

      return param_1;

    }

  } while( true );

}




