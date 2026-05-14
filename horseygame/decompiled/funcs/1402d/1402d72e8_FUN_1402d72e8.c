// Address: 0x1402d72e8
// Ghidra name: FUN_1402d72e8
// ============ 0x1402d72e8 FUN_1402d72e8 (size=153) ============


undefined8 FUN_1402d72e8(longlong param_1)



{

  int iVar1;

  longlong *plVar2;

  int iVar3;

  undefined4 uVar4;

  wchar_t *pwVar5;

  

  plVar2 = *(longlong **)(param_1 + 0x18);

  *(longlong **)(param_1 + 0x18) = plVar2 + 1;

  pwVar5 = (wchar_t *)*plVar2;

  iVar1 = *(int *)(param_1 + 0x34);

  iVar3 = *(int *)(param_1 + 0x30);

  if (*(int *)(param_1 + 0x30) == -1) {

    iVar3 = 0x7fffffff;

  }

  *(wchar_t **)(param_1 + 0x40) = pwVar5;

  if ((iVar1 == 2) ||

     (((iVar1 != 3 && (iVar1 != 0xc)) &&

      ((*(int *)(param_1 + 0x34) == 0xd || ((*(char *)(param_1 + 0x39) + 0x9dU & 0xef) == 0)))))) {

    if (pwVar5 == (wchar_t *)0x0) {

      *(char **)(param_1 + 0x40) = "(null)";

      pwVar5 = (wchar_t *)"(null)";

    }

    uVar4 = FUN_1402e6bc0(pwVar5,(longlong)iVar3);

  }

  else {

    if (pwVar5 == (wchar_t *)0x0) {

      pwVar5 = L"(null)";

      *(wchar_t **)(param_1 + 0x40) = L"(null)";

    }

    *(undefined1 *)(param_1 + 0x4c) = 1;

    uVar4 = FUN_1402e6d50(pwVar5,(longlong)iVar3);

  }

  *(undefined4 *)(param_1 + 0x48) = uVar4;

  return 1;

}




