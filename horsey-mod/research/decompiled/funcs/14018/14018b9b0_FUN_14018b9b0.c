// Address: 0x14018b9b0
// Ghidra name: FUN_14018b9b0
// ============ 0x14018b9b0 FUN_14018b9b0 (size=34) ============


uint FUN_14018b9b0(uint param_1)



{

  if ((param_1 & 0xffffff00) == 0xff515700) {

    return ~(param_1 >> 7) & 1 | 2;

  }

  return 1;

}




