// Address: 0x1402ec238
// Ghidra name: FUN_1402ec238
// ============ 0x1402ec238 FUN_1402ec238 (size=92) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



undefined8 FUN_1402ec238(undefined8 param_1)



{

  code *pcVar1;

  undefined8 uVar2;

  

  if (DAT_1404240e0 == (code *)0xffffffffffffffff) {

    return 0xc0000225;

  }

  pcVar1 = DAT_1404240e0;

  if ((DAT_1404240e0 == (code *)0x0) &&

     (pcVar1 = (code *)FUN_1402ec028(0x1c,"AppPolicyGetShowDeveloperDiagnostic",&DAT_14038eb70,

                                     &DAT_14038eb74), pcVar1 == (code *)0x0)) {

    return 0xc0000225;

  }

  uVar2 = (*pcVar1)(0xfffffffffffffffa,param_1);

  return uVar2;

}




