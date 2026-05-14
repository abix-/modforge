// Address: 0x1402e60cc
// Ghidra name: FUN_1402e60cc
// ============ 0x1402e60cc FUN_1402e60cc (size=72) ============


ulonglong FUN_1402e60cc(undefined8 param_1,undefined4 *param_2,undefined8 param_3,

                       undefined4 *param_4)



{

  byte bVar1;

  ulonglong uVar2;

  

  __acrt_lock(*param_2);

  bVar1 = (byte)DAT_1403e8b00 & 0x3f;

  uVar2 = DAT_1403fed50 ^ DAT_1403e8b00;

  __acrt_unlock(*param_4);

  return uVar2 >> bVar1 | uVar2 << 0x40 - bVar1;

}




