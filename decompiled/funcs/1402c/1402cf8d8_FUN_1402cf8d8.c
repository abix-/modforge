// Address: 0x1402cf8d8
// Ghidra name: FUN_1402cf8d8
// ============ 0x1402cf8d8 FUN_1402cf8d8 (size=93) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



void FUN_1402cf8d8(undefined8 *param_1)



{

  DWORD dwExitCode;

  int iVar1;

  undefined4 uVar2;

  longlong lVar3;

  

  if (param_1 == (undefined8 *)0x0) {

    dwExitCode = GetLastError();

                    /* WARNING: Subroutine does not return */

    ExitThread(dwExitCode);

  }

  lVar3 = FUN_1402e8664();

  *(undefined8 **)(lVar3 + 0x3c0) = param_1;

  iVar1 = FUN_1402ec8f8();

  if (iVar1 == 2) {

    iVar1 = FUN_1402ec5a4(1);

    *(bool *)(param_1 + 4) = iVar1 == 0;

  }

  uVar2 = (*(code *)*param_1)(param_1[1]);

  uVar2 = FUN_1402cfae8(uVar2);

                    /* WARNING: Subroutine does not return */

  FUN_1402da20c(uVar2);

}




