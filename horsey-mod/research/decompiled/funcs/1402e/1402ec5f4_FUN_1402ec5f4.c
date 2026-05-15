// Address: 0x1402ec5f4
// Ghidra name: FUN_1402ec5f4
// ============ 0x1402ec5f4 FUN_1402ec5f4 (size=66) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



void FUN_1402ec5f4(void)



{

  code *pcVar1;

  

  if (DAT_1404240c8 != (code *)0xffffffffffffffff) {

    pcVar1 = DAT_1404240c8;

    if ((DAT_1404240c8 == (code *)0x0) &&

       (pcVar1 = (code *)FUN_1402ec028(0x19,"RoUninitialize",&DAT_14038eb10,&DAT_14038eb14),

       pcVar1 == (code *)0x0)) {

      return;

    }

    (*pcVar1)();

  }

  return;

}




