// Address: 0x1400c4e20
// Ghidra name: FUN_1400c4e20
// ============ 0x1400c4e20 FUN_1400c4e20 (size=373) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400c4e20(LPCSTR param_1)



{

  ulonglong uVar1;

  longlong lVar2;

  LPCSTR ***ppppCVar3;

  LPCSTR pCVar4;

  ulonglong uVar5;

  LPCSTR **local_48;

  undefined8 uStack_40;

  ulonglong local_38;

  ulonglong uStack_30;

  

  lVar2 = *(longlong *)(param_1 + 0x10);

  if (0x7fffffffffffffffU - lVar2 < 5) {

                    /* WARNING: Subroutine does not return */

    FUN_140024130();

  }

  pCVar4 = param_1;

  if (0xf < *(ulonglong *)(param_1 + 0x18)) {

    pCVar4 = *(LPCSTR *)param_1;

  }

  local_48 = (LPCSTR **)0x0;

  uStack_40 = 0;

  local_38 = 0;

  uStack_30 = 0;

  uVar1 = lVar2 + 5;

  uVar5 = 0xf;

  ppppCVar3 = &local_48;

  if (0xf < uVar1) {

    uVar5 = uVar1 | 0xf;

    if (uVar5 < 0x8000000000000000) {

      if (uVar5 < 0x16) {

        uVar5 = 0x16;

      }

    }

    else {

      uVar5 = 0x7fffffffffffffff;

    }

    ppppCVar3 = (LPCSTR ***)FUN_1400285e0(uVar5 + 1);

    local_48 = (LPCSTR **)ppppCVar3;

  }

  local_38 = uVar1;

  uStack_30 = uVar5;

  FUN_1402f8e20(ppppCVar3,pCVar4,lVar2);

  *(undefined4 *)((longlong)ppppCVar3 + lVar2) = DAT_14030e090;

  *(CHAR *)((longlong)ppppCVar3 + lVar2 + 4) = DAT_14030e094;

  *(CHAR *)((longlong)ppppCVar3 + uVar1) = '\0';

  ppppCVar3 = &local_48;

  if (0xf < uStack_30) {

    ppppCVar3 = (LPCSTR ***)local_48;

  }

  pCVar4 = param_1;

  if (0xf < *(ulonglong *)(param_1 + 0x18)) {

    pCVar4 = *(LPCSTR *)param_1;

  }

  MoveFileExA(pCVar4,(LPCSTR)ppppCVar3,1);

  if (0xf < uStack_30) {

    if (0xfff < uStack_30 + 1) {

      if ((LPCSTR)0x1f < (LPCSTR)((longlong)local_48 + (-8 - (longlong)local_48[-1]))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  local_38 = _DAT_14039caa0;

  uStack_30 = _UNK_14039caa8;

  local_48 = (LPCSTR **)((ulonglong)local_48 & 0xffffffffffffff00);

  FUN_140027900(param_1);

  return;

}




