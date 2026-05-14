// Address: 0x1402c9814
// Ghidra name: FUN_1402c9814
// ============ 0x1402c9814 FUN_1402c9814 (size=201) ============


longlong FUN_1402c9814(void)



{

  DWORD dwErrCode;

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  

  if (DAT_1403e8b50 == -1) {

    lVar3 = 0;

  }

  else {

    dwErrCode = GetLastError();

    lVar2 = __vcrt_FlsGetValue(DAT_1403e8b50);

    lVar4 = 0;

    lVar3 = lVar4;

    if (((lVar2 != -1) && (lVar3 = lVar2, lVar2 == 0)) &&

       (iVar1 = __vcrt_FlsSetValue(DAT_1403e8b50), lVar3 = lVar4, iVar1 != 0)) {

      lVar3 = _calloc_base(1);

      if ((lVar3 == 0) || (iVar1 = __vcrt_FlsSetValue(DAT_1403e8b50,lVar3), iVar1 == 0)) {

        __vcrt_FlsSetValue(DAT_1403e8b50,0);

        lVar2 = lVar3;

      }

      else {

        *(undefined4 *)(lVar3 + 0x78) = 0xfffffffe;

        lVar2 = lVar4;

        lVar4 = lVar3;

      }

      thunk_FUN_1402e9a80(lVar2);

      lVar3 = lVar4;

    }

    SetLastError(dwErrCode);

  }

  return lVar3;

}




