// Address: 0x1402c6e74
// Ghidra name: FUN_1402c6e74
// ============ 0x1402c6e74 FUN_1402c6e74 (size=305) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



int FUN_1402c6e74(uint *param_1,longlong *param_2)



{

  uint uVar1;

  uint uVar2;

  BOOLEAN BVar3;

  DWORD DVar4;

  undefined1 auStack_48 [32];

  longlong local_28;

  int local_20;

  ulonglong local_18;

  

  local_18 = DAT_1403e8b00 ^ (ulonglong)auStack_48;

  DVar4 = GetCurrentThreadId();

  if ((*param_1 & 0xfffffeff) == 1) {

    if (param_1[0x12] != DVar4) {

      AcquireSRWLockExclusive((PSRWLOCK)(param_1 + 4));

      param_1[0x12] = DVar4;

    }

    param_1[0x13] = param_1[0x13] + 1;

  }

  else {

    if (param_2 == (longlong *)0x0) {

      if (param_1[0x12] != DVar4) {

        AcquireSRWLockExclusive((PSRWLOCK)(param_1 + 4));

      }

    }

    else if ((*param_2 < 0) || ((*param_2 == 0 && ((int)param_2[1] < 1)))) {

      if ((param_1[0x12] != DVar4) &&

         (BVar3 = TryAcquireSRWLockExclusive((PSRWLOCK)(param_1 + 4)), BVar3 == '\0'))

      goto LAB_1402c6f5f;

    }

    else {

      do {

        FUN_1402c6ddc(&local_28);

        if ((*param_2 <= local_28) && ((local_28 != *param_2 || ((int)param_2[1] <= local_20))))

        goto LAB_1402c6f5f;

      } while ((param_1[0x12] != DVar4) &&

              (BVar3 = TryAcquireSRWLockExclusive((PSRWLOCK)(param_1 + 4)), BVar3 == '\0'));

    }

    uVar2 = param_1[0x13];

    uVar1 = uVar2 + 1;

    param_1[0x13] = uVar1;

    if ((int)uVar1 < 2) {

      param_1[0x12] = DVar4;

    }

    else if ((*param_1 & 0x100) == 0) {

      param_1[0x13] = uVar2;

      if (param_2 == (longlong *)0x0) {

        return 3;

      }

LAB_1402c6f5f:

      if (*param_2 == 0) {

        return 3 - (uint)((int)param_2[1] != 0);

      }

      return 2;

    }

  }

  return 0;

}




