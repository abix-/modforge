// Address: 0x1401f0890
// Ghidra name: FUN_1401f0890
// ============ 0x1401f0890 FUN_1401f0890 (size=93) ============


undefined8 FUN_1401f0890(longlong param_1)



{

  char cVar1;

  undefined4 uVar2;

  int iVar3;

  

  uVar2 = FUN_140241090();

  *(undefined4 *)(param_1 + 0x310) = uVar2;

  iVar3 = 0;

  do {

    cVar1 = FUN_1401f06c0(param_1,iVar3,0x8b31 - (uint)(iVar3 != 0));

    if (cVar1 == '\0') {

      return 0;

    }

    iVar3 = iVar3 + 1;

  } while (iVar3 < 0x15);

  return 1;

}




