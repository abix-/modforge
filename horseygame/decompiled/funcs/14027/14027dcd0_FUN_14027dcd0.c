// Address: 0x14027dcd0
// Ghidra name: FUN_14027dcd0
// ============ 0x14027dcd0 FUN_14027dcd0 (size=90) ============


undefined1 FUN_14027dcd0(longlong param_1)



{

  char cVar1;

  undefined1 uVar2;

  longlong lVar3;

  

  lVar3 = FUN_1401841a0(1,0x20);

  if (lVar3 == 0) {

    return 0;

  }

  *(longlong *)(param_1 + 0x70) = lVar3;

  FUN_1402083c0(param_1,"Steam Controller");

  cVar1 = FUN_14027e570(*(undefined2 *)(param_1 + 0x22));

  if (cVar1 != '\0') {

    return 1;

  }

  uVar2 = FUN_14027e520(param_1,1);

  return uVar2;

}




