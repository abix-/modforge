// Address: 0x140184030
// Ghidra name: FUN_140184030
// ============ 0x140184030 FUN_140184030 (size=23) ============


void FUN_140184030(ushort param_1,char param_2)



{

  if (param_2 != '\0') {

    DAT_1403fc6e8 = DAT_1403fc6e8 | param_1;

    return;

  }

  DAT_1403fc6e8 = DAT_1403fc6e8 & ~param_1;

  return;

}




