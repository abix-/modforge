// Address: 0x140131c60
// Ghidra name: FUN_140131c60
// ============ 0x140131c60 FUN_140131c60 (size=204) ============


longlong FUN_140131c60(int *param_1)



{

  int iVar1;

  longlong lVar2;

  int *piVar3;

  int local_res8 [2];

  longlong local_18;

  undefined4 local_10;

  

  piVar3 = local_res8;

  if (param_1 != (int *)0x0) {

    piVar3 = param_1;

  }

  lVar2 = FUN_140131d30();

  if (lVar2 == 0) {

    *piVar3 = 0;

    FUN_14012e850("Camera subsystem is not initialized");

    return 0;

  }

  FUN_14017caa0(DAT_1403fb628);

  iVar1 = FUN_140138fe0(&DAT_1403fb650);

  lVar2 = FUN_1401841f0((longlong)iVar1 * 4 + 4);

  if (lVar2 == 0) {

    iVar1 = 0;

  }

  else {

    local_10 = 0;

    local_18 = lVar2;

    FUN_1401ab210(DAT_1403fb630,&LAB_140130a90,&local_18);

    *(undefined4 *)((longlong)iVar1 * 4 + lVar2) = 0;

  }

  FUN_14017cae0(DAT_1403fb628);

  *piVar3 = iVar1;

  return lVar2;

}




