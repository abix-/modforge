// Address: 0x14017a030
// Ghidra name: FUN_14017a030
// ============ 0x14017a030 FUN_14017a030 (size=181) ============


int * FUN_14017a030(int param_1)



{

  int *piVar1;

  longlong lVar2;

  

  if (param_1 < 1) {

    FUN_14012e850("Parameter \'%s\' is invalid","ncolors");

    return (int *)0x0;

  }

  piVar1 = (int *)FUN_1401841f0(0x18);

  if (piVar1 == (int *)0x0) {

    return (int *)0x0;

  }

  lVar2 = FUN_1401841f0((longlong)param_1 << 2);

  *(longlong *)(piVar1 + 2) = lVar2;

  if (lVar2 == 0) {

    FUN_1401841e0(piVar1);

    return (int *)0x0;

  }

  *piVar1 = param_1;

  piVar1[4] = 1;

  piVar1[5] = 1;

  FUN_1402f94c0(lVar2,0xff,(longlong)param_1 << 2);

  return piVar1;

}




