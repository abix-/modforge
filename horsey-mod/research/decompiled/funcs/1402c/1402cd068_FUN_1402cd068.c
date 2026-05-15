// Address: 0x1402cd068
// Ghidra name: FUN_1402cd068
// ============ 0x1402cd068 FUN_1402cd068 (size=102) ============


longlong FUN_1402cd068(longlong *param_1)



{

  longlong lVar1;

  DWORD local_res8 [2];

  

  if (*param_1 == 0) {

    local_res8[0] = GetLastError();

    if ((char)param_1[2] == '\0') {

      param_1[1] = 0;

      lVar1 = 0;

      *(undefined1 *)(param_1 + 2) = 1;

    }

    else {

      lVar1 = param_1[1];

    }

    lVar1 = FUN_1402e8754(local_res8,lVar1);

    *param_1 = lVar1;

    SetLastError(local_res8[0]);

    if (lVar1 == 0) {

                    /* WARNING: Subroutine does not return */

      FUN_1402e1bf8();

    }

  }

  return *param_1;

}




