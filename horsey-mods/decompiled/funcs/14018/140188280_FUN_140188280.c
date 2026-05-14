// Address: 0x140188280
// Ghidra name: FUN_140188280
// ============ 0x140188280 FUN_140188280 (size=115) ============


ulonglong FUN_140188280(undefined8 param_1,longlong param_2,undefined1 param_3)



{

  byte bVar1;

  ulonglong uVar2;

  undefined1 local_28 [32];

  

  uVar2 = FUN_1401871e0(local_28,param_1);

  if ((char)uVar2 == '\0') {

    return uVar2;

  }

  if (param_2 == 0) {

    bVar1 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e9c);

  }

  else {

    bVar1 = FUN_140187cc0(local_28,param_2,param_3);

  }

  FUN_1401871c0(local_28);

  return (ulonglong)bVar1;

}




