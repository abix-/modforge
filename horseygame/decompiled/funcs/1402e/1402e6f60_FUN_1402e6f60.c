// Address: 0x1402e6f60
// Ghidra name: FUN_1402e6f60
// ============ 0x1402e6f60 FUN_1402e6f60 (size=51) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



bool FUN_1402e6f60(undefined8 param_1)



{

  int iVar1;

  code *pcVar2;

  bool bVar3;

  

  pcVar2 = (code *)FUN_1402e6fb0();

  bVar3 = false;

  if (pcVar2 != (code *)0x0) {

    iVar1 = (*pcVar2)(param_1);

    bVar3 = iVar1 != 0;

  }

  return bVar3;

}




