// Address: 0x1401917b0
// Ghidra name: FUN_1401917b0
// ============ 0x1401917b0 FUN_1401917b0 (size=90) ============


uint FUN_1401917b0(uint param_1,longlong param_2,ulonglong param_3)



{

  uint uVar1;

  ulonglong uVar2;

  

  uVar2 = 0;

  if (param_3 == 0) {

    return param_1;

  }

  do {

    uVar1 = FUN_140191810((uint)*(byte *)(param_2 + uVar2) ^ param_1 & 0xff);

    uVar2 = uVar2 + 1;

    param_1 = uVar1 ^ param_1 >> 8;

  } while (uVar2 < param_3);

  return param_1;

}




