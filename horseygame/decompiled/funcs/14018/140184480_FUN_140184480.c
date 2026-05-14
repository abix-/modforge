// Address: 0x140184480
// Ghidra name: FUN_140184480
// ============ 0x140184480 FUN_140184480 (size=262) ============


void FUN_140184480(ulonglong param_1)



{

  DWORD dwMilliseconds;

  int iVar1;

  HANDLE pvVar2;

  ulonglong uVar3;

  longlong lVar4;

  longlong local_res10 [3];

  ulonglong in_stack_ffffffffffffffe0;

  

  pvVar2 = (HANDLE)FUN_140184320();

  if (pvVar2 == (HANDLE)0x0) {

    uVar3 = 0xf423ffff0bdc0;

    if (param_1 < 0xf423ffff0bdc1) {

      uVar3 = param_1;

    }

    pvVar2 = (HANDLE)FUN_1401842c0();

    dwMilliseconds = (DWORD)(uVar3 / 1000000);

    if (pvVar2 != (HANDLE)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00014018456c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      WaitForSingleObjectEx(pvVar2,dwMilliseconds,0);

      return;

    }

    Sleep(dwMilliseconds);

  }

  else {

    lVar4 = SUB168(SEXT816(0x5c28f5c28f5c28f5) * SEXT816((longlong)param_1),8) - param_1;

    local_res10[0] = (lVar4 >> 6) - (lVar4 >> 0x3f);

    if (DAT_1403fcb30 != (code *)0x0) {

      in_stack_ffffffffffffffe0 = 0;

      iVar1 = (*DAT_1403fcb30)(pvVar2,local_res10,0,0,0,0,0);

      if (iVar1 != 0) goto LAB_140184512;

    }

    iVar1 = (*DAT_1403fcb40)(pvVar2,local_res10,0,0,0,in_stack_ffffffffffffffe0 & 0xffffffff00000000

                            );

    if (iVar1 != 0) {

LAB_140184512:

      WaitForSingleObject(pvVar2,0xffffffff);

      return;

    }

  }

  return;

}




