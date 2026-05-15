// Address: 0x14019c390
// Ghidra name: FUN_14019c390
// ============ 0x14019c390 FUN_14019c390 (size=85) ============


uint FUN_14019c390(uint param_1,byte *param_2,longlong param_3)



{

  byte bVar1;

  uint uVar2;

  

  if (param_2 == (byte *)0x0) {

    return 0;

  }

  param_1 = ~param_1;

  for (; param_3 != 0; param_3 = param_3 + -1) {

    bVar1 = *param_2;

    param_2 = param_2 + 1;

    uVar2 = param_1 >> 4 ^ *(uint *)(&DAT_14033b620 + (ulonglong)((param_1 ^ bVar1) & 0xf) * 4);

    param_1 = uVar2 >> 4 ^

              *(uint *)(&DAT_14033b620 + ((ulonglong)(uVar2 & 0xf) ^ (ulonglong)(bVar1 >> 4)) * 4);

  }

  return ~param_1;

}




