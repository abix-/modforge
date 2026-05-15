// Address: 0x140167db0
// Ghidra name: FUN_140167db0
// ============ 0x140167db0 FUN_140167db0 (size=99) ============


ulonglong FUN_140167db0(undefined8 *param_1)



{

  ulonglong uVar1;

  ulonglong uVar2;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return 0xffffffff;

  }

  FUN_140179b40(*param_1);

  uVar1 = FUN_140217d40(param_1[0xc]);

  FUN_140179b60(*param_1);

  uVar2 = 0x7fffffff;

  if (uVar1 < 0x7fffffff) {

    uVar2 = uVar1 & 0xffffffff;

  }

  return uVar2;

}




