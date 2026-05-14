// Address: 0x140225440
// Ghidra name: FUN_140225440
// ============ 0x140225440 FUN_140225440 (size=128) ============


void FUN_140225440(undefined8 param_1,undefined8 param_2)



{

  int iVar1;

  

  if (DAT_1403fdc40 == 4) {

    DAT_1403fdc40 = 3;

    FUN_1401819c0(DAT_1403fdc38);

  }

  iVar1 = DAT_1403fdc40;

  if (DAT_1403fdc40 != 0) {

    FUN_1402f8e20(&DAT_1403fdc10,&DAT_1403fdc00,(longlong)DAT_1403fdc40 << 4);

  }

  DAT_1403fdc00 = param_1;

  DAT_1403fdc40 = iVar1 + 1;

  DAT_1403fdc08 = param_2;

  return;

}




