// Address: 0x1402ec34c
// Ghidra name: FUN_1402ec34c
// ============ 0x1402ec34c FUN_1402ec34c (size=74) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



undefined8 FUN_1402ec34c(void)



{

  code *pcVar1;

  undefined8 uVar2;

  

  if (DAT_140424000 == (code *)0xffffffffffffffff) {

    return 1;

  }

  pcVar1 = DAT_140424000;

  if ((DAT_140424000 == (code *)0x0) &&

     (pcVar1 = (code *)FUN_1402ec028(0,"AreFileApisANSI",&DAT_14038e9f8,&DAT_14038e9fc),

     pcVar1 == (code *)0x0)) {

    return 1;

  }

  uVar2 = (*pcVar1)();

  return uVar2;

}




