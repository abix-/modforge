// Address: 0x1402ec784
// Ghidra name: FUN_1402ec784
// ============ 0x1402ec784 FUN_1402ec784 (size=233) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



byte FUN_1402ec784(void)



{

  int iVar1;

  code *pcVar2;

  code *pcVar3;

  longlong lVar4;

  undefined1 auStack_58 [32];

  undefined8 local_38;

  undefined8 local_28;

  undefined4 local_20;

  ulonglong local_18;

  

  local_18 = DAT_1403e8b00 ^ (ulonglong)auStack_58;

  if ((DAT_140424058 != (code *)0xffffffffffffffff) &&

     (((pcVar2 = DAT_140424058, DAT_140424058 != (code *)0x0 ||

       (pcVar2 = (code *)FUN_1402ec028(0xb,"GetProcessWindowStation",&DAT_14038ea60,

                                       "GetProcessWindowStation"), pcVar2 != (code *)0x0)) &&

      (DAT_140424078 != (code *)0xffffffffffffffff)))) {

    pcVar3 = DAT_140424078;

    if ((DAT_140424078 == (code *)0x0) &&

       (pcVar3 = (code *)FUN_1402ec028(0xf,"GetUserObjectInformationW",&DAT_14038ea80,

                                       "GetUserObjectInformationW"), pcVar3 == (code *)0x0)) {

      return 1;

    }

    lVar4 = (*pcVar2)();

    if (lVar4 != 0) {

      local_38 = 0;

      local_28 = 0;

      local_20 = 0;

      iVar1 = (*pcVar3)(lVar4,1,&local_28,0xc);

      if (iVar1 != 0) {

        return (byte)local_20 & 1;

      }

    }

    return 0;

  }

  return 1;

}




