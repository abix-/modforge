// Address: 0x1402f1718
// Ghidra name: FUN_1402f1718
// ============ 0x1402f1718 FUN_1402f1718 (size=139) ============


undefined8

FUN_1402f1718(undefined8 param_1,undefined4 *param_2,undefined8 *param_3,undefined4 *param_4)



{

  BOOL BVar1;

  DWORD DVar2;

  HANDLE hFile;

  DWORD *pDVar3;

  undefined4 *puVar4;

  undefined8 uVar5;

  

  __acrt_lowio_lock_fh(*param_2);

  if ((*(byte *)((&DAT_1403ff160)[(longlong)(int)*(uint *)*param_3 >> 6] + 0x38 +

                (ulonglong)(*(uint *)*param_3 & 0x3f) * 0x48) & 1) != 0) {

    hFile = (HANDLE)FUN_1402f4f90();

    BVar1 = FlushFileBuffers(hFile);

    uVar5 = 0;

    if (BVar1 != 0) goto LAB_1402f178f;

    DVar2 = GetLastError();

    pDVar3 = (DWORD *)FUN_1402e688c();

    *pDVar3 = DVar2;

  }

  puVar4 = (undefined4 *)FUN_1402e68b0();

  *puVar4 = 9;

  uVar5 = 0xffffffff;

LAB_1402f178f:

  __acrt_lowio_unlock_fh(*param_4);

  return uVar5;

}




