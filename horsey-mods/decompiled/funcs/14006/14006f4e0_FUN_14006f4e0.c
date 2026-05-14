// Address: 0x14006f4e0
// Ghidra name: FUN_14006f4e0
// ============ 0x14006f4e0 FUN_14006f4e0 (size=173) ============


void FUN_14006f4e0(longlong param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  

  FUN_14006db30();

  if (*(char *)(param_1 + 0x11) == '\0') {

    lVar1 = FUN_1402c704c(0x498);

    uVar2 = 0;

    if (lVar1 != 0) {

      uVar2 = FUN_1400aac60(lVar1);

    }

    *(undefined8 *)(param_1 + 0x80) = uVar2;

    FUN_14006f150(uVar2);

    FUN_140080730(param_1,*(undefined8 *)(param_1 + 0x80),0,0);

  }

  else {

    *(undefined8 *)(param_1 + 0x80) = 0;

  }

  FUN_140075c60(param_1 + 0x70);

  FUN_140075c60(param_1 + 0xbc);

  FUN_140075cb0(param_1 + 0x74);

  FUN_140075cb0(param_1 + 0x78);

  FUN_140075cb0(param_1 + 0xb4);

  FUN_140075b80(param_1 + 0x7c);

  FUN_140075e80(param_1 + 0xb8);

  return;

}




