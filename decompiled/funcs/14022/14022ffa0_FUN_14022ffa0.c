// Address: 0x14022ffa0
// Ghidra name: FUN_14022ffa0
// ============ 0x14022ffa0 FUN_14022ffa0 (size=68) ============


bool FUN_14022ffa0(longlong param_1)



{

  char cVar1;

  int iVar2;

  

  iVar2 = (*DAT_1403fdd70)(*(undefined8 *)(param_1 + 0x18),0,0,0);

  if (iVar2 < 0) {

    cVar1 = FUN_1401a9ef0("SubmitIoRing",iVar2);

    return cVar1 != '\0';

  }

  return true;

}




