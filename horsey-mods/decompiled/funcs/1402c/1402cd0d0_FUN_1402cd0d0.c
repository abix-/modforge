// Address: 0x1402cd0d0
// Ghidra name: FUN_1402cd0d0
// ============ 0x1402cd0d0 FUN_1402cd0d0 (size=106) ============


longlong FUN_1402cd0d0(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  DWORD local_res8 [2];

  

  lVar1 = *param_1;

  lVar2 = 0;

  if (lVar1 == 0) {

    local_res8[0] = GetLastError();

    if ((char)param_1[2] == '\0') {

      param_1[1] = 0;

      *(undefined1 *)(param_1 + 2) = 1;

    }

    else {

      lVar2 = param_1[1];

    }

    lVar1 = FUN_1402e8754(local_res8,lVar2);

    *param_1 = lVar1;

    SetLastError(local_res8[0]);

  }

  return lVar1;

}




