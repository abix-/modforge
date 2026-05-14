// Address: 0x1402e6fb0
// Ghidra name: FUN_1402e6fb0
// ============ 0x1402e6fb0 FUN_1402e6fb0 (size=55) ============


ulonglong FUN_1402e6fb0(void)



{

  byte bVar1;

  ulonglong uVar2;

  

  __acrt_lock(0);

  bVar1 = (byte)DAT_1403e8b00 & 0x3f;

  uVar2 = DAT_1403fefc8 ^ DAT_1403e8b00;

  __acrt_unlock(0);

  return uVar2 >> bVar1 | uVar2 << 0x40 - bVar1;

}




