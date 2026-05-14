// Address: 0x1402e7d50
// Ghidra name: FUN_1402e7d50
// ============ 0x1402e7d50 FUN_1402e7d50 (size=32) ============


undefined8 FUN_1402e7d50(void)



{

  byte bVar1;

  

  bVar1 = (byte)DAT_1403e8b00 & 0x3f;

  return CONCAT71((int7)(DAT_1403e8b00 >> 8),

                  (DAT_1403ff130 ^ DAT_1403e8b00) >> bVar1 != 0 ||

                  (DAT_1403ff130 ^ DAT_1403e8b00) << 0x40 - bVar1 != 0);

}




