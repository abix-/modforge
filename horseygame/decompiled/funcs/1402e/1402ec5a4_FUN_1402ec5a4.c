// Address: 0x1402ec5a4
// Ghidra name: FUN_1402ec5a4
// ============ 0x1402ec5a4 FUN_1402ec5a4 (size=80) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



undefined8 FUN_1402ec5a4(undefined4 param_1)



{

  code *pcVar1;

  undefined8 uVar2;

  

  if (DAT_1404240c0 == (code *)0xffffffffffffffff) {

    return 0;

  }

  pcVar1 = DAT_1404240c0;

  if ((DAT_1404240c0 == (code *)0x0) &&

     (pcVar1 = (code *)FUN_1402ec028(0x18,"RoInitialize",&DAT_14038eb0c,&DAT_14038eb10),

     pcVar1 == (code *)0x0)) {

    return 0;

  }

  uVar2 = (*pcVar1)(param_1);

  return uVar2;

}




