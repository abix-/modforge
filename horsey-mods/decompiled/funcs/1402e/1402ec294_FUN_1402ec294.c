// Address: 0x1402ec294
// Ghidra name: FUN_1402ec294
// ============ 0x1402ec294 FUN_1402ec294 (size=92) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



undefined8 FUN_1402ec294(undefined8 param_1)



{

  code *pcVar1;

  undefined8 uVar2;

  

  if (DAT_1404240d8 == (code *)0xffffffffffffffff) {

    return 0xc0000225;

  }

  pcVar1 = DAT_1404240d8;

  if ((DAT_1404240d8 == (code *)0x0) &&

     (pcVar1 = (code *)FUN_1402ec028(0x1b,"AppPolicyGetThreadInitializationType",&DAT_14038eb40,

                                     &DAT_14038eb44), pcVar1 == (code *)0x0)) {

    return 0xc0000225;

  }

  uVar2 = (*pcVar1)(0xfffffffffffffffa,param_1);

  return uVar2;

}




