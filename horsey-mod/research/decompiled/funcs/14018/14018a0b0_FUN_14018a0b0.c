// Address: 0x14018a0b0
// Ghidra name: FUN_14018a0b0
// ============ 0x14018a0b0 FUN_14018a0b0 (size=44) ============


undefined8 FUN_14018a0b0(ulonglong *param_1,ulonglong param_2)



{

  ulonglong uVar1;

  undefined1 auVar2 [16];

  

  uVar1 = *param_1;

  if ((uVar1 != 0) &&

     (auVar2._8_8_ = 0, auVar2._0_8_ = uVar1,

     SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar2,0) <= param_2)) {

    return 0xffffffff;

  }

  *param_1 = uVar1 * param_2;

  return 0;

}




