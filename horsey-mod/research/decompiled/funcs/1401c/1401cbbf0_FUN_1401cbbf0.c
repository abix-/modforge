// Address: 0x1401cbbf0
// Ghidra name: FUN_1401cbbf0
// ============ 0x1401cbbf0 FUN_1401cbbf0 (size=116) ============


bool FUN_1401cbbf0(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  code *pcVar3;

  

  lVar2 = FUN_1401885b0("dxgidebug.dll");

  *(longlong *)(param_1 + 0x30) = lVar2;

  if (lVar2 != 0) {

    pcVar3 = (code *)FUN_140188550(lVar2,"DXGIGetDebugInterface");

    if (pcVar3 != (code *)0x0) {

      iVar1 = (*pcVar3)(&DAT_140349298,param_1 + 8);

      if (-1 < iVar1) {

        iVar1 = (*pcVar3)(&DAT_1403492a8,param_1 + 0x18);

        return -1 < iVar1;

      }

    }

  }

  return false;

}




