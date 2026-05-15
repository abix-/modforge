// Address: 0x1401638b0
// Ghidra name: FUN_1401638b0
// ============ 0x1401638b0 FUN_1401638b0 (size=120) ============


undefined8 FUN_1401638b0(longlong param_1)



{

  int iVar1;

  int *piVar2;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331fb4);

    return 0;

  }

  iVar1 = FUN_140138fe0();

  piVar2 = (int *)FUN_140217520();

  if (((piVar2 != (int *)0x0) && (-1 < iVar1 + -1)) && (iVar1 + -1 < *piVar2)) {

    return *(undefined8 *)(piVar2 + (longlong)iVar1 * 4 + -2);

  }

  return 0;

}




