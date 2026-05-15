// Address: 0x140191680
// Ghidra name: FUN_140191680
// ============ 0x140191680 FUN_140191680 (size=81) ============


ushort FUN_140191680(ushort param_1,longlong param_2,ulonglong param_3)



{

  ushort uVar1;

  ulonglong uVar2;

  

  uVar2 = 0;

  if (param_3 == 0) {

    return param_1;

  }

  do {

    uVar1 = param_1 >> 8;

    param_1 = FUN_1401916e0((byte)param_1 ^ *(byte *)(param_2 + uVar2));

    uVar2 = uVar2 + 1;

    param_1 = param_1 ^ uVar1 & 0xff;

  } while (uVar2 < param_3);

  return param_1;

}




