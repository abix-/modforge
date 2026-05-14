// Address: 0x140230870
// Ghidra name: FUN_140230870
// ============ 0x140230870 FUN_140230870 (size=255) ============


undefined8 FUN_140230870(char *param_1,undefined8 param_2,undefined8 *param_3)



{

  undefined *puVar1;

  char cVar2;

  size_t sVar3;

  LPCWSTR lpFileName;

  HANDLE pvVar4;

  undefined8 uVar5;

  DWORD local_res20 [2];

  DWORD local_18 [4];

  

  cVar2 = FUN_140230c10(param_2,local_18,local_res20);

  if (cVar2 != '\0') {

    sVar3 = strlen(param_1);

    lpFileName = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_1,sVar3 + 1);

    if (lpFileName != (LPCWSTR)0x0) {

      pvVar4 = CreateFileW(lpFileName,local_18[0],1,(LPSECURITY_ATTRIBUTES)0x0,local_res20[0],0x80,

                           (HANDLE)0x0);

      FUN_1401841e0(lpFileName);

      puVar1 = PTR_FUN_1403580c8;

      if (pvVar4 == (HANDLE)0x0) {

        uVar5 = FUN_1401a9ed0("CreateFileW");

        return uVar5;

      }

      *param_3 = PTR_FUN_1403580c0;

      param_3[1] = puVar1;

      puVar1 = PTR_FUN_1403580d8;

      param_3[2] = PTR_FUN_1403580d0;

      param_3[3] = puVar1;

      puVar1 = PTR__guard_check_icall_1403580e0;

      param_3[5] = pvVar4;

      param_3[4] = puVar1;

      return 1;

    }

  }

  return 0;

}




