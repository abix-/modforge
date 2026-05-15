// Address: 0x1402ec2f0
// Ghidra name: FUN_1402ec2f0
// ============ 0x1402ec2f0 FUN_1402ec2f0 (size=92) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



undefined8 FUN_1402ec2f0(undefined8 param_1)



{

  code *pcVar1;

  undefined8 uVar2;

  

  if (DAT_1404240e8 == (code *)0xffffffffffffffff) {

    return 0xc0000225;

  }

  pcVar1 = DAT_1404240e8;

  if ((DAT_1404240e8 == (code *)0x0) &&

     (pcVar1 = (code *)FUN_1402ec028(0x1d,"AppPolicyGetWindowingModel",&DAT_14038eb9c,

                                     "AppPolicyGetWindowingModel"), pcVar1 == (code *)0x0)) {

    return 0xc0000225;

  }

  uVar2 = (*pcVar1)(0xfffffffffffffffa,param_1);

  return uVar2;

}




